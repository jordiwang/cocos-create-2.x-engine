#pragma once
#include "base/ccConfig.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_cocos2d_FileUtils_proto;
extern se::Class* __jsb_cocos2d_FileUtils_class;

bool js_register_cocos2d_FileUtils(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_cocos2d_Device_proto;
extern se::Class* __jsb_cocos2d_Device_class;

bool js_register_cocos2d_Device(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_cocos2d_SAXParser_proto;
extern se::Class* __jsb_cocos2d_SAXParser_class;

bool js_register_cocos2d_SAXParser(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_cocos2d_CanvasGradient_proto;
extern se::Class* __jsb_cocos2d_CanvasGradient_class;

bool js_register_cocos2d_CanvasGradient(se::ScriptEngine *, se::Object* obj);


extern se::Object* __jsb_cocos2d_CanvasRenderingContext2D_proto;
extern se::Class* __jsb_cocos2d_CanvasRenderingContext2D_class;

extern se::Object* __jsb_cocos2d_LabelRenderer_proto;
extern se::Class* __jsb_cocos2d_LabelRenderer_class;

bool js_register_cocos2d_LabelRenderer(se::ScriptEngine *, se::Object* obj);
bool register_all_engine(se::ScriptEngine *, se::Object* obj);

