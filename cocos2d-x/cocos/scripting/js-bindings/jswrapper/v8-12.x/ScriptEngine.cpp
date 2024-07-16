/****************************************************************************
 Copyright (c) 2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "ScriptEngine.hpp"
#include "Value.hpp"
#include "platform/CCPlatformConfig.h"
#include "base/ccConfig.h"
#include "base/ccUtils.h"
#include <memory>

#if SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8

#include "Object.hpp"
#include "Class.hpp"
#include "Utils.hpp"
#include "../State.hpp"
#include "../MappingUtils.hpp"

#include "platform/CCApplication.h"

#include <sstream>
#include <mutex>

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include <sys/sysctl.h>
#include <sys/types.h>
#include <mach/machine.h>
#include <string.h>
#include <iostream>
#endif

#if SE_ENABLE_INSPECTOR
#include "debugger/inspector_agent.h"
#include "debugger/env.h"
#include "debugger/node.h"
#endif

#define EXPOSE_GC "__jsb_gc__"

uint32_t __jsbInvocationCount = 0;
uint32_t __jsbStackFrameLimit = 20;

#if __ANDROID__
#include <cstdio>
#include <unistd.h>
FILE *stdinRedirect{nullptr};
FILE *stdoutRedirect{nullptr};
FILE *stderrRedirect{nullptr};
#endif

#define RETRUN_VAL_IF_FAIL(cond, val) \
    if (!(cond)) return val

namespace se {

//    Class* __jsb_CCPrivateData_class = nullptr;

    namespace {

        void __log(const v8::FunctionCallbackInfo<v8::Value>& info)
        {
            if (info[0]->IsString())
            {
                v8::String::Utf8Value utf8(info.GetIsolate(), info[0]);
                SE_LOGD("JS: %s\n", *utf8);
            }
        }

        void __forceGC(const v8::FunctionCallbackInfo<v8::Value>& info)
        {
            auto *scriptEngine = reinterpret_cast<ScriptEngine*>(info.GetIsolate()->GetData(0));
            scriptEngine->garbageCollect();
        }

        std::string stackTraceToString(v8::Isolate *isolate, v8::Local<v8::StackTrace> stack)
        {
            std::string stackStr;
            if (stack.IsEmpty())
                return stackStr;

            char tmp[100] = {0};
            for (int i = 0, e = stack->GetFrameCount(); i < e; ++i)
            {
                v8::Local<v8::StackFrame> frame = stack->GetFrame(isolate, i);
                v8::Local<v8::String> script = frame->GetScriptName();
                std::string scriptName;
                if (!script.IsEmpty())
                {
                    scriptName = *v8::String::Utf8Value(isolate, script);
                }

                v8::Local<v8::String> func = frame->GetFunctionName();
                std::string funcName;
                if (!func.IsEmpty())
                {
                    funcName = *v8::String::Utf8Value(isolate, func);
                }

                stackStr += "[";
                snprintf(tmp, sizeof(tmp), "%d", i);
                stackStr += tmp;
                stackStr += "]";
                stackStr += (funcName.empty() ? "anonymous" : funcName.c_str());
                stackStr += "@";
                stackStr += (scriptName.empty() ? "(no filename)" : scriptName.c_str());
                stackStr += ":";
                snprintf(tmp, sizeof(tmp), "%d", frame->GetLineNumber());
                stackStr += tmp;

                if (i < (e-1))
                {
                    stackStr += "\n";
                }
            }

            return stackStr;
        }



        bool JSB_console_format_log(se::ScriptEngine *inst, State& s, const char* prefix, int msgIndex = 0)
        {
            if (msgIndex < 0)
                return false;

            const auto& args = s.args();
            int argc = (int)args.size();
            auto *worker = inst->getWorker();
            char tid[64] ={};
            if(worker) {
                snprintf(tid, 64, "<%s>", worker->getName().c_str());
            }
            if ((argc - msgIndex) == 1)
            {
                std::string msg = args[msgIndex].toStringForce();
                SE_LOGD("JS%s: %s%s\n", tid, prefix, msg.c_str());
            }
            else if (argc > 1)
            {
                std::string msg = args[msgIndex].toStringForce();
                size_t pos;
                for (int i = (msgIndex+1); i < argc; ++i)
                {
                    pos = msg.find("%");
                    if (pos != std::string::npos && pos != (msg.length()-1) && (msg[pos+1] == 'd' || msg[pos+1] == 's' || msg[pos+1] == 'f'))
                    {
                        msg.replace(pos, 2, args[i].toStringForce());
                    }
                    else
                    {
                        msg += " " + args[i].toStringForce();
                    }
                }

                SE_LOGD("JS%s: %s%s\n", tid, prefix, msg.c_str());
            }

            return true;
        }

        bool JSB_console_log(State& s, ScriptEngine *inst)
        {
            JSB_console_format_log(inst, s, "");
            inst->__oldConsoleLog->toObject()->call(s.args(), s.thisObject(inst));
            return true;
        }
        SE_BIND_FUNC(JSB_console_log)

        bool JSB_console_debug(State& s, ScriptEngine *inst)
        {
            JSB_console_format_log(inst, s, "[DEBUG]: ");
            inst->__oldConsoleDebug->toObject()->call(s.args(), s.thisObject(inst));
            return true;
        }
        SE_BIND_FUNC(JSB_console_debug)

        bool JSB_console_info(State& s, ScriptEngine *inst)
        {
            JSB_console_format_log(inst, s, "[INFO]: ");
            inst->__oldConsoleInfo->toObject()->call(s.args(), s.thisObject(inst));
            return true;
        }
        SE_BIND_FUNC(JSB_console_info)

        bool JSB_console_warn(State& s, ScriptEngine *inst)
        {
            JSB_console_format_log(inst, s, "[WARN]: ");
            inst->__oldConsoleWarn->toObject()->call(s.args(), s.thisObject(inst));
            return true;
        }
        SE_BIND_FUNC(JSB_console_warn)

        bool JSB_console_error(State& s, ScriptEngine *inst)
        {
            JSB_console_format_log(inst, s, "[ERROR]: ");
            inst->__oldConsoleError->toObject()->call(s.args(), s.thisObject(inst));
            return true;
        }
        SE_BIND_FUNC(JSB_console_error)

        bool JSB_console_assert(State& s, ScriptEngine *inst)
        {
            const auto& args = s.args();
            if (!args.empty())
            {
                if (args[0].isBoolean() && !args[0].toBoolean())
                {
                    JSB_console_format_log(inst, s, "[ASSERT]: ", 1);
                    inst->__oldConsoleAssert->toObject()->call(s.args(), s.thisObject(inst));
                }
            }
            return true;
        }
        SE_BIND_FUNC(JSB_console_assert)

        bool JSB_fn_setTimeout(se::State &state, se::ScriptEngine *inst) {
            auto argN = state.args().size();
            se::Value fn = state.args()[0];
            float ms = argN > 0 ? state.args()[1].toNumber() : 0;

            assert(fn.isObject());
            assert(fn.toObject()->isRooted());
            
            auto *timer = inst->getTimer();
            int tid = timer->setTimeout(ms / 1000.0F, [ fn = std::move(fn), inst](){
                se::AutoHandleScope scope(inst);
                if(fn.isObject() && fn.toObject()->isFunction()){
                    fn.toObject()->call({}, nullptr);
                }
            });
            state.rval().setInt32(tid);
            if(ms == 0) {
                inst->performMainLoopUpdate();
            }
            return true;
        }
        SE_BIND_FUNC(JSB_fn_setTimeout)

        bool JSB_fn_clearTimeout(se::State &state, se::ScriptEngine *inst) {
            int tid = state.args()[0].toInt32();
            auto *timer = inst->getTimer();
            timer->clearTimeout(tid);
            return true;
        }
        SE_BIND_FUNC(JSB_fn_clearTimeout)

        bool JSB_fn_setInterval(se::State &state, se::ScriptEngine *inst) {
            auto argN = state.args().size();
            se::Value fn = state.args()[0];
            assert(fn.isObject());
            assert(fn.toObject()->isRooted());
            float ms = argN > 0 ? state.args()[1].toNumber() : 0;
            int tid = inst->getTimer()->setInterval(ms / 1000.0F, [fn = std::move(fn), inst](float dt){
                se::AutoHandleScope scope(inst);
                if(fn.isObject() && fn.toObject()->isFunction()){
                    fn.toObject()->call({se::Value(dt)}, nullptr);
                }
            });
            state.rval().setInt32(tid);
            return true;
        }
        SE_BIND_FUNC(JSB_fn_setInterval)

        bool JSB_fn_clearInterval(se::State &state, se::ScriptEngine *inst) {
            int tid = state.args()[0].toInt32();
            inst->getTimer()->clearInterval(tid);
            return true;
        }
        SE_BIND_FUNC(JSB_fn_clearInterval)

#define JSB_get_method(method) \
        bool JSB_get_##method(se::State &state, se::ScriptEngine *inst){ \
           se::Value out; \
           inst->getGlobalObject()->getProperty("_" #method, &out); \
           state.rval() = out; \
           return true; \
        }                      \
        SE_BIND_PROP_GET(JSB_get_##method)

        JSB_get_method(setTimeout)
        JSB_get_method(clearTimeout)
        JSB_get_method(setInterval)
        JSB_get_method(clearInterval)

        bool JSB_set_setTimeout(se::State &state, se::ScriptEngine *inst) {
            SE_LOGD("try to overwrite <%s>\n", __FUNCTION__ );
            return true;
        }
        SE_BIND_PROP_SET(JSB_set_setTimeout)
        bool JSB_set_clearTimeout(se::State &state, se::ScriptEngine *inst) {
            SE_LOGD("try to overwrite <%s>\n", __FUNCTION__ );
            return true;
        }
        SE_BIND_PROP_SET(JSB_set_clearTimeout)
        bool JSB_set_setInterval(se::State &state, se::ScriptEngine *inst) {
            SE_LOGD("try to overwrite <%s>\n", __FUNCTION__ );
            return true;
        }
        SE_BIND_PROP_SET(JSB_set_setInterval)
        bool JSB_set_clearInterval(se::State &state, se::ScriptEngine *inst) {
            SE_LOGD("try to overwrite <%s>\n", __FUNCTION__ );
            return true;
        }
        SE_BIND_PROP_SET(JSB_set_clearInterval)

        #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        /**
         *  JIT is enabled on iOS 14.2+ & chipset A12+
         *  ref https://github.com/flutter/engine/pull/22377
         */
        bool jitSupported() {
            #if CC_IOS_FORCE_DISABLE_JIT
            return false;
            #elif TARGET_CPU_X86 || TARGET_CPU_X86_64
            return true;
            #else
            
            // Check for arm64e.
            cpu_type_t cpuType = 0;
            size_t cpuTypeSize = sizeof(cpu_type_t);
            if (::sysctlbyname("hw.cputype", &cpuType, &cpuTypeSize, nullptr, 0) < 0) {
                SE_LOGD("Could not execute sysctl() to get CPU type: %s", strerror(errno));
            }
            
            cpu_subtype_t cpuSubType = 0;
            if (::sysctlbyname("hw.cpusubtype", &cpuSubType, &cpuTypeSize, nullptr, 0) < 0) {
                SE_LOGD("Could not execute sysctl() to get CPU subtype: %s", strerror(errno));
            }
            
            // Tracing is necessary unless the device is arm64e (A12 chip or higher).
            if (cpuType != CPU_TYPE_ARM64 || cpuSubType != CPU_SUBTYPE_ARM64E) {
                return false;
            }
            
            // Check for iOS 14.2 and higher.
            size_t osVersionSize;
            ::sysctlbyname("kern.osversion", NULL, &osVersionSize, NULL, 0);
            char osversionBuffer[osVersionSize];
            
            if (::sysctlbyname("kern.osversion", osversionBuffer, &osVersionSize, NULL, 0) < 0) {
                SE_LOGD("Could not execute sysctl() to get current OS version: %s", strerror(errno));
                return false;
            }
            
            int majorVersion = 0;
            char minorLetter = 'Z';
            
            for (size_t index = 0; index < osVersionSize; index++) {
                char version_char = osversionBuffer[index];
                // Find the minor version build letter.
                if (isalpha(version_char)) {
                    majorVersion = atoi((const char*)osversionBuffer);
                    minorLetter = toupper(version_char);
                    break;
                }
            }
            // 18B92 is iOS 14.2 beta release candidate where tracing became unnecessary.
            return majorVersion > 18 || (majorVersion == 18 && minorLetter >= 'B');
            #endif //TARGET_CPU_X86 || TARGET_CPU_X86_64
        }
        #endif //CC_TARGET_PLATFORM == CC_PLATFORM_IOS

        struct ScriptEngineSharedContext final {
            ScriptEngineSharedContext() {
                _platform = v8::platform::NewDefaultPlatform().release();
                v8::V8::InitializePlatform(_platform);

                std::string flags;
                //NOTICE: spaces are required between flags
                flags.append(" --expose-gc-as=" EXPOSE_GC);
                // flags.append(" --trace-gc"); // v8 trace gc
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
                if(!jitSupported()) {
                   flags.append(" --jitless");
                }
        #endif
                if(!flags.empty())
                {
                    v8::V8::SetFlagsFromString(flags.c_str(), (int)flags.length());
                }
                
                bool ok = v8::V8::Initialize();
                assert(ok);
                // hack for stdin/stdout/stderr symbols
#if __ANDROID__
                if (!stdinRedirect) stdinRedirect = fdopen(dup(STDIN_FILENO), "r");
                if (!stdoutRedirect) stdoutRedirect = fdopen(dup(STDOUT_FILENO), "w");
                if (!stderrRedirect) stderrRedirect = fdopen(dup(STDERR_FILENO), "w");
#endif
            }

            ~ScriptEngineSharedContext() {
                v8::V8::Dispose();
        //        v8::V8::ShutdownPlatform();
                v8::V8::DisposePlatform();
                delete _platform;
                _platform = nullptr;
#if __ANDROID__
                if (stdinRedirect) fclose(stdinRedirect);
                if (stdoutRedirect) fclose(stdoutRedirect);
                if (stderrRedirect) fclose(stderrRedirect);
                stdinRedirect = nullptr;
                stdoutRedirect = nullptr;
                stderrRedirect = nullptr;
#endif
            }
            v8::Platform *_platform{nullptr};
        };
        std::shared_ptr<ScriptEngineSharedContext> gSharedContext;


        void invokeHook(const std::tuple<std::string, std::function<void()>> &f) {
            const auto &tag = std::get<0>(f);
            if(!tag.empty()) {
                CCLOG("[ScriptEngine] invoke hook <%s>", tag.c_str());
            }
            std::get<1>(f)();
        }

        inline void invokeHook(const std::function<void()> &f) {
            f();
        }

    } // namespace {

    void ScriptEngine::callExceptionCallback(const char* location, const char* message, const char *stack) {
        if (_nativeExceptionCallback) {
            _nativeExceptionCallback(location, message, stack);
        }
        if (_jsExceptionCallback) {
            _jsExceptionCallback(location, message, stack);
        }
    }

    void ScriptEngine::onFatalErrorCallback(const char* location, const char* message)
    {
        std::string errorStr = "[FATAL ERROR] location: ";
        errorStr += location;
        errorStr += ", message: ";
        errorStr += message;

        SE_LOGE("%s\n", errorStr.c_str());

        GetCurrent()->callExceptionCallback(location, message, "(no stack information)");
    }

    void ScriptEngine::onOOMErrorCallback(const char* location, bool is_heap_oom)
    {
        std::string errorStr = "[OOM ERROR] location: ";
        errorStr += location;
        std::string message;
        message = "is heap out of memory: ";
        if (is_heap_oom)
            message += "true";
        else
            message += "false";

        errorStr += ", " + message;
        SE_LOGE("%s\n", errorStr.c_str());
        GetCurrent()->callExceptionCallback(location, message.c_str(), "(no stack information)");
        
    }

    void ScriptEngine::onMessageCallback(v8::Local<v8::Message> message, v8::Local<v8::Value> data)
    {
        auto *thiz = reinterpret_cast<ScriptEngine*>(v8::Isolate::GetCurrent()->GetData(0));
        v8::Local<v8::String> msg = message->Get();
        Value msgVal;
        internal::jsToSeValue(v8::Isolate::GetCurrent(), msg, &msgVal);
        assert(msgVal.isString());
        v8::ScriptOrigin origin = message->GetScriptOrigin();
        Value resouceNameVal;
        internal::jsToSeValue(v8::Isolate::GetCurrent(), origin.ResourceName(), &resouceNameVal);
        int line = origin.LineOffset();
        int columnOffset = origin.ColumnOffset();

        std::stringstream  locationBuf;
        locationBuf << resouceNameVal.toStringForce() << ":" << line << ":" << columnOffset;
        std::string location = locationBuf.str();

        std::string errorStr = msgVal.toString() + ", location: " + location;
        std::string stackStr = stackTraceToString(thiz->_isolate, message->GetStackTrace());
        if (!stackStr.empty())
        {
            if (line == 0)
            {
                location = "(see stack)";
            }
            errorStr += "\nSTACK:\n" + stackStr;
        }
        SE_LOGE("ERROR: %s\n", errorStr.c_str());

        thiz->callExceptionCallback(location.c_str(), msgVal.toString().c_str(), stackStr.c_str());

        if (!thiz->_isErrorHandleWorking)
        {
            thiz->_isErrorHandleWorking = true;

            Value errorHandler;
            if (thiz->_globalObj && thiz->_globalObj->getProperty("__errorHandler", &errorHandler) && errorHandler.isObject() && errorHandler.toObject()->isFunction())
            {
                ValueArray args;
                args.push_back(resouceNameVal);
                args.push_back(se::Value(line));
                args.push_back(msgVal);
                args.push_back(Value(stackStr));
                errorHandler.toObject()->call(args, thiz->_globalObj);
            }

            thiz->_isErrorHandleWorking = false;
        }
        else
        {
            SE_LOGE("ERROR: __errorHandler has exception\n");
        }
    }

    void ScriptEngine::onPromiseRejectCallback(v8::PromiseRejectMessage msg)
    {
        v8::Isolate *isolate = v8::Isolate::GetCurrent();
        v8::HandleScope scope(isolate);
        std::stringstream ss;
        auto event = msg.GetEvent();
        auto value = msg.GetValue();
        const char *eventName = "[invalidatePromiseEvent]";
        
        if(event == v8::kPromiseRejectWithNoHandler) {
            eventName = "unhandledRejectedPromise";
        }else if(event == v8::kPromiseHandlerAddedAfterReject) {
            eventName = "handlerAddedAfterPromiseRejected";
        }else if(event == v8::kPromiseRejectAfterResolved) {
            eventName = "rejectAfterPromiseResolved";
        }else if( event == v8::kPromiseResolveAfterResolved) {
            eventName = "resolveAfterPromiseResolved";
        }
        
        if(!value.IsEmpty()) {
            // prepend error object to stack message
            v8::Local<v8::String> str = value->ToString(isolate->GetCurrentContext()).ToLocalChecked();
            v8::String::Utf8Value valueUtf8(isolate, str);
            ss << *valueUtf8 << std::endl;
        }
        
        auto stackStr = GetCurrent()->getCurrentStackTrace();
        ss << "stacktrace: " << std::endl;
        ss << stackStr << std::endl;
        GetCurrent()->callExceptionCallback("", eventName, ss.str().c_str());
        
    }

    void ScriptEngine::privateDataFinalize(void* nativeObj)
    {
        internal::PrivateData* p = (internal::PrivateData*)nativeObj;

        Object::nativeObjectFinalizeHook(p->data);

        assert(p->seObj->getRefCount() == 1);

        p->seObj->decRef();

        free(p);
    }

    ScriptEngine *ScriptEngine::GetCurrent() {
        auto *isolate = v8::Isolate::GetCurrent();
        return reinterpret_cast<ScriptEngine*>(isolate->GetData(0));
    }

    void ScriptEngine::Destroy() {
        if(gSharedContext) {
            gSharedContext.reset();
        }
    }

    ScriptEngine::ScriptEngine()
    : _isolate(nullptr)
    , _handleScope(nullptr)
    , _globalObj(nullptr)
#if SE_ENABLE_INSPECTOR
    , _env(nullptr)
    , _isolateData(nullptr)
#endif
    , _debuggerServerPort(0)
    , _vmId(0)
    , _isValid(false)
    , _isGarbageCollecting(false)
    , _isInCleanup(false)
    , _isErrorHandleWorking(false)
    {
        if(!gSharedContext) {
            gSharedContext = std::make_shared<ScriptEngineSharedContext>();
        }
    }

    ScriptEngine::~ScriptEngine()
    {
        SE_LOGD("[ScriptEngine]: destroy\n");
        cleanup();
    }

    bool ScriptEngine::init()
    {
        cleanup();

        SE_LOGD("[ScriptEngine]: init\n");

        SE_LOGD("Initializing V8, version: %s\n", v8::V8::GetVersion());
        ++_vmId;

        _engineThreadId = std::this_thread::get_id();

        for (const auto& hook : _beforeInitHookArray)
        {
            invokeHook(hook);
        }
        _beforeInitHookArray.clear();
        v8::Isolate::CreateParams create_params;
        create_params.array_buffer_allocator = v8::ArrayBuffer::Allocator::NewDefaultAllocator();
        _isolate = v8::Isolate::New(create_params);

        assert(_isolate->GetNumberOfDataSlots() > 0);
        _isolate->SetData(0, this);

        v8::HandleScope hs(_isolate);
        _isolate->Enter();

        _isolate->SetCaptureStackTraceForUncaughtExceptions(true, __jsbStackFrameLimit, v8::StackTrace::kOverview);

        _isolate->SetFatalErrorHandler(onFatalErrorCallback);
//        _isolate->SetOOMErrorHandler(onOOMErrorCallback);
        _isolate->SetOOMErrorHandler(+[](const char *location, const v8::OOMDetails &details){
            onOOMErrorCallback(location, details.is_heap_oom);
        });
        _isolate->AddMessageListener(onMessageCallback);
        _isolate->SetPromiseRejectCallback(onPromiseRejectCallback);

        _context.Reset(_isolate, v8::Context::New(_isolate));
        _context.Get(_isolate)->Enter();

        _globalObj = Object::_createJSObject(this, nullptr, _context.Get(_isolate)->Global());
        _globalObj->root();
        _globalObj->setProperty("window", Value(_globalObj));

        _globalObj->defineFunction("_setTimeout", _SE(JSB_fn_setTimeout));
        _globalObj->defineFunction("_clearTimeout", _SE(JSB_fn_clearTimeout));
        _globalObj->defineFunction("_setInterval", _SE(JSB_fn_setInterval));
        _globalObj->defineFunction("_clearInterval", _SE(JSB_fn_clearInterval));

        _globalObj->defineProperty("setTimeout", _SE(JSB_get_setTimeout), _SE(JSB_set_setTimeout));
        _globalObj->defineProperty("clearTimeout", _SE(JSB_get_clearTimeout), _SE(JSB_set_clearTimeout));
        _globalObj->defineProperty("setInterval", _SE(JSB_get_setInterval), _SE(JSB_set_setInterval));
        _globalObj->defineProperty("clearInterval", _SE(JSB_get_clearInterval), _SE(JSB_set_clearInterval));


        se::Value consoleVal;
        if (_globalObj->getProperty("console", &consoleVal) && consoleVal.isObject())
        {
            __oldConsoleLog = new Value;
            __oldConsoleDebug = new Value;
            __oldConsoleInfo = new Value;
            __oldConsoleWarn = new Value;
            __oldConsoleError = new Value;
            __oldConsoleAssert = new Value;
            
            consoleVal.toObject()->getProperty("log", __oldConsoleLog);
            consoleVal.toObject()->defineFunction("log", _SE(JSB_console_log));

            consoleVal.toObject()->getProperty("debug", __oldConsoleDebug);
            consoleVal.toObject()->defineFunction("debug", _SE(JSB_console_debug));

            consoleVal.toObject()->getProperty("info", __oldConsoleInfo);
            consoleVal.toObject()->defineFunction("info", _SE(JSB_console_info));

            consoleVal.toObject()->getProperty("warn", __oldConsoleWarn);
            consoleVal.toObject()->defineFunction("warn", _SE(JSB_console_warn));

            consoleVal.toObject()->getProperty("error", __oldConsoleError);
            consoleVal.toObject()->defineFunction("error", _SE(JSB_console_error));

            consoleVal.toObject()->getProperty("assert", __oldConsoleAssert);
            consoleVal.toObject()->defineFunction("assert", _SE(JSB_console_assert));
        }

        _globalObj->setProperty("scriptEngineType", se::Value("V8"));

        _globalObj->defineFunction("log", __log);
        _globalObj->defineFunction("forceGC", __forceGC);
        
        
        _globalObj->getProperty(EXPOSE_GC, &_gcFuncValue);
        if(_gcFuncValue.isObject() && _gcFuncValue.toObject()->isFunction()) {
            _gcFunc = _gcFuncValue.toObject();
        } else {
            _gcFunc = nullptr;
        }
        

        __jsb_CCPrivateData_class = Class::create(this, "__PrivateData", _globalObj, nullptr, nullptr);
        __jsb_CCPrivateData_class->defineFinalizeFunction(privateDataFinalize);
        __jsb_CCPrivateData_class->setCreateProto(false);
        __jsb_CCPrivateData_class->install(this);

        _isValid = true;

        for (const auto& hook : _afterInitHookArray)
        {
            invokeHook(hook);
        }
        _afterInitHookArray.clear();

        return _isValid;
    }

    void ScriptEngine::cleanup()
    {
        if (!_isValid) {
            SE_LOGD("[ScriptEngine]: cleanup skip, invalidate\n");
            return;
        }
        if(!_isolate) {
            SE_LOGD("[ScriptEngine]: cleanup skip, _isolate is nullptr\n");
            return;
        }

        SE_LOGD("ScriptEngine::cleanup begin ...\n");
        _isInCleanup = true;

        {
            AutoHandleScope hs(this);
            for (const auto& hook : _beforeCleanupHookArray)
            {
                invokeHook(hook);
            }
            _beforeCleanupHookArray.clear();

            SAFE_DEC_REF(_globalObj);
            Object::cleanup(this);
            Class::cleanup(this);
            garbageCollect();
            _gcFuncValue.setUndefined();

            CC_SAFE_DELETE(__oldConsoleLog);
            CC_SAFE_DELETE(__oldConsoleDebug);
            CC_SAFE_DELETE(__oldConsoleInfo);
            CC_SAFE_DELETE(__oldConsoleWarn);
            CC_SAFE_DELETE(__oldConsoleError);
            CC_SAFE_DELETE(__oldConsoleAssert);

#if SE_ENABLE_INSPECTOR
            if (_isolateData != nullptr)
            {
                node::FreeIsolateData(_isolateData);
                _isolateData = nullptr;
            }

            if (_env != nullptr)
            {
                _env->inspector_agent()->Stop();
                _env->CleanupHandles();
                node::FreeEnvironment(_env);
                _env = nullptr;
            }
#endif

            _context.Get(_isolate)->Exit();
            _context.Reset();
            _isolate->TerminateExecution();
            _isolate->Exit();
        }
        _isolate->Dispose();

        _isolate = nullptr;
        _globalObj = nullptr;
        _isValid = false;

        _registerCallbackArray.clear();

        for (const auto& hook : _afterCleanupHookArray)
        {
            invokeHook(hook);
        }
        _afterCleanupHookArray.clear();

        _isInCleanup = false;
        _nativePtrToObjectMap.clear();
        _nonRefNativePtrToObjectMap.clear();
        _objectsMap.clear();
        _gcFunc = nullptr;
        SE_LOGD("ScriptEngine::cleanup end ...\n");
    }

    Object* ScriptEngine::getGlobalObject() const
    {
        return _globalObj;
    }

    void ScriptEngine::addBeforeInitHook(const std::function<void()>& hook, std::string_view msg)
    {
#if COCOS2D_DEBUG > 0
        _beforeInitHookArray.emplace_back(msg, hook);
#else
        _beforeInitHookArray.push_back(hook);
#endif
    }

    void ScriptEngine::addAfterInitHook(const std::function<void()>& hook, std::string_view msg)
    {
#if COCOS2D_DEBUG > 0
        _afterInitHookArray.emplace_back(msg, hook);
#else
        _afterInitHookArray.push_back(hook);
#endif
    }

    void ScriptEngine::addBeforeCleanupHook(const std::function<void()>& hook, std::string_view msg)
    {
#if COCOS2D_DEBUG > 0
        _beforeCleanupHookArray.emplace_back(msg, hook);
#else
        _beforeCleanupHookArray.push_back(hook);
#endif
    }

    void ScriptEngine::addAfterCleanupHook(const std::function<void()>& hook, std::string_view msg)
    {
#if COCOS2D_DEBUG > 0
        _afterCleanupHookArray.emplace_back(msg, hook);
#else
        _afterCleanupHookArray.push_back(hook);
#endif
    }

    void ScriptEngine::addRegisterCallback(RegisterCallback cb)
    {
        assert(std::find(_registerCallbackArray.begin(), _registerCallbackArray.end(), cb) == _registerCallbackArray.end());
        _registerCallbackArray.push_back(cb);
    }

    bool ScriptEngine::start()
    {
        if (!init())
            return false;

        se::AutoHandleScope hs(this);

        // debugger
        if (isDebuggerEnabled())
        {
#if SE_ENABLE_INSPECTOR
            // V8 inspector stuff, most code are taken from NodeJS.
            _isolateData = node::CreateIsolateData(_isolate, uv_default_loop());
            _env = node::CreateEnvironment(_isolateData, _context.Get(_isolate), 0, nullptr, 0, nullptr);

            node::DebugOptions options;
            options.set_wait_for_connect(_isWaitForConnect);// the program will be hung up until debug attach if _isWaitForConnect = true
            options.set_inspector_enabled(true);
            options.set_port((int)_debuggerServerPort);
            options.set_host_name(_debuggerServerAddr.c_str());
            bool ok = _env->inspector_agent()->Start(gSharedContext->_platform, "", options);
            assert(ok);
#endif
        }
        //
        bool ok = false;
        _startTime = std::chrono::steady_clock::now();

        for (auto cb : _registerCallbackArray)
        {
            ok = cb(this, _globalObj);
            assert(ok);
            if (!ok)
                break;
        }

        // After ScriptEngine is started, _registerCallbackArray isn't needed. Therefore, clear it here.
        _registerCallbackArray.clear();

        return ok;
    }

    void ScriptEngine::garbageCollect()
    {
        int objSize =  (int)_objectsMap.size();
        SE_LOGD("GC begin ..., (js->native map) size: %d, all objects: %d\n", (int)_nativePtrToObjectMap.size(), objSize);
        
        if(_gcFunc == nullptr)
        {
            const double kLongIdlePauseInSeconds = 1.0;
            _isolate->ContextDisposedNotification();
            _isolate->IdleNotificationDeadline(gSharedContext->_platform->MonotonicallyIncreasingTime() + kLongIdlePauseInSeconds);
            // By sending a low memory notifications, we will try hard to collect all
            // garbage and will therefore also invoke all weak callbacks of actually
            // unreachable persistent handles.
            _isolate->LowMemoryNotification();
        }
        else
        {
            _gcFunc->call({}, nullptr);
        }
        objSize = (int)_objectsMap.size();
        
        SE_LOGD("GC end ..., (js->native map) size: %d, all objects: %d\n", (int)_nativePtrToObjectMap.size(), objSize);
    }

    bool ScriptEngine::isGarbageCollecting()
    {
        return _isGarbageCollecting;
    }

    void ScriptEngine::_setGarbageCollecting(bool isGarbageCollecting)
    {
        _isGarbageCollecting = isGarbageCollecting;
    }

    bool ScriptEngine::isValid() const
    {
        return _isValid;
    }

    bool ScriptEngine::inMainThread() const {
        return _engineThreadId == std::this_thread::get_id();
    }

    void ScriptEngine::performMainLoopUpdate() {
        // getTimer()->dispatchTask([this](){
        //     checkTask();
        // },"scriptengine.mainloopupdate");
    }

    bool ScriptEngine::evalString(std::string_view script, Value* ret/* = nullptr */, std::string_view fileName)
    {
        if(_engineThreadId != std::this_thread::get_id())
        {
            // `evalString` should run in main thread
            assert(false);
            return false;
        }
        assert(!script.empty());
        if (fileName.empty())
            fileName = "(no filename)";

        // Fix the source url is too long displayed in Chrome debugger.
        std::string sourceUrl(fileName);
        static const std::string prefixKey = "/temp/quick-scripts/";
        size_t prefixPos = sourceUrl.find(prefixKey);
        if (prefixPos != std::string::npos)
        {
            sourceUrl = sourceUrl.substr(prefixPos + prefixKey.length());
        }

        // It is needed, or will crash if invoked from non C++ context, such as invoked from objective-c context(for example, handler of UIKit).
        v8::HandleScope handle_scope(_isolate);

        v8::MaybeLocal<v8::String> source = v8::String::NewFromUtf8(_isolate, script.data(), v8::NewStringType::kNormal, script.length());
        if (source.IsEmpty())
            return false;

        v8::MaybeLocal<v8::String> originStr = v8::String::NewFromUtf8(_isolate, sourceUrl.c_str(), v8::NewStringType::kNormal, sourceUrl.length());
        if (originStr.IsEmpty())
            return false;

        v8::ScriptOrigin origin(_isolate, originStr.ToLocalChecked());
        v8::MaybeLocal<v8::Script> maybeScript = v8::Script::Compile(_context.Get(_isolate), source.ToLocalChecked(), &origin);

        bool success = false;

        if (!maybeScript.IsEmpty())
        {
            v8::TryCatch block(_isolate);

            v8::Local<v8::Script> v8Script = maybeScript.ToLocalChecked();
            v8::MaybeLocal<v8::Value> maybeResult = v8Script->Run(_context.Get(_isolate));

            if (!maybeResult.IsEmpty())
            {
                v8::Local<v8::Value> result = maybeResult.ToLocalChecked();

                if (!result->IsUndefined() && ret != nullptr)
                {
                    internal::jsToSeValue(_isolate, result, ret);
                }

                success = true;
            }

            if (block.HasCaught()) {
                v8::Local<v8::Message> message = block.Message();
                SE_LOGE("ScriptEngine::evalString catch exception:\n");
                onMessageCallback(message, v8::Undefined(_isolate));
            }
        }

        if (!success)
        {
            SE_LOGE("ScriptEngine::evalString script %s, failed!\n", fileName.data());
        }
        return success;
    }

    std::string ScriptEngine::getCurrentStackTrace()
    {
        if (!_isValid)
            return std::string();

        v8::HandleScope hs(_isolate);
        v8::Local<v8::StackTrace> stack = v8::StackTrace::CurrentStackTrace(_isolate, __jsbStackFrameLimit, v8::StackTrace::kOverview);
        return stackTraceToString(_isolate, stack);
    }

    void ScriptEngine::setFileOperationDelegate(const FileOperationDelegate& delegate)
    {
        _fileOperationDelegate = delegate;
    }

    const ScriptEngine::FileOperationDelegate& ScriptEngine::getFileOperationDelegate() const
    {
        return _fileOperationDelegate;
    }

    bool ScriptEngine::runScript(std::string_view path, Value* ret/* = nullptr */)
    {
        assert(!path.empty());
        assert(_fileOperationDelegate.isValid());

        std::string scriptBuffer = _fileOperationDelegate.onGetStringFromFile(path);

        if (!scriptBuffer.empty())
        {
            return evalString(scriptBuffer, ret, path);
        }

        SE_LOGE("ScriptEngine::runScript script %s, buffer is empty!\n", path.data());
        return false;
    }

    void ScriptEngine::requestInterrupt(void (*callback)(void *), void *data) {
        using context_t = std::tuple<decltype(callback), void *>;
        _isolate->RequestInterrupt(
                +[](v8::Isolate * /*isolate*/, void *data) {
                    auto *ctx = reinterpret_cast<context_t *>(data);
                    std::get<0> (*ctx)(std::get<1>(*ctx));
                    delete ctx;
                },
                new context_t(callback, data));
    }

    void ScriptEngine::clearException()
    {
        //IDEA:
    }

    void ScriptEngine::setExceptionCallback(const ExceptionCallback& cb)
    {
        _nativeExceptionCallback = cb;
    }

    void ScriptEngine::setJSExceptionCallback(const ExceptionCallback& cb)
    {
        _jsExceptionCallback = cb;
    }

    v8::Local<v8::Context> ScriptEngine::_getContext() const
    {
        return _context.Get(_isolate);
    }

    void ScriptEngine::enableDebugger(const std::string& serverAddr, uint32_t port, bool isWait)
    {
        _debuggerServerAddr = serverAddr;
        _debuggerServerPort = port;
        _isWaitForConnect = isWait;
    }

    bool ScriptEngine::isDebuggerEnabled() const
    {
        return !_debuggerServerAddr.empty() && _debuggerServerPort > 0;
    }

    void ScriptEngine::mainLoopUpdate()
    {
        // empty implementation
    }

    std::unique_ptr<HeapInfo> ScriptEngine::getHeapInfo() {
        cocos2d::Perf perf("getHeapInfo");
        v8::HeapStatistics info;
        _isolate->GetHeapStatistics(&info);
        return std::make_unique<HeapInfo>(HeapInfo{
            .totalHeapSize = info.total_heap_size() >> 10,
            .totalHeapSizeExec = info.total_heap_size_executable() >> 10,
            .totalPhysicalSize = info.total_physical_size() >> 10,
            .totalAvailbleSize = info.total_available_size() >> 10,
            .usedHeapSize = info.used_heap_size() >> 10,
            .heapSizeLimit = info.heap_size_limit() >> 10,
            .peakMallocedMemory = info.peak_malloced_memory() >> 10,
        });
    }

    const char *ScriptEngine::getVMVersion() const { // NOLINT
        return v8::V8::GetVersion();
    }

    cc::TimerLoop *ScriptEngine::getTimer() const {
        if(_loop) {
            return _loop;
        } else {
            return cocos2d::Application::getInstance()->getTimer();
        }
    }

    void ScriptEngine::throwError(std::string_view message) {
        v8::HandleScope scope(_isolate);
        v8::MaybeLocal<v8::String> mstr = v8::String::NewFromUtf8(_isolate, message.data());
        _isolate->ThrowError(mstr.ToLocalChecked());
    }
    
    void ScriptEngine::enqueueTask(std::function<void()> &&task) {
        std::function<void()> *tsk = new std::function<void()>(std::move(task));
        _isolate->EnqueueMicrotask([](void*data){
            auto *fn = reinterpret_cast<std::function<void()>*>(data);
            (*fn)();
            delete fn;
        }, tsk);
    }

    void ScriptEngine::checkTask() {
        // TODO: 确保没有副作用
        _isolate->PerformMicrotaskCheckpoint();
    }

} // namespace se {

#endif // #if SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8
