#pragma once
#include "base/ccConfig.h"
#if USE_SPINE > 0

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_spine_Animation_proto;
extern se::Class* __jsb_spine_Animation_class;

bool js_register_spine_Animation(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_TrackEntry_proto;
extern se::Class* __jsb_spine_TrackEntry_class;

bool js_register_spine_TrackEntry(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_AnimationState_proto;
extern se::Class* __jsb_spine_AnimationState_class;

bool js_register_spine_AnimationState(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_AnimationStateData_proto;
extern se::Class* __jsb_spine_AnimationStateData_class;

bool js_register_spine_AnimationStateData(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_Attachment_proto;
extern se::Class* __jsb_spine_Attachment_class;

bool js_register_spine_Attachment(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_Timeline_proto;
extern se::Class* __jsb_spine_Timeline_class;

bool js_register_spine_Timeline(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_AttachmentTimeline_proto;
extern se::Class* __jsb_spine_AttachmentTimeline_class;

bool js_register_spine_AttachmentTimeline(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_Bone_proto;
extern se::Class* __jsb_spine_Bone_class;

bool js_register_spine_Bone(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_BoneData_proto;
extern se::Class* __jsb_spine_BoneData_class;

bool js_register_spine_BoneData(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_VertexAttachment_proto;
extern se::Class* __jsb_spine_VertexAttachment_class;

bool js_register_spine_VertexAttachment(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_BoundingBoxAttachment_proto;
extern se::Class* __jsb_spine_BoundingBoxAttachment_class;

bool js_register_spine_BoundingBoxAttachment(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_ClippingAttachment_proto;
extern se::Class* __jsb_spine_ClippingAttachment_class;

bool js_register_spine_ClippingAttachment(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_Color_proto;
extern se::Class* __jsb_spine_Color_class;

bool js_register_spine_Color(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_CurveTimeline_proto;
extern se::Class* __jsb_spine_CurveTimeline_class;

bool js_register_spine_CurveTimeline(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_ColorTimeline_proto;
extern se::Class* __jsb_spine_ColorTimeline_class;

bool js_register_spine_ColorTimeline(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_ConstraintData_proto;
extern se::Class* __jsb_spine_ConstraintData_class;

bool js_register_spine_ConstraintData(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_DeformTimeline_proto;
extern se::Class* __jsb_spine_DeformTimeline_class;

bool js_register_spine_DeformTimeline(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_DrawOrderTimeline_proto;
extern se::Class* __jsb_spine_DrawOrderTimeline_class;

bool js_register_spine_DrawOrderTimeline(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_Event_proto;
extern se::Class* __jsb_spine_Event_class;

bool js_register_spine_Event(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_EventData_proto;
extern se::Class* __jsb_spine_EventData_class;

bool js_register_spine_EventData(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_EventTimeline_proto;
extern se::Class* __jsb_spine_EventTimeline_class;

bool js_register_spine_EventTimeline(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_IkConstraint_proto;
extern se::Class* __jsb_spine_IkConstraint_class;

bool js_register_spine_IkConstraint(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_IkConstraintData_proto;
extern se::Class* __jsb_spine_IkConstraintData_class;

bool js_register_spine_IkConstraintData(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_IkConstraintTimeline_proto;
extern se::Class* __jsb_spine_IkConstraintTimeline_class;

bool js_register_spine_IkConstraintTimeline(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_MeshAttachment_proto;
extern se::Class* __jsb_spine_MeshAttachment_class;

bool js_register_spine_MeshAttachment(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_PathAttachment_proto;
extern se::Class* __jsb_spine_PathAttachment_class;

bool js_register_spine_PathAttachment(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_PathConstraint_proto;
extern se::Class* __jsb_spine_PathConstraint_class;

bool js_register_spine_PathConstraint(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_PathConstraintData_proto;
extern se::Class* __jsb_spine_PathConstraintData_class;

bool js_register_spine_PathConstraintData(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_PathConstraintMixTimeline_proto;
extern se::Class* __jsb_spine_PathConstraintMixTimeline_class;

bool js_register_spine_PathConstraintMixTimeline(se::ScriptEngine *inst, se::Object* obj);
extern se::Object* __jsb_spine_PathConstraintPositionTimeline_proto;
extern se::Class* __jsb_spine_PathConstraintPositionTimeline_class;

bool js_register_spine_PathConstraintPositionTimeline(se::ScriptEngine *inst, se::Object* obj);
extern se::Object* __jsb_spine_PathConstraintSpacingTimeline_proto;
extern se::Class* __jsb_spine_PathConstraintSpacingTimeline_class;

bool js_register_spine_PathConstraintSpacingTimeline(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_PointAttachment_proto;
extern se::Class* __jsb_spine_PointAttachment_class;

bool js_register_spine_PointAttachment(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_RegionAttachment_proto;
extern se::Class* __jsb_spine_RegionAttachment_class;

bool js_register_spine_RegionAttachment(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_RotateTimeline_proto;
extern se::Class* __jsb_spine_RotateTimeline_class;

bool js_register_spine_RotateTimeline(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_TranslateTimeline_proto;
extern se::Class* __jsb_spine_TranslateTimeline_class;

bool js_register_spine_TranslateTimeline(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_ScaleTimeline_proto;
extern se::Class* __jsb_spine_ScaleTimeline_class;

bool js_register_spine_ScaleTimeline(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_ShearTimeline_proto;
extern se::Class* __jsb_spine_ShearTimeline_class;

bool js_register_spine_ShearTimeline(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_Skeleton_proto;
extern se::Class* __jsb_spine_Skeleton_class;

bool js_register_spine_Skeleton(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_SkeletonBounds_proto;
extern se::Class* __jsb_spine_SkeletonBounds_class;

bool js_register_spine_SkeletonBounds(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_Polygon_proto;
extern se::Class* __jsb_spine_Polygon_class;

bool js_register_spine_Polygon(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_SkeletonData_proto;
extern se::Class* __jsb_spine_SkeletonData_class;

bool js_register_spine_SkeletonData(se::ScriptEngine *inst, se::Object* obj);
extern se::Object* __jsb_spine_Skin_proto;
extern se::Class* __jsb_spine_Skin_class;

bool js_register_spine_Skin(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_Slot_proto;
extern se::Class* __jsb_spine_Slot_class;

bool js_register_spine_Slot(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_SlotData_proto;
extern se::Class* __jsb_spine_SlotData_class;

bool js_register_spine_SlotData(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_TransformConstraint_proto;
extern se::Class* __jsb_spine_TransformConstraint_class;

bool js_register_spine_TransformConstraint(se::ScriptEngine *inst, se::Object* obj);
extern se::Object* __jsb_spine_TransformConstraintData_proto;
extern se::Class* __jsb_spine_TransformConstraintData_class;

bool js_register_spine_TransformConstraintData(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_TransformConstraintTimeline_proto;
extern se::Class* __jsb_spine_TransformConstraintTimeline_class;

bool js_register_spine_TransformConstraintTimeline(se::ScriptEngine *inst, se::Object* obj);
extern se::Object* __jsb_spine_TwoColorTimeline_proto;
extern se::Class* __jsb_spine_TwoColorTimeline_class;

bool js_register_spine_TwoColorTimeline(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_VertexEffect_proto;
extern se::Class* __jsb_spine_VertexEffect_class;

bool js_register_spine_VertexEffect(se::ScriptEngine *inst, se::Object* obj);


extern se::Object* __jsb_spine_JitterVertexEffect_proto;
extern se::Class* __jsb_spine_JitterVertexEffect_class;

bool js_register_spine_JitterVertexEffect(se::ScriptEngine *inst, se::Object* obj);
extern se::Object* __jsb_spine_SwirlVertexEffect_proto;
extern se::Class* __jsb_spine_SwirlVertexEffect_class;

bool js_register_spine_SwirlVertexEffect(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_VertexEffectDelegate_proto;
extern se::Class* __jsb_spine_VertexEffectDelegate_class;

bool js_register_spine_VertexEffectDelegate(se::ScriptEngine *inst, se::Object* obj);
extern se::Object* __jsb_spine_SkeletonRenderer_proto;
extern se::Class* __jsb_spine_SkeletonRenderer_class;

bool js_register_spine_SkeletonRenderer(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_SkeletonAnimation_proto;
extern se::Class* __jsb_spine_SkeletonAnimation_class;

bool js_register_spine_SkeletonAnimation(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_SkeletonDataMgr_proto;
extern se::Class* __jsb_spine_SkeletonDataMgr_class;

bool js_register_spine_SkeletonDataMgr(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_SkeletonCacheMgr_proto;
extern se::Class* __jsb_spine_SkeletonCacheMgr_class;

bool js_register_spine_SkeletonCacheMgr(se::ScriptEngine *inst, se::Object* obj);
extern se::Object* __jsb_spine_SkeletonCacheAnimation_proto;
extern se::Class* __jsb_spine_SkeletonCacheAnimation_class;

bool js_register_spine_SkeletonCacheAnimation(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_AttachUtilBase_proto;
extern se::Class* __jsb_spine_AttachUtilBase_class;

bool js_register_spine_AttachUtilBase(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_RealTimeAttachUtil_proto;
extern se::Class* __jsb_spine_RealTimeAttachUtil_class;

bool js_register_spine_RealTimeAttachUtil(se::ScriptEngine *inst, se::Object* obj);

extern se::Object* __jsb_spine_CacheModeAttachUtil_proto;
extern se::Class* __jsb_spine_CacheModeAttachUtil_class;

bool js_register_spine_CacheModeAttachUtil(se::ScriptEngine *inst, se::Object* obj);
bool register_all_cocos2dx_spine(se::ScriptEngine *, se::Object* obj);

#endif //#if USE_SPINE > 0
