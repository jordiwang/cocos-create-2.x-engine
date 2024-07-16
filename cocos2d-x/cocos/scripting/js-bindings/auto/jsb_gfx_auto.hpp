#pragma once
#include "base/ccConfig.h"
#if (USE_GFX_RENDERER > 0) && (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_cocos2d_renderer_GraphicsHandle_proto;
extern se::Class* __jsb_cocos2d_renderer_GraphicsHandle_class;

bool js_register_cocos2d_renderer_GraphicsHandle(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_IndexBuffer_proto;
extern se::Class* __jsb_cocos2d_renderer_IndexBuffer_class;

bool js_register_cocos2d_renderer_IndexBuffer(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_VertexBuffer_proto;
extern se::Class* __jsb_cocos2d_renderer_VertexBuffer_class;

bool js_register_cocos2d_renderer_VertexBuffer(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_DeviceGraphics_proto;
extern se::Class* __jsb_cocos2d_renderer_DeviceGraphics_class;

bool js_register_cocos2d_renderer_DeviceGraphics(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_FrameBuffer_proto;
extern se::Class* __jsb_cocos2d_renderer_FrameBuffer_class;

bool js_register_cocos2d_renderer_FrameBuffer(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_RenderTarget_proto;
extern se::Class* __jsb_cocos2d_renderer_RenderTarget_class;

bool js_register_cocos2d_renderer_RenderTarget(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_RenderBuffer_proto;
extern se::Class* __jsb_cocos2d_renderer_RenderBuffer_class;

bool js_register_cocos2d_renderer_RenderBuffer(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_Texture_proto;
extern se::Class* __jsb_cocos2d_renderer_Texture_class;

bool js_register_cocos2d_renderer_Texture(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_Texture2D_proto;
extern se::Class* __jsb_cocos2d_renderer_Texture2D_class;

bool js_register_cocos2d_renderer_Texture2D(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_Program_proto;
extern se::Class* __jsb_cocos2d_renderer_Program_class;

bool js_register_cocos2d_renderer_Program(se::ScriptEngine *inst, se::Object* obj);
bool register_all_gfx(se::ScriptEngine *, se::Object* obj);

#endif //#if (USE_GFX_RENDERER > 0) && (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
