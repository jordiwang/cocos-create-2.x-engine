#pragma once
#include "base/ccConfig.h"
#if (USE_GFX_RENDERER > 0) && (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_cocos2d_renderer_ProgramLib_proto;
extern se::Class* __jsb_cocos2d_renderer_ProgramLib_class;

bool js_register_cocos2d_renderer_ProgramLib(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_EffectBase_proto;
extern se::Class* __jsb_cocos2d_renderer_EffectBase_class;

bool js_register_cocos2d_renderer_EffectBase(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_Effect_proto;
extern se::Class* __jsb_cocos2d_renderer_Effect_class;

bool js_register_cocos2d_renderer_Effect(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_EffectVariant_proto;
extern se::Class* __jsb_cocos2d_renderer_EffectVariant_class;

bool js_register_cocos2d_renderer_EffectVariant(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_AssemblerBase_proto;
extern se::Class* __jsb_cocos2d_renderer_AssemblerBase_class;

bool js_register_cocos2d_renderer_AssemblerBase(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_MemPool_proto;
extern se::Class* __jsb_cocos2d_renderer_MemPool_class;

bool js_register_cocos2d_renderer_MemPool(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_NodeProxy_proto;
extern se::Class* __jsb_cocos2d_renderer_NodeProxy_class;

bool js_register_cocos2d_renderer_NodeProxy(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_BaseRenderer_proto;
extern se::Class* __jsb_cocos2d_renderer_BaseRenderer_class;

bool js_register_cocos2d_renderer_BaseRenderer(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_View_proto;
extern se::Class* __jsb_cocos2d_renderer_View_class;

bool js_register_cocos2d_renderer_View(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_Camera_proto;
extern se::Class* __jsb_cocos2d_renderer_Camera_class;

bool js_register_cocos2d_renderer_Camera(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_ForwardRenderer_proto;
extern se::Class* __jsb_cocos2d_renderer_ForwardRenderer_class;

bool js_register_cocos2d_renderer_ForwardRenderer(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_Light_proto;
extern se::Class* __jsb_cocos2d_renderer_Light_class;

bool js_register_cocos2d_renderer_Light(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_Scene_proto;
extern se::Class* __jsb_cocos2d_renderer_Scene_class;

bool js_register_cocos2d_renderer_Scene(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_NodeMemPool_proto;
extern se::Class* __jsb_cocos2d_renderer_NodeMemPool_class;

bool js_register_cocos2d_renderer_NodeMemPool(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_RenderDataList_proto;
extern se::Class* __jsb_cocos2d_renderer_RenderDataList_class;

bool js_register_cocos2d_renderer_RenderDataList(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_Assembler_proto;
extern se::Class* __jsb_cocos2d_renderer_Assembler_class;

bool js_register_cocos2d_renderer_Assembler(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_CustomAssembler_proto;
extern se::Class* __jsb_cocos2d_renderer_CustomAssembler_class;

bool js_register_cocos2d_renderer_CustomAssembler(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_RenderFlow_proto;
extern se::Class* __jsb_cocos2d_renderer_RenderFlow_class;

bool js_register_cocos2d_renderer_RenderFlow(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_AssemblerSprite_proto;
extern se::Class* __jsb_cocos2d_renderer_AssemblerSprite_class;

bool js_register_cocos2d_renderer_AssemblerSprite(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_SimpleSprite2D_proto;
extern se::Class* __jsb_cocos2d_renderer_SimpleSprite2D_class;

bool js_register_cocos2d_renderer_SimpleSprite2D(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_MaskAssembler_proto;
extern se::Class* __jsb_cocos2d_renderer_MaskAssembler_class;

bool js_register_cocos2d_renderer_MaskAssembler(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_TiledMapAssembler_proto;
extern se::Class* __jsb_cocos2d_renderer_TiledMapAssembler_class;

bool js_register_cocos2d_renderer_TiledMapAssembler(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_SlicedSprite2D_proto;
extern se::Class* __jsb_cocos2d_renderer_SlicedSprite2D_class;

bool js_register_cocos2d_renderer_SlicedSprite2D(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_MeshAssembler_proto;
extern se::Class* __jsb_cocos2d_renderer_MeshAssembler_class;

bool js_register_cocos2d_renderer_MeshAssembler(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_SimpleSprite3D_proto;
extern se::Class* __jsb_cocos2d_renderer_SimpleSprite3D_class;

bool js_register_cocos2d_renderer_SimpleSprite3D(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_SlicedSprite3D_proto;
extern se::Class* __jsb_cocos2d_renderer_SlicedSprite3D_class;

bool js_register_cocos2d_renderer_SlicedSprite3D(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_cocos2d_renderer_Particle3DAssembler_proto;
extern se::Class* __jsb_cocos2d_renderer_Particle3DAssembler_class;

bool js_register_cocos2d_renderer_Particle3DAssembler(se::ScriptEngine *inst, se::Object* obj);
bool register_all_renderer(se::ScriptEngine *, se::Object* obj);

#endif //#if (USE_GFX_RENDERER > 0) && (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
