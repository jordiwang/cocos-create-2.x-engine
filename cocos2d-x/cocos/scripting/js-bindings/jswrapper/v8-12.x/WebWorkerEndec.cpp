//
//  WebWorkerEndec.cpp
//  libcocos2d iOS
//
//  Created by admin on 2024/5/14.
//
#include "v8.h"
#include "WebWorkerEndec.hpp"
#include "Utils.hpp"


namespace cc {
bool encodeMessage(v8::Isolate *inst, const se::Value &obj, se::Message &output);
bool decodeMessage(v8::Isolate *inst, se::Message &output, se::Value &obj);


namespace {

template <class TypeName>
static inline v8::Local<TypeName> Strong(
        const v8::PersistentBase<TypeName>& persistent) {
    assert(!persistent.IsWeak());
    return *reinterpret_cast<v8::Local<TypeName>*>(
            const_cast<v8::PersistentBase<TypeName>*>(&persistent));
}

class SerializeDelegate : public v8::ValueSerializer::Delegate {
public:
    SerializeDelegate(v8::Isolate *isolate, se::Message *msg):msg(msg),inst(isolate) {

    }
    virtual ~SerializeDelegate() = default;

    void ThrowDataCloneError(v8::Local<v8::String> message)  override {
        inst->ThrowException(message);
    }

    bool HasCustomHostObject(v8::Isolate *isolate) override {return false;}

    v8::Maybe<bool> IsHostObject(v8::Isolate *isolate, v8::Local<v8::Object> object) override {
        return v8::Just(false);
    }

    v8::Maybe<bool> WriteHostObject(v8::Isolate *isolate, v8::Local<v8::Object> object) override {
        v8::MaybeLocal<v8::String> str = v8::String::NewFromUtf8(isolate, "Can not write host-objects");
        ThrowDataCloneError(str.ToLocalChecked());
        return v8::Nothing<bool>();
    }

    v8::Maybe<uint32_t> GetSharedArrayBufferId(v8::Isolate *isolate, v8::Local<v8::SharedArrayBuffer> shared) override {
        uint32_t i;
        for(i = 0; i < seenArrayBuffers.size(); i++) {
            if(Strong(seenArrayBuffers[i]) == shared) {
                return v8::Just(i);
            }
        }

        seenArrayBuffers.emplace_back(v8::Global<v8::SharedArrayBuffer>{isolate, shared});
        msg->sharedArrayBuffer.emplace_back(shared->GetBackingStore());
        return v8::Just(i);
    }

    v8::Maybe<uint32_t> GetWasmModuleTransferId(v8::Isolate *isolate, v8::Local<v8::WasmModuleObject> module) override {
        msg->wasmModules.emplace_back(module->GetCompiledModule());
        return v8::Just(static_cast<uint32_t>(msg->wasmModules.size() - 1));
    }

    bool AdoptSharedValueConveyor(v8::Isolate *isolate, v8::SharedValueConveyor && convery) override {
        msg->sharedValueConveyor.emplace(std::move(convery));
        return true;
    }

private:
    se::Message *msg{nullptr};
    v8::Isolate *inst{nullptr};
    std::vector<v8::Global<v8::SharedArrayBuffer>> seenArrayBuffers;
};

class DeserializeDelegate: public v8::ValueDeserializer::Delegate {
public:
    DeserializeDelegate(v8::Isolate *inst, se::Message *msg):msg(msg), inst(inst) {
    }
    
    virtual ~DeserializeDelegate() = default;
    
    v8::MaybeLocal<v8::Object> ReadHostObject(v8::Isolate *isolate) override {
        return v8::MaybeLocal<v8::Object>();
    }

    v8::MaybeLocal<v8::SharedArrayBuffer> GetSharedArrayBufferFromId(v8::Isolate *isolate, uint32_t cloneId) override {
        if(cloneId >= msg->sharedArrayBuffer.size()) return {};
        v8::Local<v8::SharedArrayBuffer> sab = v8::SharedArrayBuffer::New(isolate, msg->sharedArrayBuffer[cloneId]);
        return sab;
    }

    v8::MaybeLocal<v8::WasmModuleObject> GetWasmModuleFromId(v8::Isolate *isolate, uint32_t transId) override {
        if(transId >= msg->wasmModules.size()) return {};
        return v8::WasmModuleObject::FromCompiledModule(isolate, msg->wasmModules[transId]);
    }

    const v8::SharedValueConveyor * GetSharedValueConveyor(v8::Isolate *isolate) override {
        if(!msg->sharedValueConveyor.has_value()) return nullptr;
        return &msg->sharedValueConveyor.value();
    }

private:
    se::Message *msg{nullptr};
    v8::Isolate *inst{nullptr};
};
}

bool encodeMessage(v8::Isolate *isolate, const se::Value &obj, se::Message &output) {
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::HandleScope scope(isolate);
    v8::Context::Scope contextScope(context);
    SerializeDelegate delegate(isolate, &output);
    v8::ValueSerializer serializer(isolate, &delegate);

    v8::Local<v8::Value> tmp;
    se::internal::seToJsValue(isolate, obj, &tmp);
    serializer.WriteHeader();
    if(serializer.WriteValue(context, tmp).IsNothing()) {
        return false;
    }

    std::pair<uint8_t*, size_t> data = serializer.Release();
    output.data = data.first;
    output.size = data.second;
    return true;
}

bool decodeMessage(v8::Isolate *isolate, se::Message &input, se::Value &obj) {
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::HandleScope scope(isolate);
    v8::Context::Scope contextScope(context);

    DeserializeDelegate delegate(isolate, &input);
    v8::ValueDeserializer deserializer(isolate, input.data, input.size, &delegate);

    if(deserializer.ReadHeader(context).IsNothing()) return false;

    v8::Local<v8::Value> output;
    if(!deserializer.ReadValue(context).ToLocal(&output)) return false;

    se::internal::jsToSeValue(isolate,output, &obj);
    return true;
}


}
