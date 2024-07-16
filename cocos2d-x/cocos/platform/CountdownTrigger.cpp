
#include <sys/types.h>
#include <unistd.h>
#include <algorithm>
#include <chrono>
#include <csignal>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <functional>
#include <memory>
#include "base/ccMacros.h"
#include "platform/CountdownTrigger.h"

#if ENABLE_EXECUTION_TIMEOUT_TRIGGER

namespace hsext {
#define SIGNAL_VALUE SIGALRM
//#define SIGNAL_VALUE SIGUSR1


struct CountdownTriggerContext {
    struct sigaction preAction;
    struct sigaction currAction;
    timer_t timer;

    static void fire(CountdownTrigger *watcher) {
        if (watcher) watcher->fire();
    }
};

namespace {
hsext::CountdownTrigger *currentCountdownTrigger = nullptr;
void timer_signal_handler(int signal, siginfo_t *si, void *uc) { // NOLINT
    if (signal == SIGNAL_VALUE && currentCountdownTrigger) {
        auto *svptr = si->si_value.sival_ptr;
        auto *watcher = reinterpret_cast<hsext::CountdownTrigger *>(svptr);
        CountdownTriggerContext::fire(watcher);
    }
}

struct sigaction backupAction;
struct sigaction globalPrevAction;
} // namespace

void CountdownTrigger::init() {
    memset(&backupAction, 0, sizeof(backupAction));
    sigaction(SIGNAL_VALUE, nullptr, &globalPrevAction);
    // App may crash if no handler setup for signal
    if (globalPrevAction.sa_handler == nullptr && globalPrevAction.sa_sigaction == nullptr) {
        memset(&backupAction, 0, sizeof(backupAction));
        backupAction.sa_handler = SIG_IGN; // ignore signal
        backupAction.sa_flags = 0;
        sigaction(SIGNAL_VALUE, &backupAction, nullptr);
    } else {
        // restore signal handle
        sigaction(SIGNAL_VALUE, &globalPrevAction, nullptr);
    }
}

void CountdownTrigger::destroy() {
    if (backupAction.sa_handler == SIG_IGN) {
        sigaction(SIGNAL_VALUE, &globalPrevAction, nullptr);
    }
}

CountdownTrigger::CountdownTrigger(int32_t timeoutMS, Callback cb) : _onTimeout(cb), _timeoutMS(timeoutMS) {
    assert(!currentCountdownTrigger); // "Only one instance of CountdownTrigger should exist at a time. ");
    currentCountdownTrigger = this;

    if (timeoutMS <= 0) {
        return;
    }

    _context = std::make_unique<CountdownTriggerContext>();
    _startTime = std::chrono::steady_clock::now();

    auto &action = _context->currAction;
    auto &prev = _context->preAction;
    auto &timer = _context->timer;

    memset(&action, 0, sizeof(action));
    action.sa_sigaction = timer_signal_handler;
    action.sa_flags = SA_SIGINFO;
    sigaction(SIGNAL_VALUE, &action, &prev);

    sigevent sev;
    memset(&sev, 0, sizeof(sev));
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGNAL_VALUE;
    sev.sigev_value.sival_ptr = this;
    timer_create(CLOCK_REALTIME, &sev, &timer);

    struct itimerspec its;
    its.it_value.tv_sec = timeoutMS / 1000;
    its.it_value.tv_nsec = (timeoutMS % 1000) * 1000000;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 0;
    timer_settime(timer, 0, &its, nullptr);
}

CountdownTrigger::~CountdownTrigger() {
    currentCountdownTrigger = nullptr;
    if (!_context) {
        return;
    }
    timer_delete(_context->timer);
    sigaction(SIGNAL_VALUE, &_context->preAction, nullptr);
    if (_callbackFired) {
        inspect();
    }
}

} // namespace cc

#endif