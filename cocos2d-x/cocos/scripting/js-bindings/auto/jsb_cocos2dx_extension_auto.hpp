#pragma once
#include "base/ccConfig.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_cocos2d_extension_EventAssetsManagerEx_proto;
extern se::Class* __jsb_cocos2d_extension_EventAssetsManagerEx_class;

bool js_register_cocos2d_extension_EventAssetsManagerEx(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_extension_Manifest_proto;
extern se::Class* __jsb_cocos2d_extension_Manifest_class;

bool js_register_cocos2d_extension_Manifest(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_extension_AssetsManagerEx_proto;
extern se::Class* __jsb_cocos2d_extension_AssetsManagerEx_class;

bool js_register_cocos2d_extension_AssetsManagerEx(se::ScriptEngine *inst, se::Object* obj);
bool register_all_extension(se::ScriptEngine *, se::Object* obj);
