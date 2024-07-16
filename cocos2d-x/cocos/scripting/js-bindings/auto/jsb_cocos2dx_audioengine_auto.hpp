#pragma once
#include "base/ccConfig.h"
#if (USE_AUDIO > 0) && (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_cocos2d_AudioProfile_proto;
extern se::Class* __jsb_cocos2d_AudioProfile_class;

bool js_register_cocos2d_AudioProfile(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_cocos2d_AudioEngine_proto;
extern se::Class* __jsb_cocos2d_AudioEngine_class;

bool js_register_cocos2d_AudioEngine(se::ScriptEngine *, se::Object* obj);
bool register_all_audioengine(se::ScriptEngine *, se::Object* obj);


#endif //#if (USE_AUDIO > 0) && (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
