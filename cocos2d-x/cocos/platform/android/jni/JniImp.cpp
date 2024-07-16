/****************************************************************************
 Copyright (c) 2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated engine source code (the "Software"), a limited,
 worldwide, royalty-free, non-assignable, revocable and non-exclusive license
 to use Cocos Creator solely to develop games on your target platforms. You shall
 not use Cocos Creator software for developing other software or tools that's
 used for developing games. You are not granted to publish, distribute,
 sublicense, and/or sell copies of Cocos Creator.

 The software or tools in this License Agreement are licensed, not sold.
 Xiamen Yaji Software Co., Ltd. reserves all rights not expressly granted to you.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "JniImp.h"
#include <algorithm>
#include <array>
#include <cerrno>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <future>
#include <memory>
#include <numeric>
#include <unordered_map>
#include <android/log.h>
#include <android/asset_manager_jni.h>
#include <jni.h>
#include <mutex>
#include <chrono>
#include "JniHelper.h"
#include "platform/CCApplication.h"
#include "scripting/js-bindings/jswrapper/SeApi.h"
#include "scripting/js-bindings/event/EventDispatcher.h"
#include "scripting/js-bindings/manual/jsb_classtype.hpp"
#include "platform/android/CCFileUtils-android.h"
#include "platform/CountdownTrigger.h"
#include "base/CCAutoreleasePool.h"
#include "base/CCGLUtils.h"
#include "storage/local-storage/LocalStorage.h"
#if USE_GFX_RENDERER
#include "renderer/gfx/DeviceGraphics.h"
#endif

// #define _GNU_SOURCE
#include <sys/resource.h>
#include <unistd.h>
#include <cstring>
#include <valarray>

using namespace std::chrono;

#define  JNI_IMP_LOG_TAG    "JniImp"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,JNI_IMP_LOG_TAG,__VA_ARGS__)

#ifndef ORG_RENDER_CLASS_NAME
#define ORG_RENDER_CLASS_NAME org_cocos2dx_lib_Cocos2dxRenderer
#endif
#define JNI_RENDER(FUNC) JNI_METHOD1(ORG_RENDER_CLASS_NAME,FUNC)

#ifndef ORG_ACTIVITY_CLASS_NAME
#define ORG_ACTIVITY_CLASS_NAME org_cocos2dx_lib_Cocos2dxActivity
#endif
#define JNI_ACTIVITY(FUNC) JNI_METHOD1(ORG_ACTIVITY_CLASS_NAME,FUNC)

#ifndef ORG_ACCELEROMETER_CLASS_NAME
#define ORG_ACCELEROMETER_CLASS_NAME org_cocos2dx_lib_Cocos2dxAccelerometer
#endif
#define JNI_ACCELEROMETER(FUNC) JNI_METHOD1(ORG_ACCELEROMETER_CLASS_NAME,FUNC)

#ifndef ORG_HELPER_CLASS_NAME
#define ORG_HELPER_CLASS_NAME org_cocos2dx_lib_Cocos2dxHelper
#endif
#define JNI_HELPER(FUNC) JNI_METHOD1(ORG_HELPER_CLASS_NAME,FUNC)

#ifndef ORG_AUDIOFOCUS_CLASS_NAME
#define ORG_AUDIOFOCUS_CLASS_NAME org_cocos2dx_lib_Cocos2dxAudioFocusManager
#endif
#define JNI_AUDIO(FUNC) JNI_METHOD1(ORG_AUDIOFOCUS_CLASS_NAME,FUNC)

#ifndef JCLS_HELPER
#define JCLS_HELPER "org/cocos2dx/lib/Cocos2dxHelper"
#endif

#ifndef JCLS_RENDERER
#define JCLS_RENDERER "org/cocos2dx/lib/Cocos2dxRenderer"
#endif


#define KEYCODE_BACK 0x04
#define KEYCODE_MENU 0x52
#define KEYCODE_DPAD_UP 0x13
#define KEYCODE_DPAD_DOWN 0x14
#define KEYCODE_DPAD_LEFT 0x15
#define KEYCODE_DPAD_RIGHT 0x16
#define KEYCODE_ENTER 0x42
#define KEYCODE_DPAD_CENTER  0x17

using namespace cocos2d;

extern uint32_t __jsbInvocationCount;
extern void defaultExecutionTimeoutCallback() ;
extern double gCountdownTimeoutMS;
extern "C" void decode_image_init();
extern "C" void decode_image_set_logger(void (*log)(const char *msg));

#define INSPECT_TOUCH_EVENTS 0

namespace
{
#if USE_SYSINFO
    template <size_t N, typename E = int16_t>
    class FrameTimeRecorder {
    public:
        FrameTimeRecorder() {
            std::fill(_data.begin(), _data.end(), 0);
        }

        void record(E frameTime) {
            _data[writePos] = frameTime;
            writePos = (writePos + 1) % N;
            written++;
        }

        inline size_t size() const {
            return std::min((size_t)written, N);
        }

        inline size_t capacity() const { return N; }
        inline size_t mapOffset(size_t idx) const {
            return (writePos + N - idx - 1) % N;
        }

        // index 0 - recent frame
        E operator[](size_t s) const {
            if (s >= size()) return -1;
            return _data[mapOffset(s)];
        }

        void reset() {
            std::fill(_data.begin(), _data.end(), 0);
            writePos = 0;
            written = 0;
        }

        int32_t recentSum(size_t cnt) const {
            if (cnt < 5) {
                int32_t s = 0;
                for (int i = 0; i < cnt; i++) {
                    s += _data[mapOffset(i)];
                }
                return s;
            }
            auto start = mapOffset(cnt - 1);
            auto end = mapOffset(-1);
            assert(start != end);
            if (start > end) {
                // 0 -> end,  start -> [last]
                auto l = std::accumulate(_data.begin(), _data.data() + end, 0);
                auto r = std::accumulate(_data.begin() + start, _data.end(), 0);
                return l + r;
            }
            return std::accumulate(_data.begin() + start, _data.begin() + end, 0);
        }

    private:
        std::array<E, N> _data;
        int32_t writePos{0};
        int32_t written{0};
    };


    class FrameRateMonitor {
    public:
        using OnLowFPSCallback = std::function<void(float,float)>;
        FrameRateMonitor() {
            lastInvokeCallback = high_resolution_clock::now();
        }

        void queryFrameRates(float *output, size_t *frameCount, size_t outputSize) {
            auto querySize = std::min(outputSize, size());
            for (size_t i = 0; i < querySize; i++) {
                auto r = recorder[i];
                output[i] = r == 0 ? -1.0F : 1000.0F / r;
            }
            *frameCount = querySize;
        }
        void queryFrameTimes(int16_t *output, size_t *frameCount, size_t outputSize) {
            auto querySize = std::min(outputSize, size());
            for (size_t i = 0; i < querySize; i++) {
                output[i] = recorder[i];
            }
            *frameCount = querySize;
        }

        void record(int32_t frameTimeMS) {
            assert(frameTimeMS >= 0);
            recorder.record(static_cast<int32_t>(frameTimeMS));
            updateCumulativeFrameTime();
        }

        [[nodiscard]] size_t size() const { return recorder.size(); }

        [[nodiscard]] size_t capacity() const { return recorder.capacity(); }

        void setFrameRateThreshold(float fps) { frameRateThreshold = fps; }
        float getFrameRateThreshold() const { return frameRateThreshold; }
        void setFrameRateMeasurementWindow(int winSize) {
            frameRateMeasurementWindow = std::min(static_cast<int>(recorder.capacity()), winSize);
            if (callback) resetCumulativeFrameTime();
        }
        int getFrameRateMeasurementWindow() const { return frameRateMeasurementWindow; }
        void setFrameRateCallbackIntervalMS(float periodMS) {
            frameRateCallbackIntervalMS = periodMS;
            lastInvokeCallback = high_resolution_clock::now();
        }
        float getFrameRateCallbacKIntervalMs() const { return frameRateCallbackIntervalMS; }
        void setOnLowFPSCallback(OnLowFPSCallback &&cb) {
            callback = std::move(cb);
            resetCumulativeFrameTime();
        }

        float getCumulativeFPS() const {
            if(frameRateMeasurementWindow < 0) return -1.0F;
            int frames = std::min(accumulatedFrames, frameRateMeasurementWindow);
            int acc = recorder.recentSum(frames);
            return  static_cast<float>(1000.0 * frames / (acc == 0 ? 16.6F * frames : acc));
        }

        void reset() {
            callback = nullptr;
            recorder.reset();
            accumulatedFrames =0;
            lastInvokeCallback = high_resolution_clock::now();
        }

    private:
        void updateCumulativeFrameTime() {
            if (!callback || frameRateMeasurementWindow < 0) return;

            accumulatedFrames ++;
            float accFPS = getCumulativeFPS();
            if (accFPS < frameRateThreshold && canTriggerCallback()) {
                callback(accFPS, frameRateThreshold);
                lastInvokeCallback = high_resolution_clock::now();
            }
        }
        void resetCumulativeFrameTime() {
            accumulatedFrames = 0;
        }
        bool canTriggerCallback() const {
            auto now = high_resolution_clock::now();
            auto pastMS = duration_cast<milliseconds>(now - lastInvokeCallback).count();
            return frameRateCallbackIntervalMS > 0 &&  pastMS >= frameRateCallbackIntervalMS;
        }

        FrameTimeRecorder<128, int16_t> recorder;
        int32_t accumulatedFrames{0};
        float frameRateThreshold{0.0F};
        int frameRateMeasurementWindow{-1};
        float frameRateCallbackIntervalMS{0};
        time_point<high_resolution_clock> lastInvokeCallback;
        OnLowFPSCallback callback{nullptr};
    };

#endif
    struct AppContext {
        bool isOpenDebugView = false;
        bool isGLOptModeEnabled = true;
        std::string apkPath;
        EditTextCallback editTextCallback = nullptr;
        void *ctx = nullptr;
        int deviceSampleRate = 44100;
        int deviceAudioBufferSizeInFrames = 192;
        int width = 0;
        int height = 0;
        bool isStarted = false;
        bool isGameFinished = false;
        int SDKInt = 0;
        cocos2d::Application* application = nullptr;
#if USE_SYSINFO
        FrameRateMonitor framerateMonitor;
#endif
        std::vector<std::function<void()>> touchEventQueue;
        std::mutex touchQueueMtx;
    };

    std::unique_ptr<AppContext> appCtx;

    bool setCanvasCallback(se::ScriptEngine *inst, se::Object *ns )
    {
        se::AutoHandleScope scope(inst);
        char commandBuf[200] = {0};
        uint8_t devicePixelRatio = Application::getInstance()->getDevicePixelRatio();
        sprintf(commandBuf, "window.innerWidth = %d; window.innerHeight = %d;",
                appCtx->width / devicePixelRatio,
                appCtx->height / devicePixelRatio);
        inst->evalString(commandBuf);
        glViewport(0, 0, appCtx->width / devicePixelRatio, appCtx->height / devicePixelRatio);
        glDepthMask(GL_TRUE);
        
        return true;
    }

    inline std::vector<std::function<void()>> & currentTouchEventQueue() {
        return appCtx->touchEventQueue;
    }

    void flushTouchEventQueue() {
        std::unique_lock<std::mutex> guard(appCtx->touchQueueMtx);
        auto &currentQueue = currentTouchEventQueue();
        if(currentQueue.empty()) return;
        std::vector<std::function<void()>> tmpQueue;
        std::swap(tmpQueue, currentQueue);
        guard.unlock();
        for(auto & fn : tmpQueue) {
            fn();
        }
    }

    void sys_printf(const char *msg){
        CCLOG("[hyper_pix] %s", msg);
    }

}

void cocos_jni_env_init (JNIEnv* env);

Application* cocos_android_app_init(JNIEnv* env, int width, int height);

extern "C"
{
    void getSDKInt(JNIEnv* env)
    {
        if (env && appCtx->SDKInt == 0)
        {
            // VERSION is a nested class within android.os.Build (hence "$" rather than "/")
            jclass versionClass = env->FindClass("android/os/Build$VERSION");
            if (NULL == versionClass)
                return;

            jfieldID sdkIntFieldID = env->GetStaticFieldID(versionClass, "SDK_INT", "I");
            if (NULL == sdkIntFieldID)
                return;

            appCtx->SDKInt = env->GetStaticIntField(versionClass, sdkIntFieldID);
        }
    }

    JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
    {
        appCtx = std::make_unique<AppContext>();
        JniHelper::setJavaVM(vm);
        cocos_jni_env_init(JniHelper::getEnv());
        decode_image_init();
#if COCOS2D_DEBUG > 0
        decode_image_set_logger(sys_printf);
#endif
        getSDKInt(JniHelper::getEnv());
#if ENABLE_EXECUTION_TIMEOUT_TRIGGER
        hsext::CountdownTrigger::init();
#endif
        return JNI_VERSION_1_4;
    }

    /*****************************************************
     * Cocos2dxActivity native functions implementation.
     *****************************************************/

    JNIEXPORT jintArray JNICALL JNI_ACTIVITY(getGLContextAttrs)(JNIEnv*  env, jclass thiz)
    {
        //REFINE
        int tmp[7] = {8, 8, 8,
                      8, 0, 0, 0};
        jintArray glContextAttrsJava = env->NewIntArray(7);
        env->SetIntArrayRegion(glContextAttrsJava, 0, 7, tmp);

        return glContextAttrsJava;
    }

	/*****************************************************
	 * Cocos2dxRenderer native functions implementation.
	 *****************************************************/
    JNIEXPORT void JNICALL JNI_RENDER(nativeInit)(JNIEnv*  env, jclass thiz, jint w, jint h, jstring jDefaultResourcePath)
    {
        appCtx->width = w;
        appCtx->height = h;
        
        appCtx->application = cocos_android_app_init(env, w, h);

        appCtx->isGameFinished = false;
        ccInvalidateStateCache();
        std::string defaultResourcePath = JniHelper::jstring2string(jDefaultResourcePath);
        LOGD("nativeInit: %d, %d, %s", w, h, defaultResourcePath.c_str());
        

        if (!defaultResourcePath.empty())
            FileUtils::getInstance()->setDefaultResourceRootPath(defaultResourcePath);

        se::ScriptEngine* se = cocos2d::Application::getInstance()->getScriptEngine();
        se->addRegisterCallback(setCanvasCallback);

        se->getTimer()->addIdleTask([se](){
            se->checkTask();
        }, "worker.idle");

        EventDispatcher::init();

        appCtx->application->start();
        appCtx->isStarted = true;
    }

	JNIEXPORT void JNICALL JNI_RENDER(nativeRender)(JNIEnv* env, jclass clazz)
	{
        if (appCtx->isGameFinished)
        {
            // with Application destructor called, native resource will be released
            delete appCtx->application;
            appCtx->application = nullptr;
            localStorageCacheSync();
            JniHelper::callStaticVoidMethod(JCLS_HELPER, "endApplication");
            return;
        }

        auto *app = appCtx->application;

        if (!appCtx->isStarted)
        {
            app->clearTasks();

            se::WebWorker::stopAll();

            app->getScriptEngine()->cleanup();
            cocos2d::PoolManager::getInstance()->getCurrentPool()->clear();

            //REFINE: Wait HttpClient, WebSocket, Audio thread to exit

            ccInvalidateStateCache();
          
            se::ScriptEngine* se = app->getScriptEngine();
            se->addRegisterCallback(setCanvasCallback);

            se->getTimer()->addIdleTask([se](){
                se->checkTask();
            }, "worker.idle");

            EventDispatcher::init();

            if(!app->applicationDidFinishLaunching())
            {
                appCtx->isGameFinished = true;
                return;
            }

            appCtx->isStarted = true;
        }

        static steady_clock::time_point prevTime = std::chrono::high_resolution_clock::now();
        static steady_clock::time_point now;
        static float dt = 0.f;
        static float dtSum = 0.f;
        static uint32_t jsbInvocationTotalCount = 0;
        static uint32_t jsbInvocationTotalFrames = 0;
        bool downsampleEnabled = app->isDownsampleEnabled();

        #if PT_ENABLE_JSB_PERF
        JSBFnPerf::reset();
        #endif

#if ENABLE_EXECUTION_TIMEOUT_TRIGGER
        hsext::CountdownTrigger executionTimeout((int)gCountdownTimeoutMS, defaultExecutionTimeoutCallback);
#endif

        app->flushTick();

        app->getTimer()->setState("nativeRender.before");

        if (downsampleEnabled)
            app->getRenderTexture()->prepare();

        app->update();

        flushTouchEventQueue();

        app->getTimer()->setState("tick.before");
        EventDispatcher::dispatchTickEvent(dt);
        app->getTimer()->setState("tick.after");

        if (downsampleEnabled)
            app->getRenderTexture()->draw();

        PoolManager::getInstance()->getCurrentPool()->clear();

        localStorageCacheSync();

        now = steady_clock::now();
        auto stdDt = now-prevTime; 
        dt = duration_cast<microseconds>(stdDt).count() / 1000000.f;

        prevTime = steady_clock::now();

#if USE_SYSINFO
        appCtx->framerateMonitor.record(duration_cast<milliseconds>(stdDt).count());
#endif

        if (appCtx->isOpenDebugView)
        {
            dtSum += dt;
            ++jsbInvocationTotalFrames;
            jsbInvocationTotalCount += __jsbInvocationCount;

            if (dtSum > 1.0f)
            {
                dtSum = 0.0f;
                setJSBInvocationCountJNI(jsbInvocationTotalCount / jsbInvocationTotalFrames);
                jsbInvocationTotalCount = 0;
                jsbInvocationTotalFrames = 0;
            }
        }
        

        __jsbInvocationCount = 0;
        #if PT_ENABLE_JSB_PERF
        JSBFnPerf::inspect();
        #endif
        app->getTimer()->setState("nativeRender.end");
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeOnPause)(JNIEnv *env, jclass clazz)
    {

        localStorageCacheSync();

        if (appCtx->isGameFinished) {
            return;
        }
        if (appCtx->application)
            appCtx->application->onPause();
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeOnResume)(JNIEnv *env, jclass clazz)
    {
        if (appCtx->isGameFinished) {
            return;
        }
        if (appCtx->application)
            appCtx->application->onResume();
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeInsertText)(JNIEnv* env, jclass thiz, jstring text)
    {
        //REFINE
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeDeleteBackward)(JNIEnv* env, jclass thiz)
    {
        //REFINE
    }

    JNIEXPORT jstring JNICALL JNI_RENDER(nativeGetContentText)(JNIEnv *env, jclass clazz)
    {
        //REFINE
        return nullptr;
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeOnSurfaceChanged)(JNIEnv*  env, jclass thiz, jint w, jint h)
    {
        //REFINE
    }

    /***********************************************************
	 * Cocos2dxAccelerometer native functions implementation.
	 ***********************************************************/

    JNIEXPORT void JNICALL JNI_ACCELEROMETER(onSensorChanged)(JNIEnv*  env, jclass thiz, jfloat x, jfloat y, jfloat z, jlong timeStamp)
    {
        //REFINE
    }

    /***********************************************************
	 * Touches native functions implementation.
	 ***********************************************************/

    static void dispatchTouchEventWithOnePoint(JNIEnv* env, cocos2d::TouchEvent::Type type, jint id, jfloat x, jfloat y)
    {
        if (appCtx->isGameFinished) {
            return;
        }
        cocos2d::TouchEvent touchEvent;
        touchEvent.type = type;

        uint8_t devicePixelRatio = Application::getInstance()->getDevicePixelRatio();
        cocos2d::TouchInfo touchInfo;
        touchInfo.index = id;
        touchInfo.x = x / devicePixelRatio;
        touchInfo.y = y / devicePixelRatio;
        touchEvent.touches.push_back(touchInfo);
        
        cocos2d::EventDispatcher::dispatchTouchEvent(touchEvent);
    }

    static void dispatchTouchEventWithPoints(JNIEnv* env, cocos2d::TouchEvent::Type type, jintArray ids, jfloatArray xs, jfloatArray ys)
    {
        if (appCtx->isGameFinished) {
            return;
        }
        cocos2d::TouchEvent touchEvent;
        touchEvent.type = type;

        int size = env->GetArrayLength(ids);
        jint id[size];
        jfloat x[size];
        jfloat y[size];

        env->GetIntArrayRegion(ids, 0, size, id);
        env->GetFloatArrayRegion(xs, 0, size, x);
        env->GetFloatArrayRegion(ys, 0, size, y);

        uint8_t devicePixelRatio = Application::getInstance()->getDevicePixelRatio();
        for(int i = 0; i < size; i++)
        {
            cocos2d::TouchInfo touchInfo;
            touchInfo.index = id[i];
            touchInfo.x = x[i] / devicePixelRatio;
            touchInfo.y = y[i] / devicePixelRatio;
            touchEvent.touches.push_back(touchInfo);
        }

        cocos2d::EventDispatcher::dispatchTouchEvent(touchEvent);
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeTouchesBegin)(JNIEnv * env, jclass thiz, jint id, jfloat x, jfloat y)
    {
        if (appCtx->isGameFinished) {
            return;
        }
        dispatchTouchEventWithOnePoint(env, cocos2d::TouchEvent::Type::BEGAN, id, x, y);
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeTouchesEnd)(JNIEnv * env, jclass thiz, jint id, jfloat x, jfloat y)
    {
        if (appCtx->isGameFinished) {
            return;
        }
        dispatchTouchEventWithOnePoint(env, cocos2d::TouchEvent::Type::ENDED, id, x, y);
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeTouchesMove)(JNIEnv * env, jclass thiz, jintArray ids, jfloatArray xs, jfloatArray ys)
    {
        if (appCtx->isGameFinished) {
            return;
        }
        dispatchTouchEventWithPoints(env, cocos2d::TouchEvent::Type::MOVED, ids, xs, ys);
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeTouchesCancel)(JNIEnv * env, jclass thiz, jintArray ids, jfloatArray xs, jfloatArray ys)
    {
        if (appCtx->isGameFinished) {
            return;
        }
        dispatchTouchEventWithPoints(env, cocos2d::TouchEvent::Type::CANCELLED, ids, xs, ys);
    }
   //////////////////////////////////////////////////////////////////////////////////////////
   //////////////////////////////  insert queue version of touch events  ////////////////////

    JNIEXPORT void JNICALL JNI_RENDER(nativeTouchesBeginQueue)(JNIEnv * env, jclass thiz, jint id, jfloat x, jfloat y)
    {
        if (appCtx->isGameFinished) {
            return;
        }
        std::lock_guard<std::mutex> guard(appCtx->touchQueueMtx);
        currentTouchEventQueue().emplace_back([id, x, y](){
            dispatchTouchEventWithOnePoint(JniHelper::getEnv(), cocos2d::TouchEvent::Type::BEGAN, id, x, y);
        });
        appCtx->application->dispatchTask([](){flushTouchEventQueue();},
        #if INSPECT_TOUCH_EVENTS
         "touch.flush-begin"
        #else
         ""
        #endif
        );
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeTouchesEndQueue)(JNIEnv * env, jclass thiz, jint id, jfloat x, jfloat y)
    {
        if (appCtx->isGameFinished) {
            return;
        }
        std::lock_guard<std::mutex> guard(appCtx->touchQueueMtx);
        currentTouchEventQueue().emplace_back([id, x, y]() {
            dispatchTouchEventWithOnePoint(JniHelper::getEnv(), cocos2d::TouchEvent::Type::ENDED, id, x, y);
        });
        appCtx->application->dispatchTask([](){flushTouchEventQueue();}, 
        #if INSPECT_TOUCH_EVENTS
        "touch.flush-end"
        #else
        ""
        #endif
        );
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeTouchesMoveQueue)(JNIEnv * env, jclass thiz, jintArray ids, jfloatArray xs, jfloatArray ys)
    {
        if (appCtx->isGameFinished) {
            return;
        }
        std::lock_guard<std::mutex> guard(appCtx->touchQueueMtx);
        assert(ids);
        assert(xs);
        assert(ys);
        auto ids_g = (jintArray) env->NewGlobalRef(ids);
        auto xs_g = (jfloatArray) env->NewGlobalRef(xs);
        auto ys_g = (jfloatArray) env->NewGlobalRef(ys);
        currentTouchEventQueue().emplace_back([ids_g, xs_g, ys_g]() {
            auto *env = JniHelper::getEnv();
            dispatchTouchEventWithPoints(JniHelper::getEnv(), cocos2d::TouchEvent::Type::MOVED, ids_g, xs_g, ys_g);
            env->DeleteGlobalRef(ids_g);
            env->DeleteGlobalRef(xs_g);
            env->DeleteGlobalRef(ys_g);
        });
        appCtx->application->dispatchTask([](){flushTouchEventQueue();}, 
        #if INSPECT_TOUCH_EVENTS
        "touch.flush-move"
        #else
        ""
        #endif
        );
    }


    JNIEXPORT void JNICALL JNI_RENDER(nativeTouchesCancelQueue)(JNIEnv * env, jclass thiz, jintArray ids, jfloatArray xs, jfloatArray ys)
    {
        if (appCtx->isGameFinished) {
            return;
        }
        auto ids_g = (jintArray) env->NewGlobalRef(ids);
        auto xs_g = (jfloatArray) env->NewGlobalRef(xs);
        auto ys_g = (jfloatArray) env->NewGlobalRef(ys);
        std::lock_guard<std::mutex> guard(appCtx->touchQueueMtx);
        currentTouchEventQueue().emplace_back([ids_g, xs_g, ys_g]() {
            auto *env = JniHelper::getEnv();
            dispatchTouchEventWithPoints(env, cocos2d::TouchEvent::Type::CANCELLED, ids_g, xs_g, ys_g);
            env->DeleteGlobalRef(ids_g);
            env->DeleteGlobalRef(xs_g);
            env->DeleteGlobalRef(ys_g);
        });
        appCtx->application->dispatchTask([](){flushTouchEventQueue();}, 
        #if INSPECT_TOUCH_EVENTS
            "touch.flush-cancel"
        #else
         ""
        #endif
        );
    }
    ////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////key events ////////////////////////////////////

    JNIEXPORT jboolean JNICALL JNI_RENDER(nativeKeyEvent)(JNIEnv * env, jclass thiz, jint keyCode, jboolean isPressed)
    {
        if (appCtx->isGameFinished) {
            return JNI_TRUE;
        }

        int keyInWeb = -1;
        // key values in web, refer to http://docs.cocos.com/creator/api/en/enums/KEY.html
        switch(keyCode)
        {
            case KEYCODE_BACK:
                keyInWeb = 6;
                break;
            case KEYCODE_ENTER:
                keyInWeb = 13;
                break;
            case KEYCODE_MENU:
                keyInWeb = 18;
                break;
            case KEYCODE_DPAD_UP:
                keyInWeb = 1003;
                break;
            case KEYCODE_DPAD_DOWN:
                keyInWeb = 1004;
                break;
            case KEYCODE_DPAD_LEFT:
                keyInWeb = 1000;
                break;
            case KEYCODE_DPAD_RIGHT:
                keyInWeb = 1001;
                break;
            case KEYCODE_DPAD_CENTER:
                keyInWeb = 1005;
                break;
            default:
                keyInWeb = 0; // If the key can't be identified, this value is 0
        }
        KeyboardEvent event;
        event.key = keyInWeb;
        event.action = isPressed ? KeyboardEvent::Action::PRESS : KeyboardEvent::Action::RELEASE;
        EventDispatcher::dispatchKeyboardEvent(event);

        return JNI_TRUE;
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeWait)(JNIEnv * env, jobject thiz, jlong waitMS) {
        appCtx->application->waitFor(waitMS);
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeNotify)(JNIEnv * env, jobject thiz) {
        appCtx->application->getTimer()->requestInterrupt();
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeLoopExit)(JNIEnv * env, jobject thiz) {
        if(appCtx) {
            localStorageCacheSync();
            cocos2d::PoolManager::getInstance()->getCurrentPool()->clear();
            ccInvalidateStateCache();
            if(appCtx->application) {
                delete appCtx->application;
            }
#if USE_GFX_RENDERER
            cocos2d::renderer::DeviceGraphics::destroy();
#endif
            appCtx.reset();
            appCtx = std::make_unique<AppContext>();
        }
    }
/***********************************************************
 * Cocos2dxHelper native functions implementation.
 ***********************************************************/

    JNIEXPORT void JNICALL JNI_HELPER(nativeSetApkPath)(JNIEnv* env, jclass thiz, jstring apkPath)
    {
        appCtx->apkPath = JniHelper::jstring2string(apkPath);
    }

    JNIEXPORT void JNICALL JNI_HELPER(nativeSetContext)(JNIEnv*  env, jclass thiz, jobject context, jobject assetManager)
    {
        JniHelper::setClassLoaderFrom(context);
        FileUtilsAndroid::setassetmanager(AAssetManager_fromJava(env, assetManager));
    }

    JNIEXPORT void JNICALL JNI_HELPER(nativeSetAudioDeviceInfo)(JNIEnv*  env, jclass thiz, jboolean isSupportLowLatency, jint deviceSampleRate, jint deviceAudioBufferSizeInFrames)
    {
        appCtx->deviceSampleRate = deviceSampleRate;
        appCtx->deviceAudioBufferSizeInFrames = deviceAudioBufferSizeInFrames;
        LOGD("nativeSetAudioDeviceInfo: sampleRate: %d, bufferSizeInFrames: %d", appCtx->deviceSampleRate, appCtx->deviceAudioBufferSizeInFrames);
    }

    JNIEXPORT void JNICALL JNI_HELPER(nativeSetEditTextDialogResult)(JNIEnv* env, jclass obj, jbyteArray text)
    {
        jsize  size = env->GetArrayLength(text);

        if (size > 0) 
        {
            jbyte * data = (jbyte*)env->GetByteArrayElements(text, 0);
            char* buffer = (char*)malloc(size+1);
            if (buffer != nullptr) 
            {
                memcpy(buffer, data, size);
                buffer[size] = '\0';
                // pass data to edittext's delegate
                if (appCtx->editTextCallback)
                    appCtx->editTextCallback(buffer, appCtx->ctx);
                free(buffer);
            }
            env->ReleaseByteArrayElements(text, data, 0);
        } 
        else 
        {
            if (appCtx->editTextCallback)
                appCtx->editTextCallback("", appCtx->ctx);
        }
    }

    /***********************************************************
     * Cocos2dxAudioFocusManager native functions implementation.
     ***********************************************************/

    JNIEXPORT void JNICALL JNI_AUDIO(nativeOnAudioFocusChange)(JNIEnv* env, jclass thiz, jint focusChange)
    {
        // cocos_audioengine_focus_change(focusChange);
    }
} // end of extern "C"

void restartJSVM()
{
    appCtx->isStarted = false;
}

/***********************************************************
 * Functions invoke from cpp to Java.
 ***********************************************************/

std::string getApkPathJNI() 
{
    return appCtx->apkPath;
}

std::string getPackageNameJNI() 
{
    return JniHelper::callStaticStringMethod(JCLS_HELPER, "getPackageName");
}

int getObbAssetFileDescriptorJNI(const std::string& path, long* startOffset, long* size) 
{
    JniMethodInfo methodInfo;
    int fd = 0;
    
    if (JniHelper::getStaticMethodInfo(methodInfo, JCLS_HELPER, "getObbAssetFileDescriptor", "(Ljava/lang/String;)[J"))
    {
        jstring stringArg = methodInfo.env->NewStringUTF(path.c_str());
        jlongArray newArray = (jlongArray)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID, stringArg);
        jsize theArrayLen = methodInfo.env->GetArrayLength(newArray);
        
        if (3 == theArrayLen) 
        {
            jboolean copy = JNI_FALSE;
            jlong *array = methodInfo.env->GetLongArrayElements(newArray, &copy);
            fd = static_cast<int>(array[0]);
            *startOffset = array[1];
            *size = array[2];
            methodInfo.env->ReleaseLongArrayElements(newArray, array, 0);
        }
        
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        methodInfo.env->DeleteLocalRef(stringArg);
    }
    
    return fd;
}

int getDeviceSampleRateJNI()
{
    return appCtx->deviceSampleRate;
}

int getDeviceAudioBufferSizeInFramesJNI()
{
    return appCtx->deviceAudioBufferSizeInFrames;
}

void convertEncodingJNI(const std::string& src, int byteSize, const std::string& fromCharset, std::string& dst, const std::string& newCharset)
{
    JniMethodInfo methodInfo;

    if (JniHelper::getStaticMethodInfo(methodInfo, JCLS_HELPER, "conversionEncoding", "([BLjava/lang/String;Ljava/lang/String;)[B"))
    {
        jbyteArray strArray = methodInfo.env->NewByteArray(byteSize);
        methodInfo.env->SetByteArrayRegion(strArray, 0, byteSize, reinterpret_cast<const jbyte*>(src.c_str()));

        jstring stringArg1 = methodInfo.env->NewStringUTF(fromCharset.c_str());
        jstring stringArg2 = methodInfo.env->NewStringUTF(newCharset.c_str());

        jbyteArray newArray = (jbyteArray)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID, strArray, stringArg1, stringArg2);
        jsize theArrayLen = methodInfo.env->GetArrayLength(newArray);
        methodInfo.env->GetByteArrayRegion(newArray, 0, theArrayLen, (jbyte*)dst.c_str());

        methodInfo.env->DeleteLocalRef(strArray);
        methodInfo.env->DeleteLocalRef(stringArg1);
        methodInfo.env->DeleteLocalRef(stringArg2);
        methodInfo.env->DeleteLocalRef(newArray);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

std::string getCurrentLanguageJNI()
{
    return JniHelper::callStaticStringMethod(JCLS_HELPER, "getCurrentLanguage");
}

std::string getCurrentLanguageCodeJNI()
{
    return JniHelper::callStaticStringMethod(JCLS_HELPER, "getCurrentLanguageCode");
}

std::string getSystemVersionJNI()
{
    return JniHelper::callStaticStringMethod(JCLS_HELPER, "getSystemVersion");
}

bool openURLJNI(const std::string& url)
{
    return JniHelper::callStaticBooleanMethod(JCLS_HELPER, "openURL", url);
}

void copyTextToClipboardJNI(const std::string& text)
{
    JniHelper::callStaticVoidMethod(JCLS_HELPER, "copyTextToClipboard", text);
}

void setPreferredFramesPerSecondJNI(int fps)
{
    JniHelper::callStaticVoidMethod(JCLS_RENDERER, "setPreferredFramesPerSecond", fps);
}

void setGameInfoDebugViewTextJNI(int index, const std::string& text)
{
    if (!appCtx->isOpenDebugView)
        return;
    JniHelper::callStaticVoidMethod(JCLS_HELPER, "setGameInfoDebugViewText", index, text);
}

void setJSBInvocationCountJNI(int count)
{
    if (!appCtx->isOpenDebugView)
        return;
    JniHelper::callStaticVoidMethod(JCLS_HELPER, "setJSBInvocationCount", count);
}

void openDebugViewJNI()
{
    if (!appCtx->isOpenDebugView)
    {
        LOGD("openDebugViewJNI ...");
        appCtx->isOpenDebugView = true;
        JniHelper::callStaticVoidMethod(JCLS_HELPER, "openDebugView");
        if (!appCtx->isGLOptModeEnabled)
        {
            JniHelper::callStaticVoidMethod(JCLS_HELPER, "disableBatchGLCommandsToNative");
        }
    }
}

void disableBatchGLCommandsToNativeJNI()
{
    appCtx->isGLOptModeEnabled = false;
    if (appCtx->isOpenDebugView)
    {
        JniHelper::callStaticVoidMethod(JCLS_HELPER, "disableBatchGLCommandsToNative");
    }
}

void exitApplication()
{
    appCtx->isGameFinished = true;
}


bool getApplicationExited()
{
    return appCtx->isGameFinished;
}

int getAndroidSDKInt()
{
    return appCtx->SDKInt;
}

namespace hsext {

    void setEnableIdleFrameRateAdjustmentJNI(bool enable) {
        JniHelper::callStaticVoidMethod(JCLS_RENDERER, "setEnableIdleFrameRateAdjustment", enable);
    }

    bool getEnableIdleFrameRateAdjustmentJNI() {
        return JniHelper::callStaticBooleanMethod(JCLS_RENDERER, "getEnableIdleFrameRateAdjustment");
    }

    void setIdleFrameRateJNI(float fps) {
        JniHelper::callStaticVoidMethod(JCLS_RENDERER, "setIdleFrameRate", fps);
    }

    float getIdleFrameRateJNI() {
        return JniHelper::callStaticFloatMethod(JCLS_RENDERER, "getIdleFrameRate");
    }

    void setIdleFramesJNI(int frames) {
        JniHelper::callStaticVoidMethod(JCLS_RENDERER, "setIdleFrames", frames);
    }

    int getIdleFramesJNI() {
        return JniHelper::callStaticIntMethod(JCLS_RENDERER, "getIdleFrames");
    }

#if USE_SYSINFO
    void setFrameRateThreshold(float frameRate) {
        appCtx->framerateMonitor.setFrameRateThreshold(frameRate);
    }
    float getFrameRateThreshold(){
        return appCtx->framerateMonitor.getFrameRateThreshold();
    }
    void setFrameRateMeasurementWindow(int32_t windowSize) {
        appCtx->framerateMonitor.setFrameRateMeasurementWindow(windowSize);
    }
    int32_t getFrameRateMeasurementWindow() {
        return appCtx->framerateMonitor.getFrameRateMeasurementWindow();
    }
    void setFrameRateCallbackInterval(float periodMS) {
        appCtx->framerateMonitor.setFrameRateCallbackIntervalMS(periodMS);
    }
    float getFrameRateCallbackInterval() {
        return appCtx->framerateMonitor.getFrameRateCallbacKIntervalMs();
    }
    void getFrameTimeList(int16_t *list, size_t *outSize, size_t listSize){
        return appCtx->framerateMonitor.queryFrameTimes(list, outSize, listSize);
    }

    void setOnLowFrameRate(std::function<void(float, float)> && callback) {
        appCtx->framerateMonitor.setOnLowFPSCallback(std::move(callback));
    }

    void resetFrameRate() {
        appCtx->framerateMonitor.reset();
    }
#endif
}

#if USE_SYSINFO

namespace hsext {
namespace {
std::string_view trim(std::string_view line) {
    while (line[0] == ' ' || line[0] == '\t') {
        line.remove_prefix(1);
    }
    while (line.back() == ' ' || line.back() == '\t' || line.back() == '\n') {
        line.remove_suffix(1);
    }
    return line;
}
struct MemInfo {
    int32_t memTotal{0};
    int32_t memFree{0};
    int32_t memAvailable{-1};
    int32_t memBuffers{0};
    int32_t memCached{0};

    int32_t calcAvaiable() const {
        if(memAvailable == -1) {
            return memBuffers + memFree + memCached;
        }
        return memAvailable;
    }
};

struct CpuTicks {
    uint64_t user0;
    uint64_t nice1;
    uint64_t system2;
    uint64_t idle3;
    uint64_t iowait4;
    uint64_t total;
};

struct ProcStat {
    int32_t pid{0};
    std::string comm;
    char state[2] = {0};
    uint64_t utime{0};
    uint64_t stime{0};  // kernel mode
    uint64_t cutime{0}; // children user mode
    uint64_t cstime{0}; // children kernel mode
    uint64_t rss{0}; // Resident Set Size: number of pages the process has in real memory.
    int num_threads{0};
};

std::ostream &operator<<(std::ostream &out, const MemInfo &info) {
    out << "MemInfo {.memTotal = " << info.memTotal << 
    ", .memFree = " << info.memFree << 
    ", .memAvailable = " << info.memAvailable << 
    ", .memBuffers = " << info.memBuffers << 
    ", .memCached = " << info.memCached << 
    "}";
    return out;
}
std::ostream &operator<<(std::ostream &out, const CpuTicks &info) {
    out << "CpuTicks {.user = " << info.user0 << ", "
        << ".nice = " << info.nice1 << ", "
        << ".system = " << info.system2 << ", "
        << ".idle = " << info.idle3 << ", "
        << ".iowait = " << info.iowait4 << ", "
        << ".total = " << info.total << "}";
    return out;
}

std::ostream &operator<<(std::ostream &out, const ProcStat &info) {
    out << "ProcInfo {.pid  = " << info.pid << ", "
        << ".comm = " << info.comm.c_str() << ","
        << ".state = " << info.state << ","
        << ".utime = " << info.utime << ","
        << ".stime = " << info.stime << ","
        << ".cutime = " << info.cutime << ","
        << ".cstime = " << info.cstime << ","
        << ".num_threads = " << info.num_threads << "}";
    return out;
}

MemInfo readMemInfo() {
    MemInfo ret;
    FILE *fp = fopen("/proc/meminfo", "rt");
    if (!fp) {
        printf("faild to open /proc/meminfo: %s", strerror(errno));
        return ret;
    }
    char buffer[256] = {0};
    while (fgets(buffer, 256, fp)) {
        std::string_view line = buffer;
        // std::cout <<" [getline] " << line << ": " << line.substr(0, 14) << "|" << std::endl;
        if (line.substr(0, 9) == "MemTotal:") {
            line = trim(line.substr(9));
            sscanf(line.data(), "%d kB", &ret.memTotal);
        } else if (line.substr(0, 8) == "MemFree:") {
            line = trim(line.substr(8));
            sscanf(line.data(), "%d kB", &ret.memFree);
        } else if (line.substr(0, 13) == "MemAvailable:") {
            line = trim(line.substr(13));
            sscanf(line.data(), "%d kB", &ret.memAvailable);
        } else if (line.substr(0, 7) == "Cached:") {
            line = trim(line.substr(7));
            sscanf(line.data(), "%d kB", &ret.memCached);
        } else if (line.substr(0, 8) == "Buffers:") {
            line = trim(line.substr(8));
            sscanf(line.data(), "%d kB", &ret.memBuffers);
        }

        memset(buffer, 0, 256);
    }

    if (fp) {
        fclose(fp);
    }
    return ret;
}

CpuTicks readProcStatPUTicks(bool &ok) {
    static bool stopReading = false;
    CpuTicks ret{};
    if(stopReading) {
        ok = false;
        return ret;
    }
    FILE *fp = fopen("/proc/stat", "rt");
    if (!fp) {
        printf("faild to open /proc/stat: %s", strerror(errno));
        ok = false;
        stopReading = true;
        return ret;
    }
    ok = true;

    auto *buff = reinterpret_cast<char *>(calloc(1, 1024));
    fgets(buff, 1023, fp);
    std::string_view line = buff;
    std::vector<uint64_t> numbers;
    assert(line.substr(0, 3) == "cpu");
    line.remove_prefix(4);
    char *end;
    uint64_t total = 0;
    while (!line.empty()) {
        uint64_t num = strtoull(line.data(), &end, 10);
        if (errno == ERANGE || end == line.data()) {
            break;
        }
        numbers.emplace_back(num);
        line.remove_prefix(end - line.data());
        total += num;
    }
    free(buff);
    if (numbers.size() > 4) {
        ret.user0 = numbers[0];
        ret.nice1 = numbers[1];
        ret.system2 = numbers[2];
        ret.idle3 = numbers[3];
        ret.iowait4 = numbers[4];
        ret.total = total;
    } else {
        ok = false;
    }

    if (fp) {
        fclose(fp);
    }
    return ret;
}


ProcStat readProcInfo() {
    ProcStat ret;
    char statPath[256] = {0};
    snprintf(statPath, 255, "/proc/%d/stat", getpid());
    FILE *fp = fopen(statPath, "rt");
    if (!fp) {
        printf("faild to open %s: %s", statPath, strerror(errno));
        return ret;
    }

    int pid;
    char comm[256] = {0};
    char state[3] = {0};
    int ppid, pgrp, session, tty_nr, tpgid, flags;     // NOLINT
    int minflt, cminflt, majflt, cmajflt;       // NOLINT
    unsigned long utime, stime, cutime, cstime; // NOLINT
    unsigned long priority, nice, num_threads;  // NOLINT
    long itrealvalue;
    unsigned long long starttime;
    unsigned long vsize;
    long rss;
    memset(statPath, 0, sizeof(statPath));
    fgets(statPath, 255, fp);
    int rcnt = sscanf(statPath,
                      "%d %s %s %d "
                      "%d %d %d %d %d "
                      "%d %d %d %d "
                      "%lu %lu %ld %ld "
                      "%ld %ld %ld "
                      "%ld %llu %lu %ld " ,
                      &pid, comm, state, &ppid,
                      &pgrp, &session, &tty_nr, &tpgid, &flags,
                      &minflt, &cminflt, &majflt, &cmajflt,
                      &utime, &stime, &cutime, &cstime,
                      &priority, &nice, &num_threads,
                      &itrealvalue, &starttime, &vsize, &rss);
    if(rcnt != 24) {
        SE_LOGE("sscanf failed with %d values, <%s>", rcnt, statPath);
        assert(false);
    }

    ret.pid = pid;
    ret.comm = comm;
    ret.state[0] = state[0];
    ret.utime = utime;
    ret.stime = stime;
    ret.cstime = cstime;
    ret.cutime = cutime;
    ret.rss = rss * getpagesize() / 1024; // in kB
    ret.num_threads = static_cast<int>(num_threads);

    if (fp) {
        fclose(fp);
    }
    return ret;
}
} // namespace

bool getProcessInfo(int ms, std::function<void(ProcessInfo*)> &&callback) {
    static std::atomic_bool sRunning{false};
    bool running = false;
    if(!sRunning.compare_exchange_strong(running, true)) {
        return false;
    }
    std::atomic_bool *ptrRunning = &sRunning;
    // In the Cocos engine, there is no global thread pool, and creating individual threads is
    // not a good practice. Considering that game threads are not stable enough, a separate thread
    // is used here.
    std::thread queryThread([ms, ptrRunning, callback = std::move(callback)]() {
        auto memInfo = readMemInfo();
        bool procStatOk = false;
        bool procStatOkAfter = false;
        auto cpuTicksBefore = readProcStatPUTicks(procStatOk);
        auto procStatBefore = readProcInfo();
        auto beforeSleep = high_resolution_clock::now();
        // delay for some time
        std::this_thread::sleep_for(milliseconds(ms));
        auto cpuTicksAfter = readProcStatPUTicks(procStatOkAfter);
        auto procStatAfter = readProcInfo();
        int64_t newIdleTicks;
        int64_t totalPastTick;
        if(procStatOk && procStatOkAfter) {
           newIdleTicks = cpuTicksAfter.idle3 - cpuTicksBefore.idle3;
           totalPastTick = cpuTicksAfter.total - cpuTicksBefore.total;
        }else{
            auto USER_HZ = sysconf(_SC_CLK_TCK); // per seconds
            auto afterSleep = high_resolution_clock::now();
            auto us = duration_cast<microseconds>(afterSleep - beforeSleep).count();
            totalPastTick = (us / 1000000.0 * USER_HZ);
            newIdleTicks = totalPastTick; // no permission to read
        }
        auto newProcUtime = procStatAfter.utime - procStatBefore.utime;
        auto newProcStime = procStatAfter.stime - procStatBefore.stime;
        auto info = std::make_shared<ProcessInfo>();
        info->totalMem = memInfo.memTotal;
        info->availableMem = memInfo.calcAvaiable();
        info->pid = procStatAfter.pid;
        info->sysCpuUsage = 1.0F - newIdleTicks * 1.0F / totalPastTick;
        info->procCpuUsage = (newProcStime + newProcUtime) *1.0F / totalPastTick;
        info->threadNumInProc = procStatAfter.num_threads;
        info->rss = procStatAfter.rss;
        info->cpuNum = sysconf(_SC_NPROCESSORS_ONLN);
        cocos2d::Application::getInstance()->dispatchTask([info, callback, ptrRunning]() {
            callback(info.get());
            ptrRunning->store(false);
        }, "jsbimpl.getProcessInfo");
    });
    queryThread.detach();
    return true;
}
} // namespace hsext
#endif