#pragma once
#include "base/ccConfig.h"
#if USE_MIDDLEWARE > 0

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_cocos2d_middleware_Texture2D_proto;
extern se::Class* __jsb_cocos2d_middleware_Texture2D_class;

bool js_register_cocos2d_middleware_Texture2D(se::ScriptEngine *inst, se::Object* obj);
extern se::Object* __jsb_cocos2d_middleware_MiddlewareManager_proto;
extern se::Class* __jsb_cocos2d_middleware_MiddlewareManager_class;

bool js_register_cocos2d_middleware_MiddlewareManager(se::ScriptEngine *inst, se::Object* obj);
bool register_all_cocos2dx_editor_support(se::ScriptEngine *, se::Object* obj);

#endif //#if USE_MIDDLEWARE > 0
