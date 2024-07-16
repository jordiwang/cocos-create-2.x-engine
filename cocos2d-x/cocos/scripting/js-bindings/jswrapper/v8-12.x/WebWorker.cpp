//
// Created by pt on 2024/5/14.
//

#include "uv.h"

#include "v8.h"
#include "WebWorker.h"
#include "WebWorkerEndec.hpp"

#include "./SeApi.h"

#include <mutex>
#include <vector>
#include <memory>
#include <condition_variable>
#include <optional>
#include <base/ccMacros.h>

#include "cocos/scripting/js-bindings/manual/jsb_worker_manual.hpp"
#include "cocos/scripting/js-bindings/manual/jsb_global.h"


namespace se {
    
    namespace {
        std::unordered_set<WebWorker*> allWorkers;
        std::mutex allWorkersMtx;

    }
     
    void WebWorker::stopAll() {
        // 这个方法在主线程中调用，worker 线程有可能正在实现 Worker 的 destructor
        // 有概率奔溃，但是在退出阶段。暂时忽略。
        std::unordered_set<WebWorker*> workersTmp;
        {
            std::lock_guard<std::mutex> guard(allWorkersMtx);
            std::swap(allWorkers, workersTmp);
        }
        for(auto *w : workersTmp) {
            w->incRef();
            CCLOG("Workers<%s> is stopping...", w->getName().c_str());
            w->terminate();
        }
        for(auto *w : workersTmp) {
            w->wait();
            w->decRef();
            CCLOG("Workers<%s> stopped", w->getName().c_str());
        }
        
    }

    WebWorker::WebWorker(ScriptEngine *parent, std::string_view path):_parentScriptEngine(parent){
        _scriptEngine = new ScriptEngine();
        _scriptEngine->addRegisterCallback(register_web_worker_thread);
        _scriptEngine->enableDebugger("", -1); // disable debugger
        jsb_init_file_operation_delegate(_scriptEngine);
        _scriptEngine->setExceptionCallback([](const char *location, const char *message, const char *stack){
           CCLOGERROR("<Worker> exception: %s, loc: %s, stack: %s\n", message, location, stack);
        });
        _scriptEngine->start();
        // register worker
        _scriptEngine->setWorker(this);
        // set timer
        _mainLoop = new cc::TimerLoop(_scriptEngine);
        _scriptEngine->setTimer(_mainLoop);
        // _mainLoop->addIdleTask([this](){
        //     _scriptEngine->checkTask();
        // }, "worker.idle");
        _aliveId = _mainLoop->setInterval(10.0F, [](float dt){
            CCLOG("<Worker> worker alive");
        });
        CCLOG("<Worker> Run worker with %s", path.data());
        _scriptEngine->runScript(path);


        
        if(allWorkers.size() > 10) {
            CCLOGERROR("[error] Too many workers created: %d", static_cast<int>(allWorkers.size()));
        }
        std::lock_guard<std::mutex> guard(allWorkersMtx);
        allWorkers.insert(this);
    }

    WebWorker::~WebWorker() {
        // should stop the thread which created it
//        stop"();
        CCLOG("~Worker<%s>: deleted. %d workers remain.", _name.c_str(), static_cast<int>(allWorkers.size()));
        {
            std::lock_guard<std::mutex> guard(allWorkersMtx);
            allWorkers.erase(this);
        }
    }

    void WebWorker::terminate() {
        if(_mainLoop) {
            _mainLoop->stop();
        }
    }

    void WebWorker::stop() {
        if(_mainLoop){
            _mainLoop->clearInterval(_aliveId);
            _mainLoop->stop();
            delete _mainLoop;
            _mainLoop = nullptr;
        }
        if(_scriptEngine) {
            _scriptEngine->cleanup();
            delete _scriptEngine;
            _scriptEngine = nullptr;
        }
    }

    void WebWorker::pollMessage() {
        if(!_mainLoop) return;
        _mainLoop->loop();
        _workerEnded.set_value();
    }

    void WebWorker::wait() {
        _workerEnded.get_future().get();
    }

    void WebWorker::postMessage(se::ScriptEngine *currentScriptEngine, se::ScriptEngine *dstScriptEngine, const se::Value &jsVal, std::function<void(const se::Value &)> &&handler) {
        if(!dstScriptEngine) return;
        auto msg = std::make_shared<Message>();
        cc::encodeMessage(currentScriptEngine->getIsolate(), jsVal, *msg);
        if(!dstScriptEngine || !dstScriptEngine->isValid()) return;
        dstScriptEngine->getTimer()->dispatchTask([msg, dstScriptEngine, handler = std::move(handler)](){
            se::AutoHandleScope scope(dstScriptEngine);
            //TODO: add se::context_scope
            v8::Context::Scope contextScope(dstScriptEngine->_getContext());
            se::Value out;
            cc::decodeMessage(dstScriptEngine->getIsolate(), *msg, out);
            handler(out);
        }, "worker.postMessage");
    }

}
