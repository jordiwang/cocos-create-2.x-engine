#pragma once
#include "base/ccConfig.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

namespace se {
    class Object;
    class ScriptEngine;
    class Class;
}

extern se::Object* __jsb_cocos2d_network_Downloader_proto;
extern se::Class* __jsb_cocos2d_network_Downloader_class;

bool js_register_cocos2d_network_Downloader(se::ScriptEngine *inst, se::Object* obj);
bool register_all_network(se::ScriptEngine *, se::Object* obj);

#endif //#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
