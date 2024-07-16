#pragma once
#include "base/ccConfig.h"
#if (USE_WEB_VIEW > 0) && (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS) && !defined(CC_TARGET_OS_TVOS)

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_cocos2d_WebView_proto;
extern se::Class* __jsb_cocos2d_WebView_class;

bool js_register_cocos2d_WebView(se::ScriptEngine *inst, se::Object* obj);
bool register_all_webview(se::ScriptEngine *,se::Object* obj);


#endif //#if (USE_WEB_VIEW > 0) && (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS) && !defined(CC_TARGET_OS_TVOS)
