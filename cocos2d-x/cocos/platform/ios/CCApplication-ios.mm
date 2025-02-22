/****************************************************************************
 Copyright (c) 2010-2012 cocos2d-x.org
 Copyright (c) 2013-2017 Chukong Technologies Inc.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/


#import "CCApplication.h"
#import <UIKit/UIKit.h>
#include <pthread.h>
#include "base/CCAutoreleasePool.h"
#include "base/CCGLUtils.h"
#include "base/CCConfiguration.h"
#include "renderer/gfx/DeviceGraphics.h"
#include "scripting/js-bindings/event/EventDispatcher.h"
#include "scripting/js-bindings/jswrapper/SeApi.h"
#include "CCEAGLView-ios.h"
#include "base/CCGLUtils.h"
#include "audio/include/AudioEngine.h"
#include "platform/CCDevice.h"
#include "cocos/renderer/gfx/DeviceGraphics.h"
#include "storage/local-storage/LocalStorage.h"

#include "decode_image.h"

namespace
{
    bool setCanvasCallback(se::ScriptEngine *inst, se::Object* global)
    {
        auto &viewSize = cocos2d::Application::getInstance()->getViewSize();
        uint8_t devicePixelRatio = cocos2d::Application::getInstance()->getDevicePixelRatio();
        int screenScale =  cocos2d::Device::getDevicePixelRatio();
        char commandBuf[200] = {0};
        //set window.innerWidth/innerHeight in CSS pixel units, not physical pixel units.
        sprintf(commandBuf, "window.innerWidth = %d; window.innerHeight = %d;",
                (int)(viewSize.x / screenScale / devicePixelRatio),
                (int)(viewSize.y / screenScale / devicePixelRatio));
        inst->evalString(commandBuf);
        
        glDepthMask(GL_TRUE);
        return true;
    }
}

@interface MainLoop : NSObject
{
    id _displayLink;
    int _fps;
    float _systemVersion;
    BOOL _isAppActive;
    cocos2d::Device::Rotation _lastRotation;
    cocos2d::Application* _application;
    std::shared_ptr<cocos2d::Scheduler> _scheduler;
}
-(void) startMainLoop;
-(void) stopMainLoop;
-(void) doCaller: (id) sender;
-(void) setPreferredFPS:(int)fps;
-(void) firstStart:(id) view;
@end

@implementation MainLoop

- (instancetype)initWithApplication:(cocos2d::Application*) application
{
    self = [super init];
    if (self)
    {
        _fps = 60;
        _systemVersion = [[UIDevice currentDevice].systemVersion floatValue];
    
        _application = application;
        
        _lastRotation = cocos2d::Device::getDeviceRotation();
        _isAppActive = [UIApplication sharedApplication].applicationState == UIApplicationStateActive;
        NSNotificationCenter *nc = [NSNotificationCenter defaultCenter];
        [nc addObserver:self selector:@selector(appDidBecomeActive) name:UIApplicationDidBecomeActiveNotification object:nil];
        [nc addObserver:self selector:@selector(appDidBecomeInactive) name:UIApplicationWillResignActiveNotification object:nil];
        
        [[UIDevice currentDevice] beginGeneratingDeviceOrientationNotifications];
        [nc addObserver:self selector:@selector(statusBarOrientationChanged:)name:UIApplicationDidChangeStatusBarOrientationNotification
              object:nil];
    }
    return self;
}

- (void) statusBarOrientationChanged:(NSNotification *)note
{
    cocos2d::Device::Rotation rotation = cocos2d::Device::Rotation::_0;
    UIDevice * device = [UIDevice currentDevice];
    
    // NOTE: https://developer.apple.com/documentation/uikit/uideviceorientation
    // when the device rotates to LandscapeLeft, device.orientation returns UIDeviceOrientationLandscapeRight
    // when the device rotates to LandscapeRight, device.orientation returns UIDeviceOrientationLandscapeLeft
    switch(device.orientation)
    {
        case UIDeviceOrientationPortrait:
            rotation = cocos2d::Device::Rotation::_0;
            break;
        case UIDeviceOrientationLandscapeLeft:
            rotation = cocos2d::Device::Rotation::_90;
            break;
        case UIDeviceOrientationPortraitUpsideDown:
            rotation = cocos2d::Device::Rotation::_180;
            break;
        case UIDeviceOrientationLandscapeRight:
            rotation = cocos2d::Device::Rotation::_270;
            break;
        default:
            break;
    };
    if(_lastRotation != rotation){
        cocos2d::EventDispatcher::dispatchOrientationChangeEvent((int) rotation);
        _lastRotation = rotation;
    }
    
    CGRect bounds = [UIScreen mainScreen].bounds;
    float scale = [[UIScreen mainScreen] scale];
    float width = bounds.size.width * scale;
    float height = bounds.size.height * scale;
    cocos2d::Application::getInstance()->updateViewSize(width, height);
}

-(void) dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
    [_displayLink release];
    
    [super dealloc];
}

- (void)appDidBecomeActive
{
    _isAppActive = YES;
}

- (void)appDidBecomeInactive
{
    _isAppActive = NO;
}

-(void) firstStart:(id) view
{
    if ([view isReady]) 
    {
//        _application->clearTasks();
        
        se::WebWorker::stopAll();
        _application->clearTasks();

        se::ScriptEngine* se =  cocos2d::Application::getInstance()->getScriptEngine();
        se->cleanup();
        cocos2d::PoolManager::getInstance()->getCurrentPool()->clear();
        cocos2d::EventDispatcher::init();
        
        se->getTimer()->addIdleTask([se](){
            se->checkTask();
        }, "worker.idle");

        cocos2d::ccInvalidateStateCache();
        se->addRegisterCallback(setCanvasCallback);
        

        if(!_application->applicationDidFinishLaunching())
            return;

        [self startMainLoop];
    }
    else
        // Replace performSelector usage for Apple review policy
        // https://github.com/cocos-creator/3d-tasks/issues/9770
        // [self performSelector:@selector(firstStart:) withObject:view afterDelay:0];
        dispatch_async(dispatch_get_main_queue(), ^{
            [self firstStart:view];
        });
}

-(void) startMainLoop
{
    [self stopMainLoop];
    
    _displayLink = [NSClassFromString(@"CADisplayLink") displayLinkWithTarget:self selector:@selector(doCaller:)];
    if (_systemVersion >= 10.0f)
        [_displayLink setPreferredFramesPerSecond: _fps];
    else
        [_displayLink setFrameInterval: 60 / _fps];
    [_displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
}

-(void) stopMainLoop
{
    if (_displayLink != nil)
    {
        [_displayLink invalidate];
        _displayLink = nil;
    }
}

-(void) setPreferredFPS:(int)fps
{
    _fps = fps;
    [self startMainLoop];
}

-(void) doCaller: (id) sender
{
    static std::chrono::steady_clock::time_point prevTime;
    static std::chrono::steady_clock::time_point now;
    static float dt = 0.f;

    if (_isAppActive)
    {
        EAGLContext* context = [(CCEAGLView*)(_application->getView()) getContext];
        if (context != [EAGLContext currentContext])
        {
            glFlush();
        }
        [EAGLContext setCurrentContext: context];
        
        prevTime = std::chrono::steady_clock::now();
        
        bool downsampleEnabled = _application->isDownsampleEnabled();
        if (downsampleEnabled)
            _application->getRenderTexture()->prepare();
        
        _application->flushTick();
//        _scheduler->update(dt);
        
        cocos2d::EventDispatcher::dispatchTickEvent(dt);
        
        _application->update();
        
        if (downsampleEnabled)
            _application->getRenderTexture()->draw();
        
        [(CCEAGLView*)(_application->getView()) swapBuffers];
        cocos2d::PoolManager::getInstance()->getCurrentPool()->clear();
        
        localStorageCacheSync();
        
        now = std::chrono::steady_clock::now();
        dt = std::chrono::duration_cast<std::chrono::microseconds>(now - prevTime).count() / 1000000.f;
    }
}

@end

NS_CC_BEGIN

Application* Application::_instance = nullptr;

Application::Application(const std::string& name, int width, int height)
{
    Application::_instance = this;
    
    decode_image_init();
#if COCOS2D_DEBUG > 0
    decode_image_set_logger([](const char *msg) {
        printf("[hyperpix] %s\n", msg);
    });
#endif
    
    pthread_setname_np("GameThread");
    
    _scriptEngine = std::make_shared<se::ScriptEngine>();

    _timerLoop = new cc::TimerLoop(_scriptEngine.get());
    
    createView(name, width, height);
    Configuration::getInstance();
    
    glGetIntegerv(GL_FRAMEBUFFER_BINDING, &_mainFBO);
    _renderTexture = new RenderTexture(width, height);
    
    EventDispatcher::init();
    
    _delegate = [[MainLoop alloc] initWithApplication:this];
    
    updateViewSize(width, height);
}

Application::~Application()
{

#if USE_AUDIO
    AudioEngine::end();
#endif

    EventDispatcher::destroy();
    
    clearTasks();
    se::WebWorker::stopAll();
    
    _scriptEngine.reset();
    se::ScriptEngine::Destroy();
    
    // stop main loop
    [(MainLoop*)_delegate stopMainLoop];
    [(MainLoop*)_delegate release];
    _delegate = nullptr;
    
    [(CCEAGLView*)_view release];
    _view = nullptr;

    delete _renderTexture;
    _renderTexture = nullptr;

    Application::_instance = nullptr;
    delete _timerLoop;
    _timerLoop = nullptr;
    printf("~Application\n");
}

const cocos2d::Vec2& Application::getViewSize() const
{
    return _viewSize;
}

void Application::updateViewSize(int width, int height)
{
    _viewSize.x = width;
    _viewSize.y = height;
    cocos2d::EventDispatcher::dispatchResizeEvent(width, height);
}

void Application::start()
{
    if (_delegate)
            // Replace performSelector usage for Apple review policy
            // https://github.com/cocos-creator/3d-tasks/issues/9770
            // [(MainLoop*)_delegate performSelector:@selector(firstStart:) withObject:(CCEAGLView*)_view afterDelay:0];
            dispatch_async(dispatch_get_main_queue(), ^{
            [(MainLoop*)_delegate firstStart:(CCEAGLView*)_view];
        });
}

void Application::restart()
{
    if (_delegate) {
        [(MainLoop*)_delegate stopMainLoop];
        // Replace performSelector usage for Apple review policy
        // https://github.com/cocos-creator/3d-tasks/issues/9770
        // [(MainLoop*)_delegate performSelector:@selector(firstStart:) withObject:(CCEAGLView*)_view afterDelay:0];
        dispatch_async(dispatch_get_main_queue(), ^{
            [(MainLoop*)_delegate firstStart:(CCEAGLView*)_view];
        });
    }
}

void Application::end()
{
    delete this;

    exit(0);
}

void Application::setPreferredFramesPerSecond(int fps)
{
    [(MainLoop*)_delegate setPreferredFPS: fps];
}

std::string Application::getCurrentLanguageCode() const
{
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSArray *languages = [defaults objectForKey:@"AppleLanguages"];
    NSString *currentLanguage = [languages objectAtIndex:0];
    return [currentLanguage UTF8String];
}

bool Application::isDisplayStats() {
    se::AutoHandleScope hs(_scriptEngine.get());
    se::Value ret;
    char commandBuf[100] = "cc.debug.isDisplayStats();";
    getScriptEngine()->evalString(commandBuf, &ret);
    return ret.toBoolean();
}

void Application::setDisplayStats(bool isShow) {
    se::AutoHandleScope hs(_scriptEngine.get());
    char commandBuf[100] = {0};
    sprintf(commandBuf, "cc.debug.setDisplayStats(%s);", isShow ? "true" : "false");
    getScriptEngine()->evalString(commandBuf);
}

Application::LanguageType Application::getCurrentLanguage() const
{
    // get the current language and country config
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSArray *languages = [defaults objectForKey:@"AppleLanguages"];
    NSString *currentLanguage = [languages objectAtIndex:0];

    // get the current language code.(such as English is "en", Chinese is "zh" and so on)
    NSDictionary* temp = [NSLocale componentsFromLocaleIdentifier:currentLanguage];
    NSString * languageCode = [temp objectForKey:NSLocaleLanguageCode];

    if ([languageCode isEqualToString:@"zh"]) return LanguageType::CHINESE;
    if ([languageCode isEqualToString:@"en"]) return LanguageType::ENGLISH;
    if ([languageCode isEqualToString:@"fr"]) return LanguageType::FRENCH;
    if ([languageCode isEqualToString:@"it"]) return LanguageType::ITALIAN;
    if ([languageCode isEqualToString:@"de"]) return LanguageType::GERMAN;
    if ([languageCode isEqualToString:@"es"]) return LanguageType::SPANISH;
    if ([languageCode isEqualToString:@"nl"]) return LanguageType::DUTCH;
    if ([languageCode isEqualToString:@"ru"]) return LanguageType::RUSSIAN;
    if ([languageCode isEqualToString:@"ko"]) return LanguageType::KOREAN;
    if ([languageCode isEqualToString:@"ja"]) return LanguageType::JAPANESE;
    if ([languageCode isEqualToString:@"hu"]) return LanguageType::HUNGARIAN;
    if ([languageCode isEqualToString:@"pt"]) return LanguageType::PORTUGUESE;
    if ([languageCode isEqualToString:@"ar"]) return LanguageType::ARABIC;
    if ([languageCode isEqualToString:@"nb"]) return LanguageType::NORWEGIAN;
    if ([languageCode isEqualToString:@"pl"]) return LanguageType::POLISH;
    if ([languageCode isEqualToString:@"tr"]) return LanguageType::TURKISH;
    if ([languageCode isEqualToString:@"uk"]) return LanguageType::UKRAINIAN;
    if ([languageCode isEqualToString:@"ro"]) return LanguageType::ROMANIAN;
    if ([languageCode isEqualToString:@"bg"]) return LanguageType::BULGARIAN;
    return LanguageType::ENGLISH;
}

Application::Platform Application::getPlatform() const
{
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) // idiom for iOS <= 3.2, otherwise: [UIDevice userInterfaceIdiom] is faster.
        return Platform::IPAD;
    else
        return Platform::IPHONE;
}

float Application::getScreenScale() const
{
    return [(UIView*)_view contentScaleFactor];
}

GLint Application::getMainFBO() const
{
    return _mainFBO;
}

bool Application::openURL(const std::string &url)
{
    NSString* msg = [NSString stringWithCString:url.c_str() encoding:NSUTF8StringEncoding];
    NSURL* nsUrl = [NSURL URLWithString:msg];
    return [[UIApplication sharedApplication] openURL:nsUrl];
}

void Application::copyTextToClipboard(const std::string &text)
{
    UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
    pasteboard.string = [NSString stringWithCString:text.c_str() encoding:NSUTF8StringEncoding];
}

bool Application::applicationDidFinishLaunching()
{
    return true;
}

void Application::onPause()
{
}

void Application::onResume()
{
}

void Application::setMultitouch(bool value)
{
    if (value != _multiTouch)
    {
        _multiTouch = value;
        if (_view)
            [(CCEAGLView*)_view setMultipleTouchEnabled:_multiTouch];
    }
}

void Application::onCreateView(PixelFormat& pixelformat, DepthFormat& depthFormat, int& multisamplingCount)
{
    pixelformat = PixelFormat::RGB565;
    depthFormat = DepthFormat::DEPTH24_STENCIL8;

    multisamplingCount = 0;
}

namespace
{
    GLenum depthFormatMap[] =
    {
        0,                        // NONE: no depth and no stencil
        GL_DEPTH_COMPONENT24_OES, // DEPTH_COMPONENT16: unsupport, convert to GL_DEPTH_COMPONENT24_OES
        GL_DEPTH_COMPONENT24_OES, // DEPTH_COMPONENT24
        GL_DEPTH_COMPONENT24_OES, // DEPTH_COMPONENT32F: unsupport, convert to GL_DEPTH_COMPONENT24_OES
        GL_DEPTH24_STENCIL8_OES,  // DEPTH24_STENCIL8
        GL_DEPTH24_STENCIL8_OES,  // DEPTH32F_STENCIL8: unsupport, convert to GL_DEPTH24_STENCIL8_OES
        GL_DEPTH_STENCIL_OES      // STENCIL_INDEX8
    };
    
    GLenum depthFormat2GLDepthFormat(cocos2d::Application::DepthFormat depthFormat)
    {
        return depthFormatMap[(int)depthFormat];
    }
}

void Application::createView(const std::string& /*name*/, int width, int height)
{
    PixelFormat pixelFormat = PixelFormat::RGB565;
    DepthFormat depthFormat = DepthFormat::DEPTH24_STENCIL8;
    int multisamplingCount = 0;
    
    onCreateView(pixelFormat,
                 depthFormat,
                 multisamplingCount);
    
    CGRect bounds;
    bounds.origin.x = 0;
    bounds.origin.y = 0;
    bounds.size.width = width;
    bounds.size.height = height;
    
    //IDEA: iOS only support these pixel format?
    // - RGB565
    // - RGBA8
    NSString *pixelString = kEAGLColorFormatRGB565;
    if (PixelFormat::RGB565 != pixelFormat &&
        PixelFormat::RGBA8 != pixelFormat)
        NSLog(@"Unsupported pixel format is set, iOS only support RGB565 or RGBA8. Change to use RGB565");
    else if (PixelFormat::RGBA8 == pixelFormat)
        pixelString = kEAGLColorFormatRGBA8;
    
    // create view
    CCEAGLView *eaglView = [CCEAGLView viewWithFrame: bounds
                                         pixelFormat: pixelString
                                         depthFormat: depthFormat2GLDepthFormat(depthFormat)
                                  preserveBackbuffer: NO
                                          sharegroup: nil
                                       multiSampling: multisamplingCount != 0
                                     numberOfSamples: multisamplingCount];
    
    [eaglView setMultipleTouchEnabled:_multiTouch];
    
    [eaglView retain];
    _view = eaglView;
}

std::string Application::getSystemVersion()
{
    NSString* systemVersion = [UIDevice currentDevice].systemVersion;
    return [systemVersion UTF8String];
}

NS_CC_END
