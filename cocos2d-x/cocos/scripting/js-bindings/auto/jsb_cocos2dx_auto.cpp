#include "scripting/js-bindings/auto/jsb_cocos2dx_auto.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "cocos2d.h"
#include "2d/CCTTFLabelRenderer.h"

se::Object* __jsb_cocos2d_FileUtils_proto = nullptr;
se::Class* __jsb_cocos2d_FileUtils_class = nullptr;

static bool js_engine_FileUtils_writeDataToFile(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_writeDataToFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocos2d::Data arg0;
        std::string arg1;
        ok &= seval_to_Data(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_writeDataToFile : Error processing arguments");
        bool result = cobj->writeDataToFile(arg0, arg1);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_writeDataToFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_writeDataToFile)

static bool js_engine_FileUtils_fullPathForFilename(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_fullPathForFilename : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_fullPathForFilename : Error processing arguments");
        std::string result = cobj->fullPathForFilename(arg0);
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_fullPathForFilename : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_fullPathForFilename)

static bool js_engine_FileUtils_getStringFromFile(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_getStringFromFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getStringFromFile : Error processing arguments");
        std::string result = cobj->getStringFromFile(arg0);
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getStringFromFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_getStringFromFile)

static bool js_engine_FileUtils_removeFile(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_removeFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_removeFile : Error processing arguments");
        bool result = cobj->removeFile(arg0);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_removeFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_removeFile)

static bool js_engine_FileUtils_getDataFromFile(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_getDataFromFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getDataFromFile : Error processing arguments");
        cocos2d::Data result = cobj->getDataFromFile(arg0);
        ok &= Data_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getDataFromFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_getDataFromFile)

static bool js_engine_FileUtils_isAbsolutePath(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_isAbsolutePath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_isAbsolutePath : Error processing arguments");
        bool result = cobj->isAbsolutePath(arg0);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_isAbsolutePath : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_isAbsolutePath)

static bool js_engine_FileUtils_renameFile(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_engine_FileUtils_renameFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            bool result = cobj->renameFile(arg0, arg1);
            ok &= boolean_to_seval(inst, result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_engine_FileUtils_renameFile : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 3) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            std::string arg2;
            ok &= seval_to_std_string(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            bool result = cobj->renameFile(arg0, arg1, arg2);
            ok &= boolean_to_seval(inst, result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_engine_FileUtils_renameFile : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_renameFile)

static bool js_engine_FileUtils_normalizePath(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_normalizePath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_normalizePath : Error processing arguments");
        std::string result = cobj->normalizePath(arg0);
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_normalizePath : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_normalizePath)

static bool js_engine_FileUtils_getDefaultResourceRootPath(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_getDefaultResourceRootPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cobj->getDefaultResourceRootPath();
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getDefaultResourceRootPath : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_getDefaultResourceRootPath)

static bool js_engine_FileUtils_loadFilenameLookupDictionaryFromFile(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_loadFilenameLookupDictionaryFromFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_loadFilenameLookupDictionaryFromFile : Error processing arguments");
        cobj->loadFilenameLookupDictionaryFromFile(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_loadFilenameLookupDictionaryFromFile)

static bool js_engine_FileUtils_isPopupNotify(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_isPopupNotify : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isPopupNotify();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_isPopupNotify : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_isPopupNotify)

static bool js_engine_FileUtils_getValueVectorFromFile(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_getValueVectorFromFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getValueVectorFromFile : Error processing arguments");
        cocos2d::ValueVector result = cobj->getValueVectorFromFile(arg0);
        ok &= ccvaluevector_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getValueVectorFromFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_getValueVectorFromFile)

static bool js_engine_FileUtils_getSearchPaths(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_getSearchPaths : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::vector<std::string>& result = cobj->getSearchPaths();
        ok &= std_vector_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getSearchPaths : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_getSearchPaths)

static bool js_engine_FileUtils_getFileDir(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_getFileDir : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getFileDir : Error processing arguments");
        std::string result = cobj->getFileDir(arg0);
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getFileDir : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_getFileDir)

static bool js_engine_FileUtils_writeToFile(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_writeToFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocos2d::ValueMap arg0;
        std::string arg1;
        ok &= seval_to_ccvaluemap(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_writeToFile : Error processing arguments");
        bool result = cobj->writeToFile(arg0, arg1);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_writeToFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_writeToFile)

static bool js_engine_FileUtils_getOriginalSearchPaths(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_getOriginalSearchPaths : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::vector<std::string>& result = cobj->getOriginalSearchPaths();
        ok &= std_vector_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getOriginalSearchPaths : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_getOriginalSearchPaths)

static bool js_engine_FileUtils_listFiles(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_listFiles : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_listFiles : Error processing arguments");
        std::vector<std::string> result = cobj->listFiles(arg0);
        ok &= std_vector_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_listFiles : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_listFiles)

static bool js_engine_FileUtils_getValueMapFromFile(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_getValueMapFromFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getValueMapFromFile : Error processing arguments");
        cocos2d::ValueMap result = cobj->getValueMapFromFile(arg0);
        ok &= ccvaluemap_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getValueMapFromFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_getValueMapFromFile)

static bool js_engine_FileUtils_getFileSize(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_getFileSize : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getFileSize : Error processing arguments");
        long result = cobj->getFileSize(arg0);
        ok &= long_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getFileSize : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_getFileSize)

static bool js_engine_FileUtils_getValueMapFromData(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_getValueMapFromData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const char* arg0 = nullptr;
        int arg1 = 0;
        std::string arg0_tmp; ok &= seval_to_std_string(inst, args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[1], &tmp); arg1 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getValueMapFromData : Error processing arguments");
        cocos2d::ValueMap result = cobj->getValueMapFromData(arg0, arg1);
        ok &= ccvaluemap_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getValueMapFromData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_getValueMapFromData)

static bool js_engine_FileUtils_removeDirectory(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_removeDirectory : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_removeDirectory : Error processing arguments");
        bool result = cobj->removeDirectory(arg0);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_removeDirectory : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_removeDirectory)

static bool js_engine_FileUtils_setSearchPaths(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_setSearchPaths : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::vector<std::string> arg0;
        ok &= seval_to_std_vector_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_setSearchPaths : Error processing arguments");
        cobj->setSearchPaths(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_setSearchPaths)

static bool js_engine_FileUtils_writeStringToFile(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_writeStringToFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_writeStringToFile : Error processing arguments");
        bool result = cobj->writeStringToFile(arg0, arg1);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_writeStringToFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_writeStringToFile)

static bool js_engine_FileUtils_setSearchResolutionsOrder(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_setSearchResolutionsOrder : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::vector<std::string> arg0;
        ok &= seval_to_std_vector_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_setSearchResolutionsOrder : Error processing arguments");
        cobj->setSearchResolutionsOrder(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_setSearchResolutionsOrder)

static bool js_engine_FileUtils_addSearchResolutionsOrder(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_addSearchResolutionsOrder : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_addSearchResolutionsOrder : Error processing arguments");
        cobj->addSearchResolutionsOrder(arg0);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_boolean(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_addSearchResolutionsOrder : Error processing arguments");
        cobj->addSearchResolutionsOrder(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_addSearchResolutionsOrder)

static bool js_engine_FileUtils_addSearchPath(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_addSearchPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_addSearchPath : Error processing arguments");
        cobj->addSearchPath(arg0);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_boolean(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_addSearchPath : Error processing arguments");
        cobj->addSearchPath(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_addSearchPath)

static bool js_engine_FileUtils_writeValueVectorToFile(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_writeValueVectorToFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocos2d::ValueVector arg0;
        std::string arg1;
        ok &= seval_to_ccvaluevector(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_writeValueVectorToFile : Error processing arguments");
        bool result = cobj->writeValueVectorToFile(arg0, arg1);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_writeValueVectorToFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_writeValueVectorToFile)

static bool js_engine_FileUtils_isFileExist(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_isFileExist : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_isFileExist : Error processing arguments");
        bool result = cobj->isFileExist(arg0);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_isFileExist : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_isFileExist)

static bool js_engine_FileUtils_purgeCachedEntries(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_purgeCachedEntries : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->purgeCachedEntries();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_purgeCachedEntries)

static bool js_engine_FileUtils_fullPathFromRelativeFile(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_fullPathFromRelativeFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_fullPathFromRelativeFile : Error processing arguments");
        std::string result = cobj->fullPathFromRelativeFile(arg0, arg1);
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_fullPathFromRelativeFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_fullPathFromRelativeFile)

static bool js_engine_FileUtils_getSuitableFOpen(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_getSuitableFOpen : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getSuitableFOpen : Error processing arguments");
        std::string result = cobj->getSuitableFOpen(arg0);
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getSuitableFOpen : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_getSuitableFOpen)

static bool js_engine_FileUtils_writeValueMapToFile(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_writeValueMapToFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocos2d::ValueMap arg0;
        std::string arg1;
        ok &= seval_to_ccvaluemap(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_writeValueMapToFile : Error processing arguments");
        bool result = cobj->writeValueMapToFile(arg0, arg1);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_writeValueMapToFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_writeValueMapToFile)

static bool js_engine_FileUtils_getFileExtension(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_getFileExtension : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getFileExtension : Error processing arguments");
        std::string result = cobj->getFileExtension(arg0);
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getFileExtension : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_getFileExtension)

static bool js_engine_FileUtils_setWritablePath(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_setWritablePath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_setWritablePath : Error processing arguments");
        cobj->setWritablePath(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_setWritablePath)

static bool js_engine_FileUtils_setPopupNotify(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_setPopupNotify : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_setPopupNotify : Error processing arguments");
        cobj->setPopupNotify(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_setPopupNotify)

static bool js_engine_FileUtils_isDirectoryExist(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_isDirectoryExist : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_isDirectoryExist : Error processing arguments");
        bool result = cobj->isDirectoryExist(arg0);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_isDirectoryExist : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_isDirectoryExist)

static bool js_engine_FileUtils_setDefaultResourceRootPath(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_setDefaultResourceRootPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_setDefaultResourceRootPath : Error processing arguments");
        cobj->setDefaultResourceRootPath(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_setDefaultResourceRootPath)

static bool js_engine_FileUtils_getSearchResolutionsOrder(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_getSearchResolutionsOrder : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::vector<std::string>& result = cobj->getSearchResolutionsOrder();
        ok &= std_vector_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getSearchResolutionsOrder : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_getSearchResolutionsOrder)

static bool js_engine_FileUtils_createDirectory(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_createDirectory : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_createDirectory : Error processing arguments");
        bool result = cobj->createDirectory(arg0);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_createDirectory : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_createDirectory)

static bool js_engine_FileUtils_getWritablePath(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_FileUtils_getWritablePath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = cobj->getWritablePath();
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getWritablePath : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_getWritablePath)

static bool js_engine_FileUtils_setDelegate(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::FileUtils* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_setDelegate : Error processing arguments");
        cocos2d::FileUtils::setDelegate(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_setDelegate)

static bool js_engine_FileUtils_getInstance(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::FileUtils* result = cocos2d::FileUtils::getInstance();
        ok &= native_ptr_to_seval<cocos2d::FileUtils>(inst, (cocos2d::FileUtils*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_FileUtils_getInstance : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_FileUtils_getInstance)



static bool js_cocos2d_FileUtils_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::FileUtils)", s.nativeThisObject());
    auto iter = inst->getNoneRefNativePtrMap().find(s.nativeThisObject());
    if (iter != inst->getNoneRefNativePtrMap().end())
    {
        inst->getNoneRefNativePtrMap().erase(iter);
        cocos2d::FileUtils* cobj = (cocos2d::FileUtils*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_FileUtils_finalize)

bool js_register_engine_FileUtils(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "FileUtils", obj, nullptr, nullptr);

    cls->defineFunction(inst, "writeDataToFile", _SE(js_engine_FileUtils_writeDataToFile));
    cls->defineFunction(inst, "fullPathForFilename", _SE(js_engine_FileUtils_fullPathForFilename));
    cls->defineFunction(inst, "getStringFromFile", _SE(js_engine_FileUtils_getStringFromFile));
    cls->defineFunction(inst, "removeFile", _SE(js_engine_FileUtils_removeFile));
    cls->defineFunction(inst, "getDataFromFile", _SE(js_engine_FileUtils_getDataFromFile));
    cls->defineFunction(inst, "isAbsolutePath", _SE(js_engine_FileUtils_isAbsolutePath));
    cls->defineFunction(inst, "renameFile", _SE(js_engine_FileUtils_renameFile));
    cls->defineFunction(inst, "normalizePath", _SE(js_engine_FileUtils_normalizePath));
    cls->defineFunction(inst, "getDefaultResourceRootPath", _SE(js_engine_FileUtils_getDefaultResourceRootPath));
    cls->defineFunction(inst, "loadFilenameLookup", _SE(js_engine_FileUtils_loadFilenameLookupDictionaryFromFile));
    cls->defineFunction(inst, "isPopupNotify", _SE(js_engine_FileUtils_isPopupNotify));
    cls->defineFunction(inst, "getValueVectorFromFile", _SE(js_engine_FileUtils_getValueVectorFromFile));
    cls->defineFunction(inst, "getSearchPaths", _SE(js_engine_FileUtils_getSearchPaths));
    cls->defineFunction(inst, "getFileDir", _SE(js_engine_FileUtils_getFileDir));
    cls->defineFunction(inst, "writeToFile", _SE(js_engine_FileUtils_writeToFile));
    cls->defineFunction(inst, "getOriginalSearchPaths", _SE(js_engine_FileUtils_getOriginalSearchPaths));
    cls->defineFunction(inst, "listFiles", _SE(js_engine_FileUtils_listFiles));
    cls->defineFunction(inst, "getValueMapFromFile", _SE(js_engine_FileUtils_getValueMapFromFile));
    cls->defineFunction(inst, "getFileSize", _SE(js_engine_FileUtils_getFileSize));
    cls->defineFunction(inst, "getValueMapFromData", _SE(js_engine_FileUtils_getValueMapFromData));
    cls->defineFunction(inst, "removeDirectory", _SE(js_engine_FileUtils_removeDirectory));
    cls->defineFunction(inst, "setSearchPaths", _SE(js_engine_FileUtils_setSearchPaths));
    cls->defineFunction(inst, "writeStringToFile", _SE(js_engine_FileUtils_writeStringToFile));
    cls->defineFunction(inst, "setSearchResolutionsOrder", _SE(js_engine_FileUtils_setSearchResolutionsOrder));
    cls->defineFunction(inst, "addSearchResolutionsOrder", _SE(js_engine_FileUtils_addSearchResolutionsOrder));
    cls->defineFunction(inst, "addSearchPath", _SE(js_engine_FileUtils_addSearchPath));
    cls->defineFunction(inst, "writeValueVectorToFile", _SE(js_engine_FileUtils_writeValueVectorToFile));
    cls->defineFunction(inst, "isFileExist", _SE(js_engine_FileUtils_isFileExist));
    cls->defineFunction(inst, "purgeCachedEntries", _SE(js_engine_FileUtils_purgeCachedEntries));
    cls->defineFunction(inst, "fullPathFromRelativeFile", _SE(js_engine_FileUtils_fullPathFromRelativeFile));
    cls->defineFunction(inst, "getSuitableFOpen", _SE(js_engine_FileUtils_getSuitableFOpen));
    cls->defineFunction(inst, "writeValueMapToFile", _SE(js_engine_FileUtils_writeValueMapToFile));
    cls->defineFunction(inst, "getFileExtension", _SE(js_engine_FileUtils_getFileExtension));
    cls->defineFunction(inst, "setWritablePath", _SE(js_engine_FileUtils_setWritablePath));
    cls->defineFunction(inst, "setPopupNotify", _SE(js_engine_FileUtils_setPopupNotify));
    cls->defineFunction(inst, "isDirectoryExist", _SE(js_engine_FileUtils_isDirectoryExist));
    cls->defineFunction(inst, "setDefaultResourceRootPath", _SE(js_engine_FileUtils_setDefaultResourceRootPath));
    cls->defineFunction(inst, "getSearchResolutionsOrder", _SE(js_engine_FileUtils_getSearchResolutionsOrder));
    cls->defineFunction(inst, "createDirectory", _SE(js_engine_FileUtils_createDirectory));
    cls->defineFunction(inst, "getWritablePath", _SE(js_engine_FileUtils_getWritablePath));
    cls->defineStaticFunction(inst, "setDelegate", _SE(js_engine_FileUtils_setDelegate));
    cls->defineStaticFunction(inst, "getInstance", _SE(js_engine_FileUtils_getInstance));
    cls->defineFinalizeFunction(_SE(js_cocos2d_FileUtils_finalize));
    cls->install(inst);
    inst->registerClass<cocos2d::FileUtils>(cls);

    __jsb_cocos2d_FileUtils_proto = cls->getProto();
    __jsb_cocos2d_FileUtils_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_cocos2d_Device_proto = nullptr;
se::Class* __jsb_cocos2d_Device_class = nullptr;

static bool js_engine_Device_getDevicePixelRatio(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cocos2d::Device::getDevicePixelRatio();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_Device_getDevicePixelRatio : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_Device_getDevicePixelRatio)

static bool js_engine_Device_setAccelerometerEnabled(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_Device_setAccelerometerEnabled : Error processing arguments");
        cocos2d::Device::setAccelerometerEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_Device_setAccelerometerEnabled)

static bool js_engine_Device_setAccelerometerInterval(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_Device_setAccelerometerInterval : Error processing arguments");
        cocos2d::Device::setAccelerometerInterval(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_Device_setAccelerometerInterval)

static bool js_engine_Device_vibrate(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_Device_vibrate : Error processing arguments");
        cocos2d::Device::vibrate(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_Device_vibrate)

static bool js_engine_Device_setKeepScreenOn(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_Device_setKeepScreenOn : Error processing arguments");
        cocos2d::Device::setKeepScreenOn(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_Device_setKeepScreenOn)

static bool js_engine_Device_getNetworkType(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = (int)cocos2d::Device::getNetworkType();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_Device_getNetworkType : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_Device_getNetworkType)

static bool js_engine_Device_getBatteryLevel(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cocos2d::Device::getBatteryLevel();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_Device_getBatteryLevel : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_Device_getBatteryLevel)

static bool js_engine_Device_getDeviceRotation(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = (int)cocos2d::Device::getDeviceRotation();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_Device_getDeviceRotation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_Device_getDeviceRotation)

static bool js_engine_Device_getDPI(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cocos2d::Device::getDPI();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_Device_getDPI : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_Device_getDPI)

static bool js_engine_Device_getSafeAreaEdge(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec4 result = cocos2d::Device::getSafeAreaEdge();
        ok &= Vec4_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_Device_getSafeAreaEdge : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_Device_getSafeAreaEdge)

static bool js_engine_Device_getDeviceModel(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = cocos2d::Device::getDeviceModel();
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_Device_getDeviceModel : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_Device_getDeviceModel)




bool js_register_engine_Device(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Device", obj, nullptr, nullptr);

    cls->defineStaticFunction(inst, "getDevicePixelRatio", _SE(js_engine_Device_getDevicePixelRatio));
    cls->defineStaticFunction(inst, "setAccelerometerEnabled", _SE(js_engine_Device_setAccelerometerEnabled));
    cls->defineStaticFunction(inst, "setAccelerometerInterval", _SE(js_engine_Device_setAccelerometerInterval));
    cls->defineStaticFunction(inst, "vibrate", _SE(js_engine_Device_vibrate));
    cls->defineStaticFunction(inst, "setKeepScreenOn", _SE(js_engine_Device_setKeepScreenOn));
    cls->defineStaticFunction(inst, "getNetworkType", _SE(js_engine_Device_getNetworkType));
    cls->defineStaticFunction(inst, "getBatteryLevel", _SE(js_engine_Device_getBatteryLevel));
    cls->defineStaticFunction(inst, "getDeviceRotation", _SE(js_engine_Device_getDeviceRotation));
    cls->defineStaticFunction(inst, "getDPI", _SE(js_engine_Device_getDPI));
    cls->defineStaticFunction(inst, "getSafeAreaEdge", _SE(js_engine_Device_getSafeAreaEdge));
    cls->defineStaticFunction(inst, "getDeviceModel", _SE(js_engine_Device_getDeviceModel));
    cls->install(inst);
    inst->registerClass<cocos2d::Device>(cls);

    __jsb_cocos2d_Device_proto = cls->getProto();
    __jsb_cocos2d_Device_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_cocos2d_SAXParser_proto = nullptr;
se::Class* __jsb_cocos2d_SAXParser_class = nullptr;

static bool js_engine_SAXParser_init(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::SAXParser* cobj = (cocos2d::SAXParser*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_SAXParser_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(inst, args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        SE_PRECONDITION2(ok, false, "js_engine_SAXParser_init : Error processing arguments");
        bool result = cobj->init(arg0);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_SAXParser_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_SAXParser_init)




bool js_register_engine_SAXParser(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "PlistParser", obj, nullptr, nullptr);

    cls->defineFunction(inst, "init", _SE(js_engine_SAXParser_init));
    cls->install(inst);
    inst->registerClass<cocos2d::SAXParser>(cls);

    __jsb_cocos2d_SAXParser_proto = cls->getProto();
    __jsb_cocos2d_SAXParser_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_cocos2d_CanvasGradient_proto = nullptr;
se::Class* __jsb_cocos2d_CanvasGradient_class = nullptr;

static bool js_engine_CanvasGradient_addColorStop(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasGradient* cobj = (cocos2d::CanvasGradient*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasGradient_addColorStop : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        std::string arg1;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasGradient_addColorStop : Error processing arguments");
        cobj->addColorStop(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasGradient_addColorStop)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_CanvasGradient_finalize)

static bool js_engine_CanvasGradient_constructor(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasGradient* cobj = new (std::nothrow) cocos2d::CanvasGradient();
    s.thisObject(inst)->setPrivateData(cobj);
    inst->getNoneRefNativePtrMap().emplace(cobj);
    return true;
}
SE_BIND_CTOR(js_engine_CanvasGradient_constructor, __jsb_cocos2d_CanvasGradient_class, js_cocos2d_CanvasGradient_finalize)




static bool js_cocos2d_CanvasGradient_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::CanvasGradient)", s.nativeThisObject());
    auto iter = inst->getNoneRefNativePtrMap().find(s.nativeThisObject());
    if (iter != inst->getNoneRefNativePtrMap().end())
    {
        inst->getNoneRefNativePtrMap().erase(iter);
        cocos2d::CanvasGradient* cobj = (cocos2d::CanvasGradient*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_CanvasGradient_finalize)

bool js_register_engine_CanvasGradient(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "CanvasGradient", obj, nullptr, _SE(js_engine_CanvasGradient_constructor));

    cls->defineFunction(inst, "addColorStop", _SE(js_engine_CanvasGradient_addColorStop));
    cls->defineFinalizeFunction(_SE(js_cocos2d_CanvasGradient_finalize));
    cls->install(inst );
    inst->registerClass<cocos2d::CanvasGradient>(cls);

    __jsb_cocos2d_CanvasGradient_proto = cls->getProto();
    __jsb_cocos2d_CanvasGradient_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_cocos2d_CanvasRenderingContext2D_proto = nullptr;
se::Class* __jsb_cocos2d_CanvasRenderingContext2D_class = nullptr;

static bool js_engine_CanvasRenderingContext2D_restore(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_restore : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->restore();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_restore)

static bool js_engine_CanvasRenderingContext2D_moveTo(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_moveTo : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_moveTo : Error processing arguments");
        cobj->moveTo(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_moveTo)

static bool js_engine_CanvasRenderingContext2D_lineTo(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_lineTo : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_lineTo : Error processing arguments");
        cobj->lineTo(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_lineTo)

static bool js_engine_CanvasRenderingContext2D_setPremultiply(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_setPremultiply : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_setPremultiply : Error processing arguments");
        cobj->setPremultiply(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_setPremultiply)

static bool js_engine_CanvasRenderingContext2D_setTransform(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_setTransform : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 6) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        float arg5 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_float(inst, args[4], &arg4);
        ok &= seval_to_float(inst, args[5], &arg5);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_setTransform : Error processing arguments");
        cobj->setTransform(arg0, arg1, arg2, arg3, arg4, arg5);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 6);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_setTransform)

static bool js_engine_CanvasRenderingContext2D_stroke(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_stroke : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->stroke();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_stroke)

static bool js_engine_CanvasRenderingContext2D_measureText(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_measureText : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_measureText : Error processing arguments");
        cocos2d::Size result = cobj->measureText(arg0);
        ok &= Size_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_measureText : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_measureText)

static bool js_engine_CanvasRenderingContext2D_fill(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_fill : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->fill();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_fill)

static bool js_engine_CanvasRenderingContext2D__fillImageData(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D__fillImageData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 5) {
        cocos2d::Data arg0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        ok &= seval_to_Data(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_float(inst, args[4], &arg4);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D__fillImageData : Error processing arguments");
        cobj->_fillImageData(arg0, arg1, arg2, arg3, arg4);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D__fillImageData)

static bool js_engine_CanvasRenderingContext2D_scale(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_scale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_scale : Error processing arguments");
        cobj->scale(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_scale)

static bool js_engine_CanvasRenderingContext2D_clearRect(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_clearRect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_clearRect : Error processing arguments");
        cobj->clearRect(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_clearRect)

static bool js_engine_CanvasRenderingContext2D_transform(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_transform : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 6) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        float arg5 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_float(inst, args[4], &arg4);
        ok &= seval_to_float(inst, args[5], &arg5);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_transform : Error processing arguments");
        cobj->transform(arg0, arg1, arg2, arg3, arg4, arg5);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 6);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_transform)

static bool js_engine_CanvasRenderingContext2D_fillText(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_fillText : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        std::string arg0;
        float arg1 = 0;
        float arg2 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_fillText : Error processing arguments");
        cobj->fillText(arg0, arg1, arg2);
        return true;
    }
    if (argc == 4) {
        std::string arg0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_fillText : Error processing arguments");
        cobj->fillText(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_fillText)

static bool js_engine_CanvasRenderingContext2D_strokeText(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_strokeText : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        std::string arg0;
        float arg1 = 0;
        float arg2 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_strokeText : Error processing arguments");
        cobj->strokeText(arg0, arg1, arg2);
        return true;
    }
    if (argc == 4) {
        std::string arg0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_strokeText : Error processing arguments");
        cobj->strokeText(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_strokeText)

static bool js_engine_CanvasRenderingContext2D_save(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_save : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->save();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_save)

static bool js_engine_CanvasRenderingContext2D_fillRect(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_fillRect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_fillRect : Error processing arguments");
        cobj->fillRect(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_fillRect)

static bool js_engine_CanvasRenderingContext2D_rotate(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_rotate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_rotate : Error processing arguments");
        cobj->rotate(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_rotate)

static bool js_engine_CanvasRenderingContext2D_beginPath(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_beginPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->beginPath();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_beginPath)

static bool js_engine_CanvasRenderingContext2D_rect(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_rect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_rect : Error processing arguments");
        cobj->rect(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_rect)

static bool js_engine_CanvasRenderingContext2D_translate(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_translate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_translate : Error processing arguments");
        cobj->translate(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_translate)

static bool js_engine_CanvasRenderingContext2D_createLinearGradient(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_createLinearGradient : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_createLinearGradient : Error processing arguments");
        cocos2d::CanvasGradient* result = cobj->createLinearGradient(arg0, arg1, arg2, arg3);
        ok &= native_ptr_to_seval<cocos2d::CanvasGradient>(inst, (cocos2d::CanvasGradient*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_createLinearGradient : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_createLinearGradient)

static bool js_engine_CanvasRenderingContext2D_closePath(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_CanvasRenderingContext2D_closePath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->closePath();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_CanvasRenderingContext2D_closePath)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_CanvasRenderingContext2D_finalize)

static bool js_engine_CanvasRenderingContext2D_constructor(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    float arg0 = 0;
    float arg1 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    ok &= seval_to_float(inst, args[1], &arg1);
    SE_PRECONDITION2(ok, false, "js_engine_CanvasRenderingContext2D_constructor : Error processing arguments");
    cocos2d::CanvasRenderingContext2D* cobj = new (std::nothrow) cocos2d::CanvasRenderingContext2D(arg0, arg1);
    s.thisObject(inst)->setPrivateData(cobj);
    inst->getNoneRefNativePtrMap().emplace(cobj);
    return true;
}
SE_BIND_CTOR(js_engine_CanvasRenderingContext2D_constructor, __jsb_cocos2d_CanvasRenderingContext2D_class, js_cocos2d_CanvasRenderingContext2D_finalize)




static bool js_cocos2d_CanvasRenderingContext2D_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::CanvasRenderingContext2D)", s.nativeThisObject());
    auto iter = inst->getNoneRefNativePtrMap().find(s.nativeThisObject());
    if (iter != inst->getNoneRefNativePtrMap().end())
    {
        inst->getNoneRefNativePtrMap().erase(iter);
        cocos2d::CanvasRenderingContext2D* cobj = (cocos2d::CanvasRenderingContext2D*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_CanvasRenderingContext2D_finalize)

bool js_register_engine_CanvasRenderingContext2D(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "CanvasRenderingContext2D", obj, nullptr, _SE(js_engine_CanvasRenderingContext2D_constructor));

    cls->defineFunction(inst, "restore", _SE(js_engine_CanvasRenderingContext2D_restore));
    cls->defineFunction(inst, "moveTo", _SE(js_engine_CanvasRenderingContext2D_moveTo));
    cls->defineFunction(inst, "lineTo", _SE(js_engine_CanvasRenderingContext2D_lineTo));
    cls->defineFunction(inst, "setPremultiply", _SE(js_engine_CanvasRenderingContext2D_setPremultiply));
    cls->defineFunction(inst, "setTransform", _SE(js_engine_CanvasRenderingContext2D_setTransform));
    cls->defineFunction(inst, "stroke", _SE(js_engine_CanvasRenderingContext2D_stroke));
    cls->defineFunction(inst, "measureText", _SE(js_engine_CanvasRenderingContext2D_measureText));
    cls->defineFunction(inst, "fill", _SE(js_engine_CanvasRenderingContext2D_fill));
    cls->defineFunction(inst, "_fillImageData", _SE(js_engine_CanvasRenderingContext2D__fillImageData));
    cls->defineFunction(inst, "scale", _SE(js_engine_CanvasRenderingContext2D_scale));
    cls->defineFunction(inst, "clearRect", _SE(js_engine_CanvasRenderingContext2D_clearRect));
    cls->defineFunction(inst, "transform", _SE(js_engine_CanvasRenderingContext2D_transform));
    cls->defineFunction(inst, "fillText", _SE(js_engine_CanvasRenderingContext2D_fillText));
    cls->defineFunction(inst, "strokeText", _SE(js_engine_CanvasRenderingContext2D_strokeText));
    cls->defineFunction(inst, "save", _SE(js_engine_CanvasRenderingContext2D_save));
    cls->defineFunction(inst, "fillRect", _SE(js_engine_CanvasRenderingContext2D_fillRect));
    cls->defineFunction(inst, "rotate", _SE(js_engine_CanvasRenderingContext2D_rotate));
    cls->defineFunction(inst, "beginPath", _SE(js_engine_CanvasRenderingContext2D_beginPath));
    cls->defineFunction(inst, "rect", _SE(js_engine_CanvasRenderingContext2D_rect));
    cls->defineFunction(inst, "translate", _SE(js_engine_CanvasRenderingContext2D_translate));
    cls->defineFunction(inst, "createLinearGradient", _SE(js_engine_CanvasRenderingContext2D_createLinearGradient));
    cls->defineFunction(inst, "closePath", _SE(js_engine_CanvasRenderingContext2D_closePath));
    cls->defineFinalizeFunction(_SE(js_cocos2d_CanvasRenderingContext2D_finalize));
    cls->install(inst);
    inst->registerClass<cocos2d::CanvasRenderingContext2D>(cls);

    __jsb_cocos2d_CanvasRenderingContext2D_proto = cls->getProto();
    __jsb_cocos2d_CanvasRenderingContext2D_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_cocos2d_LabelRenderer_proto = nullptr;
se::Class* __jsb_cocos2d_LabelRenderer_class = nullptr;

static bool js_engine_LabelRenderer_setEffect(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::LabelRenderer* cobj = (cocos2d::LabelRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_LabelRenderer_setEffect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::renderer::EffectVariant* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_LabelRenderer_setEffect : Error processing arguments");
        cobj->setEffect(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_LabelRenderer_setEffect)

static bool js_engine_LabelRenderer_bindNodeProxy(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::LabelRenderer* cobj = (cocos2d::LabelRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_LabelRenderer_bindNodeProxy : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::renderer::NodeProxy* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_LabelRenderer_bindNodeProxy : Error processing arguments");
        cobj->bindNodeProxy(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_LabelRenderer_bindNodeProxy)

static bool js_engine_LabelRenderer_render(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::LabelRenderer* cobj = (cocos2d::LabelRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_LabelRenderer_render : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->render();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_LabelRenderer_render)

static bool js_engine_LabelRenderer_setJsComponent(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::LabelRenderer* cobj = (cocos2d::LabelRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_LabelRenderer_setJsComponent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        se::Object* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_engine_LabelRenderer_setJsComponent : Error processing arguments");
        cobj->setJsComponent(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_engine_LabelRenderer_setJsComponent)

static bool js_engine_LabelRenderer_getJsComponent(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::LabelRenderer* cobj = (cocos2d::LabelRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_engine_LabelRenderer_getJsComponent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        se::Object* result = cobj->getJsComponent();
        ok &= native_ptr_to_seval<se::Object>(inst, (se::Object*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_engine_LabelRenderer_getJsComponent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_engine_LabelRenderer_getJsComponent)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_LabelRenderer_finalize)

static bool js_engine_LabelRenderer_constructor(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::LabelRenderer* cobj = new (std::nothrow) cocos2d::LabelRenderer();
    s.thisObject(inst)->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_engine_LabelRenderer_constructor, __jsb_cocos2d_LabelRenderer_class, js_cocos2d_LabelRenderer_finalize)

static bool js_engine_LabelRenderer_ctor(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::LabelRenderer* cobj = new (std::nothrow) cocos2d::LabelRenderer();
    s.thisObject(inst)->setPrivateData(cobj);
    return true;
}
SE_BIND_SUB_CLS_CTOR(js_engine_LabelRenderer_ctor, __jsb_cocos2d_LabelRenderer_class, js_cocos2d_LabelRenderer_finalize)


    


static bool js_cocos2d_LabelRenderer_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::LabelRenderer)", s.nativeThisObject());
    cocos2d::LabelRenderer* cobj = (cocos2d::LabelRenderer*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_LabelRenderer_finalize)

bool js_register_engine_LabelRenderer(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "LabelRenderer", obj, nullptr, _SE(js_engine_LabelRenderer_constructor));

    cls->defineFunction(inst, "setEffect", _SE(js_engine_LabelRenderer_setEffect));
    cls->defineFunction(inst, "bindNodeProxy", _SE(js_engine_LabelRenderer_bindNodeProxy));
    cls->defineFunction(inst, "render", _SE(js_engine_LabelRenderer_render));
    cls->defineFunction(inst, "setJsComponent", _SE(js_engine_LabelRenderer_setJsComponent));
    cls->defineFunction(inst, "getJsComponent", _SE(js_engine_LabelRenderer_getJsComponent));
    cls->defineFunction(inst, "ctor", _SE(js_engine_LabelRenderer_ctor));
    cls->defineFinalizeFunction(_SE(js_cocos2d_LabelRenderer_finalize));
    cls->install(inst);
    inst->registerClass<cocos2d::LabelRenderer>(cls);

    __jsb_cocos2d_LabelRenderer_proto = cls->getProto();
    __jsb_cocos2d_LabelRenderer_class = cls;

    jsb_set_extend_property(inst, "jsb", "LabelRenderer");
    inst->clearException();
    return true;
}

bool register_all_engine(se::ScriptEngine *inst, se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("jsb", &nsVal))
    {
        se::HandleObject jsobj(se::Object::createPlainObject(inst));
        nsVal.setObject(jsobj);
        obj->setProperty("jsb", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_engine_CanvasGradient(inst, ns);
    js_register_engine_LabelRenderer(inst, ns);
    js_register_engine_CanvasRenderingContext2D(inst, ns);
    js_register_engine_Device(inst, ns);
    js_register_engine_SAXParser(inst, ns);
    js_register_engine_FileUtils(inst, ns);
    return true;
}

