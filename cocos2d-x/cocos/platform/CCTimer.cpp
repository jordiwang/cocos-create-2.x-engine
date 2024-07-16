#include "CCTimer.h"

#include <atomic>
#include <chrono>
#include <iterator>
#include <mutex>
#include <string>
#include <string_view>
#include <unordered_map>
#include "base/ccMacros.h"
#include "base/ccUtils.h"
#include "scripting/js-bindings/jswrapper/SeApi.h"
#include "uv.h"

#if COCOS2D_DEBUG > 0
    #define LDEBUG 1
#else
    #define LDEBUG 0
#endif

#define PRINT_HANDLES 0

namespace cc {
struct TimerContext;
namespace {
struct AsyncTask {
    AsyncTask() = default;
    AsyncTask(AsyncTask &&o) noexcept {
        moveInto(std::move(o));
    }

    AsyncTask(const AsyncTask &) = delete;
    AsyncTask &operator=(const AsyncTask &) = delete;
    AsyncTask &operator=(AsyncTask &&o) noexcept {
        moveInto(std::move(o));
        return *this;
    }

    void moveInto(AsyncTask &&o) noexcept {
        if (&o == this) return;
        callback = std::move(o.callback);
        timerContext = o.timerContext;
        id = o.id;
        o.timerContext = nullptr;
        o.id = 0;
#if LDEBUG
        startTime = o.startTime;
        taskName = std::move(o.taskName);
        appState = std::move(o.appState);
        isUpdating = o.isUpdating;
#endif
    }
    std::function<void()> callback;
    TimerContext *timerContext;
    int id;
#if LDEBUG
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::string taskName;
    std::string appState;
    bool isUpdating;
#endif
};
struct IntervalTask {
    uv_timer_t handle;
    std::function<void(float)> callback;
    TimerContext *timerContext;
    int id;
    int runTimes{0};
    std::chrono::time_point<std::chrono::high_resolution_clock> lastTime;
#if LDEBUG
    float interval;
#endif
};

struct DelayTask {
    uv_timer_t handle;
    std::function<void()> callback;
    TimerContext *timerContext;
    int id;
    float timeout;
#if LDEBUG
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
#endif
};

struct CheckTask {
    uv_check_t handle;
    std::function<void()> callback;
    TimerContext *timerContext;
    int id;
#if LDEBUG
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::string taskName;
#endif
};

template <typename T>
inline T *to_context(void *ptr) { // NOLINT
    constexpr auto offset = offsetof(T, handle);
    return reinterpret_cast<T *>(reinterpret_cast<char *>(ptr) - offset);
}

template<typename T>
void free_task_cb(uv_handle_t *ptr) {
    delete to_context<T>(ptr);
}

} // namespace

struct TimerContext {
    TimerContext() { uv_loop_init(&mainLoop); }
    ~TimerContext() { uv_loop_close(&mainLoop); }
    uv_loop_t mainLoop;
    uv_async_t asyncTasksHandle;
    uv_async_t interruptHandle;
    uv_timer_t waitForHandle;
#if COCOS2D_DEBUG > 0 && PRINT_HANDLES
    uv_timer_t inspectHandleDbg;
#endif
    int intervalIdGen{10000};
    int delayIdGen{20000};
    std::atomic_int32_t asyncIdGen{30000};
    int idleIdGen{40000};
    std::unordered_map<int, IntervalTask *> intervalTasks;
    std::unordered_map<int, DelayTask *> delayTasks;
    std::unordered_map<int, CheckTask *> idleTasks;
    mutable std::recursive_mutex asyncTasksMutex;
    std::vector<std::unique_ptr<AsyncTask>> asyncTasks;

    bool hasImmediateTask() const {
        std::unique_lock<std::recursive_mutex> guard(asyncTasksMutex);
        if (!asyncTasks.empty()) {
            return true;
        }
        for (const auto &t : delayTasks) {
            if (t.second->timeout == 0.0F) {
                return true;
            }
        }
        return false;
    }
};

namespace {

void async_interrupt_callback(uv_async_t *async) {
    auto * flag = reinterpret_cast<std::atomic_bool*>(async->data);
    if(flag && !flag->load()) {
        uv_stop(async->loop);
    }
}

void async_task_callback(uv_async_t *async) { // NOLINT
    auto *taskContext = reinterpret_cast<TimerContext *>(async->data);
    if (!taskContext) return;
    std::vector<std::unique_ptr<AsyncTask>> tasks;
    {
        std::unique_lock<std::recursive_mutex> guard(taskContext->asyncTasksMutex);
        std::swap(tasks, taskContext->asyncTasks);
    }

    for (auto &tsk : tasks) {
#if LDEBUG
        auto pst = std::chrono::duration_cast<std::chrono::microseconds>(
                       std::chrono::high_resolution_clock::now() - tsk->startTime)
                       .count();
        if(!tsk->taskName.empty()) {
            CCLOG("[timer] dispatch_task<%s> takes: %f ms, updating: %d, app_state: %s",
                tsk->taskName.c_str(), pst / 1000.0F, tsk->isUpdating ? 1 : 0,
                tsk->appState.c_str());
        }
#endif
        tsk->callback();
    }
}

void interval_task_callback(uv_timer_t *timer) { // NOLINT
    auto *ctx = to_context<IntervalTask>(timer);
    if (!ctx) return;
//    CCLOG("[timer] trigger interval %p, id %d, interval %f", ctx, ctx->id, ctx->interval);
    auto now = std::chrono::high_resolution_clock::now();
    auto past =
        std::chrono::duration_cast<std::chrono::milliseconds>(now - ctx->lastTime)
            .count();
    ctx->lastTime = now;
    ctx->runTimes++;
    ctx->callback(past / 1000.0F);
}
void delay_task_callbackr(uv_timer_t *timer) { // NOLINT
    auto *ctx = to_context<DelayTask>(timer);
#if LDEBUG
    auto pst = std::chrono::duration_cast<std::chrono::microseconds>(
                   std::chrono::high_resolution_clock::now() - ctx->startTime)
                   .count();
    CCLOG("[timer] timeout takes: %f ms, %f ms expected", pst / 1000.0F,
          ctx->timeout * 1000.0F);
#endif
    // remove first
    uv_timer_stop(timer);
    ctx->timerContext->delayTasks.erase(ctx->id);
    uv_close(reinterpret_cast<uv_handle_t *>(timer), free_task_cb<DelayTask>);
    
    // invoke callback later
    ctx->callback();
}
void check_task_callback(uv_check_t *timer) { // NOLINT
    auto *ctx = to_context<CheckTask>(timer);
    if (!ctx) return;
    ctx->callback();
}
} // namespace

TimerLoop::TimerLoop(se::ScriptEngine *inst) : _inst(inst) {
    _timerContext = new TimerContext;

    uv_async_init(&_timerContext->mainLoop, &_timerContext->asyncTasksHandle, async_task_callback);
    _timerContext->asyncTasksHandle.data = _timerContext;

    uv_async_init(&_timerContext->mainLoop, &_timerContext->interruptHandle, async_interrupt_callback);
    _timerContext->interruptHandle.data = &_timeoutHappended;

    uv_timer_init(&_timerContext->mainLoop, &_timerContext->waitForHandle);
    _timerContext->waitForHandle.data = &_timeoutHappended;

#if COCOS2D_DEBUG > 0 && PRINT_HANDLES
    static int aliveTick = 0;
    uv_timer_init(&_timerContext->mainLoop, &_timerContext->inspectHandleDbg);
    uv_timer_start(
        &_timerContext->inspectHandleDbg, [](uv_timer_t *timer) {
            cocos2d::log("[TimerLoop] alive %d", aliveTick++);
            uv_walk(
                timer->loop, [](uv_handle_t *handle, void * /* unused*/) {
                    cocos2d::log("[TimerLoop] walk: handle %p, type %d", handle, handle->type);
                    if (handle->type == UV_TIMER) {
                        auto *t = reinterpret_cast<uv_timer_t *>(handle);
                        cocos2d::log("   timer: repeat: %d", static_cast<int>(uv_timer_get_repeat(t)));
                    } else if (handle->type == UV_ASYNC) {
                        auto *c = reinterpret_cast<AsyncTask *>(handle->data);
                        if (c) {
                            cocos2d::log("   async: %s", c->taskName.c_str());
                        }
                    }
                },
                nullptr);
        },
        1000, 10000);
#endif
}

TimerLoop::~TimerLoop() {
    uv_close(reinterpret_cast<uv_handle_t *>(&_timerContext->waitForHandle), nullptr);
    uv_close(reinterpret_cast<uv_handle_t *>(&_timerContext->asyncTasksHandle), nullptr);
    uv_close(reinterpret_cast<uv_handle_t *>(&_timerContext->interruptHandle), nullptr);
#if LDEBUG > 0 && PRINT_HANDLES
    uv_timer_stop(&_timerContext->inspectHandleDbg);
    uv_close(reinterpret_cast<uv_handle_t *>(&_timerContext->inspectHandleDbg), nullptr);
#endif
    delete _timerContext;
}

int TimerLoop::dispatchTask(std::function<void()> &&task,
                            std::string_view taskName) {
    if (_inst->inMainThread()) {
        task();
        return 0;
    }
    auto newId = _timerContext->asyncIdGen++;
    {
        std::unique_lock<std::recursive_mutex> guard(_timerContext->asyncTasksMutex);
        auto ctx = std::make_unique<AsyncTask>();
#if LDEBUG
        ctx->startTime = std::chrono::high_resolution_clock::now();
        ctx->taskName = std::string(taskName);
        ctx->appState = _stateStr;
        ctx->isUpdating = _inUpdateLoop;
#endif
        ctx->callback = std::move(task);
        ctx->timerContext = _timerContext;
        ctx->id = newId;
        _timerContext->asyncTasks.emplace_back(std::move(ctx));
    }
    uv_async_send(&_timerContext->asyncTasksHandle);
    return newId;
}

int TimerLoop::setInterval(float dt, std::function<void(float)> &&task) {
    if (_inst->isValid()) {
        assert(_inst->inMainThread());
    }
    auto newId = _timerContext->intervalIdGen++;
    auto *data = new IntervalTask;
    data->callback = std::move(task);
    data->timerContext = _timerContext;
    data->id = newId;
    data->lastTime = std::chrono::high_resolution_clock::now();
#if LDEBUG
    data->interval = dt;
#endif
    CCLOG("[timer] setInterval %p: %d", data, newId);
    _timerContext->intervalTasks[newId] = data;
    uv_timer_init(&_timerContext->mainLoop, &data->handle);
    // repeat forever
    uint64_t dtMS = dt * 1000;
    assert(dtMS > 1);
    uv_timer_start(&data->handle, interval_task_callback, dtMS, dtMS);
    return newId;
}

int TimerLoop::setTimeout(float dt, std::function<void()> &&task) {
    if (_inst->isValid()) {
        assert(_inst->inMainThread());
    }
    auto newId = _timerContext->delayIdGen++;
    auto *data = new DelayTask;
    data->callback = std::move(task);
    data->timerContext = _timerContext;
    data->id = newId;
    data->timeout = dt;
#if LDEBUG
    data->startTime = std::chrono::high_resolution_clock::now(),
#endif
    _timerContext->delayTasks[newId] = data;
    uv_timer_init(&_timerContext->mainLoop, &data->handle);
    // repeat once
    uv_timer_start(&data->handle, delay_task_callbackr, dt * 1000, 0);
    return newId;
}

void TimerLoop::clearTimeout(int id) {
    if (_inst->isValid()) {
        assert(_inst->inMainThread());
    }
    auto itr = _timerContext->delayTasks.find(id);
    if (itr == _timerContext->delayTasks.end()) {
        return;
    }
    auto *ctx = itr->second;
    uv_timer_stop(&ctx->handle);
    _timerContext->delayTasks.erase(id);
    ctx->id = ~ctx->id;
    uv_close(reinterpret_cast<uv_handle_t *>(&ctx->handle), free_task_cb<DelayTask>);
}

void TimerLoop::clearInterval(int id) {
    if (_inst->isValid()) {
        assert(_inst->inMainThread());
    }
    auto itr = _timerContext->intervalTasks.find(id);
    if (itr == _timerContext->intervalTasks.end()) {
        return;
    }
    auto *ctx = itr->second;
    CCLOG("[timer] clearInterval %p: %d, interval %f", ctx, id, ctx->interval);
    uv_timer_stop(&ctx->handle);
    uv_close(reinterpret_cast<uv_handle_t *>(&ctx->handle), free_task_cb<IntervalTask>);
    _timerContext->intervalTasks.erase(id);
}

int TimerLoop::addIdleTask(std::function<void()> &&task, std::string_view taskName) {
    if (_inst->isValid()) {
        assert(_inst->inMainThread());
    }
    auto newId = _timerContext->idleIdGen++;
    auto *data = new CheckTask(CheckTask {
        .callback = std::move(task),
        .timerContext = _timerContext,
        .id = newId,
#if LDEBUG
        .startTime = std::chrono::high_resolution_clock::now(),
        .taskName = std::string(taskName),
#endif
    });
    _timerContext->idleTasks[newId] = data;
    uv_check_init(&_timerContext->mainLoop, &data->handle);
    uv_check_start(&data->handle, check_task_callback);
    return newId;
}

void TimerLoop::clearIdleTask(int id) {
    if (_inst->isValid()) {
        assert(_inst->inMainThread());
    }
    auto itr = _timerContext->idleTasks.find(id);
    if (itr == _timerContext->idleTasks.end()) {
        return;
    }
    auto *ctx = itr->second;
    uv_check_stop(&ctx->handle);
    _timerContext->idleTasks.erase(itr);
    uv_close(reinterpret_cast<uv_handle_t *>(&ctx->handle), free_task_cb<CheckTask>);
}

void TimerLoop::update() {
    if (_inst->isValid()) {
        assert(_inst->inMainThread());
    }
    if (_inUpdateLoop) {
        return;
    }
    _inUpdateLoop = true;
    do {
        uv_run(&_timerContext->mainLoop, UV_RUN_NOWAIT);
    } while (_timerContext->hasImmediateTask());
    _inUpdateLoop = false;
}

void TimerLoop::clearTasks() {
    // mutex required
    auto intevalTasks = std::move(_timerContext->intervalTasks);
    auto delayTasks = std::move(_timerContext->delayTasks);
    auto idleTasks = std::move(_timerContext->idleTasks);

    for (auto &itr : intevalTasks) {
        uv_timer_stop(&itr.second->handle);
        itr.second->handle.data = nullptr;
        uv_close(reinterpret_cast<uv_handle_t *>(&itr.second->handle), free_task_cb<IntervalTask>);
    }
    for (auto &itr : delayTasks) {
        uv_timer_stop(&itr.second->handle);
        itr.second->handle.data = nullptr;
        uv_close(reinterpret_cast<uv_handle_t *>(&itr.second->handle), free_task_cb<DelayTask>);
    }

    for (auto &itr : idleTasks) {
        uv_check_stop(&itr.second->handle);
        itr.second->handle.data = nullptr;
        uv_close(reinterpret_cast<uv_handle_t *>(&itr.second->handle), free_task_cb<CheckTask>);
    }

    update(); /* flush all close_cb */
}

void TimerLoop::waitFor(int ms) {
    if (_inUpdateLoop) {
        return;
    }
//    cocos2d::Perf waitForPerf("[Timer] waitFor");
    _inUpdateLoop = true;
    auto *handle = &_timerContext->waitForHandle;
    _timeoutHappended = false;
    uv_timer_start(
        handle,
        [](uv_timer_t *timer) {
            reinterpret_cast<std::atomic_bool *>(timer->data)->store(true);
            uv_stop(timer->loop);
        },
        ms, 0);
    do {
        uv_run(&_timerContext->mainLoop, UV_RUN_ONCE);
    } while (!_timeoutHappended);

    uv_timer_stop(handle);

    _inUpdateLoop = false;
}

void TimerLoop::loop() {
    uv_run(&_timerContext->mainLoop, UV_RUN_DEFAULT);
}

void TimerLoop::stop() {
    uv_stop(&_timerContext->mainLoop);
}

void TimerLoop::requestInterrupt() {
    if(!_timeoutHappended) {
        _timeoutHappended.store(true);
        uv_async_send(&_timerContext->interruptHandle);
    }
}

} // namespace cc
