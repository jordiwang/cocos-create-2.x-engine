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
#include "Object.hpp"
#include "ObjectWrap.h"
#include "Value.hpp"

#if SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8
#include "Utils.hpp"
#include "Class.hpp"
#include "ScriptEngine.hpp"
#include "../MappingUtils.hpp"

#include <memory>
#include <unordered_map>
#include <vector>
#include <tuple>

#if CC_DEBUG_GC_CRASH
std::unordered_map<void *, std::vector<std::tuple<void*,const char*, bool /*alive*/>>> gPtr2Class;
#endif

namespace se {


//    std::unique_ptr<std::unordered_map<Object*, void*>> __objectMap; // Currently, the value `void*` is always nullptr

    namespace {

        void emptyV8FnCb(const v8::FunctionCallbackInfo<v8::Value> &args) {
            v8::MaybeLocal<v8::String> msg = v8::String::NewFromUtf8(args.GetIsolate(), "[emptyV8FnCb] current function is not implemented!");
            args.GetIsolate()->ThrowException(msg.ToLocalChecked());
        }
    }

    Object* ObjectWrap::getObject() const {
        return Object::fromObjectWrap(this);
    }

    Object::Object()
    : _cls(nullptr)
    , _rootCount(0)
    , _privateData(nullptr)
    , _finalizeCb(nullptr)
    , _internalData(nullptr)
    {
    }

    Object::~Object()
    {

#if CC_DEBUG_GC_CRASH
        auto itr = gPtr2Class.find(&_obj);
        if(itr != gPtr2Class.end()) {
            auto & tuple = itr->second.back();
            std::get<2>(tuple) = false;
            if(std::get<0>(tuple) == nullptr) {
               SE_LOGE("Got an unused wrap %p!!, is native %s, _rootCnt %d, name: %s", &_obj,
                   _obj._hasNativeClass ? "yes" : "no",
                   _rootCount,
                   std::get<1>(tuple)
               );
            }
        }
#endif
        if (_rootCount > 0)
        {
            _obj.unref();
        }
//        if(_inst && _inst->isValid()) {
        if(_inst ) { //&& _inst->isValid()) {
            _inst->getObjects().erase(this);
        }
    }

    /*static*/
    void Object::nativeObjectFinalizeHook(void *nativeObj)
    {
        if (nativeObj == nullptr)
            return;
        auto *inst = ScriptEngine::GetCurrent();
        auto &ptrMap = inst->getNativePtrMap();
        auto iter = ptrMap.find(nativeObj);
        if (iter != ptrMap.end())
        {
            Object* obj = iter->second;
            if (obj->_finalizeCb != nullptr)
            {
                obj->_finalizeCb(nativeObj);
            }
            else
            {
                assert(obj->_getClass() != nullptr);
                if (obj->_getClass()->_finalizeFunc != nullptr)
                    obj->_getClass()->_finalizeFunc(nativeObj);
            }
            obj->decRef();
            ptrMap.erase(iter);
        }
        else
        {
//            assert(false);
        }
    }
    

    /* static */
    void Object::cleanup(ScriptEngine *inst)
    {
        void* nativeObj = nullptr;
        Object* obj = nullptr;
        Class* cls = nullptr;
        auto& nativePtrToObjectMap = inst->getNativePtrMap();
        for (const auto& e : nativePtrToObjectMap)
        {
            nativeObj = e.first;
            obj = e.second;

            if (obj->_finalizeCb != nullptr)
            {
                obj->_finalizeCb(nativeObj);
            }
            else
            {
                if (obj->_getClass() != nullptr)
                {
                    if (obj->_getClass()->_finalizeFunc != nullptr)
                    {
                        obj->_getClass()->_finalizeFunc(nativeObj);
                    }
                }
            }
            // internal data should only be freed in Object::cleanup, since in other case, it is freed in ScriptEngine::privateDataFinalize
            if (obj->_internalData != nullptr)
            {
                free(obj->_internalData);
                obj->_internalData = nullptr;
            }
            obj->decRef();
        }

        nativePtrToObjectMap.clear();

        auto &objectMap = inst->getObjects();
        std::vector<Object*> toReleaseObjects;
        for (auto* obj : objectMap)
        {
            cls = obj->_getClass();
            obj->_obj.persistent().Reset();
            obj->_rootCount = 0;

            if (cls != nullptr && cls->_name == "__PrivateData")
            {
                toReleaseObjects.push_back(obj);
            }
        }
        objectMap.clear();
        for (auto e : toReleaseObjects)
        {
            e->decRef();
        }
    }

    Object* Object::createPlainObject(ScriptEngine *inst)
    {
        v8::Local<v8::Object> jsobj = v8::Object::New(inst->getIsolate());
        Object* obj = _createJSObject(inst, nullptr, jsobj);
        return obj;
    }

    Object* Object::getObjectWithPtr(ScriptEngine *inst, void* ptr)
    {
        Object* obj = nullptr;

        auto &ptrMap = inst->getNativePtrMap();
        auto iter = ptrMap.find(ptr);
        if (iter != ptrMap.end())
        {
            obj = iter->second;
            obj->incRef();
        }
        return obj;
    }

    Object* Object::_createJSObject(ScriptEngine *inst, Class* cls, v8::Local<v8::Object> obj)
    {
        Object* ret = new Object();
        if (!ret->init(inst, cls, obj))
        {
            delete ret;
            ret = nullptr;
        }
        return ret;
    }

    Object* Object::createObjectWithClass(ScriptEngine *inst, Class* cls)
    {
        v8::Local<v8::Object> jsobj = Class::_createJSObjectWithClass(inst, cls);
        Object* obj = Object::_createJSObject(inst, cls, jsobj);
        return obj;
    }

    Object* Object::createArrayObject(ScriptEngine *inst, size_t length)
    {
        v8::Local<v8::Array> jsobj = v8::Array::New(inst->getIsolate(), (int)length);
        Object* obj = Object::_createJSObject(inst, nullptr, jsobj);
        return obj;
    }

    Object* Object::createArrayBufferObject(ScriptEngine *inst, void* data, size_t byteLength)
    {
        v8::Local<v8::ArrayBuffer> jsobj = v8::ArrayBuffer::New(inst->getIsolate(), byteLength);
        std::shared_ptr<v8::BackingStore> store = jsobj->GetBackingStore();
        if (data)
        {
            memcpy(store->Data(), data, byteLength);
        }
        else
        {
            memset(store->Data(), 0, byteLength);
        }
        Object* obj = Object::_createJSObject(inst, nullptr, jsobj);
        return obj;
    }

    Object* Object::createExternalArrayBufferObject(ScriptEngine *inst, void* bytes, size_t byteLength, external_arraybuffer_free_fn fn, void *ctx) {
       std::shared_ptr<v8::BackingStore> store = v8::ArrayBuffer::NewBackingStore(bytes, byteLength, fn, ctx);
       v8::Local<v8::ArrayBuffer> jsobj = v8::ArrayBuffer::New(inst->getIsolate(), store);
       if(!jsobj.IsEmpty()) {
           return Object::_createJSObject(inst, nullptr, jsobj);
       }
       return nullptr;
    }

    Object* Object::createExternalUint8ArrayObject(ScriptEngine *inst, void* bytes, size_t byteLength, external_arraybuffer_free_fn fn, void *ctx) {
       std::shared_ptr<v8::BackingStore> store = v8::ArrayBuffer::NewBackingStore(bytes, byteLength, fn, ctx);
       v8::Local<v8::ArrayBuffer> arraybuffer = v8::ArrayBuffer::New(inst->getIsolate(), store);
       v8::Local<v8::Uint8Array> jsobj= v8::Uint8Array::New(arraybuffer, 0, byteLength);
       if(!jsobj.IsEmpty()) {
           return Object::_createJSObject(inst, nullptr, jsobj);
       }
       return nullptr;
    }

    Object* Object::createExternalInt16ArrayObject(ScriptEngine *inst, int16_t* bytes, size_t elementCount, external_arraybuffer_free_fn fn, void *ctx) {
        std::shared_ptr<v8::BackingStore> store = v8::ArrayBuffer::NewBackingStore(bytes, sizeof(int16_t) * elementCount, fn, ctx);
        v8::Local<v8::ArrayBuffer> arraybuffer = v8::ArrayBuffer::New(inst->getIsolate(), store);
        v8::Local<v8::Int16Array> jsobj= v8::Int16Array::New(arraybuffer, 0, elementCount);
        if(!jsobj.IsEmpty()) {
            return Object::_createJSObject(inst, nullptr, jsobj);
        }
        return nullptr;
    }

    Object* Object::createTypedArray(ScriptEngine *inst, TypedArrayType type, void* data, size_t byteLength)
    {
        if (type == TypedArrayType::NONE)
        {
            SE_LOGE("Don't pass se::Object::TypedArrayType::NONE to createTypedArray API!");
            return nullptr;
        }

        if (type == TypedArrayType::UINT8_CLAMPED)
        {
            SE_LOGE("Doesn't support to create Uint8ClampedArray with Object::createTypedArray API!");
            return nullptr;
        }

        v8::Local<v8::ArrayBuffer> jsobj = v8::ArrayBuffer::New(inst->getIsolate(), byteLength);
        //If data has content,then will copy data into buffer,or will only clear buffer.
        auto store = jsobj->GetBackingStore();
        if (data) {
            memcpy(store->Data(), data, byteLength);
        }else{
            memset(store->Data(), 0, byteLength);
        }
        
        v8::Local<v8::Object> arr;
        switch (type) {
            case TypedArrayType::INT8:
                arr = v8::Int8Array::New(jsobj, 0, byteLength);
                break;
            case TypedArrayType::INT16:
                arr = v8::Int16Array::New(jsobj, 0, byteLength / 2);
                break;
            case TypedArrayType::INT32:
                arr = v8::Int32Array::New(jsobj, 0, byteLength / 4);
                break;
            case TypedArrayType::UINT8:
                arr = v8::Uint8Array::New(jsobj, 0, byteLength);
                break;
            case TypedArrayType::UINT16:
                arr = v8::Uint16Array::New(jsobj, 0, byteLength / 2);
                break;
            case TypedArrayType::UINT32:
                arr = v8::Uint32Array::New(jsobj, 0, byteLength / 4);
                break;
            case TypedArrayType::FLOAT32:
                arr = v8::Float32Array::New(jsobj, 0, byteLength / 4);
                break;
            case TypedArrayType::FLOAT64:
                arr = v8::Float64Array::New(jsobj, 0, byteLength / 8);
                break;
            default:
                assert(false); // Should never go here.
                break;
        }

        Object* obj = Object::_createJSObject(inst, nullptr, arr);
        return obj;
    }

    Object* Object::createUint8TypedArray(ScriptEngine *inst, uint8_t* data, size_t dataCount)
    {
        return createTypedArray(inst, TypedArrayType::UINT8, data, dataCount);
    }

    Object* Object::createJSONObject(ScriptEngine *inst, std::string_view jsonStr)
    {
        auto *isolate = inst->getIsolate();
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        Value strVal(jsonStr.data());
        v8::Local<v8::Value> jsStr;
        internal::seToJsValue(isolate, strVal, &jsStr);
        v8::Local<v8::String> v8Str = v8::Local<v8::String>::Cast(jsStr);
        v8::MaybeLocal<v8::Value> ret = v8::JSON::Parse(context, v8Str);
        if (ret.IsEmpty())
            return nullptr;

        v8::Local<v8::Object> jsobj = v8::Local<v8::Object>::Cast(ret.ToLocalChecked());
        return Object::_createJSObject(inst, nullptr, jsobj);
    }

    bool Object::init(ScriptEngine *inst, Class* cls, v8::Local<v8::Object> obj)
    {
        _inst = inst;
        _cls = cls;

        _obj.init(inst->getIsolate(), obj, cls != nullptr);
        _obj.setFinalizeCallback(nativeObjectFinalizeHook);

        auto &objectMap = inst->getObjects();
        assert(objectMap.find(this) == objectMap.end());
        objectMap.emplace(this);

        return true;
    }

    bool Object::getProperty(std::string_view name, Value *data)
    {
        assert(data != nullptr);
        data->setUndefined();

        auto *isolate = _inst->getIsolate();
        v8::HandleScope handle_scope(isolate);

        if (_obj.persistent().IsEmpty())
        {
            return false;
        }

        v8::MaybeLocal<v8::String> nameValue = v8::String::NewFromUtf8(isolate, name.data(), v8::NewStringType::kInternalized, name.length());
        if (nameValue.IsEmpty())
            return false;

        v8::Local<v8::String> nameValToLocal = nameValue.ToLocalChecked();
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        v8::Maybe<bool> maybeExist = _obj.handle(isolate)->Has(context, nameValToLocal);
        if (maybeExist.IsNothing())
            return false;


        if (!maybeExist.FromJust())
            return false;

        v8::MaybeLocal<v8::Value> result = _obj.handle(isolate)->Get(context, nameValToLocal);
        if (result.IsEmpty())
            return false;

        internal::jsToSeValue(isolate, result.ToLocalChecked(), data);

        return true;
    }

    bool Object::deleteProperty(std::string_view name)
    {
        auto *isolate = _inst->getIsolate();
        v8::HandleScope handle_scope(isolate);

        if (_obj.persistent().IsEmpty())
        {
            return false;
        }

        v8::MaybeLocal<v8::String> nameValue = v8::String::NewFromUtf8(isolate, name.data(), v8::NewStringType::kNormal);
        if (nameValue.IsEmpty())
            return false;

        v8::Local<v8::String> nameValToLocal = nameValue.ToLocalChecked();
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        v8::Maybe<bool> maybeExist = _obj.handle(isolate)->Delete(context, nameValToLocal);
        if (maybeExist.IsNothing())
            return false;

        if (!maybeExist.FromJust())
            return false;

        return true;
    }


    bool Object::setProperty(std::string_view name, const Value& data)
    {
        auto *isolate = _inst->getIsolate();
        v8::MaybeLocal<v8::String> nameValue = v8::String::NewFromUtf8(isolate, name.data(), v8::NewStringType::kInternalized, name.length());
        if (nameValue.IsEmpty())
            return false;

        v8::Local<v8::Value> value;
        internal::seToJsValue(isolate, data, &value);
        v8::Maybe<bool> ret = _obj.handle(isolate)->Set(isolate->GetCurrentContext(), nameValue.ToLocalChecked(), value);
        if (ret.IsNothing())
        {
            SE_LOGD("ERROR: %s, Set return nothing ...\n", __FUNCTION__);
            return false;
        }
        return true;
    }

    bool Object::defineProperty(std::string_view name, v8::FunctionCallback getter, v8::FunctionCallback setter)
    {
        auto *isolate = _inst->getIsolate();
        v8::MaybeLocal<v8::String> nameValue = v8::String::NewFromUtf8(isolate, name.data(), v8::NewStringType::kNormal, name.length());
        if (nameValue.IsEmpty())
            return false;

        v8::Local<v8::String> nameValChecked = nameValue.ToLocalChecked();
        v8::Local<v8::Name> jsName = v8::Local<v8::Name>::Cast(nameValChecked);
        v8::Local<v8::Context> currentContext = isolate->GetCurrentContext();

        v8::MaybeLocal<v8::Function> v8Getter = v8::Function::New(currentContext, getter ? getter : emptyV8FnCb);
        v8::MaybeLocal<v8::Function> v8Setter = v8::Function::New(currentContext, setter ? setter : emptyV8FnCb);
        _obj.handle(isolate)->SetAccessorProperty(jsName, v8Getter.ToLocalChecked(), v8Setter.ToLocalChecked());
        return true;
    }

    bool Object::isFunction() const
    {
        return const_cast<Object*>(this)->_obj.handle(_inst->getIsolate())->IsCallable();
    }

    bool Object::_isNativeFunction() const
    {
        if (isFunction())
        {
            std::string info = toString();
            if (info.find("[native code]") != std::string::npos)
            {
                return true;
            }
        }
        return false;
    }

    bool Object::isTypedArray() const
    {
        return const_cast<Object*>(this)->_obj.handle(_inst->getIsolate())->IsTypedArray();
    }

    Object::TypedArrayType Object::getTypedArrayType() const
    {
        v8::Local<v8::Value> value = const_cast<Object*>(this)->_obj.handle(_inst->getIsolate());
        TypedArrayType ret = TypedArrayType::NONE;
        if (value->IsInt8Array())
            ret = TypedArrayType::INT8;
        else if (value->IsInt16Array())
            ret = TypedArrayType::INT16;
        else if (value->IsInt32Array())
            ret = TypedArrayType::INT32;
        else if (value->IsUint8Array())
            ret = TypedArrayType::UINT8;
        else if (value->IsUint8ClampedArray())
            ret = TypedArrayType::UINT8_CLAMPED;
        else if (value->IsUint16Array())
            ret = TypedArrayType::UINT16;
        else if (value->IsUint32Array())
            ret = TypedArrayType::UINT32;
        else if (value->IsFloat32Array())
            ret = TypedArrayType::FLOAT32;
        else if (value->IsFloat64Array())
            ret = TypedArrayType::FLOAT64;

        return ret;
    }

    bool Object::getTypedArrayData(uint8_t** ptr, size_t* length) const
    {
        assert(isTypedArray());
        v8::Local<v8::Object> obj = const_cast<Object*>(this)->_obj.handle(_inst->getIsolate());
        v8::Local<v8::TypedArray> arr = v8::Local<v8::TypedArray>::Cast(obj);
        auto content = arr->Buffer()->GetBackingStore();
        *ptr = (uint8_t*)content->Data() + arr->ByteOffset();
        *length = arr->ByteLength();
        return true;
    }

    bool Object::isArrayBuffer() const
    {
        v8::Local<v8::Object> obj = const_cast<Object*>(this)->_obj.handle(_inst->getIsolate());
        return obj->IsArrayBuffer();
    }

    bool Object::getArrayBufferData(uint8_t** ptr, size_t* length) const
    {
        assert(isArrayBuffer());
        v8::Local<v8::Object> obj = const_cast<Object*>(this)->_obj.handle(_inst->getIsolate());
        v8::Local<v8::ArrayBuffer> arrBuf = v8::Local<v8::ArrayBuffer>::Cast(obj);
        auto content = arrBuf->GetBackingStore();
        *ptr = (uint8_t*)content->Data();
        *length = content->ByteLength();
        return true;
    }

    void Object::setPrivateData(void* data)
    {
        assert(_privateData == nullptr);
        auto &ptrMap = _inst->getNativePtrMap();
        assert(ptrMap.find(data) == ptrMap.end());

        auto *isolate = _inst->getIsolate();
#if CC_DEBUG_GC_CRASH
        internal::setPrivate(isolate, _obj, data, &_internalData, _cls->getName());
#else
        internal::setPrivate(isolate, _obj, data, &_internalData);
#endif
        ptrMap.emplace(data, this);
        _privateData = data;
    }

    void* Object::getPrivateData() const
    {
        if (_privateData == nullptr)
        {
            auto *isolate = _inst->getIsolate();
            const_cast<Object*>(this)->_privateData = internal::getPrivate(isolate, const_cast<Object*>(this)->_obj.handle(isolate));
        }
        return _privateData;
    }

    void Object::clearPrivateData(bool clearMapping)
    {
        if (_privateData != nullptr)
        {
            if (clearMapping)
                _inst->getNativePtrMap().erase(_privateData);
            internal::clearPrivate(_inst->getIsolate(), _obj);
            _privateData = nullptr;
        }
    }

    v8::Local<v8::Object> Object::_getJSObject() const
    {
        return const_cast<Object*>(this)->_obj.handle(_inst->getIsolate());
    }

    ObjectWrap& Object::_getWrap()
    {
        return _obj;
    }

    bool Object::call(const ValueArray& args, Object* thisObject, Value* rval/* = nullptr*/)
    {
        v8::HandleScope scope(_inst->getIsolate());
//        v8::Context::Scope contextScope(_inst->_getContext());
        
        if (_obj.persistent().IsEmpty())
        {
            SE_LOGD("Function object is released!\n");
            return false;
        }
        size_t argc = args.size();
        auto *isolate = _inst->getIsolate();
        std::vector<v8::Local<v8::Value>> argv(argc);
        internal::seToJsArgs(isolate, args, &argv);

        v8::Local<v8::Object> thiz = v8::Local<v8::Object>::Cast(v8::Undefined(isolate));
        if (thisObject != nullptr)
        {
            if (thisObject->_obj.persistent().IsEmpty())
            {
                SE_LOGD("This object is released!\n");
                return false;
            }
            thiz = thisObject->_obj.handle(isolate);
        }

        for (size_t i = 0; i < argc; ++i)
        {
            if (argv[i].IsEmpty())
            {
                SE_LOGD("%s argv[%d] is released!\n", __FUNCTION__, (int)i);
                return false;
            }
        }

        v8::Local<v8::Context> context = _inst->_getContext();
        v8::MaybeLocal<v8::Value> result = _obj.handle(isolate)->CallAsFunction(context, thiz, (int)argc, argv.data());

        if (!result.IsEmpty())
        {
            if (rval != nullptr)
            {
                internal::jsToSeValue(isolate, result.ToLocalChecked(), rval);
            }
            return true;
        }
        else
        {
            SE_REPORT_ERROR("Invoking function (%p) failed!", this);
            _inst->clearException();
        }

//        assert(false);

        return false;
    }

    bool Object::defineFunction(std::string_view funcName, void (*func)(const v8::FunctionCallbackInfo<v8::Value> &args))
    {
        auto *isolate = _inst->getIsolate();
        v8::MaybeLocal<v8::String> maybeFuncName = v8::String::NewFromUtf8(isolate, funcName.data(), v8::NewStringType::kNormal, funcName.length());
        if (maybeFuncName.IsEmpty())
            return false;

        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        v8::MaybeLocal<v8::Function> maybeFunc = v8::FunctionTemplate::New(isolate, func)->GetFunction(context);
        if (maybeFunc.IsEmpty())
            return false;

        v8::Maybe<bool> ret = _obj.handle(isolate)->Set(context,
                                    v8::Local<v8::Name>::Cast(maybeFuncName.ToLocalChecked()),
                                    maybeFunc.ToLocalChecked());

        return ret.IsJust() && ret.FromJust();
    }

    bool Object::isArray() const
    {
        return const_cast<Object*>(this)->_obj.handle(_inst->getIsolate())->IsArray();
    }

    bool Object::getArrayLength(uint32_t* length) const
    {
        assert(isArray());
        assert(length != nullptr);
        Object* thiz = const_cast<Object*>(this);
        auto *isolate = _inst->getIsolate();

        v8::MaybeLocal<v8::String> lengthStr = v8::String::NewFromUtf8(isolate, "length", v8::NewStringType::kInternalized);
        if (lengthStr.IsEmpty())
        {
            *length = 0;
            return false;
        }
        v8::Local<v8::Context> context = isolate->GetCurrentContext();

        v8::MaybeLocal<v8::Value> val = thiz->_obj.handle(isolate)->Get(context, lengthStr.ToLocalChecked());
        if (val.IsEmpty())
            return false;

        v8::MaybeLocal<v8::Object> obj = val.ToLocalChecked()->ToObject(context);
        if (obj.IsEmpty())
            return false;

        v8::Maybe<uint32_t> mbLen= obj.ToLocalChecked()->Uint32Value(context);
        if (mbLen.IsNothing())
            return false;

        *length = mbLen.FromJust();
        return true;
    }

    bool Object::getArrayElement(uint32_t index, Value* data) const
    {
        assert(isArray());
        assert(data != nullptr);
        Object* thiz = const_cast<Object*>(this);
        auto *isolate = _inst->getIsolate();
        v8::MaybeLocal<v8::Value> result = thiz->_obj.handle(isolate)->Get(isolate->GetCurrentContext(), index);

        if (result.IsEmpty())
            return false;

        internal::jsToSeValue(isolate, result.ToLocalChecked(), data);
        return true;
    }

    bool Object::setArrayElement(uint32_t index, const Value& data)
    {
        assert(isArray());

        v8::Local<v8::Value> jsval;
        auto *isolate = _inst->getIsolate();
        internal::seToJsValue(isolate, data, &jsval);
        v8::Maybe<bool> ret = _obj.handle(isolate)->Set(isolate->GetCurrentContext(), index, jsval);

        return ret.IsJust() && ret.FromJust();
    }

    bool Object::getAllKeys(std::vector<std::string>* allKeys) const
    {
        auto isolate = _inst->getIsolate();
        assert(allKeys != nullptr);
        Object* thiz = const_cast<Object*>(this);
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        v8::MaybeLocal<v8::Array> keys = thiz->_obj.handle(isolate)->GetOwnPropertyNames(context);
        if (keys.IsEmpty())
            return false;

        v8::Local<v8::Array> keysChecked = keys.ToLocalChecked();
        Value keyVal;
        for (uint32_t i = 0, len = keysChecked->Length(); i < len; ++i)
        {
            v8::MaybeLocal<v8::Value> key = keysChecked->Get(context, i);
            if (key.IsEmpty())
            {
                allKeys->clear();
                return false;
            }
            internal::jsToSeValue(isolate, key.ToLocalChecked(), &keyVal);
            if (keyVal.isString())
            {
                allKeys->push_back(keyVal.toString());
            }
            else if (keyVal.isNumber())
            {
                char buf[50] = {0};
                snprintf(buf, sizeof(buf), "%d", keyVal.toInt32());
                allKeys->push_back(buf);
            }
            else
            {
                assert(false);
            }
        }
        return true;
    }

    Class* Object::_getClass() const
    {
        return _cls;
    }

    void Object::_setFinalizeCallback(V8FinalizeFunc finalizeCb)
    {
        assert(finalizeCb != nullptr);
        _finalizeCb = finalizeCb;
    }

    void Object::root()
    {
        if (_rootCount == 0)
        {
            _obj.ref();
        }
        ++_rootCount;
    }

    void Object::unroot()
    {
        if (_rootCount > 0)
        {
            --_rootCount;
            if (_rootCount == 0)
            {
                _obj.unref();
            }
        }
    }

    bool Object::isRooted() const
    {
        return _rootCount > 0;
    }

    bool Object::strictEquals(Object *o) const
    {
        assert(o->_inst == _inst);
        auto *isolate = _inst->getIsolate();
        Object* a = const_cast<Object*>(this);
        return a->_obj.handle(isolate) == o->_obj.handle(isolate);
    }

    bool Object::attachObject(Object* obj)
    {
        assert(obj);

        Object* global = _inst->getGlobalObject();
        Value jsbVal;
        if (!global->getProperty("jsb", &jsbVal))
            return false;
        Object* jsbObj = jsbVal.toObject();

        Value func;

        if (!jsbObj->getProperty("registerNativeRef", &func))
            return false;

        ValueArray args;
        args.push_back(Value(this));
        args.push_back(Value(obj));
        func.toObject()->call(args, global);
        return true;
    }

    bool Object::detachObject(Object* obj)
    {
        assert(obj);

        Object* global = _inst->getGlobalObject();
        Value jsbVal;
        if (!global->getProperty("jsb", &jsbVal))
            return false;
        Object* jsbObj = jsbVal.toObject();

        Value func;

        if (!jsbObj->getProperty("unregisterNativeRef", &func))
            return false;

        ValueArray args;
        args.push_back(Value(this));
        args.push_back(Value(obj));
        func.toObject()->call(args, global);
        return true;
    }

    std::string Object::toString() const
    {
        auto *isolate = _inst->getIsolate();
        v8::Local<v8::Object> v8Obj = const_cast<Object *>(this)->_obj.handle(isolate);
        v8::String::Utf8Value utf8(isolate, v8Obj);
        return *utf8;
    }

} // namespace se {

#endif // #if SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8
