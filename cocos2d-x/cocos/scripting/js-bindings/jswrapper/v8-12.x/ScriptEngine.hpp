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
#pragma once

#include "../config.hpp"
#include "Value.hpp"
#include <unordered_map>
#include <unordered_set>

#if SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8

#include "Base.h"
#include "../Value.hpp"

#include "platform/CCTimer.h"
#include "WebWorker.h"

#include <thread>
#include <tuple>

namespace node {
    namespace inspector {
        class Agent;
    }

    class Environment;
    class IsolateData;
}

namespace se {

    class Object;
    class Class;
    class Value;

    struct HeapInfo {
        size_t totalHeapSize;
        size_t totalHeapSizeExec;
        size_t totalPhysicalSize;
        size_t totalAvailbleSize;
        size_t usedHeapSize;
        size_t heapSizeLimit;
        size_t peakMallocedMemory;
    };

    /**
     * ScriptEngine is a sington which represents a context of JavaScript VM.
     */
    class ScriptEngine final
    {
    public:

        static ScriptEngine *GetCurrent();
        static void Destroy();

        ScriptEngine();
        
        ~ScriptEngine();
        
        /**
         *  @brief Gets the global object of JavaScript VM.
         *  @return The se::Object stores the global JavaScript object.
         */
        Object* getGlobalObject() const;

        typedef bool (*RegisterCallback)(ScriptEngine *, Object*);

        /**
         *  @brief Adds a callback for registering a native binding module.
         *  @param[in] cb A callback for registering a native binding module.
         *  @note This method just add a callback to a vector, callbacks is invoked in `start` method.
         */
        void addRegisterCallback(RegisterCallback cb);

        /**
         *  @brief Starts the script engine.
         *  @return true if succeed, otherwise false.
         *  @note This method will invoke all callbacks of native binding modules by the order of registration.
         */
        bool start();

        /**
         *  @brief Initializes script engine.
         *  @return true if succeed, otherwise false.
         *  @note This method will create JavaScript context and global object.
         */
        bool init();

        /**
         *  @brief Adds a hook function before initializing script engine.
         *  @param[in] hook A hook function to be invoked before initializing script engine.
         *  @note Multiple hook functions could be added, they will be invoked by the order of adding.
         */
        void addBeforeInitHook(const std::function<void()>& hook, std::string_view msg={});

        /**
         *  @brief Adds a hook function after initializing script engine.
         *  @param[in] hook A hook function to be invoked before initializing script engine.
         *  @note Multiple hook functions could be added, they will be invoked by the order of adding.
         */
        void addAfterInitHook(const std::function<void()>& hook, std::string_view msg={});

        /**
         *  @brief Cleanups script engine.
         *  @note This method will removes all objects in JavaScript VM even whose are rooted, then shutdown JavaScript VMf.
         */
        void cleanup();

        /**
         *  @brief Adds a hook function before cleanuping script engine.
         *  @param[in] hook A hook function to be invoked before cleanuping script engine.
         *  @note Multiple hook functions could be added, they will be invoked by the order of adding.
         */
        void addBeforeCleanupHook(const std::function<void()>& hook, std::string_view msg={});

        /**
         *  @brief Adds a hook function after cleanuping script engine.
         *  @param[in] hook A hook function to be invoked after cleanuping script engine.
         *  @note Multiple hook functions could be added, they will be invoked by the order of adding.
         */
        void addAfterCleanupHook(const std::function<void()>& hook, std::string_view msg={});

        /**
         *  @brief Executes a utf-8 string buffer which contains JavaScript code.
         *  @param[in] scriptStr A utf-8 string buffer, if it isn't null-terminated, parameter `length` should be assigned and > 0.
         *  @param[in] length The length of parameter `scriptStr`, it will be set to string length internally if passing < 0 and parameter `scriptStr` is null-terminated.
         *  @param[in] rval The se::Value that results from evaluating script. Passing nullptr if you don't care about the result.
         *  @param[in] fileName A string containing a URL for the script's source file. This is used by debuggers and when reporting exceptions. Pass NULL if you do not care to include source file information.
         *  @return true if succeed, otherwise false.
         */
        bool evalString(std::string_view script, Value* rval = nullptr, std::string_view fileName = {});

        /**
         * @brief Grab a snapshot of the current JavaScript execution stack.
         * @return current stack trace string
         */
        std::string getCurrentStackTrace();

        /**
         *  Delegate class for file operation
         */
        class FileOperationDelegate
        {
        public:
            FileOperationDelegate(): onGetStringFromFile(nullptr)
            , onCheckFileExist(nullptr)
            , onGetFullPath(nullptr)
            {}

            /**
             *  @brief Tests whether delegate is valid.
             */
            bool isValid() const {
                return onGetStringFromFile != nullptr
                && onCheckFileExist != nullptr
                && onGetFullPath != nullptr; }

            // path, return file string content.
            std::function<std::string(std::string_view)> onGetStringFromFile;
            // path
            std::function<bool(std::string_view)> onCheckFileExist;
            // path, return full path
            std::function<std::string(std::string_view)> onGetFullPath;
        };

        /**
         *  @brief Sets the delegate for file operation.
         *  @param delegate[in] The delegate instance for file operation.
         */
        void setFileOperationDelegate(const FileOperationDelegate& delegate);

        /**
         *  @brief Gets the delegate for file operation.
         *  @return The delegate for file operation
         */
        const FileOperationDelegate& getFileOperationDelegate() const;

        /**
         *  @brief Executes a file which contains JavaScript code.
         *  @param[in] path Script file path.
         *  @param[in] rval The se::Value that results from evaluating script. Passing nullptr if you don't care about the result.
         *  @return true if succeed, otherwise false.
         */
        bool runScript(std::string_view path, Value* rval = nullptr);

        /**
         *  @brief Tests whether script engine is doing garbage collection.
         *  @return true if it's in garbage collection, otherwise false.
         */
        bool isGarbageCollecting();

        /**
         *  @brief Performs a JavaScript garbage collection.
         */
        void garbageCollect();

        /**
         *  @brief Tests whether script engine is being cleaned up.
         *  @return true if it's in cleaning up, otherwise false.
         */
        bool isInCleanup() { return _isInCleanup; }

        /**
         *  @brief Tests whether script engine is valid.
         *  @return true if it's valid, otherwise false.
         */
        bool isValid() const;

        /**
         *  @brief Clears all exceptions.
         */
        void clearException();

        /**
         * @brief
         * This function asks ScriptEngine to interrupt lengthy JavaScript operations and run the provided callback, passing the supplied data to it.
         * Once the callback completes, control returns to the JavaScript code. Multiple interrupt requests may be ongoing.
         * This function can be called from a different thread without needing a Locker. The registered callback should not reenter the interrupted Isolate.
         * @param callback the callback to be called when interruption happens.
         * @param data the data to be passed to the callback
         */
        void requestInterrupt(void (*callback)(void *), void *data);

        using ExceptionCallback = std::function<void(const char*, const char*, const char*)>; // location, message, stack

        /**
         *  @brief Sets the callback function while an exception is fired.
         *  @param[in] cb The callback function to notify that an exception is fired.
         */
        void setExceptionCallback(const ExceptionCallback& cb);

        /**
         *  @brief Sets the callback function while an exception is fired in JS.
         *  @param[in] cb The callback function to notify that an exception is fired.
         */
        void setJSExceptionCallback(const ExceptionCallback& cb);


        /**
         *  @brief Gets the start time of script engine.
         *  @return The start time of script engine.
         */
        const std::chrono::steady_clock::time_point& getStartTime() const { return _startTime; }

        /**
         *  @brief Enables JavaScript debugger
         *  @param[in] serverAddr The address of debugger server.
         *  @param[in] isWait Whether wait debugger attach when loading.
         */
        void enableDebugger(const std::string& serverAddr, uint32_t port, bool isWait = false);

        /**
         *  @brief Tests whether JavaScript debugger is enabled
         *  @return true if JavaScript debugger is enabled, otherwise false.
         */
        bool isDebuggerEnabled() const;

        /**
         *  @brief Main loop update trigger, it's need to invoked in main thread every frame.
         */
        void mainLoopUpdate();
        
        bool inMainThread() const;
        
        void performMainLoopUpdate();
        
        std::unique_ptr<HeapInfo> getHeapInfo();

        const char *getVMVersion() const;

        /**
         *  @brief Gets script virtual machine instance ID. Default value is 1, increase by 1 if `init` is invoked.
         */
        uint32_t getVMId() const { return _vmId; }

        v8::Isolate* getIsolate() {return _isolate;}

        // Private API used in wrapper
        void _retainScriptObject(void* owner, void* target);
        void _releaseScriptObject(void* owner, void* target);
        v8::Local<v8::Context> _getContext() const;
        void _setGarbageCollecting(bool isGarbageCollecting);
        //

        auto &getNativePtrMap() { return _nativePtrToObjectMap; }
        auto &getNoneRefNativePtrMap() { return _nonRefNativePtrToObjectMap; }
        auto &getClasses() {return  _classTypeMap;}
        auto &getObjects() {return  _objectsMap;}
        template<typename T>
        void registerClass(Class *cls);

        template<typename T>
        Class *findClass(const T * nativeObj);

        cc::TimerLoop *getTimer() const;
        void setTimer(cc::TimerLoop *timer){ _loop = timer;}
       
        WebWorker *getWorker() const { return _worker;}
        void setWorker(WebWorker *worker) {_worker = worker;}

        void throwError(std::string_view message);
        void enqueueTask(std::function<void()> &&task);
        void checkTask();
        
    private:

    private:

        static void privateDataFinalize(void* nativeObj);

        static void onFatalErrorCallback(const char* location, const char* message);
        static void onOOMErrorCallback(const char* location, bool is_heap_oom);
        static void onMessageCallback(v8::Local<v8::Message> message, v8::Local<v8::Value> data);
        static void onPromiseRejectCallback(v8::PromiseRejectMessage msg);

        void callExceptionCallback(const char*, const char*, const char*);

        v8::Isolate* _isolate;
        uint32_t _vmId;

    public:
        Value *__oldConsoleLog{nullptr};
        Value *__oldConsoleDebug{nullptr};
        Value *__oldConsoleInfo{nullptr};
        Value *__oldConsoleWarn{nullptr};
        Value *__oldConsoleError{nullptr};
        Value *__oldConsoleAssert{nullptr};

        Class *__jsb_CCPrivateData_class{nullptr};
    private:
        
        std::chrono::steady_clock::time_point _startTime;
        std::vector<RegisterCallback> _registerCallbackArray;

        v8::Persistent<v8::Context> _context;

        v8::HandleScope* _handleScope;
        Object* _globalObj;
        Value _gcFuncValue;
        Object *_gcFunc = nullptr;

        cc::TimerLoop *_loop{nullptr};
        WebWorker *_worker{nullptr};

        FileOperationDelegate _fileOperationDelegate;
        ExceptionCallback _nativeExceptionCallback = nullptr;
        ExceptionCallback _jsExceptionCallback = nullptr;

        node::Environment* _env {nullptr};
        node::IsolateData* _isolateData{nullptr};

        std::unordered_map<void*, Object *> _nativePtrToObjectMap;
        std::unordered_set<void*> _nonRefNativePtrToObjectMap;
        std::unordered_map<std::string, Class*> _classTypeMap;
        std::unordered_set<Object*> _objectsMap;

        std::thread::id _engineThreadId;

        std::string _debuggerServerAddr;
        uint32_t _debuggerServerPort{0};

#if COCOS2D_DEBUG > 0
        std::vector<std::tuple<std::string, std::function<void()>>> _beforeInitHookArray;
        std::vector<std::tuple<std::string, std::function<void()>>> _afterInitHookArray;
        std::vector<std::tuple<std::string, std::function<void()>>> _beforeCleanupHookArray;
        std::vector<std::tuple<std::string, std::function<void()>>> _afterCleanupHookArray;
#else
        std::vector<std::function<void()>> _beforeInitHookArray;
        std::vector<std::function<void()>> _afterInitHookArray;
        std::vector<std::function<void()>> _beforeCleanupHookArray;
        std::vector<std::function<void()>> _afterCleanupHookArray;
#endif

        bool _isValid{false};
        bool _isGarbageCollecting{false};
        bool _isInCleanup{false};
        bool _isErrorHandleWorking{false};
        bool _isWaitForConnect{false};
    };

    /**
     * A stack-allocated class that governs a number of local handles.
     * It's only implemented for v8 wrapper now.
     * Other script engine wrappers have empty implementation for this class.
     * It's used at the beginning of executing any wrapper API.
     */
    class AutoHandleScope
    {
    public:
        AutoHandleScope(ScriptEngine *inst)
        : _handleScope(inst->getIsolate())
        {
        }
        ~AutoHandleScope() = default;
    private:
        v8::HandleScope _handleScope;
    };


    template<typename T>
    void ScriptEngine::registerClass(se::Class* cls)
    {
        const char* typeName = typeid(T).name();
        assert(_classTypeMap.find(typeName) == _classTypeMap.end());
        _classTypeMap.emplace(typeName, cls);
    }

    template<typename T>
    se::Class* ScriptEngine::findClass(const T* nativeObj)
    {
        bool found = false;
        std::string typeName = typeid(*nativeObj).name();
        auto iter = _classTypeMap.find(typeName);
        if (iter == _classTypeMap.end())
        {
            typeName = typeid(T).name();
            iter = _classTypeMap.find(typeName);
            if (iter != _classTypeMap.end())
            {
                found = true;
            }
        }
        else
        {
            found = true;
        }
        return found ? iter->second : nullptr;
    }

} // namespace se {

#endif // #if SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8
