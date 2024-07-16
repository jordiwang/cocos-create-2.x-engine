#include "scripting/js-bindings/auto/jsb_cocos2dx_spine_auto.hpp"
#if USE_SPINE > 0
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "spine-creator-support/spine-cocos2dx.h"

se::Object* __jsb_spine_Animation_proto = nullptr;
se::Class* __jsb_spine_Animation_class = nullptr;

static bool js_cocos2dx_spine_Animation_getTimelines(se::State &s, se::ScriptEngine *inst)
{
    spine::Animation* cobj = (spine::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Animation_getTimelines : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::Timeline *>& result = cobj->getTimelines();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Animation_getTimelines : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Animation_getTimelines)

static bool js_cocos2dx_spine_Animation_hasTimeline(se::State &s, se::ScriptEngine *inst)
{
    spine::Animation* cobj = (spine::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Animation_hasTimeline : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Animation_hasTimeline : Error processing arguments");
        bool result = cobj->hasTimeline(arg0);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Animation_hasTimeline : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Animation_hasTimeline)

static bool js_cocos2dx_spine_Animation_getName(se::State &s, se::ScriptEngine *inst)
{
    spine::Animation* cobj = (spine::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Animation_getName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getName();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Animation_getName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Animation_getName)

static bool js_cocos2dx_spine_Animation_getDuration(se::State &s, se::ScriptEngine *inst)
{
    spine::Animation* cobj = (spine::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Animation_getDuration : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getDuration();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Animation_getDuration : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Animation_getDuration)

static bool js_cocos2dx_spine_Animation_setDuration(se::State &s, se::ScriptEngine *inst)
{
    spine::Animation* cobj = (spine::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Animation_setDuration : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Animation_setDuration : Error processing arguments");
        cobj->setDuration(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Animation_setDuration)




bool js_register_cocos2dx_spine_Animation(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Animation", obj, nullptr, nullptr);

    cls->defineFunction(inst, "getTimelines", _SE(js_cocos2dx_spine_Animation_getTimelines));
    cls->defineFunction(inst, "hasTimeline", _SE(js_cocos2dx_spine_Animation_hasTimeline));
    cls->defineFunction(inst, "getName", _SE(js_cocos2dx_spine_Animation_getName));
    cls->defineFunction(inst, "getDuration", _SE(js_cocos2dx_spine_Animation_getDuration));
    cls->defineFunction(inst, "setDuration", _SE(js_cocos2dx_spine_Animation_setDuration));
    cls->install(inst);
    inst->registerClass<spine::Animation>(cls);

    __jsb_spine_Animation_proto = cls->getProto();
    __jsb_spine_Animation_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_TrackEntry_proto = nullptr;
se::Class* __jsb_spine_TrackEntry_class = nullptr;

static bool js_cocos2dx_spine_TrackEntry_getNext(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getNext : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::TrackEntry* result = cobj->getNext();
        ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getNext : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getNext)

static bool js_cocos2dx_spine_TrackEntry_getAttachmentThreshold(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getAttachmentThreshold : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getAttachmentThreshold();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getAttachmentThreshold : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getAttachmentThreshold)

static bool js_cocos2dx_spine_TrackEntry_setTimeScale(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_setTimeScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_setTimeScale : Error processing arguments");
        cobj->setTimeScale(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_setTimeScale)

static bool js_cocos2dx_spine_TrackEntry_getMixDuration(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getMixDuration : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getMixDuration();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getMixDuration : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getMixDuration)

static bool js_cocos2dx_spine_TrackEntry_setAnimationEnd(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_setAnimationEnd : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_setAnimationEnd : Error processing arguments");
        cobj->setAnimationEnd(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_setAnimationEnd)

static bool js_cocos2dx_spine_TrackEntry_setEventThreshold(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_setEventThreshold : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_setEventThreshold : Error processing arguments");
        cobj->setEventThreshold(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_setEventThreshold)

static bool js_cocos2dx_spine_TrackEntry_getMixingTo(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getMixingTo : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::TrackEntry* result = cobj->getMixingTo();
        ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getMixingTo : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getMixingTo)

static bool js_cocos2dx_spine_TrackEntry_setTrackEnd(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_setTrackEnd : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_setTrackEnd : Error processing arguments");
        cobj->setTrackEnd(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_setTrackEnd)

static bool js_cocos2dx_spine_TrackEntry_getMixBlend(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getMixBlend : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = (unsigned int)cobj->getMixBlend();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getMixBlend : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getMixBlend)

static bool js_cocos2dx_spine_TrackEntry_getTrackEnd(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getTrackEnd : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTrackEnd();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getTrackEnd : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getTrackEnd)

static bool js_cocos2dx_spine_TrackEntry_setDelay(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_setDelay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_setDelay : Error processing arguments");
        cobj->setDelay(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_setDelay)

static bool js_cocos2dx_spine_TrackEntry_getAnimationEnd(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getAnimationEnd : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getAnimationEnd();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getAnimationEnd : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getAnimationEnd)

static bool js_cocos2dx_spine_TrackEntry_setAttachmentThreshold(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_setAttachmentThreshold : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_setAttachmentThreshold : Error processing arguments");
        cobj->setAttachmentThreshold(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_setAttachmentThreshold)

static bool js_cocos2dx_spine_TrackEntry_setMixTime(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_setMixTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_setMixTime : Error processing arguments");
        cobj->setMixTime(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_setMixTime)

static bool js_cocos2dx_spine_TrackEntry_isComplete(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_isComplete : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isComplete();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_isComplete : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_isComplete)

static bool js_cocos2dx_spine_TrackEntry_getMixingFrom(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getMixingFrom : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::TrackEntry* result = cobj->getMixingFrom();
        ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getMixingFrom : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getMixingFrom)

static bool js_cocos2dx_spine_TrackEntry_setAlpha(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_setAlpha : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_setAlpha : Error processing arguments");
        cobj->setAlpha(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_setAlpha)

static bool js_cocos2dx_spine_TrackEntry_getDrawOrderThreshold(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getDrawOrderThreshold : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getDrawOrderThreshold();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getDrawOrderThreshold : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getDrawOrderThreshold)

static bool js_cocos2dx_spine_TrackEntry_getMixTime(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getMixTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getMixTime();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getMixTime : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getMixTime)

static bool js_cocos2dx_spine_TrackEntry_setTrackTime(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_setTrackTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_setTrackTime : Error processing arguments");
        cobj->setTrackTime(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_setTrackTime)

static bool js_cocos2dx_spine_TrackEntry_setMixDuration(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_setMixDuration : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_setMixDuration : Error processing arguments");
        cobj->setMixDuration(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_setMixDuration)

static bool js_cocos2dx_spine_TrackEntry_resetRotationDirections(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_resetRotationDirections : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->resetRotationDirections();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_resetRotationDirections)

static bool js_cocos2dx_spine_TrackEntry_setHoldPrevious(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_setHoldPrevious : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_setHoldPrevious : Error processing arguments");
        cobj->setHoldPrevious(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_setHoldPrevious)

static bool js_cocos2dx_spine_TrackEntry_getLoop(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getLoop : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getLoop();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getLoop : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getLoop)

static bool js_cocos2dx_spine_TrackEntry_getTrackTime(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getTrackTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTrackTime();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getTrackTime : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getTrackTime)

static bool js_cocos2dx_spine_TrackEntry_getAnimationStart(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getAnimationStart : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getAnimationStart();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getAnimationStart : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getAnimationStart)

static bool js_cocos2dx_spine_TrackEntry_getAnimationLast(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getAnimationLast : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getAnimationLast();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getAnimationLast : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getAnimationLast)

static bool js_cocos2dx_spine_TrackEntry_setAnimationStart(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_setAnimationStart : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_setAnimationStart : Error processing arguments");
        cobj->setAnimationStart(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_setAnimationStart)

static bool js_cocos2dx_spine_TrackEntry_setLoop(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_setLoop : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_setLoop : Error processing arguments");
        cobj->setLoop(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_setLoop)

static bool js_cocos2dx_spine_TrackEntry_getTrackIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getTrackIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getTrackIndex();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getTrackIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getTrackIndex)

static bool js_cocos2dx_spine_TrackEntry_getTimeScale(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getTimeScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTimeScale();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getTimeScale : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getTimeScale)

static bool js_cocos2dx_spine_TrackEntry_getDelay(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getDelay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getDelay();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getDelay : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getDelay)

static bool js_cocos2dx_spine_TrackEntry_getAnimation(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Animation* result = cobj->getAnimation();
        ok &= native_ptr_to_rooted_seval<spine::Animation>(inst, (spine::Animation*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getAnimation)

static bool js_cocos2dx_spine_TrackEntry_getHoldPrevious(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getHoldPrevious : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getHoldPrevious();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getHoldPrevious : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getHoldPrevious)

static bool js_cocos2dx_spine_TrackEntry_getAnimationTime(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getAnimationTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getAnimationTime();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getAnimationTime : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getAnimationTime)

static bool js_cocos2dx_spine_TrackEntry_getEventThreshold(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getEventThreshold : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getEventThreshold();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getEventThreshold : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getEventThreshold)

static bool js_cocos2dx_spine_TrackEntry_setDrawOrderThreshold(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_setDrawOrderThreshold : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_setDrawOrderThreshold : Error processing arguments");
        cobj->setDrawOrderThreshold(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_setDrawOrderThreshold)

static bool js_cocos2dx_spine_TrackEntry_setAnimationLast(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_setAnimationLast : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_setAnimationLast : Error processing arguments");
        cobj->setAnimationLast(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_setAnimationLast)

static bool js_cocos2dx_spine_TrackEntry_getAlpha(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_getAlpha : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getAlpha();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_getAlpha : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_getAlpha)

static bool js_cocos2dx_spine_TrackEntry_setMixBlend(se::State &s, se::ScriptEngine *inst)
{
    spine::TrackEntry* cobj = (spine::TrackEntry*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TrackEntry_setMixBlend : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::MixBlend arg0;
        ok &= seval_to_uint32(inst, args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TrackEntry_setMixBlend : Error processing arguments");
        cobj->setMixBlend(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TrackEntry_setMixBlend)




bool js_register_cocos2dx_spine_TrackEntry(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "TrackEntry", obj, nullptr, nullptr);

    cls->defineFunction(inst, "getNext", _SE(js_cocos2dx_spine_TrackEntry_getNext));
    cls->defineFunction(inst, "getAttachmentThreshold", _SE(js_cocos2dx_spine_TrackEntry_getAttachmentThreshold));
    cls->defineFunction(inst, "setTimeScale", _SE(js_cocos2dx_spine_TrackEntry_setTimeScale));
    cls->defineFunction(inst, "getMixDuration", _SE(js_cocos2dx_spine_TrackEntry_getMixDuration));
    cls->defineFunction(inst, "setAnimationEnd", _SE(js_cocos2dx_spine_TrackEntry_setAnimationEnd));
    cls->defineFunction(inst, "setEventThreshold", _SE(js_cocos2dx_spine_TrackEntry_setEventThreshold));
    cls->defineFunction(inst, "getMixingTo", _SE(js_cocos2dx_spine_TrackEntry_getMixingTo));
    cls->defineFunction(inst, "setTrackEnd", _SE(js_cocos2dx_spine_TrackEntry_setTrackEnd));
    cls->defineFunction(inst, "getMixBlend", _SE(js_cocos2dx_spine_TrackEntry_getMixBlend));
    cls->defineFunction(inst, "getTrackEnd", _SE(js_cocos2dx_spine_TrackEntry_getTrackEnd));
    cls->defineFunction(inst, "setDelay", _SE(js_cocos2dx_spine_TrackEntry_setDelay));
    cls->defineFunction(inst, "getAnimationEnd", _SE(js_cocos2dx_spine_TrackEntry_getAnimationEnd));
    cls->defineFunction(inst, "setAttachmentThreshold", _SE(js_cocos2dx_spine_TrackEntry_setAttachmentThreshold));
    cls->defineFunction(inst, "setMixTime", _SE(js_cocos2dx_spine_TrackEntry_setMixTime));
    cls->defineFunction(inst, "isComplete", _SE(js_cocos2dx_spine_TrackEntry_isComplete));
    cls->defineFunction(inst, "getMixingFrom", _SE(js_cocos2dx_spine_TrackEntry_getMixingFrom));
    cls->defineFunction(inst, "setAlpha", _SE(js_cocos2dx_spine_TrackEntry_setAlpha));
    cls->defineFunction(inst, "getDrawOrderThreshold", _SE(js_cocos2dx_spine_TrackEntry_getDrawOrderThreshold));
    cls->defineFunction(inst, "getMixTime", _SE(js_cocos2dx_spine_TrackEntry_getMixTime));
    cls->defineFunction(inst, "setTrackTime", _SE(js_cocos2dx_spine_TrackEntry_setTrackTime));
    cls->defineFunction(inst, "setMixDuration", _SE(js_cocos2dx_spine_TrackEntry_setMixDuration));
    cls->defineFunction(inst, "resetRotationDirections", _SE(js_cocos2dx_spine_TrackEntry_resetRotationDirections));
    cls->defineFunction(inst, "setHoldPrevious", _SE(js_cocos2dx_spine_TrackEntry_setHoldPrevious));
    cls->defineFunction(inst, "getLoop", _SE(js_cocos2dx_spine_TrackEntry_getLoop));
    cls->defineFunction(inst, "getTrackTime", _SE(js_cocos2dx_spine_TrackEntry_getTrackTime));
    cls->defineFunction(inst, "getAnimationStart", _SE(js_cocos2dx_spine_TrackEntry_getAnimationStart));
    cls->defineFunction(inst, "getAnimationLast", _SE(js_cocos2dx_spine_TrackEntry_getAnimationLast));
    cls->defineFunction(inst, "setAnimationStart", _SE(js_cocos2dx_spine_TrackEntry_setAnimationStart));
    cls->defineFunction(inst, "setLoop", _SE(js_cocos2dx_spine_TrackEntry_setLoop));
    cls->defineFunction(inst, "getTrackIndex", _SE(js_cocos2dx_spine_TrackEntry_getTrackIndex));
    cls->defineFunction(inst, "getTimeScale", _SE(js_cocos2dx_spine_TrackEntry_getTimeScale));
    cls->defineFunction(inst, "getDelay", _SE(js_cocos2dx_spine_TrackEntry_getDelay));
    cls->defineFunction(inst, "getAnimation", _SE(js_cocos2dx_spine_TrackEntry_getAnimation));
    cls->defineFunction(inst, "getHoldPrevious", _SE(js_cocos2dx_spine_TrackEntry_getHoldPrevious));
    cls->defineFunction(inst, "getAnimationTime", _SE(js_cocos2dx_spine_TrackEntry_getAnimationTime));
    cls->defineFunction(inst, "getEventThreshold", _SE(js_cocos2dx_spine_TrackEntry_getEventThreshold));
    cls->defineFunction(inst, "setDrawOrderThreshold", _SE(js_cocos2dx_spine_TrackEntry_setDrawOrderThreshold));
    cls->defineFunction(inst, "setAnimationLast", _SE(js_cocos2dx_spine_TrackEntry_setAnimationLast));
    cls->defineFunction(inst, "getAlpha", _SE(js_cocos2dx_spine_TrackEntry_getAlpha));
    cls->defineFunction(inst, "setMixBlend", _SE(js_cocos2dx_spine_TrackEntry_setMixBlend));
    cls->install(inst);
    inst->registerClass<spine::TrackEntry>(cls);

    __jsb_spine_TrackEntry_proto = cls->getProto();
    __jsb_spine_TrackEntry_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_AnimationState_proto = nullptr;
se::Class* __jsb_spine_AnimationState_class = nullptr;

static bool js_cocos2dx_spine_AnimationState_getData(se::State &s, se::ScriptEngine *inst)
{
    spine::AnimationState* cobj = (spine::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AnimationState_getData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::AnimationStateData* result = cobj->getData();
        ok &= native_ptr_to_rooted_seval<spine::AnimationStateData>(inst, (spine::AnimationStateData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationState_getData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationState_getData)

static bool js_cocos2dx_spine_AnimationState_addAnimation(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    spine::AnimationState* cobj = (spine::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_spine_AnimationState_addAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 4) {
            size_t arg0 = 0;
            ok &= seval_to_size(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            spine::Animation* arg1 = nullptr;
            ok &= seval_to_native_ptr(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            bool arg2;
            ok &= seval_to_boolean(inst, args[2], &arg2);
            float arg3 = 0;
            ok &= seval_to_float(inst, args[3], &arg3);
            if (!ok) { ok = true; break; }
            spine::TrackEntry* result = cobj->addAnimation(arg0, arg1, arg2, arg3);
            ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationState_addAnimation : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 4) {
            size_t arg0 = 0;
            ok &= seval_to_size(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            spine::String arg1;
            arg1 = args[1].toStringForce().c_str();
            if (!ok) { ok = true; break; }
            bool arg2;
            ok &= seval_to_boolean(inst, args[2], &arg2);
            float arg3 = 0;
            ok &= seval_to_float(inst, args[3], &arg3);
            if (!ok) { ok = true; break; }
            spine::TrackEntry* result = cobj->addAnimation(arg0, arg1, arg2, arg3);
            ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationState_addAnimation : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationState_addAnimation)

static bool js_cocos2dx_spine_AnimationState_setEmptyAnimations(se::State &s, se::ScriptEngine *inst)
{
    spine::AnimationState* cobj = (spine::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AnimationState_setEmptyAnimations : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationState_setEmptyAnimations : Error processing arguments");
        cobj->setEmptyAnimations(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationState_setEmptyAnimations)

static bool js_cocos2dx_spine_AnimationState_getCurrent(se::State &s, se::ScriptEngine *inst)
{
    spine::AnimationState* cobj = (spine::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AnimationState_getCurrent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        size_t arg0 = 0;
        ok &= seval_to_size(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationState_getCurrent : Error processing arguments");
        spine::TrackEntry* result = cobj->getCurrent(arg0);
        ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationState_getCurrent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationState_getCurrent)

static bool js_cocos2dx_spine_AnimationState_enableQueue(se::State &s, se::ScriptEngine *inst)
{
    spine::AnimationState* cobj = (spine::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AnimationState_enableQueue : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->enableQueue();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationState_enableQueue)

static bool js_cocos2dx_spine_AnimationState_clearTracks(se::State &s, se::ScriptEngine *inst)
{
    spine::AnimationState* cobj = (spine::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AnimationState_clearTracks : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->clearTracks();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationState_clearTracks)

static bool js_cocos2dx_spine_AnimationState_update(se::State &s, se::ScriptEngine *inst)
{
    spine::AnimationState* cobj = (spine::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AnimationState_update : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationState_update : Error processing arguments");
        cobj->update(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationState_update)

static bool js_cocos2dx_spine_AnimationState_disableQueue(se::State &s, se::ScriptEngine *inst)
{
    spine::AnimationState* cobj = (spine::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AnimationState_disableQueue : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->disableQueue();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationState_disableQueue)

static bool js_cocos2dx_spine_AnimationState_setEmptyAnimation(se::State &s, se::ScriptEngine *inst)
{
    spine::AnimationState* cobj = (spine::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AnimationState_setEmptyAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        size_t arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_size(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationState_setEmptyAnimation : Error processing arguments");
        spine::TrackEntry* result = cobj->setEmptyAnimation(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationState_setEmptyAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationState_setEmptyAnimation)

static bool js_cocos2dx_spine_AnimationState_setTimeScale(se::State &s, se::ScriptEngine *inst)
{
    spine::AnimationState* cobj = (spine::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AnimationState_setTimeScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationState_setTimeScale : Error processing arguments");
        cobj->setTimeScale(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationState_setTimeScale)

static bool js_cocos2dx_spine_AnimationState_getTracks(se::State &s, se::ScriptEngine *inst)
{
    spine::AnimationState* cobj = (spine::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AnimationState_getTracks : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::TrackEntry *>& result = cobj->getTracks();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationState_getTracks : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationState_getTracks)

static bool js_cocos2dx_spine_AnimationState_clearTrack(se::State &s, se::ScriptEngine *inst)
{
    spine::AnimationState* cobj = (spine::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AnimationState_clearTrack : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        size_t arg0 = 0;
        ok &= seval_to_size(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationState_clearTrack : Error processing arguments");
        cobj->clearTrack(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationState_clearTrack)

static bool js_cocos2dx_spine_AnimationState_setAnimation(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    spine::AnimationState* cobj = (spine::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_spine_AnimationState_setAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 3) {
            size_t arg0 = 0;
            ok &= seval_to_size(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            spine::Animation* arg1 = nullptr;
            ok &= seval_to_native_ptr(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            bool arg2;
            ok &= seval_to_boolean(inst, args[2], &arg2);
            spine::TrackEntry* result = cobj->setAnimation(arg0, arg1, arg2);
            ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationState_setAnimation : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 3) {
            size_t arg0 = 0;
            ok &= seval_to_size(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            spine::String arg1;
            arg1 = args[1].toStringForce().c_str();
            if (!ok) { ok = true; break; }
            bool arg2;
            ok &= seval_to_boolean(inst, args[2], &arg2);
            spine::TrackEntry* result = cobj->setAnimation(arg0, arg1, arg2);
            ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationState_setAnimation : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationState_setAnimation)

static bool js_cocos2dx_spine_AnimationState_addEmptyAnimation(se::State &s, se::ScriptEngine *inst)
{
    spine::AnimationState* cobj = (spine::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AnimationState_addEmptyAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        size_t arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        ok &= seval_to_size(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationState_addEmptyAnimation : Error processing arguments");
        spine::TrackEntry* result = cobj->addEmptyAnimation(arg0, arg1, arg2);
        ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationState_addEmptyAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationState_addEmptyAnimation)

static bool js_cocos2dx_spine_AnimationState_getTimeScale(se::State &s, se::ScriptEngine *inst)
{
    spine::AnimationState* cobj = (spine::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AnimationState_getTimeScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTimeScale();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationState_getTimeScale : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationState_getTimeScale)




bool js_register_cocos2dx_spine_AnimationState(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "AnimationState", obj, nullptr, nullptr);

    cls->defineFunction(inst, "getData", _SE(js_cocos2dx_spine_AnimationState_getData));
    cls->defineFunction(inst, "addAnimation", _SE(js_cocos2dx_spine_AnimationState_addAnimation));
    cls->defineFunction(inst, "setEmptyAnimations", _SE(js_cocos2dx_spine_AnimationState_setEmptyAnimations));
    cls->defineFunction(inst, "getCurrent", _SE(js_cocos2dx_spine_AnimationState_getCurrent));
    cls->defineFunction(inst, "enableQueue", _SE(js_cocos2dx_spine_AnimationState_enableQueue));
    cls->defineFunction(inst, "clearTracks", _SE(js_cocos2dx_spine_AnimationState_clearTracks));
    cls->defineFunction(inst, "update", _SE(js_cocos2dx_spine_AnimationState_update));
    cls->defineFunction(inst, "disableQueue", _SE(js_cocos2dx_spine_AnimationState_disableQueue));
    cls->defineFunction(inst, "setEmptyAnimation", _SE(js_cocos2dx_spine_AnimationState_setEmptyAnimation));
    cls->defineFunction(inst, "setTimeScale", _SE(js_cocos2dx_spine_AnimationState_setTimeScale));
    cls->defineFunction(inst, "getTracks", _SE(js_cocos2dx_spine_AnimationState_getTracks));
    cls->defineFunction(inst, "clearTrack", _SE(js_cocos2dx_spine_AnimationState_clearTrack));
    cls->defineFunction(inst, "setAnimation", _SE(js_cocos2dx_spine_AnimationState_setAnimation));
    cls->defineFunction(inst, "addEmptyAnimation", _SE(js_cocos2dx_spine_AnimationState_addEmptyAnimation));
    cls->defineFunction(inst, "getTimeScale", _SE(js_cocos2dx_spine_AnimationState_getTimeScale));
    cls->install(inst);
    inst->registerClass<spine::AnimationState>(cls);

    __jsb_spine_AnimationState_proto = cls->getProto();
    __jsb_spine_AnimationState_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_AnimationStateData_proto = nullptr;
se::Class* __jsb_spine_AnimationStateData_class = nullptr;

static bool js_cocos2dx_spine_AnimationStateData_getMix(se::State &s, se::ScriptEngine *inst)
{
    spine::AnimationStateData* cobj = (spine::AnimationStateData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AnimationStateData_getMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        spine::Animation* arg0 = nullptr;
        spine::Animation* arg1 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationStateData_getMix : Error processing arguments");
        float result = cobj->getMix(arg0, arg1);
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationStateData_getMix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationStateData_getMix)

static bool js_cocos2dx_spine_AnimationStateData_getDefaultMix(se::State &s, se::ScriptEngine *inst)
{
    spine::AnimationStateData* cobj = (spine::AnimationStateData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AnimationStateData_getDefaultMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getDefaultMix();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationStateData_getDefaultMix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationStateData_getDefaultMix)

static bool js_cocos2dx_spine_AnimationStateData_setMix(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    spine::AnimationStateData* cobj = (spine::AnimationStateData*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_spine_AnimationStateData_setMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 3) {
            spine::Animation* arg0 = nullptr;
            ok &= seval_to_native_ptr(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            spine::Animation* arg1 = nullptr;
            ok &= seval_to_native_ptr(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            cobj->setMix(arg0, arg1, arg2);
            return true;
        }
    } while(false);

    do {
        if (argc == 3) {
            spine::String arg0;
            arg0 = args[0].toStringForce().c_str();
            if (!ok) { ok = true; break; }
            spine::String arg1;
            arg1 = args[1].toStringForce().c_str();
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            cobj->setMix(arg0, arg1, arg2);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationStateData_setMix)

static bool js_cocos2dx_spine_AnimationStateData_setDefaultMix(se::State &s, se::ScriptEngine *inst)
{
    spine::AnimationStateData* cobj = (spine::AnimationStateData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AnimationStateData_setDefaultMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationStateData_setDefaultMix : Error processing arguments");
        cobj->setDefaultMix(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationStateData_setDefaultMix)

static bool js_cocos2dx_spine_AnimationStateData_getSkeletonData(se::State &s, se::ScriptEngine *inst)
{
    spine::AnimationStateData* cobj = (spine::AnimationStateData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AnimationStateData_getSkeletonData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::SkeletonData* result = cobj->getSkeletonData();
        ok &= native_ptr_to_rooted_seval<spine::SkeletonData>(inst, (spine::SkeletonData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AnimationStateData_getSkeletonData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AnimationStateData_getSkeletonData)




bool js_register_cocos2dx_spine_AnimationStateData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "AnimationStateData", obj, nullptr, nullptr);

    cls->defineFunction(inst, "getMix", _SE(js_cocos2dx_spine_AnimationStateData_getMix));
    cls->defineFunction(inst, "getDefaultMix", _SE(js_cocos2dx_spine_AnimationStateData_getDefaultMix));
    cls->defineFunction(inst, "setMix", _SE(js_cocos2dx_spine_AnimationStateData_setMix));
    cls->defineFunction(inst, "setDefaultMix", _SE(js_cocos2dx_spine_AnimationStateData_setDefaultMix));
    cls->defineFunction(inst, "getSkeletonData", _SE(js_cocos2dx_spine_AnimationStateData_getSkeletonData));
    cls->install(inst);
    inst->registerClass<spine::AnimationStateData>(cls);

    __jsb_spine_AnimationStateData_proto = cls->getProto();
    __jsb_spine_AnimationStateData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_Attachment_proto = nullptr;
se::Class* __jsb_spine_Attachment_class = nullptr;

static bool js_cocos2dx_spine_Attachment_getRefCount(se::State &s, se::ScriptEngine *inst)
{
    spine::Attachment* cobj = (spine::Attachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Attachment_getRefCount : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getRefCount();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Attachment_getRefCount : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Attachment_getRefCount)

static bool js_cocos2dx_spine_Attachment_reference(se::State &s, se::ScriptEngine *inst)
{
    spine::Attachment* cobj = (spine::Attachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Attachment_reference : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->reference();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Attachment_reference)

static bool js_cocos2dx_spine_Attachment_getName(se::State &s, se::ScriptEngine *inst)
{
    spine::Attachment* cobj = (spine::Attachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Attachment_getName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getName();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Attachment_getName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Attachment_getName)

static bool js_cocos2dx_spine_Attachment_dereference(se::State &s, se::ScriptEngine *inst)
{
    spine::Attachment* cobj = (spine::Attachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Attachment_dereference : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->dereference();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Attachment_dereference)

static bool js_cocos2dx_spine_Attachment_copy(se::State &s, se::ScriptEngine *inst)
{
    spine::Attachment* cobj = (spine::Attachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Attachment_copy : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Attachment* result = cobj->copy();
        ok &= native_ptr_to_rooted_seval<spine::Attachment>(inst, (spine::Attachment*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Attachment_copy : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Attachment_copy)




bool js_register_cocos2dx_spine_Attachment(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Attachment", obj, nullptr, nullptr);

    cls->defineFunction(inst, "getRefCount", _SE(js_cocos2dx_spine_Attachment_getRefCount));
    cls->defineFunction(inst, "reference", _SE(js_cocos2dx_spine_Attachment_reference));
    cls->defineFunction(inst, "getName", _SE(js_cocos2dx_spine_Attachment_getName));
    cls->defineFunction(inst, "dereference", _SE(js_cocos2dx_spine_Attachment_dereference));
    cls->defineFunction(inst, "copy", _SE(js_cocos2dx_spine_Attachment_copy));
    cls->install(inst);
    inst->registerClass<spine::Attachment>(cls);

    __jsb_spine_Attachment_proto = cls->getProto();
    __jsb_spine_Attachment_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_Timeline_proto = nullptr;
se::Class* __jsb_spine_Timeline_class = nullptr;

static bool js_cocos2dx_spine_Timeline_getPropertyId(se::State &s, se::ScriptEngine *inst)
{
    spine::Timeline* cobj = (spine::Timeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Timeline_getPropertyId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPropertyId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Timeline_getPropertyId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Timeline_getPropertyId)




bool js_register_cocos2dx_spine_Timeline(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Timeline", obj, nullptr, nullptr);

    cls->defineFunction(inst, "getPropertyId", _SE(js_cocos2dx_spine_Timeline_getPropertyId));
    cls->install(inst);
    inst->registerClass<spine::Timeline>(cls);

    __jsb_spine_Timeline_proto = cls->getProto();
    __jsb_spine_Timeline_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_AttachmentTimeline_proto = nullptr;
se::Class* __jsb_spine_AttachmentTimeline_class = nullptr;

static bool js_cocos2dx_spine_AttachmentTimeline_getAttachmentNames(se::State &s, se::ScriptEngine *inst)
{
    spine::AttachmentTimeline* cobj = (spine::AttachmentTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AttachmentTimeline_getAttachmentNames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::Vector<spine::String>& result = cobj->getAttachmentNames();
        ok &= spine_Vector_String_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AttachmentTimeline_getAttachmentNames : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AttachmentTimeline_getAttachmentNames)

static bool js_cocos2dx_spine_AttachmentTimeline_setSlotIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::AttachmentTimeline* cobj = (spine::AttachmentTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AttachmentTimeline_setSlotIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        size_t arg0 = 0;
        ok &= seval_to_size(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AttachmentTimeline_setSlotIndex : Error processing arguments");
        cobj->setSlotIndex(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AttachmentTimeline_setSlotIndex)

static bool js_cocos2dx_spine_AttachmentTimeline_getPropertyId(se::State &s, se::ScriptEngine *inst)
{
    spine::AttachmentTimeline* cobj = (spine::AttachmentTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AttachmentTimeline_getPropertyId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPropertyId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AttachmentTimeline_getPropertyId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AttachmentTimeline_getPropertyId)

static bool js_cocos2dx_spine_AttachmentTimeline_setFrame(se::State &s, se::ScriptEngine *inst)
{
    spine::AttachmentTimeline* cobj = (spine::AttachmentTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AttachmentTimeline_setFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        int arg0 = 0;
        float arg1 = 0;
        spine::String arg2;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        ok &= seval_to_float(inst, args[1], &arg1);
        arg2 = args[2].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AttachmentTimeline_setFrame : Error processing arguments");
        cobj->setFrame(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AttachmentTimeline_setFrame)

static bool js_cocos2dx_spine_AttachmentTimeline_getSlotIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::AttachmentTimeline* cobj = (spine::AttachmentTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AttachmentTimeline_getSlotIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        size_t result = cobj->getSlotIndex();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AttachmentTimeline_getSlotIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AttachmentTimeline_getSlotIndex)

static bool js_cocos2dx_spine_AttachmentTimeline_getFrameCount(se::State &s, se::ScriptEngine *inst)
{
    spine::AttachmentTimeline* cobj = (spine::AttachmentTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AttachmentTimeline_getFrameCount : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        size_t result = cobj->getFrameCount();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AttachmentTimeline_getFrameCount : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AttachmentTimeline_getFrameCount)

static bool js_cocos2dx_spine_AttachmentTimeline_getFrames(se::State &s, se::ScriptEngine *inst)
{
    spine::AttachmentTimeline* cobj = (spine::AttachmentTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AttachmentTimeline_getFrames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::Vector<float>& result = cobj->getFrames();
        ok &= spine_Vector_T_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AttachmentTimeline_getFrames : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AttachmentTimeline_getFrames)


extern se::Object* __jsb_spine_Timeline_proto;


bool js_register_cocos2dx_spine_AttachmentTimeline(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "AttachmentTimeline", obj, __jsb_spine_Timeline_proto, nullptr);

    cls->defineFunction(inst, "getAttachmentNames", _SE(js_cocos2dx_spine_AttachmentTimeline_getAttachmentNames));
    cls->defineFunction(inst, "setSlotIndex", _SE(js_cocos2dx_spine_AttachmentTimeline_setSlotIndex));
    cls->defineFunction(inst, "getPropertyId", _SE(js_cocos2dx_spine_AttachmentTimeline_getPropertyId));
    cls->defineFunction(inst, "setFrame", _SE(js_cocos2dx_spine_AttachmentTimeline_setFrame));
    cls->defineFunction(inst, "getSlotIndex", _SE(js_cocos2dx_spine_AttachmentTimeline_getSlotIndex));
    cls->defineFunction(inst, "getFrameCount", _SE(js_cocos2dx_spine_AttachmentTimeline_getFrameCount));
    cls->defineFunction(inst, "getFrames", _SE(js_cocos2dx_spine_AttachmentTimeline_getFrames));
    cls->install(inst);
    inst->registerClass<spine::AttachmentTimeline>(cls);

    __jsb_spine_AttachmentTimeline_proto = cls->getProto();
    __jsb_spine_AttachmentTimeline_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_Bone_proto = nullptr;
se::Class* __jsb_spine_Bone_class = nullptr;

static bool js_cocos2dx_spine_Bone_setD(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setD : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setD : Error processing arguments");
        cobj->setD(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setD)

static bool js_cocos2dx_spine_Bone_setAppliedRotation(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setAppliedRotation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setAppliedRotation : Error processing arguments");
        cobj->setAppliedRotation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setAppliedRotation)

static bool js_cocos2dx_spine_Bone_setAScaleY(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setAScaleY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setAScaleY : Error processing arguments");
        cobj->setAScaleY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setAScaleY)

static bool js_cocos2dx_spine_Bone_setAScaleX(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setAScaleX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setAScaleX : Error processing arguments");
        cobj->setAScaleX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setAScaleX)

static bool js_cocos2dx_spine_Bone_getB(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getB : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getB();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getB : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getB)

static bool js_cocos2dx_spine_Bone_getC(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getC : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getC();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getC : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getC)

static bool js_cocos2dx_spine_Bone_getD(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getD : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getD();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getD : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getD)

static bool js_cocos2dx_spine_Bone_getWorldScaleY(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getWorldScaleY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getWorldScaleY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getWorldScaleY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getWorldScaleY)

static bool js_cocos2dx_spine_Bone_getX(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getX)

static bool js_cocos2dx_spine_Bone_getY(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getY)

static bool js_cocos2dx_spine_Bone_getChildren(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getChildren : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::Bone *>& result = cobj->getChildren();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getChildren : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getChildren)

static bool js_cocos2dx_spine_Bone_setWorldX(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setWorldX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setWorldX : Error processing arguments");
        cobj->setWorldX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setWorldX)

static bool js_cocos2dx_spine_Bone_setAppliedValid(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setAppliedValid : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setAppliedValid : Error processing arguments");
        cobj->setAppliedValid(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setAppliedValid)

static bool js_cocos2dx_spine_Bone_getRotation(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getRotation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRotation();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getRotation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getRotation)

static bool js_cocos2dx_spine_Bone_getAShearX(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getAShearX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getAShearX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getAShearX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getAShearX)

static bool js_cocos2dx_spine_Bone_getAShearY(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getAShearY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getAShearY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getAShearY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getAShearY)

static bool js_cocos2dx_spine_Bone_getWorldRotationY(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getWorldRotationY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getWorldRotationY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getWorldRotationY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getWorldRotationY)

static bool js_cocos2dx_spine_Bone_isAppliedValid(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_isAppliedValid : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isAppliedValid();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_isAppliedValid : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_isAppliedValid)

static bool js_cocos2dx_spine_Bone_getScaleY(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getScaleY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getScaleY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getScaleY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getScaleY)

static bool js_cocos2dx_spine_Bone_getScaleX(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getScaleX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getScaleX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getScaleX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getScaleX)

static bool js_cocos2dx_spine_Bone_setToSetupPose(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setToSetupPose : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->setToSetupPose();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setToSetupPose)

static bool js_cocos2dx_spine_Bone_getWorldToLocalRotationX(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getWorldToLocalRotationX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getWorldToLocalRotationX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getWorldToLocalRotationX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getWorldToLocalRotationX)

static bool js_cocos2dx_spine_Bone_getWorldToLocalRotationY(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getWorldToLocalRotationY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getWorldToLocalRotationY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getWorldToLocalRotationY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getWorldToLocalRotationY)

static bool js_cocos2dx_spine_Bone_getAScaleX(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getAScaleX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getAScaleX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getAScaleX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getAScaleX)

static bool js_cocos2dx_spine_Bone_getA(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getA : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getA();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getA : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getA)

static bool js_cocos2dx_spine_Bone_setRotation(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setRotation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setRotation : Error processing arguments");
        cobj->setRotation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setRotation)

static bool js_cocos2dx_spine_Bone_getAX(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getAX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getAX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getAX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getAX)

static bool js_cocos2dx_spine_Bone_getData(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::BoneData& result = cobj->getData();
        ok &= native_ptr_to_rooted_seval<spine::BoneData>(inst, (spine::BoneData*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getData)

static bool js_cocos2dx_spine_Bone_setShearX(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setShearX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setShearX : Error processing arguments");
        cobj->setShearX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setShearX)

static bool js_cocos2dx_spine_Bone_setShearY(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setShearY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setShearY : Error processing arguments");
        cobj->setShearY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setShearY)

static bool js_cocos2dx_spine_Bone_setScaleY(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setScaleY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setScaleY : Error processing arguments");
        cobj->setScaleY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setScaleY)

static bool js_cocos2dx_spine_Bone_setScaleX(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setScaleX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setScaleX : Error processing arguments");
        cobj->setScaleX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setScaleX)

static bool js_cocos2dx_spine_Bone_setA(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setA : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setA : Error processing arguments");
        cobj->setA(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setA)

static bool js_cocos2dx_spine_Bone_setB(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setB : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setB : Error processing arguments");
        cobj->setB(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setB)

static bool js_cocos2dx_spine_Bone_getAScaleY(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getAScaleY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getAScaleY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getAScaleY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getAScaleY)

static bool js_cocos2dx_spine_Bone_getWorldScaleX(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getWorldScaleX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getWorldScaleX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getWorldScaleX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getWorldScaleX)

static bool js_cocos2dx_spine_Bone_getWorldRotationX(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getWorldRotationX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getWorldRotationX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getWorldRotationX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getWorldRotationX)

static bool js_cocos2dx_spine_Bone_getShearX(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getShearX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getShearX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getShearX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getShearX)

static bool js_cocos2dx_spine_Bone_update(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_update : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->update();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_update)

static bool js_cocos2dx_spine_Bone_getShearY(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getShearY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getShearY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getShearY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getShearY)

static bool js_cocos2dx_spine_Bone_setAShearX(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setAShearX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setAShearX : Error processing arguments");
        cobj->setAShearX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setAShearX)

static bool js_cocos2dx_spine_Bone_setAShearY(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setAShearY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setAShearY : Error processing arguments");
        cobj->setAShearY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setAShearY)

static bool js_cocos2dx_spine_Bone_setActive(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setActive : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setActive : Error processing arguments");
        cobj->setActive(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setActive)

static bool js_cocos2dx_spine_Bone_setC(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setC : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setC : Error processing arguments");
        cobj->setC(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setC)

static bool js_cocos2dx_spine_Bone_setWorldY(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setWorldY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setWorldY : Error processing arguments");
        cobj->setWorldY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setWorldY)

static bool js_cocos2dx_spine_Bone_setX(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setX : Error processing arguments");
        cobj->setX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setX)

static bool js_cocos2dx_spine_Bone_setY(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setY : Error processing arguments");
        cobj->setY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setY)

static bool js_cocos2dx_spine_Bone_setAX(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setAX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setAX : Error processing arguments");
        cobj->setAX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setAX)

static bool js_cocos2dx_spine_Bone_setAY(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_setAY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setAY : Error processing arguments");
        cobj->setAY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setAY)

static bool js_cocos2dx_spine_Bone_isActive(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_isActive : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isActive();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_isActive : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_isActive)

static bool js_cocos2dx_spine_Bone_getAY(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getAY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getAY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getAY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getAY)

static bool js_cocos2dx_spine_Bone_rotateWorld(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_rotateWorld : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_rotateWorld : Error processing arguments");
        cobj->rotateWorld(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_rotateWorld)

static bool js_cocos2dx_spine_Bone_getParent(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getParent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Bone* result = cobj->getParent();
        ok &= native_ptr_to_rooted_seval<spine::Bone>(inst, (spine::Bone*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getParent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getParent)

static bool js_cocos2dx_spine_Bone_getAppliedRotation(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getAppliedRotation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getAppliedRotation();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getAppliedRotation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getAppliedRotation)

static bool js_cocos2dx_spine_Bone_updateWorldTransform(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_spine_Bone_updateWorldTransform : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 7) {
            float arg0 = 0;
            ok &= seval_to_float(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            float arg1 = 0;
            ok &= seval_to_float(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            float arg3 = 0;
            ok &= seval_to_float(inst, args[3], &arg3);
            if (!ok) { ok = true; break; }
            float arg4 = 0;
            ok &= seval_to_float(inst, args[4], &arg4);
            if (!ok) { ok = true; break; }
            float arg5 = 0;
            ok &= seval_to_float(inst, args[5], &arg5);
            if (!ok) { ok = true; break; }
            float arg6 = 0;
            ok &= seval_to_float(inst, args[6], &arg6);
            if (!ok) { ok = true; break; }
            cobj->updateWorldTransform(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
            return true;
        }
    } while(false);

    do {
        if (argc == 0) {
            cobj->updateWorldTransform();
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_updateWorldTransform)

static bool js_cocos2dx_spine_Bone_getWorldY(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getWorldY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getWorldY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getWorldY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getWorldY)

static bool js_cocos2dx_spine_Bone_getWorldX(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getWorldX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getWorldX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getWorldX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getWorldX)

static bool js_cocos2dx_spine_Bone_getSkeleton(se::State &s, se::ScriptEngine *inst)
{
    spine::Bone* cobj = (spine::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Bone_getSkeleton : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Skeleton& result = cobj->getSkeleton();
        ok &= native_ptr_to_rooted_seval<spine::Skeleton>(inst, (spine::Skeleton*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_getSkeleton : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_getSkeleton)

static bool js_cocos2dx_spine_Bone_isYDown(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = spine::Bone::isYDown();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_isYDown : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_isYDown)

static bool js_cocos2dx_spine_Bone_setYDown(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Bone_setYDown : Error processing arguments");
        spine::Bone::setYDown(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Bone_setYDown)




bool js_register_cocos2dx_spine_Bone(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Bone", obj, nullptr, nullptr);

    cls->defineFunction(inst, "setD", _SE(js_cocos2dx_spine_Bone_setD));
    cls->defineFunction(inst, "setAppliedRotation", _SE(js_cocos2dx_spine_Bone_setAppliedRotation));
    cls->defineFunction(inst, "setAScaleY", _SE(js_cocos2dx_spine_Bone_setAScaleY));
    cls->defineFunction(inst, "setAScaleX", _SE(js_cocos2dx_spine_Bone_setAScaleX));
    cls->defineFunction(inst, "getB", _SE(js_cocos2dx_spine_Bone_getB));
    cls->defineFunction(inst, "getC", _SE(js_cocos2dx_spine_Bone_getC));
    cls->defineFunction(inst, "getD", _SE(js_cocos2dx_spine_Bone_getD));
    cls->defineFunction(inst, "getWorldScaleY", _SE(js_cocos2dx_spine_Bone_getWorldScaleY));
    cls->defineFunction(inst, "getX", _SE(js_cocos2dx_spine_Bone_getX));
    cls->defineFunction(inst, "getY", _SE(js_cocos2dx_spine_Bone_getY));
    cls->defineFunction(inst, "getChildren", _SE(js_cocos2dx_spine_Bone_getChildren));
    cls->defineFunction(inst, "setWorldX", _SE(js_cocos2dx_spine_Bone_setWorldX));
    cls->defineFunction(inst, "setAppliedValid", _SE(js_cocos2dx_spine_Bone_setAppliedValid));
    cls->defineFunction(inst, "getRotation", _SE(js_cocos2dx_spine_Bone_getRotation));
    cls->defineFunction(inst, "getAShearX", _SE(js_cocos2dx_spine_Bone_getAShearX));
    cls->defineFunction(inst, "getAShearY", _SE(js_cocos2dx_spine_Bone_getAShearY));
    cls->defineFunction(inst, "getWorldRotationY", _SE(js_cocos2dx_spine_Bone_getWorldRotationY));
    cls->defineFunction(inst, "isAppliedValid", _SE(js_cocos2dx_spine_Bone_isAppliedValid));
    cls->defineFunction(inst, "getScaleY", _SE(js_cocos2dx_spine_Bone_getScaleY));
    cls->defineFunction(inst, "getScaleX", _SE(js_cocos2dx_spine_Bone_getScaleX));
    cls->defineFunction(inst, "setToSetupPose", _SE(js_cocos2dx_spine_Bone_setToSetupPose));
    cls->defineFunction(inst, "getWorldToLocalRotationX", _SE(js_cocos2dx_spine_Bone_getWorldToLocalRotationX));
    cls->defineFunction(inst, "getWorldToLocalRotationY", _SE(js_cocos2dx_spine_Bone_getWorldToLocalRotationY));
    cls->defineFunction(inst, "getAScaleX", _SE(js_cocos2dx_spine_Bone_getAScaleX));
    cls->defineFunction(inst, "getA", _SE(js_cocos2dx_spine_Bone_getA));
    cls->defineFunction(inst, "setRotation", _SE(js_cocos2dx_spine_Bone_setRotation));
    cls->defineFunction(inst, "getAX", _SE(js_cocos2dx_spine_Bone_getAX));
    cls->defineFunction(inst, "getData", _SE(js_cocos2dx_spine_Bone_getData));
    cls->defineFunction(inst, "setShearX", _SE(js_cocos2dx_spine_Bone_setShearX));
    cls->defineFunction(inst, "setShearY", _SE(js_cocos2dx_spine_Bone_setShearY));
    cls->defineFunction(inst, "setScaleY", _SE(js_cocos2dx_spine_Bone_setScaleY));
    cls->defineFunction(inst, "setScaleX", _SE(js_cocos2dx_spine_Bone_setScaleX));
    cls->defineFunction(inst, "setA", _SE(js_cocos2dx_spine_Bone_setA));
    cls->defineFunction(inst, "setB", _SE(js_cocos2dx_spine_Bone_setB));
    cls->defineFunction(inst, "getAScaleY", _SE(js_cocos2dx_spine_Bone_getAScaleY));
    cls->defineFunction(inst, "getWorldScaleX", _SE(js_cocos2dx_spine_Bone_getWorldScaleX));
    cls->defineFunction(inst, "getWorldRotationX", _SE(js_cocos2dx_spine_Bone_getWorldRotationX));
    cls->defineFunction(inst, "getShearX", _SE(js_cocos2dx_spine_Bone_getShearX));
    cls->defineFunction(inst, "update", _SE(js_cocos2dx_spine_Bone_update));
    cls->defineFunction(inst, "getShearY", _SE(js_cocos2dx_spine_Bone_getShearY));
    cls->defineFunction(inst, "setAShearX", _SE(js_cocos2dx_spine_Bone_setAShearX));
    cls->defineFunction(inst, "setAShearY", _SE(js_cocos2dx_spine_Bone_setAShearY));
    cls->defineFunction(inst, "setActive", _SE(js_cocos2dx_spine_Bone_setActive));
    cls->defineFunction(inst, "setC", _SE(js_cocos2dx_spine_Bone_setC));
    cls->defineFunction(inst, "setWorldY", _SE(js_cocos2dx_spine_Bone_setWorldY));
    cls->defineFunction(inst, "setX", _SE(js_cocos2dx_spine_Bone_setX));
    cls->defineFunction(inst, "setY", _SE(js_cocos2dx_spine_Bone_setY));
    cls->defineFunction(inst, "setAX", _SE(js_cocos2dx_spine_Bone_setAX));
    cls->defineFunction(inst, "setAY", _SE(js_cocos2dx_spine_Bone_setAY));
    cls->defineFunction(inst, "isActive", _SE(js_cocos2dx_spine_Bone_isActive));
    cls->defineFunction(inst, "getAY", _SE(js_cocos2dx_spine_Bone_getAY));
    cls->defineFunction(inst, "rotateWorld", _SE(js_cocos2dx_spine_Bone_rotateWorld));
    cls->defineFunction(inst, "getParent", _SE(js_cocos2dx_spine_Bone_getParent));
    cls->defineFunction(inst, "getAppliedRotation", _SE(js_cocos2dx_spine_Bone_getAppliedRotation));
    cls->defineFunction(inst, "updateWorldTransform", _SE(js_cocos2dx_spine_Bone_updateWorldTransform));
    cls->defineFunction(inst, "getWorldY", _SE(js_cocos2dx_spine_Bone_getWorldY));
    cls->defineFunction(inst, "getWorldX", _SE(js_cocos2dx_spine_Bone_getWorldX));
    cls->defineFunction(inst, "getSkeleton", _SE(js_cocos2dx_spine_Bone_getSkeleton));
    cls->defineStaticFunction(inst, "isYDown", _SE(js_cocos2dx_spine_Bone_isYDown));
    cls->defineStaticFunction(inst, "setYDown", _SE(js_cocos2dx_spine_Bone_setYDown));
    cls->install(inst);
    inst->registerClass<spine::Bone>(cls);

    __jsb_spine_Bone_proto = cls->getProto();
    __jsb_spine_Bone_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_BoneData_proto = nullptr;
se::Class* __jsb_spine_BoneData_class = nullptr;

static bool js_cocos2dx_spine_BoneData_getX(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_getX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_getX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_getX)

static bool js_cocos2dx_spine_BoneData_getY(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_getY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_getY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_getY)

static bool js_cocos2dx_spine_BoneData_getRotation(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_getRotation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRotation();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_getRotation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_getRotation)

static bool js_cocos2dx_spine_BoneData_isSkinRequired(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_isSkinRequired : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isSkinRequired();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_isSkinRequired : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_isSkinRequired)

static bool js_cocos2dx_spine_BoneData_getIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_getIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getIndex();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_getIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_getIndex)

static bool js_cocos2dx_spine_BoneData_getScaleY(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_getScaleY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getScaleY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_getScaleY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_getScaleY)

static bool js_cocos2dx_spine_BoneData_getScaleX(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_getScaleX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getScaleX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_getScaleX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_getScaleX)

static bool js_cocos2dx_spine_BoneData_getLength(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_getLength : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getLength();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_getLength : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_getLength)

static bool js_cocos2dx_spine_BoneData_getName(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_getName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getName();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_getName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_getName)

static bool js_cocos2dx_spine_BoneData_setLength(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_setLength : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_setLength : Error processing arguments");
        cobj->setLength(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_setLength)

static bool js_cocos2dx_spine_BoneData_setRotation(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_setRotation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_setRotation : Error processing arguments");
        cobj->setRotation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_setRotation)

static bool js_cocos2dx_spine_BoneData_setShearX(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_setShearX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_setShearX : Error processing arguments");
        cobj->setShearX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_setShearX)

static bool js_cocos2dx_spine_BoneData_setShearY(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_setShearY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_setShearY : Error processing arguments");
        cobj->setShearY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_setShearY)

static bool js_cocos2dx_spine_BoneData_setScaleY(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_setScaleY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_setScaleY : Error processing arguments");
        cobj->setScaleY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_setScaleY)

static bool js_cocos2dx_spine_BoneData_setScaleX(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_setScaleX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_setScaleX : Error processing arguments");
        cobj->setScaleX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_setScaleX)

static bool js_cocos2dx_spine_BoneData_getShearX(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_getShearX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getShearX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_getShearX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_getShearX)

static bool js_cocos2dx_spine_BoneData_getShearY(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_getShearY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getShearY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_getShearY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_getShearY)

static bool js_cocos2dx_spine_BoneData_setX(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_setX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_setX : Error processing arguments");
        cobj->setX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_setX)

static bool js_cocos2dx_spine_BoneData_setY(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_setY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_setY : Error processing arguments");
        cobj->setY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_setY)

static bool js_cocos2dx_spine_BoneData_setSkinRequired(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_setSkinRequired : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_setSkinRequired : Error processing arguments");
        cobj->setSkinRequired(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_setSkinRequired)

static bool js_cocos2dx_spine_BoneData_getParent(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_getParent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::BoneData* result = cobj->getParent();
        ok &= native_ptr_to_rooted_seval<spine::BoneData>(inst, (spine::BoneData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_getParent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_getParent)

static bool js_cocos2dx_spine_BoneData_getTransformMode(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_getTransformMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = (unsigned int)cobj->getTransformMode();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_getTransformMode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_getTransformMode)

static bool js_cocos2dx_spine_BoneData_setTransformMode(se::State &s, se::ScriptEngine *inst)
{
    spine::BoneData* cobj = (spine::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoneData_setTransformMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::TransformMode arg0;
        ok &= seval_to_uint32(inst, args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoneData_setTransformMode : Error processing arguments");
        cobj->setTransformMode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoneData_setTransformMode)




bool js_register_cocos2dx_spine_BoneData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "BoneData", obj, nullptr, nullptr);

    cls->defineFunction(inst, "getX", _SE(js_cocos2dx_spine_BoneData_getX));
    cls->defineFunction(inst, "getY", _SE(js_cocos2dx_spine_BoneData_getY));
    cls->defineFunction(inst, "getRotation", _SE(js_cocos2dx_spine_BoneData_getRotation));
    cls->defineFunction(inst, "isSkinRequired", _SE(js_cocos2dx_spine_BoneData_isSkinRequired));
    cls->defineFunction(inst, "getIndex", _SE(js_cocos2dx_spine_BoneData_getIndex));
    cls->defineFunction(inst, "getScaleY", _SE(js_cocos2dx_spine_BoneData_getScaleY));
    cls->defineFunction(inst, "getScaleX", _SE(js_cocos2dx_spine_BoneData_getScaleX));
    cls->defineFunction(inst, "getLength", _SE(js_cocos2dx_spine_BoneData_getLength));
    cls->defineFunction(inst, "getName", _SE(js_cocos2dx_spine_BoneData_getName));
    cls->defineFunction(inst, "setLength", _SE(js_cocos2dx_spine_BoneData_setLength));
    cls->defineFunction(inst, "setRotation", _SE(js_cocos2dx_spine_BoneData_setRotation));
    cls->defineFunction(inst, "setShearX", _SE(js_cocos2dx_spine_BoneData_setShearX));
    cls->defineFunction(inst, "setShearY", _SE(js_cocos2dx_spine_BoneData_setShearY));
    cls->defineFunction(inst, "setScaleY", _SE(js_cocos2dx_spine_BoneData_setScaleY));
    cls->defineFunction(inst, "setScaleX", _SE(js_cocos2dx_spine_BoneData_setScaleX));
    cls->defineFunction(inst, "getShearX", _SE(js_cocos2dx_spine_BoneData_getShearX));
    cls->defineFunction(inst, "getShearY", _SE(js_cocos2dx_spine_BoneData_getShearY));
    cls->defineFunction(inst, "setX", _SE(js_cocos2dx_spine_BoneData_setX));
    cls->defineFunction(inst, "setY", _SE(js_cocos2dx_spine_BoneData_setY));
    cls->defineFunction(inst, "setSkinRequired", _SE(js_cocos2dx_spine_BoneData_setSkinRequired));
    cls->defineFunction(inst, "getParent", _SE(js_cocos2dx_spine_BoneData_getParent));
    cls->defineFunction(inst, "getTransformMode", _SE(js_cocos2dx_spine_BoneData_getTransformMode));
    cls->defineFunction(inst, "setTransformMode", _SE(js_cocos2dx_spine_BoneData_setTransformMode));
    cls->install(inst);
    inst->registerClass<spine::BoneData>(cls);

    __jsb_spine_BoneData_proto = cls->getProto();
    __jsb_spine_BoneData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_VertexAttachment_proto = nullptr;
se::Class* __jsb_spine_VertexAttachment_class = nullptr;

static bool js_cocos2dx_spine_VertexAttachment_getVertices(se::State &s, se::ScriptEngine *inst)
{
    spine::VertexAttachment* cobj = (spine::VertexAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_VertexAttachment_getVertices : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<float>& result = cobj->getVertices();
        ok &= spine_Vector_T_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_VertexAttachment_getVertices : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_VertexAttachment_getVertices)

static bool js_cocos2dx_spine_VertexAttachment_getDeformAttachment(se::State &s, se::ScriptEngine *inst)
{
    spine::VertexAttachment* cobj = (spine::VertexAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_VertexAttachment_getDeformAttachment : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::VertexAttachment* result = cobj->getDeformAttachment();
        ok &= native_ptr_to_rooted_seval<spine::VertexAttachment>(inst, (spine::VertexAttachment*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_VertexAttachment_getDeformAttachment : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_VertexAttachment_getDeformAttachment)

static bool js_cocos2dx_spine_VertexAttachment_getId(se::State &s, se::ScriptEngine *inst)
{
    spine::VertexAttachment* cobj = (spine::VertexAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_VertexAttachment_getId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_VertexAttachment_getId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_VertexAttachment_getId)

static bool js_cocos2dx_spine_VertexAttachment_copyTo(se::State &s, se::ScriptEngine *inst)
{
    spine::VertexAttachment* cobj = (spine::VertexAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_VertexAttachment_copyTo : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::VertexAttachment* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_VertexAttachment_copyTo : Error processing arguments");
        cobj->copyTo(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_VertexAttachment_copyTo)

static bool js_cocos2dx_spine_VertexAttachment_setDeformAttachment(se::State &s, se::ScriptEngine *inst)
{
    spine::VertexAttachment* cobj = (spine::VertexAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_VertexAttachment_setDeformAttachment : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::VertexAttachment* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_VertexAttachment_setDeformAttachment : Error processing arguments");
        cobj->setDeformAttachment(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_VertexAttachment_setDeformAttachment)

static bool js_cocos2dx_spine_VertexAttachment_getWorldVerticesLength(se::State &s, se::ScriptEngine *inst)
{
    spine::VertexAttachment* cobj = (spine::VertexAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_VertexAttachment_getWorldVerticesLength : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        size_t result = cobj->getWorldVerticesLength();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_VertexAttachment_getWorldVerticesLength : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_VertexAttachment_getWorldVerticesLength)

static bool js_cocos2dx_spine_VertexAttachment_setWorldVerticesLength(se::State &s, se::ScriptEngine *inst)
{
    spine::VertexAttachment* cobj = (spine::VertexAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_VertexAttachment_setWorldVerticesLength : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        size_t arg0 = 0;
        ok &= seval_to_size(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_VertexAttachment_setWorldVerticesLength : Error processing arguments");
        cobj->setWorldVerticesLength(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_VertexAttachment_setWorldVerticesLength)


extern se::Object* __jsb_spine_Attachment_proto;


bool js_register_cocos2dx_spine_VertexAttachment(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "VertexAttachment", obj, __jsb_spine_Attachment_proto, nullptr);

    cls->defineFunction(inst, "getVertices", _SE(js_cocos2dx_spine_VertexAttachment_getVertices));
    cls->defineFunction(inst, "getDeformAttachment", _SE(js_cocos2dx_spine_VertexAttachment_getDeformAttachment));
    cls->defineFunction(inst, "getId", _SE(js_cocos2dx_spine_VertexAttachment_getId));
    cls->defineFunction(inst, "copyTo", _SE(js_cocos2dx_spine_VertexAttachment_copyTo));
    cls->defineFunction(inst, "setDeformAttachment", _SE(js_cocos2dx_spine_VertexAttachment_setDeformAttachment));
    cls->defineFunction(inst, "getWorldVerticesLength", _SE(js_cocos2dx_spine_VertexAttachment_getWorldVerticesLength));
    cls->defineFunction(inst, "setWorldVerticesLength", _SE(js_cocos2dx_spine_VertexAttachment_setWorldVerticesLength));
    cls->install(inst);
    inst->registerClass<spine::VertexAttachment>(cls);

    __jsb_spine_VertexAttachment_proto = cls->getProto();
    __jsb_spine_VertexAttachment_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_BoundingBoxAttachment_proto = nullptr;
se::Class* __jsb_spine_BoundingBoxAttachment_class = nullptr;

static bool js_cocos2dx_spine_BoundingBoxAttachment_copy(se::State &s, se::ScriptEngine *inst)
{
    spine::BoundingBoxAttachment* cobj = (spine::BoundingBoxAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_BoundingBoxAttachment_copy : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Attachment* result = cobj->copy();
        ok &= native_ptr_to_rooted_seval<spine::Attachment>(inst, (spine::Attachment*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_BoundingBoxAttachment_copy : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_BoundingBoxAttachment_copy)


extern se::Object* __jsb_spine_VertexAttachment_proto;


bool js_register_cocos2dx_spine_BoundingBoxAttachment(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "BoundingBoxAttachment", obj, __jsb_spine_VertexAttachment_proto, nullptr);

    cls->defineFunction(inst, "copy", _SE(js_cocos2dx_spine_BoundingBoxAttachment_copy));
    cls->install(inst);
    inst->registerClass<spine::BoundingBoxAttachment>(cls);

    __jsb_spine_BoundingBoxAttachment_proto = cls->getProto();
    __jsb_spine_BoundingBoxAttachment_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_ClippingAttachment_proto = nullptr;
se::Class* __jsb_spine_ClippingAttachment_class = nullptr;

static bool js_cocos2dx_spine_ClippingAttachment_setEndSlot(se::State &s, se::ScriptEngine *inst)
{
    spine::ClippingAttachment* cobj = (spine::ClippingAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_ClippingAttachment_setEndSlot : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::SlotData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_ClippingAttachment_setEndSlot : Error processing arguments");
        cobj->setEndSlot(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_ClippingAttachment_setEndSlot)

static bool js_cocos2dx_spine_ClippingAttachment_copy(se::State &s, se::ScriptEngine *inst)
{
    spine::ClippingAttachment* cobj = (spine::ClippingAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_ClippingAttachment_copy : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Attachment* result = cobj->copy();
        ok &= native_ptr_to_rooted_seval<spine::Attachment>(inst, (spine::Attachment*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_ClippingAttachment_copy : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_ClippingAttachment_copy)

static bool js_cocos2dx_spine_ClippingAttachment_getEndSlot(se::State &s, se::ScriptEngine *inst)
{
    spine::ClippingAttachment* cobj = (spine::ClippingAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_ClippingAttachment_getEndSlot : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::SlotData* result = cobj->getEndSlot();
        ok &= native_ptr_to_rooted_seval<spine::SlotData>(inst, (spine::SlotData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_ClippingAttachment_getEndSlot : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_ClippingAttachment_getEndSlot)


extern se::Object* __jsb_spine_VertexAttachment_proto;


bool js_register_cocos2dx_spine_ClippingAttachment(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "ClippingAttachment", obj, __jsb_spine_VertexAttachment_proto, nullptr);

    cls->defineFunction(inst, "setEndSlot", _SE(js_cocos2dx_spine_ClippingAttachment_setEndSlot));
    cls->defineFunction(inst, "copy", _SE(js_cocos2dx_spine_ClippingAttachment_copy));
    cls->defineFunction(inst, "getEndSlot", _SE(js_cocos2dx_spine_ClippingAttachment_getEndSlot));
    cls->install(inst);
    inst->registerClass<spine::ClippingAttachment>(cls);

    __jsb_spine_ClippingAttachment_proto = cls->getProto();
    __jsb_spine_ClippingAttachment_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_Color_proto = nullptr;
se::Class* __jsb_spine_Color_class = nullptr;

static bool js_cocos2dx_spine_Color_clamp(se::State &s, se::ScriptEngine *inst)
{
    spine::Color* cobj = (spine::Color*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Color_clamp : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Color& result = cobj->clamp();
        ok &= native_ptr_to_rooted_seval<spine::Color>(inst, (spine::Color*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Color_clamp : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Color_clamp)

static bool js_cocos2dx_spine_Color_get_r(se::State &s, se::ScriptEngine *inst)
{
    spine::Color* cobj = (spine::Color*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Color_get_r : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->r, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_spine_Color_get_r)

static bool js_cocos2dx_spine_Color_set_r(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    spine::Color* cobj = (spine::Color*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Color_set_r : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Color_set_r : Error processing new value");
    cobj->r = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_spine_Color_set_r)

static bool js_cocos2dx_spine_Color_get_g(se::State &s, se::ScriptEngine *inst)
{
    spine::Color* cobj = (spine::Color*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Color_get_g : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->g, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_spine_Color_get_g)

static bool js_cocos2dx_spine_Color_set_g(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    spine::Color* cobj = (spine::Color*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Color_set_g : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Color_set_g : Error processing new value");
    cobj->g = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_spine_Color_set_g)

static bool js_cocos2dx_spine_Color_get_b(se::State &s, se::ScriptEngine *inst)
{
    spine::Color* cobj = (spine::Color*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Color_get_b : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->b, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_spine_Color_get_b)

static bool js_cocos2dx_spine_Color_set_b(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    spine::Color* cobj = (spine::Color*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Color_set_b : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Color_set_b : Error processing new value");
    cobj->b = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_spine_Color_set_b)

static bool js_cocos2dx_spine_Color_get_a(se::State &s, se::ScriptEngine *inst)
{
    spine::Color* cobj = (spine::Color*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Color_get_a : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->a, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_spine_Color_get_a)

static bool js_cocos2dx_spine_Color_set_a(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    spine::Color* cobj = (spine::Color*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Color_set_a : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Color_set_a : Error processing new value");
    cobj->a = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_spine_Color_set_a)




bool js_register_cocos2dx_spine_Color(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Color", obj, nullptr, nullptr);

    cls->defineProperty(inst, "r", _SE(js_cocos2dx_spine_Color_get_r), _SE(js_cocos2dx_spine_Color_set_r));
    cls->defineProperty(inst, "g", _SE(js_cocos2dx_spine_Color_get_g), _SE(js_cocos2dx_spine_Color_set_g));
    cls->defineProperty(inst, "b", _SE(js_cocos2dx_spine_Color_get_b), _SE(js_cocos2dx_spine_Color_set_b));
    cls->defineProperty(inst, "a", _SE(js_cocos2dx_spine_Color_get_a), _SE(js_cocos2dx_spine_Color_set_a));
    cls->defineFunction(inst, "clamp", _SE(js_cocos2dx_spine_Color_clamp));
    cls->install(inst);
    inst->registerClass<spine::Color>(cls);

    __jsb_spine_Color_proto = cls->getProto();
    __jsb_spine_Color_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_CurveTimeline_proto = nullptr;
se::Class* __jsb_spine_CurveTimeline_class = nullptr;

static bool js_cocos2dx_spine_CurveTimeline_setCurve(se::State &s, se::ScriptEngine *inst)
{
    spine::CurveTimeline* cobj = (spine::CurveTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_CurveTimeline_setCurve : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 5) {
        size_t arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        ok &= seval_to_size(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_float(inst, args[4], &arg4);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_CurveTimeline_setCurve : Error processing arguments");
        cobj->setCurve(arg0, arg1, arg2, arg3, arg4);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_CurveTimeline_setCurve)

static bool js_cocos2dx_spine_CurveTimeline_getPropertyId(se::State &s, se::ScriptEngine *inst)
{
    spine::CurveTimeline* cobj = (spine::CurveTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_CurveTimeline_getPropertyId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPropertyId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_CurveTimeline_getPropertyId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_CurveTimeline_getPropertyId)

static bool js_cocos2dx_spine_CurveTimeline_setLinear(se::State &s, se::ScriptEngine *inst)
{
    spine::CurveTimeline* cobj = (spine::CurveTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_CurveTimeline_setLinear : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        size_t arg0 = 0;
        ok &= seval_to_size(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_CurveTimeline_setLinear : Error processing arguments");
        cobj->setLinear(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_CurveTimeline_setLinear)

static bool js_cocos2dx_spine_CurveTimeline_getFrameCount(se::State &s, se::ScriptEngine *inst)
{
    spine::CurveTimeline* cobj = (spine::CurveTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_CurveTimeline_getFrameCount : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        size_t result = cobj->getFrameCount();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_CurveTimeline_getFrameCount : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_CurveTimeline_getFrameCount)

static bool js_cocos2dx_spine_CurveTimeline_setStepped(se::State &s, se::ScriptEngine *inst)
{
    spine::CurveTimeline* cobj = (spine::CurveTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_CurveTimeline_setStepped : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        size_t arg0 = 0;
        ok &= seval_to_size(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_CurveTimeline_setStepped : Error processing arguments");
        cobj->setStepped(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_CurveTimeline_setStepped)

static bool js_cocos2dx_spine_CurveTimeline_getCurvePercent(se::State &s, se::ScriptEngine *inst)
{
    spine::CurveTimeline* cobj = (spine::CurveTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_CurveTimeline_getCurvePercent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        size_t arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_size(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_CurveTimeline_getCurvePercent : Error processing arguments");
        float result = cobj->getCurvePercent(arg0, arg1);
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_CurveTimeline_getCurvePercent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_CurveTimeline_getCurvePercent)

static bool js_cocos2dx_spine_CurveTimeline_getCurveType(se::State &s, se::ScriptEngine *inst)
{
    spine::CurveTimeline* cobj = (spine::CurveTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_CurveTimeline_getCurveType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        size_t arg0 = 0;
        ok &= seval_to_size(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_CurveTimeline_getCurveType : Error processing arguments");
        float result = cobj->getCurveType(arg0);
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_CurveTimeline_getCurveType : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_CurveTimeline_getCurveType)


extern se::Object* __jsb_spine_Timeline_proto;


bool js_register_cocos2dx_spine_CurveTimeline(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "CurveTimeline", obj, __jsb_spine_Timeline_proto, nullptr);

    cls->defineFunction(inst, "setCurve", _SE(js_cocos2dx_spine_CurveTimeline_setCurve));
    cls->defineFunction(inst, "getPropertyId", _SE(js_cocos2dx_spine_CurveTimeline_getPropertyId));
    cls->defineFunction(inst, "setLinear", _SE(js_cocos2dx_spine_CurveTimeline_setLinear));
    cls->defineFunction(inst, "getFrameCount", _SE(js_cocos2dx_spine_CurveTimeline_getFrameCount));
    cls->defineFunction(inst, "setStepped", _SE(js_cocos2dx_spine_CurveTimeline_setStepped));
    cls->defineFunction(inst, "getCurvePercent", _SE(js_cocos2dx_spine_CurveTimeline_getCurvePercent));
    cls->defineFunction(inst, "getCurveType", _SE(js_cocos2dx_spine_CurveTimeline_getCurveType));
    cls->install(inst);
    inst->registerClass<spine::CurveTimeline>(cls);

    __jsb_spine_CurveTimeline_proto = cls->getProto();
    __jsb_spine_CurveTimeline_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_ColorTimeline_proto = nullptr;
se::Class* __jsb_spine_ColorTimeline_class = nullptr;

static bool js_cocos2dx_spine_ColorTimeline_setSlotIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::ColorTimeline* cobj = (spine::ColorTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_ColorTimeline_setSlotIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_ColorTimeline_setSlotIndex : Error processing arguments");
        cobj->setSlotIndex(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_ColorTimeline_setSlotIndex)

static bool js_cocos2dx_spine_ColorTimeline_getPropertyId(se::State &s, se::ScriptEngine *inst)
{
    spine::ColorTimeline* cobj = (spine::ColorTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_ColorTimeline_getPropertyId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPropertyId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_ColorTimeline_getPropertyId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_ColorTimeline_getPropertyId)

static bool js_cocos2dx_spine_ColorTimeline_setFrame(se::State &s, se::ScriptEngine *inst)
{
    spine::ColorTimeline* cobj = (spine::ColorTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_ColorTimeline_setFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 6) {
        int arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        float arg5 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_float(inst, args[4], &arg4);
        ok &= seval_to_float(inst, args[5], &arg5);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_ColorTimeline_setFrame : Error processing arguments");
        cobj->setFrame(arg0, arg1, arg2, arg3, arg4, arg5);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 6);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_ColorTimeline_setFrame)

static bool js_cocos2dx_spine_ColorTimeline_getSlotIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::ColorTimeline* cobj = (spine::ColorTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_ColorTimeline_getSlotIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getSlotIndex();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_ColorTimeline_getSlotIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_ColorTimeline_getSlotIndex)

static bool js_cocos2dx_spine_ColorTimeline_getFrames(se::State &s, se::ScriptEngine *inst)
{
    spine::ColorTimeline* cobj = (spine::ColorTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_ColorTimeline_getFrames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<float>& result = cobj->getFrames();
        ok &= spine_Vector_T_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_ColorTimeline_getFrames : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_ColorTimeline_getFrames)


extern se::Object* __jsb_spine_CurveTimeline_proto;


bool js_register_cocos2dx_spine_ColorTimeline(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "ColorTimeline", obj, __jsb_spine_CurveTimeline_proto, nullptr);

    cls->defineFunction(inst, "setSlotIndex", _SE(js_cocos2dx_spine_ColorTimeline_setSlotIndex));
    cls->defineFunction(inst, "getPropertyId", _SE(js_cocos2dx_spine_ColorTimeline_getPropertyId));
    cls->defineFunction(inst, "setFrame", _SE(js_cocos2dx_spine_ColorTimeline_setFrame));
    cls->defineFunction(inst, "getSlotIndex", _SE(js_cocos2dx_spine_ColorTimeline_getSlotIndex));
    cls->defineFunction(inst, "getFrames", _SE(js_cocos2dx_spine_ColorTimeline_getFrames));
    cls->install(inst);
    inst->registerClass<spine::ColorTimeline>(cls);

    __jsb_spine_ColorTimeline_proto = cls->getProto();
    __jsb_spine_ColorTimeline_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_ConstraintData_proto = nullptr;
se::Class* __jsb_spine_ConstraintData_class = nullptr;

static bool js_cocos2dx_spine_ConstraintData_setOrder(se::State &s, se::ScriptEngine *inst)
{
    spine::ConstraintData* cobj = (spine::ConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_ConstraintData_setOrder : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        size_t arg0 = 0;
        ok &= seval_to_size(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_ConstraintData_setOrder : Error processing arguments");
        cobj->setOrder(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_ConstraintData_setOrder)

static bool js_cocos2dx_spine_ConstraintData_getName(se::State &s, se::ScriptEngine *inst)
{
    spine::ConstraintData* cobj = (spine::ConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_ConstraintData_getName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getName();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_ConstraintData_getName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_ConstraintData_getName)

static bool js_cocos2dx_spine_ConstraintData_setSkinRequired(se::State &s, se::ScriptEngine *inst)
{
    spine::ConstraintData* cobj = (spine::ConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_ConstraintData_setSkinRequired : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_ConstraintData_setSkinRequired : Error processing arguments");
        cobj->setSkinRequired(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_ConstraintData_setSkinRequired)

static bool js_cocos2dx_spine_ConstraintData_getOrder(se::State &s, se::ScriptEngine *inst)
{
    spine::ConstraintData* cobj = (spine::ConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_ConstraintData_getOrder : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        size_t result = cobj->getOrder();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_ConstraintData_getOrder : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_ConstraintData_getOrder)

static bool js_cocos2dx_spine_ConstraintData_isSkinRequired(se::State &s, se::ScriptEngine *inst)
{
    spine::ConstraintData* cobj = (spine::ConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_ConstraintData_isSkinRequired : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isSkinRequired();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_ConstraintData_isSkinRequired : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_ConstraintData_isSkinRequired)




bool js_register_cocos2dx_spine_ConstraintData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "ConstraintData", obj, nullptr, nullptr);

    cls->defineFunction(inst, "setOrder", _SE(js_cocos2dx_spine_ConstraintData_setOrder));
    cls->defineFunction(inst, "getName", _SE(js_cocos2dx_spine_ConstraintData_getName));
    cls->defineFunction(inst, "setSkinRequired", _SE(js_cocos2dx_spine_ConstraintData_setSkinRequired));
    cls->defineFunction(inst, "getOrder", _SE(js_cocos2dx_spine_ConstraintData_getOrder));
    cls->defineFunction(inst, "isSkinRequired", _SE(js_cocos2dx_spine_ConstraintData_isSkinRequired));
    cls->install(inst);
    inst->registerClass<spine::ConstraintData>(cls);

    __jsb_spine_ConstraintData_proto = cls->getProto();
    __jsb_spine_ConstraintData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_DeformTimeline_proto = nullptr;
se::Class* __jsb_spine_DeformTimeline_class = nullptr;

static bool js_cocos2dx_spine_DeformTimeline_setSlotIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::DeformTimeline* cobj = (spine::DeformTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_DeformTimeline_setSlotIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_DeformTimeline_setSlotIndex : Error processing arguments");
        cobj->setSlotIndex(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_DeformTimeline_setSlotIndex)

static bool js_cocos2dx_spine_DeformTimeline_getPropertyId(se::State &s, se::ScriptEngine *inst)
{
    spine::DeformTimeline* cobj = (spine::DeformTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_DeformTimeline_getPropertyId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPropertyId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_DeformTimeline_getPropertyId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_DeformTimeline_getPropertyId)

static bool js_cocos2dx_spine_DeformTimeline_getSlotIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::DeformTimeline* cobj = (spine::DeformTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_DeformTimeline_getSlotIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getSlotIndex();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_DeformTimeline_getSlotIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_DeformTimeline_getSlotIndex)

static bool js_cocos2dx_spine_DeformTimeline_getAttachment(se::State &s, se::ScriptEngine *inst)
{
    spine::DeformTimeline* cobj = (spine::DeformTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_DeformTimeline_getAttachment : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::VertexAttachment* result = cobj->getAttachment();
        ok &= native_ptr_to_rooted_seval<spine::VertexAttachment>(inst, (spine::VertexAttachment*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_DeformTimeline_getAttachment : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_DeformTimeline_getAttachment)

static bool js_cocos2dx_spine_DeformTimeline_setAttachment(se::State &s, se::ScriptEngine *inst)
{
    spine::DeformTimeline* cobj = (spine::DeformTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_DeformTimeline_setAttachment : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::VertexAttachment* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_DeformTimeline_setAttachment : Error processing arguments");
        cobj->setAttachment(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_DeformTimeline_setAttachment)

static bool js_cocos2dx_spine_DeformTimeline_getFrames(se::State &s, se::ScriptEngine *inst)
{
    spine::DeformTimeline* cobj = (spine::DeformTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_DeformTimeline_getFrames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<float>& result = cobj->getFrames();
        ok &= spine_Vector_T_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_DeformTimeline_getFrames : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_DeformTimeline_getFrames)


extern se::Object* __jsb_spine_CurveTimeline_proto;


bool js_register_cocos2dx_spine_DeformTimeline(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "DeformTimeline", obj, __jsb_spine_CurveTimeline_proto, nullptr);

    cls->defineFunction(inst, "setSlotIndex", _SE(js_cocos2dx_spine_DeformTimeline_setSlotIndex));
    cls->defineFunction(inst, "getPropertyId", _SE(js_cocos2dx_spine_DeformTimeline_getPropertyId));
    cls->defineFunction(inst, "getSlotIndex", _SE(js_cocos2dx_spine_DeformTimeline_getSlotIndex));
    cls->defineFunction(inst, "getAttachment", _SE(js_cocos2dx_spine_DeformTimeline_getAttachment));
    cls->defineFunction(inst, "setAttachment", _SE(js_cocos2dx_spine_DeformTimeline_setAttachment));
    cls->defineFunction(inst, "getFrames", _SE(js_cocos2dx_spine_DeformTimeline_getFrames));
    cls->install(inst);
    inst->registerClass<spine::DeformTimeline>(cls);

    __jsb_spine_DeformTimeline_proto = cls->getProto();
    __jsb_spine_DeformTimeline_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_DrawOrderTimeline_proto = nullptr;
se::Class* __jsb_spine_DrawOrderTimeline_class = nullptr;

static bool js_cocos2dx_spine_DrawOrderTimeline_getPropertyId(se::State &s, se::ScriptEngine *inst)
{
    spine::DrawOrderTimeline* cobj = (spine::DrawOrderTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_DrawOrderTimeline_getPropertyId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPropertyId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_DrawOrderTimeline_getPropertyId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_DrawOrderTimeline_getPropertyId)

static bool js_cocos2dx_spine_DrawOrderTimeline_getFrameCount(se::State &s, se::ScriptEngine *inst)
{
    spine::DrawOrderTimeline* cobj = (spine::DrawOrderTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_DrawOrderTimeline_getFrameCount : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        size_t result = cobj->getFrameCount();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_DrawOrderTimeline_getFrameCount : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_DrawOrderTimeline_getFrameCount)

static bool js_cocos2dx_spine_DrawOrderTimeline_getFrames(se::State &s, se::ScriptEngine *inst)
{
    spine::DrawOrderTimeline* cobj = (spine::DrawOrderTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_DrawOrderTimeline_getFrames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<float>& result = cobj->getFrames();
        ok &= spine_Vector_T_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_DrawOrderTimeline_getFrames : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_DrawOrderTimeline_getFrames)


extern se::Object* __jsb_spine_Timeline_proto;


bool js_register_cocos2dx_spine_DrawOrderTimeline(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "DrawOrderTimeline", obj, __jsb_spine_Timeline_proto, nullptr);

    cls->defineFunction(inst, "getPropertyId", _SE(js_cocos2dx_spine_DrawOrderTimeline_getPropertyId));
    cls->defineFunction(inst, "getFrameCount", _SE(js_cocos2dx_spine_DrawOrderTimeline_getFrameCount));
    cls->defineFunction(inst, "getFrames", _SE(js_cocos2dx_spine_DrawOrderTimeline_getFrames));
    cls->install(inst);
    inst->registerClass<spine::DrawOrderTimeline>(cls);

    __jsb_spine_DrawOrderTimeline_proto = cls->getProto();
    __jsb_spine_DrawOrderTimeline_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_Event_proto = nullptr;
se::Class* __jsb_spine_Event_class = nullptr;

static bool js_cocos2dx_spine_Event_getFloatValue(se::State &s, se::ScriptEngine *inst)
{
    spine::Event* cobj = (spine::Event*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Event_getFloatValue : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getFloatValue();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Event_getFloatValue : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Event_getFloatValue)

static bool js_cocos2dx_spine_Event_getIntValue(se::State &s, se::ScriptEngine *inst)
{
    spine::Event* cobj = (spine::Event*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Event_getIntValue : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getIntValue();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Event_getIntValue : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Event_getIntValue)

static bool js_cocos2dx_spine_Event_getStringValue(se::State &s, se::ScriptEngine *inst)
{
    spine::Event* cobj = (spine::Event*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Event_getStringValue : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getStringValue();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Event_getStringValue : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Event_getStringValue)

static bool js_cocos2dx_spine_Event_getTime(se::State &s, se::ScriptEngine *inst)
{
    spine::Event* cobj = (spine::Event*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Event_getTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTime();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Event_getTime : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Event_getTime)

static bool js_cocos2dx_spine_Event_getBalance(se::State &s, se::ScriptEngine *inst)
{
    spine::Event* cobj = (spine::Event*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Event_getBalance : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getBalance();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Event_getBalance : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Event_getBalance)

static bool js_cocos2dx_spine_Event_setFloatValue(se::State &s, se::ScriptEngine *inst)
{
    spine::Event* cobj = (spine::Event*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Event_setFloatValue : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Event_setFloatValue : Error processing arguments");
        cobj->setFloatValue(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Event_setFloatValue)

static bool js_cocos2dx_spine_Event_setIntValue(se::State &s, se::ScriptEngine *inst)
{
    spine::Event* cobj = (spine::Event*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Event_setIntValue : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Event_setIntValue : Error processing arguments");
        cobj->setIntValue(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Event_setIntValue)

static bool js_cocos2dx_spine_Event_getVolume(se::State &s, se::ScriptEngine *inst)
{
    spine::Event* cobj = (spine::Event*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Event_getVolume : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getVolume();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Event_getVolume : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Event_getVolume)

static bool js_cocos2dx_spine_Event_setBalance(se::State &s, se::ScriptEngine *inst)
{
    spine::Event* cobj = (spine::Event*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Event_setBalance : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Event_setBalance : Error processing arguments");
        cobj->setBalance(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Event_setBalance)

static bool js_cocos2dx_spine_Event_getData(se::State &s, se::ScriptEngine *inst)
{
    spine::Event* cobj = (spine::Event*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Event_getData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::EventData& result = cobj->getData();
        ok &= native_ptr_to_rooted_seval<spine::EventData>(inst, (spine::EventData*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Event_getData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Event_getData)

static bool js_cocos2dx_spine_Event_setStringValue(se::State &s, se::ScriptEngine *inst)
{
    spine::Event* cobj = (spine::Event*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Event_setStringValue : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Event_setStringValue : Error processing arguments");
        cobj->setStringValue(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Event_setStringValue)

static bool js_cocos2dx_spine_Event_setVolume(se::State &s, se::ScriptEngine *inst)
{
    spine::Event* cobj = (spine::Event*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Event_setVolume : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Event_setVolume : Error processing arguments");
        cobj->setVolume(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Event_setVolume)




bool js_register_cocos2dx_spine_Event(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Event", obj, nullptr, nullptr);

    cls->defineFunction(inst, "getFloatValue", _SE(js_cocos2dx_spine_Event_getFloatValue));
    cls->defineFunction(inst, "getIntValue", _SE(js_cocos2dx_spine_Event_getIntValue));
    cls->defineFunction(inst, "getStringValue", _SE(js_cocos2dx_spine_Event_getStringValue));
    cls->defineFunction(inst, "getTime", _SE(js_cocos2dx_spine_Event_getTime));
    cls->defineFunction(inst, "getBalance", _SE(js_cocos2dx_spine_Event_getBalance));
    cls->defineFunction(inst, "setFloatValue", _SE(js_cocos2dx_spine_Event_setFloatValue));
    cls->defineFunction(inst, "setIntValue", _SE(js_cocos2dx_spine_Event_setIntValue));
    cls->defineFunction(inst, "getVolume", _SE(js_cocos2dx_spine_Event_getVolume));
    cls->defineFunction(inst, "setBalance", _SE(js_cocos2dx_spine_Event_setBalance));
    cls->defineFunction(inst, "getData", _SE(js_cocos2dx_spine_Event_getData));
    cls->defineFunction(inst, "setStringValue", _SE(js_cocos2dx_spine_Event_setStringValue));
    cls->defineFunction(inst, "setVolume", _SE(js_cocos2dx_spine_Event_setVolume));
    cls->install(inst);
    inst->registerClass<spine::Event>(cls);

    __jsb_spine_Event_proto = cls->getProto();
    __jsb_spine_Event_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_EventData_proto = nullptr;
se::Class* __jsb_spine_EventData_class = nullptr;

static bool js_cocos2dx_spine_EventData_getAudioPath(se::State &s, se::ScriptEngine *inst)
{
    spine::EventData* cobj = (spine::EventData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventData_getAudioPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getAudioPath();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventData_getAudioPath : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventData_getAudioPath)

static bool js_cocos2dx_spine_EventData_getIntValue(se::State &s, se::ScriptEngine *inst)
{
    spine::EventData* cobj = (spine::EventData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventData_getIntValue : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getIntValue();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventData_getIntValue : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventData_getIntValue)

static bool js_cocos2dx_spine_EventData_getStringValue(se::State &s, se::ScriptEngine *inst)
{
    spine::EventData* cobj = (spine::EventData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventData_getStringValue : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getStringValue();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventData_getStringValue : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventData_getStringValue)

static bool js_cocos2dx_spine_EventData_getFloatValue(se::State &s, se::ScriptEngine *inst)
{
    spine::EventData* cobj = (spine::EventData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventData_getFloatValue : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getFloatValue();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventData_getFloatValue : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventData_getFloatValue)

static bool js_cocos2dx_spine_EventData_getName(se::State &s, se::ScriptEngine *inst)
{
    spine::EventData* cobj = (spine::EventData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventData_getName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getName();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventData_getName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventData_getName)

static bool js_cocos2dx_spine_EventData_setFloatValue(se::State &s, se::ScriptEngine *inst)
{
    spine::EventData* cobj = (spine::EventData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventData_setFloatValue : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventData_setFloatValue : Error processing arguments");
        cobj->setFloatValue(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventData_setFloatValue)

static bool js_cocos2dx_spine_EventData_setIntValue(se::State &s, se::ScriptEngine *inst)
{
    spine::EventData* cobj = (spine::EventData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventData_setIntValue : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventData_setIntValue : Error processing arguments");
        cobj->setIntValue(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventData_setIntValue)

static bool js_cocos2dx_spine_EventData_getVolume(se::State &s, se::ScriptEngine *inst)
{
    spine::EventData* cobj = (spine::EventData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventData_getVolume : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getVolume();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventData_getVolume : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventData_getVolume)

static bool js_cocos2dx_spine_EventData_setBalance(se::State &s, se::ScriptEngine *inst)
{
    spine::EventData* cobj = (spine::EventData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventData_setBalance : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventData_setBalance : Error processing arguments");
        cobj->setBalance(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventData_setBalance)

static bool js_cocos2dx_spine_EventData_setVolume(se::State &s, se::ScriptEngine *inst)
{
    spine::EventData* cobj = (spine::EventData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventData_setVolume : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventData_setVolume : Error processing arguments");
        cobj->setVolume(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventData_setVolume)

static bool js_cocos2dx_spine_EventData_setStringValue(se::State &s, se::ScriptEngine *inst)
{
    spine::EventData* cobj = (spine::EventData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventData_setStringValue : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventData_setStringValue : Error processing arguments");
        cobj->setStringValue(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventData_setStringValue)

static bool js_cocos2dx_spine_EventData_getBalance(se::State &s, se::ScriptEngine *inst)
{
    spine::EventData* cobj = (spine::EventData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventData_getBalance : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getBalance();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventData_getBalance : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventData_getBalance)

static bool js_cocos2dx_spine_EventData_setAudioPath(se::State &s, se::ScriptEngine *inst)
{
    spine::EventData* cobj = (spine::EventData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventData_setAudioPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventData_setAudioPath : Error processing arguments");
        cobj->setAudioPath(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventData_setAudioPath)




bool js_register_cocos2dx_spine_EventData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "EventData", obj, nullptr, nullptr);

    cls->defineFunction(inst, "getAudioPath", _SE(js_cocos2dx_spine_EventData_getAudioPath));
    cls->defineFunction(inst, "getIntValue", _SE(js_cocos2dx_spine_EventData_getIntValue));
    cls->defineFunction(inst, "getStringValue", _SE(js_cocos2dx_spine_EventData_getStringValue));
    cls->defineFunction(inst, "getFloatValue", _SE(js_cocos2dx_spine_EventData_getFloatValue));
    cls->defineFunction(inst, "getName", _SE(js_cocos2dx_spine_EventData_getName));
    cls->defineFunction(inst, "setFloatValue", _SE(js_cocos2dx_spine_EventData_setFloatValue));
    cls->defineFunction(inst, "setIntValue", _SE(js_cocos2dx_spine_EventData_setIntValue));
    cls->defineFunction(inst, "getVolume", _SE(js_cocos2dx_spine_EventData_getVolume));
    cls->defineFunction(inst, "setBalance", _SE(js_cocos2dx_spine_EventData_setBalance));
    cls->defineFunction(inst, "setVolume", _SE(js_cocos2dx_spine_EventData_setVolume));
    cls->defineFunction(inst, "setStringValue", _SE(js_cocos2dx_spine_EventData_setStringValue));
    cls->defineFunction(inst, "getBalance", _SE(js_cocos2dx_spine_EventData_getBalance));
    cls->defineFunction(inst, "setAudioPath", _SE(js_cocos2dx_spine_EventData_setAudioPath));
    cls->install(inst);
    inst->registerClass<spine::EventData>(cls);

    __jsb_spine_EventData_proto = cls->getProto();
    __jsb_spine_EventData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_EventTimeline_proto = nullptr;
se::Class* __jsb_spine_EventTimeline_class = nullptr;

static bool js_cocos2dx_spine_EventTimeline_getPropertyId(se::State &s, se::ScriptEngine *inst)
{
    spine::EventTimeline* cobj = (spine::EventTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventTimeline_getPropertyId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPropertyId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventTimeline_getPropertyId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventTimeline_getPropertyId)

static bool js_cocos2dx_spine_EventTimeline_setFrame(se::State &s, se::ScriptEngine *inst)
{
    spine::EventTimeline* cobj = (spine::EventTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventTimeline_setFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        size_t arg0 = 0;
        spine::Event* arg1 = nullptr;
        ok &= seval_to_size(inst, args[0], &arg0);
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventTimeline_setFrame : Error processing arguments");
        cobj->setFrame(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventTimeline_setFrame)

static bool js_cocos2dx_spine_EventTimeline_getFrameCount(se::State &s, se::ScriptEngine *inst)
{
    spine::EventTimeline* cobj = (spine::EventTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventTimeline_getFrameCount : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        size_t result = cobj->getFrameCount();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventTimeline_getFrameCount : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventTimeline_getFrameCount)

static bool js_cocos2dx_spine_EventTimeline_getFrames(se::State &s, se::ScriptEngine *inst)
{
    spine::EventTimeline* cobj = (spine::EventTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventTimeline_getFrames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<float> result = cobj->getFrames();
        ok &= spine_Vector_T_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventTimeline_getFrames : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventTimeline_getFrames)

static bool js_cocos2dx_spine_EventTimeline_getEvents(se::State &s, se::ScriptEngine *inst)
{
    spine::EventTimeline* cobj = (spine::EventTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_EventTimeline_getEvents : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::Event *>& result = cobj->getEvents();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_EventTimeline_getEvents : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_EventTimeline_getEvents)


extern se::Object* __jsb_spine_Timeline_proto;


bool js_register_cocos2dx_spine_EventTimeline(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "EventTimeline", obj, __jsb_spine_Timeline_proto, nullptr);

    cls->defineFunction(inst, "getPropertyId", _SE(js_cocos2dx_spine_EventTimeline_getPropertyId));
    cls->defineFunction(inst, "setFrame", _SE(js_cocos2dx_spine_EventTimeline_setFrame));
    cls->defineFunction(inst, "getFrameCount", _SE(js_cocos2dx_spine_EventTimeline_getFrameCount));
    cls->defineFunction(inst, "getFrames", _SE(js_cocos2dx_spine_EventTimeline_getFrames));
    cls->defineFunction(inst, "getEvents", _SE(js_cocos2dx_spine_EventTimeline_getEvents));
    cls->install(inst);
    inst->registerClass<spine::EventTimeline>(cls);

    __jsb_spine_EventTimeline_proto = cls->getProto();
    __jsb_spine_EventTimeline_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_IkConstraint_proto = nullptr;
se::Class* __jsb_spine_IkConstraint_class = nullptr;

static bool js_cocos2dx_spine_IkConstraint_getMix(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_getMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getMix();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraint_getMix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_getMix)

static bool js_cocos2dx_spine_IkConstraint_getStretch(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_getStretch : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getStretch();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraint_getStretch : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_getStretch)

static bool js_cocos2dx_spine_IkConstraint_getCompress(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_getCompress : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getCompress();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraint_getCompress : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_getCompress)

static bool js_cocos2dx_spine_IkConstraint_setStretch(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_setStretch : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraint_setStretch : Error processing arguments");
        cobj->setStretch(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_setStretch)

static bool js_cocos2dx_spine_IkConstraint_setActive(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_setActive : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraint_setActive : Error processing arguments");
        cobj->setActive(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_setActive)

static bool js_cocos2dx_spine_IkConstraint_getBones(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_getBones : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::Bone *>& result = cobj->getBones();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraint_getBones : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_getBones)

static bool js_cocos2dx_spine_IkConstraint_setTarget(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_setTarget : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::Bone* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraint_setTarget : Error processing arguments");
        cobj->setTarget(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_setTarget)

static bool js_cocos2dx_spine_IkConstraint_setBendDirection(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_setBendDirection : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraint_setBendDirection : Error processing arguments");
        cobj->setBendDirection(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_setBendDirection)

static bool js_cocos2dx_spine_IkConstraint_update(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_update : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->update();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_update)

static bool js_cocos2dx_spine_IkConstraint_getTarget(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_getTarget : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Bone* result = cobj->getTarget();
        ok &= native_ptr_to_rooted_seval<spine::Bone>(inst, (spine::Bone*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraint_getTarget : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_getTarget)

static bool js_cocos2dx_spine_IkConstraint_setCompress(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_setCompress : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraint_setCompress : Error processing arguments");
        cobj->setCompress(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_setCompress)

static bool js_cocos2dx_spine_IkConstraint_getBendDirection(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_getBendDirection : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getBendDirection();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraint_getBendDirection : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_getBendDirection)

static bool js_cocos2dx_spine_IkConstraint_getOrder(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_getOrder : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getOrder();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraint_getOrder : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_getOrder)

static bool js_cocos2dx_spine_IkConstraint_getSoftness(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_getSoftness : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getSoftness();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraint_getSoftness : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_getSoftness)

static bool js_cocos2dx_spine_IkConstraint_setMix(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_setMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraint_setMix : Error processing arguments");
        cobj->setMix(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_setMix)

static bool js_cocos2dx_spine_IkConstraint_getData(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_getData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::IkConstraintData& result = cobj->getData();
        ok &= native_ptr_to_rooted_seval<spine::IkConstraintData>(inst, (spine::IkConstraintData*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraint_getData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_getData)

static bool js_cocos2dx_spine_IkConstraint_setSoftness(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_setSoftness : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraint_setSoftness : Error processing arguments");
        cobj->setSoftness(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_setSoftness)

static bool js_cocos2dx_spine_IkConstraint_isActive(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraint* cobj = (spine::IkConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraint_isActive : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isActive();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraint_isActive : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraint_isActive)




bool js_register_cocos2dx_spine_IkConstraint(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "IkConstraint", obj, nullptr, nullptr);

    cls->defineFunction(inst, "getMix", _SE(js_cocos2dx_spine_IkConstraint_getMix));
    cls->defineFunction(inst, "getStretch", _SE(js_cocos2dx_spine_IkConstraint_getStretch));
    cls->defineFunction(inst, "getCompress", _SE(js_cocos2dx_spine_IkConstraint_getCompress));
    cls->defineFunction(inst, "setStretch", _SE(js_cocos2dx_spine_IkConstraint_setStretch));
    cls->defineFunction(inst, "setActive", _SE(js_cocos2dx_spine_IkConstraint_setActive));
    cls->defineFunction(inst, "getBones", _SE(js_cocos2dx_spine_IkConstraint_getBones));
    cls->defineFunction(inst, "setTarget", _SE(js_cocos2dx_spine_IkConstraint_setTarget));
    cls->defineFunction(inst, "setBendDirection", _SE(js_cocos2dx_spine_IkConstraint_setBendDirection));
    cls->defineFunction(inst, "update", _SE(js_cocos2dx_spine_IkConstraint_update));
    cls->defineFunction(inst, "getTarget", _SE(js_cocos2dx_spine_IkConstraint_getTarget));
    cls->defineFunction(inst, "setCompress", _SE(js_cocos2dx_spine_IkConstraint_setCompress));
    cls->defineFunction(inst, "getBendDirection", _SE(js_cocos2dx_spine_IkConstraint_getBendDirection));
    cls->defineFunction(inst, "getOrder", _SE(js_cocos2dx_spine_IkConstraint_getOrder));
    cls->defineFunction(inst, "getSoftness", _SE(js_cocos2dx_spine_IkConstraint_getSoftness));
    cls->defineFunction(inst, "setMix", _SE(js_cocos2dx_spine_IkConstraint_setMix));
    cls->defineFunction(inst, "getData", _SE(js_cocos2dx_spine_IkConstraint_getData));
    cls->defineFunction(inst, "setSoftness", _SE(js_cocos2dx_spine_IkConstraint_setSoftness));
    cls->defineFunction(inst, "isActive", _SE(js_cocos2dx_spine_IkConstraint_isActive));
    cls->install(inst);
    inst->registerClass<spine::IkConstraint>(cls);

    __jsb_spine_IkConstraint_proto = cls->getProto();
    __jsb_spine_IkConstraint_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_IkConstraintData_proto = nullptr;
se::Class* __jsb_spine_IkConstraintData_class = nullptr;

static bool js_cocos2dx_spine_IkConstraintData_getMix(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraintData* cobj = (spine::IkConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraintData_getMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getMix();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraintData_getMix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraintData_getMix)

static bool js_cocos2dx_spine_IkConstraintData_setUniform(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraintData* cobj = (spine::IkConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraintData_setUniform : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraintData_setUniform : Error processing arguments");
        cobj->setUniform(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraintData_setUniform)

static bool js_cocos2dx_spine_IkConstraintData_setStretch(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraintData* cobj = (spine::IkConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraintData_setStretch : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraintData_setStretch : Error processing arguments");
        cobj->setStretch(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraintData_setStretch)

static bool js_cocos2dx_spine_IkConstraintData_getUniform(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraintData* cobj = (spine::IkConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraintData_getUniform : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getUniform();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraintData_getUniform : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraintData_getUniform)

static bool js_cocos2dx_spine_IkConstraintData_getBones(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraintData* cobj = (spine::IkConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraintData_getBones : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::BoneData *>& result = cobj->getBones();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraintData_getBones : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraintData_getBones)

static bool js_cocos2dx_spine_IkConstraintData_setTarget(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraintData* cobj = (spine::IkConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraintData_setTarget : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::BoneData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraintData_setTarget : Error processing arguments");
        cobj->setTarget(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraintData_setTarget)

static bool js_cocos2dx_spine_IkConstraintData_getTarget(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraintData* cobj = (spine::IkConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraintData_getTarget : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::BoneData* result = cobj->getTarget();
        ok &= native_ptr_to_rooted_seval<spine::BoneData>(inst, (spine::BoneData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraintData_getTarget : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraintData_getTarget)

static bool js_cocos2dx_spine_IkConstraintData_setCompress(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraintData* cobj = (spine::IkConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraintData_setCompress : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraintData_setCompress : Error processing arguments");
        cobj->setCompress(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraintData_setCompress)

static bool js_cocos2dx_spine_IkConstraintData_getBendDirection(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraintData* cobj = (spine::IkConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraintData_getBendDirection : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getBendDirection();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraintData_getBendDirection : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraintData_getBendDirection)

static bool js_cocos2dx_spine_IkConstraintData_setBendDirection(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraintData* cobj = (spine::IkConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraintData_setBendDirection : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraintData_setBendDirection : Error processing arguments");
        cobj->setBendDirection(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraintData_setBendDirection)

static bool js_cocos2dx_spine_IkConstraintData_getSoftness(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraintData* cobj = (spine::IkConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraintData_getSoftness : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getSoftness();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraintData_getSoftness : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraintData_getSoftness)

static bool js_cocos2dx_spine_IkConstraintData_getStretch(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraintData* cobj = (spine::IkConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraintData_getStretch : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getStretch();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraintData_getStretch : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraintData_getStretch)

static bool js_cocos2dx_spine_IkConstraintData_setMix(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraintData* cobj = (spine::IkConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraintData_setMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraintData_setMix : Error processing arguments");
        cobj->setMix(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraintData_setMix)

static bool js_cocos2dx_spine_IkConstraintData_getCompress(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraintData* cobj = (spine::IkConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraintData_getCompress : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getCompress();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraintData_getCompress : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraintData_getCompress)

static bool js_cocos2dx_spine_IkConstraintData_setSoftness(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraintData* cobj = (spine::IkConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraintData_setSoftness : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraintData_setSoftness : Error processing arguments");
        cobj->setSoftness(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraintData_setSoftness)


extern se::Object* __jsb_spine_ConstraintData_proto;


bool js_register_cocos2dx_spine_IkConstraintData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "IkConstraintData", obj, __jsb_spine_ConstraintData_proto, nullptr);

    cls->defineFunction(inst, "getMix", _SE(js_cocos2dx_spine_IkConstraintData_getMix));
    cls->defineFunction(inst, "setUniform", _SE(js_cocos2dx_spine_IkConstraintData_setUniform));
    cls->defineFunction(inst, "setStretch", _SE(js_cocos2dx_spine_IkConstraintData_setStretch));
    cls->defineFunction(inst, "getUniform", _SE(js_cocos2dx_spine_IkConstraintData_getUniform));
    cls->defineFunction(inst, "getBones", _SE(js_cocos2dx_spine_IkConstraintData_getBones));
    cls->defineFunction(inst, "setTarget", _SE(js_cocos2dx_spine_IkConstraintData_setTarget));
    cls->defineFunction(inst, "getTarget", _SE(js_cocos2dx_spine_IkConstraintData_getTarget));
    cls->defineFunction(inst, "setCompress", _SE(js_cocos2dx_spine_IkConstraintData_setCompress));
    cls->defineFunction(inst, "getBendDirection", _SE(js_cocos2dx_spine_IkConstraintData_getBendDirection));
    cls->defineFunction(inst, "setBendDirection", _SE(js_cocos2dx_spine_IkConstraintData_setBendDirection));
    cls->defineFunction(inst, "getSoftness", _SE(js_cocos2dx_spine_IkConstraintData_getSoftness));
    cls->defineFunction(inst, "getStretch", _SE(js_cocos2dx_spine_IkConstraintData_getStretch));
    cls->defineFunction(inst, "setMix", _SE(js_cocos2dx_spine_IkConstraintData_setMix));
    cls->defineFunction(inst, "getCompress", _SE(js_cocos2dx_spine_IkConstraintData_getCompress));
    cls->defineFunction(inst, "setSoftness", _SE(js_cocos2dx_spine_IkConstraintData_setSoftness));
    cls->install(inst);
    inst->registerClass<spine::IkConstraintData>(cls);

    __jsb_spine_IkConstraintData_proto = cls->getProto();
    __jsb_spine_IkConstraintData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_IkConstraintTimeline_proto = nullptr;
se::Class* __jsb_spine_IkConstraintTimeline_class = nullptr;

static bool js_cocos2dx_spine_IkConstraintTimeline_getPropertyId(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraintTimeline* cobj = (spine::IkConstraintTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraintTimeline_getPropertyId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPropertyId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraintTimeline_getPropertyId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraintTimeline_getPropertyId)

static bool js_cocos2dx_spine_IkConstraintTimeline_setFrame(se::State &s, se::ScriptEngine *inst)
{
    spine::IkConstraintTimeline* cobj = (spine::IkConstraintTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_IkConstraintTimeline_setFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 7) {
        int arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        int arg4 = 0;
        bool arg5;
        bool arg6;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[4], &tmp); arg4 = (int)tmp; } while(false);
        ok &= seval_to_boolean(inst, args[5], &arg5);
        ok &= seval_to_boolean(inst, args[6], &arg6);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_IkConstraintTimeline_setFrame : Error processing arguments");
        cobj->setFrame(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 7);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_IkConstraintTimeline_setFrame)


extern se::Object* __jsb_spine_CurveTimeline_proto;


bool js_register_cocos2dx_spine_IkConstraintTimeline(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "IkConstraintTimeline", obj, __jsb_spine_CurveTimeline_proto, nullptr);

    cls->defineFunction(inst, "getPropertyId", _SE(js_cocos2dx_spine_IkConstraintTimeline_getPropertyId));
    cls->defineFunction(inst, "setFrame", _SE(js_cocos2dx_spine_IkConstraintTimeline_setFrame));
    cls->install(inst);
    inst->registerClass<spine::IkConstraintTimeline>(cls);

    __jsb_spine_IkConstraintTimeline_proto = cls->getProto();
    __jsb_spine_IkConstraintTimeline_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_MeshAttachment_proto = nullptr;
se::Class* __jsb_spine_MeshAttachment_class = nullptr;

static bool js_cocos2dx_spine_MeshAttachment_setRegionOriginalHeight(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_setRegionOriginalHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_setRegionOriginalHeight : Error processing arguments");
        cobj->setRegionOriginalHeight(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_setRegionOriginalHeight)

static bool js_cocos2dx_spine_MeshAttachment_setRegionOffsetY(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_setRegionOffsetY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_setRegionOffsetY : Error processing arguments");
        cobj->setRegionOffsetY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_setRegionOffsetY)

static bool js_cocos2dx_spine_MeshAttachment_setRegionOffsetX(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_setRegionOffsetX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_setRegionOffsetX : Error processing arguments");
        cobj->setRegionOffsetX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_setRegionOffsetX)

static bool js_cocos2dx_spine_MeshAttachment_copy(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_copy : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Attachment* result = cobj->copy();
        ok &= native_ptr_to_rooted_seval<spine::Attachment>(inst, (spine::Attachment*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_copy : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_copy)

static bool js_cocos2dx_spine_MeshAttachment_getRegionOriginalWidth(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getRegionOriginalWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRegionOriginalWidth();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getRegionOriginalWidth : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getRegionOriginalWidth)

static bool js_cocos2dx_spine_MeshAttachment_getWidth(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getWidth();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getWidth : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getWidth)

static bool js_cocos2dx_spine_MeshAttachment_setParentMesh(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_setParentMesh : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::MeshAttachment* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_setParentMesh : Error processing arguments");
        cobj->setParentMesh(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_setParentMesh)

static bool js_cocos2dx_spine_MeshAttachment_setWidth(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_setWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_setWidth : Error processing arguments");
        cobj->setWidth(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_setWidth)

static bool js_cocos2dx_spine_MeshAttachment_setRegionRotate(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_setRegionRotate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_setRegionRotate : Error processing arguments");
        cobj->setRegionRotate(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_setRegionRotate)

static bool js_cocos2dx_spine_MeshAttachment_setRegionDegrees(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_setRegionDegrees : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_setRegionDegrees : Error processing arguments");
        cobj->setRegionDegrees(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_setRegionDegrees)

static bool js_cocos2dx_spine_MeshAttachment_getUVs(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getUVs : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<float>& result = cobj->getUVs();
        ok &= spine_Vector_T_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getUVs : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getUVs)

static bool js_cocos2dx_spine_MeshAttachment_getRegionDegrees(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getRegionDegrees : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getRegionDegrees();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getRegionDegrees : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getRegionDegrees)

static bool js_cocos2dx_spine_MeshAttachment_getRegionHeight(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getRegionHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRegionHeight();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getRegionHeight : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getRegionHeight)

static bool js_cocos2dx_spine_MeshAttachment_getRegionU2(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getRegionU2 : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRegionU2();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getRegionU2 : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getRegionU2)

static bool js_cocos2dx_spine_MeshAttachment_getHeight(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getHeight();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getHeight : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getHeight)

static bool js_cocos2dx_spine_MeshAttachment_getPath(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getPath();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getPath : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getPath)

static bool js_cocos2dx_spine_MeshAttachment_setRegionV2(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_setRegionV2 : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_setRegionV2 : Error processing arguments");
        cobj->setRegionV2(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_setRegionV2)

static bool js_cocos2dx_spine_MeshAttachment_setRegionWidth(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_setRegionWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_setRegionWidth : Error processing arguments");
        cobj->setRegionWidth(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_setRegionWidth)

static bool js_cocos2dx_spine_MeshAttachment_setRegionV(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_setRegionV : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_setRegionV : Error processing arguments");
        cobj->setRegionV(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_setRegionV)

static bool js_cocos2dx_spine_MeshAttachment_setPath(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_setPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_setPath : Error processing arguments");
        cobj->setPath(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_setPath)

static bool js_cocos2dx_spine_MeshAttachment_setRegionU(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_setRegionU : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_setRegionU : Error processing arguments");
        cobj->setRegionU(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_setRegionU)

static bool js_cocos2dx_spine_MeshAttachment_setHullLength(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_setHullLength : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_setHullLength : Error processing arguments");
        cobj->setHullLength(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_setHullLength)

static bool js_cocos2dx_spine_MeshAttachment_getColor(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Color& result = cobj->getColor();
        ok &= native_ptr_to_rooted_seval<spine::Color>(inst, (spine::Color*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getColor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getColor)

static bool js_cocos2dx_spine_MeshAttachment_getRegionOriginalHeight(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getRegionOriginalHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRegionOriginalHeight();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getRegionOriginalHeight : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getRegionOriginalHeight)

static bool js_cocos2dx_spine_MeshAttachment_getEdges(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getEdges : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<unsigned short>& result = cobj->getEdges();
        ok &= spine_Vector_T_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getEdges : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getEdges)

static bool js_cocos2dx_spine_MeshAttachment_getRegionUVs(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getRegionUVs : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<float>& result = cobj->getRegionUVs();
        ok &= spine_Vector_T_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getRegionUVs : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getRegionUVs)

static bool js_cocos2dx_spine_MeshAttachment_getRegionV2(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getRegionV2 : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRegionV2();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getRegionV2 : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getRegionV2)

static bool js_cocos2dx_spine_MeshAttachment_getRegionWidth(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getRegionWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRegionWidth();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getRegionWidth : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getRegionWidth)

static bool js_cocos2dx_spine_MeshAttachment_setHeight(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_setHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_setHeight : Error processing arguments");
        cobj->setHeight(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_setHeight)

static bool js_cocos2dx_spine_MeshAttachment_setRegionOriginalWidth(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_setRegionOriginalWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_setRegionOriginalWidth : Error processing arguments");
        cobj->setRegionOriginalWidth(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_setRegionOriginalWidth)

static bool js_cocos2dx_spine_MeshAttachment_newLinkedMesh(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_newLinkedMesh : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::MeshAttachment* result = cobj->newLinkedMesh();
        ok &= native_ptr_to_rooted_seval<spine::MeshAttachment>(inst, (spine::MeshAttachment*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_newLinkedMesh : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_newLinkedMesh)

static bool js_cocos2dx_spine_MeshAttachment_updateUVs(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_updateUVs : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->updateUVs();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_updateUVs)

static bool js_cocos2dx_spine_MeshAttachment_setRegionU2(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_setRegionU2 : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_setRegionU2 : Error processing arguments");
        cobj->setRegionU2(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_setRegionU2)

static bool js_cocos2dx_spine_MeshAttachment_getHullLength(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getHullLength : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getHullLength();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getHullLength : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getHullLength)

static bool js_cocos2dx_spine_MeshAttachment_setRegionHeight(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_setRegionHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_setRegionHeight : Error processing arguments");
        cobj->setRegionHeight(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_setRegionHeight)

static bool js_cocos2dx_spine_MeshAttachment_getTriangles(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getTriangles : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<unsigned short>& result = cobj->getTriangles();
        ok &= spine_Vector_T_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getTriangles : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getTriangles)

static bool js_cocos2dx_spine_MeshAttachment_getRegionOffsetY(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getRegionOffsetY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRegionOffsetY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getRegionOffsetY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getRegionOffsetY)

static bool js_cocos2dx_spine_MeshAttachment_getRegionOffsetX(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getRegionOffsetX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRegionOffsetX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getRegionOffsetX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getRegionOffsetX)

static bool js_cocos2dx_spine_MeshAttachment_getRegionV(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getRegionV : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRegionV();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getRegionV : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getRegionV)

static bool js_cocos2dx_spine_MeshAttachment_getRegionRotate(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getRegionRotate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getRegionRotate();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getRegionRotate : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getRegionRotate)

static bool js_cocos2dx_spine_MeshAttachment_getParentMesh(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getParentMesh : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::MeshAttachment* result = cobj->getParentMesh();
        ok &= native_ptr_to_rooted_seval<spine::MeshAttachment>(inst, (spine::MeshAttachment*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getParentMesh : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getParentMesh)

static bool js_cocos2dx_spine_MeshAttachment_getRegionU(se::State &s, se::ScriptEngine *inst)
{
    spine::MeshAttachment* cobj = (spine::MeshAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_MeshAttachment_getRegionU : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRegionU();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_MeshAttachment_getRegionU : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_MeshAttachment_getRegionU)


extern se::Object* __jsb_spine_VertexAttachment_proto;


bool js_register_cocos2dx_spine_MeshAttachment(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "MeshAttachment", obj, __jsb_spine_VertexAttachment_proto, nullptr);

    cls->defineFunction(inst, "setRegionOriginalHeight", _SE(js_cocos2dx_spine_MeshAttachment_setRegionOriginalHeight));
    cls->defineFunction(inst, "setRegionOffsetY", _SE(js_cocos2dx_spine_MeshAttachment_setRegionOffsetY));
    cls->defineFunction(inst, "setRegionOffsetX", _SE(js_cocos2dx_spine_MeshAttachment_setRegionOffsetX));
    cls->defineFunction(inst, "copy", _SE(js_cocos2dx_spine_MeshAttachment_copy));
    cls->defineFunction(inst, "getRegionOriginalWidth", _SE(js_cocos2dx_spine_MeshAttachment_getRegionOriginalWidth));
    cls->defineFunction(inst, "getWidth", _SE(js_cocos2dx_spine_MeshAttachment_getWidth));
    cls->defineFunction(inst, "setParentMesh", _SE(js_cocos2dx_spine_MeshAttachment_setParentMesh));
    cls->defineFunction(inst, "setWidth", _SE(js_cocos2dx_spine_MeshAttachment_setWidth));
    cls->defineFunction(inst, "setRegionRotate", _SE(js_cocos2dx_spine_MeshAttachment_setRegionRotate));
    cls->defineFunction(inst, "setRegionDegrees", _SE(js_cocos2dx_spine_MeshAttachment_setRegionDegrees));
    cls->defineFunction(inst, "getUVs", _SE(js_cocos2dx_spine_MeshAttachment_getUVs));
    cls->defineFunction(inst, "getRegionDegrees", _SE(js_cocos2dx_spine_MeshAttachment_getRegionDegrees));
    cls->defineFunction(inst, "getRegionHeight", _SE(js_cocos2dx_spine_MeshAttachment_getRegionHeight));
    cls->defineFunction(inst, "getRegionU2", _SE(js_cocos2dx_spine_MeshAttachment_getRegionU2));
    cls->defineFunction(inst, "getHeight", _SE(js_cocos2dx_spine_MeshAttachment_getHeight));
    cls->defineFunction(inst, "getPath", _SE(js_cocos2dx_spine_MeshAttachment_getPath));
    cls->defineFunction(inst, "setRegionV2", _SE(js_cocos2dx_spine_MeshAttachment_setRegionV2));
    cls->defineFunction(inst, "setRegionWidth", _SE(js_cocos2dx_spine_MeshAttachment_setRegionWidth));
    cls->defineFunction(inst, "setRegionV", _SE(js_cocos2dx_spine_MeshAttachment_setRegionV));
    cls->defineFunction(inst, "setPath", _SE(js_cocos2dx_spine_MeshAttachment_setPath));
    cls->defineFunction(inst, "setRegionU", _SE(js_cocos2dx_spine_MeshAttachment_setRegionU));
    cls->defineFunction(inst, "setHullLength", _SE(js_cocos2dx_spine_MeshAttachment_setHullLength));
    cls->defineFunction(inst, "getColor", _SE(js_cocos2dx_spine_MeshAttachment_getColor));
    cls->defineFunction(inst, "getRegionOriginalHeight", _SE(js_cocos2dx_spine_MeshAttachment_getRegionOriginalHeight));
    cls->defineFunction(inst, "getEdges", _SE(js_cocos2dx_spine_MeshAttachment_getEdges));
    cls->defineFunction(inst, "getRegionUVs", _SE(js_cocos2dx_spine_MeshAttachment_getRegionUVs));
    cls->defineFunction(inst, "getRegionV2", _SE(js_cocos2dx_spine_MeshAttachment_getRegionV2));
    cls->defineFunction(inst, "getRegionWidth", _SE(js_cocos2dx_spine_MeshAttachment_getRegionWidth));
    cls->defineFunction(inst, "setHeight", _SE(js_cocos2dx_spine_MeshAttachment_setHeight));
    cls->defineFunction(inst, "setRegionOriginalWidth", _SE(js_cocos2dx_spine_MeshAttachment_setRegionOriginalWidth));
    cls->defineFunction(inst, "newLinkedMesh", _SE(js_cocos2dx_spine_MeshAttachment_newLinkedMesh));
    cls->defineFunction(inst, "updateUVs", _SE(js_cocos2dx_spine_MeshAttachment_updateUVs));
    cls->defineFunction(inst, "setRegionU2", _SE(js_cocos2dx_spine_MeshAttachment_setRegionU2));
    cls->defineFunction(inst, "getHullLength", _SE(js_cocos2dx_spine_MeshAttachment_getHullLength));
    cls->defineFunction(inst, "setRegionHeight", _SE(js_cocos2dx_spine_MeshAttachment_setRegionHeight));
    cls->defineFunction(inst, "getTriangles", _SE(js_cocos2dx_spine_MeshAttachment_getTriangles));
    cls->defineFunction(inst, "getRegionOffsetY", _SE(js_cocos2dx_spine_MeshAttachment_getRegionOffsetY));
    cls->defineFunction(inst, "getRegionOffsetX", _SE(js_cocos2dx_spine_MeshAttachment_getRegionOffsetX));
    cls->defineFunction(inst, "getRegionV", _SE(js_cocos2dx_spine_MeshAttachment_getRegionV));
    cls->defineFunction(inst, "getRegionRotate", _SE(js_cocos2dx_spine_MeshAttachment_getRegionRotate));
    cls->defineFunction(inst, "getParentMesh", _SE(js_cocos2dx_spine_MeshAttachment_getParentMesh));
    cls->defineFunction(inst, "getRegionU", _SE(js_cocos2dx_spine_MeshAttachment_getRegionU));
    cls->install(inst);
    inst->registerClass<spine::MeshAttachment>(cls);

    __jsb_spine_MeshAttachment_proto = cls->getProto();
    __jsb_spine_MeshAttachment_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_PathAttachment_proto = nullptr;
se::Class* __jsb_spine_PathAttachment_class = nullptr;

static bool js_cocos2dx_spine_PathAttachment_isConstantSpeed(se::State &s, se::ScriptEngine *inst)
{
    spine::PathAttachment* cobj = (spine::PathAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathAttachment_isConstantSpeed : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isConstantSpeed();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathAttachment_isConstantSpeed : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathAttachment_isConstantSpeed)

static bool js_cocos2dx_spine_PathAttachment_isClosed(se::State &s, se::ScriptEngine *inst)
{
    spine::PathAttachment* cobj = (spine::PathAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathAttachment_isClosed : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isClosed();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathAttachment_isClosed : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathAttachment_isClosed)

static bool js_cocos2dx_spine_PathAttachment_setConstantSpeed(se::State &s, se::ScriptEngine *inst)
{
    spine::PathAttachment* cobj = (spine::PathAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathAttachment_setConstantSpeed : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathAttachment_setConstantSpeed : Error processing arguments");
        cobj->setConstantSpeed(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathAttachment_setConstantSpeed)

static bool js_cocos2dx_spine_PathAttachment_setClosed(se::State &s, se::ScriptEngine *inst)
{
    spine::PathAttachment* cobj = (spine::PathAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathAttachment_setClosed : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathAttachment_setClosed : Error processing arguments");
        cobj->setClosed(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathAttachment_setClosed)

static bool js_cocos2dx_spine_PathAttachment_getLengths(se::State &s, se::ScriptEngine *inst)
{
    spine::PathAttachment* cobj = (spine::PathAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathAttachment_getLengths : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<float>& result = cobj->getLengths();
        ok &= spine_Vector_T_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathAttachment_getLengths : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathAttachment_getLengths)

static bool js_cocos2dx_spine_PathAttachment_copy(se::State &s, se::ScriptEngine *inst)
{
    spine::PathAttachment* cobj = (spine::PathAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathAttachment_copy : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Attachment* result = cobj->copy();
        ok &= native_ptr_to_rooted_seval<spine::Attachment>(inst, (spine::Attachment*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathAttachment_copy : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathAttachment_copy)


extern se::Object* __jsb_spine_VertexAttachment_proto;


bool js_register_cocos2dx_spine_PathAttachment(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "PathAttachment", obj, __jsb_spine_VertexAttachment_proto, nullptr);

    cls->defineFunction(inst, "isConstantSpeed", _SE(js_cocos2dx_spine_PathAttachment_isConstantSpeed));
    cls->defineFunction(inst, "isClosed", _SE(js_cocos2dx_spine_PathAttachment_isClosed));
    cls->defineFunction(inst, "setConstantSpeed", _SE(js_cocos2dx_spine_PathAttachment_setConstantSpeed));
    cls->defineFunction(inst, "setClosed", _SE(js_cocos2dx_spine_PathAttachment_setClosed));
    cls->defineFunction(inst, "getLengths", _SE(js_cocos2dx_spine_PathAttachment_getLengths));
    cls->defineFunction(inst, "copy", _SE(js_cocos2dx_spine_PathAttachment_copy));
    cls->install(inst);
    inst->registerClass<spine::PathAttachment>(cls);

    __jsb_spine_PathAttachment_proto = cls->getProto();
    __jsb_spine_PathAttachment_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_PathConstraint_proto = nullptr;
se::Class* __jsb_spine_PathConstraint_class = nullptr;

static bool js_cocos2dx_spine_PathConstraint_setSpacing(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraint* cobj = (spine::PathConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraint_setSpacing : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraint_setSpacing : Error processing arguments");
        cobj->setSpacing(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraint_setSpacing)

static bool js_cocos2dx_spine_PathConstraint_setRotateMix(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraint* cobj = (spine::PathConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraint_setRotateMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraint_setRotateMix : Error processing arguments");
        cobj->setRotateMix(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraint_setRotateMix)

static bool js_cocos2dx_spine_PathConstraint_getRotateMix(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraint* cobj = (spine::PathConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraint_getRotateMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRotateMix();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraint_getRotateMix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraint_getRotateMix)

static bool js_cocos2dx_spine_PathConstraint_setActive(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraint* cobj = (spine::PathConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraint_setActive : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraint_setActive : Error processing arguments");
        cobj->setActive(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraint_setActive)

static bool js_cocos2dx_spine_PathConstraint_getBones(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraint* cobj = (spine::PathConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraint_getBones : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::Bone *>& result = cobj->getBones();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraint_getBones : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraint_getBones)

static bool js_cocos2dx_spine_PathConstraint_setTarget(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraint* cobj = (spine::PathConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraint_setTarget : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::Slot* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraint_setTarget : Error processing arguments");
        cobj->setTarget(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraint_setTarget)

static bool js_cocos2dx_spine_PathConstraint_getTranslateMix(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraint* cobj = (spine::PathConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraint_getTranslateMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTranslateMix();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraint_getTranslateMix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraint_getTranslateMix)

static bool js_cocos2dx_spine_PathConstraint_update(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraint* cobj = (spine::PathConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraint_update : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->update();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraint_update)

static bool js_cocos2dx_spine_PathConstraint_getTarget(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraint* cobj = (spine::PathConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraint_getTarget : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Slot* result = cobj->getTarget();
        ok &= native_ptr_to_rooted_seval<spine::Slot>(inst, (spine::Slot*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraint_getTarget : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraint_getTarget)

static bool js_cocos2dx_spine_PathConstraint_getSpacing(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraint* cobj = (spine::PathConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraint_getSpacing : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getSpacing();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraint_getSpacing : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraint_getSpacing)

static bool js_cocos2dx_spine_PathConstraint_getOrder(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraint* cobj = (spine::PathConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraint_getOrder : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getOrder();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraint_getOrder : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraint_getOrder)

static bool js_cocos2dx_spine_PathConstraint_isActive(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraint* cobj = (spine::PathConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraint_isActive : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isActive();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraint_isActive : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraint_isActive)

static bool js_cocos2dx_spine_PathConstraint_apply(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraint* cobj = (spine::PathConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraint_apply : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->apply();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraint_apply)

static bool js_cocos2dx_spine_PathConstraint_setPosition(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraint* cobj = (spine::PathConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraint_setPosition : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraint_setPosition : Error processing arguments");
        cobj->setPosition(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraint_setPosition)

static bool js_cocos2dx_spine_PathConstraint_getData(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraint* cobj = (spine::PathConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraint_getData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::PathConstraintData& result = cobj->getData();
        ok &= native_ptr_to_rooted_seval<spine::PathConstraintData>(inst, (spine::PathConstraintData*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraint_getData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraint_getData)

static bool js_cocos2dx_spine_PathConstraint_getPosition(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraint* cobj = (spine::PathConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraint_getPosition : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getPosition();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraint_getPosition : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraint_getPosition)

static bool js_cocos2dx_spine_PathConstraint_setTranslateMix(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraint* cobj = (spine::PathConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraint_setTranslateMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraint_setTranslateMix : Error processing arguments");
        cobj->setTranslateMix(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraint_setTranslateMix)




bool js_register_cocos2dx_spine_PathConstraint(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "PathConstraint", obj, nullptr, nullptr);

    cls->defineFunction(inst, "setSpacing", _SE(js_cocos2dx_spine_PathConstraint_setSpacing));
    cls->defineFunction(inst, "setRotateMix", _SE(js_cocos2dx_spine_PathConstraint_setRotateMix));
    cls->defineFunction(inst, "getRotateMix", _SE(js_cocos2dx_spine_PathConstraint_getRotateMix));
    cls->defineFunction(inst, "setActive", _SE(js_cocos2dx_spine_PathConstraint_setActive));
    cls->defineFunction(inst, "getBones", _SE(js_cocos2dx_spine_PathConstraint_getBones));
    cls->defineFunction(inst, "setTarget", _SE(js_cocos2dx_spine_PathConstraint_setTarget));
    cls->defineFunction(inst, "getTranslateMix", _SE(js_cocos2dx_spine_PathConstraint_getTranslateMix));
    cls->defineFunction(inst, "update", _SE(js_cocos2dx_spine_PathConstraint_update));
    cls->defineFunction(inst, "getTarget", _SE(js_cocos2dx_spine_PathConstraint_getTarget));
    cls->defineFunction(inst, "getSpacing", _SE(js_cocos2dx_spine_PathConstraint_getSpacing));
    cls->defineFunction(inst, "getOrder", _SE(js_cocos2dx_spine_PathConstraint_getOrder));
    cls->defineFunction(inst, "isActive", _SE(js_cocos2dx_spine_PathConstraint_isActive));
    cls->defineFunction(inst, "apply", _SE(js_cocos2dx_spine_PathConstraint_apply));
    cls->defineFunction(inst, "setPosition", _SE(js_cocos2dx_spine_PathConstraint_setPosition));
    cls->defineFunction(inst, "getData", _SE(js_cocos2dx_spine_PathConstraint_getData));
    cls->defineFunction(inst, "getPosition", _SE(js_cocos2dx_spine_PathConstraint_getPosition));
    cls->defineFunction(inst, "setTranslateMix", _SE(js_cocos2dx_spine_PathConstraint_setTranslateMix));
    cls->install(inst);
    inst->registerClass<spine::PathConstraint>(cls);

    __jsb_spine_PathConstraint_proto = cls->getProto();
    __jsb_spine_PathConstraint_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_PathConstraintData_proto = nullptr;
se::Class* __jsb_spine_PathConstraintData_class = nullptr;

static bool js_cocos2dx_spine_PathConstraintData_setOffsetRotation(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_setOffsetRotation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_setOffsetRotation : Error processing arguments");
        cobj->setOffsetRotation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_setOffsetRotation)

static bool js_cocos2dx_spine_PathConstraintData_setSpacing(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_setSpacing : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_setSpacing : Error processing arguments");
        cobj->setSpacing(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_setSpacing)

static bool js_cocos2dx_spine_PathConstraintData_getOffsetRotation(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_getOffsetRotation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getOffsetRotation();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_getOffsetRotation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_getOffsetRotation)

static bool js_cocos2dx_spine_PathConstraintData_setSpacingMode(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_setSpacingMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::SpacingMode arg0;
        ok &= seval_to_uint32(inst, args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_setSpacingMode : Error processing arguments");
        cobj->setSpacingMode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_setSpacingMode)

static bool js_cocos2dx_spine_PathConstraintData_getRotateMix(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_getRotateMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRotateMix();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_getRotateMix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_getRotateMix)

static bool js_cocos2dx_spine_PathConstraintData_getPositionMode(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_getPositionMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = (unsigned int)cobj->getPositionMode();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_getPositionMode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_getPositionMode)

static bool js_cocos2dx_spine_PathConstraintData_getBones(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_getBones : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::BoneData *>& result = cobj->getBones();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_getBones : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_getBones)

static bool js_cocos2dx_spine_PathConstraintData_setTarget(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_setTarget : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::SlotData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_setTarget : Error processing arguments");
        cobj->setTarget(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_setTarget)

static bool js_cocos2dx_spine_PathConstraintData_getTranslateMix(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_getTranslateMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTranslateMix();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_getTranslateMix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_getTranslateMix)

static bool js_cocos2dx_spine_PathConstraintData_getSpacing(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_getSpacing : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getSpacing();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_getSpacing : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_getSpacing)

static bool js_cocos2dx_spine_PathConstraintData_getTarget(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_getTarget : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::SlotData* result = cobj->getTarget();
        ok &= native_ptr_to_rooted_seval<spine::SlotData>(inst, (spine::SlotData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_getTarget : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_getTarget)

static bool js_cocos2dx_spine_PathConstraintData_getRotateMode(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_getRotateMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = (unsigned int)cobj->getRotateMode();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_getRotateMode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_getRotateMode)

static bool js_cocos2dx_spine_PathConstraintData_setRotateMode(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_setRotateMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::RotateMode arg0;
        ok &= seval_to_uint32(inst, args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_setRotateMode : Error processing arguments");
        cobj->setRotateMode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_setRotateMode)

static bool js_cocos2dx_spine_PathConstraintData_getSpacingMode(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_getSpacingMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = (unsigned int)cobj->getSpacingMode();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_getSpacingMode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_getSpacingMode)

static bool js_cocos2dx_spine_PathConstraintData_setRotateMix(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_setRotateMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_setRotateMix : Error processing arguments");
        cobj->setRotateMix(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_setRotateMix)

static bool js_cocos2dx_spine_PathConstraintData_setPosition(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_setPosition : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_setPosition : Error processing arguments");
        cobj->setPosition(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_setPosition)

static bool js_cocos2dx_spine_PathConstraintData_setPositionMode(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_setPositionMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::PositionMode arg0;
        ok &= seval_to_uint32(inst, args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_setPositionMode : Error processing arguments");
        cobj->setPositionMode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_setPositionMode)

static bool js_cocos2dx_spine_PathConstraintData_getPosition(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_getPosition : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getPosition();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_getPosition : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_getPosition)

static bool js_cocos2dx_spine_PathConstraintData_setTranslateMix(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintData* cobj = (spine::PathConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintData_setTranslateMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintData_setTranslateMix : Error processing arguments");
        cobj->setTranslateMix(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintData_setTranslateMix)


extern se::Object* __jsb_spine_ConstraintData_proto;


bool js_register_cocos2dx_spine_PathConstraintData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "PathConstraintData", obj, __jsb_spine_ConstraintData_proto, nullptr);

    cls->defineFunction(inst, "setOffsetRotation", _SE(js_cocos2dx_spine_PathConstraintData_setOffsetRotation));
    cls->defineFunction(inst, "setSpacing", _SE(js_cocos2dx_spine_PathConstraintData_setSpacing));
    cls->defineFunction(inst, "getOffsetRotation", _SE(js_cocos2dx_spine_PathConstraintData_getOffsetRotation));
    cls->defineFunction(inst, "setSpacingMode", _SE(js_cocos2dx_spine_PathConstraintData_setSpacingMode));
    cls->defineFunction(inst, "getRotateMix", _SE(js_cocos2dx_spine_PathConstraintData_getRotateMix));
    cls->defineFunction(inst, "getPositionMode", _SE(js_cocos2dx_spine_PathConstraintData_getPositionMode));
    cls->defineFunction(inst, "getBones", _SE(js_cocos2dx_spine_PathConstraintData_getBones));
    cls->defineFunction(inst, "setTarget", _SE(js_cocos2dx_spine_PathConstraintData_setTarget));
    cls->defineFunction(inst, "getTranslateMix", _SE(js_cocos2dx_spine_PathConstraintData_getTranslateMix));
    cls->defineFunction(inst, "getSpacing", _SE(js_cocos2dx_spine_PathConstraintData_getSpacing));
    cls->defineFunction(inst, "getTarget", _SE(js_cocos2dx_spine_PathConstraintData_getTarget));
    cls->defineFunction(inst, "getRotateMode", _SE(js_cocos2dx_spine_PathConstraintData_getRotateMode));
    cls->defineFunction(inst, "setRotateMode", _SE(js_cocos2dx_spine_PathConstraintData_setRotateMode));
    cls->defineFunction(inst, "getSpacingMode", _SE(js_cocos2dx_spine_PathConstraintData_getSpacingMode));
    cls->defineFunction(inst, "setRotateMix", _SE(js_cocos2dx_spine_PathConstraintData_setRotateMix));
    cls->defineFunction(inst, "setPosition", _SE(js_cocos2dx_spine_PathConstraintData_setPosition));
    cls->defineFunction(inst, "setPositionMode", _SE(js_cocos2dx_spine_PathConstraintData_setPositionMode));
    cls->defineFunction(inst, "getPosition", _SE(js_cocos2dx_spine_PathConstraintData_getPosition));
    cls->defineFunction(inst, "setTranslateMix", _SE(js_cocos2dx_spine_PathConstraintData_setTranslateMix));
    cls->install(inst);
    inst->registerClass<spine::PathConstraintData>(cls);

    __jsb_spine_PathConstraintData_proto = cls->getProto();
    __jsb_spine_PathConstraintData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_PathConstraintMixTimeline_proto = nullptr;
se::Class* __jsb_spine_PathConstraintMixTimeline_class = nullptr;

static bool js_cocos2dx_spine_PathConstraintMixTimeline_getPropertyId(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintMixTimeline* cobj = (spine::PathConstraintMixTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintMixTimeline_getPropertyId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPropertyId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintMixTimeline_getPropertyId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintMixTimeline_getPropertyId)


extern se::Object* __jsb_spine_CurveTimeline_proto;


bool js_register_cocos2dx_spine_PathConstraintMixTimeline(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "PathConstraintMixTimeline", obj, __jsb_spine_CurveTimeline_proto, nullptr);

    cls->defineFunction(inst, "getPropertyId", _SE(js_cocos2dx_spine_PathConstraintMixTimeline_getPropertyId));
    cls->install(inst);
    inst->registerClass<spine::PathConstraintMixTimeline>(cls);

    __jsb_spine_PathConstraintMixTimeline_proto = cls->getProto();
    __jsb_spine_PathConstraintMixTimeline_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_PathConstraintPositionTimeline_proto = nullptr;
se::Class* __jsb_spine_PathConstraintPositionTimeline_class = nullptr;

static bool js_cocos2dx_spine_PathConstraintPositionTimeline_getPropertyId(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintPositionTimeline* cobj = (spine::PathConstraintPositionTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintPositionTimeline_getPropertyId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPropertyId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintPositionTimeline_getPropertyId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintPositionTimeline_getPropertyId)

static bool js_cocos2dx_spine_PathConstraintPositionTimeline_setFrame(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintPositionTimeline* cobj = (spine::PathConstraintPositionTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintPositionTimeline_setFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        int arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintPositionTimeline_setFrame : Error processing arguments");
        cobj->setFrame(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintPositionTimeline_setFrame)


extern se::Object* __jsb_spine_CurveTimeline_proto;


bool js_register_cocos2dx_spine_PathConstraintPositionTimeline(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "PathConstraintPositionTimeline", obj, __jsb_spine_CurveTimeline_proto, nullptr);

    cls->defineFunction(inst, "getPropertyId", _SE(js_cocos2dx_spine_PathConstraintPositionTimeline_getPropertyId));
    cls->defineFunction(inst, "setFrame", _SE(js_cocos2dx_spine_PathConstraintPositionTimeline_setFrame));
    cls->install(inst);
    inst->registerClass<spine::PathConstraintPositionTimeline>(cls);

    __jsb_spine_PathConstraintPositionTimeline_proto = cls->getProto();
    __jsb_spine_PathConstraintPositionTimeline_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_PathConstraintSpacingTimeline_proto = nullptr;
se::Class* __jsb_spine_PathConstraintSpacingTimeline_class = nullptr;

static bool js_cocos2dx_spine_PathConstraintSpacingTimeline_getPropertyId(se::State &s, se::ScriptEngine *inst)
{
    spine::PathConstraintSpacingTimeline* cobj = (spine::PathConstraintSpacingTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PathConstraintSpacingTimeline_getPropertyId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPropertyId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PathConstraintSpacingTimeline_getPropertyId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PathConstraintSpacingTimeline_getPropertyId)


extern se::Object* __jsb_spine_PathConstraintPositionTimeline_proto;


bool js_register_cocos2dx_spine_PathConstraintSpacingTimeline(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "PathConstraintSpacingTimeline", obj, __jsb_spine_PathConstraintPositionTimeline_proto, nullptr);

    cls->defineFunction(inst, "getPropertyId", _SE(js_cocos2dx_spine_PathConstraintSpacingTimeline_getPropertyId));
    cls->install(inst);
    inst->registerClass<spine::PathConstraintSpacingTimeline>(cls);

    __jsb_spine_PathConstraintSpacingTimeline_proto = cls->getProto();
    __jsb_spine_PathConstraintSpacingTimeline_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_PointAttachment_proto = nullptr;
se::Class* __jsb_spine_PointAttachment_class = nullptr;

static bool js_cocos2dx_spine_PointAttachment_getX(se::State &s, se::ScriptEngine *inst)
{
    spine::PointAttachment* cobj = (spine::PointAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PointAttachment_getX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PointAttachment_getX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PointAttachment_getX)

static bool js_cocos2dx_spine_PointAttachment_getY(se::State &s, se::ScriptEngine *inst)
{
    spine::PointAttachment* cobj = (spine::PointAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PointAttachment_getY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PointAttachment_getY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PointAttachment_getY)

static bool js_cocos2dx_spine_PointAttachment_getRotation(se::State &s, se::ScriptEngine *inst)
{
    spine::PointAttachment* cobj = (spine::PointAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PointAttachment_getRotation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRotation();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PointAttachment_getRotation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PointAttachment_getRotation)

static bool js_cocos2dx_spine_PointAttachment_setRotation(se::State &s, se::ScriptEngine *inst)
{
    spine::PointAttachment* cobj = (spine::PointAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PointAttachment_setRotation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PointAttachment_setRotation : Error processing arguments");
        cobj->setRotation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PointAttachment_setRotation)

static bool js_cocos2dx_spine_PointAttachment_copy(se::State &s, se::ScriptEngine *inst)
{
    spine::PointAttachment* cobj = (spine::PointAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PointAttachment_copy : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Attachment* result = cobj->copy();
        ok &= native_ptr_to_rooted_seval<spine::Attachment>(inst, (spine::Attachment*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PointAttachment_copy : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PointAttachment_copy)

static bool js_cocos2dx_spine_PointAttachment_setX(se::State &s, se::ScriptEngine *inst)
{
    spine::PointAttachment* cobj = (spine::PointAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PointAttachment_setX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PointAttachment_setX : Error processing arguments");
        cobj->setX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PointAttachment_setX)

static bool js_cocos2dx_spine_PointAttachment_setY(se::State &s, se::ScriptEngine *inst)
{
    spine::PointAttachment* cobj = (spine::PointAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_PointAttachment_setY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_PointAttachment_setY : Error processing arguments");
        cobj->setY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_PointAttachment_setY)


extern se::Object* __jsb_spine_Attachment_proto;


bool js_register_cocos2dx_spine_PointAttachment(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "PointAttachment", obj, __jsb_spine_Attachment_proto, nullptr);

    cls->defineFunction(inst, "getX", _SE(js_cocos2dx_spine_PointAttachment_getX));
    cls->defineFunction(inst, "getY", _SE(js_cocos2dx_spine_PointAttachment_getY));
    cls->defineFunction(inst, "getRotation", _SE(js_cocos2dx_spine_PointAttachment_getRotation));
    cls->defineFunction(inst, "setRotation", _SE(js_cocos2dx_spine_PointAttachment_setRotation));
    cls->defineFunction(inst, "copy", _SE(js_cocos2dx_spine_PointAttachment_copy));
    cls->defineFunction(inst, "setX", _SE(js_cocos2dx_spine_PointAttachment_setX));
    cls->defineFunction(inst, "setY", _SE(js_cocos2dx_spine_PointAttachment_setY));
    cls->install(inst);
    inst->registerClass<spine::PointAttachment>(cls);

    __jsb_spine_PointAttachment_proto = cls->getProto();
    __jsb_spine_PointAttachment_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_RegionAttachment_proto = nullptr;
se::Class* __jsb_spine_RegionAttachment_class = nullptr;

static bool js_cocos2dx_spine_RegionAttachment_setRegionOriginalHeight(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_setRegionOriginalHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_setRegionOriginalHeight : Error processing arguments");
        cobj->setRegionOriginalHeight(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_setRegionOriginalHeight)

static bool js_cocos2dx_spine_RegionAttachment_setRegionOffsetY(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_setRegionOffsetY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_setRegionOffsetY : Error processing arguments");
        cobj->setRegionOffsetY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_setRegionOffsetY)

static bool js_cocos2dx_spine_RegionAttachment_setRegionOffsetX(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_setRegionOffsetX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_setRegionOffsetX : Error processing arguments");
        cobj->setRegionOffsetX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_setRegionOffsetX)

static bool js_cocos2dx_spine_RegionAttachment_getRegionOriginalWidth(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_getRegionOriginalWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRegionOriginalWidth();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_getRegionOriginalWidth : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_getRegionOriginalWidth)

static bool js_cocos2dx_spine_RegionAttachment_setUVs(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_setUVs : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 5) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        bool arg4;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_boolean(inst, args[4], &arg4);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_setUVs : Error processing arguments");
        cobj->setUVs(arg0, arg1, arg2, arg3, arg4);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_setUVs)

static bool js_cocos2dx_spine_RegionAttachment_getWidth(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_getWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getWidth();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_getWidth : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_getWidth)

static bool js_cocos2dx_spine_RegionAttachment_getY(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_getY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_getY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_getY)

static bool js_cocos2dx_spine_RegionAttachment_getRotation(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_getRotation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRotation();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_getRotation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_getRotation)

static bool js_cocos2dx_spine_RegionAttachment_setWidth(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_setWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_setWidth : Error processing arguments");
        cobj->setWidth(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_setWidth)

static bool js_cocos2dx_spine_RegionAttachment_setRegionWidth(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_setRegionWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_setRegionWidth : Error processing arguments");
        cobj->setRegionWidth(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_setRegionWidth)

static bool js_cocos2dx_spine_RegionAttachment_getUVs(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_getUVs : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<float>& result = cobj->getUVs();
        ok &= spine_Vector_T_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_getUVs : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_getUVs)

static bool js_cocos2dx_spine_RegionAttachment_getRegionHeight(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_getRegionHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRegionHeight();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_getRegionHeight : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_getRegionHeight)

static bool js_cocos2dx_spine_RegionAttachment_getScaleY(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_getScaleY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getScaleY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_getScaleY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_getScaleY)

static bool js_cocos2dx_spine_RegionAttachment_getScaleX(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_getScaleX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getScaleX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_getScaleX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_getScaleX)

static bool js_cocos2dx_spine_RegionAttachment_getHeight(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_getHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getHeight();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_getHeight : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_getHeight)

static bool js_cocos2dx_spine_RegionAttachment_getPath(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_getPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getPath();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_getPath : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_getPath)

static bool js_cocos2dx_spine_RegionAttachment_setRotation(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_setRotation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_setRotation : Error processing arguments");
        cobj->setRotation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_setRotation)

static bool js_cocos2dx_spine_RegionAttachment_setPath(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_setPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_setPath : Error processing arguments");
        cobj->setPath(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_setPath)

static bool js_cocos2dx_spine_RegionAttachment_getRegionWidth(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_getRegionWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRegionWidth();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_getRegionWidth : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_getRegionWidth)

static bool js_cocos2dx_spine_RegionAttachment_setScaleY(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_setScaleY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_setScaleY : Error processing arguments");
        cobj->setScaleY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_setScaleY)

static bool js_cocos2dx_spine_RegionAttachment_setScaleX(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_setScaleX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_setScaleX : Error processing arguments");
        cobj->setScaleX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_setScaleX)

static bool js_cocos2dx_spine_RegionAttachment_setRegionOriginalWidth(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_setRegionOriginalWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_setRegionOriginalWidth : Error processing arguments");
        cobj->setRegionOriginalWidth(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_setRegionOriginalWidth)

static bool js_cocos2dx_spine_RegionAttachment_getColor(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_getColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Color& result = cobj->getColor();
        ok &= native_ptr_to_rooted_seval<spine::Color>(inst, (spine::Color*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_getColor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_getColor)

static bool js_cocos2dx_spine_RegionAttachment_copy(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_copy : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Attachment* result = cobj->copy();
        ok &= native_ptr_to_rooted_seval<spine::Attachment>(inst, (spine::Attachment*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_copy : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_copy)

static bool js_cocos2dx_spine_RegionAttachment_setX(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_setX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_setX : Error processing arguments");
        cobj->setX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_setX)

static bool js_cocos2dx_spine_RegionAttachment_setY(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_setY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_setY : Error processing arguments");
        cobj->setY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_setY)

static bool js_cocos2dx_spine_RegionAttachment_setHeight(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_setHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_setHeight : Error processing arguments");
        cobj->setHeight(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_setHeight)

static bool js_cocos2dx_spine_RegionAttachment_getX(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_getX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_getX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_getX)

static bool js_cocos2dx_spine_RegionAttachment_getOffset(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_getOffset : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<float>& result = cobj->getOffset();
        ok &= spine_Vector_T_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_getOffset : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_getOffset)

static bool js_cocos2dx_spine_RegionAttachment_setRegionHeight(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_setRegionHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_setRegionHeight : Error processing arguments");
        cobj->setRegionHeight(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_setRegionHeight)

static bool js_cocos2dx_spine_RegionAttachment_updateOffset(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_updateOffset : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->updateOffset();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_updateOffset)

static bool js_cocos2dx_spine_RegionAttachment_getRegionOriginalHeight(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_getRegionOriginalHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRegionOriginalHeight();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_getRegionOriginalHeight : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_getRegionOriginalHeight)

static bool js_cocos2dx_spine_RegionAttachment_getRegionOffsetY(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_getRegionOffsetY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRegionOffsetY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_getRegionOffsetY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_getRegionOffsetY)

static bool js_cocos2dx_spine_RegionAttachment_getRegionOffsetX(se::State &s, se::ScriptEngine *inst)
{
    spine::RegionAttachment* cobj = (spine::RegionAttachment*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RegionAttachment_getRegionOffsetX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRegionOffsetX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RegionAttachment_getRegionOffsetX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RegionAttachment_getRegionOffsetX)


extern se::Object* __jsb_spine_Attachment_proto;


bool js_register_cocos2dx_spine_RegionAttachment(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "RegionAttachment", obj, __jsb_spine_Attachment_proto, nullptr);

    cls->defineFunction(inst, "setRegionOriginalHeight", _SE(js_cocos2dx_spine_RegionAttachment_setRegionOriginalHeight));
    cls->defineFunction(inst, "setRegionOffsetY", _SE(js_cocos2dx_spine_RegionAttachment_setRegionOffsetY));
    cls->defineFunction(inst, "setRegionOffsetX", _SE(js_cocos2dx_spine_RegionAttachment_setRegionOffsetX));
    cls->defineFunction(inst, "getRegionOriginalWidth", _SE(js_cocos2dx_spine_RegionAttachment_getRegionOriginalWidth));
    cls->defineFunction(inst, "setUVs", _SE(js_cocos2dx_spine_RegionAttachment_setUVs));
    cls->defineFunction(inst, "getWidth", _SE(js_cocos2dx_spine_RegionAttachment_getWidth));
    cls->defineFunction(inst, "getY", _SE(js_cocos2dx_spine_RegionAttachment_getY));
    cls->defineFunction(inst, "getRotation", _SE(js_cocos2dx_spine_RegionAttachment_getRotation));
    cls->defineFunction(inst, "setWidth", _SE(js_cocos2dx_spine_RegionAttachment_setWidth));
    cls->defineFunction(inst, "setRegionWidth", _SE(js_cocos2dx_spine_RegionAttachment_setRegionWidth));
    cls->defineFunction(inst, "getUVs", _SE(js_cocos2dx_spine_RegionAttachment_getUVs));
    cls->defineFunction(inst, "getRegionHeight", _SE(js_cocos2dx_spine_RegionAttachment_getRegionHeight));
    cls->defineFunction(inst, "getScaleY", _SE(js_cocos2dx_spine_RegionAttachment_getScaleY));
    cls->defineFunction(inst, "getScaleX", _SE(js_cocos2dx_spine_RegionAttachment_getScaleX));
    cls->defineFunction(inst, "getHeight", _SE(js_cocos2dx_spine_RegionAttachment_getHeight));
    cls->defineFunction(inst, "getPath", _SE(js_cocos2dx_spine_RegionAttachment_getPath));
    cls->defineFunction(inst, "setRotation", _SE(js_cocos2dx_spine_RegionAttachment_setRotation));
    cls->defineFunction(inst, "setPath", _SE(js_cocos2dx_spine_RegionAttachment_setPath));
    cls->defineFunction(inst, "getRegionWidth", _SE(js_cocos2dx_spine_RegionAttachment_getRegionWidth));
    cls->defineFunction(inst, "setScaleY", _SE(js_cocos2dx_spine_RegionAttachment_setScaleY));
    cls->defineFunction(inst, "setScaleX", _SE(js_cocos2dx_spine_RegionAttachment_setScaleX));
    cls->defineFunction(inst, "setRegionOriginalWidth", _SE(js_cocos2dx_spine_RegionAttachment_setRegionOriginalWidth));
    cls->defineFunction(inst, "getColor", _SE(js_cocos2dx_spine_RegionAttachment_getColor));
    cls->defineFunction(inst, "copy", _SE(js_cocos2dx_spine_RegionAttachment_copy));
    cls->defineFunction(inst, "setX", _SE(js_cocos2dx_spine_RegionAttachment_setX));
    cls->defineFunction(inst, "setY", _SE(js_cocos2dx_spine_RegionAttachment_setY));
    cls->defineFunction(inst, "setHeight", _SE(js_cocos2dx_spine_RegionAttachment_setHeight));
    cls->defineFunction(inst, "getX", _SE(js_cocos2dx_spine_RegionAttachment_getX));
    cls->defineFunction(inst, "getOffset", _SE(js_cocos2dx_spine_RegionAttachment_getOffset));
    cls->defineFunction(inst, "setRegionHeight", _SE(js_cocos2dx_spine_RegionAttachment_setRegionHeight));
    cls->defineFunction(inst, "updateOffset", _SE(js_cocos2dx_spine_RegionAttachment_updateOffset));
    cls->defineFunction(inst, "getRegionOriginalHeight", _SE(js_cocos2dx_spine_RegionAttachment_getRegionOriginalHeight));
    cls->defineFunction(inst, "getRegionOffsetY", _SE(js_cocos2dx_spine_RegionAttachment_getRegionOffsetY));
    cls->defineFunction(inst, "getRegionOffsetX", _SE(js_cocos2dx_spine_RegionAttachment_getRegionOffsetX));
    cls->install(inst);
    inst->registerClass<spine::RegionAttachment>(cls);

    __jsb_spine_RegionAttachment_proto = cls->getProto();
    __jsb_spine_RegionAttachment_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_RotateTimeline_proto = nullptr;
se::Class* __jsb_spine_RotateTimeline_class = nullptr;

static bool js_cocos2dx_spine_RotateTimeline_getPropertyId(se::State &s, se::ScriptEngine *inst)
{
    spine::RotateTimeline* cobj = (spine::RotateTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RotateTimeline_getPropertyId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPropertyId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RotateTimeline_getPropertyId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RotateTimeline_getPropertyId)

static bool js_cocos2dx_spine_RotateTimeline_setFrame(se::State &s, se::ScriptEngine *inst)
{
    spine::RotateTimeline* cobj = (spine::RotateTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RotateTimeline_setFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        int arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RotateTimeline_setFrame : Error processing arguments");
        cobj->setFrame(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RotateTimeline_setFrame)

static bool js_cocos2dx_spine_RotateTimeline_getFrames(se::State &s, se::ScriptEngine *inst)
{
    spine::RotateTimeline* cobj = (spine::RotateTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RotateTimeline_getFrames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<float>& result = cobj->getFrames();
        ok &= spine_Vector_T_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RotateTimeline_getFrames : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RotateTimeline_getFrames)

static bool js_cocos2dx_spine_RotateTimeline_setBoneIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::RotateTimeline* cobj = (spine::RotateTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RotateTimeline_setBoneIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RotateTimeline_setBoneIndex : Error processing arguments");
        cobj->setBoneIndex(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RotateTimeline_setBoneIndex)

static bool js_cocos2dx_spine_RotateTimeline_getBoneIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::RotateTimeline* cobj = (spine::RotateTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_RotateTimeline_getBoneIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getBoneIndex();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_RotateTimeline_getBoneIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_RotateTimeline_getBoneIndex)


extern se::Object* __jsb_spine_CurveTimeline_proto;


bool js_register_cocos2dx_spine_RotateTimeline(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "RotateTimeline", obj, __jsb_spine_CurveTimeline_proto, nullptr);

    cls->defineFunction(inst, "getPropertyId", _SE(js_cocos2dx_spine_RotateTimeline_getPropertyId));
    cls->defineFunction(inst, "setFrame", _SE(js_cocos2dx_spine_RotateTimeline_setFrame));
    cls->defineFunction(inst, "getFrames", _SE(js_cocos2dx_spine_RotateTimeline_getFrames));
    cls->defineFunction(inst, "setBoneIndex", _SE(js_cocos2dx_spine_RotateTimeline_setBoneIndex));
    cls->defineFunction(inst, "getBoneIndex", _SE(js_cocos2dx_spine_RotateTimeline_getBoneIndex));
    cls->install(inst);
    inst->registerClass<spine::RotateTimeline>(cls);

    __jsb_spine_RotateTimeline_proto = cls->getProto();
    __jsb_spine_RotateTimeline_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_TranslateTimeline_proto = nullptr;
se::Class* __jsb_spine_TranslateTimeline_class = nullptr;

static bool js_cocos2dx_spine_TranslateTimeline_getPropertyId(se::State &s, se::ScriptEngine *inst)
{
    spine::TranslateTimeline* cobj = (spine::TranslateTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TranslateTimeline_getPropertyId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPropertyId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TranslateTimeline_getPropertyId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TranslateTimeline_getPropertyId)

static bool js_cocos2dx_spine_TranslateTimeline_setFrame(se::State &s, se::ScriptEngine *inst)
{
    spine::TranslateTimeline* cobj = (spine::TranslateTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TranslateTimeline_setFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        int arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TranslateTimeline_setFrame : Error processing arguments");
        cobj->setFrame(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TranslateTimeline_setFrame)


extern se::Object* __jsb_spine_CurveTimeline_proto;


bool js_register_cocos2dx_spine_TranslateTimeline(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "TranslateTimeline", obj, __jsb_spine_CurveTimeline_proto, nullptr);

    cls->defineFunction(inst, "getPropertyId", _SE(js_cocos2dx_spine_TranslateTimeline_getPropertyId));
    cls->defineFunction(inst, "setFrame", _SE(js_cocos2dx_spine_TranslateTimeline_setFrame));
    cls->install(inst);
    inst->registerClass<spine::TranslateTimeline>(cls);

    __jsb_spine_TranslateTimeline_proto = cls->getProto();
    __jsb_spine_TranslateTimeline_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_ScaleTimeline_proto = nullptr;
se::Class* __jsb_spine_ScaleTimeline_class = nullptr;

static bool js_cocos2dx_spine_ScaleTimeline_getPropertyId(se::State &s, se::ScriptEngine *inst)
{
    spine::ScaleTimeline* cobj = (spine::ScaleTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_ScaleTimeline_getPropertyId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPropertyId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_ScaleTimeline_getPropertyId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_ScaleTimeline_getPropertyId)


extern se::Object* __jsb_spine_TranslateTimeline_proto;


bool js_register_cocos2dx_spine_ScaleTimeline(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "ScaleTimeline", obj, __jsb_spine_TranslateTimeline_proto, nullptr);

    cls->defineFunction(inst, "getPropertyId", _SE(js_cocos2dx_spine_ScaleTimeline_getPropertyId));
    cls->install(inst);
    inst->registerClass<spine::ScaleTimeline>(cls);

    __jsb_spine_ScaleTimeline_proto = cls->getProto();
    __jsb_spine_ScaleTimeline_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_ShearTimeline_proto = nullptr;
se::Class* __jsb_spine_ShearTimeline_class = nullptr;

static bool js_cocos2dx_spine_ShearTimeline_getPropertyId(se::State &s, se::ScriptEngine *inst)
{
    spine::ShearTimeline* cobj = (spine::ShearTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_ShearTimeline_getPropertyId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPropertyId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_ShearTimeline_getPropertyId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_ShearTimeline_getPropertyId)


extern se::Object* __jsb_spine_TranslateTimeline_proto;


bool js_register_cocos2dx_spine_ShearTimeline(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "ShearTimeline", obj, __jsb_spine_TranslateTimeline_proto, nullptr);

    cls->defineFunction(inst, "getPropertyId", _SE(js_cocos2dx_spine_ShearTimeline_getPropertyId));
    cls->install(inst);
    inst->registerClass<spine::ShearTimeline>(cls);

    __jsb_spine_ShearTimeline_proto = cls->getProto();
    __jsb_spine_ShearTimeline_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_Skeleton_proto = nullptr;
se::Class* __jsb_spine_Skeleton_class = nullptr;

static bool js_cocos2dx_spine_Skeleton_setToSetupPose(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_setToSetupPose : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->setToSetupPose();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_setToSetupPose)

static bool js_cocos2dx_spine_Skeleton_getSkin(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_getSkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Skin* result = cobj->getSkin();
        ok &= native_ptr_to_rooted_seval<spine::Skin>(inst, (spine::Skin*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getSkin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_getSkin)

static bool js_cocos2dx_spine_Skeleton_getX(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_getX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_getX)

static bool js_cocos2dx_spine_Skeleton_findTransformConstraint(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_findTransformConstraint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_findTransformConstraint : Error processing arguments");
        spine::TransformConstraint* result = cobj->findTransformConstraint(arg0);
        ok &= native_ptr_to_rooted_seval<spine::TransformConstraint>(inst, (spine::TransformConstraint*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_findTransformConstraint : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_findTransformConstraint)

static bool js_cocos2dx_spine_Skeleton_setAttachment(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_setAttachment : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        spine::String arg0;
        spine::String arg1;
        arg0 = args[0].toStringForce().c_str();
        arg1 = args[1].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_setAttachment : Error processing arguments");
        cobj->setAttachment(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_setAttachment)

static bool js_cocos2dx_spine_Skeleton_findIkConstraint(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_findIkConstraint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_findIkConstraint : Error processing arguments");
        spine::IkConstraint* result = cobj->findIkConstraint(arg0);
        ok &= native_ptr_to_rooted_seval<spine::IkConstraint>(inst, (spine::IkConstraint*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_findIkConstraint : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_findIkConstraint)

static bool js_cocos2dx_spine_Skeleton_setBonesToSetupPose(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_setBonesToSetupPose : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->setBonesToSetupPose();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_setBonesToSetupPose)

static bool js_cocos2dx_spine_Skeleton_getScaleY(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_getScaleY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getScaleY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getScaleY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_getScaleY)

static bool js_cocos2dx_spine_Skeleton_getScaleX(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_getScaleX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getScaleX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getScaleX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_getScaleX)

static bool js_cocos2dx_spine_Skeleton_findBoneIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_findBoneIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_findBoneIndex : Error processing arguments");
        int result = cobj->findBoneIndex(arg0);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_findBoneIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_findBoneIndex)

static bool js_cocos2dx_spine_Skeleton_setSlotsToSetupPose(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_setSlotsToSetupPose : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->setSlotsToSetupPose();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_setSlotsToSetupPose)

static bool js_cocos2dx_spine_Skeleton_getDrawOrder(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_getDrawOrder : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::Slot *>& result = cobj->getDrawOrder();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getDrawOrder : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_getDrawOrder)

static bool js_cocos2dx_spine_Skeleton_getTime(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_getTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTime();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getTime : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_getTime)

static bool js_cocos2dx_spine_Skeleton_getColor(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_getColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Color& result = cobj->getColor();
        ok &= native_ptr_to_rooted_seval<spine::Color>(inst, (spine::Color*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getColor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_getColor)

static bool js_cocos2dx_spine_Skeleton_getIkConstraints(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_getIkConstraints : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::IkConstraint *>& result = cobj->getIkConstraints();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getIkConstraints : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_getIkConstraints)

static bool js_cocos2dx_spine_Skeleton_getData(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_getData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::SkeletonData* result = cobj->getData();
        ok &= native_ptr_to_rooted_seval<spine::SkeletonData>(inst, (spine::SkeletonData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_getData)

static bool js_cocos2dx_spine_Skeleton_getUpdateCacheList(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_getUpdateCacheList : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::Updatable *>& result = cobj->getUpdateCacheList();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getUpdateCacheList : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_getUpdateCacheList)

static bool js_cocos2dx_spine_Skeleton_setScaleY(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_setScaleY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_setScaleY : Error processing arguments");
        cobj->setScaleY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_setScaleY)

static bool js_cocos2dx_spine_Skeleton_setScaleX(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_setScaleX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_setScaleX : Error processing arguments");
        cobj->setScaleX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_setScaleX)

static bool js_cocos2dx_spine_Skeleton_getPathConstraints(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_getPathConstraints : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::PathConstraint *>& result = cobj->getPathConstraints();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getPathConstraints : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_getPathConstraints)

static bool js_cocos2dx_spine_Skeleton_getSlots(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_getSlots : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::Slot *>& result = cobj->getSlots();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getSlots : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_getSlots)

static bool js_cocos2dx_spine_Skeleton_printUpdateCache(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_printUpdateCache : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->printUpdateCache();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_printUpdateCache)

static bool js_cocos2dx_spine_Skeleton_update(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_update : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_update : Error processing arguments");
        cobj->update(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_update)

static bool js_cocos2dx_spine_Skeleton_getAttachment(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_spine_Skeleton_getAttachment : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            int arg0 = 0;
            do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
            if (!ok) { ok = true; break; }
            spine::String arg1;
            arg1 = args[1].toStringForce().c_str();
            if (!ok) { ok = true; break; }
            spine::Attachment* result = cobj->getAttachment(arg0, arg1);
            ok &= native_ptr_to_rooted_seval<spine::Attachment>(inst, (spine::Attachment*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getAttachment : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            spine::String arg0;
            arg0 = args[0].toStringForce().c_str();
            if (!ok) { ok = true; break; }
            spine::String arg1;
            arg1 = args[1].toStringForce().c_str();
            if (!ok) { ok = true; break; }
            spine::Attachment* result = cobj->getAttachment(arg0, arg1);
            ok &= native_ptr_to_rooted_seval<spine::Attachment>(inst, (spine::Attachment*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getAttachment : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_getAttachment)

static bool js_cocos2dx_spine_Skeleton_setTime(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_setTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_setTime : Error processing arguments");
        cobj->setTime(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_setTime)

static bool js_cocos2dx_spine_Skeleton_setPosition(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_setPosition : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_setPosition : Error processing arguments");
        cobj->setPosition(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_setPosition)

static bool js_cocos2dx_spine_Skeleton_setX(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_setX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_setX : Error processing arguments");
        cobj->setX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_setX)

static bool js_cocos2dx_spine_Skeleton_setY(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_setY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_setY : Error processing arguments");
        cobj->setY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_setY)

static bool js_cocos2dx_spine_Skeleton_findBone(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_findBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_findBone : Error processing arguments");
        spine::Bone* result = cobj->findBone(arg0);
        ok &= native_ptr_to_rooted_seval<spine::Bone>(inst, (spine::Bone*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_findBone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_findBone)

static bool js_cocos2dx_spine_Skeleton_getY(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_getY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_getY)

static bool js_cocos2dx_spine_Skeleton_getBones(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_getBones : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::Bone *>& result = cobj->getBones();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getBones : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_getBones)

static bool js_cocos2dx_spine_Skeleton_getRootBone(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_getRootBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Bone* result = cobj->getRootBone();
        ok &= native_ptr_to_rooted_seval<spine::Bone>(inst, (spine::Bone*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getRootBone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_getRootBone)

static bool js_cocos2dx_spine_Skeleton_updateCache(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_updateCache : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->updateCache();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_updateCache)

static bool js_cocos2dx_spine_Skeleton_findSlotIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_findSlotIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_findSlotIndex : Error processing arguments");
        int result = cobj->findSlotIndex(arg0);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_findSlotIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_findSlotIndex)

static bool js_cocos2dx_spine_Skeleton_getTransformConstraints(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_getTransformConstraints : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::TransformConstraint *>& result = cobj->getTransformConstraints();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_getTransformConstraints : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_getTransformConstraints)

static bool js_cocos2dx_spine_Skeleton_setSkin(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_spine_Skeleton_setSkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            spine::Skin* arg0 = nullptr;
            ok &= seval_to_native_ptr(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            cobj->setSkin(arg0);
            return true;
        }
    } while(false);

    do {
        if (argc == 1) {
            spine::String arg0;
            arg0 = args[0].toStringForce().c_str();
            if (!ok) { ok = true; break; }
            cobj->setSkin(arg0);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_setSkin)

static bool js_cocos2dx_spine_Skeleton_findSlot(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_findSlot : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_findSlot : Error processing arguments");
        spine::Slot* result = cobj->findSlot(arg0);
        ok &= native_ptr_to_rooted_seval<spine::Slot>(inst, (spine::Slot*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_findSlot : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_findSlot)

static bool js_cocos2dx_spine_Skeleton_updateWorldTransform(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_updateWorldTransform : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->updateWorldTransform();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_updateWorldTransform)

static bool js_cocos2dx_spine_Skeleton_findPathConstraint(se::State &s, se::ScriptEngine *inst)
{
    spine::Skeleton* cobj = (spine::Skeleton*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skeleton_findPathConstraint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_findPathConstraint : Error processing arguments");
        spine::PathConstraint* result = cobj->findPathConstraint(arg0);
        ok &= native_ptr_to_rooted_seval<spine::PathConstraint>(inst, (spine::PathConstraint*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skeleton_findPathConstraint : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skeleton_findPathConstraint)




bool js_register_cocos2dx_spine_Skeleton(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Skeleton", obj, nullptr, nullptr);

    cls->defineFunction(inst, "setToSetupPose", _SE(js_cocos2dx_spine_Skeleton_setToSetupPose));
    cls->defineFunction(inst, "getSkin", _SE(js_cocos2dx_spine_Skeleton_getSkin));
    cls->defineFunction(inst, "getX", _SE(js_cocos2dx_spine_Skeleton_getX));
    cls->defineFunction(inst, "findTransformConstraint", _SE(js_cocos2dx_spine_Skeleton_findTransformConstraint));
    cls->defineFunction(inst, "setAttachment", _SE(js_cocos2dx_spine_Skeleton_setAttachment));
    cls->defineFunction(inst, "findIkConstraint", _SE(js_cocos2dx_spine_Skeleton_findIkConstraint));
    cls->defineFunction(inst, "setBonesToSetupPose", _SE(js_cocos2dx_spine_Skeleton_setBonesToSetupPose));
    cls->defineFunction(inst, "getScaleY", _SE(js_cocos2dx_spine_Skeleton_getScaleY));
    cls->defineFunction(inst, "getScaleX", _SE(js_cocos2dx_spine_Skeleton_getScaleX));
    cls->defineFunction(inst, "findBoneIndex", _SE(js_cocos2dx_spine_Skeleton_findBoneIndex));
    cls->defineFunction(inst, "setSlotsToSetupPose", _SE(js_cocos2dx_spine_Skeleton_setSlotsToSetupPose));
    cls->defineFunction(inst, "getDrawOrder", _SE(js_cocos2dx_spine_Skeleton_getDrawOrder));
    cls->defineFunction(inst, "getTime", _SE(js_cocos2dx_spine_Skeleton_getTime));
    cls->defineFunction(inst, "getColor", _SE(js_cocos2dx_spine_Skeleton_getColor));
    cls->defineFunction(inst, "getIkConstraints", _SE(js_cocos2dx_spine_Skeleton_getIkConstraints));
    cls->defineFunction(inst, "getData", _SE(js_cocos2dx_spine_Skeleton_getData));
    cls->defineFunction(inst, "getUpdateCacheList", _SE(js_cocos2dx_spine_Skeleton_getUpdateCacheList));
    cls->defineFunction(inst, "setScaleY", _SE(js_cocos2dx_spine_Skeleton_setScaleY));
    cls->defineFunction(inst, "setScaleX", _SE(js_cocos2dx_spine_Skeleton_setScaleX));
    cls->defineFunction(inst, "getPathConstraints", _SE(js_cocos2dx_spine_Skeleton_getPathConstraints));
    cls->defineFunction(inst, "getSlots", _SE(js_cocos2dx_spine_Skeleton_getSlots));
    cls->defineFunction(inst, "printUpdateCache", _SE(js_cocos2dx_spine_Skeleton_printUpdateCache));
    cls->defineFunction(inst, "update", _SE(js_cocos2dx_spine_Skeleton_update));
    cls->defineFunction(inst, "getAttachment", _SE(js_cocos2dx_spine_Skeleton_getAttachment));
    cls->defineFunction(inst, "setTime", _SE(js_cocos2dx_spine_Skeleton_setTime));
    cls->defineFunction(inst, "setPosition", _SE(js_cocos2dx_spine_Skeleton_setPosition));
    cls->defineFunction(inst, "setX", _SE(js_cocos2dx_spine_Skeleton_setX));
    cls->defineFunction(inst, "setY", _SE(js_cocos2dx_spine_Skeleton_setY));
    cls->defineFunction(inst, "findBone", _SE(js_cocos2dx_spine_Skeleton_findBone));
    cls->defineFunction(inst, "getY", _SE(js_cocos2dx_spine_Skeleton_getY));
    cls->defineFunction(inst, "getBones", _SE(js_cocos2dx_spine_Skeleton_getBones));
    cls->defineFunction(inst, "getRootBone", _SE(js_cocos2dx_spine_Skeleton_getRootBone));
    cls->defineFunction(inst, "updateCache", _SE(js_cocos2dx_spine_Skeleton_updateCache));
    cls->defineFunction(inst, "findSlotIndex", _SE(js_cocos2dx_spine_Skeleton_findSlotIndex));
    cls->defineFunction(inst, "getTransformConstraints", _SE(js_cocos2dx_spine_Skeleton_getTransformConstraints));
    cls->defineFunction(inst, "setSkin", _SE(js_cocos2dx_spine_Skeleton_setSkin));
    cls->defineFunction(inst, "findSlot", _SE(js_cocos2dx_spine_Skeleton_findSlot));
    cls->defineFunction(inst, "updateWorldTransform", _SE(js_cocos2dx_spine_Skeleton_updateWorldTransform));
    cls->defineFunction(inst, "findPathConstraint", _SE(js_cocos2dx_spine_Skeleton_findPathConstraint));
    cls->install(inst);
    inst->registerClass<spine::Skeleton>(cls);

    __jsb_spine_Skeleton_proto = cls->getProto();
    __jsb_spine_Skeleton_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_SkeletonBounds_proto = nullptr;
se::Class* __jsb_spine_SkeletonBounds_class = nullptr;

static bool js_cocos2dx_spine_SkeletonBounds_getHeight(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonBounds* cobj = (spine::SkeletonBounds*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonBounds_getHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getHeight();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonBounds_getHeight : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonBounds_getHeight)

static bool js_cocos2dx_spine_SkeletonBounds_aabbintersectsSegment(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonBounds* cobj = (spine::SkeletonBounds*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonBounds_aabbintersectsSegment : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonBounds_aabbintersectsSegment : Error processing arguments");
        bool result = cobj->aabbintersectsSegment(arg0, arg1, arg2, arg3);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonBounds_aabbintersectsSegment : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonBounds_aabbintersectsSegment)

static bool js_cocos2dx_spine_SkeletonBounds_getWidth(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonBounds* cobj = (spine::SkeletonBounds*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonBounds_getWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getWidth();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonBounds_getWidth : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonBounds_getWidth)

static bool js_cocos2dx_spine_SkeletonBounds_aabbcontainsPoint(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonBounds* cobj = (spine::SkeletonBounds*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonBounds_aabbcontainsPoint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonBounds_aabbcontainsPoint : Error processing arguments");
        bool result = cobj->aabbcontainsPoint(arg0, arg1);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonBounds_aabbcontainsPoint : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonBounds_aabbcontainsPoint)

static bool js_cocos2dx_spine_SkeletonBounds_intersectsSegment(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    spine::SkeletonBounds* cobj = (spine::SkeletonBounds*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_spine_SkeletonBounds_intersectsSegment : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 5) {
            spine::Polygon* arg0 = nullptr;
            ok &= seval_to_native_ptr(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            float arg1 = 0;
            ok &= seval_to_float(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            float arg3 = 0;
            ok &= seval_to_float(inst, args[3], &arg3);
            if (!ok) { ok = true; break; }
            float arg4 = 0;
            ok &= seval_to_float(inst, args[4], &arg4);
            if (!ok) { ok = true; break; }
            bool result = cobj->intersectsSegment(arg0, arg1, arg2, arg3, arg4);
            ok &= boolean_to_seval(inst, result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonBounds_intersectsSegment : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 4) {
            float arg0 = 0;
            ok &= seval_to_float(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            float arg1 = 0;
            ok &= seval_to_float(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            float arg3 = 0;
            ok &= seval_to_float(inst, args[3], &arg3);
            if (!ok) { ok = true; break; }
            spine::BoundingBoxAttachment* result = cobj->intersectsSegment(arg0, arg1, arg2, arg3);
            ok &= native_ptr_to_rooted_seval<spine::BoundingBoxAttachment>(inst, (spine::BoundingBoxAttachment*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonBounds_intersectsSegment : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonBounds_intersectsSegment)

static bool js_cocos2dx_spine_SkeletonBounds_containsPoint(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    spine::SkeletonBounds* cobj = (spine::SkeletonBounds*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_spine_SkeletonBounds_containsPoint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            float arg0 = 0;
            ok &= seval_to_float(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            float arg1 = 0;
            ok &= seval_to_float(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            spine::BoundingBoxAttachment* result = cobj->containsPoint(arg0, arg1);
            ok &= native_ptr_to_rooted_seval<spine::BoundingBoxAttachment>(inst, (spine::BoundingBoxAttachment*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonBounds_containsPoint : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 3) {
            spine::Polygon* arg0 = nullptr;
            ok &= seval_to_native_ptr(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            float arg1 = 0;
            ok &= seval_to_float(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            bool result = cobj->containsPoint(arg0, arg1, arg2);
            ok &= boolean_to_seval(inst, result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonBounds_containsPoint : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonBounds_containsPoint)

static bool js_cocos2dx_spine_SkeletonBounds_getPolygon(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonBounds* cobj = (spine::SkeletonBounds*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonBounds_getPolygon : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::BoundingBoxAttachment* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonBounds_getPolygon : Error processing arguments");
        spine::Polygon* result = cobj->getPolygon(arg0);
        ok &= native_ptr_to_rooted_seval<spine::Polygon>(inst, (spine::Polygon*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonBounds_getPolygon : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonBounds_getPolygon)




bool js_register_cocos2dx_spine_SkeletonBounds(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "SkeletonBounds", obj, nullptr, nullptr);

    cls->defineFunction(inst, "getHeight", _SE(js_cocos2dx_spine_SkeletonBounds_getHeight));
    cls->defineFunction(inst, "aabbintersectsSegment", _SE(js_cocos2dx_spine_SkeletonBounds_aabbintersectsSegment));
    cls->defineFunction(inst, "getWidth", _SE(js_cocos2dx_spine_SkeletonBounds_getWidth));
    cls->defineFunction(inst, "aabbcontainsPoint", _SE(js_cocos2dx_spine_SkeletonBounds_aabbcontainsPoint));
    cls->defineFunction(inst, "intersectsSegment", _SE(js_cocos2dx_spine_SkeletonBounds_intersectsSegment));
    cls->defineFunction(inst, "containsPoint", _SE(js_cocos2dx_spine_SkeletonBounds_containsPoint));
    cls->defineFunction(inst, "getPolygon", _SE(js_cocos2dx_spine_SkeletonBounds_getPolygon));
    cls->install(inst);
    inst->registerClass<spine::SkeletonBounds>(cls);

    __jsb_spine_SkeletonBounds_proto = cls->getProto();
    __jsb_spine_SkeletonBounds_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_Polygon_proto = nullptr;
se::Class* __jsb_spine_Polygon_class = nullptr;




bool js_register_cocos2dx_spine_Polygon(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Polygon", obj, nullptr, nullptr);

    cls->install(inst);
    inst->registerClass<spine::Polygon>(cls);

    __jsb_spine_Polygon_proto = cls->getProto();
    __jsb_spine_Polygon_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_SkeletonData_proto = nullptr;
se::Class* __jsb_spine_SkeletonData_class = nullptr;

static bool js_cocos2dx_spine_SkeletonData_findEvent(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_findEvent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findEvent : Error processing arguments");
        spine::EventData* result = cobj->findEvent(arg0);
        ok &= native_ptr_to_rooted_seval<spine::EventData>(inst, (spine::EventData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findEvent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_findEvent)

static bool js_cocos2dx_spine_SkeletonData_findAnimation(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_findAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findAnimation : Error processing arguments");
        spine::Animation* result = cobj->findAnimation(arg0);
        ok &= native_ptr_to_rooted_seval<spine::Animation>(inst, (spine::Animation*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_findAnimation)

static bool js_cocos2dx_spine_SkeletonData_getX(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getX)

static bool js_cocos2dx_spine_SkeletonData_findTransformConstraint(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_findTransformConstraint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findTransformConstraint : Error processing arguments");
        spine::TransformConstraintData* result = cobj->findTransformConstraint(arg0);
        ok &= native_ptr_to_rooted_seval<spine::TransformConstraintData>(inst, (spine::TransformConstraintData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findTransformConstraint : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_findTransformConstraint)

static bool js_cocos2dx_spine_SkeletonData_setFps(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_setFps : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_setFps : Error processing arguments");
        cobj->setFps(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_setFps)

static bool js_cocos2dx_spine_SkeletonData_findIkConstraint(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_findIkConstraint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findIkConstraint : Error processing arguments");
        spine::IkConstraintData* result = cobj->findIkConstraint(arg0);
        ok &= native_ptr_to_rooted_seval<spine::IkConstraintData>(inst, (spine::IkConstraintData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findIkConstraint : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_findIkConstraint)

static bool js_cocos2dx_spine_SkeletonData_getFps(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getFps : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getFps();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getFps : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getFps)

static bool js_cocos2dx_spine_SkeletonData_getSkins(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getSkins : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::Skin *>& result = cobj->getSkins();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getSkins : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getSkins)

static bool js_cocos2dx_spine_SkeletonData_setWidth(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_setWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_setWidth : Error processing arguments");
        cobj->setWidth(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_setWidth)

static bool js_cocos2dx_spine_SkeletonData_setVersion(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_setVersion : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_setVersion : Error processing arguments");
        cobj->setVersion(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_setVersion)

static bool js_cocos2dx_spine_SkeletonData_setHash(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_setHash : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_setHash : Error processing arguments");
        cobj->setHash(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_setHash)

static bool js_cocos2dx_spine_SkeletonData_findBoneIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_findBoneIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findBoneIndex : Error processing arguments");
        int result = cobj->findBoneIndex(arg0);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findBoneIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_findBoneIndex)

static bool js_cocos2dx_spine_SkeletonData_getDefaultSkin(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getDefaultSkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Skin* result = cobj->getDefaultSkin();
        ok &= native_ptr_to_rooted_seval<spine::Skin>(inst, (spine::Skin*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getDefaultSkin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getDefaultSkin)

static bool js_cocos2dx_spine_SkeletonData_getHeight(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getHeight();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getHeight : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getHeight)

static bool js_cocos2dx_spine_SkeletonData_setDefaultSkin(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_setDefaultSkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::Skin* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_setDefaultSkin : Error processing arguments");
        cobj->setDefaultSkin(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_setDefaultSkin)

static bool js_cocos2dx_spine_SkeletonData_getHash(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getHash : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getHash();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getHash : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getHash)

static bool js_cocos2dx_spine_SkeletonData_getAnimations(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getAnimations : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::Animation *>& result = cobj->getAnimations();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getAnimations : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getAnimations)

static bool js_cocos2dx_spine_SkeletonData_setImagesPath(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_setImagesPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_setImagesPath : Error processing arguments");
        cobj->setImagesPath(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_setImagesPath)

static bool js_cocos2dx_spine_SkeletonData_getIkConstraints(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getIkConstraints : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::IkConstraintData *>& result = cobj->getIkConstraints();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getIkConstraints : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getIkConstraints)

static bool js_cocos2dx_spine_SkeletonData_getImagesPath(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getImagesPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getImagesPath();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getImagesPath : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getImagesPath)

static bool js_cocos2dx_spine_SkeletonData_getEvents(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getEvents : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::EventData *>& result = cobj->getEvents();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getEvents : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getEvents)

static bool js_cocos2dx_spine_SkeletonData_findBone(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_findBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findBone : Error processing arguments");
        spine::BoneData* result = cobj->findBone(arg0);
        ok &= native_ptr_to_rooted_seval<spine::BoneData>(inst, (spine::BoneData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findBone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_findBone)

static bool js_cocos2dx_spine_SkeletonData_setName(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_setName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_setName : Error processing arguments");
        cobj->setName(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_setName)

static bool js_cocos2dx_spine_SkeletonData_getPathConstraints(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getPathConstraints : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::PathConstraintData *>& result = cobj->getPathConstraints();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getPathConstraints : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getPathConstraints)

static bool js_cocos2dx_spine_SkeletonData_getAudioPath(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getAudioPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getAudioPath();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getAudioPath : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getAudioPath)

static bool js_cocos2dx_spine_SkeletonData_getVersion(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getVersion : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getVersion();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getVersion : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getVersion)

static bool js_cocos2dx_spine_SkeletonData_setX(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_setX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_setX : Error processing arguments");
        cobj->setX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_setX)

static bool js_cocos2dx_spine_SkeletonData_setY(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_setY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_setY : Error processing arguments");
        cobj->setY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_setY)

static bool js_cocos2dx_spine_SkeletonData_setHeight(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_setHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_setHeight : Error processing arguments");
        cobj->setHeight(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_setHeight)

static bool js_cocos2dx_spine_SkeletonData_getWidth(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getWidth();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getWidth : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getWidth)

static bool js_cocos2dx_spine_SkeletonData_getSlots(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getSlots : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::SlotData *>& result = cobj->getSlots();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getSlots : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getSlots)

static bool js_cocos2dx_spine_SkeletonData_findSkin(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_findSkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findSkin : Error processing arguments");
        spine::Skin* result = cobj->findSkin(arg0);
        ok &= native_ptr_to_rooted_seval<spine::Skin>(inst, (spine::Skin*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findSkin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_findSkin)

static bool js_cocos2dx_spine_SkeletonData_getY(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getY)

static bool js_cocos2dx_spine_SkeletonData_getBones(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getBones : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::BoneData *>& result = cobj->getBones();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getBones : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getBones)

static bool js_cocos2dx_spine_SkeletonData_findPathConstraintIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_findPathConstraintIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findPathConstraintIndex : Error processing arguments");
        int result = cobj->findPathConstraintIndex(arg0);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findPathConstraintIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_findPathConstraintIndex)

static bool js_cocos2dx_spine_SkeletonData_findSlotIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_findSlotIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findSlotIndex : Error processing arguments");
        int result = cobj->findSlotIndex(arg0);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findSlotIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_findSlotIndex)

static bool js_cocos2dx_spine_SkeletonData_getTransformConstraints(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getTransformConstraints : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::TransformConstraintData *>& result = cobj->getTransformConstraints();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getTransformConstraints : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getTransformConstraints)

static bool js_cocos2dx_spine_SkeletonData_findSlot(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_findSlot : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findSlot : Error processing arguments");
        spine::SlotData* result = cobj->findSlot(arg0);
        ok &= native_ptr_to_rooted_seval<spine::SlotData>(inst, (spine::SlotData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findSlot : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_findSlot)

static bool js_cocos2dx_spine_SkeletonData_setAudioPath(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_setAudioPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_setAudioPath : Error processing arguments");
        cobj->setAudioPath(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_setAudioPath)

static bool js_cocos2dx_spine_SkeletonData_findPathConstraint(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_findPathConstraint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findPathConstraint : Error processing arguments");
        spine::PathConstraintData* result = cobj->findPathConstraint(arg0);
        ok &= native_ptr_to_rooted_seval<spine::PathConstraintData>(inst, (spine::PathConstraintData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_findPathConstraint : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_findPathConstraint)

static bool js_cocos2dx_spine_SkeletonData_getName(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonData* cobj = (spine::SkeletonData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonData_getName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getName();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonData_getName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonData_getName)




bool js_register_cocos2dx_spine_SkeletonData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "SkeletonData", obj, nullptr, nullptr);

    cls->defineFunction(inst, "findEvent", _SE(js_cocos2dx_spine_SkeletonData_findEvent));
    cls->defineFunction(inst, "findAnimation", _SE(js_cocos2dx_spine_SkeletonData_findAnimation));
    cls->defineFunction(inst, "getX", _SE(js_cocos2dx_spine_SkeletonData_getX));
    cls->defineFunction(inst, "findTransformConstraint", _SE(js_cocos2dx_spine_SkeletonData_findTransformConstraint));
    cls->defineFunction(inst, "setFps", _SE(js_cocos2dx_spine_SkeletonData_setFps));
    cls->defineFunction(inst, "findIkConstraint", _SE(js_cocos2dx_spine_SkeletonData_findIkConstraint));
    cls->defineFunction(inst, "getFps", _SE(js_cocos2dx_spine_SkeletonData_getFps));
    cls->defineFunction(inst, "getSkins", _SE(js_cocos2dx_spine_SkeletonData_getSkins));
    cls->defineFunction(inst, "setWidth", _SE(js_cocos2dx_spine_SkeletonData_setWidth));
    cls->defineFunction(inst, "setVersion", _SE(js_cocos2dx_spine_SkeletonData_setVersion));
    cls->defineFunction(inst, "setHash", _SE(js_cocos2dx_spine_SkeletonData_setHash));
    cls->defineFunction(inst, "findBoneIndex", _SE(js_cocos2dx_spine_SkeletonData_findBoneIndex));
    cls->defineFunction(inst, "getDefaultSkin", _SE(js_cocos2dx_spine_SkeletonData_getDefaultSkin));
    cls->defineFunction(inst, "getHeight", _SE(js_cocos2dx_spine_SkeletonData_getHeight));
    cls->defineFunction(inst, "setDefaultSkin", _SE(js_cocos2dx_spine_SkeletonData_setDefaultSkin));
    cls->defineFunction(inst, "getHash", _SE(js_cocos2dx_spine_SkeletonData_getHash));
    cls->defineFunction(inst, "getAnimations", _SE(js_cocos2dx_spine_SkeletonData_getAnimations));
    cls->defineFunction(inst, "setImagesPath", _SE(js_cocos2dx_spine_SkeletonData_setImagesPath));
    cls->defineFunction(inst, "getIkConstraints", _SE(js_cocos2dx_spine_SkeletonData_getIkConstraints));
    cls->defineFunction(inst, "getImagesPath", _SE(js_cocos2dx_spine_SkeletonData_getImagesPath));
    cls->defineFunction(inst, "getEvents", _SE(js_cocos2dx_spine_SkeletonData_getEvents));
    cls->defineFunction(inst, "findBone", _SE(js_cocos2dx_spine_SkeletonData_findBone));
    cls->defineFunction(inst, "setName", _SE(js_cocos2dx_spine_SkeletonData_setName));
    cls->defineFunction(inst, "getPathConstraints", _SE(js_cocos2dx_spine_SkeletonData_getPathConstraints));
    cls->defineFunction(inst, "getAudioPath", _SE(js_cocos2dx_spine_SkeletonData_getAudioPath));
    cls->defineFunction(inst, "getVersion", _SE(js_cocos2dx_spine_SkeletonData_getVersion));
    cls->defineFunction(inst, "setX", _SE(js_cocos2dx_spine_SkeletonData_setX));
    cls->defineFunction(inst, "setY", _SE(js_cocos2dx_spine_SkeletonData_setY));
    cls->defineFunction(inst, "setHeight", _SE(js_cocos2dx_spine_SkeletonData_setHeight));
    cls->defineFunction(inst, "getWidth", _SE(js_cocos2dx_spine_SkeletonData_getWidth));
    cls->defineFunction(inst, "getSlots", _SE(js_cocos2dx_spine_SkeletonData_getSlots));
    cls->defineFunction(inst, "findSkin", _SE(js_cocos2dx_spine_SkeletonData_findSkin));
    cls->defineFunction(inst, "getY", _SE(js_cocos2dx_spine_SkeletonData_getY));
    cls->defineFunction(inst, "getBones", _SE(js_cocos2dx_spine_SkeletonData_getBones));
    cls->defineFunction(inst, "findPathConstraintIndex", _SE(js_cocos2dx_spine_SkeletonData_findPathConstraintIndex));
    cls->defineFunction(inst, "findSlotIndex", _SE(js_cocos2dx_spine_SkeletonData_findSlotIndex));
    cls->defineFunction(inst, "getTransformConstraints", _SE(js_cocos2dx_spine_SkeletonData_getTransformConstraints));
    cls->defineFunction(inst, "findSlot", _SE(js_cocos2dx_spine_SkeletonData_findSlot));
    cls->defineFunction(inst, "setAudioPath", _SE(js_cocos2dx_spine_SkeletonData_setAudioPath));
    cls->defineFunction(inst, "findPathConstraint", _SE(js_cocos2dx_spine_SkeletonData_findPathConstraint));
    cls->defineFunction(inst, "getName", _SE(js_cocos2dx_spine_SkeletonData_getName));
    cls->install(inst);
    inst->registerClass<spine::SkeletonData>(cls);

    __jsb_spine_SkeletonData_proto = cls->getProto();
    __jsb_spine_SkeletonData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_Skin_proto = nullptr;
se::Class* __jsb_spine_Skin_class = nullptr;

static bool js_cocos2dx_spine_Skin_findNamesForSlot(se::State &s, se::ScriptEngine *inst)
{
    spine::Skin* cobj = (spine::Skin*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skin_findNamesForSlot : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        size_t arg0 = 0;
        spine::Vector<spine::String> arg1;
        ok &= seval_to_size(inst, args[0], &arg0);
        ok &= seval_to_spine_Vector_String(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skin_findNamesForSlot : Error processing arguments");
        cobj->findNamesForSlot(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skin_findNamesForSlot)

static bool js_cocos2dx_spine_Skin_getConstraints(se::State &s, se::ScriptEngine *inst)
{
    spine::Skin* cobj = (spine::Skin*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skin_getConstraints : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::ConstraintData *>& result = cobj->getConstraints();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skin_getConstraints : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skin_getConstraints)

static bool js_cocos2dx_spine_Skin_removeAttachment(se::State &s, se::ScriptEngine *inst)
{
    spine::Skin* cobj = (spine::Skin*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skin_removeAttachment : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        size_t arg0 = 0;
        spine::String arg1;
        ok &= seval_to_size(inst, args[0], &arg0);
        arg1 = args[1].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skin_removeAttachment : Error processing arguments");
        cobj->removeAttachment(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skin_removeAttachment)

static bool js_cocos2dx_spine_Skin_getBones(se::State &s, se::ScriptEngine *inst)
{
    spine::Skin* cobj = (spine::Skin*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skin_getBones : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::BoneData *>& result = cobj->getBones();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skin_getBones : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skin_getBones)

static bool js_cocos2dx_spine_Skin_getName(se::State &s, se::ScriptEngine *inst)
{
    spine::Skin* cobj = (spine::Skin*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skin_getName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getName();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skin_getName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skin_getName)

static bool js_cocos2dx_spine_Skin_getAttachment(se::State &s, se::ScriptEngine *inst)
{
    spine::Skin* cobj = (spine::Skin*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skin_getAttachment : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        size_t arg0 = 0;
        spine::String arg1;
        ok &= seval_to_size(inst, args[0], &arg0);
        arg1 = args[1].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skin_getAttachment : Error processing arguments");
        spine::Attachment* result = cobj->getAttachment(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<spine::Attachment>(inst, (spine::Attachment*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skin_getAttachment : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skin_getAttachment)

static bool js_cocos2dx_spine_Skin_addSkin(se::State &s, se::ScriptEngine *inst)
{
    spine::Skin* cobj = (spine::Skin*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skin_addSkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::Skin* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skin_addSkin : Error processing arguments");
        cobj->addSkin(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skin_addSkin)

static bool js_cocos2dx_spine_Skin_setAttachment(se::State &s, se::ScriptEngine *inst)
{
    spine::Skin* cobj = (spine::Skin*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skin_setAttachment : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        size_t arg0 = 0;
        spine::String arg1;
        spine::Attachment* arg2 = nullptr;
        ok &= seval_to_size(inst, args[0], &arg0);
        arg1 = args[1].toStringForce().c_str();
        ok &= seval_to_native_ptr(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skin_setAttachment : Error processing arguments");
        cobj->setAttachment(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skin_setAttachment)

static bool js_cocos2dx_spine_Skin_copySkin(se::State &s, se::ScriptEngine *inst)
{
    spine::Skin* cobj = (spine::Skin*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skin_copySkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::Skin* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skin_copySkin : Error processing arguments");
        cobj->copySkin(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skin_copySkin)

static bool js_cocos2dx_spine_Skin_findAttachmentsForSlot(se::State &s, se::ScriptEngine *inst)
{
    spine::Skin* cobj = (spine::Skin*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Skin_findAttachmentsForSlot : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        size_t arg0 = 0;
        spine::Vector<spine::Attachment *> arg1;
        ok &= seval_to_size(inst, args[0], &arg0);
        ok &= seval_to_spine_Vector_T_ptr(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Skin_findAttachmentsForSlot : Error processing arguments");
        cobj->findAttachmentsForSlot(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Skin_findAttachmentsForSlot)




bool js_register_cocos2dx_spine_Skin(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Skin", obj, nullptr, nullptr);

    cls->defineFunction(inst, "findNamesForSlot", _SE(js_cocos2dx_spine_Skin_findNamesForSlot));
    cls->defineFunction(inst, "getConstraints", _SE(js_cocos2dx_spine_Skin_getConstraints));
    cls->defineFunction(inst, "removeAttachment", _SE(js_cocos2dx_spine_Skin_removeAttachment));
    cls->defineFunction(inst, "getBones", _SE(js_cocos2dx_spine_Skin_getBones));
    cls->defineFunction(inst, "getName", _SE(js_cocos2dx_spine_Skin_getName));
    cls->defineFunction(inst, "getAttachment", _SE(js_cocos2dx_spine_Skin_getAttachment));
    cls->defineFunction(inst, "addSkin", _SE(js_cocos2dx_spine_Skin_addSkin));
    cls->defineFunction(inst, "setAttachment", _SE(js_cocos2dx_spine_Skin_setAttachment));
    cls->defineFunction(inst, "copySkin", _SE(js_cocos2dx_spine_Skin_copySkin));
    cls->defineFunction(inst, "findAttachmentsForSlot", _SE(js_cocos2dx_spine_Skin_findAttachmentsForSlot));
    cls->install(inst);
    inst->registerClass<spine::Skin>(cls);

    __jsb_spine_Skin_proto = cls->getProto();
    __jsb_spine_Skin_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_Slot_proto = nullptr;
se::Class* __jsb_spine_Slot_class = nullptr;

static bool js_cocos2dx_spine_Slot_getBone(se::State &s, se::ScriptEngine *inst)
{
    spine::Slot* cobj = (spine::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Slot_getBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Bone& result = cobj->getBone();
        ok &= native_ptr_to_rooted_seval<spine::Bone>(inst, (spine::Bone*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Slot_getBone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Slot_getBone)

static bool js_cocos2dx_spine_Slot_setAttachmentTime(se::State &s, se::ScriptEngine *inst)
{
    spine::Slot* cobj = (spine::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Slot_setAttachmentTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Slot_setAttachmentTime : Error processing arguments");
        cobj->setAttachmentTime(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Slot_setAttachmentTime)

static bool js_cocos2dx_spine_Slot_getDarkColor(se::State &s, se::ScriptEngine *inst)
{
    spine::Slot* cobj = (spine::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Slot_getDarkColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Color& result = cobj->getDarkColor();
        ok &= native_ptr_to_rooted_seval<spine::Color>(inst, (spine::Color*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Slot_getDarkColor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Slot_getDarkColor)

static bool js_cocos2dx_spine_Slot_getColor(se::State &s, se::ScriptEngine *inst)
{
    spine::Slot* cobj = (spine::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Slot_getColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Color& result = cobj->getColor();
        ok &= native_ptr_to_rooted_seval<spine::Color>(inst, (spine::Color*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Slot_getColor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Slot_getColor)

static bool js_cocos2dx_spine_Slot_setToSetupPose(se::State &s, se::ScriptEngine *inst)
{
    spine::Slot* cobj = (spine::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Slot_setToSetupPose : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->setToSetupPose();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Slot_setToSetupPose)

static bool js_cocos2dx_spine_Slot_getAttachment(se::State &s, se::ScriptEngine *inst)
{
    spine::Slot* cobj = (spine::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Slot_getAttachment : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Attachment* result = cobj->getAttachment();
        ok &= native_ptr_to_rooted_seval<spine::Attachment>(inst, (spine::Attachment*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Slot_getAttachment : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Slot_getAttachment)

static bool js_cocos2dx_spine_Slot_getAttachmentTime(se::State &s, se::ScriptEngine *inst)
{
    spine::Slot* cobj = (spine::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Slot_getAttachmentTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getAttachmentTime();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Slot_getAttachmentTime : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Slot_getAttachmentTime)

static bool js_cocos2dx_spine_Slot_setAttachment(se::State &s, se::ScriptEngine *inst)
{
    spine::Slot* cobj = (spine::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Slot_setAttachment : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::Attachment* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Slot_setAttachment : Error processing arguments");
        cobj->setAttachment(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Slot_setAttachment)

static bool js_cocos2dx_spine_Slot_hasDarkColor(se::State &s, se::ScriptEngine *inst)
{
    spine::Slot* cobj = (spine::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Slot_hasDarkColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->hasDarkColor();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Slot_hasDarkColor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Slot_hasDarkColor)

static bool js_cocos2dx_spine_Slot_getDeform(se::State &s, se::ScriptEngine *inst)
{
    spine::Slot* cobj = (spine::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Slot_getDeform : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<float>& result = cobj->getDeform();
        ok &= spine_Vector_T_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Slot_getDeform : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Slot_getDeform)

static bool js_cocos2dx_spine_Slot_getSkeleton(se::State &s, se::ScriptEngine *inst)
{
    spine::Slot* cobj = (spine::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Slot_getSkeleton : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Skeleton& result = cobj->getSkeleton();
        ok &= native_ptr_to_rooted_seval<spine::Skeleton>(inst, (spine::Skeleton*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Slot_getSkeleton : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Slot_getSkeleton)

static bool js_cocos2dx_spine_Slot_getData(se::State &s, se::ScriptEngine *inst)
{
    spine::Slot* cobj = (spine::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_Slot_getData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::SlotData& result = cobj->getData();
        ok &= native_ptr_to_rooted_seval<spine::SlotData>(inst, (spine::SlotData*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_Slot_getData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_Slot_getData)




bool js_register_cocos2dx_spine_Slot(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Slot", obj, nullptr, nullptr);

    cls->defineFunction(inst, "getBone", _SE(js_cocos2dx_spine_Slot_getBone));
    cls->defineFunction(inst, "setAttachmentTime", _SE(js_cocos2dx_spine_Slot_setAttachmentTime));
    cls->defineFunction(inst, "getDarkColor", _SE(js_cocos2dx_spine_Slot_getDarkColor));
    cls->defineFunction(inst, "getColor", _SE(js_cocos2dx_spine_Slot_getColor));
    cls->defineFunction(inst, "setToSetupPose", _SE(js_cocos2dx_spine_Slot_setToSetupPose));
    cls->defineFunction(inst, "getAttachment", _SE(js_cocos2dx_spine_Slot_getAttachment));
    cls->defineFunction(inst, "getAttachmentTime", _SE(js_cocos2dx_spine_Slot_getAttachmentTime));
    cls->defineFunction(inst, "setAttachment", _SE(js_cocos2dx_spine_Slot_setAttachment));
    cls->defineFunction(inst, "hasDarkColor", _SE(js_cocos2dx_spine_Slot_hasDarkColor));
    cls->defineFunction(inst, "getDeform", _SE(js_cocos2dx_spine_Slot_getDeform));
    cls->defineFunction(inst, "getSkeleton", _SE(js_cocos2dx_spine_Slot_getSkeleton));
    cls->defineFunction(inst, "getData", _SE(js_cocos2dx_spine_Slot_getData));
    cls->install(inst);
    inst->registerClass<spine::Slot>(cls);

    __jsb_spine_Slot_proto = cls->getProto();
    __jsb_spine_Slot_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_SlotData_proto = nullptr;
se::Class* __jsb_spine_SlotData_class = nullptr;

static bool js_cocos2dx_spine_SlotData_getIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::SlotData* cobj = (spine::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SlotData_getIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getIndex();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SlotData_getIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SlotData_getIndex)

static bool js_cocos2dx_spine_SlotData_getDarkColor(se::State &s, se::ScriptEngine *inst)
{
    spine::SlotData* cobj = (spine::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SlotData_getDarkColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Color& result = cobj->getDarkColor();
        ok &= native_ptr_to_rooted_seval<spine::Color>(inst, (spine::Color*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SlotData_getDarkColor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SlotData_getDarkColor)

static bool js_cocos2dx_spine_SlotData_getAttachmentName(se::State &s, se::ScriptEngine *inst)
{
    spine::SlotData* cobj = (spine::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SlotData_getAttachmentName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getAttachmentName();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SlotData_getAttachmentName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SlotData_getAttachmentName)

static bool js_cocos2dx_spine_SlotData_getColor(se::State &s, se::ScriptEngine *inst)
{
    spine::SlotData* cobj = (spine::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SlotData_getColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Color& result = cobj->getColor();
        ok &= native_ptr_to_rooted_seval<spine::Color>(inst, (spine::Color*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SlotData_getColor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SlotData_getColor)

static bool js_cocos2dx_spine_SlotData_getName(se::State &s, se::ScriptEngine *inst)
{
    spine::SlotData* cobj = (spine::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SlotData_getName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const spine::String& result = cobj->getName();
        s.rval().setString(result.buffer());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SlotData_getName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SlotData_getName)

static bool js_cocos2dx_spine_SlotData_setBlendMode(se::State &s, se::ScriptEngine *inst)
{
    spine::SlotData* cobj = (spine::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SlotData_setBlendMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::BlendMode arg0;
        ok &= seval_to_uint32(inst, args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SlotData_setBlendMode : Error processing arguments");
        cobj->setBlendMode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SlotData_setBlendMode)

static bool js_cocos2dx_spine_SlotData_getBlendMode(se::State &s, se::ScriptEngine *inst)
{
    spine::SlotData* cobj = (spine::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SlotData_getBlendMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = (unsigned int)cobj->getBlendMode();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SlotData_getBlendMode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SlotData_getBlendMode)

static bool js_cocos2dx_spine_SlotData_hasDarkColor(se::State &s, se::ScriptEngine *inst)
{
    spine::SlotData* cobj = (spine::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SlotData_hasDarkColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->hasDarkColor();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SlotData_hasDarkColor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SlotData_hasDarkColor)

static bool js_cocos2dx_spine_SlotData_setHasDarkColor(se::State &s, se::ScriptEngine *inst)
{
    spine::SlotData* cobj = (spine::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SlotData_setHasDarkColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SlotData_setHasDarkColor : Error processing arguments");
        cobj->setHasDarkColor(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SlotData_setHasDarkColor)

static bool js_cocos2dx_spine_SlotData_setAttachmentName(se::State &s, se::ScriptEngine *inst)
{
    spine::SlotData* cobj = (spine::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SlotData_setAttachmentName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::String arg0;
        arg0 = args[0].toStringForce().c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SlotData_setAttachmentName : Error processing arguments");
        cobj->setAttachmentName(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SlotData_setAttachmentName)

static bool js_cocos2dx_spine_SlotData_getBoneData(se::State &s, se::ScriptEngine *inst)
{
    spine::SlotData* cobj = (spine::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SlotData_getBoneData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::BoneData& result = cobj->getBoneData();
        ok &= native_ptr_to_rooted_seval<spine::BoneData>(inst, (spine::BoneData*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SlotData_getBoneData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SlotData_getBoneData)




bool js_register_cocos2dx_spine_SlotData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "SlotData", obj, nullptr, nullptr);

    cls->defineFunction(inst, "getIndex", _SE(js_cocos2dx_spine_SlotData_getIndex));
    cls->defineFunction(inst, "getDarkColor", _SE(js_cocos2dx_spine_SlotData_getDarkColor));
    cls->defineFunction(inst, "getAttachmentName", _SE(js_cocos2dx_spine_SlotData_getAttachmentName));
    cls->defineFunction(inst, "getColor", _SE(js_cocos2dx_spine_SlotData_getColor));
    cls->defineFunction(inst, "getName", _SE(js_cocos2dx_spine_SlotData_getName));
    cls->defineFunction(inst, "setBlendMode", _SE(js_cocos2dx_spine_SlotData_setBlendMode));
    cls->defineFunction(inst, "getBlendMode", _SE(js_cocos2dx_spine_SlotData_getBlendMode));
    cls->defineFunction(inst, "hasDarkColor", _SE(js_cocos2dx_spine_SlotData_hasDarkColor));
    cls->defineFunction(inst, "setHasDarkColor", _SE(js_cocos2dx_spine_SlotData_setHasDarkColor));
    cls->defineFunction(inst, "setAttachmentName", _SE(js_cocos2dx_spine_SlotData_setAttachmentName));
    cls->defineFunction(inst, "getBoneData", _SE(js_cocos2dx_spine_SlotData_getBoneData));
    cls->install(inst);
    inst->registerClass<spine::SlotData>(cls);

    __jsb_spine_SlotData_proto = cls->getProto();
    __jsb_spine_SlotData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_TransformConstraint_proto = nullptr;
se::Class* __jsb_spine_TransformConstraint_class = nullptr;

static bool js_cocos2dx_spine_TransformConstraint_setActive(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraint* cobj = (spine::TransformConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraint_setActive : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraint_setActive : Error processing arguments");
        cobj->setActive(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraint_setActive)

static bool js_cocos2dx_spine_TransformConstraint_getScaleMix(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraint* cobj = (spine::TransformConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraint_getScaleMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getScaleMix();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraint_getScaleMix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraint_getScaleMix)

static bool js_cocos2dx_spine_TransformConstraint_setRotateMix(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraint* cobj = (spine::TransformConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraint_setRotateMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraint_setRotateMix : Error processing arguments");
        cobj->setRotateMix(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraint_setRotateMix)

static bool js_cocos2dx_spine_TransformConstraint_getRotateMix(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraint* cobj = (spine::TransformConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraint_getRotateMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRotateMix();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraint_getRotateMix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraint_getRotateMix)

static bool js_cocos2dx_spine_TransformConstraint_getBones(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraint* cobj = (spine::TransformConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraint_getBones : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::Bone *>& result = cobj->getBones();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraint_getBones : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraint_getBones)

static bool js_cocos2dx_spine_TransformConstraint_setTarget(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraint* cobj = (spine::TransformConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraint_setTarget : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::Bone* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraint_setTarget : Error processing arguments");
        cobj->setTarget(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraint_setTarget)

static bool js_cocos2dx_spine_TransformConstraint_getTranslateMix(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraint* cobj = (spine::TransformConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraint_getTranslateMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTranslateMix();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraint_getTranslateMix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraint_getTranslateMix)

static bool js_cocos2dx_spine_TransformConstraint_setShearMix(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraint* cobj = (spine::TransformConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraint_setShearMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraint_setShearMix : Error processing arguments");
        cobj->setShearMix(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraint_setShearMix)

static bool js_cocos2dx_spine_TransformConstraint_update(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraint* cobj = (spine::TransformConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraint_update : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->update();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraint_update)

static bool js_cocos2dx_spine_TransformConstraint_getTarget(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraint* cobj = (spine::TransformConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraint_getTarget : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Bone* result = cobj->getTarget();
        ok &= native_ptr_to_rooted_seval<spine::Bone>(inst, (spine::Bone*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraint_getTarget : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraint_getTarget)

static bool js_cocos2dx_spine_TransformConstraint_setScaleMix(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraint* cobj = (spine::TransformConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraint_setScaleMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraint_setScaleMix : Error processing arguments");
        cobj->setScaleMix(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraint_setScaleMix)

static bool js_cocos2dx_spine_TransformConstraint_getOrder(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraint* cobj = (spine::TransformConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraint_getOrder : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getOrder();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraint_getOrder : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraint_getOrder)

static bool js_cocos2dx_spine_TransformConstraint_getShearMix(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraint* cobj = (spine::TransformConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraint_getShearMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getShearMix();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraint_getShearMix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraint_getShearMix)

static bool js_cocos2dx_spine_TransformConstraint_apply(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraint* cobj = (spine::TransformConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraint_apply : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->apply();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraint_apply)

static bool js_cocos2dx_spine_TransformConstraint_getData(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraint* cobj = (spine::TransformConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraint_getData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::TransformConstraintData& result = cobj->getData();
        ok &= native_ptr_to_rooted_seval<spine::TransformConstraintData>(inst, (spine::TransformConstraintData*)&result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraint_getData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraint_getData)

static bool js_cocos2dx_spine_TransformConstraint_isActive(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraint* cobj = (spine::TransformConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraint_isActive : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isActive();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraint_isActive : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraint_isActive)

static bool js_cocos2dx_spine_TransformConstraint_setTranslateMix(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraint* cobj = (spine::TransformConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraint_setTranslateMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraint_setTranslateMix : Error processing arguments");
        cobj->setTranslateMix(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraint_setTranslateMix)




bool js_register_cocos2dx_spine_TransformConstraint(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "TransformConstraint", obj, nullptr, nullptr);

    cls->defineFunction(inst, "setActive", _SE(js_cocos2dx_spine_TransformConstraint_setActive));
    cls->defineFunction(inst, "getScaleMix", _SE(js_cocos2dx_spine_TransformConstraint_getScaleMix));
    cls->defineFunction(inst, "setRotateMix", _SE(js_cocos2dx_spine_TransformConstraint_setRotateMix));
    cls->defineFunction(inst, "getRotateMix", _SE(js_cocos2dx_spine_TransformConstraint_getRotateMix));
    cls->defineFunction(inst, "getBones", _SE(js_cocos2dx_spine_TransformConstraint_getBones));
    cls->defineFunction(inst, "setTarget", _SE(js_cocos2dx_spine_TransformConstraint_setTarget));
    cls->defineFunction(inst, "getTranslateMix", _SE(js_cocos2dx_spine_TransformConstraint_getTranslateMix));
    cls->defineFunction(inst, "setShearMix", _SE(js_cocos2dx_spine_TransformConstraint_setShearMix));
    cls->defineFunction(inst, "update", _SE(js_cocos2dx_spine_TransformConstraint_update));
    cls->defineFunction(inst, "getTarget", _SE(js_cocos2dx_spine_TransformConstraint_getTarget));
    cls->defineFunction(inst, "setScaleMix", _SE(js_cocos2dx_spine_TransformConstraint_setScaleMix));
    cls->defineFunction(inst, "getOrder", _SE(js_cocos2dx_spine_TransformConstraint_getOrder));
    cls->defineFunction(inst, "getShearMix", _SE(js_cocos2dx_spine_TransformConstraint_getShearMix));
    cls->defineFunction(inst, "apply", _SE(js_cocos2dx_spine_TransformConstraint_apply));
    cls->defineFunction(inst, "getData", _SE(js_cocos2dx_spine_TransformConstraint_getData));
    cls->defineFunction(inst, "isActive", _SE(js_cocos2dx_spine_TransformConstraint_isActive));
    cls->defineFunction(inst, "setTranslateMix", _SE(js_cocos2dx_spine_TransformConstraint_setTranslateMix));
    cls->install(inst);
    inst->registerClass<spine::TransformConstraint>(cls);

    __jsb_spine_TransformConstraint_proto = cls->getProto();
    __jsb_spine_TransformConstraint_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_TransformConstraintData_proto = nullptr;
se::Class* __jsb_spine_TransformConstraintData_class = nullptr;

static bool js_cocos2dx_spine_TransformConstraintData_getOffsetRotation(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraintData* cobj = (spine::TransformConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraintData_getOffsetRotation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getOffsetRotation();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraintData_getOffsetRotation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraintData_getOffsetRotation)

static bool js_cocos2dx_spine_TransformConstraintData_getRotateMix(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraintData* cobj = (spine::TransformConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraintData_getRotateMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRotateMix();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraintData_getRotateMix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraintData_getRotateMix)

static bool js_cocos2dx_spine_TransformConstraintData_isLocal(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraintData* cobj = (spine::TransformConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraintData_isLocal : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isLocal();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraintData_isLocal : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraintData_isLocal)

static bool js_cocos2dx_spine_TransformConstraintData_getBones(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraintData* cobj = (spine::TransformConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraintData_getBones : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Vector<spine::BoneData *>& result = cobj->getBones();
        ok &= spine_Vector_T_ptr_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraintData_getBones : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraintData_getBones)

static bool js_cocos2dx_spine_TransformConstraintData_isRelative(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraintData* cobj = (spine::TransformConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraintData_isRelative : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isRelative();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraintData_isRelative : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraintData_isRelative)

static bool js_cocos2dx_spine_TransformConstraintData_getTranslateMix(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraintData* cobj = (spine::TransformConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraintData_getTranslateMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTranslateMix();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraintData_getTranslateMix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraintData_getTranslateMix)

static bool js_cocos2dx_spine_TransformConstraintData_getTarget(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraintData* cobj = (spine::TransformConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraintData_getTarget : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::BoneData* result = cobj->getTarget();
        ok &= native_ptr_to_rooted_seval<spine::BoneData>(inst, (spine::BoneData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraintData_getTarget : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraintData_getTarget)

static bool js_cocos2dx_spine_TransformConstraintData_getOffsetScaleX(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraintData* cobj = (spine::TransformConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraintData_getOffsetScaleX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getOffsetScaleX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraintData_getOffsetScaleX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraintData_getOffsetScaleX)

static bool js_cocos2dx_spine_TransformConstraintData_getOffsetScaleY(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraintData* cobj = (spine::TransformConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraintData_getOffsetScaleY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getOffsetScaleY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraintData_getOffsetScaleY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraintData_getOffsetScaleY)

static bool js_cocos2dx_spine_TransformConstraintData_getOffsetShearY(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraintData* cobj = (spine::TransformConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraintData_getOffsetShearY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getOffsetShearY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraintData_getOffsetShearY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraintData_getOffsetShearY)

static bool js_cocos2dx_spine_TransformConstraintData_getOffsetY(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraintData* cobj = (spine::TransformConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraintData_getOffsetY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getOffsetY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraintData_getOffsetY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraintData_getOffsetY)

static bool js_cocos2dx_spine_TransformConstraintData_getOffsetX(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraintData* cobj = (spine::TransformConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraintData_getOffsetX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getOffsetX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraintData_getOffsetX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraintData_getOffsetX)

static bool js_cocos2dx_spine_TransformConstraintData_getShearMix(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraintData* cobj = (spine::TransformConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraintData_getShearMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getShearMix();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraintData_getShearMix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraintData_getShearMix)

static bool js_cocos2dx_spine_TransformConstraintData_getScaleMix(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraintData* cobj = (spine::TransformConstraintData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraintData_getScaleMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getScaleMix();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraintData_getScaleMix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraintData_getScaleMix)


extern se::Object* __jsb_spine_ConstraintData_proto;


bool js_register_cocos2dx_spine_TransformConstraintData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "TransformConstraintData", obj, __jsb_spine_ConstraintData_proto, nullptr);

    cls->defineFunction(inst, "getOffsetRotation", _SE(js_cocos2dx_spine_TransformConstraintData_getOffsetRotation));
    cls->defineFunction(inst, "getRotateMix", _SE(js_cocos2dx_spine_TransformConstraintData_getRotateMix));
    cls->defineFunction(inst, "isLocal", _SE(js_cocos2dx_spine_TransformConstraintData_isLocal));
    cls->defineFunction(inst, "getBones", _SE(js_cocos2dx_spine_TransformConstraintData_getBones));
    cls->defineFunction(inst, "isRelative", _SE(js_cocos2dx_spine_TransformConstraintData_isRelative));
    cls->defineFunction(inst, "getTranslateMix", _SE(js_cocos2dx_spine_TransformConstraintData_getTranslateMix));
    cls->defineFunction(inst, "getTarget", _SE(js_cocos2dx_spine_TransformConstraintData_getTarget));
    cls->defineFunction(inst, "getOffsetScaleX", _SE(js_cocos2dx_spine_TransformConstraintData_getOffsetScaleX));
    cls->defineFunction(inst, "getOffsetScaleY", _SE(js_cocos2dx_spine_TransformConstraintData_getOffsetScaleY));
    cls->defineFunction(inst, "getOffsetShearY", _SE(js_cocos2dx_spine_TransformConstraintData_getOffsetShearY));
    cls->defineFunction(inst, "getOffsetY", _SE(js_cocos2dx_spine_TransformConstraintData_getOffsetY));
    cls->defineFunction(inst, "getOffsetX", _SE(js_cocos2dx_spine_TransformConstraintData_getOffsetX));
    cls->defineFunction(inst, "getShearMix", _SE(js_cocos2dx_spine_TransformConstraintData_getShearMix));
    cls->defineFunction(inst, "getScaleMix", _SE(js_cocos2dx_spine_TransformConstraintData_getScaleMix));
    cls->install(inst);
    inst->registerClass<spine::TransformConstraintData>(cls);

    __jsb_spine_TransformConstraintData_proto = cls->getProto();
    __jsb_spine_TransformConstraintData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_TransformConstraintTimeline_proto = nullptr;
se::Class* __jsb_spine_TransformConstraintTimeline_class = nullptr;

static bool js_cocos2dx_spine_TransformConstraintTimeline_getPropertyId(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraintTimeline* cobj = (spine::TransformConstraintTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraintTimeline_getPropertyId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPropertyId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraintTimeline_getPropertyId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraintTimeline_getPropertyId)

static bool js_cocos2dx_spine_TransformConstraintTimeline_setFrame(se::State &s, se::ScriptEngine *inst)
{
    spine::TransformConstraintTimeline* cobj = (spine::TransformConstraintTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TransformConstraintTimeline_setFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 6) {
        size_t arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        float arg5 = 0;
        ok &= seval_to_size(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_float(inst, args[4], &arg4);
        ok &= seval_to_float(inst, args[5], &arg5);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TransformConstraintTimeline_setFrame : Error processing arguments");
        cobj->setFrame(arg0, arg1, arg2, arg3, arg4, arg5);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 6);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TransformConstraintTimeline_setFrame)


extern se::Object* __jsb_spine_CurveTimeline_proto;


bool js_register_cocos2dx_spine_TransformConstraintTimeline(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "TransformConstraintTimeline", obj, __jsb_spine_CurveTimeline_proto, nullptr);

    cls->defineFunction(inst, "getPropertyId", _SE(js_cocos2dx_spine_TransformConstraintTimeline_getPropertyId));
    cls->defineFunction(inst, "setFrame", _SE(js_cocos2dx_spine_TransformConstraintTimeline_setFrame));
    cls->install(inst);
    inst->registerClass<spine::TransformConstraintTimeline>(cls);

    __jsb_spine_TransformConstraintTimeline_proto = cls->getProto();
    __jsb_spine_TransformConstraintTimeline_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_TwoColorTimeline_proto = nullptr;
se::Class* __jsb_spine_TwoColorTimeline_class = nullptr;

static bool js_cocos2dx_spine_TwoColorTimeline_setSlotIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::TwoColorTimeline* cobj = (spine::TwoColorTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TwoColorTimeline_setSlotIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TwoColorTimeline_setSlotIndex : Error processing arguments");
        cobj->setSlotIndex(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TwoColorTimeline_setSlotIndex)

static bool js_cocos2dx_spine_TwoColorTimeline_getPropertyId(se::State &s, se::ScriptEngine *inst)
{
    spine::TwoColorTimeline* cobj = (spine::TwoColorTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TwoColorTimeline_getPropertyId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPropertyId();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TwoColorTimeline_getPropertyId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TwoColorTimeline_getPropertyId)

static bool js_cocos2dx_spine_TwoColorTimeline_setFrame(se::State &s, se::ScriptEngine *inst)
{
    spine::TwoColorTimeline* cobj = (spine::TwoColorTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TwoColorTimeline_setFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 9) {
        int arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        float arg5 = 0;
        float arg6 = 0;
        float arg7 = 0;
        float arg8 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_float(inst, args[4], &arg4);
        ok &= seval_to_float(inst, args[5], &arg5);
        ok &= seval_to_float(inst, args[6], &arg6);
        ok &= seval_to_float(inst, args[7], &arg7);
        ok &= seval_to_float(inst, args[8], &arg8);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TwoColorTimeline_setFrame : Error processing arguments");
        cobj->setFrame(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 9);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TwoColorTimeline_setFrame)

static bool js_cocos2dx_spine_TwoColorTimeline_getSlotIndex(se::State &s, se::ScriptEngine *inst)
{
    spine::TwoColorTimeline* cobj = (spine::TwoColorTimeline*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_TwoColorTimeline_getSlotIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getSlotIndex();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_TwoColorTimeline_getSlotIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_TwoColorTimeline_getSlotIndex)


extern se::Object* __jsb_spine_CurveTimeline_proto;


bool js_register_cocos2dx_spine_TwoColorTimeline(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "TwoColorTimeline", obj, __jsb_spine_CurveTimeline_proto, nullptr);

    cls->defineFunction(inst, "setSlotIndex", _SE(js_cocos2dx_spine_TwoColorTimeline_setSlotIndex));
    cls->defineFunction(inst, "getPropertyId", _SE(js_cocos2dx_spine_TwoColorTimeline_getPropertyId));
    cls->defineFunction(inst, "setFrame", _SE(js_cocos2dx_spine_TwoColorTimeline_setFrame));
    cls->defineFunction(inst, "getSlotIndex", _SE(js_cocos2dx_spine_TwoColorTimeline_getSlotIndex));
    cls->install(inst);
    inst->registerClass<spine::TwoColorTimeline>(cls);

    __jsb_spine_TwoColorTimeline_proto = cls->getProto();
    __jsb_spine_TwoColorTimeline_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_VertexEffect_proto = nullptr;
se::Class* __jsb_spine_VertexEffect_class = nullptr;




bool js_register_cocos2dx_spine_VertexEffect(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "VertexEffect", obj, nullptr, nullptr);

    cls->install(inst);
    inst->registerClass<spine::VertexEffect>(cls);

    __jsb_spine_VertexEffect_proto = cls->getProto();
    __jsb_spine_VertexEffect_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_JitterVertexEffect_proto = nullptr;
se::Class* __jsb_spine_JitterVertexEffect_class = nullptr;

static bool js_cocos2dx_spine_JitterVertexEffect_setJitterX(se::State &s, se::ScriptEngine *inst)
{
    spine::JitterVertexEffect* cobj = (spine::JitterVertexEffect*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_JitterVertexEffect_setJitterX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_JitterVertexEffect_setJitterX : Error processing arguments");
        cobj->setJitterX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_JitterVertexEffect_setJitterX)

static bool js_cocos2dx_spine_JitterVertexEffect_setJitterY(se::State &s, se::ScriptEngine *inst)
{
    spine::JitterVertexEffect* cobj = (spine::JitterVertexEffect*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_JitterVertexEffect_setJitterY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_JitterVertexEffect_setJitterY : Error processing arguments");
        cobj->setJitterY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_JitterVertexEffect_setJitterY)

static bool js_cocos2dx_spine_JitterVertexEffect_getJitterX(se::State &s, se::ScriptEngine *inst)
{
    spine::JitterVertexEffect* cobj = (spine::JitterVertexEffect*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_JitterVertexEffect_getJitterX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getJitterX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_JitterVertexEffect_getJitterX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_JitterVertexEffect_getJitterX)

static bool js_cocos2dx_spine_JitterVertexEffect_getJitterY(se::State &s, se::ScriptEngine *inst)
{
    spine::JitterVertexEffect* cobj = (spine::JitterVertexEffect*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_JitterVertexEffect_getJitterY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getJitterY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_JitterVertexEffect_getJitterY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_JitterVertexEffect_getJitterY)


extern se::Object* __jsb_spine_VertexEffect_proto;


bool js_register_cocos2dx_spine_JitterVertexEffect(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "JitterVertexEffect", obj, __jsb_spine_VertexEffect_proto, nullptr);

    cls->defineFunction(inst, "setJitterX", _SE(js_cocos2dx_spine_JitterVertexEffect_setJitterX));
    cls->defineFunction(inst, "setJitterY", _SE(js_cocos2dx_spine_JitterVertexEffect_setJitterY));
    cls->defineFunction(inst, "getJitterX", _SE(js_cocos2dx_spine_JitterVertexEffect_getJitterX));
    cls->defineFunction(inst, "getJitterY", _SE(js_cocos2dx_spine_JitterVertexEffect_getJitterY));
    cls->install(inst);
    inst->registerClass<spine::JitterVertexEffect>(cls);

    __jsb_spine_JitterVertexEffect_proto = cls->getProto();
    __jsb_spine_JitterVertexEffect_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_SwirlVertexEffect_proto = nullptr;
se::Class* __jsb_spine_SwirlVertexEffect_class = nullptr;

static bool js_cocos2dx_spine_SwirlVertexEffect_setRadius(se::State &s, se::ScriptEngine *inst)
{
    spine::SwirlVertexEffect* cobj = (spine::SwirlVertexEffect*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SwirlVertexEffect_setRadius : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SwirlVertexEffect_setRadius : Error processing arguments");
        cobj->setRadius(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SwirlVertexEffect_setRadius)

static bool js_cocos2dx_spine_SwirlVertexEffect_getAngle(se::State &s, se::ScriptEngine *inst)
{
    spine::SwirlVertexEffect* cobj = (spine::SwirlVertexEffect*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SwirlVertexEffect_getAngle : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getAngle();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SwirlVertexEffect_getAngle : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SwirlVertexEffect_getAngle)

static bool js_cocos2dx_spine_SwirlVertexEffect_getCenterY(se::State &s, se::ScriptEngine *inst)
{
    spine::SwirlVertexEffect* cobj = (spine::SwirlVertexEffect*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SwirlVertexEffect_getCenterY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getCenterY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SwirlVertexEffect_getCenterY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SwirlVertexEffect_getCenterY)

static bool js_cocos2dx_spine_SwirlVertexEffect_getCenterX(se::State &s, se::ScriptEngine *inst)
{
    spine::SwirlVertexEffect* cobj = (spine::SwirlVertexEffect*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SwirlVertexEffect_getCenterX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getCenterX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SwirlVertexEffect_getCenterX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SwirlVertexEffect_getCenterX)

static bool js_cocos2dx_spine_SwirlVertexEffect_setAngle(se::State &s, se::ScriptEngine *inst)
{
    spine::SwirlVertexEffect* cobj = (spine::SwirlVertexEffect*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SwirlVertexEffect_setAngle : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SwirlVertexEffect_setAngle : Error processing arguments");
        cobj->setAngle(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SwirlVertexEffect_setAngle)

static bool js_cocos2dx_spine_SwirlVertexEffect_setWorldX(se::State &s, se::ScriptEngine *inst)
{
    spine::SwirlVertexEffect* cobj = (spine::SwirlVertexEffect*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SwirlVertexEffect_setWorldX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SwirlVertexEffect_setWorldX : Error processing arguments");
        cobj->setWorldX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SwirlVertexEffect_setWorldX)

static bool js_cocos2dx_spine_SwirlVertexEffect_setWorldY(se::State &s, se::ScriptEngine *inst)
{
    spine::SwirlVertexEffect* cobj = (spine::SwirlVertexEffect*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SwirlVertexEffect_setWorldY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SwirlVertexEffect_setWorldY : Error processing arguments");
        cobj->setWorldY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SwirlVertexEffect_setWorldY)

static bool js_cocos2dx_spine_SwirlVertexEffect_getWorldY(se::State &s, se::ScriptEngine *inst)
{
    spine::SwirlVertexEffect* cobj = (spine::SwirlVertexEffect*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SwirlVertexEffect_getWorldY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getWorldY();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SwirlVertexEffect_getWorldY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SwirlVertexEffect_getWorldY)

static bool js_cocos2dx_spine_SwirlVertexEffect_getWorldX(se::State &s, se::ScriptEngine *inst)
{
    spine::SwirlVertexEffect* cobj = (spine::SwirlVertexEffect*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SwirlVertexEffect_getWorldX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getWorldX();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SwirlVertexEffect_getWorldX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SwirlVertexEffect_getWorldX)

static bool js_cocos2dx_spine_SwirlVertexEffect_setCenterY(se::State &s, se::ScriptEngine *inst)
{
    spine::SwirlVertexEffect* cobj = (spine::SwirlVertexEffect*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SwirlVertexEffect_setCenterY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SwirlVertexEffect_setCenterY : Error processing arguments");
        cobj->setCenterY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SwirlVertexEffect_setCenterY)

static bool js_cocos2dx_spine_SwirlVertexEffect_setCenterX(se::State &s, se::ScriptEngine *inst)
{
    spine::SwirlVertexEffect* cobj = (spine::SwirlVertexEffect*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SwirlVertexEffect_setCenterX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SwirlVertexEffect_setCenterX : Error processing arguments");
        cobj->setCenterX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SwirlVertexEffect_setCenterX)

static bool js_cocos2dx_spine_SwirlVertexEffect_getRadius(se::State &s, se::ScriptEngine *inst)
{
    spine::SwirlVertexEffect* cobj = (spine::SwirlVertexEffect*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SwirlVertexEffect_getRadius : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRadius();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SwirlVertexEffect_getRadius : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SwirlVertexEffect_getRadius)


extern se::Object* __jsb_spine_VertexEffect_proto;


bool js_register_cocos2dx_spine_SwirlVertexEffect(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "SwirlVertexEffect", obj, __jsb_spine_VertexEffect_proto, nullptr);

    cls->defineFunction(inst, "setRadius", _SE(js_cocos2dx_spine_SwirlVertexEffect_setRadius));
    cls->defineFunction(inst, "getAngle", _SE(js_cocos2dx_spine_SwirlVertexEffect_getAngle));
    cls->defineFunction(inst, "getCenterY", _SE(js_cocos2dx_spine_SwirlVertexEffect_getCenterY));
    cls->defineFunction(inst, "getCenterX", _SE(js_cocos2dx_spine_SwirlVertexEffect_getCenterX));
    cls->defineFunction(inst, "setAngle", _SE(js_cocos2dx_spine_SwirlVertexEffect_setAngle));
    cls->defineFunction(inst, "setWorldX", _SE(js_cocos2dx_spine_SwirlVertexEffect_setWorldX));
    cls->defineFunction(inst, "setWorldY", _SE(js_cocos2dx_spine_SwirlVertexEffect_setWorldY));
    cls->defineFunction(inst, "getWorldY", _SE(js_cocos2dx_spine_SwirlVertexEffect_getWorldY));
    cls->defineFunction(inst, "getWorldX", _SE(js_cocos2dx_spine_SwirlVertexEffect_getWorldX));
    cls->defineFunction(inst, "setCenterY", _SE(js_cocos2dx_spine_SwirlVertexEffect_setCenterY));
    cls->defineFunction(inst, "setCenterX", _SE(js_cocos2dx_spine_SwirlVertexEffect_setCenterX));
    cls->defineFunction(inst, "getRadius", _SE(js_cocos2dx_spine_SwirlVertexEffect_getRadius));
    cls->install(inst);
    inst->registerClass<spine::SwirlVertexEffect>(cls);

    __jsb_spine_SwirlVertexEffect_proto = cls->getProto();
    __jsb_spine_SwirlVertexEffect_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_VertexEffectDelegate_proto = nullptr;
se::Class* __jsb_spine_VertexEffectDelegate_class = nullptr;

static bool js_cocos2dx_spine_VertexEffectDelegate_getEffectType(se::State &s, se::ScriptEngine *inst)
{
    spine::VertexEffectDelegate* cobj = (spine::VertexEffectDelegate*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_VertexEffectDelegate_getEffectType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cobj->getEffectType();
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_VertexEffectDelegate_getEffectType : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_VertexEffectDelegate_getEffectType)

static bool js_cocos2dx_spine_VertexEffectDelegate_initSwirlWithPowOut(se::State &s, se::ScriptEngine *inst)
{
    spine::VertexEffectDelegate* cobj = (spine::VertexEffectDelegate*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_VertexEffectDelegate_initSwirlWithPowOut : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        int arg1 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[1], &tmp); arg1 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_VertexEffectDelegate_initSwirlWithPowOut : Error processing arguments");
        spine::SwirlVertexEffect* result = cobj->initSwirlWithPowOut(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<spine::SwirlVertexEffect>(inst, (spine::SwirlVertexEffect*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_VertexEffectDelegate_initSwirlWithPowOut : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_VertexEffectDelegate_initSwirlWithPowOut)

static bool js_cocos2dx_spine_VertexEffectDelegate_initSwirlWithPow(se::State &s, se::ScriptEngine *inst)
{
    spine::VertexEffectDelegate* cobj = (spine::VertexEffectDelegate*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_VertexEffectDelegate_initSwirlWithPow : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        int arg1 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[1], &tmp); arg1 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_VertexEffectDelegate_initSwirlWithPow : Error processing arguments");
        spine::SwirlVertexEffect* result = cobj->initSwirlWithPow(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<spine::SwirlVertexEffect>(inst, (spine::SwirlVertexEffect*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_VertexEffectDelegate_initSwirlWithPow : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_VertexEffectDelegate_initSwirlWithPow)

static bool js_cocos2dx_spine_VertexEffectDelegate_initJitter(se::State &s, se::ScriptEngine *inst)
{
    spine::VertexEffectDelegate* cobj = (spine::VertexEffectDelegate*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_VertexEffectDelegate_initJitter : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_VertexEffectDelegate_initJitter : Error processing arguments");
        spine::JitterVertexEffect* result = cobj->initJitter(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<spine::JitterVertexEffect>(inst, (spine::JitterVertexEffect*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_VertexEffectDelegate_initJitter : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_VertexEffectDelegate_initJitter)

static bool js_cocos2dx_spine_VertexEffectDelegate_getSwirlVertexEffect(se::State &s, se::ScriptEngine *inst)
{
    spine::VertexEffectDelegate* cobj = (spine::VertexEffectDelegate*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_VertexEffectDelegate_getSwirlVertexEffect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::SwirlVertexEffect* result = cobj->getSwirlVertexEffect();
        ok &= native_ptr_to_rooted_seval<spine::SwirlVertexEffect>(inst, (spine::SwirlVertexEffect*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_VertexEffectDelegate_getSwirlVertexEffect : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_VertexEffectDelegate_getSwirlVertexEffect)

static bool js_cocos2dx_spine_VertexEffectDelegate_getVertexEffect(se::State &s, se::ScriptEngine *inst)
{
    spine::VertexEffectDelegate* cobj = (spine::VertexEffectDelegate*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_VertexEffectDelegate_getVertexEffect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::VertexEffect* result = cobj->getVertexEffect();
        ok &= native_ptr_to_rooted_seval<spine::VertexEffect>(inst, (spine::VertexEffect*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_VertexEffectDelegate_getVertexEffect : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_VertexEffectDelegate_getVertexEffect)

static bool js_cocos2dx_spine_VertexEffectDelegate_getJitterVertexEffect(se::State &s, se::ScriptEngine *inst)
{
    spine::VertexEffectDelegate* cobj = (spine::VertexEffectDelegate*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_VertexEffectDelegate_getJitterVertexEffect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::JitterVertexEffect* result = cobj->getJitterVertexEffect();
        ok &= native_ptr_to_rooted_seval<spine::JitterVertexEffect>(inst, (spine::JitterVertexEffect*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_VertexEffectDelegate_getJitterVertexEffect : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_VertexEffectDelegate_getJitterVertexEffect)

static bool js_cocos2dx_spine_VertexEffectDelegate_clear(se::State &s, se::ScriptEngine *inst)
{
    spine::VertexEffectDelegate* cobj = (spine::VertexEffectDelegate*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_VertexEffectDelegate_clear : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->clear();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_VertexEffectDelegate_clear)

SE_DECLARE_FINALIZE_FUNC(js_spine_VertexEffectDelegate_finalize)

static bool js_cocos2dx_spine_VertexEffectDelegate_constructor(se::State &s, se::ScriptEngine *inst)
{
    spine::VertexEffectDelegate* cobj = new (std::nothrow) spine::VertexEffectDelegate();
    s.thisObject(inst)->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_spine_VertexEffectDelegate_constructor, __jsb_spine_VertexEffectDelegate_class, js_spine_VertexEffectDelegate_finalize)




static bool js_spine_VertexEffectDelegate_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (spine::VertexEffectDelegate)", s.nativeThisObject());
    spine::VertexEffectDelegate* cobj = (spine::VertexEffectDelegate*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_spine_VertexEffectDelegate_finalize)

bool js_register_cocos2dx_spine_VertexEffectDelegate(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "VertexEffectDelegate", obj, nullptr, _SE(js_cocos2dx_spine_VertexEffectDelegate_constructor));

    cls->defineFunction(inst, "getEffectType", _SE(js_cocos2dx_spine_VertexEffectDelegate_getEffectType));
    cls->defineFunction(inst, "initSwirlWithPowOut", _SE(js_cocos2dx_spine_VertexEffectDelegate_initSwirlWithPowOut));
    cls->defineFunction(inst, "initSwirlWithPow", _SE(js_cocos2dx_spine_VertexEffectDelegate_initSwirlWithPow));
    cls->defineFunction(inst, "initJitter", _SE(js_cocos2dx_spine_VertexEffectDelegate_initJitter));
    cls->defineFunction(inst, "getSwirlVertexEffect", _SE(js_cocos2dx_spine_VertexEffectDelegate_getSwirlVertexEffect));
    cls->defineFunction(inst, "getVertexEffect", _SE(js_cocos2dx_spine_VertexEffectDelegate_getVertexEffect));
    cls->defineFunction(inst, "getJitterVertexEffect", _SE(js_cocos2dx_spine_VertexEffectDelegate_getJitterVertexEffect));
    cls->defineFunction(inst, "clear", _SE(js_cocos2dx_spine_VertexEffectDelegate_clear));
    cls->defineFinalizeFunction(_SE(js_spine_VertexEffectDelegate_finalize));
    cls->install(inst);
    inst->registerClass<spine::VertexEffectDelegate>(cls);

    __jsb_spine_VertexEffectDelegate_proto = cls->getProto();
    __jsb_spine_VertexEffectDelegate_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_SkeletonRenderer_proto = nullptr;
se::Class* __jsb_spine_SkeletonRenderer_class = nullptr;

static bool js_cocos2dx_spine_SkeletonRenderer_setUseTint(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_setUseTint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_setUseTint : Error processing arguments");
        cobj->setUseTint(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_setUseTint)

static bool js_cocos2dx_spine_SkeletonRenderer_setTimeScale(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_setTimeScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_setTimeScale : Error processing arguments");
        cobj->setTimeScale(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_setTimeScale)

static bool js_cocos2dx_spine_SkeletonRenderer_render(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_render : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_render : Error processing arguments");
        cobj->render(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_render)

static bool js_cocos2dx_spine_SkeletonRenderer_initWithUUID(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_initWithUUID : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_initWithUUID : Error processing arguments");
        cobj->initWithUUID(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_initWithUUID)

static bool js_cocos2dx_spine_SkeletonRenderer_setAttachUtil(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_setAttachUtil : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::RealTimeAttachUtil* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_setAttachUtil : Error processing arguments");
        cobj->setAttachUtil(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_setAttachUtil)

static bool js_cocos2dx_spine_SkeletonRenderer_setOpacityModifyRGB(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_setOpacityModifyRGB : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_setOpacityModifyRGB : Error processing arguments");
        cobj->setOpacityModifyRGB(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_setOpacityModifyRGB)

static bool js_cocos2dx_spine_SkeletonRenderer_paused(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_paused : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_paused : Error processing arguments");
        cobj->paused(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_paused)

static bool js_cocos2dx_spine_SkeletonRenderer_setAttachment(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_spine_SkeletonRenderer_setAttachment : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            const char* arg1 = nullptr;
            std::string arg1_tmp; ok &= seval_to_std_string(inst, args[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { ok = true; break; }
            bool result = cobj->setAttachment(arg0, arg1);
            ok &= boolean_to_seval(inst, result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_setAttachment : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            bool result = cobj->setAttachment(arg0, arg1);
            ok &= boolean_to_seval(inst, result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_setAttachment : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_setAttachment)

static bool js_cocos2dx_spine_SkeletonRenderer_setBonesToSetupPose(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_setBonesToSetupPose : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->setBonesToSetupPose();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_setBonesToSetupPose)

static bool js_cocos2dx_spine_SkeletonRenderer_onEnable(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_onEnable : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->onEnable();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_onEnable)

static bool js_cocos2dx_spine_SkeletonRenderer_setEffect(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_setEffect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::renderer::EffectVariant* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_setEffect : Error processing arguments");
        cobj->setEffect(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_setEffect)

static bool js_cocos2dx_spine_SkeletonRenderer_stopSchedule(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_stopSchedule : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->stopSchedule();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_stopSchedule)

static bool js_cocos2dx_spine_SkeletonRenderer_isOpacityModifyRGB(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_isOpacityModifyRGB : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isOpacityModifyRGB();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_isOpacityModifyRGB : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_isOpacityModifyRGB)

static bool js_cocos2dx_spine_SkeletonRenderer_setDebugSlotsEnabled(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_setDebugSlotsEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_setDebugSlotsEnabled : Error processing arguments");
        cobj->setDebugSlotsEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_setDebugSlotsEnabled)

static bool js_cocos2dx_spine_SkeletonRenderer_initWithJsonFile(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_spine_SkeletonRenderer_initWithJsonFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            cobj->initWithJsonFile(arg0, arg1);
            return true;
        }
    } while(false);

    do {
        if (argc == 3) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            cobj->initWithJsonFile(arg0, arg1, arg2);
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            spine::Atlas* arg1 = nullptr;
            ok &= seval_to_native_ptr(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            cobj->initWithJsonFile(arg0, arg1);
            return true;
        }
    } while(false);

    do {
        if (argc == 3) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            spine::Atlas* arg1 = nullptr;
            ok &= seval_to_native_ptr(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            cobj->initWithJsonFile(arg0, arg1, arg2);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_initWithJsonFile)

static bool js_cocos2dx_spine_SkeletonRenderer_setToSetupPose(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_setToSetupPose : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->setToSetupPose();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_setToSetupPose)

static bool js_cocos2dx_spine_SkeletonRenderer_setSlotsToSetupPose(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_setSlotsToSetupPose : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->setSlotsToSetupPose();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_setSlotsToSetupPose)

static bool js_cocos2dx_spine_SkeletonRenderer_initWithBinaryFile(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_spine_SkeletonRenderer_initWithBinaryFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            cobj->initWithBinaryFile(arg0, arg1);
            return true;
        }
    } while(false);

    do {
        if (argc == 3) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            cobj->initWithBinaryFile(arg0, arg1, arg2);
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            spine::Atlas* arg1 = nullptr;
            ok &= seval_to_native_ptr(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            cobj->initWithBinaryFile(arg0, arg1);
            return true;
        }
    } while(false);

    do {
        if (argc == 3) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            spine::Atlas* arg1 = nullptr;
            ok &= seval_to_native_ptr(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            cobj->initWithBinaryFile(arg0, arg1, arg2);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_initWithBinaryFile)

static bool js_cocos2dx_spine_SkeletonRenderer_initWithSkeleton(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_initWithSkeleton : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::Skeleton* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_initWithSkeleton : Error processing arguments");
        cobj->initWithSkeleton(arg0);
        return true;
    }
    if (argc == 2) {
        spine::Skeleton* arg0 = nullptr;
        bool arg1;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_boolean(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_initWithSkeleton : Error processing arguments");
        cobj->initWithSkeleton(arg0, arg1);
        return true;
    }
    if (argc == 3) {
        spine::Skeleton* arg0 = nullptr;
        bool arg1;
        bool arg2;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_boolean(inst, args[1], &arg1);
        ok &= seval_to_boolean(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_initWithSkeleton : Error processing arguments");
        cobj->initWithSkeleton(arg0, arg1, arg2);
        return true;
    }
    if (argc == 4) {
        spine::Skeleton* arg0 = nullptr;
        bool arg1;
        bool arg2;
        bool arg3;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_boolean(inst, args[1], &arg1);
        ok &= seval_to_boolean(inst, args[2], &arg2);
        ok &= seval_to_boolean(inst, args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_initWithSkeleton : Error processing arguments");
        cobj->initWithSkeleton(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_initWithSkeleton)

static bool js_cocos2dx_spine_SkeletonRenderer_getBoundingBox(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_getBoundingBox : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Rect result = cobj->getBoundingBox();
        ok &= Rect_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_getBoundingBox : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_getBoundingBox)

static bool js_cocos2dx_spine_SkeletonRenderer_getDebugData(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_getDebugData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        se_object_ptr result = cobj->getDebugData();
        s.rval().setObject(result);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_getDebugData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_getDebugData)

static bool js_cocos2dx_spine_SkeletonRenderer_findBone(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_findBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_findBone : Error processing arguments");
        spine::Bone* result = cobj->findBone(arg0);
        ok &= native_ptr_to_rooted_seval<spine::Bone>(inst, (spine::Bone*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_findBone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_findBone)

static bool js_cocos2dx_spine_SkeletonRenderer_update(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_update : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_update : Error processing arguments");
        cobj->update(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_update)

static bool js_cocos2dx_spine_SkeletonRenderer_getAttachment(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_getAttachment : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_getAttachment : Error processing arguments");
        spine::Attachment* result = cobj->getAttachment(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<spine::Attachment>(inst, (spine::Attachment*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_getAttachment : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_getAttachment)

static bool js_cocos2dx_spine_SkeletonRenderer_setDebugMeshEnabled(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_setDebugMeshEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_setDebugMeshEnabled : Error processing arguments");
        cobj->setDebugMeshEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_setDebugMeshEnabled)

static bool js_cocos2dx_spine_SkeletonRenderer_beginSchedule(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_beginSchedule : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->beginSchedule();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_beginSchedule)

static bool js_cocos2dx_spine_SkeletonRenderer_initialize(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_initialize : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->initialize();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_initialize)

static bool js_cocos2dx_spine_SkeletonRenderer_setDebugBonesEnabled(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_setDebugBonesEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_setDebugBonesEnabled : Error processing arguments");
        cobj->setDebugBonesEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_setDebugBonesEnabled)

static bool js_cocos2dx_spine_SkeletonRenderer_getTimeScale(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_getTimeScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTimeScale();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_getTimeScale : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_getTimeScale)

static bool js_cocos2dx_spine_SkeletonRenderer_setSlotsRange(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_setSlotsRange : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        int arg1 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[1], &tmp); arg1 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_setSlotsRange : Error processing arguments");
        cobj->setSlotsRange(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_setSlotsRange)

static bool js_cocos2dx_spine_SkeletonRenderer_onDisable(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_onDisable : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->onDisable();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_onDisable)

static bool js_cocos2dx_spine_SkeletonRenderer_setColor(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_setColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Color4B arg0;
        ok &= seval_to_Color4B(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_setColor : Error processing arguments");
        cobj->setColor(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_setColor)

static bool js_cocos2dx_spine_SkeletonRenderer_bindNodeProxy(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_bindNodeProxy : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::renderer::NodeProxy* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_bindNodeProxy : Error processing arguments");
        cobj->bindNodeProxy(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_bindNodeProxy)

static bool js_cocos2dx_spine_SkeletonRenderer_setBatchEnabled(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_setBatchEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_setBatchEnabled : Error processing arguments");
        cobj->setBatchEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_setBatchEnabled)

static bool js_cocos2dx_spine_SkeletonRenderer_setSkin(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_spine_SkeletonRenderer_setSkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= seval_to_std_string(inst, args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            cobj->setSkin(arg0);
            return true;
        }
    } while(false);

    do {
        if (argc == 1) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            cobj->setSkin(arg0);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_setSkin)

static bool js_cocos2dx_spine_SkeletonRenderer_findSlot(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_findSlot : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_findSlot : Error processing arguments");
        spine::Slot* result = cobj->findSlot(arg0);
        ok &= native_ptr_to_rooted_seval<spine::Slot>(inst, (spine::Slot*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_findSlot : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_findSlot)

static bool js_cocos2dx_spine_SkeletonRenderer_updateWorldTransform(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_updateWorldTransform : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->updateWorldTransform();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_updateWorldTransform)

static bool js_cocos2dx_spine_SkeletonRenderer_getSkeleton(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_getSkeleton : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Skeleton* result = cobj->getSkeleton();
        ok &= native_ptr_to_rooted_seval<spine::Skeleton>(inst, (spine::Skeleton*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_getSkeleton : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_getSkeleton)

static bool js_cocos2dx_spine_SkeletonRenderer_setVertexEffectDelegate(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonRenderer_setVertexEffectDelegate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::VertexEffectDelegate* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonRenderer_setVertexEffectDelegate : Error processing arguments");
        cobj->setVertexEffectDelegate(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonRenderer_setVertexEffectDelegate)

SE_DECLARE_FINALIZE_FUNC(js_spine_SkeletonRenderer_finalize)

static bool js_cocos2dx_spine_SkeletonRenderer_constructor(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            spine::Skeleton* arg0 = nullptr;
            ok &= seval_to_native_ptr(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            spine::SkeletonRenderer* cobj = new (std::nothrow) spine::SkeletonRenderer(arg0);
            s.thisObject(inst)->setPrivateData(cobj);
            return true;
        }
    } while(false);
    do {
        if (argc == 2) {
            spine::Skeleton* arg0 = nullptr;
            ok &= seval_to_native_ptr(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            bool arg1;
            ok &= seval_to_boolean(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            spine::SkeletonRenderer* cobj = new (std::nothrow) spine::SkeletonRenderer(arg0, arg1);
            s.thisObject(inst)->setPrivateData(cobj);
            return true;
        }
    } while(false);
    do {
        if (argc == 3) {
            spine::Skeleton* arg0 = nullptr;
            ok &= seval_to_native_ptr(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            bool arg1;
            ok &= seval_to_boolean(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            bool arg2;
            ok &= seval_to_boolean(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            spine::SkeletonRenderer* cobj = new (std::nothrow) spine::SkeletonRenderer(arg0, arg1, arg2);
            s.thisObject(inst)->setPrivateData(cobj);
            return true;
        }
    } while(false);
    do {
        if (argc == 4) {
            spine::Skeleton* arg0 = nullptr;
            ok &= seval_to_native_ptr(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            bool arg1;
            ok &= seval_to_boolean(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            bool arg2;
            ok &= seval_to_boolean(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            bool arg3;
            ok &= seval_to_boolean(inst, args[3], &arg3);
            if (!ok) { ok = true; break; }
            spine::SkeletonRenderer* cobj = new (std::nothrow) spine::SkeletonRenderer(arg0, arg1, arg2, arg3);
            s.thisObject(inst)->setPrivateData(cobj);
            return true;
        }
    } while(false);
    do {
        if (argc == 0) {
            spine::SkeletonRenderer* cobj = new (std::nothrow) spine::SkeletonRenderer();
            s.thisObject(inst)->setPrivateData(cobj);
            return true;
        }
    } while(false);
    do {
        if (argc == 1) {
            spine::SkeletonData* arg0 = nullptr;
            ok &= seval_to_native_ptr(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            spine::SkeletonRenderer* cobj = new (std::nothrow) spine::SkeletonRenderer(arg0);
            s.thisObject(inst)->setPrivateData(cobj);
            return true;
        }
    } while(false);
    do {
        if (argc == 2) {
            spine::SkeletonData* arg0 = nullptr;
            ok &= seval_to_native_ptr(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            bool arg1;
            ok &= seval_to_boolean(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            spine::SkeletonRenderer* cobj = new (std::nothrow) spine::SkeletonRenderer(arg0, arg1);
            s.thisObject(inst)->setPrivateData(cobj);
            return true;
        }
    } while(false);
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            spine::Atlas* arg1 = nullptr;
            ok &= seval_to_native_ptr(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            spine::SkeletonRenderer* cobj = new (std::nothrow) spine::SkeletonRenderer(arg0, arg1);
            s.thisObject(inst)->setPrivateData(cobj);
            return true;
        }
    } while(false);
    do {
        if (argc == 3) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            spine::Atlas* arg1 = nullptr;
            ok &= seval_to_native_ptr(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            spine::SkeletonRenderer* cobj = new (std::nothrow) spine::SkeletonRenderer(arg0, arg1, arg2);
            s.thisObject(inst)->setPrivateData(cobj);
            return true;
        }
    } while(false);
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            spine::SkeletonRenderer* cobj = new (std::nothrow) spine::SkeletonRenderer(arg0, arg1);
            s.thisObject(inst)->setPrivateData(cobj);
            return true;
        }
    } while(false);
    do {
        if (argc == 3) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            spine::SkeletonRenderer* cobj = new (std::nothrow) spine::SkeletonRenderer(arg0, arg1, arg2);
            s.thisObject(inst)->setPrivateData(cobj);
            return true;
        }
    } while(false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_CTOR(js_cocos2dx_spine_SkeletonRenderer_constructor, __jsb_spine_SkeletonRenderer_class, js_spine_SkeletonRenderer_finalize)




static bool js_spine_SkeletonRenderer_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (spine::SkeletonRenderer)", s.nativeThisObject());
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_spine_SkeletonRenderer_finalize)

bool js_register_cocos2dx_spine_SkeletonRenderer(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Skeleton", obj, nullptr, _SE(js_cocos2dx_spine_SkeletonRenderer_constructor));

    cls->defineFunction(inst, "setUseTint", _SE(js_cocos2dx_spine_SkeletonRenderer_setUseTint));
    cls->defineFunction(inst, "setTimeScale", _SE(js_cocos2dx_spine_SkeletonRenderer_setTimeScale));
    cls->defineFunction(inst, "render", _SE(js_cocos2dx_spine_SkeletonRenderer_render));
    cls->defineFunction(inst, "initWithUUID", _SE(js_cocos2dx_spine_SkeletonRenderer_initWithUUID));
    cls->defineFunction(inst, "setAttachUtil", _SE(js_cocos2dx_spine_SkeletonRenderer_setAttachUtil));
    cls->defineFunction(inst, "setOpacityModifyRGB", _SE(js_cocos2dx_spine_SkeletonRenderer_setOpacityModifyRGB));
    cls->defineFunction(inst, "paused", _SE(js_cocos2dx_spine_SkeletonRenderer_paused));
    cls->defineFunction(inst, "setAttachment", _SE(js_cocos2dx_spine_SkeletonRenderer_setAttachment));
    cls->defineFunction(inst, "setBonesToSetupPose", _SE(js_cocos2dx_spine_SkeletonRenderer_setBonesToSetupPose));
    cls->defineFunction(inst, "onEnable", _SE(js_cocos2dx_spine_SkeletonRenderer_onEnable));
    cls->defineFunction(inst, "setEffect", _SE(js_cocos2dx_spine_SkeletonRenderer_setEffect));
    cls->defineFunction(inst, "stopSchedule", _SE(js_cocos2dx_spine_SkeletonRenderer_stopSchedule));
    cls->defineFunction(inst, "isOpacityModifyRGB", _SE(js_cocos2dx_spine_SkeletonRenderer_isOpacityModifyRGB));
    cls->defineFunction(inst, "setDebugSlotsEnabled", _SE(js_cocos2dx_spine_SkeletonRenderer_setDebugSlotsEnabled));
    cls->defineFunction(inst, "initWithJsonFile", _SE(js_cocos2dx_spine_SkeletonRenderer_initWithJsonFile));
    cls->defineFunction(inst, "setToSetupPose", _SE(js_cocos2dx_spine_SkeletonRenderer_setToSetupPose));
    cls->defineFunction(inst, "setSlotsToSetupPose", _SE(js_cocos2dx_spine_SkeletonRenderer_setSlotsToSetupPose));
    cls->defineFunction(inst, "initWithBinaryFile", _SE(js_cocos2dx_spine_SkeletonRenderer_initWithBinaryFile));
    cls->defineFunction(inst, "initWithSkeleton", _SE(js_cocos2dx_spine_SkeletonRenderer_initWithSkeleton));
    cls->defineFunction(inst, "getBoundingBox", _SE(js_cocos2dx_spine_SkeletonRenderer_getBoundingBox));
    cls->defineFunction(inst, "getDebugData", _SE(js_cocos2dx_spine_SkeletonRenderer_getDebugData));
    cls->defineFunction(inst, "findBone", _SE(js_cocos2dx_spine_SkeletonRenderer_findBone));
    cls->defineFunction(inst, "update", _SE(js_cocos2dx_spine_SkeletonRenderer_update));
    cls->defineFunction(inst, "getAttachment", _SE(js_cocos2dx_spine_SkeletonRenderer_getAttachment));
    cls->defineFunction(inst, "setDebugMeshEnabled", _SE(js_cocos2dx_spine_SkeletonRenderer_setDebugMeshEnabled));
    cls->defineFunction(inst, "beginSchedule", _SE(js_cocos2dx_spine_SkeletonRenderer_beginSchedule));
    cls->defineFunction(inst, "initialize", _SE(js_cocos2dx_spine_SkeletonRenderer_initialize));
    cls->defineFunction(inst, "setDebugBonesEnabled", _SE(js_cocos2dx_spine_SkeletonRenderer_setDebugBonesEnabled));
    cls->defineFunction(inst, "getTimeScale", _SE(js_cocos2dx_spine_SkeletonRenderer_getTimeScale));
    cls->defineFunction(inst, "setSlotsRange", _SE(js_cocos2dx_spine_SkeletonRenderer_setSlotsRange));
    cls->defineFunction(inst, "onDisable", _SE(js_cocos2dx_spine_SkeletonRenderer_onDisable));
    cls->defineFunction(inst, "setColor", _SE(js_cocos2dx_spine_SkeletonRenderer_setColor));
    cls->defineFunction(inst, "bindNodeProxy", _SE(js_cocos2dx_spine_SkeletonRenderer_bindNodeProxy));
    cls->defineFunction(inst, "setBatchEnabled", _SE(js_cocos2dx_spine_SkeletonRenderer_setBatchEnabled));
    cls->defineFunction(inst, "setSkin", _SE(js_cocos2dx_spine_SkeletonRenderer_setSkin));
    cls->defineFunction(inst, "findSlot", _SE(js_cocos2dx_spine_SkeletonRenderer_findSlot));
    cls->defineFunction(inst, "updateWorldTransform", _SE(js_cocos2dx_spine_SkeletonRenderer_updateWorldTransform));
    cls->defineFunction(inst, "getSkeleton", _SE(js_cocos2dx_spine_SkeletonRenderer_getSkeleton));
    cls->defineFunction(inst, "setVertexEffectDelegate", _SE(js_cocos2dx_spine_SkeletonRenderer_setVertexEffectDelegate));
    cls->defineFinalizeFunction(_SE(js_spine_SkeletonRenderer_finalize));
    cls->install(inst);
    inst->registerClass<spine::SkeletonRenderer>(cls);

    __jsb_spine_SkeletonRenderer_proto = cls->getProto();
    __jsb_spine_SkeletonRenderer_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_SkeletonAnimation_proto = nullptr;
se::Class* __jsb_spine_SkeletonAnimation_class = nullptr;

static bool js_cocos2dx_spine_SkeletonAnimation_setAnimation(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_setAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        int arg0 = 0;
        std::string arg1;
        bool arg2;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        ok &= seval_to_boolean(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setAnimation : Error processing arguments");
        spine::TrackEntry* result = cobj->setAnimation(arg0, arg1, arg2);
        ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setAnimation)

static bool js_cocos2dx_spine_SkeletonAnimation_findAnimation(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_findAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_findAnimation : Error processing arguments");
        spine::Animation* result = cobj->findAnimation(arg0);
        ok &= native_ptr_to_rooted_seval<spine::Animation>(inst, (spine::Animation*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_findAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_findAnimation)

static bool js_cocos2dx_spine_SkeletonAnimation_setTrackEventListener(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackEventListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        spine::TrackEntry* arg0 = nullptr;
        std::function<void (spine::TrackEntry *, spine::Event *)> arg1;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        do {
            if (args[1].isObject() && args[1].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[1]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](spine::TrackEntry* larg0, spine::Event* larg1) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(2);
                    ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)larg0, &args[0]);
                    ok &= native_ptr_to_rooted_seval<spine::Event>(inst, (spine::Event*)larg1, &args[1]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                };
                arg1 = lambda;
            }
            else
            {
                arg1 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackEventListener : Error processing arguments");
        cobj->setTrackEventListener(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setTrackEventListener)

static bool js_cocos2dx_spine_SkeletonAnimation_setMix(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_setMix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        float arg2 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setMix : Error processing arguments");
        cobj->setMix(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setMix)

static bool js_cocos2dx_spine_SkeletonAnimation_setTrackStartListener(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackStartListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        spine::TrackEntry* arg0 = nullptr;
        std::function<void (spine::TrackEntry *)> arg1;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        do {
            if (args[1].isObject() && args[1].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[1]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](spine::TrackEntry* larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)larg0, &args[0]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                };
                arg1 = lambda;
            }
            else
            {
                arg1 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackStartListener : Error processing arguments");
        cobj->setTrackStartListener(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setTrackStartListener)

static bool js_cocos2dx_spine_SkeletonAnimation_addEmptyAnimation(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_addEmptyAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        float arg1 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_addEmptyAnimation : Error processing arguments");
        spine::TrackEntry* result = cobj->addEmptyAnimation(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_addEmptyAnimation : Error processing arguments");
        return true;
    }
    if (argc == 3) {
        int arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_addEmptyAnimation : Error processing arguments");
        spine::TrackEntry* result = cobj->addEmptyAnimation(arg0, arg1, arg2);
        ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_addEmptyAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_addEmptyAnimation)

static bool js_cocos2dx_spine_SkeletonAnimation_setDisposeListener(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_setDisposeListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void (spine::TrackEntry *)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](spine::TrackEntry* larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)larg0, &args[0]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setDisposeListener : Error processing arguments");
        cobj->setDisposeListener(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setDisposeListener)

static bool js_cocos2dx_spine_SkeletonAnimation_setTrackInterruptListener(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackInterruptListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        spine::TrackEntry* arg0 = nullptr;
        std::function<void (spine::TrackEntry *)> arg1;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        do {
            if (args[1].isObject() && args[1].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[1]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](spine::TrackEntry* larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)larg0, &args[0]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                };
                arg1 = lambda;
            }
            else
            {
                arg1 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackInterruptListener : Error processing arguments");
        cobj->setTrackInterruptListener(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setTrackInterruptListener)

static bool js_cocos2dx_spine_SkeletonAnimation_setTrackCompleteListener(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackCompleteListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        spine::TrackEntry* arg0 = nullptr;
        std::function<void (spine::TrackEntry *)> arg1;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        do {
            if (args[1].isObject() && args[1].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[1]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](spine::TrackEntry* larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)larg0, &args[0]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                };
                arg1 = lambda;
            }
            else
            {
                arg1 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackCompleteListener : Error processing arguments");
        cobj->setTrackCompleteListener(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setTrackCompleteListener)

static bool js_cocos2dx_spine_SkeletonAnimation_setAnimationStateData(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_setAnimationStateData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::AnimationStateData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setAnimationStateData : Error processing arguments");
        cobj->setAnimationStateData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setAnimationStateData)

static bool js_cocos2dx_spine_SkeletonAnimation_setEndListener(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_setEndListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void (spine::TrackEntry *)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](spine::TrackEntry* larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)larg0, &args[0]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setEndListener : Error processing arguments");
        cobj->setEndListener(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setEndListener)

static bool js_cocos2dx_spine_SkeletonAnimation_getState(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_getState : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::AnimationState* result = cobj->getState();
        ok &= native_ptr_to_rooted_seval<spine::AnimationState>(inst, (spine::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_getState : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_getState)

static bool js_cocos2dx_spine_SkeletonAnimation_setCompleteListener(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_setCompleteListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void (spine::TrackEntry *)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](spine::TrackEntry* larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)larg0, &args[0]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setCompleteListener : Error processing arguments");
        cobj->setCompleteListener(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setCompleteListener)

static bool js_cocos2dx_spine_SkeletonAnimation_setTrackDisposeListener(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackDisposeListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        spine::TrackEntry* arg0 = nullptr;
        std::function<void (spine::TrackEntry *)> arg1;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        do {
            if (args[1].isObject() && args[1].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[1]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](spine::TrackEntry* larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)larg0, &args[0]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                };
                arg1 = lambda;
            }
            else
            {
                arg1 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackDisposeListener : Error processing arguments");
        cobj->setTrackDisposeListener(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setTrackDisposeListener)

static bool js_cocos2dx_spine_SkeletonAnimation_getCurrent(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_getCurrent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::TrackEntry* result = cobj->getCurrent();
        ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_getCurrent : Error processing arguments");
        return true;
    }
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_getCurrent : Error processing arguments");
        spine::TrackEntry* result = cobj->getCurrent(arg0);
        ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_getCurrent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_getCurrent)

static bool js_cocos2dx_spine_SkeletonAnimation_setEventListener(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_setEventListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void (spine::TrackEntry *, spine::Event *)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](spine::TrackEntry* larg0, spine::Event* larg1) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(2);
                    ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)larg0, &args[0]);
                    ok &= native_ptr_to_rooted_seval<spine::Event>(inst, (spine::Event*)larg1, &args[1]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setEventListener : Error processing arguments");
        cobj->setEventListener(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setEventListener)

static bool js_cocos2dx_spine_SkeletonAnimation_setEmptyAnimation(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_setEmptyAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        float arg1 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setEmptyAnimation : Error processing arguments");
        spine::TrackEntry* result = cobj->setEmptyAnimation(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setEmptyAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setEmptyAnimation)

static bool js_cocos2dx_spine_SkeletonAnimation_clearTrack(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_clearTrack : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cobj->clearTrack();
        return true;
    }
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_clearTrack : Error processing arguments");
        cobj->clearTrack(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_clearTrack)

static bool js_cocos2dx_spine_SkeletonAnimation_setInterruptListener(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_setInterruptListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void (spine::TrackEntry *)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](spine::TrackEntry* larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)larg0, &args[0]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setInterruptListener : Error processing arguments");
        cobj->setInterruptListener(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setInterruptListener)

static bool js_cocos2dx_spine_SkeletonAnimation_addAnimation(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_addAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        int arg0 = 0;
        std::string arg1;
        bool arg2;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        ok &= seval_to_boolean(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_addAnimation : Error processing arguments");
        spine::TrackEntry* result = cobj->addAnimation(arg0, arg1, arg2);
        ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_addAnimation : Error processing arguments");
        return true;
    }
    if (argc == 4) {
        int arg0 = 0;
        std::string arg1;
        bool arg2;
        float arg3 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        ok &= seval_to_boolean(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_addAnimation : Error processing arguments");
        spine::TrackEntry* result = cobj->addAnimation(arg0, arg1, arg2, arg3);
        ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_addAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_addAnimation)

static bool js_cocos2dx_spine_SkeletonAnimation_setEmptyAnimations(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_setEmptyAnimations : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setEmptyAnimations : Error processing arguments");
        cobj->setEmptyAnimations(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setEmptyAnimations)

static bool js_cocos2dx_spine_SkeletonAnimation_clearTracks(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_clearTracks : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->clearTracks();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_clearTracks)

static bool js_cocos2dx_spine_SkeletonAnimation_setTrackEndListener(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackEndListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        spine::TrackEntry* arg0 = nullptr;
        std::function<void (spine::TrackEntry *)> arg1;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        do {
            if (args[1].isObject() && args[1].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[1]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](spine::TrackEntry* larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)larg0, &args[0]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                };
                arg1 = lambda;
            }
            else
            {
                arg1 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackEndListener : Error processing arguments");
        cobj->setTrackEndListener(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setTrackEndListener)

static bool js_cocos2dx_spine_SkeletonAnimation_setStartListener(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonAnimation_setStartListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void (spine::TrackEntry *)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](spine::TrackEntry* larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= native_ptr_to_rooted_seval<spine::TrackEntry>(inst, (spine::TrackEntry*)larg0, &args[0]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setStartListener : Error processing arguments");
        cobj->setStartListener(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setStartListener)

static bool js_cocos2dx_spine_SkeletonAnimation_createWithBinaryFile(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            spine::SkeletonAnimation* result = spine::SkeletonAnimation::createWithBinaryFile(arg0, arg1);
            ok &= native_ptr_to_seval<spine::SkeletonAnimation>(inst, (spine::SkeletonAnimation*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_createWithBinaryFile : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 3) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            spine::SkeletonAnimation* result = spine::SkeletonAnimation::createWithBinaryFile(arg0, arg1, arg2);
            ok &= native_ptr_to_seval<spine::SkeletonAnimation>(inst, (spine::SkeletonAnimation*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_createWithBinaryFile : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            spine::Atlas* arg1 = nullptr;
            ok &= seval_to_native_ptr(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            spine::SkeletonAnimation* result = spine::SkeletonAnimation::createWithBinaryFile(arg0, arg1);
            ok &= native_ptr_to_seval<spine::SkeletonAnimation>(inst, (spine::SkeletonAnimation*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_createWithBinaryFile : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 3) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            spine::Atlas* arg1 = nullptr;
            ok &= seval_to_native_ptr(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            spine::SkeletonAnimation* result = spine::SkeletonAnimation::createWithBinaryFile(arg0, arg1, arg2);
            ok &= native_ptr_to_seval<spine::SkeletonAnimation>(inst, (spine::SkeletonAnimation*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_createWithBinaryFile : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_createWithBinaryFile)

static bool js_cocos2dx_spine_SkeletonAnimation_create(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = spine::SkeletonAnimation::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(inst, __jsb_spine_SkeletonAnimation_class);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_create)

static bool js_cocos2dx_spine_SkeletonAnimation_createWithJsonFile(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            spine::SkeletonAnimation* result = spine::SkeletonAnimation::createWithJsonFile(arg0, arg1);
            ok &= native_ptr_to_seval<spine::SkeletonAnimation>(inst, (spine::SkeletonAnimation*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_createWithJsonFile : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 3) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            spine::SkeletonAnimation* result = spine::SkeletonAnimation::createWithJsonFile(arg0, arg1, arg2);
            ok &= native_ptr_to_seval<spine::SkeletonAnimation>(inst, (spine::SkeletonAnimation*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_createWithJsonFile : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            spine::Atlas* arg1 = nullptr;
            ok &= seval_to_native_ptr(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            spine::SkeletonAnimation* result = spine::SkeletonAnimation::createWithJsonFile(arg0, arg1);
            ok &= native_ptr_to_seval<spine::SkeletonAnimation>(inst, (spine::SkeletonAnimation*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_createWithJsonFile : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 3) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            spine::Atlas* arg1 = nullptr;
            ok &= seval_to_native_ptr(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(inst, args[2], &arg2);
            if (!ok) { ok = true; break; }
            spine::SkeletonAnimation* result = spine::SkeletonAnimation::createWithJsonFile(arg0, arg1, arg2);
            ok &= native_ptr_to_seval<spine::SkeletonAnimation>(inst, (spine::SkeletonAnimation*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_createWithJsonFile : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_createWithJsonFile)

static bool js_cocos2dx_spine_SkeletonAnimation_setGlobalTimeScale(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonAnimation_setGlobalTimeScale : Error processing arguments");
        spine::SkeletonAnimation::setGlobalTimeScale(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonAnimation_setGlobalTimeScale)

SE_DECLARE_FINALIZE_FUNC(js_spine_SkeletonAnimation_finalize)

static bool js_cocos2dx_spine_SkeletonAnimation_constructor(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = new (std::nothrow) spine::SkeletonAnimation();
    s.thisObject(inst)->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_spine_SkeletonAnimation_constructor, __jsb_spine_SkeletonAnimation_class, js_spine_SkeletonAnimation_finalize)

static bool js_cocos2dx_spine_SkeletonAnimation_ctor(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonAnimation* cobj = new (std::nothrow) spine::SkeletonAnimation();
    s.thisObject(inst)->setPrivateData(cobj);
    return true;
}
SE_BIND_SUB_CLS_CTOR(js_cocos2dx_spine_SkeletonAnimation_ctor, __jsb_spine_SkeletonAnimation_class, js_spine_SkeletonAnimation_finalize)


    

extern se::Object* __jsb_spine_SkeletonRenderer_proto;

static bool js_spine_SkeletonAnimation_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (spine::SkeletonAnimation)", s.nativeThisObject());
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_spine_SkeletonAnimation_finalize)

bool js_register_cocos2dx_spine_SkeletonAnimation(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "SkeletonAnimation", obj, __jsb_spine_SkeletonRenderer_proto, _SE(js_cocos2dx_spine_SkeletonAnimation_constructor));

    cls->defineFunction(inst, "setAnimation", _SE(js_cocos2dx_spine_SkeletonAnimation_setAnimation));
    cls->defineFunction(inst, "findAnimation", _SE(js_cocos2dx_spine_SkeletonAnimation_findAnimation));
    cls->defineFunction(inst, "setTrackEventListener", _SE(js_cocos2dx_spine_SkeletonAnimation_setTrackEventListener));
    cls->defineFunction(inst, "setMix", _SE(js_cocos2dx_spine_SkeletonAnimation_setMix));
    cls->defineFunction(inst, "setTrackStartListener", _SE(js_cocos2dx_spine_SkeletonAnimation_setTrackStartListener));
    cls->defineFunction(inst, "addEmptyAnimation", _SE(js_cocos2dx_spine_SkeletonAnimation_addEmptyAnimation));
    cls->defineFunction(inst, "setDisposeListener", _SE(js_cocos2dx_spine_SkeletonAnimation_setDisposeListener));
    cls->defineFunction(inst, "setTrackInterruptListener", _SE(js_cocos2dx_spine_SkeletonAnimation_setTrackInterruptListener));
    cls->defineFunction(inst, "setTrackCompleteListenerNative", _SE(js_cocos2dx_spine_SkeletonAnimation_setTrackCompleteListener));
    cls->defineFunction(inst, "setAnimationStateData", _SE(js_cocos2dx_spine_SkeletonAnimation_setAnimationStateData));
    cls->defineFunction(inst, "setEndListener", _SE(js_cocos2dx_spine_SkeletonAnimation_setEndListener));
    cls->defineFunction(inst, "getState", _SE(js_cocos2dx_spine_SkeletonAnimation_getState));
    cls->defineFunction(inst, "setCompleteListenerNative", _SE(js_cocos2dx_spine_SkeletonAnimation_setCompleteListener));
    cls->defineFunction(inst, "setTrackDisposeListener", _SE(js_cocos2dx_spine_SkeletonAnimation_setTrackDisposeListener));
    cls->defineFunction(inst, "getCurrent", _SE(js_cocos2dx_spine_SkeletonAnimation_getCurrent));
    cls->defineFunction(inst, "setEventListener", _SE(js_cocos2dx_spine_SkeletonAnimation_setEventListener));
    cls->defineFunction(inst, "setEmptyAnimation", _SE(js_cocos2dx_spine_SkeletonAnimation_setEmptyAnimation));
    cls->defineFunction(inst, "clearTrack", _SE(js_cocos2dx_spine_SkeletonAnimation_clearTrack));
    cls->defineFunction(inst, "setInterruptListener", _SE(js_cocos2dx_spine_SkeletonAnimation_setInterruptListener));
    cls->defineFunction(inst, "addAnimation", _SE(js_cocos2dx_spine_SkeletonAnimation_addAnimation));
    cls->defineFunction(inst, "setEmptyAnimations", _SE(js_cocos2dx_spine_SkeletonAnimation_setEmptyAnimations));
    cls->defineFunction(inst, "clearTracks", _SE(js_cocos2dx_spine_SkeletonAnimation_clearTracks));
    cls->defineFunction(inst, "setTrackEndListener", _SE(js_cocos2dx_spine_SkeletonAnimation_setTrackEndListener));
    cls->defineFunction(inst, "setStartListener", _SE(js_cocos2dx_spine_SkeletonAnimation_setStartListener));
    cls->defineFunction(inst, "ctor", _SE(js_cocos2dx_spine_SkeletonAnimation_ctor));
    cls->defineStaticFunction(inst, "createWithBinaryFile", _SE(js_cocos2dx_spine_SkeletonAnimation_createWithBinaryFile));
    cls->defineStaticFunction(inst, "create", _SE(js_cocos2dx_spine_SkeletonAnimation_create));
    cls->defineStaticFunction(inst, "createWithJsonFile", _SE(js_cocos2dx_spine_SkeletonAnimation_createWithJsonFile));
    cls->defineStaticFunction(inst, "setGlobalTimeScale", _SE(js_cocos2dx_spine_SkeletonAnimation_setGlobalTimeScale));
    cls->defineFinalizeFunction(_SE(js_spine_SkeletonAnimation_finalize));
    cls->install(inst);
    inst->registerClass<spine::SkeletonAnimation>(cls);

    __jsb_spine_SkeletonAnimation_proto = cls->getProto();
    __jsb_spine_SkeletonAnimation_class = cls;

    jsb_set_extend_property(inst, "spine", "SkeletonAnimation");
    inst->clearException();
    return true;
}

se::Object* __jsb_spine_SkeletonDataMgr_proto = nullptr;
se::Class* __jsb_spine_SkeletonDataMgr_class = nullptr;

static bool js_cocos2dx_spine_SkeletonDataMgr_setDestroyCallback(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonDataMgr* cobj = (spine::SkeletonDataMgr*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonDataMgr_setDestroyCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void (int)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](int larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= int32_to_seval(inst, larg0, &args[0]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonDataMgr_setDestroyCallback : Error processing arguments");
        cobj->setDestroyCallback(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonDataMgr_setDestroyCallback)

static bool js_cocos2dx_spine_SkeletonDataMgr_getInstance(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::SkeletonDataMgr* result = spine::SkeletonDataMgr::getInstance();
        ok &= native_ptr_to_seval<spine::SkeletonDataMgr>(inst, (spine::SkeletonDataMgr*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonDataMgr_getInstance : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonDataMgr_getInstance)

SE_DECLARE_FINALIZE_FUNC(js_spine_SkeletonDataMgr_finalize)

static bool js_cocos2dx_spine_SkeletonDataMgr_constructor(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonDataMgr* cobj = new (std::nothrow) spine::SkeletonDataMgr();
    s.thisObject(inst)->setPrivateData(cobj);
    inst->getNoneRefNativePtrMap().emplace(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_spine_SkeletonDataMgr_constructor, __jsb_spine_SkeletonDataMgr_class, js_spine_SkeletonDataMgr_finalize)




static bool js_spine_SkeletonDataMgr_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (spine::SkeletonDataMgr)", s.nativeThisObject());
    auto iter = inst->getNoneRefNativePtrMap().find(s.nativeThisObject());
    if (iter != inst->getNoneRefNativePtrMap().end())
    {
        inst->getNoneRefNativePtrMap().erase(iter);
        spine::SkeletonDataMgr* cobj = (spine::SkeletonDataMgr*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_spine_SkeletonDataMgr_finalize)

bool js_register_cocos2dx_spine_SkeletonDataMgr(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "SkeletonDataMgr", obj, nullptr, _SE(js_cocos2dx_spine_SkeletonDataMgr_constructor));

    cls->defineFunction(inst, "setDestroyCallback", _SE(js_cocos2dx_spine_SkeletonDataMgr_setDestroyCallback));
    cls->defineStaticFunction(inst, "getInstance", _SE(js_cocos2dx_spine_SkeletonDataMgr_getInstance));
    cls->defineFinalizeFunction(_SE(js_spine_SkeletonDataMgr_finalize));
    cls->install(inst);
    inst->registerClass<spine::SkeletonDataMgr>(cls);

    __jsb_spine_SkeletonDataMgr_proto = cls->getProto();
    __jsb_spine_SkeletonDataMgr_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_SkeletonCacheMgr_proto = nullptr;
se::Class* __jsb_spine_SkeletonCacheMgr_class = nullptr;

static bool js_cocos2dx_spine_SkeletonCacheMgr_removeSkeletonCache(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheMgr* cobj = (spine::SkeletonCacheMgr*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheMgr_removeSkeletonCache : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheMgr_removeSkeletonCache : Error processing arguments");
        cobj->removeSkeletonCache(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheMgr_removeSkeletonCache)

static bool js_cocos2dx_spine_SkeletonCacheMgr_buildSkeletonCache(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheMgr* cobj = (spine::SkeletonCacheMgr*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheMgr_buildSkeletonCache : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheMgr_buildSkeletonCache : Error processing arguments");
        spine::SkeletonCache* result = cobj->buildSkeletonCache(arg0);
        ok &= native_ptr_to_seval<spine::SkeletonCache>(inst, (spine::SkeletonCache*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheMgr_buildSkeletonCache : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheMgr_buildSkeletonCache)

static bool js_cocos2dx_spine_SkeletonCacheMgr_destroyInstance(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        spine::SkeletonCacheMgr::destroyInstance();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheMgr_destroyInstance)

static bool js_cocos2dx_spine_SkeletonCacheMgr_getInstance(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::SkeletonCacheMgr* result = spine::SkeletonCacheMgr::getInstance();
        ok &= native_ptr_to_seval<spine::SkeletonCacheMgr>(inst, (spine::SkeletonCacheMgr*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheMgr_getInstance : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheMgr_getInstance)



static bool js_spine_SkeletonCacheMgr_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (spine::SkeletonCacheMgr)", s.nativeThisObject());
    auto iter = inst->getNoneRefNativePtrMap().find(s.nativeThisObject());
    if (iter != inst->getNoneRefNativePtrMap().end())
    {
        inst->getNoneRefNativePtrMap().erase(iter);
        spine::SkeletonCacheMgr* cobj = (spine::SkeletonCacheMgr*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_spine_SkeletonCacheMgr_finalize)

bool js_register_cocos2dx_spine_SkeletonCacheMgr(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "SkeletonCacheMgr", obj, nullptr, nullptr);

    cls->defineFunction(inst, "removeSkeletonCache", _SE(js_cocos2dx_spine_SkeletonCacheMgr_removeSkeletonCache));
    cls->defineFunction(inst, "buildSkeletonCache", _SE(js_cocos2dx_spine_SkeletonCacheMgr_buildSkeletonCache));
    cls->defineStaticFunction(inst, "destroyInstance", _SE(js_cocos2dx_spine_SkeletonCacheMgr_destroyInstance));
    cls->defineStaticFunction(inst, "getInstance", _SE(js_cocos2dx_spine_SkeletonCacheMgr_getInstance));
    cls->defineFinalizeFunction(_SE(js_spine_SkeletonCacheMgr_finalize));
    cls->install(inst);
    inst->registerClass<spine::SkeletonCacheMgr>(cls);

    __jsb_spine_SkeletonCacheMgr_proto = cls->getProto();
    __jsb_spine_SkeletonCacheMgr_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_SkeletonCacheAnimation_proto = nullptr;
se::Class* __jsb_spine_SkeletonCacheAnimation_class = nullptr;

static bool js_cocos2dx_spine_SkeletonCacheAnimation_setUseTint(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setUseTint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setUseTint : Error processing arguments");
        cobj->setUseTint(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_setUseTint)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_setTimeScale(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setTimeScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setTimeScale : Error processing arguments");
        cobj->setTimeScale(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_setTimeScale)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_findAnimation(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_findAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_findAnimation : Error processing arguments");
        spine::Animation* result = cobj->findAnimation(arg0);
        ok &= native_ptr_to_rooted_seval<spine::Animation>(inst, (spine::Animation*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_findAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_findAnimation)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_setAttachUtil(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setAttachUtil : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        spine::CacheModeAttachUtil* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setAttachUtil : Error processing arguments");
        cobj->setAttachUtil(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_setAttachUtil)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_paused(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_paused : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_paused : Error processing arguments");
        cobj->paused(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_paused)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_setAttachment(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setAttachment : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            const char* arg1 = nullptr;
            std::string arg1_tmp; ok &= seval_to_std_string(inst, args[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { ok = true; break; }
            bool result = cobj->setAttachment(arg0, arg1);
            ok &= boolean_to_seval(inst, result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setAttachment : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            bool result = cobj->setAttachment(arg0, arg1);
            ok &= boolean_to_seval(inst, result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setAttachment : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_setAttachment)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_setAnimation(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_boolean(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setAnimation : Error processing arguments");
        cobj->setAnimation(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_setAnimation)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_setBonesToSetupPose(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setBonesToSetupPose : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->setBonesToSetupPose();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_setBonesToSetupPose)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_onEnable(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_onEnable : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->onEnable();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_onEnable)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_setStartListener(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setStartListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void (std::string)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](std::string larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= std_string_to_seval(inst, larg0, &args[0]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setStartListener : Error processing arguments");
        cobj->setStartListener(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_setStartListener)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_setEffect(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setEffect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::renderer::EffectVariant* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setEffect : Error processing arguments");
        cobj->setEffect(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_setEffect)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_isOpacityModifyRGB(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_isOpacityModifyRGB : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isOpacityModifyRGB();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_isOpacityModifyRGB : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_isOpacityModifyRGB)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_setToSetupPose(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setToSetupPose : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->setToSetupPose();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_setToSetupPose)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_setOpacityModifyRGB(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setOpacityModifyRGB : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setOpacityModifyRGB : Error processing arguments");
        cobj->setOpacityModifyRGB(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_setOpacityModifyRGB)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_setSlotsToSetupPose(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setSlotsToSetupPose : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->setSlotsToSetupPose();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_setSlotsToSetupPose)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_setEndListener(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setEndListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void (std::string)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](std::string larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= std_string_to_seval(inst, larg0, &args[0]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setEndListener : Error processing arguments");
        cobj->setEndListener(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_setEndListener)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_beginSchedule(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_beginSchedule : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->beginSchedule();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_beginSchedule)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_updateAllAnimationCache(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_updateAllAnimationCache : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->updateAllAnimationCache();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_updateAllAnimationCache)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_addAnimation(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_addAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_boolean(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_addAnimation : Error processing arguments");
        cobj->addAnimation(arg0, arg1);
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        bool arg1;
        float arg2 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_boolean(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_addAnimation : Error processing arguments");
        cobj->addAnimation(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_addAnimation)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_update(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_update : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_update : Error processing arguments");
        cobj->update(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_update)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_getAttachment(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_getAttachment : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_getAttachment : Error processing arguments");
        spine::Attachment* result = cobj->getAttachment(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<spine::Attachment>(inst, (spine::Attachment*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_getAttachment : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_getAttachment)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_setCompleteListener(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setCompleteListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void (std::string)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](std::string larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= std_string_to_seval(inst, larg0, &args[0]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setCompleteListener : Error processing arguments");
        cobj->setCompleteListener(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_setCompleteListener)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_updateAnimationCache(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_updateAnimationCache : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_updateAnimationCache : Error processing arguments");
        cobj->updateAnimationCache(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_updateAnimationCache)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_getTimeScale(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_getTimeScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTimeScale();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_getTimeScale : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_getTimeScale)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_findBone(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_findBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_findBone : Error processing arguments");
        spine::Bone* result = cobj->findBone(arg0);
        ok &= native_ptr_to_rooted_seval<spine::Bone>(inst, (spine::Bone*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_findBone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_findBone)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_onDisable(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_onDisable : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->onDisable();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_onDisable)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_setColor(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Color4B arg0;
        ok &= seval_to_Color4B(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setColor : Error processing arguments");
        cobj->setColor(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_setColor)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_bindNodeProxy(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_bindNodeProxy : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::renderer::NodeProxy* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_bindNodeProxy : Error processing arguments");
        cobj->bindNodeProxy(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_bindNodeProxy)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_setBatchEnabled(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setBatchEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setBatchEnabled : Error processing arguments");
        cobj->setBatchEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_setBatchEnabled)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_setSkin(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_setSkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= seval_to_std_string(inst, args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            cobj->setSkin(arg0);
            return true;
        }
    } while(false);

    do {
        if (argc == 1) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            cobj->setSkin(arg0);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_setSkin)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_findSlot(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_findSlot : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_findSlot : Error processing arguments");
        spine::Slot* result = cobj->findSlot(arg0);
        ok &= native_ptr_to_rooted_seval<spine::Slot>(inst, (spine::Slot*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_findSlot : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_findSlot)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_getSkeleton(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_getSkeleton : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        spine::Skeleton* result = cobj->getSkeleton();
        ok &= native_ptr_to_rooted_seval<spine::Skeleton>(inst, (spine::Skeleton*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_getSkeleton : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_getSkeleton)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_stopSchedule(se::State &s, se::ScriptEngine *inst)
{
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_SkeletonCacheAnimation_stopSchedule : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->stopSchedule();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_SkeletonCacheAnimation_stopSchedule)

SE_DECLARE_FINALIZE_FUNC(js_spine_SkeletonCacheAnimation_finalize)

static bool js_cocos2dx_spine_SkeletonCacheAnimation_constructor(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    std::string arg0;
    bool arg1;
    ok &= seval_to_std_string(inst, args[0], &arg0);
    ok &= seval_to_boolean(inst, args[1], &arg1);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_SkeletonCacheAnimation_constructor : Error processing arguments");
    spine::SkeletonCacheAnimation* cobj = new (std::nothrow) spine::SkeletonCacheAnimation(arg0, arg1);
    s.thisObject(inst)->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_spine_SkeletonCacheAnimation_constructor, __jsb_spine_SkeletonCacheAnimation_class, js_spine_SkeletonCacheAnimation_finalize)




static bool js_spine_SkeletonCacheAnimation_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (spine::SkeletonCacheAnimation)", s.nativeThisObject());
    spine::SkeletonCacheAnimation* cobj = (spine::SkeletonCacheAnimation*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_spine_SkeletonCacheAnimation_finalize)

bool js_register_cocos2dx_spine_SkeletonCacheAnimation(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "SkeletonCacheAnimation", obj, nullptr, _SE(js_cocos2dx_spine_SkeletonCacheAnimation_constructor));

    cls->defineFunction(inst, "setUseTint", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_setUseTint));
    cls->defineFunction(inst, "setTimeScale", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_setTimeScale));
    cls->defineFunction(inst, "findAnimation", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_findAnimation));
    cls->defineFunction(inst, "setAttachUtil", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_setAttachUtil));
    cls->defineFunction(inst, "paused", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_paused));
    cls->defineFunction(inst, "setAttachment", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_setAttachment));
    cls->defineFunction(inst, "setAnimation", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_setAnimation));
    cls->defineFunction(inst, "setBonesToSetupPose", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_setBonesToSetupPose));
    cls->defineFunction(inst, "onEnable", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_onEnable));
    cls->defineFunction(inst, "setStartListener", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_setStartListener));
    cls->defineFunction(inst, "setEffect", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_setEffect));
    cls->defineFunction(inst, "isOpacityModifyRGB", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_isOpacityModifyRGB));
    cls->defineFunction(inst, "setToSetupPose", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_setToSetupPose));
    cls->defineFunction(inst, "setOpacityModifyRGB", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_setOpacityModifyRGB));
    cls->defineFunction(inst, "setSlotsToSetupPose", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_setSlotsToSetupPose));
    cls->defineFunction(inst, "setEndListener", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_setEndListener));
    cls->defineFunction(inst, "beginSchedule", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_beginSchedule));
    cls->defineFunction(inst, "updateAllAnimationCache", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_updateAllAnimationCache));
    cls->defineFunction(inst, "addAnimation", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_addAnimation));
    cls->defineFunction(inst, "update", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_update));
    cls->defineFunction(inst, "getAttachment", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_getAttachment));
    cls->defineFunction(inst, "setCompleteListener", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_setCompleteListener));
    cls->defineFunction(inst, "updateAnimationCache", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_updateAnimationCache));
    cls->defineFunction(inst, "getTimeScale", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_getTimeScale));
    cls->defineFunction(inst, "findBone", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_findBone));
    cls->defineFunction(inst, "onDisable", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_onDisable));
    cls->defineFunction(inst, "setColor", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_setColor));
    cls->defineFunction(inst, "bindNodeProxy", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_bindNodeProxy));
    cls->defineFunction(inst, "setBatchEnabled", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_setBatchEnabled));
    cls->defineFunction(inst, "setSkin", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_setSkin));
    cls->defineFunction(inst, "findSlot", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_findSlot));
    cls->defineFunction(inst, "getSkeleton", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_getSkeleton));
    cls->defineFunction(inst, "stopSchedule", _SE(js_cocos2dx_spine_SkeletonCacheAnimation_stopSchedule));
    cls->defineFinalizeFunction(_SE(js_spine_SkeletonCacheAnimation_finalize));
    cls->install(inst);
    inst->registerClass<spine::SkeletonCacheAnimation>(cls);

    __jsb_spine_SkeletonCacheAnimation_proto = cls->getProto();
    __jsb_spine_SkeletonCacheAnimation_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_AttachUtilBase_proto = nullptr;
se::Class* __jsb_spine_AttachUtilBase_class = nullptr;

static bool js_cocos2dx_spine_AttachUtilBase_associateAttachedNode(se::State &s, se::ScriptEngine *inst)
{
    spine::AttachUtilBase* cobj = (spine::AttachUtilBase*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_spine_AttachUtilBase_associateAttachedNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        spine::Skeleton* arg0 = nullptr;
        cocos2d::renderer::NodeProxy* arg1 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_spine_AttachUtilBase_associateAttachedNode : Error processing arguments");
        cobj->associateAttachedNode(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_spine_AttachUtilBase_associateAttachedNode)




bool js_register_cocos2dx_spine_AttachUtilBase(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "AttachUtilBase", obj, nullptr, nullptr);

    cls->defineFunction(inst, "associateAttachedNode", _SE(js_cocos2dx_spine_AttachUtilBase_associateAttachedNode));
    cls->install(inst);
    inst->registerClass<spine::AttachUtilBase>(cls);

    __jsb_spine_AttachUtilBase_proto = cls->getProto();
    __jsb_spine_AttachUtilBase_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_RealTimeAttachUtil_proto = nullptr;
se::Class* __jsb_spine_RealTimeAttachUtil_class = nullptr;

SE_DECLARE_FINALIZE_FUNC(js_spine_RealTimeAttachUtil_finalize)

static bool js_cocos2dx_spine_RealTimeAttachUtil_constructor(se::State &s, se::ScriptEngine *inst)
{
    spine::RealTimeAttachUtil* cobj = new (std::nothrow) spine::RealTimeAttachUtil();
    s.thisObject(inst)->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_spine_RealTimeAttachUtil_constructor, __jsb_spine_RealTimeAttachUtil_class, js_spine_RealTimeAttachUtil_finalize)



extern se::Object* __jsb_spine_AttachUtilBase_proto;

static bool js_spine_RealTimeAttachUtil_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (spine::RealTimeAttachUtil)", s.nativeThisObject());
    spine::RealTimeAttachUtil* cobj = (spine::RealTimeAttachUtil*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_spine_RealTimeAttachUtil_finalize)

bool js_register_cocos2dx_spine_RealTimeAttachUtil(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "RealTimeAttachUtil", obj, __jsb_spine_AttachUtilBase_proto, _SE(js_cocos2dx_spine_RealTimeAttachUtil_constructor));

    cls->defineFinalizeFunction(_SE(js_spine_RealTimeAttachUtil_finalize));
    cls->install(inst);
    inst->registerClass<spine::RealTimeAttachUtil>(cls);

    __jsb_spine_RealTimeAttachUtil_proto = cls->getProto();
    __jsb_spine_RealTimeAttachUtil_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_spine_CacheModeAttachUtil_proto = nullptr;
se::Class* __jsb_spine_CacheModeAttachUtil_class = nullptr;

SE_DECLARE_FINALIZE_FUNC(js_spine_CacheModeAttachUtil_finalize)

static bool js_cocos2dx_spine_CacheModeAttachUtil_constructor(se::State &s, se::ScriptEngine *inst)
{
    spine::CacheModeAttachUtil* cobj = new (std::nothrow) spine::CacheModeAttachUtil();
    s.thisObject(inst)->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_spine_CacheModeAttachUtil_constructor, __jsb_spine_CacheModeAttachUtil_class, js_spine_CacheModeAttachUtil_finalize)



extern se::Object* __jsb_spine_AttachUtilBase_proto;

static bool js_spine_CacheModeAttachUtil_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (spine::CacheModeAttachUtil)", s.nativeThisObject());
    spine::CacheModeAttachUtil* cobj = (spine::CacheModeAttachUtil*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_spine_CacheModeAttachUtil_finalize)

bool js_register_cocos2dx_spine_CacheModeAttachUtil(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "CacheModeAttachUtil", obj, __jsb_spine_AttachUtilBase_proto, _SE(js_cocos2dx_spine_CacheModeAttachUtil_constructor));

    cls->defineFinalizeFunction(_SE(js_spine_CacheModeAttachUtil_finalize));
    cls->install(inst);
    inst->registerClass<spine::CacheModeAttachUtil>(cls);

    __jsb_spine_CacheModeAttachUtil_proto = cls->getProto();
    __jsb_spine_CacheModeAttachUtil_class = cls;

    inst->clearException();
    return true;
}

bool register_all_cocos2dx_spine(se::ScriptEngine *inst, se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("spine", &nsVal))
    {
        se::HandleObject jsobj(se::Object::createPlainObject(inst));
        nsVal.setObject(jsobj);
        obj->setProperty("spine", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_cocos2dx_spine_Slot(inst, ns);
    js_register_cocos2dx_spine_AttachUtilBase(inst, ns);
    js_register_cocos2dx_spine_RealTimeAttachUtil(inst, ns);
    js_register_cocos2dx_spine_ConstraintData(inst, ns);
    js_register_cocos2dx_spine_Polygon(inst, ns);
    js_register_cocos2dx_spine_SkeletonCacheAnimation(inst, ns);
    js_register_cocos2dx_spine_Attachment(inst, ns);
    js_register_cocos2dx_spine_VertexAttachment(inst, ns);
    js_register_cocos2dx_spine_SkeletonDataMgr(inst, ns);
    js_register_cocos2dx_spine_VertexEffect(inst, ns);
    js_register_cocos2dx_spine_JitterVertexEffect(inst, ns);
    js_register_cocos2dx_spine_SkeletonCacheMgr(inst, ns);
    js_register_cocos2dx_spine_Timeline(inst, ns);
    js_register_cocos2dx_spine_CurveTimeline(inst, ns);
    js_register_cocos2dx_spine_IkConstraintTimeline(inst, ns);
    js_register_cocos2dx_spine_SkeletonRenderer(inst, ns);
    js_register_cocos2dx_spine_Animation(inst, ns);
    js_register_cocos2dx_spine_MeshAttachment(inst, ns);
    js_register_cocos2dx_spine_TranslateTimeline(inst, ns);
    js_register_cocos2dx_spine_ShearTimeline(inst, ns);
    js_register_cocos2dx_spine_AttachmentTimeline(inst, ns);
    js_register_cocos2dx_spine_PathConstraintMixTimeline(inst, ns);
    js_register_cocos2dx_spine_PathConstraintPositionTimeline(inst, ns);
    js_register_cocos2dx_spine_PathConstraintSpacingTimeline(inst, ns);
    js_register_cocos2dx_spine_SkeletonAnimation(inst, ns);
    js_register_cocos2dx_spine_IkConstraintData(inst, ns);
    js_register_cocos2dx_spine_SwirlVertexEffect(inst, ns);
    js_register_cocos2dx_spine_AnimationStateData(inst, ns);
    js_register_cocos2dx_spine_PointAttachment(inst, ns);
    js_register_cocos2dx_spine_AnimationState(inst, ns);
    js_register_cocos2dx_spine_TrackEntry(inst, ns);
    js_register_cocos2dx_spine_BoneData(inst, ns);
    js_register_cocos2dx_spine_ScaleTimeline(inst, ns);
    js_register_cocos2dx_spine_SkeletonData(inst, ns);
    js_register_cocos2dx_spine_PathAttachment(inst, ns);
    js_register_cocos2dx_spine_TransformConstraint(inst, ns);
    js_register_cocos2dx_spine_BoundingBoxAttachment(inst, ns);
    js_register_cocos2dx_spine_ClippingAttachment(inst, ns);
    js_register_cocos2dx_spine_DeformTimeline(inst, ns);
    js_register_cocos2dx_spine_SkeletonBounds(inst, ns);
    js_register_cocos2dx_spine_TransformConstraintData(inst, ns);
    js_register_cocos2dx_spine_ColorTimeline(inst, ns);
    js_register_cocos2dx_spine_PathConstraint(inst, ns);
    js_register_cocos2dx_spine_TransformConstraintTimeline(inst, ns);
    js_register_cocos2dx_spine_Bone(inst, ns);
    js_register_cocos2dx_spine_EventTimeline(inst, ns);
    js_register_cocos2dx_spine_Skeleton(inst, ns);
    js_register_cocos2dx_spine_TwoColorTimeline(inst, ns);
    js_register_cocos2dx_spine_Color(inst, ns);
    js_register_cocos2dx_spine_DrawOrderTimeline(inst, ns);
    js_register_cocos2dx_spine_RegionAttachment(inst, ns);
    js_register_cocos2dx_spine_IkConstraint(inst, ns);
    js_register_cocos2dx_spine_RotateTimeline(inst, ns);
    js_register_cocos2dx_spine_SlotData(inst, ns);
    js_register_cocos2dx_spine_CacheModeAttachUtil(inst, ns);
    js_register_cocos2dx_spine_Skin(inst, ns);
    js_register_cocos2dx_spine_VertexEffectDelegate(inst, ns);
    js_register_cocos2dx_spine_EventData(inst, ns);
    js_register_cocos2dx_spine_Event(inst, ns);
    js_register_cocos2dx_spine_PathConstraintData(inst, ns);
    return true;
}

#endif //#if USE_SPINE > 0
