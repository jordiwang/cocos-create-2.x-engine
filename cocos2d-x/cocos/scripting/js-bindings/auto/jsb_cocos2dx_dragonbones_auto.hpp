#pragma once
#include "base/ccConfig.h"
#if USE_DRAGONBONES > 0

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_dragonBones_BaseObject_proto;
extern se::Class* __jsb_dragonBones_BaseObject_class;

bool js_register_dragonBones_BaseObject(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_Matrix_proto;
extern se::Class* __jsb_dragonBones_Matrix_class;

bool js_register_dragonBones_Matrix(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_Transform_proto;
extern se::Class* __jsb_dragonBones_Transform_class;

bool js_register_dragonBones_Transform(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_TextureAtlasData_proto;
extern se::Class* __jsb_dragonBones_TextureAtlasData_class;

bool js_register_dragonBones_TextureAtlasData(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_TextureData_proto;
extern se::Class* __jsb_dragonBones_TextureData_class;

bool js_register_dragonBones_TextureData(se::ScriptEngine *, se::Object* obj);


extern se::Object* __jsb_dragonBones_UserData_proto;
extern se::Class* __jsb_dragonBones_UserData_class;

bool js_register_dragonBones_UserData(se::ScriptEngine *, se::Object* obj);


extern se::Object* __jsb_dragonBones_ArmatureData_proto;
extern se::Class* __jsb_dragonBones_ArmatureData_class;

bool js_register_dragonBones_ArmatureData(se::ScriptEngine *, se::Object* obj);


extern se::Object* __jsb_dragonBones_BoneData_proto;
extern se::Class* __jsb_dragonBones_BoneData_class;

bool js_register_dragonBones_BoneData(se::ScriptEngine *, se::Object* obj);


extern se::Object* __jsb_dragonBones_SlotData_proto;
extern se::Class* __jsb_dragonBones_SlotData_class;

bool js_register_dragonBones_SlotData(se::ScriptEngine *, se::Object* obj);


extern se::Object* __jsb_dragonBones_DragonBonesData_proto;
extern se::Class* __jsb_dragonBones_DragonBonesData_class;

bool js_register_dragonBones_DragonBonesData(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_SkinData_proto;
extern se::Class* __jsb_dragonBones_SkinData_class;

bool js_register_dragonBones_SkinData(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_BoundingBoxData_proto;
extern se::Class* __jsb_dragonBones_BoundingBoxData_class;

bool js_register_dragonBones_BoundingBoxData(se::ScriptEngine *, se::Object* obj);


extern se::Object* __jsb_dragonBones_RectangleBoundingBoxData_proto;
extern se::Class* __jsb_dragonBones_RectangleBoundingBoxData_class;

bool js_register_dragonBones_RectangleBoundingBoxData(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_EllipseBoundingBoxData_proto;
extern se::Class* __jsb_dragonBones_EllipseBoundingBoxData_class;

bool js_register_dragonBones_EllipseBoundingBoxData(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_PolygonBoundingBoxData_proto;
extern se::Class* __jsb_dragonBones_PolygonBoundingBoxData_class;

bool js_register_dragonBones_PolygonBoundingBoxData(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_AnimationData_proto;
extern se::Class* __jsb_dragonBones_AnimationData_class;

bool js_register_dragonBones_AnimationData(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_Armature_proto;
extern se::Class* __jsb_dragonBones_Armature_class;

bool js_register_dragonBones_Armature(se::ScriptEngine *, se::Object* obj);


extern se::Object* __jsb_dragonBones_TransformObject_proto;
extern se::Class* __jsb_dragonBones_TransformObject_class;

bool js_register_dragonBones_TransformObject(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_AnimationState_proto;
extern se::Class* __jsb_dragonBones_AnimationState_class;

bool js_register_dragonBones_AnimationState(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_Bone_proto;
extern se::Class* __jsb_dragonBones_Bone_class;

bool js_register_dragonBones_Bone(se::ScriptEngine *, se::Object* obj);
extern se::Object* __jsb_dragonBones_Slot_proto;
extern se::Class* __jsb_dragonBones_Slot_class;

bool js_register_dragonBones_Slot(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_WorldClock_proto;
extern se::Class* __jsb_dragonBones_WorldClock_class;

bool js_register_dragonBones_WorldClock(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_Animation_proto;
extern se::Class* __jsb_dragonBones_Animation_class;

bool js_register_dragonBones_Animation(se::ScriptEngine *, se::Object* obj);
extern se::Object* __jsb_dragonBones_EventObject_proto;
extern se::Class* __jsb_dragonBones_EventObject_class;

bool js_register_dragonBones_EventObject(se::ScriptEngine *, se::Object* obj);
extern se::Object* __jsb_dragonBones_BaseFactory_proto;
extern se::Class* __jsb_dragonBones_BaseFactory_class;

bool js_register_dragonBones_BaseFactory(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_CCTextureAtlasData_proto;
extern se::Class* __jsb_dragonBones_CCTextureAtlasData_class;

bool js_register_dragonBones_CCTextureAtlasData(se::ScriptEngine *, se::Object* obj);
extern se::Object* __jsb_dragonBones_CCTextureData_proto;
extern se::Class* __jsb_dragonBones_CCTextureData_class;

bool js_register_dragonBones_CCTextureData(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_CCSlot_proto;
extern se::Class* __jsb_dragonBones_CCSlot_class;

bool js_register_dragonBones_CCSlot(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_CCArmatureDisplay_proto;
extern se::Class* __jsb_dragonBones_CCArmatureDisplay_class;

bool js_register_dragonBones_CCArmatureDisplay(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_CCFactory_proto;
extern se::Class* __jsb_dragonBones_CCFactory_class;

bool js_register_dragonBones_CCFactory(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_ArmatureCacheMgr_proto;
extern se::Class* __jsb_dragonBones_ArmatureCacheMgr_class;

bool js_register_dragonBones_ArmatureCacheMgr(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_CCArmatureCacheDisplay_proto;
extern se::Class* __jsb_dragonBones_CCArmatureCacheDisplay_class;

bool js_register_dragonBones_CCArmatureCacheDisplay(se::ScriptEngine *, se::Object* obj);
extern se::Object* __jsb_dragonBones_AttachUtilBase_proto;
extern se::Class* __jsb_dragonBones_AttachUtilBase_class;

bool js_register_dragonBones_AttachUtilBase(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_RealTimeAttachUtil_proto;
extern se::Class* __jsb_dragonBones_RealTimeAttachUtil_class;

bool js_register_dragonBones_RealTimeAttachUtil(se::ScriptEngine *, se::Object* obj);

extern se::Object* __jsb_dragonBones_CacheModeAttachUtil_proto;
extern se::Class* __jsb_dragonBones_CacheModeAttachUtil_class;

bool js_register_dragonBones_CacheModeAttachUtil(se::ScriptEngine *, se::Object* obj);
bool register_all_cocos2dx_dragonbones(se::ScriptEngine *, se::Object* obj);

#endif //#if USE_DRAGONBONES > 0
