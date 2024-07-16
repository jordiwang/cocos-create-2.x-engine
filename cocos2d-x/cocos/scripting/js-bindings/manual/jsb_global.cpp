/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated engine source code (the "Software"), a limited,
 worldwide, royalty-free, non-assignable, revocable and non-exclusive license
 to use Cocos Creator solely to develop games on your target platforms. You shall
 not use Cocos Creator software for developing other software or tools that's
 used for developing games. You are not granted to publish, distribute,
 sublicense, and/or sell copies of Cocos Creator.

 The software or tools in this License Agreement are licensed, not sold.
 Xiamen Yaji Software Co., Ltd. reserves all rights not expressly granted to you.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "jsb_global.h"
#include <string_view>
#include "jsb_conversions.hpp"
#include "xxtea/xxtea.h"

#include "base/CCThreadPool.h"
#include "base/resdec.h"
#include "network/HttpClient.h"
#include "platform/CCApplication.h"
#include "ui/edit-box/EditBox.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "platform/android/jni/JniImp.h"
#include "platform/CountdownTrigger.h"
#include <sched.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <dlfcn.h>
#include <sys/resource.h>
#include <cinttypes>
#endif

#include <regex>

#define PROC_USE_MMAP 0
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#define USE_COMPRESSED_IMAGE_CACHE 1
#endif

#if PROC_USE_MMAP
#include <sys/fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#endif

#if USE_COMPRESSED_IMAGE_CACHE
#include "platform/CCCache.h"
#endif
using namespace cocos2d;

extern bool jsb_register_ncnn(se::Object *nsObj);

se::Object* __jsbObj = nullptr;
se::Object* __jsbFrameRateObj = nullptr;
se::Object* __glObj = nullptr;

static std::shared_ptr<ThreadPool> g_threadPool;

static std::shared_ptr<cocos2d::network::Downloader> g_localDownloader = nullptr;
static std::map<std::string, std::function<void(const std::string&, unsigned char*, int ,const std::string&)>> g_localDownloaderHandlers;
static uint64_t g_localDownloaderTaskId = 1000000;
static std::string xxteaKey = "";
static std::chrono::time_point<std::chrono::high_resolution_clock> gBootTime = std::chrono::high_resolution_clock::now();
static bool _enableGPUTextureCache = true;

void jsb_set_xxtea_key(const std::string& key)
{
    xxteaKey = key;
}

void jsb_set_xxtea_key(se::ScriptEngine *, const std::string& key)
{
    xxteaKey = key;
}

static cocos2d::network::Downloader *localDownloader()
{
    if(!g_localDownloader)
    {
        g_localDownloader = std::make_shared<cocos2d::network::Downloader>();
        g_localDownloader->onDataTaskSuccess = [=](const cocos2d::network::DownloadTask& task,
                                            std::vector<unsigned char>& data) {
            if(data.empty())
            {
                SE_REPORT_ERROR("Getting image from (%s) failed!", task.requestURL.c_str());
                return;
            }

            auto callback = g_localDownloaderHandlers.find(task.identifier);
            if(callback == g_localDownloaderHandlers.end())
            {
                SE_REPORT_ERROR("Getting image from (%s), callback not found!!", task.requestURL.c_str());
                return;
            }
            size_t imageBytes = data.size();
            unsigned char* imageData = (unsigned char*)malloc(imageBytes);
            memcpy(imageData, data.data(), imageBytes);

            (callback->second)("", imageData, imageBytes, "");
            //initImageFunc("", imageData, imageBytes);
            g_localDownloaderHandlers.erase(callback);
        };
        g_localDownloader->onTaskError = [=](const cocos2d::network::DownloadTask& task,
                                      int errorCode,
                                      int errorCodeInternal,
                                      const std::string& errorStr) {

            SE_REPORT_ERROR("Getting image from (%s) failed!", task.requestURL.c_str());
            auto callback = g_localDownloaderHandlers.find(task.identifier);
            if(callback == g_localDownloaderHandlers.end())
            {
                SE_REPORT_ERROR("Getting image from (%s), callback not found!!", task.requestURL.c_str());
                return;
            }

            (callback->second)("", nullptr, 0, errorStr);
            g_localDownloaderHandlers.erase(task.identifier);
        };
    }
    return g_localDownloader.get();
}

static void localDownloaderCreateTask(const std::string &url, std::function<void(const std::string&, unsigned char*, int, const std::string&)> callback)
{
    std::stringstream ss;
    ss << "jsb_loadimage_" << (g_localDownloaderTaskId++);
    std::string key = ss.str();
    auto task = localDownloader()->createDownloadDataTask(url, key);
    g_localDownloaderHandlers.emplace(std::make_pair(task->identifier, callback));
}

static const char* JS_COMPRESS_EXT = ".jsc";

static std::string_view removeFileExt(std::string_view filePath)
{
    size_t pos = filePath.rfind('.');
    if (0 < pos)
    {
        return filePath.substr(0, pos);
    }
    return filePath;
}

static bool try_load_and_decode_wjs_file(std::string_view path_v, std::string &output) {

    auto *fu = FileUtils::getInstance();
    std::string path(path_v);
    if(!path_v.ends_with(".wjs") || !fu->isFileExist(path)) return false;

    Data fileData = FileUtils::getInstance()->getDataFromFile(path);
    uint32_t dataLen{0};
    uint8_t *data = xxtea_decrypt((uint8_t *) fileData.getBytes(),
                                    (uint32_t) fileData.getSize(),
                                    (uint8_t *) xxteaKey.c_str(),
                                    (uint32_t) xxteaKey.size(), &dataLen);
    if(!data || dataLen == 0) {
        output.assign(reinterpret_cast<char*>(fileData.getBytes()), fileData.getSize());
        // continue
        return true;
    }
    if (ZipUtils::isGZipBuffer(data, dataLen)) {
        uint8_t *unpackedData;
        ssize_t unpackedLen = ZipUtils::inflateMemory(data, dataLen, &unpackedData);
        if (unpackedData == nullptr) {
            SE_REPORT_ERROR("Can't decrypt code for %s", path.data());
            return false;
        }

        output.assign(reinterpret_cast<const char *>(unpackedData), unpackedLen);
        free(unpackedData);
        free(data);

        return true;
    }

    output.assign(reinterpret_cast<const char *>(data), dataLen);
    free(data);
    return true;
}

void jsb_init_file_operation_delegate(se::ScriptEngine *inst)
{
    static se::ScriptEngine::FileOperationDelegate delegate;
    if (!delegate.isValid()) {
        delegate.onGetStringFromFile = [](std::string_view path) -> std::string{
            assert(!path.empty());

            std::string content;
            if(try_load_and_decode_wjs_file(path, content)){
                return content;
            }

            std::string byteCodePath = std::string(removeFileExt(path)) + JS_COMPRESS_EXT;
            if (FileUtils::getInstance()->isFileExist(byteCodePath)) {
                Data fileData = FileUtils::getInstance()->getDataFromFile(byteCodePath);
                if(fileData.isNull()) {
                    SE_REPORT_ERROR("Can't decrypt code for %s, empty file", byteCodePath.c_str());
                    return "";
                }
                uint32_t dataLen;
                uint8_t *data = xxtea_decrypt((uint8_t *) fileData.getBytes(),
                                              (uint32_t) fileData.getSize(),
                                              (uint8_t *) xxteaKey.c_str(),
                                              (uint32_t) xxteaKey.size(), &dataLen);

                if (data == nullptr) {
                    SE_REPORT_ERROR("Can't decrypt code for %s", byteCodePath.c_str());
                    return "";
                }

                if (ZipUtils::isGZipBuffer(data, dataLen)) {
                    uint8_t *unpackedData;
                    ssize_t unpackedLen = ZipUtils::inflateMemory(data, dataLen, &unpackedData);
                    if (unpackedData == nullptr) {
                        SE_REPORT_ERROR("Can't decrypt code for %s", byteCodePath.c_str());
                        return "";
                    }

                    std::string ret(reinterpret_cast<const char *>(unpackedData), unpackedLen);
                    free(unpackedData);
                    free(data);

                    return ret;
                } else {
                    std::string ret(reinterpret_cast<const char *>(data), dataLen);
                    free(data);
                    return ret;
                }
            }
            const std::string pathStr(path);
            if (FileUtils::getInstance()->isFileExist(pathStr)) {
                std::string content = FileUtils::getInstance()->getStringFromFile(pathStr);
                return content;
            } else {
                SE_LOGE("ScriptEngine::onGetStringFromFile %s not found, possible missing file.\n",
                        path.data());
            }
            return "";
        };

        delegate.onGetFullPath = [](std::string_view path) -> std::string{
            assert(!path.empty());
            std::string byteCodePath = std::string(removeFileExt(path)) + JS_COMPRESS_EXT;
            if (FileUtils::getInstance()->isFileExist(byteCodePath)) {
                return FileUtils::getInstance()->fullPathForFilename(byteCodePath);
            }
            return FileUtils::getInstance()->fullPathForFilename(path.data());
        };

        delegate.onCheckFileExist = [](std::string_view path) -> bool{
            assert(!path.empty());
            return FileUtils::getInstance()->isFileExist(path.data());
        };

        assert(delegate.isValid());
    }
    
    inst->setFileOperationDelegate(delegate);
}

bool jsb_enable_debugger(se::ScriptEngine *inst, const std::string& debuggerServerAddr, uint32_t port, bool isWaitForConnect)
{
    if (debuggerServerAddr.empty() || port == 0)
        return false;

    inst->enableDebugger(debuggerServerAddr.c_str(), port, isWaitForConnect);

    // For debugger main loop
//    class SimpleRunLoop
//    {
//    public:
//        void update(float dt)
//        {
//            inst->mainLoopUpdate();
//        }
//    };
//    static SimpleRunLoop runLoop;
    //cjh IDEA:    Director::getInstance()->getScheduler()->scheduleUpdate(&runLoop, 0, false);
    return true;
}

bool jsb_set_extend_property(se::ScriptEngine *inst, const char* ns, const char* clsName)
{
    se::Object* globalObj = inst->getGlobalObject();
    se::Value nsVal;
    if (globalObj->getProperty(ns, &nsVal) && nsVal.isObject())
    {
        se::Value ccVal;
        if (globalObj->getProperty("cc", &ccVal) && ccVal.isObject())
        {
            se::Value ccClassVal;
            if (ccVal.toObject()->getProperty("Class", &ccClassVal) && ccClassVal.isObject())
            {
                se::Value extendVal;
                if (ccClassVal.toObject()->getProperty("extend", &extendVal) && extendVal.isObject() && extendVal.toObject()->isFunction())
                {
                    se::Value targetClsVal;
                    if (nsVal.toObject()->getProperty(clsName, &targetClsVal) && targetClsVal.isObject())
                    {
                        return targetClsVal.toObject()->setProperty("extend", extendVal);
                    }
                }
            }
        }
    }
    return false;
}

namespace {

    std::unordered_map<std::string, se::Value> __moduleCache;

    static bool require(se::State& s, se::ScriptEngine *inst)
    {
        const auto& args = s.args();
        int argc = (int)args.size();
        assert(argc >= 1);
        assert(args[0].isString());

        return jsb_run_script(inst, args[0].toString(), &s.rval());
    }
    SE_BIND_FUNC(require)

    static bool doModuleRequire(se::ScriptEngine *inst, const std::string& path, se::Value* ret, const std::string& prevScriptFileDir)
    {
        se::AutoHandleScope hs(inst);
        assert(!path.empty());

        const auto& fileOperationDelegate = inst->getFileOperationDelegate();
        assert(fileOperationDelegate.isValid());

        std::string fullPath;

        std::string pathWithSuffix = path;
        if (pathWithSuffix.rfind(".js") != (pathWithSuffix.length() - 3))
            pathWithSuffix += ".js";
        std::string scriptBuffer = fileOperationDelegate.onGetStringFromFile(pathWithSuffix);

        if (scriptBuffer.empty() && !prevScriptFileDir.empty())
        {
            std::string secondPath = prevScriptFileDir;
            if (secondPath[secondPath.length()-1] != '/')
                secondPath += "/";

            secondPath += path;

            if (FileUtils::getInstance()->isDirectoryExist(secondPath))
            {
                if (secondPath[secondPath.length()-1] != '/')
                    secondPath += "/";
                secondPath += "index.js";
            }
            else
            {
                if (path.rfind(".js") != (path.length() - 3))
                    secondPath += ".js";
            }

            fullPath = fileOperationDelegate.onGetFullPath(secondPath);
            scriptBuffer = fileOperationDelegate.onGetStringFromFile(fullPath);
        }
        else
        {
            fullPath = fileOperationDelegate.onGetFullPath(pathWithSuffix);
        }


        if (!scriptBuffer.empty())
        {
            const auto& iter = __moduleCache.find(fullPath);
            if (iter != __moduleCache.end())
            {
                *ret = iter->second;
//                printf("Found cache: %s, value: %d\n", fullPath.c_str(), (int)ret->getType());
                return true;
            }
            std::string currentScriptFileDir = FileUtils::getInstance()->getFileDir(fullPath);

            // Add closure for evalutate the script
            char prefix[] = "(function(currentScriptDir){ window.module = window.module || {}; var exports = window.module.exports = {}; ";
            char suffix[512] = {0};
            snprintf(suffix, sizeof(suffix), "\nwindow.module.exports = window.module.exports || exports;\n})('%s'); ", currentScriptFileDir.c_str());

            // Add current script path to require function invocation
            scriptBuffer = prefix + std::regex_replace(scriptBuffer, std::regex("([^A-Za-z0-9]|^)requireModule\\((.*?)\\)"), "$1requireModule($2, currentScriptDir)") + suffix;

//            FILE* fp = fopen("/Users/james/Downloads/test.txt", "wb");
//            fwrite(scriptBuffer.c_str(), scriptBuffer.length(), 1, fp);
//            fclose(fp);

            std::string reletivePath = fullPath;
#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    #if CC_TARGET_PLATFORM == CC_PLATFORM_MAC
            const std::string reletivePathKey = "/Contents/Resources";
    #else
            const std::string reletivePathKey = ".app";
    #endif

            size_t pos = reletivePath.find(reletivePathKey);
            if (pos != std::string::npos)
            {
                reletivePath = reletivePath.substr(pos + reletivePathKey.length() + 1);
            }
#endif


//            RENDERER_LOGD("Evaluate: %s", fullPath.c_str());

            auto se = inst;
            bool succeed = se->evalString(scriptBuffer, nullptr, reletivePath);
            se::Value moduleVal;
            if (succeed && se->getGlobalObject()->getProperty("module", &moduleVal) && moduleVal.isObject())
            {
                se::Value exportsVal;
                if (moduleVal.toObject()->getProperty("exports", &exportsVal))
                {
                    if (ret != nullptr)
                        *ret = exportsVal;

                    __moduleCache[fullPath] = std::move(exportsVal);
                }
                else
                {
                    __moduleCache[fullPath] = se::Value::Undefined;
                }
                // clear module.exports
                moduleVal.toObject()->setProperty("exports", se::Value::Undefined);
            }
            else
            {
                __moduleCache[fullPath] = se::Value::Undefined;
            }
            assert(succeed);
            return succeed;
        }

        SE_LOGE("doModuleRequire %s, buffer is empty!\n", path.c_str());
        assert(false);
        return false;
    }

    static bool moduleRequire(se::State& s, se::ScriptEngine *inst)
    {
        const auto& args = s.args();
        int argc = (int)args.size();
        assert(argc >= 2);
        assert(args[0].isString());
        assert(args[1].isString());

        return doModuleRequire(inst, args[0].toString(), &s.rval(), args[1].toString());
    }
    SE_BIND_FUNC(moduleRequire)
} // namespace {

bool jsb_run_script(se::ScriptEngine *inst, const std::string& filePath, se::Value* rval/* = nullptr */)
{
    se::AutoHandleScope hs(inst);
    return inst->runScript(filePath, rval);
}

bool jsb_run_script_module(se::ScriptEngine *inst, const std::string& filePath, se::Value* rval/* = nullptr */)
{
    return doModuleRequire(inst, filePath, rval, "");
}

static bool jsc_garbageCollect(se::State& s, se::ScriptEngine *inst)
{
    inst->garbageCollect();
    return true;
}
SE_BIND_FUNC(jsc_garbageCollect)

static bool jsc_dumpNativePtrToSeObjectMap(se::State& s, se::ScriptEngine *inst)
{
    auto &ptrMap = inst->getNativePtrMap();
    cocos2d::log(">>> total: %d, Dump (native -> jsobj) map begin", (int)ptrMap.size());

    struct NamePtrStruct
    {
        const char* name;
        void* ptr;
    };

    std::vector<NamePtrStruct> namePtrArray;

    for (const auto& e : ptrMap)
    {
        se::Object* jsobj = e.second;
        assert(jsobj->_getClass() != nullptr);
        NamePtrStruct tmp;
        tmp.name = jsobj->_getClass()->getName();
        tmp.ptr = e.first;
        namePtrArray.push_back(tmp);
    }

    std::sort(namePtrArray.begin(), namePtrArray.end(), [](const NamePtrStruct& a, const NamePtrStruct& b) -> bool {
        std::string left = a.name;
        std::string right = b.name;
        for( std::string::const_iterator lit = left.begin(), rit = right.begin(); lit != left.end() && rit != right.end(); ++lit, ++rit )
            if( ::tolower( *lit ) < ::tolower( *rit ) )
                return true;
            else if( ::tolower( *lit ) > ::tolower( *rit ) )
                return false;
        if( left.size() < right.size() )
            return true;
        return false;
    });

    for (const auto& e : namePtrArray)
    {
        cocos2d::log("%s: %p", e.name, e.ptr);
    }
    cocos2d::log(">>> total: %d, nonRefMap: %d, Dump (native -> jsobj) map end", (int)ptrMap.size(), (int)inst->getNoneRefNativePtrMap().size());
    return true;
}
SE_BIND_FUNC(jsc_dumpNativePtrToSeObjectMap)


#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

static bool jsb_getEnableIdleFrameRateAdjustment(se::State &s, se::ScriptEngine *inst) {
    auto &args = s.args();
    s.rval().setBoolean(hsext::getEnableIdleFrameRateAdjustmentJNI());
    return true;
}
SE_BIND_PROP_GET(jsb_getEnableIdleFrameRateAdjustment)

static bool jsb_setEnableIdleFrameRateAdjustment(se::State &s, se::ScriptEngine *inst) {
    auto &args = s.args();
    if (args.size() == 1) {
        hsext::setEnableIdleFrameRateAdjustmentJNI(args[0].toBoolean());
        return true;
    }
    return false;
}
SE_BIND_PROP_SET(jsb_setEnableIdleFrameRateAdjustment)

static bool jsb_setIdleFrameRate(se::State &s, se::ScriptEngine *inst) {
    auto &args = s.args();
    if (args.size() == 1) {
        hsext::setIdleFrameRateJNI(args[0].toFloat());
        return true;
    }
    return false;
}
SE_BIND_PROP_SET(jsb_setIdleFrameRate)

static bool jsb_getIdleFrameRate(se::State &s, se::ScriptEngine *inst) {
    auto &args = s.args();
    s.rval().setFloat(hsext::getIdleFrameRateJNI());
    return true;
}
SE_BIND_PROP_GET(jsb_getIdleFrameRate)

static bool jsb_setIdleFrames(se::State &s, se::ScriptEngine *inst) {
    auto &args = s.args();
    if (args.size() == 1) {
        hsext::setIdleFramesJNI(args[0].toInt32());
        return true;
    }
    return false;
}
SE_BIND_PROP_SET(jsb_setIdleFrames)

static bool jsb_getIdleFrames(se::State &s, se::ScriptEngine *inst) {
    auto &args = s.args();
    s.rval().setInt32(hsext::getIdleFramesJNI());
    return true;
}
SE_BIND_PROP_GET(jsb_getIdleFrames)
#endif

static bool jsc_dumpRoot(se::State& s, se::ScriptEngine *inst)
{
    assert(false);
    return true;
}
SE_BIND_FUNC(jsc_dumpRoot)

static bool JSBCore_platform(se::State& s, se::ScriptEngine *inst)
{
    Application::Platform platform = Application::getInstance()->getPlatform();
    s.rval().setInt32((int32_t)platform);
    return true;
}
SE_BIND_FUNC(JSBCore_platform)

static bool JSBCore_version(se::State& s, se::ScriptEngine *inst)
{
//cjh    char version[256];
//    snprintf(version, sizeof(version)-1, "%s", cocos2dVersion());
//
//    s.rval().setString(version);
    return true;
}
SE_BIND_FUNC(JSBCore_version)

static bool JSB_VM_version(se::State& s, se::ScriptEngine *inst)
{
#if __ANDROID__
    const char *vmVersion = inst->getVMVersion();
    s.rval().setString(vmVersion);
#else
    s.rval().setString("unknown");
#endif
    return true;
}
SE_BIND_FUNC(JSB_VM_version)

static bool JSBCore_os(se::State& s, se::ScriptEngine *inst)
{
    se::Value os;

    // osx, ios, android, windows, linux, etc..
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    os.setString("iOS");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    os.setString("Android");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    os.setString("Windows");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MARMALADE)
    os.setString("Marmalade");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
    os.setString("Linux");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_BADA)
    os.setString("Bada");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY)
    os.setString("Blackberry");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    os.setString("OS X");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    os.setString("WINRT");
#else
    os.setString("Unknown");
#endif

    s.rval() = os;
    return true;
}
SE_BIND_FUNC(JSBCore_os)

static bool JSBCore_getCurrentLanguage(se::State& s, se::ScriptEngine *inst)
{
    std::string languageStr;
    Application::LanguageType language = Application::getInstance()->getCurrentLanguage();
    switch (language)
    {
        case Application::LanguageType::ENGLISH:
            languageStr = "en";
            break;
        case Application::LanguageType::CHINESE:
            languageStr = "zh";
            break;
        case Application::LanguageType::FRENCH:
            languageStr = "fr";
            break;
        case Application::LanguageType::ITALIAN:
            languageStr = "it";
            break;
        case Application::LanguageType::GERMAN:
            languageStr = "de";
            break;
        case Application::LanguageType::SPANISH:
            languageStr = "es";
            break;
        case Application::LanguageType::DUTCH:
            languageStr = "du";
            break;
        case Application::LanguageType::RUSSIAN:
            languageStr = "ru";
            break;
        case Application::LanguageType::KOREAN:
            languageStr = "ko";
            break;
        case Application::LanguageType::JAPANESE:
            languageStr = "ja";
            break;
        case Application::LanguageType::HUNGARIAN:
            languageStr = "hu";
            break;
        case Application::LanguageType::PORTUGUESE:
            languageStr = "pt";
            break;
        case Application::LanguageType::ARABIC:
            languageStr = "ar";
            break;
        case Application::LanguageType::NORWEGIAN:
            languageStr = "no";
            break;
        case Application::LanguageType::POLISH:
            languageStr = "pl";
            break;
        case Application::LanguageType::TURKISH:
            languageStr = "tr";
            break;
        case Application::LanguageType::UKRAINIAN:
            languageStr = "uk";
            break;
        case Application::LanguageType::ROMANIAN:
            languageStr = "ro";
            break;
        case Application::LanguageType::BULGARIAN:
            languageStr = "bg";
            break;
        default:
            languageStr = "unknown";
            break;
    }
    s.rval().setString(languageStr);
    return true;
}
SE_BIND_FUNC(JSBCore_getCurrentLanguage)

static bool JSBCore_getCurrentLanguageCode(se::State& s, se::ScriptEngine *inst)
{
    std::string language = Application::getInstance()->getCurrentLanguageCode();
    s.rval().setString(language);
    return true;
}
SE_BIND_FUNC(JSBCore_getCurrentLanguageCode)

static bool JSB_getOSVersion(se::State& s, se::ScriptEngine *inst)
{
    std::string systemVersion = Application::getInstance()->getSystemVersion();
    s.rval().setString(systemVersion);
    return true;
}
SE_BIND_FUNC(JSB_getOSVersion)

static bool JSB_cleanScript(se::State& s, se::ScriptEngine *inst)
{
    assert(false); //IDEA:
    return true;
}
SE_BIND_FUNC(JSB_cleanScript)

static bool JSB_core_restartVM(se::State& s, se::ScriptEngine *inst)
{
    //REFINE: release AudioEngine, waiting HttpClient & WebSocket threads to exit.
    Application::getInstance()->restart();
    return true;
}
SE_BIND_FUNC(JSB_core_restartVM)

static bool JSB_closeWindow(se::State& s, se::ScriptEngine *inst)
{
    Application::getInstance()->end();
    return true;
}
SE_BIND_FUNC(JSB_closeWindow)

static bool JSB_isObjectValid(se::State& s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1)
    {
        void* nativePtr = nullptr;
        seval_to_native_ptr(inst, args[0], &nativePtr);
        s.rval().setBoolean(nativePtr != nullptr);
        return true;
    }

    SE_REPORT_ERROR("Invalid number of arguments: %d. Expecting: 1", argc);
    return false;
}
SE_BIND_FUNC(JSB_isObjectValid)

static bool getOrCreatePlainObject_r(se::ScriptEngine *inst, const char* name, se::Object* parent, se::Object** outObj)
{
    assert(parent != nullptr);
    assert(outObj != nullptr);
    se::Value tmp;

    if (parent->getProperty(name, &tmp) && tmp.isObject())
    {
        *outObj = tmp.toObject();
        (*outObj)->incRef();
    }
    else
    {
        *outObj = se::Object::createPlainObject(inst);
        parent->setProperty(name, se::Value(*outObj));
    }

    return true;
}

static bool js_performance_now(se::State& s, se::ScriptEngine *inst)
{
    auto now = std::chrono::steady_clock::now();
    auto micro = std::chrono::duration_cast<std::chrono::microseconds>(now - inst->getStartTime()).count();
    s.rval().setNumber((double)micro * 0.001);
    return true;
}
SE_BIND_FUNC(js_performance_now)

namespace
{
    struct ImageInfo
    {
        ~ImageInfo()
        {
            if (freeData)
                delete [] data;
        }

        uint32_t length = 0;
        uint32_t width = 0;
        uint32_t height = 0;
        uint8_t* data = nullptr;
        GLenum glFormat = GL_RGBA;
        GLenum glInternalFormat = GL_RGBA;
        GLenum type = GL_UNSIGNED_BYTE;
        uint8_t bpp = 0;
        uint8_t numberOfMipmaps = 0;
        cocos2d::renderer::jsTextureFormat jsFormat{cocos2d::renderer::jsTextureFormat::UNKNOWN};
        bool hasAlpha = false;
        bool hasPremultipliedAlpha = false;
        bool compressed = false;

        bool freeData = false;
    };

    uint8_t* convertRGB2RGBA (uint32_t length, uint8_t* src) {
        uint8_t* dst = new uint8_t[length];
        for (uint32_t i = 0; i < length; i += 4) {
            dst[i] = *src++;
            dst[i + 1] = *src++;
            dst[i + 2] = *src++;
            dst[i + 3] = 255;
        }
        return dst;
    }

    uint8_t* convertIA2RGBA (uint32_t length, uint8_t* src) {
        uint8_t* dst = new uint8_t[length];
        for (uint32_t i = 0; i < length; i += 4) {
            dst[i] = *src;
            dst[i + 1] = *src;
            dst[i + 2] = *src++;
            dst[i + 3] = *src++;
        }
        return dst;
    }

    uint8_t* convertI2RGBA (uint32_t length, uint8_t* src) {
        uint8_t* dst = new uint8_t[length];
        for (uint32_t i = 0; i < length; i += 4) {
            dst[i] = *src;
            dst[i + 1] = *src;
            dst[i + 2] = *src++;
            dst[i + 3] = 255;
        }
        return dst;
    }

    struct ImageInfo* createImageInfo(const Image* img)
    {
        struct ImageInfo* imgInfo = new struct ImageInfo();
        imgInfo->length = (uint32_t)img->getDataLen();
        imgInfo->width = img->getWidth();
        imgInfo->height = img->getHeight();
        imgInfo->data = img->getData();

        imgInfo->jsFormat = img->getJSFormat();

        const auto& pixelFormatInfo = img->getPixelFormatInfo();
        imgInfo->glFormat = pixelFormatInfo.format;
        imgInfo->glInternalFormat = pixelFormatInfo.internalFormat;
        imgInfo->type = pixelFormatInfo.type;

        imgInfo->bpp = img->getBitPerPixel();
        imgInfo->numberOfMipmaps = img->getNumberOfMipmaps();
        imgInfo->hasAlpha = img->hasAlpha();
        imgInfo->hasPremultipliedAlpha = img->hasPremultipliedAlpha();
        imgInfo->compressed = img->isCompressed();

        // Convert to RGBA888 because standard web api will return only RGBA888.
        // If not, then it may have issue in glTexSubImage. For example, engine
        // will create a big texture, and update its content with small pictures.
        // The big texture is RGBA888, then the small picture should be the same
        // format, or it will cause 0x502 error on OpenGL ES 2.
        if (!imgInfo->compressed && imgInfo->glFormat != GL_RGBA) {
            imgInfo->length = img->getWidth() * img->getHeight() * 4;
            uint8_t* dst = nullptr;
            uint32_t length = imgInfo->length;
            uint8_t* src = imgInfo->data;
            switch(imgInfo->glFormat) {
                case GL_LUMINANCE_ALPHA:
                    dst = convertIA2RGBA(length, src);
                    break;
                case GL_ALPHA:
                case GL_LUMINANCE:
                    dst = convertI2RGBA(length, src);
                    break;
                case GL_RGB:
                    dst = convertRGB2RGBA(length, src);
                    break;
                default:
                    SE_LOGE("unknown image format");
                    break;
            }

            imgInfo->data = dst;
            imgInfo->hasAlpha = true;
            imgInfo->bpp = 32;
            imgInfo->glFormat = GL_RGBA;
            imgInfo->glInternalFormat = GL_RGBA;
            imgInfo->freeData = true;
        }

        return imgInfo;
    }
}

static std::atomic_int32_t imageTestId = 100;
bool jsb_global_load_image(se::ScriptEngine *inst, const std::string& path, const se::Value& callbackVal) {
    if (path.empty())
    {
        se::ValueArray seArgs;
        callbackVal.toObject()->call(seArgs, nullptr);
        return true;
    }
#if USE_COMPRESSED_IMAGE_CACHE
    using initImageFuncType = std::function<void(const std::string& fullPath, unsigned char* imageData, int imageBytes, const std::string& errorMsg)>;
    auto loadFromCache = [](se::ScriptEngine *inst, const std::string &path, se::Value callbackVal, const initImageFuncType& nextFn) {
        if(!g_threadPool) {
            return false;
        }
        g_threadPool->pushTask([inst, callbackVal, path, nextFn](int _tid) {
            std::shared_ptr<ImageInfo> imgInfo = std::make_shared<ImageInfo>();
            std::vector<uint8_t> imageBuffer;
            auto *cacheDb = cocos2d::CacheDB::getInstance();
            auto cacheHit = cacheDb->load<ImageInfo>(path, *(imgInfo.get()), imageBuffer);
            if (cacheHit) {
                cocos2d::Application::getInstance()->dispatchTask([imageBuffer = std::move(imageBuffer), inst, imgInfo, callbackVal, path, imgInfoSP = imgInfo](){
                    se::AutoHandleScope scope(inst);
                    se::ValueArray seArgs;
                    se::HandleObject retObj{se::Object::createPlainObject(inst)};
                    ImageInfo &imgInfo = *(imgInfoSP.get());
                    auto *imageBufferPtr = new std::vector<uint8_t>(std::move(imageBuffer));
                    imgInfo.data = imageBufferPtr->data();
                    se::HandleObject dataVal{
                            se::Object::createExternalUint8ArrayObject(inst, imageBufferPtr->data(),
                                                                       imageBufferPtr->size(),
                                                                       [](void *ptr, size_t len,
                                                                          void *ctx) {
                                                                           auto *buffer = reinterpret_cast<std::vector<uint8_t> *>(ctx);
                                                                           delete buffer;
                                                                       }, imageBufferPtr)};
                    retObj->setProperty("data", se::Value(dataVal));
                    retObj->setProperty("width", se::Value(imgInfo.width));
                    retObj->setProperty("height", se::Value(imgInfo.height));
                    retObj->setProperty("premultiplyAlpha", se::Value(imgInfo.hasPremultipliedAlpha));
                    retObj->setProperty("bpp", se::Value(imgInfo.bpp));
                    retObj->setProperty("hasAlpha", se::Value(imgInfo.hasAlpha));
                    retObj->setProperty("compressed", se::Value(imgInfo.compressed));
                    retObj->setProperty("numberOfMipmaps", se::Value(imgInfo.numberOfMipmaps));
                    if (imgInfo.jsFormat != cocos2d::renderer::jsTextureFormat::UNKNOWN) {
                        retObj->setProperty("jsFormat", se::Value(static_cast<int>(imgInfo.jsFormat)));
                    }
                    assert(imgInfo.numberOfMipmaps == 0);

                    retObj->setProperty("glFormat", se::Value(imgInfo.glFormat));
                    retObj->setProperty("glInternalFormat", se::Value(imgInfo.glInternalFormat));
                    retObj->setProperty("glType", se::Value(imgInfo.type));

                    seArgs.push_back(se::Value(retObj));
                    callbackVal.toObject()->call(seArgs, nullptr);
                    SE_LOGD("[CacheDB] hit image %s\n", path.c_str());
                }, "jsbglobal.cached-image");

            } else {
                nextFn(path, nullptr, 0, "");
            }
        });
        return true;
    };

#endif
    std::shared_ptr<se::Value> callbackPtr = std::make_shared<se::Value>(callbackVal);

    auto initImageFunc = [path, callbackPtr, inst](const std::string& fullPath, unsigned char* imageData, int imageBytes, const std::string& errorMsg){
        std::shared_ptr<uint8_t> imageDataGuard(imageData, free);

        auto pool = g_threadPool;
        if (!pool)
            return;
        pool->pushTask([=](int tid) mutable {
            cocos2d::Perf perf("jsbglobal.init-image");
            // NOTE: FileUtils::getInstance()->fullPathForFilename isn't a threadsafe method,
            // Image::initWithImageFile will call fullPathForFilename internally which may
            // cause thread race issues. Therefore, we get the full path of file before
            // going into task callback.
            // Be careful of invoking any Cocos2d-x interface in a sub-thread.
            bool loadSucceed = false;
            std::shared_ptr<Image> img(new Image(), [](Image *image) {
                image->release();
            });

            if (!errorMsg.empty()) {
                loadSucceed = false;
            }
            else if (fullPath.empty())
            {
                loadSucceed = img->initWithImageData(imageDataGuard.get(), imageBytes);
                imageDataGuard = nullptr;
            }
            else
            {
                loadSucceed = img->initWithImageFile(fullPath);
            }


            std::shared_ptr<ImageInfo> imgInfo;
            if(loadSucceed)
            {
                imgInfo.reset(createImageInfo(img.get()));
            }
#if USE_COMPRESSED_IMAGE_CACHE
            if(_enableGPUTextureCache &&
            !fullPath.empty() &&
            imgInfo->compressed &&
            imgInfo->jsFormat != cocos2d::renderer::jsTextureFormat::UNKNOWN
            ) {
                if(g_threadPool) {
                   g_threadPool->pushTask([fullPath, imgInfo, img](int tid){
                       cocos2d::CacheDB::getInstance()->store<ImageInfo>(fullPath, *(imgInfo.get()), std::span<uint8_t>{imgInfo->data, static_cast<size_t>(img->getDataLen())});
                   });
                }
            }
#endif

            Application::getInstance()->dispatchTask([=]() mutable {
                se::AutoHandleScope hs(inst);
                se::ValueArray seArgs;
                se::Value dataVal;

                std::vector<se::Value> refs;
                if (loadSucceed)
                {
                    se::HandleObject retObj(se::Object::createPlainObject(inst));
                    refs.emplace_back(se::Value(retObj, true));

#if __ANDROID__
                    // RGBA only
                    // assert(imgInfo->width * imgInfo->height * 4 == imgInfo->length);
                    if(imgInfo->data == nullptr || imgInfo->length == 0) {
                        dataVal.setNull();
                    } else {
                        if (!imgInfo->freeData) {
                            img->releaseData(&dataVal);
                        } else {
                            // move data into Uint8Array, do not copy
                            se::HandleObject buffer = se::Object::createExternalUint8ArrayObject(
                                    inst,
                                    imgInfo->data,
                                    imgInfo->length,
                                    +[](void *data, size_t, void *) {
                                        delete[] reinterpret_cast<uint8_t *>(data);
                                    });
                            imgInfo->data = nullptr;
                            imgInfo->length = 0;
                            dataVal.setObject(buffer, true);
                        }
                    }
#else
                    Data data;
                    data.fastSet(imgInfo->data, imgInfo->length);
                    Data_to_seval(inst, data, &dataVal);
                    data.takeBuffer();
#endif
                    retObj->setProperty("data", dataVal);
                    retObj->setProperty("width", se::Value(imgInfo->width));
                    retObj->setProperty("height", se::Value(imgInfo->height));
                    retObj->setProperty("premultiplyAlpha", se::Value(imgInfo->hasPremultipliedAlpha));
                    retObj->setProperty("bpp", se::Value(imgInfo->bpp));
                    retObj->setProperty("hasAlpha", se::Value(imgInfo->hasAlpha));
                    retObj->setProperty("compressed", se::Value(imgInfo->compressed));
                    retObj->setProperty("numberOfMipmaps", se::Value(imgInfo->numberOfMipmaps));
                    if(imgInfo->jsFormat != cocos2d::renderer::jsTextureFormat::UNKNOWN) {
                        retObj->setProperty("jsFormat", se::Value(static_cast<int>(imgInfo->jsFormat)));
                    }
                    if (imgInfo->numberOfMipmaps > 0)
                    {
                        se::HandleObject mipmapArray(se::Object::createArrayObject(inst, imgInfo->numberOfMipmaps));
                        refs.emplace_back(se::Value(mipmapArray, true));

                        retObj->setProperty("mipmaps", se::Value(mipmapArray));
                        auto mipmapInfo = img->getMipmaps();
                        for (int i = 0; i < imgInfo->numberOfMipmaps; ++i)
                        {
                            se::HandleObject info (se::Object::createPlainObject(inst));
                            refs.emplace_back(se::Value(info,true));

                            info->setProperty("offset", se::Value(mipmapInfo[i].offset));
                            info->setProperty("length", se::Value(mipmapInfo[i].len));
                            mipmapArray->setArrayElement(i, se::Value(info));
                        }
                    }

                    retObj->setProperty("glFormat", se::Value(imgInfo->glFormat));
                    retObj->setProperty("glInternalFormat", se::Value(imgInfo->glInternalFormat));
                    retObj->setProperty("glType", se::Value(imgInfo->type));

                    seArgs.push_back(se::Value(retObj));

                    imgInfo = nullptr;
                }
                else
                {
                    SE_REPORT_ERROR("initWithImageFile: %s failed!", path.c_str());
                }

                if (!errorMsg.empty()) {
                    se::HandleObject retObj(se::Object::createPlainObject(inst));
                    refs.emplace_back(se::Value(retObj, true));

                    retObj->setProperty("errorMsg", se::Value(errorMsg));
                    seArgs.push_back(se::Value(retObj));
                }

                callbackPtr->toObject()->call(seArgs, nullptr);
                img = nullptr;


            }, "jsbglobal.load-image");

        });
    };

    size_t pos = std::string::npos;
    if (path.find("http://") == 0 || path.find("https://") == 0)
    {
        localDownloaderCreateTask(path, initImageFunc);

    }
    else if (path.find("data:") == 0 && (pos = path.find("base64,")) != std::string::npos)
    {
        int imageBytes = 0;
        unsigned char* imageData = nullptr;
        size_t dataStartPos = pos + strlen("base64,");
        const char* base64Data = path.data() + dataStartPos;
        size_t dataLen = path.length() - dataStartPos;
        imageBytes = base64Decode((const unsigned char *)base64Data, (unsigned int)dataLen, &imageData);
        if (imageBytes <= 0 || imageData == nullptr)
        {
            SE_REPORT_ERROR("Decode base64 image data failed!");
            return false;
        }
        initImageFunc("", imageData, imageBytes, "");
    }
    else
    {
        std::string fullPath(FileUtils::getInstance()->fullPathForFilename(path));
        if (0 == path.find("file://"))
            fullPath = FileUtils::getInstance()->fullPathForFilename(path.substr(strlen("file://")));

        if (fullPath.empty())
        {
            SE_REPORT_ERROR("File (%s) doesn't exist!", path.c_str());
            return false;
        }
#if USE_COMPRESSED_IMAGE_CACHE
        if(_enableGPUTextureCache && loadFromCache(inst, fullPath, callbackVal, initImageFunc)) {
            return true;
        }
#endif
        initImageFunc(fullPath, nullptr, 0, "");
    }
    return true;
}

static bool js_loadImage(se::State& s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string path;
        ok &= seval_to_std_string(inst, args[0], &path);
        SE_PRECONDITION2(ok, false, "js_loadImage : Error processing arguments");

        se::Value callbackVal = args[1];
        assert(callbackVal.isObject());
        assert(callbackVal.toObject()->isFunction());

        return jsb_global_load_image(inst, path, callbackVal);
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_loadImage)

//pixels(RGBA), width, height, fullFilePath(*.png/*.jpg)
static bool js_saveImageData(se::State& s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        cocos2d::Data data;
        ok &= seval_to_Data(inst, args[0], &data);

        uint32_t width, height;
        ok &= seval_to_uint32(inst, args[1], &width);
        ok &= seval_to_uint32(inst, args[2], &height);

        std::string filePath;
        ok &= seval_to_std_string(inst, args[3], &filePath);
        SE_PRECONDITION2(ok, false, "js_saveImageData : Error processing arguments");

        Image* img = new Image();
        img->initWithRawData(data.getBytes(), data.getSize(), width, height, 8);
        // isToRGB = false, to keep alpha channel
        bool ret = img->saveToFile(filePath, false);
        s.rval().setBoolean(ret);

        img->release();
        return ret;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_saveImageData)

static bool js_setDebugViewText(se::State& s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int32_t index;
        ok = seval_to_int32(inst, args[0], &index);
        SE_PRECONDITION2(ok, false, "Convert arg0 index failed!");

        std::string text;
        ok = seval_to_std_string(inst, args[1], &text);
        SE_PRECONDITION2(ok, false, "Convert arg1 text failed!");


#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        setGameInfoDebugViewTextJNI(index, text);
#endif
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_setDebugViewText)

static bool js_openDebugView(se::State& s, se::ScriptEngine *inst)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    openDebugViewJNI();
#endif
    return true;
}
SE_BIND_FUNC(js_openDebugView)

static bool js_disableBatchGLCommandsToNative(se::State& s, se::ScriptEngine *inst)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    disableBatchGLCommandsToNativeJNI();
#endif
    return true;
}
SE_BIND_FUNC(js_disableBatchGLCommandsToNative)

static bool JSB_openURL(se::State& s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc > 0) {
        std::string url;
        ok = seval_to_std_string(inst, args[0], &url);
        SE_PRECONDITION2(ok, false, "url is invalid!");
        Application::getInstance()->openURL(url);
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(JSB_openURL)

static bool JSB_copyTextToClipboard(se::State& s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc > 0) {
        std::string text;
        ok = seval_to_std_string(inst, args[0], &text);
        SE_PRECONDITION2(ok, false, "text is invalid!");
        Application::getInstance()->copyTextToClipboard(text);
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(JSB_copyTextToClipboard)

static bool JSB_setPreferredFramesPerSecond(se::State& s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc > 0) {
        int32_t fps;
        ok = seval_to_int32(inst, args[0], &fps);
        SE_PRECONDITION2(ok, false, "fps is invalid!");
        Application::getInstance()->setPreferredFramesPerSecond(fps);
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(JSB_setPreferredFramesPerSecond)

static bool JSB_showInputBox(se::State& s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1)
    {
        bool ok;
        se::Value tmp;
        const auto& obj = args[0].toObject();

        cocos2d::EditBox::ShowInfo showInfo;

        ok = obj->getProperty("defaultValue", &tmp);
        SE_PRECONDITION2(ok && tmp.isString(), false, "defaultValue is invalid!");
        showInfo.defaultValue = tmp.toString();


        ok = obj->getProperty("maxLength", &tmp);
        SE_PRECONDITION2(ok && tmp.isNumber(), false, "maxLength is invalid!");
        showInfo.maxLength = tmp.toInt32();

        ok = obj->getProperty("multiple", &tmp);
        SE_PRECONDITION2(ok && tmp.isBoolean(), false, "multiple is invalid!");
        showInfo.isMultiline = tmp.toBoolean();

        if (obj->getProperty("confirmHold", &tmp))
        {
            SE_PRECONDITION2(tmp.isBoolean(), false, "confirmHold is invalid!");
            if (! tmp.isUndefined())
                showInfo.confirmHold = tmp.toBoolean();
        }


        if (obj->getProperty("confirmType", &tmp))
        {
            SE_PRECONDITION2(tmp.isString(), false, "confirmType is invalid!");
            if (!tmp.isUndefined())
                showInfo.confirmType = tmp.toString();
        }

        if (obj->getProperty("inputType", &tmp))
        {
            SE_PRECONDITION2(tmp.isString(), false, "inputType is invalid!");
            if (! tmp.isUndefined())
                showInfo.inputType = tmp.toString();
        }


        if (obj->getProperty("originX", &tmp))
        {
            SE_PRECONDITION2(tmp.isNumber(), false, "originX is invalid!");
            if (! tmp.isUndefined())
                showInfo.x = tmp.toInt32();
        }

        if (obj->getProperty("originY", &tmp))
        {
            SE_PRECONDITION2(tmp.isNumber(), false, "originY is invalid!");
            if (! tmp.isUndefined())
                showInfo.y = tmp.toInt32();
        }

        if (obj->getProperty("width", &tmp))
        {
            SE_PRECONDITION2(tmp.isNumber(), false, "width is invalid!");
            if (! tmp.isUndefined())
                showInfo.width = tmp.toInt32();
        }

        if (obj->getProperty("height", &tmp))
        {
            SE_PRECONDITION2(tmp.isNumber(), false, "height is invalid!");
            if (! tmp.isUndefined())
                showInfo.height = tmp.toInt32();
        }

        EditBox::show(showInfo);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(JSB_showInputBox);

static bool JSB_updateInputBoxRect(se::State& s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 4)
    {
        SE_PRECONDITION2(args[0].isNumber(), false, "x is invalid!");
        const auto& x = args[0].toInt32();
        
        SE_PRECONDITION2(args[1].isNumber(), false, "y is invalid!");
        const auto& y = args[1].toInt32();
        
        SE_PRECONDITION2(args[2].isNumber(), false, "width is invalid!");
        const auto& width = args[2].toInt32();
        
        
        SE_PRECONDITION2(args[3].isNumber(), false, "height is invalid!");
        const auto& height = args[3].toInt32();
        
        EditBox::updateRect(x, y, width, height);
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(JSB_updateInputBoxRect);

static bool JSB_hideInputBox(se::State& s, se::ScriptEngine *inst)
{
    EditBox::hide();
    return true;
}
SE_BIND_FUNC(JSB_hideInputBox)

////////////////////////////////////////////////////////////////////////////////
/////////////////////////// SortThreads ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

struct ThreadInfo {
    std::string name;
    uint32_t processed = 0;
    bool _exists  = false;
    bool highPriority = false;
};
using ThreadInfoMap = std::unordered_map<pid_t, ThreadInfo>;

static void iterateThreads(ThreadInfoMap &threadsInfo) {
    pid_t pid = getpid();
    char tasksPath[128] = {0};
    snprintf(tasksPath, 128, "/proc/%d/task", (int) pid);

    DIR *procdir = opendir(tasksPath);
    if (!procdir) {
        CCLOG("Failed to open dir %s, error: %s", tasksPath, strerror(errno));
        return ;
    }
    dirent *entry;
    for(auto &it : threadsInfo) {
        it.second._exists = false;
    }

    while ((entry = readdir(procdir))) {
        if (entry->d_name[0] == '.') {
            continue;
        }
        pid_t threadid = atoi(entry->d_name);

        ThreadInfo &info = threadsInfo[threadid];
        info._exists = true;

        if((info.processed & 1) == 1) {
            continue;
        }

        char statusPath[255] = {0};
        char statusLine[255] = {0};
        snprintf(statusPath, 255, "/proc/%d/task/%s/status", (int) pid, entry->d_name);
#if PROC_USE_MMAP
        int fd = open(statusPath, O_RDONLY);
        if(!fd) continue;
        struct stat st;
        if(fstat(fd, &st)) {
            SE_LOGE("failed to call fstat on '%s'", statusPath);
            close(fd);
            continue;
        }
        char *content =(char *)mmap(nullptr, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
        if(content == MAP_FAILED) {
            SE_LOGE("faild to call mmap on '%s'", statusPath);
            close(fd);
            continue;
        }
        std::string_view view(content, st.st_size);
        auto start = view.find("Name:");
        auto end = view.find('\n');
        if(start != std::string::npos && end != std::string::npos && start < end) {
            std::string_view lineView = view.substr(start + 5, end);
            while(!lineView.empty() && (
                    lineView[lineView.size() - 1] == ' ' ||
                    lineView[lineView.size() - 1] == '\n'||
                    lineView[lineView.size() - 1] == '\t'||
                    lineView[lineView.size() - 1] == '\r'
                 )) {
                lineView.remove_suffix(1);
            }
            while(!lineView.empty() && (
                    lineView[0] == ' ' ||
                    lineView[0] == '\t'
                    )) {
               lineView.remove_suffix(1);
            }
            if(!lineView.empty()) {
                info.name = lineView;
            }else {
                SE_LOGE("Failed to parse thread name from lineContent '%s'", std::string(view.substr(start, end)).c_str());
            }
        }

        munmap((void *) content, st.st_size);
        close(fd);
#else
        FILE *fpStatus = fopen(statusPath, "rt");
        std::string &taskName = info.name;
        if (fpStatus) {
            while (fgets(statusLine, sizeof(statusLine), fpStatus)) {
                if (strncmp("Name:", statusLine, 5) == 0 || strncmp("name:", statusLine, 5) == 0) {
                    int p = 5;
                    while ((statusLine[p] == ' ' || statusLine[p] == '\t') &&
                           p < sizeof(statusLine)) { p++; }
                    if (p != sizeof(statusLine)) {
                        taskName = &statusLine[p];
                    }
                    p = taskName.length() - 1;
                    while (p > 0 &&
                           (taskName[p] == ' ' || taskName[p] == '\t' || taskName[p] == '\n')) {
                        p--;
                    }
                    if (p > 0) {
                        taskName.resize(p + 1);
                    }
                    break;
                }
                memset(statusLine, 0, sizeof(statusLine));
            }
            fclose(fpStatus);
        }
#endif
        info.processed |= 1;
        CCLOG("sortThreads: +add %d:%s", (int)threadid, info.name.c_str());
    }

    for(auto it = std::begin(threadsInfo); it != std::end(threadsInfo); ) {
        if(!it->second._exists) {
            it = threadsInfo.erase(it);
            CCLOG("sortThreads: -rem %d:%s", (int)it->first, it->second.name.c_str());
        } else {
           it++;
        }
    }
    closedir(procdir);
}
static bool startsWith(const std::string &tname, const char *prefix, size_t N) {
   if(tname.length() < N) return false;
   return memcmp(tname.c_str(), prefix, N) == 0;
}
#define TI_SW(str) startsWith(threadInfo.name, str, sizeof(str) - 1)
static void markThreads(ThreadInfoMap &threadsInfo) {
   auto selfTid = gettid();
   for(auto &iter : threadsInfo)  {
       auto &threadInfo = iter.second;
       if((threadInfo.processed & 2) == 2) {
           continue;
       }
       threadInfo.processed |= 2;
       if(selfTid == iter.first) {
           threadInfo.highPriority = true;
       } else if(TI_SW("main")){
           threadInfo.highPriority = true;
       } else if(TI_SW("Binder")){
           threadInfo.highPriority = true;
       } else if(TI_SW("GLThread")) {
           threadInfo.highPriority = true;
       } else if(TI_SW("GL updater")) {
           threadInfo.highPriority = true;
       } else if(TI_SW("HeapTask")) {
           threadInfo.highPriority = true;
       } else if(TI_SW("Interaction")) {
           threadInfo.highPriority = true;
       } else if(TI_SW("V8")) {
           threadInfo.highPriority = true;
       } else if(TI_SW("GCDaemon")) {
           threadInfo.highPriority = true;
       } else if(TI_SW("RenderThread")) {
           threadInfo.highPriority = true;
       }

       if(threadInfo.highPriority) {
           CCLOG("sortThreads: mark [%s] as high priority", threadInfo.name.c_str());
       }
    }
}

struct CPUInfo {
    uint32_t cpuId = 0;
    uint32_t freq = 0;
};

static std::vector<CPUInfo>& collectCPUInfo() {
    // "/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq"
    static std::vector<CPUInfo> cpuInfoList;
    static const char *cpuDirPath = "/sys/devices/system/cpu";
    static bool everRun = false;
    char cpuFreqPath[255] = {0};

    if(!cpuInfoList.empty() || everRun){
        return cpuInfoList;
    }

    everRun = true;

    DIR * cpuDir = opendir(cpuDirPath);
    if(!cpuDir) {
        return cpuInfoList;
    }
    int cpuId = 0;
    uint32_t freqValue;
    do {
        CPUInfo cpuInfo;
        snprintf(cpuFreqPath, 255, "/sys/devices/system/cpu/cpu%d", cpuId);
        if(access(cpuFreqPath, F_OK) != 0) {
           break;
        }
        snprintf(cpuFreqPath, 255, "/sys/devices/system/cpu/cpu%d/cpufreq/cpuinfo_max_freq", cpuId);
        if(access(cpuFreqPath, F_OK) != 0) {
            break;
        }
        FILE  *cpuFreqFile = fopen(cpuFreqPath, "rt");
        if(cpuFreqFile) {
            fscanf(cpuFreqFile, "%" PRIu32 "", &freqValue);
            fclose(cpuFreqFile);
        }
        cpuInfo.cpuId = cpuId;
        cpuInfo.freq = freqValue;
        cpuInfoList.emplace_back(cpuInfo);
        cpuId++;
    }while(true);
    closedir(cpuDir);

    std::sort(cpuInfoList.begin(), cpuInfoList.end(), [](const CPUInfo &a, const CPUInfo &b){
        return a.freq > b.freq;
    });

    return cpuInfoList;
}

static bool jsc_sortThreads(se::State &s, se::ScriptEngine *inst) {
    static ThreadInfoMap threadsInfo;

    iterateThreads(threadsInfo);
    markThreads(threadsInfo);

    auto &cpuList = collectCPUInfo();
    if(cpuList.size() == 1) return false;

    cpu_set_t foreground_set;
    cpu_set_t background_set;
    CPU_ZERO(&foreground_set);
    CPU_ZERO(&background_set);

    int bgCPU = std::max(1, (int)floor(0.3 * cpuList.size()));
    int foregroudCPU = std::max(1,static_cast<int>(cpuList.size() - bgCPU));
    bgCPU = cpuList.size() - foregroudCPU;
    for(int i = 0;i < foregroudCPU; i++ ) {
        CPU_SET(cpuList[i].cpuId, &foreground_set);
    }
    for(int i = 0;i < bgCPU; i++ ) {
        CPU_SET(cpuList[i + foregroudCPU].cpuId, &background_set);
    }

    int ret;
    int policy;

    for(auto &iter : threadsInfo) {
        auto &threadInfo = iter.second;
        auto &taskName = threadInfo.name;
        auto threadid = iter.first;

        if((threadInfo.processed & 4) == 4) {
            continue;
        }

        threadInfo.processed |= 4;

        if(threadInfo.highPriority) continue;

        ret = sched_setaffinity(threadid, sizeof(cpu_set_t), &background_set);
        if(ret) {
            CCLOG("Failed to call sched_setaffinity: %s", strerror(errno));
        }
        /******** not need to set both  ********/
        // ret = setpriority(PRIO_PROCESS, threadid, 15);
        // if (ret) {
        //     CCLOG("Failed to call setpriority: %s", strerror(errno));
        // }
    }

    return true;
}

SE_BIND_FUNC(jsc_sortThreads)

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// Execution Timout ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#if ENABLE_EXECUTION_TIMEOUT_TRIGGER

double gCountdownTimeoutMS =  0;
static se::Object *gTimeoutCallback = nullptr;

static bool jsb_getExecutionTimeout(se::State &state, se::ScriptEngine *inst) {
    state.rval().setNumber(gCountdownTimeoutMS);
    return true;
}
SE_BIND_PROP_GET(jsb_getExecutionTimeout)
// public symbol
void defaultExecutionTimeoutCallback() {
    cocos2d::Application::getInstance()->getScriptEngine()->requestInterrupt(
            +[](void * /*data*/) {
                auto *inst = cocos2d::Application::getInstance()->getScriptEngine();
                se::AutoHandleScope scope(inst);
                auto stackString = inst->getCurrentStackTrace();
                if (gTimeoutCallback) {
                    gTimeoutCallback->call({se::Value(stackString)}, nullptr);
                }
            },
            nullptr);
}
static bool jsb_setExecutionTimeout(se::State &state, se::ScriptEngine *inst) {
    double timeout = state.args()[0].toNumber();
    gCountdownTimeoutMS = timeout < 0.001 ? 0.0 : static_cast<int>(timeout);
    return true;
}
SE_BIND_PROP_SET(jsb_setExecutionTimeout)

static bool jsb_getETCallback(se::State &state, se::ScriptEngine *inst) {
    if(gTimeoutCallback) {
        state.rval().setObject(gTimeoutCallback);
        return true;
    }
    state.rval().setUndefined();
    return true;
}
SE_BIND_PROP_GET(jsb_getETCallback)

static bool jsb_setETCallback(se::State &state, se::ScriptEngine *inst) {
    se::Value callback = state.args()[0];
    if(callback.isObject() && callback.toObject()->isFunction()) {
        if(gTimeoutCallback) {
            gTimeoutCallback->unroot();
            gTimeoutCallback->decRef();
        }
        gTimeoutCallback = callback.toObject();
        gTimeoutCallback->incRef();
        gTimeoutCallback->root();
        inst->addBeforeCleanupHook([](){
            if(gTimeoutCallback) {
                gTimeoutCallback->unroot();
                gTimeoutCallback->decRef();
                gTimeoutCallback = nullptr;
            }
        }, "beforecleanup.timeoutcallback");
        return true;
    }
    return false;
}
SE_BIND_PROP_SET(jsb_setETCallback)
#endif // ENABLE_EXECUTION_TIMEOUT_TRIGGER

#endif

#if USE_SYSINFO
bool jsb_framerate_dyn_queryFrameList(se::State &s, se::ScriptEngine *inst) {
    constexpr size_t SampleCount = 64;
    auto *frameList = reinterpret_cast<int16_t*>(malloc(SampleCount * sizeof(int16_t)));
    size_t outSize{0};
    auto freecb = +[](void *data, size_t, void *) {
        free(data);
    };
    hsext::getFrameTimeList(frameList, &outSize, SampleCount);
    se::HandleObject frames{se::Object::createExternalInt16ArrayObject(inst, frameList, SampleCount, freecb, nullptr)};
    s.rval().setObject(frames, true);
    return true;
}
SE_BIND_PROP_GET(jsb_framerate_dyn_queryFrameList);

bool jsb_getProcessInfo(se::State &state, se::ScriptEngine *inst) {
    auto &args = state.args();
   if(args.size() < 2) {
       SE_REPORT_ERROR("parameter count(%d) incorrect, %d expected!", (int)args.size(), 2);
       return false;
   }
   if(!args[0].isNumber()) {
       SE_REPORT_ERROR("arg0 should be a number!");
       return false;
   }
   if(!args[1].isObject() || !args[1].toObject()->isFunction()) {
       SE_REPORT_ERROR("arg1 should be a function");
       return false;
   }
   double ms = std::max(50.0, args[0].toNumber());
   se::Object *callback = args[1].toObject();
   callback->incRef();
   callback->root();
   auto result = hsext::getProcessInfo(static_cast<int>(ms), [callback, inst](hsext::ProcessInfo *info){
       se::AutoHandleScope scope(inst);
       se::HandleObject ret{se::Object::createPlainObject(inst)};
       ret->setProperty("pid", se::Value(info->pid));
       ret->setProperty("totalMem", se::Value(static_cast<int>(info->totalMem)));
       ret->setProperty("availableMem", se::Value(static_cast<int>(info->availableMem)));
       ret->setProperty("cpuNum", se::Value(info->cpuNum));
       ret->setProperty("sysCpuUsage", se::Value(info->sysCpuUsage));
       ret->setProperty("procCpuUsage", se::Value(info->procCpuUsage));
       ret->setProperty("threadNumInProc", se::Value(info->threadNumInProc));
       ret->setProperty("rss", se::Value(static_cast<int>(info->rss)));
       ret->defineProperty("frames", _SE(jsb_framerate_dyn_queryFrameList), nullptr);
       callback->call({se::Value(ret)}, nullptr, nullptr);
       callback->unroot();
       callback->decRef();
   });
   if(!result) {
       SE_REPORT_ERROR("Failed to call hsext::getProcessInfo(%d, [cb])", static_cast<int>(ms));
   }
   return result;
}
SE_BIND_FUNC(jsb_getProcessInfo);



bool jsb_framerate_getThreshold(se::State &state, se::ScriptEngine *inst){
    state.rval().setNumber(hsext::getFrameRateThreshold());
    return true;
}
bool jsb_framerate_setThreshold(se::State &state, se::ScriptEngine *inst){
    // >= 0.01
    hsext::setFrameRateThreshold(std::max(0.01F, state.args()[0].toFloat()));
    return true;
}
bool jsb_framerate_getMeasurementWindow(se::State &state, se::ScriptEngine *inst){
    state.rval().setNumber(hsext::getFrameRateMeasurementWindow());
    return true;
}
bool jsb_framerate_setMeasurementWindow(se::State &state, se::ScriptEngine *inst){
    // >= 2
    hsext::setFrameRateMeasurementWindow(std::max(2, state.args()[0].toInt32()));
    return true;
}
bool jsb_framerate_getCallbackInterval(se::State &state, se::ScriptEngine *inst){
    state.rval().setNumber(hsext::getFrameRateCallbackInterval());
    return true;
}
bool jsb_framerate_setCallbackInterval(se::State &state, se::ScriptEngine *inst){
    // >= 50ms
    hsext::setFrameRateCallbackInterval(std::max(50.0F,state.args()[0].toFloat()));
    return true;
}
SE_BIND_PROP_GET(jsb_framerate_getThreshold)
SE_BIND_PROP_SET(jsb_framerate_setThreshold)
SE_BIND_PROP_GET(jsb_framerate_getMeasurementWindow)
SE_BIND_PROP_SET(jsb_framerate_setMeasurementWindow)
SE_BIND_PROP_GET(jsb_framerate_getCallbackInterval)
SE_BIND_PROP_SET(jsb_framerate_setCallbackInterval)

bool jsb_framerate_onLowFrameRate(se::State &state, se::ScriptEngine *inst) {
    auto &args = state.args();
    if(args.size() == 0) {
        SE_REPORT_ERROR("incorrect parameter count %d, %d expected", (int)args.size(), 1);
        return false;
    }
    se::Value callback = state.args()[0];

    if(callback.isNullOrUndefined()) {
        hsext::setOnLowFrameRate(nullptr);
        return true;
    }

    if(!callback.isObject() || !callback.toObject()->isFunction()) {
        SE_REPORT_ERROR("arg0 should be a function");
        return false;
    }
    hsext::setOnLowFrameRate([callback, inst](float fps, float expectFps) {
        se::AutoHandleScope scope(inst);
        se::HandleObject info{se::Object::createPlainObject(inst)};
        info->setProperty("fps", se::Value(fps));
        info->setProperty("targetFps", se::Value(expectFps));
        info->defineProperty("frames", _SE(jsb_framerate_dyn_queryFrameList), nullptr);
        callback.toObject()->call({se::Value(info)}, nullptr);
    });
    return true;
}
SE_BIND_FUNC(jsb_framerate_onLowFrameRate)
#endif

static int getPeakMemUsageKb() {
    struct rusage usage;
    if(getrusage(RUSAGE_SELF, &usage) < 0) return -1;
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC
    return static_cast<int>(usage.ru_maxrss >> 10);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    return static_cast<int>(usage.ru_maxrss);
#else
    return -1;
#endif
}
bool jsb_getJSHeapInfo(se::State &state, se::ScriptEngine *inst) {
    se::HandleObject infoObj(se::Object::createPlainObject(inst));
    
    auto info = inst->getHeapInfo();
    
    infoObj->setProperty("totalHeapSize", se::Value(static_cast<int>(info->totalHeapSize)));
    infoObj->setProperty("totalPhysicalSize", se::Value(static_cast<int>(info->totalPhysicalSize)));
    infoObj->setProperty("totalAvailableSize", se::Value(static_cast<int>(info->totalAvailbleSize)));
    infoObj->setProperty("usedHeapSize", se::Value(static_cast<int>(info->usedHeapSize)));
    infoObj->setProperty("heapSizeLimit", se::Value(static_cast<int>(info->heapSizeLimit)));
    infoObj->setProperty("maxRSS", se::Value(static_cast<int>(getPeakMemUsageKb())));
    infoObj->setProperty("peakMallocedMemory", se::Value(static_cast<int>(info->peakMallocedMemory)));

    state.rval().setObject(infoObj);
    return true;
}
SE_BIND_FUNC(jsb_getJSHeapInfo);

#if USE_TFLITE && CC_TARGET_PLATFORM != CC_PLATFORM_MAC

extern "C" {
bool unloadModel(int id);
int loadModel(char *, size_t len);
bool executeModel(int model, float *, size_t, float *, size_t);
}

static bool jsb_loadModel(se::State &state, se::ScriptEngine *inst) {
    auto &args = state.args();
    if(args.size() != 1) {
        SE_LOGE("load model argument len: %d, 1 expected!", static_cast<int>(args.size()));
        return false;
    }
    se::Value buffer = args[0];
    if(!buffer.isObject() || !buffer.toObject()->isArrayBuffer()) {
        SE_LOGE("parameter should be arraybuffer, but '%s' got", buffer.toStringForce().c_str());
        return false;
    }
    se::Object *bufferObj = buffer.toObject();
    uint8_t *data;
    size_t dataLen;
    if(!bufferObj->getArrayBufferData(&data, &dataLen)) {
        SE_LOGE("failed to read array buffer data");
        return false;
    }

    int modelId = loadModel(reinterpret_cast<char*>(data), dataLen);
    state.rval().setInt32(modelId);
    if(modelId < 0) {
        SE_LOGE("failed to load model");
        return false;
    }
    return true;
}
SE_BIND_FUNC(jsb_loadModel);

static bool jsb_unloadModel(se::State &state, se::ScriptEngine *inst) {
    auto &args = state.args();
    if(args.size() != 1) {
        SE_LOGE("unload model argument len: %d, 1 expected!", static_cast<int>(args.size()));
        return false;
    }
    int modelId = args[0].toInt32();
    unloadModel(modelId);
    return true;
}
SE_BIND_FUNC(jsb_unloadModel);

static bool jsb_executeModel(se::State &state, se::ScriptEngine *inst) {
    auto &args = state.args();
    if(args.size() < 3){
        SE_LOGE("3/4 parameters expected, but got %d", static_cast<int>(args.size()));
        return false;
    }
    se::Value id = args[0];
    se::Value inVal = args[1];
    se::Value outVal = args[2];
    se::Value callback;

    if(args.size() == 4)  callback = args[3];

    if(!id.isNumber()) {
        SE_LOGE("arg 0 should be a number");
        return false;
    }
    if(!inVal.isObject() || !inVal.toObject()->isTypedArray()) {
        SE_LOGE("arg 1 should be a float32 array");
        return false;
    }
    if(!outVal.isObject() || !outVal.toObject()->isTypedArray()) {
        SE_LOGE("arg 2 should be a float32 array");
        return false;
    }

    if(!callback.isNullOrUndefined()) {
        if(!callback.isObject() || !callback.toObject()->isFunction()) {
            SE_LOGE("arg 3 should be a function");
            return false;
        }
    }

    se::Object *inArr = inVal.toObject();
    se::Object *outArr = outVal.toObject();
    if(inArr->getTypedArrayType() != se::Object::TypedArrayType::FLOAT32) {
        SE_LOGE("arg1 is not flaot32 array");
        return false;
    }
    if(outArr->getTypedArrayType() != se::Object::TypedArrayType::FLOAT32) {
        SE_LOGE("arg2 is not flaot32 array");
        return false;
    }

    uint8_t *inFloats;
    uint8_t *outFloats;
    size_t inSize;
    size_t outSize;

    if(!inArr->getTypedArrayData(&inFloats, &inSize)){
        SE_LOGE("failed to read inFloats");
        return false;
    }
    if(!outArr->getTypedArrayData(&outFloats, &outSize)) {
        SE_LOGE("failed to read outFloats");
        return false;
    }

    bool execOk = false;

    if(callback.isNullOrUndefined()) {
        cocos2d::Perf perf("tflite::executeModel");
        execOk = executeModel(id.toInt32(), reinterpret_cast<float *>(inFloats),
                              inSize / sizeof(float),
                              reinterpret_cast<float *>(outFloats), outSize / sizeof(float));
    } else {
        auto modelId = id.toInt32();
        std::thread tsk([modelId,inFloats, inSize, outSize, outFloats, callback, inst](){
            auto ret = executeModel(modelId, reinterpret_cast<float *>(inFloats),
                                    inSize / sizeof(float),
                                    reinterpret_cast<float *>(outFloats), outSize / sizeof(float));
            cocos2d::Application::getInstance()->dispatchTask([callback, inst, ret](){
                se::AutoHandleScope scope(inst);
                se::Value jsRt;
                jsRt.setBoolean(ret);
                callback.toObject()->call({jsRt},nullptr);
            }, "jsbglobal.execute-model");

        });
        tsk.detach();
        execOk = true;
    }
    state.rval().setBoolean(execOk);
    return true;
}

SE_BIND_FUNC(jsb_executeModel);

#endif

bool jsb_timeSinceAppBoot(se::State &state, se::ScriptEngine *inst) {
    auto now = std::chrono::high_resolution_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(now - gBootTime).count();
    state.rval().setNumber( us / 1000.0);
    return true;
}
SE_BIND_PROP_GET(jsb_timeSinceAppBoot)

bool js_enableGPUTextureTranscodeing(se::State &state, se::ScriptEngine *inst) {
    cocos2d::Image::enableGPUTextureAutoTranscoding(true);
    return true;
}
SE_BIND_FUNC(js_enableGPUTextureTranscodeing)

bool js_disableGPUTextureTranscodeing(se::State &state, se::ScriptEngine *inst) {
    cocos2d::Image::enableGPUTextureAutoTranscoding(false);
    return true;
}
SE_BIND_FUNC(js_disableGPUTextureTranscodeing)

bool js_enableGPUTextureCache(se::State &state, se::ScriptEngine *inst) {
    _enableGPUTextureCache = true;
    return true;
}
SE_BIND_FUNC(js_enableGPUTextureCache)

bool js_disableGPUTextureCache(se::State &state, se::ScriptEngine *inst) {
    _enableGPUTextureCache = false;
    return true;
}
SE_BIND_FUNC(js_disableGPUTextureCache)

bool js_clearGPUTextureCache(se::State &state, se::ScriptEngine *inst) {
#if USE_COMPRESSED_IMAGE_CACHE
    cocos2d::CacheDB::getInstance()->clear();
#endif
    return true;
}
SE_BIND_FUNC(js_clearGPUTextureCache)

bool jsb_register_global_variables(se::ScriptEngine *inst, se::Object* global)
{
    g_threadPool.reset(ThreadPool::newFixedThreadPool(3));

    global->defineFunction("require", _SE(require));
    global->defineFunction("requireModule", _SE(moduleRequire));

    getOrCreatePlainObject_r(inst, "jsb", global, &__jsbObj);
#if USE_SYSINFO
    getOrCreatePlainObject_r(inst, "framerate", __jsbObj, &__jsbFrameRateObj);
#endif

    auto glContextCls = se::Class::create(inst, "WebGLRenderingContext", global, nullptr, nullptr);
    glContextCls->install(inst);

    SAFE_DEC_REF(__glObj);
    __glObj = se::Object::createObjectWithClass(inst, glContextCls);
    global->setProperty("__gl", se::Value(__glObj));

    __jsbObj->defineFunction("require", _SE(require));
    __jsbObj->defineFunction("garbageCollect", _SE(jsc_garbageCollect));
    __jsbObj->defineFunction("dumpNativePtrToSeObjectMap", _SE(jsc_dumpNativePtrToSeObjectMap));
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    __jsbObj->defineProperty("enableIdleFrameRateAdjustment", _SE(jsb_getEnableIdleFrameRateAdjustment),_SE(jsb_setEnableIdleFrameRateAdjustment));
    __jsbObj->defineProperty("idleFrameRate", _SE(jsb_getIdleFrameRate), _SE(jsb_setIdleFrameRate));
    __jsbObj->defineProperty("maxIdleFrames", _SE(jsb_getIdleFrames), _SE(jsb_setIdleFrames));
    __jsbObj->defineFunction("sortThreads", _SE(jsc_sortThreads));

#if ENABLE_EXECUTION_TIMEOUT_TRIGGER
    __jsbObj->defineProperty("executionTimeout", _SE(jsb_getExecutionTimeout),_SE(jsb_setExecutionTimeout));
    __jsbObj->defineProperty("executionTimeoutCallback", _SE(jsb_getETCallback), _SE(jsb_setETCallback));
#endif
#endif

#if USE_SYSINFO
    __jsbFrameRateObj->defineProperty("threshold", _SE(jsb_framerate_getThreshold), _SE(jsb_framerate_setThreshold));
    __jsbFrameRateObj->defineProperty("measurementWindow", _SE(jsb_framerate_getMeasurementWindow), _SE(jsb_framerate_setMeasurementWindow));
    __jsbFrameRateObj->defineProperty("interval", _SE(jsb_framerate_getCallbackInterval), _SE(jsb_framerate_setCallbackInterval));
    __jsbFrameRateObj->defineFunction("setCallback", _SE(jsb_framerate_onLowFrameRate));
    __jsbObj->defineFunction("getProcessInfo", _SE(jsb_getProcessInfo));
#endif

    __jsbObj->defineFunction("getJSHeapInfo", _SE(jsb_getJSHeapInfo));

#if USE_TFLITE && CC_TARGET_PLATFORM != CC_PLATFORM_MAC
    __jsbObj->defineFunction("loadModel", _SE(jsb_loadModel));
    __jsbObj->defineFunction("executeModel", _SE(jsb_executeModel));
    __jsbObj->defineFunction("unloadModel", _SE(jsb_unloadModel));
#endif

    __jsbObj->defineFunction("enableGPUTextureTranscoding", _SE(js_enableGPUTextureTranscodeing));
    __jsbObj->defineFunction("disableGPUTextureTranscoding", _SE(js_disableGPUTextureTranscodeing));
    __jsbObj->defineFunction("enableGPUTextureCache", _SE(js_enableGPUTextureCache));
    __jsbObj->defineFunction("disableGPUTextureCache", _SE(js_disableGPUTextureCache));
    __jsbObj->defineFunction("clearGPUTextureCache", _SE(js_clearGPUTextureCache));


    __jsbObj->defineFunction("loadImage", _SE(js_loadImage));
    __jsbObj->defineFunction("saveImageData", _SE(js_saveImageData));
    __jsbObj->defineFunction("setDebugViewText", _SE(js_setDebugViewText));
    __jsbObj->defineFunction("openDebugView", _SE(js_openDebugView));
    __jsbObj->defineFunction("disableBatchGLCommandsToNative", _SE(js_disableBatchGLCommandsToNative));
    __jsbObj->defineFunction("openURL", _SE(JSB_openURL));
    __jsbObj->defineFunction("copyTextToClipboard", _SE(JSB_copyTextToClipboard));

    __jsbObj->defineFunction("setPreferredFramesPerSecond", _SE(JSB_setPreferredFramesPerSecond));
    __jsbObj->defineFunction("showInputBox", _SE(JSB_showInputBox));
    __jsbObj->defineFunction("hideInputBox", _SE(JSB_hideInputBox));
    __jsbObj->defineFunction("updateInputBoxRect", _SE(JSB_updateInputBoxRect));
    __jsbObj->defineProperty("msSinceStart", _SE(jsb_timeSinceAppBoot), nullptr);

#if USE_NCNN
    jsb_register_ncnn(__jsbObj);
#endif

    global->defineFunction("__getPlatform", _SE(JSBCore_platform));
    global->defineFunction("__getOS", _SE(JSBCore_os));
    global->defineFunction("__getOSVersion", _SE(JSB_getOSVersion));
    global->defineFunction("__getCurrentLanguage", _SE(JSBCore_getCurrentLanguage));
    global->defineFunction("__getCurrentLanguageCode", _SE(JSBCore_getCurrentLanguageCode));
    global->defineFunction("__getVersion", _SE(JSBCore_version));
    global->defineFunction("__getVMVersion", _SE(JSB_VM_version));
    global->defineFunction("__restartVM", _SE(JSB_core_restartVM));
    global->defineFunction("__cleanScript", _SE(JSB_cleanScript));
    global->defineFunction("__isObjectValid", _SE(JSB_isObjectValid));
    global->defineFunction("close", _SE(JSB_closeWindow));

    se::HandleObject performanceObj(se::Object::createPlainObject(inst));
    performanceObj->defineFunction("now", _SE(js_performance_now));
    global->setProperty("performance", se::Value(performanceObj));

    inst->clearException();

    inst->addBeforeCleanupHook([](){
        g_threadPool = nullptr;

        PoolManager::getInstance()->getCurrentPool()->clear();
    }, "beforecleanup.gthreadpool.poolmgr");

    inst->addAfterCleanupHook([](){

        PoolManager::getInstance()->getCurrentPool()->clear();

        __moduleCache.clear();
#if USE_SYSINFO
        hsext::resetFrameRate();
        SAFE_DEC_REF(__jsbFrameRateObj);
#endif

        SAFE_DEC_REF(__jsbObj);
        SAFE_DEC_REF(__glObj);
    });

    return true;
}
