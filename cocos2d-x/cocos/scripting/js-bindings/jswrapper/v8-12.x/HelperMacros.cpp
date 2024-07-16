#include "./HelperMacros.h"
#include <chrono>
#include <cstdint>
#include <functional>
#include <unordered_map>
#include "../State.hpp"
#include "./ScriptEngine.hpp"
#include "./Utils.hpp"
#include "Value.hpp"
#include "base/ccMacros.h"

#define PT_CACHE_VALUE_ARRAY 0

#if PT_ENABLE_JSB_PERF

struct JSBFnInfo {
    int invokeTimes = 0;
    uint64_t totalNs = 0;
};

static std::unordered_map<const char *, JSBFnInfo> invokeInfo;

JSBFnPerf::JSBFnPerf(const char *fn) : _fn(fn) {
    _start = std::chrono::high_resolution_clock::now();
}

JSBFnPerf::~JSBFnPerf() {
    using namespace std::chrono;
    auto pass = duration_cast<nanoseconds>(high_resolution_clock::now() - _start).count();
    auto &info = invokeInfo[_fn];
    info.invokeTimes++;
    info.totalNs += pass;
}

void JSBFnPerf::reset() {
    invokeInfo.clear();
}

void JSBFnPerf::inspect() {
    int cnt = 0;
    uint64_t ns = 0;
    for (auto &i : invokeInfo) {
        cnt += i.second.invokeTimes;
        ns += i.second.totalNs;
    }
    CCLOG("JSB %d jsb functions, invoke %d times, takes %f ms",
          (int)invokeInfo.size(),
          cnt,
          (float)(ns * 1.0 / 1000000.0));

    for (auto &i : invokeInfo) {
        CCLOG(" %s : %d times, %f ms", i.first, i.second.invokeTimes, (float)(i.second.totalNs / 1000000.0));
    }
}

#endif

SE_HOT void
jsbFunctionWrapper(const v8::FunctionCallbackInfo<v8::Value> &v8args, se_function_ptr func,
                   const char *funcName) {
    bool ret = false;
    v8::Isolate *_isolate = v8args.GetIsolate();
    auto *inst = reinterpret_cast<se::ScriptEngine *>(_isolate->GetData(0));
    v8::HandleScope _hs(_isolate);
#if PT_CACHE_VALUE_ARRAY
    bool needDeleteValueArray{false};
    se::ValueArray &args = se::gValueArrayPool.get(v8args.Length(), needDeleteValueArray);
    se::CallbackDepthGuard depthGuard{args, se::gValueArrayPool._depth, needDeleteValueArray};
#else
    se::ValueArray args(v8args.Length());
#endif
    se::internal::jsToSeArgs(v8args, &args);
    void *nativeThisObject = se::internal::getPrivate(_isolate, v8args.This());
    se::State state(nativeThisObject, args);
    ret = func(state, inst);
    if (!ret) {
        SE_LOGE("[ERROR] Failed to invoke %s", funcName);
    }
    se::internal::setReturnValue(state.rval(), v8args);
}

SE_HOT void
jsbFinalizeWrapper(void *nativeThisObject, se_function_ptr func, const char *funcName) {
    if (nativeThisObject == nullptr) return;
    auto *isolate = v8::Isolate::GetCurrent();
    auto *inst = reinterpret_cast<se::ScriptEngine *>(isolate->GetData(0));
    inst->_setGarbageCollecting(true);
    se::State state(nativeThisObject);
    bool ret = func(state, inst);
    if (!ret) {
        SE_LOGE("[ERROR] Failed to invoke %s", funcName);
    }
    inst->_setGarbageCollecting(false);
}

SE_HOT void
jsbConstructorWrapper(const v8::FunctionCallbackInfo<v8::Value> &v8args, se_function_ptr func,
                      se_finalize_ptr finalizeCb, se::Class *cls, const char *funcName) {
    v8::Isolate *_isolate = v8args.GetIsolate();
    auto *inst = reinterpret_cast<se::ScriptEngine *>(_isolate->GetData(0));
    v8::HandleScope _hs(_isolate);
    bool ret = true;
#if PT_CACHE_VALUE_ARRAY
    bool needDeleteValueArray{false};
    se::ValueArray &args = se::gValueArrayPool.get(v8args.Length(), needDeleteValueArray);
    se::CallbackDepthGuard depthGuard{args, se::gValueArrayPool._depth, needDeleteValueArray};
#else
    se::ValueArray args(v8args.Length());
#endif
    se::internal::jsToSeArgs(v8args, &args);
    se::Object *thisObject = se::Object::_createJSObject(inst, cls, v8args.This());
    thisObject->_setFinalizeCallback(finalizeCb);
    se::State state(thisObject, args);
    ret = func(state, inst);
    if (!ret) {
        SE_LOGE("[ERROR] Failed to invoke %s", funcName);
    }
    se::Value _property;
    bool _found = false;
    _found = thisObject->getProperty("_ctor", &_property);
    if (_found) _property.toObject()->call(args, thisObject);
}

SE_HOT void jsbGetterWrapper(const v8::FunctionCallbackInfo<v8::Value> &v8args, se_function_ptr func,
                             const char *funcName) {
    v8::Isolate *_isolate = v8args.GetIsolate();
    auto *inst = reinterpret_cast<se::ScriptEngine *>(_isolate->GetData(0));
    v8::HandleScope _hs(_isolate);
    bool ret = true;
    void *nativeThisObject = se::internal::getPrivate(_isolate, v8args.This());
    se::State state(nativeThisObject);
    ret = func(state, inst);
    if (!ret) {
        SE_LOGE("[ERROR] Failed to invoke %s", funcName);
    }
    se::internal::setReturnValue(state.rval(), v8args);
}

SE_HOT void
jsbSetterWrapper(const v8::FunctionCallbackInfo<v8::Value> &v8args, se_function_ptr func,
                 const char *funcName) {
    v8::Isolate *_isolate = v8args.GetIsolate();
    auto *inst = reinterpret_cast<se::ScriptEngine *>(_isolate->GetData(0));
    v8::HandleScope _hs(_isolate);
    bool ret = true;
    void *nativeThisObject = se::internal::getPrivate(_isolate, v8args.This());
#if PT_CACHE_VALUE_ARRAY
    bool needDeleteValueArray{false};
    se::ValueArray &args = se::gValueArrayPool.get(1, needDeleteValueArray);
    se::CallbackDepthGuard depthGuard{args, se::gValueArrayPool._depth,
                                      needDeleteValueArray};
#else
    se::ValueArray args(1);
#endif
    se::internal::jsToSeArgs(v8args, &args);
    se::State state(nativeThisObject, args);
    ret = func(state, inst);
    if (!ret) {
        SE_LOGE("[ERROR] Failed to invoke %s", funcName);
    }
}
