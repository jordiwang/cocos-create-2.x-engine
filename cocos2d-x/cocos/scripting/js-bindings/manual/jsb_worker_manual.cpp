//
//  jsb_worker_manual.cpp
//  libcocos2d iOS
//
//  Created by admin on 2024/5/14.
//

#include "jsb_worker_manual.hpp"
#include "base/ccMacros.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"
#include "cocos/scripting/js-bindings/jswrapper/v8-12.x/WebWorker.h"

#include <thread>
#include <future>

#include <pthread.h>

namespace {

se::Class* __jsb_WebWorker_class = nullptr;


bool WebWorker_finalize(se::State &state, se::ScriptEngine *inst){
    auto *worker = reinterpret_cast<se::WebWorker*>(state.nativeThisObject());
    worker->terminate();
    worker->decRef();
    SE_LOGE("<<WebWorker finalized...>>\n");
    return true;
}
SE_BIND_FINALIZE_FUNC(WebWorker_finalize)

bool WebWorker_constructor(se::State &state, se::ScriptEngine *inst) {
    static int workerId = 0;
    
    auto &args = state.args();
    if(args.size() < 1) {
        SE_REPORT_ERROR("1 argument required!");
        assert(false);
        return false;
    }
    auto path = args[0];
    if(!path.isString()) {
        SE_REPORT_ERROR("a file path expected!");
        assert(false);
        return false;
    }
    
    std::string pathv = path.toString();
    if(pathv.empty()){
        SE_REPORT_ERROR("the file path is empty!");
        assert(false);
        return false;
    }
    
    std::promise<se::WebWorker*> promise;
    std::thread sub([&promise,inst, pathv](){
        char buff[32] = {};
        snprintf(buff, 32, "WebWorker.%d", workerId++);
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        pthread_setname_np(buff);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        pthread_setname_np(pthread_self(), buff);
#endif
        auto *worker = new se::WebWorker(inst, pathv);
        worker->setName(buff);
        worker->incRef();
        promise.set_value(worker);
        worker->pollMessage();
        worker->stop();
        worker->decRef();
    });
    sub.detach();
    auto *worker = promise.get_future().get();
    auto *self = state.thisObject(inst);
    self->setPrivateData(worker);
    self->root();

    return true;
}
SE_BIND_CTOR(WebWorker_constructor,__jsb_WebWorker_class, WebWorker_finalize)

bool WebWorker_postMessage(se::State &state, se::ScriptEngine *inst) {
    if(state.args().size() < 1){
        SE_REPORT_ERROR("1 argument is required!");
        return false;
    }
    auto *worker = reinterpret_cast<se::WebWorker*>(state.nativeThisObject());
    auto *workerScriptEngine = worker->getScriptEngine();
    if(!workerScriptEngine) {
//        inst->throwError("The worker was terminated!");
        SE_REPORT_ERROR("Worker was terminated!");
        return false;
    }
    se::WebWorker::postMessage(inst, workerScriptEngine, state.args()[0], [workerScriptEngine](const se::Value &data){
//        se::AutoHandleScope scope(inner);
        se::Value cb;
        auto *globalThis = workerScriptEngine->getGlobalObject();
        globalThis->getProperty("onmessage", &cb);
        if(cb.isNullOrUndefined()) {
            SE_REPORT_ERROR("onmessage is not set in worker script!");
            return;
        }
        se::Value event(se::Object::createPlainObject(workerScriptEngine));
        event.toObject()->setProperty("data", data);
        if(cb.isObject() && cb.toObject()->isFunction()) {
            cb.toObject()->call({event}, nullptr);
        }
    });
    
    return true;
}
SE_BIND_FUNC(WebWorker_postMessage)

bool WebWorker_terminate(se::State &state, se::ScriptEngine *inst) {
    auto *worker = reinterpret_cast<se::WebWorker*>(state.nativeThisObject());
    worker->terminate();
    state.thisObject(inst)->unroot();
    return true;
}
SE_BIND_FUNC(WebWorker_terminate)

bool WorkerThread_postMessage(se::State &state, se::ScriptEngine *workerInst) {
    se::WebWorker *worker = workerInst->getWorker();
    if(!worker) {
        SE_REPORT_ERROR("Can not find worker within current ScriptEngine instance");
        return false;
    }
    if(state.args().size() < 1) {
        SE_REPORT_ERROR("One argument is required!");
        return false;
    }
    auto *parentScriptEngine = worker->getParent();
    se::WebWorker::postMessage(workerInst, parentScriptEngine, state.args()[0],  [parentScriptEngine, worker](const se::Value &data){
        se::Value cb;
        auto &ptrMap = parentScriptEngine->getNativePtrMap();
        auto itr = ptrMap.find(worker);
        if(itr == ptrMap.end()) {
            SE_REPORT_ERROR("Worker instance not found!");
            return;
        }
        itr->second->getProperty("onmessage", &cb);
        if(cb.isNullOrUndefined()) {
            SE_REPORT_ERROR("onmessage is not set on worker object!");
            return;
        }
        se::Value event(se::Object::createPlainObject(parentScriptEngine));
        event.toObject()->setProperty("data", data);
        if(cb.isObject() && cb.toObject()->isFunction()) {
            cb.toObject()->call({event}, itr->second);
        }
    });
    
    return true;
}
SE_BIND_FUNC(WorkerThread_postMessage)

bool WorkerThread_terminate(se::State &state, se::ScriptEngine *workerInst) {
    auto *worker = workerInst->getWorker();
    if(worker) {
        worker->terminate();
        return true;
    }
    return false;
}
SE_BIND_FUNC(WorkerThread_terminate)

}

bool register_web_worker(se::ScriptEngine *inst, se::Object *ns) {
    se::Class *kls = se::Class::create(inst, "Worker", ns, nullptr, _SE(WebWorker_constructor));
    kls->defineFinalizeFunction(_SE(WebWorker_finalize));
    kls->defineFunction(inst, "postMessage", _SE(WebWorker_postMessage));
    kls->defineFunction(inst, "terminate", _SE(WebWorker_terminate));
    kls->install(inst);
    inst->registerClass<se::WebWorker>(kls);
    __jsb_WebWorker_class = kls;
    return true;
}


bool register_web_worker_thread(se::ScriptEngine *workerInst, se::Object *ns) {
    ns->defineFunction("postMessage", _SE(WorkerThread_postMessage));
    ns->defineFunction("terminate", _SE(WorkerThread_terminate));
    return true;
}

