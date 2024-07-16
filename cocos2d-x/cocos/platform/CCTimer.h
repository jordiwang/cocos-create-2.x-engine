#pragma once

#include <functional>
#include <string>
#include <string_view>

namespace se {
class ScriptEngine;
}
namespace cc {
struct TimerContext;
class TimerLoop {
public:
    explicit TimerLoop(se::ScriptEngine *inst);
    ~TimerLoop();

    void waitFor(int ms);
    int dispatchTask(std::function<void()> &&task, std::string_view taskName);
    [[nodiscard]] int setInterval(float dt, std::function<void(float)> &&task);
    int setTimeout(float dt, std::function<void()> &&task);
    void clearTimeout(int);
    void clearInterval(int);

    int addIdleTask(std::function<void()> &&task, std::string_view taskName);
    void clearIdleTask(int);

    void update();
    void clearTasks();

    void setState(std::string_view state) {
#if COCOS2D_DEBUG > 0
        _stateStr = state;
#endif
    }

    void loop();
    void stop();

    void requestInterrupt();
private:
    se::ScriptEngine *_inst{nullptr};
    TimerContext *_timerContext{nullptr};
#if COCOS2D_DEBUG > 0
    std::string _stateStr;
#endif
    bool _inUpdateLoop{false};
    std::atomic_bool _timeoutHappended{false};
};
} // namespace cc
