//
//  WebWorkerEndec.hpp
//  libcocos2d iOS
//
//  Created by admin on 2024/5/14.
//

#pragma once
#include <memory>
#include <optional>
#include <vector>

namespace se {
class Value;
struct Message {
    std::vector<std::shared_ptr<v8::BackingStore>> sharedArrayBuffer;
    std::optional<v8::SharedValueConveyor> sharedValueConveyor;
    std::vector<v8::CompiledWasmModule> wasmModules;
    uint8_t *data{nullptr};
    size_t size{0};
    Message() = default;
    Message(const Message &) = delete;
    Message & operator = (const Message &) = delete;

    ~Message() {
        if(data && size > 0) free(data);
        data = nullptr;
        size = 0;
    }
};
}

namespace cc {
bool encodeMessage(v8::Isolate *inst, const se::Value &obj, se::Message &output);
bool decodeMessage(v8::Isolate *inst, se::Message &output, se::Value &obj);
}

