
#pragma once

#include <chrono>
#include <memory>
#include "base/ccMacros.h"

#if FORCE_ENABLE_EXECUTION_TIMEOUT_TRIGGER
#define ENABLE_EXECUTION_TIMEOUT_TRIGGER 1
#else
#if COCOS2D_DEBUG
#define ENABLE_EXECUTION_TIMEOUT_TRIGGER 1
#else
#define ENABLE_EXECUTION_TIMEOUT_TRIGGER 0
#endif
#endif

#if ENABLE_EXECUTION_TIMEOUT_TRIGGER

namespace hsext {
struct CountdownTriggerContext;

/**
 * @class CountdownTrigger
 * @brief A class implementing a singleton countdown trigger mechanism.
 *
 * The CountdownTrigger class provides a mechanism to trigger a callback function after a specified timeout duration.
 * Due to the underlying signal system implementation, only one instance of CountdownTrigger can be created at a time.
 * This is because signal handlers may overwrite each other if multiple instances exist.
 * The callback function is intended to be automatically triggered when the timeout is reached.
 * If the CountdownTrigger object is destroyed, the countdown trigger will be cancelled.
 *
 * Example usage:
 * @code
 *     void myTimeoutFunction() {
 *         // Code to be executed upon timeout.
 *     }
 *     {
 *         CountdownTrigger wd(5000, myTimeoutFunction); // Set a timeout of 5000 milliseconds.
 *         // Perform actions under the supervision of the CountdownTrigger.
 *         ....
 *     }
 * @endcode
 */
class CountdownTrigger final {
public:
    using Callback = void (*)();
    /**
     * @brief Construct a new CountdownTrigger object. Remember only one instance of CountdownTrigger can exist at a time.
     *
     * @param timeoutMS The timeout duration in milliseconds.
     * @param cb The callback function to be executed when the timeout duration is reached.
     */
    CountdownTrigger(int32_t timeoutMS, Callback cb);
    ~CountdownTrigger();

    static void init();
    static void destroy();

private:
    /**
     * @brief Inspect the current state of the CountdownTrigger instance.
     */
    void inspect();
    /**
     * @brief Method triggered when the timeout signal is received. This method should not be called manually.
     */
    inline void fire();
    Callback _onTimeout;
    int32_t _timeoutMS{1000};
    bool _callbackFired{false};
    std::unique_ptr<CountdownTriggerContext> _context;
    std::chrono::time_point<std::chrono::steady_clock> _startTime;

    friend class CountdownTriggerContext;
};

inline void CountdownTrigger::inspect() {
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;
    using std::chrono::steady_clock;
    auto now = steady_clock::now();
    auto past = duration_cast<milliseconds>(now - _startTime).count();
    CCLOG("[CountdownTrigger] timeout: %dms, past: %dms", _timeoutMS, static_cast<int>(past));
}

inline void CountdownTrigger::fire() {
    if (_onTimeout) _onTimeout();
    _callbackFired = true;
}

} // namespace cc

#endif