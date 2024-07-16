//
// Created by pt on 2024/5/14.
//

#pragma once

#include "platform/CCTimer.h"
#include "../RefCounter.hpp"

#include <memory>
#include <future>
#include <string_view>
#include <atomic>

namespace se {

    class ScriptEngine;
    class Message;
    class Value;

class WebWorker final : public RefCounter {
public:
    static void stopAll();
    
    WebWorker(ScriptEngine *parent, std::string_view path);
    ~WebWorker();

    void stop();
    void terminate();

    static void postMessage(se::ScriptEngine *currentScriptEngine, se::ScriptEngine *dstScriptEngine, const se::Value &msg, std::function<void(const se::Value&)> &&handler);
    void pollMessage();

    se::ScriptEngine *getScriptEngine() const {
        return _scriptEngine;
    }
    se::ScriptEngine *getParent() const {
        return _parentScriptEngine;
    }
    void wait();
    
    const std::string &getName() const {return _name;}
    void setName(std::string_view name) {_name = name;}
private:

    ScriptEngine *_parentScriptEngine{nullptr};
    ScriptEngine *_scriptEngine{nullptr};
    cc::TimerLoop *_mainLoop{nullptr};
    std::promise<void> _workerEnded;
    int _aliveId{0};
    std::string _name;
};

}


