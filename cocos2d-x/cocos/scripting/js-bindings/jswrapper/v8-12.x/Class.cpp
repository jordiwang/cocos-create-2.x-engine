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
#include "Class.hpp"

#if SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8

#include "Object.hpp"
#include "Utils.hpp"
#include "ScriptEngine.hpp"

namespace se {
// ------------------------------------------------------- Object

//     namespace {
// //        std::unordered_map<std::string, Class *> __clsMap;
//         std::vector<Class*> __allClasses;
//     }

    Class::Class()
    : _parent(nullptr)
    , _parentProto(nullptr)
    , _proto(nullptr)
    , _ctor(nullptr)
    , _finalizeFunc(nullptr)
    , _createProto(true)
    {
    }

    Class::~Class()
    {
    }

    /* static */
    Class* Class::create(ScriptEngine *inst, const std::string& clsName, se::Object* parent, Object* parentProto, v8::FunctionCallback ctor)
    {
        Class* cls = new Class();
        if (cls != nullptr && !cls->init(inst, clsName, parent, parentProto, ctor))
        {
            delete cls;
            cls = nullptr;
        }
        return cls;
    }

    bool Class::init(ScriptEngine *inst, const std::string& clsName, Object* parent, Object* parentProto, v8::FunctionCallback ctor)
    {
        _name = clsName;

        _parent = parent;
        if (_parent != nullptr)
            _parent->incRef();

        _parentProto = parentProto;
        if (_parentProto != nullptr)
            _parentProto->incRef();

        _ctor = ctor;
        auto *isolate = inst->getIsolate();

        _ctorTemplate.Reset(isolate, v8::FunctionTemplate::New(isolate, _ctor));
        v8::MaybeLocal<v8::String> jsNameVal = v8::String::NewFromUtf8(isolate, _name.c_str(), v8::NewStringType::kNormal);
        if (jsNameVal.IsEmpty())
            return false;

        _ctorTemplate.Get(isolate)->SetClassName(jsNameVal.ToLocalChecked());
        _ctorTemplate.Get(isolate)->InstanceTemplate()->SetInternalFieldCount(1);

        return true;
    }

    void Class::destroy()
    {
        SAFE_DEC_REF(_parent);
        SAFE_DEC_REF(_proto);
        SAFE_DEC_REF(_parentProto);
        _ctorTemplate.Reset();
    }

    void Class::cleanup(ScriptEngine *inst)
    {
        auto &classes = inst->getClasses();
        for (auto cls : classes)
        {
            cls.second->destroy();
        }

        inst->addAfterCleanupHook([&classes](){
            for (auto cls : classes)
            {
                delete cls.second;
            }
            classes.clear();
        });
    }

    void Class::setCreateProto(bool createProto)
    {
        _createProto = createProto;
    }

    bool Class::install(ScriptEngine *inst)
    {
//        assert(__clsMap.find(_name) == __clsMap.end());
//
//        __clsMap.emplace(_name, this);
        auto *isolate = inst->getIsolate();

        if (_parentProto != nullptr)
        {
            _ctorTemplate.Get(isolate)->Inherit(_parentProto->_getClass()->_ctorTemplate.Get(isolate));
        }

        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        v8::MaybeLocal<v8::Function> ctor = _ctorTemplate.Get(isolate)->GetFunction(context);
        if (ctor.IsEmpty())
            return false;

        v8::Local<v8::Function> ctorChecked = ctor.ToLocalChecked();
        v8::MaybeLocal<v8::String> name = v8::String::NewFromUtf8(isolate, _name.c_str(), v8::NewStringType::kNormal);
        if (name.IsEmpty())
            return false;

        v8::Maybe<bool> result = _parent->_getJSObject()->Set(context, name.ToLocalChecked(), ctorChecked);
        if (result.IsNothing())
            return false;

        v8::MaybeLocal<v8::String> prototypeName = v8::String::NewFromUtf8(isolate, "prototype", v8::NewStringType::kNormal);
        if (prototypeName.IsEmpty())
            return false;

        v8::MaybeLocal<v8::Value> prototypeObj = ctorChecked->Get(context, prototypeName.ToLocalChecked());
        if (prototypeObj.IsEmpty())
            return false;

        if (_createProto)
        {
            // Proto object is released in Class::destroy.
            _proto = Object::_createJSObject(inst, this, v8::Local<v8::Object>::Cast(prototypeObj.ToLocalChecked()));
            _proto->root();
        }
        return true;
    }

    bool Class::defineFunction(ScriptEngine *inst, const char *name, v8::FunctionCallback func)
    {
        auto *isolate = inst->getIsolate();
        v8::MaybeLocal<v8::String> jsName =  v8::String::NewFromUtf8(isolate, name, v8::NewStringType::kNormal);
        if (jsName.IsEmpty())
            return false;
        _ctorTemplate.Get(isolate)->PrototypeTemplate()->Set(jsName.ToLocalChecked(), v8::FunctionTemplate::New(isolate, func));
        return true;
    }

    bool Class::defineProperty(ScriptEngine *inst, const char *name, v8::FunctionCallback getter, v8::FunctionCallback setter)
    {
        auto *isolate = inst->getIsolate();
        v8::MaybeLocal<v8::String> jsName =  v8::String::NewFromUtf8(isolate, name, v8::NewStringType::kNormal);
        if (jsName.IsEmpty())
            return false;

        auto prototypeTemplate = _ctorTemplate.Get(isolate)->PrototypeTemplate();

        v8::Local<v8::FunctionTemplate> getterTemplate{};
        v8::Local<v8::FunctionTemplate> setterTemplate{};

        if (getter != nullptr) {
            getterTemplate = v8::FunctionTemplate::New(isolate, getter);
        }

        if (setter != nullptr) {
            setterTemplate = v8::FunctionTemplate::New(isolate, setter);
        }
        prototypeTemplate->SetAccessorProperty(jsName.ToLocalChecked(), getterTemplate, setterTemplate);
        return true;
    }

    bool Class::defineStaticFunction(ScriptEngine *inst, const char *name, v8::FunctionCallback func)
    {
        auto *isolate = inst->getIsolate();
        v8::MaybeLocal<v8::String> jsName =  v8::String::NewFromUtf8(isolate, name, v8::NewStringType::kNormal);
        if (jsName.IsEmpty())
            return false;
        _ctorTemplate.Get(isolate)->Set(jsName.ToLocalChecked(), v8::FunctionTemplate::New(isolate, func));
        return true;
    }

    bool Class::defineStaticProperty(ScriptEngine *inst, const char *name, v8::AccessorNameGetterCallback getter, v8::AccessorNameSetterCallback setter)
    {
        auto *isolate = inst->getIsolate();
        v8::MaybeLocal<v8::String> jsName =  v8::String::NewFromUtf8(isolate, name, v8::NewStringType::kNormal);
        if (jsName.IsEmpty())
            return false;
        _ctorTemplate.Get(isolate)->SetNativeDataProperty(jsName.ToLocalChecked(), getter, setter);
        return true;
    }

    bool Class::defineFinalizeFunction(V8FinalizeFunc finalizeFunc)
    {
        assert(finalizeFunc != nullptr);
        _finalizeFunc = finalizeFunc;
        return true;
    }

//    v8::Local<v8::Object> Class::_createJSObject(const std::string &clsName, Class** outCls)
//    {
//        auto iter = __clsMap.find(clsName);
//        if (iter == __clsMap.end())
//        {
//            *outCls = nullptr;
//            return v8::Local<v8::Object>::Cast(v8::Undefined(__isolate));
//        }
//
//        *outCls = iter->second;
//        return _createJSObjectWithClass(iter->second);
//    }

    v8::Local<v8::Object> Class::_createJSObjectWithClass(ScriptEngine *inst, Class* cls)
    {
        auto *isolate = inst->getIsolate();
        v8::MaybeLocal<v8::Object> ret = cls->_ctorTemplate.Get(isolate)->InstanceTemplate()->NewInstance(isolate->GetCurrentContext());
        assert(!ret.IsEmpty());
        return ret.ToLocalChecked();
    }

    Object* Class::getProto() const
    {
        return _proto;
    }

    V8FinalizeFunc Class::_getFinalizeFunction() const
    {
        return _finalizeFunc;
    }

} // namespace se {

#endif // #if SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8
