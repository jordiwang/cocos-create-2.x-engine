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

#include "v8.h"
#include "../config.hpp"
#include "../ValueArrayPool.h"
#include <chrono>

#if SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8

extern uint32_t __jsbInvocationCount;


#define PT_ENABLE_JSB_PERF 0

#if PT_ENABLE_JSB_PERF

class JSBFnPerf {
public:
    JSBFnPerf(const char * fn);
    ~JSBFnPerf();
    static void inspect();
    static void reset();
private:
    const char * _fn{nullptr};
    std::chrono::time_point<std::chrono::high_resolution_clock> _start;
};
#else

class JSBFnPerf {
public:
    JSBFnPerf(const char *fn) {}

    ~JSBFnPerf() {}
};

#endif

namespace se {
    class Class;

    class Object;
    class ScriptEngine;
    class State;
} // namespace se
using se_function_ptr = bool (*)(se::State &state, se::ScriptEngine *inst);
using se_finalize_ptr = void (*)(void *);

void jsbFunctionWrapper(const v8::FunctionCallbackInfo<v8::Value> &,
                        se_function_ptr,
                        const char *);

void jsbFinalizeWrapper(void * nativeThisObject,
                        se_function_ptr,
                        const char *);

void jsbConstructorWrapper(const v8::FunctionCallbackInfo<v8::Value> &,
                           se_function_ptr,
                           se_finalize_ptr finalizeCb,
                           se::Class *,
                           const char *);

void jsbGetterWrapper(const v8::FunctionCallbackInfo<v8::Value> &,
                      se_function_ptr,
                      const char *);

void jsbSetterWrapper(const v8::FunctionCallbackInfo<v8::Value> &,
                      se_function_ptr,
                      const char *);


#ifdef __GNUC__
#define SE_UNUSED __attribute__ ((unused))
#define SE_HOT    __attribute__((hot))
#else
#define SE_UNUSED
#define SE_HOT
#endif

#define SAFE_INC_REF(obj) if (obj != nullptr) obj->incRef()
#define SAFE_DEC_REF(obj) if ((obj) != nullptr) { (obj)->decRef(); (obj) = nullptr; }

#define _SE(name) name##Registry

#define SE_DECLARE_FUNC(funcName) \
    void funcName##Registry(const v8::FunctionCallbackInfo<v8::Value>& v8args)


#define SE_BIND_FUNC(funcName) \
    void funcName##Registry(const v8::FunctionCallbackInfo<v8::Value>& _v8args) \
    { \
        ++__jsbInvocationCount; \
        jsbFunctionWrapper(_v8args, funcName, #funcName);                         \
    }

#define SE_BIND_FINALIZE_FUNC(funcName) \
    void funcName##Registry(void* nativeThisObject) \
    { \
        if (nativeThisObject == nullptr)                           \
            return;                                          \
        jsbFinalizeWrapper(nativeThisObject, funcName, #funcName); \
    }

#define SE_DECLARE_FINALIZE_FUNC(funcName) \
    void funcName##Registry(void* nativeThisObject);

// v8 doesn't need to create a new JSObject in SE_BIND_CTOR while SpiderMonkey needs.
#define SE_BIND_CTOR(funcName, cls, finalizeCb) \
    void funcName##Registry(const v8::FunctionCallbackInfo<v8::Value>& _v8args) \
    { \
        ++__jsbInvocationCount; \
        jsbConstructorWrapper(_v8args, funcName, _SE(finalizeCb), cls, #funcName); \
    }

#define SE_BIND_SUB_CLS_CTOR SE_BIND_CTOR


#define SE_BIND_PROP_GET(funcName) \
    void funcName##Registry(const v8::FunctionCallbackInfo<v8::Value>& _v8args) \
    { \
        ++__jsbInvocationCount;    \
        jsbGetterWrapper(_v8args, funcName, #funcName); \
    }


#define SE_BIND_PROP_SET(funcName) \
    void funcName##Registry(const v8::FunctionCallbackInfo<v8::Value>& _v8args) \
    { \
        ++__jsbInvocationCount; \
        jsbSetterWrapper(_v8args, funcName, #funcName); \
    }


#define SE_TYPE_NAME(t) typeid(t).name()

#define SE_QUOTEME_(x) #x
#define SE_QUOTEME(x) SE_QUOTEME_(x)

//IDEA: implement this macro
#define SE_REPORT_ERROR(fmt, ...) SE_LOGE("[ERROR] (" __FILE__ ", " SE_QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__)

#if COCOS2D_DEBUG > 0

#define SE_ASSERT(cond, fmt, ...) \
    do \
    { \
        if (!(cond)) \
        { \
            SE_LOGE("ASSERT (" __FILE__ ", " SE_QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__); \
            assert(false); \
        } \
    } while(false)

#else

#define SE_ASSERT(cond, fmt, ...) 

#endif // #if COCOS2D_DEBUG > 0


#endif // #if SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8
