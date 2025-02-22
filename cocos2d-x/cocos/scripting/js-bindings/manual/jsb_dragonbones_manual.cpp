/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated engine source code (the "Software"), a limited,
 worldwide, royalty-free, non-assignable, revocable and non-exclusive license
 to use Cocos Creator solely to develop games on your target platforms. You shall
 not use Cocos Creator software for developing other software or tools that's
 used for developing games. You are not granted to publish, distribute,
 sublicense, and/or sell copies of Cocos Creator.

 The software or tools in this License Agreement are licensed, not sold.
 Xiamen Yaji Software Co., Ltd. reserves all rights not expressly granted to you.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "jsb_dragonbones_manual.hpp"
#include "base/ccConfig.h"

#if USE_DRAGONBONES > 0

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"
#include "cocos/scripting/js-bindings/manual/jsb_conversions.hpp"
#include "cocos/scripting/js-bindings/manual/jsb_global.h"
#include "cocos/scripting/js-bindings/manual/jsb_helper.hpp"
#include "cocos/scripting/js-bindings/auto/jsb_cocos2dx_dragonbones_auto.hpp"
#include "cocos/editor-support/dragonbones-creator-support/CCDragonBonesHeaders.h"
#include "cocos/scripting/js-bindings/auto/jsb_cocos2dx_editor_support_auto.hpp"

#include "cocos/platform/CCApplication.h"

#include "cocos2d.h"

using namespace cocos2d;

// add by fins
static bool js_cocos2dx_dragonbones_Slot_get_globalTransformMatrix(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot *cobj = (dragonBones::Slot *)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_get_globalTransformMatrix : Invalid Native Object");
    const auto &args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0)
    {
        dragonBones::Matrix *result = cobj->getGlobalTransformMatrix();
        ok &= native_ptr_to_rooted_seval<dragonBones::Matrix>(inst, (dragonBones::Matrix *)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_get_globalTransformMatrix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Slot_get_globalTransformMatrix)

// add by fins
static bool js_cocos2dx_dragonbones_Animation_get_animations(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation *cobj = (dragonBones::Animation *)s.nativeThisObject();
    se::HandleObject retObj(se::Object::createPlainObject(inst));
    bool ok = false;
    se::Value tmp;
    for (const auto &e : cobj->getAnimations())
    {
        if (!e.first.empty())
        {
            ok = native_ptr_to_rooted_seval<dragonBones::AnimationData>(inst, e.second, __jsb_dragonBones_AnimationData_class, &tmp);
            SE_PRECONDITION2(ok, false, "Convert dragonBones::AnimationData to se::Value failed!");
            retObj->setProperty(e.first.c_str(), tmp);
        }
    }
    s.rval().setObject(retObj);
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Animation_get_animations)

static bool js_cocos2dx_dragonbones_Armature_getDisplay(se::State& s, se::ScriptEngine *inst)
{
    if (s.args().size() == 0)
    {
        dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
        dragonBones::CCArmatureDisplay* ret = (dragonBones::CCArmatureDisplay*)(cobj->getDisplay());
        if (ret != nullptr)
        {
            bool ok = native_ptr_to_seval<dragonBones::CCArmatureDisplay>(inst, ret, __jsb_dragonBones_CCArmatureDisplay_class, &s.rval());
            SE_PRECONDITION2(ok, false, "Convert dragonBones::Animation to se::Value failed!");
        }
        else
        {
            s.rval().setNull();
        }
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)s.args().size(), 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getDisplay)

static bool js_cocos2dx_dragonbones_Armature_getSlots(se::State& s, se::ScriptEngine *inst)
{
	dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
	const auto& result = cobj->getSlots();
	se::HandleObject arr(se::Object::createArrayObject(inst, result.size()));

	uint32_t i = 0;
	se::Value tmp;
	bool ok = true;
	for (const auto& slot : result)
	{
		if (!native_ptr_to_rooted_seval<dragonBones::Slot>(inst, slot, &tmp))
		{
			ok = false;
			break;
		}
		arr->setArrayElement(i, tmp);
		++i;
	}
	if (ok)
		s.rval().setObject(arr);

	SE_PRECONDITION2(ok, false, "Convert getSlots to se::Value failed!");
	return true;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getSlots)

static bool js_cocos2dx_dragonbones_Armature_getBones(se::State& s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    const auto& result = cobj->getBones();
    se::HandleObject arr(se::Object::createArrayObject(inst, result.size()));

    uint32_t i = 0;
    se::Value tmp;
    bool ok = true;
    for (const auto& bone : result)
    {
        if (!native_ptr_to_rooted_seval<dragonBones::Bone>(inst, bone, &tmp))
        {
            ok = false;
            break;
        }
        arr->setArrayElement(i, tmp);
        ++i;
    }
    if (ok)
        s.rval().setObject(arr);

    SE_PRECONDITION2(ok, false, "Convert getBones to se::Value failed!");
    return true;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getBones)

static bool js_cocos2dx_dragonbones_Armature_getBoneByDisplay(se::State& s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_getBoneByDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::CCArmatureDisplay* display = nullptr;
        ok = seval_to_native_ptr(inst, args[0], &display);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getBoneByDisplay : Error processing arguments");
        dragonBones::Bone* result = cobj->getBoneByDisplay(display);
        ok &= native_ptr_to_rooted_seval<dragonBones::Bone>(inst, (dragonBones::Bone*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getBoneByDisplay : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getBoneByDisplay)

static bool js_cocos2dx_dragonbones_Armature_getSlotByDisplay(se::State& s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_getSlotByDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::CCArmatureDisplay* display = nullptr;
        ok = seval_to_native_ptr(inst, args[0], &display);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getSlotByDisplay : Error processing arguments");
        dragonBones::Slot* result = cobj->getSlotByDisplay(display);
        ok &= native_ptr_to_rooted_seval<dragonBones::Slot>(inst, (dragonBones::Slot*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getSlotByDisplay : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getSlotByDisplay)

static bool js_cocos2dx_dragonbones_Armature_setReplacedTexture(se::State& s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_setReplacedTexture : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        middleware::Texture2D* texture = nullptr;
        ok = seval_to_native_ptr(inst, args[0], &texture);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_setReplacedTexture : Error processing arguments");
        cobj->setReplacedTexture(texture);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_setReplacedTexture)

static bool js_cocos2dx_dragonbones_Armature_getReplacedTexture(se::State& s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_getReplacedTexture : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        middleware::Texture2D* result = (middleware::Texture2D*)cobj->getReplacedTexture();
        ok = native_ptr_to_seval<middleware::Texture2D>(inst, result, __jsb_cocos2d_middleware_Texture2D_class, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getReplacedTexture : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getReplacedTexture)

static bool js_cocos2dx_dragonbones_ArmatureData_get_animations(se::State& s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    se::HandleObject retObj(se::Object::createPlainObject(inst));
    bool ok = false;
    se::Value tmp;
    for (const auto& e : cobj->animations)
    {
        if (!e.first.empty())
        {
            ok = native_ptr_to_rooted_seval<dragonBones::AnimationData>(inst, e.second, __jsb_dragonBones_AnimationData_class, &tmp);
            SE_PRECONDITION2(ok, false, "Convert dragonBones::AnimationData to se::Value failed!");
            retObj->setProperty(e.first.c_str(), tmp);
        }
    }
    s.rval().setObject(retObj);
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_ArmatureData_get_animations)

static bool js_cocos2dx_dragonbones_ArmatureData_get_bones(se::State& s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    se::HandleObject retObj(se::Object::createPlainObject(inst));
    bool ok = false;
    se::Value tmp;
    for (const auto& e : cobj->bones)
    {
        if (!e.first.empty())
        {
            ok = native_ptr_to_rooted_seval<dragonBones::BoneData>(inst, e.second, __jsb_dragonBones_BoneData_class, &tmp);
            SE_PRECONDITION2(ok, false, "Convert dragonBones::AnimationData to se::Value failed!");
            retObj->setProperty(e.first.c_str(), tmp);
        }
    }
    s.rval().setObject(retObj);
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_ArmatureData_get_bones)

static bool js_cocos2dx_dragonbones_ArmatureData_get_skins(se::State& s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    se::HandleObject retObj(se::Object::createPlainObject(inst));
    bool ok = false;
    se::Value tmp;
    for (const auto& e : cobj->skins)
    {
        if (!e.first.empty())
        {
            ok = native_ptr_to_rooted_seval<dragonBones::SkinData>(inst, e.second, __jsb_dragonBones_SkinData_class, &tmp);
            SE_PRECONDITION2(ok, false, "Convert dragonBones::AnimationData to se::Value failed!");
            retObj->setProperty(e.first.c_str(), tmp);
        }
    }
    s.rval().setObject(retObj);
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_ArmatureData_get_skins)

static bool js_cocos2dx_dragonbones_ArmatureData_get_slots(se::State& s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    se::HandleObject retObj(se::Object::createPlainObject(inst));
    bool ok = false;
    se::Value tmp;
    for (const auto& e : cobj->slots)
    {
        if (!e.first.empty())
        {
            ok = native_ptr_to_rooted_seval<dragonBones::SlotData>(inst, e.second, __jsb_dragonBones_SlotData_class, &tmp);
            SE_PRECONDITION2(ok, false, "Convert dragonBones::AnimationData to se::Value failed!");
            retObj->setProperty(e.first.c_str(), tmp);
        }
    }
    s.rval().setObject(retObj);
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_ArmatureData_get_slots)

static bool js_cocos2dx_dragonbones_DragonBonesData_get_armatureNames(se::State& s, se::ScriptEngine *inst)
{
    dragonBones::DragonBonesData* cobj = (dragonBones::DragonBonesData*)s.nativeThisObject();

    const auto& ret = cobj->getArmatureNames();
    bool ok = std_vector_string_to_seval(inst, ret, &s.rval());
    SE_PRECONDITION2(ok, false, "Convert ArmatureNames to se::Value failed!");
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_DragonBonesData_get_armatureNames)

static bool js_cocos2dx_dragonbones_Slot_getDisplay(se::State& s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot *)s.nativeThisObject();
    dragonBones::CCArmatureDisplay* ret = static_cast<dragonBones::CCArmatureDisplay*>(cobj->getDisplay());
    bool ok = native_ptr_to_seval<dragonBones::CCArmatureDisplay>(inst, ret, __jsb_dragonBones_CCArmatureDisplay_class, &s.rval());
    SE_PRECONDITION2(ok, false, "Convert dragonBones::DBCCSprite to se::Value failed!");
    return true;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_getDisplay)

static bool js_cocos2dx_dragonbones_Slot_set_displayIndex(se::State& s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_set_displayIndex : Invalid Native Object");

    CC_UNUSED bool ok = true;
    int32_t arg0;
    ok &= seval_to_int32(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_set_displayIndex : Error processing new value");
    cobj->setDisplayIndex(arg0);
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_Slot_set_displayIndex)

static bool js_cocos2dx_dragonbones_Slot_get_displayIndex(se::State& s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_get_displayIndex : Invalid Native Object");

    const int32_t ret = cobj->getDisplayIndex();
    bool ok = int32_to_seval(inst, ret, &s.rval());
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_get_displayIndex to se::Value failed!");
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Slot_get_displayIndex)

static bool js_cocos2dx_dragonbones_Slot_setDisplay(se::State& s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    int argc = (int)args.size();

    if (argc == 2)
    {
        dragonBones::Slot* cobj = (dragonBones::Slot *)s.nativeThisObject();
        dragonBones::CCArmatureDisplay* dbSprite = nullptr;
        bool ok = seval_to_native_ptr(inst, args[0], &dbSprite);
        SE_PRECONDITION2(ok, false, "Convert se::Value to dragonBones::DBCCSprite failed!");
        dragonBones::DisplayType type;
        ok = seval_to_int32(inst, args[1], (int32_t *)&type);
        SE_PRECONDITION2(ok, false, "Convert se::Value to dragonBones::DisplayType failed!");
        cobj->setDisplay(dbSprite, type);
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_setDisplay)

static bool js_cocos2dx_dragonbones_BaseFactory_parseTextureAtlasData(se::State& s, se::ScriptEngine *inst)
{
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BaseFactory_parseTextureAtlasData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const char* arg0 = nullptr;
        void* arg1 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(inst, args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_parseTextureAtlasData : Error processing arguments");
        dragonBones::TextureAtlasData* result = cobj->parseTextureAtlasData(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<dragonBones::TextureAtlasData>(inst, (dragonBones::TextureAtlasData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_parseTextureAtlasData : Error processing arguments");
        return true;
    }
    if (argc == 3) {
        const char* arg0 = nullptr;
        void* arg1 = nullptr;
        std::string arg2;
        std::string arg0_tmp; ok &= seval_to_std_string(inst, args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_parseTextureAtlasData : Error processing arguments");
        ok &= seval_to_std_string(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_parseTextureAtlasData : Error processing arguments");
        dragonBones::TextureAtlasData* result = cobj->parseTextureAtlasData(arg0, arg1, arg2);
        ok &= native_ptr_to_rooted_seval<dragonBones::TextureAtlasData>(inst, (dragonBones::TextureAtlasData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_parseTextureAtlasData : Error processing arguments");
        return true;
    }
    if (argc == 4) {
        const char* arg0 = nullptr;
        void* arg1 = nullptr;
        std::string arg2;
        float arg3 = 0;
        std::string arg0_tmp; ok &= seval_to_std_string(inst, args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_parseTextureAtlasData : Error processing arguments");
        ok &= seval_to_std_string(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_parseTextureAtlasData : Error processing arguments");
        dragonBones::TextureAtlasData* result = cobj->parseTextureAtlasData(arg0, arg1, arg2, arg3);
        ok &= native_ptr_to_rooted_seval<dragonBones::TextureAtlasData>(inst, (dragonBones::TextureAtlasData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_parseTextureAtlasData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseFactory_parseTextureAtlasData)

bool register_all_dragonbones_manual(se::ScriptEngine *inst, se::Object* obj)
{
    // add by fins
    __jsb_dragonBones_Slot_proto->defineProperty("globalTransformMatrix", _SE(js_cocos2dx_dragonbones_Slot_get_globalTransformMatrix), nullptr);
    // add by fins
    __jsb_dragonBones_Animation_proto->defineProperty("animations", _SE(js_cocos2dx_dragonbones_Animation_get_animations), nullptr);

    __jsb_dragonBones_Armature_proto->defineFunction("getDisplay", _SE(js_cocos2dx_dragonbones_Armature_getDisplay));
    __jsb_dragonBones_Armature_proto->defineFunction("getSlots", _SE(js_cocos2dx_dragonbones_Armature_getSlots));
    __jsb_dragonBones_Armature_proto->defineFunction("getBones", _SE(js_cocos2dx_dragonbones_Armature_getBones));
    __jsb_dragonBones_Armature_proto->defineFunction("getBoneByDisplay", _SE(js_cocos2dx_dragonbones_Armature_getBoneByDisplay));
    __jsb_dragonBones_Armature_proto->defineFunction("getSlotByDisplay", _SE(js_cocos2dx_dragonbones_Armature_getSlotByDisplay));
    __jsb_dragonBones_Armature_proto->defineFunction("setReplacedTexture", _SE(js_cocos2dx_dragonbones_Armature_setReplacedTexture));
    __jsb_dragonBones_Armature_proto->defineFunction("getReplacedTexture", _SE(js_cocos2dx_dragonbones_Armature_getReplacedTexture));

    __jsb_dragonBones_ArmatureData_proto->defineProperty("animations", _SE(js_cocos2dx_dragonbones_ArmatureData_get_animations), nullptr);
    __jsb_dragonBones_ArmatureData_proto->defineProperty("bones", _SE(js_cocos2dx_dragonbones_ArmatureData_get_bones), nullptr);
    __jsb_dragonBones_ArmatureData_proto->defineProperty("skins", _SE(js_cocos2dx_dragonbones_ArmatureData_get_skins), nullptr);
    __jsb_dragonBones_ArmatureData_proto->defineProperty("slots", _SE(js_cocos2dx_dragonbones_ArmatureData_get_slots), nullptr);

    __jsb_dragonBones_DragonBonesData_proto->defineProperty("armatureNames", _SE(js_cocos2dx_dragonbones_DragonBonesData_get_armatureNames), nullptr);

    __jsb_dragonBones_Slot_proto->defineProperty("displayIndex", _SE(js_cocos2dx_dragonbones_Slot_get_displayIndex), _SE(js_cocos2dx_dragonbones_Slot_set_displayIndex));
    __jsb_dragonBones_Slot_proto->defineFunction("getDisplay", _SE(js_cocos2dx_dragonbones_Slot_getDisplay));
    __jsb_dragonBones_Slot_proto->defineFunction("setDisplay", _SE(js_cocos2dx_dragonbones_Slot_setDisplay));

    __jsb_dragonBones_BaseFactory_proto->defineFunction("parseTextureAtlasData", _SE(js_cocos2dx_dragonbones_BaseFactory_parseTextureAtlasData));

    dragonBones::BaseObject::setObjectRecycleOrDestroyCallback([inst](dragonBones::BaseObject* obj, int type){

        std::string typeName = typeid(*obj).name();

        se::Object* seObj = nullptr;

        auto &ptrMap = inst->getNativePtrMap();
        auto iter = ptrMap.find(obj);
        if (iter != ptrMap.end())
        {
            // Save se::Object pointer for being used in cleanup method.
            seObj = iter->second;
            // Unmap native and js object since native object was destroyed.
            // Otherwise, it may trigger 'assertion' in se::Object::setPrivateData later
            // since native obj is already released and the new native object may be assigned with
            // the same address.
            ptrMap.erase(iter);
        }
        else
        {
            // CCLOG("Didn't find %s, %p in map", typeName, obj);
            // assert(false);
            return;
        }

        std::string typeNameStr = typeName;
        auto cleanup = [inst, seObj, typeNameStr](){

            if (!inst->isValid() || inst->isInCleanup())
                return;

            se::AutoHandleScope hs(inst);
            inst->clearException();

            // The mapping of native object & se::Object was cleared in above code.
            // The private data (native object) may be a different object associated with other se::Object.
            // Therefore, don't clear the mapping again.
            seObj->clearPrivateData(false);
            seObj->unroot();
            seObj->decRef();
        };

        if (!inst->isGarbageCollecting())
        {
            cleanup();
        }
        else
        {
            CleanupTask::pushTaskToAutoReleasePool(cleanup);
        }
    });

    cocos2d::Application::getInstance()->getScriptEngine()->addAfterCleanupHook([](){

        // If dragonBones has not init,then no need to cleanup.
        if (!dragonBones::CCFactory::isInit())
        {
            return;
        }

        dragonBones::DragonBones::checkInPool = false;

        auto factory = dragonBones::CCFactory::getFactory();
        factory->stopSchedule();

        // Copy the dragonbones object vector since vector element will be deleted in BaseObject destructor.
        std::vector<dragonBones::BaseObject*> allDragonBonesObjects = dragonBones::BaseObject::getAllObjects();
        SE_LOGD("Starting to cleanup dragonbones object, count: %d\n", (int)allDragonBonesObjects.size());
        for (auto dbObj : allDragonBonesObjects)
        {
            if (!dbObj->isInPool())
            {
                dbObj->returnToPool();
            }
        }

        dragonBones::BaseObject::clearPool(0);
        dragonBones::CCFactory::destroyFactory();

        dragonBones::DragonBones::checkInPool = true;

        // Don't need to use copy operator since we only print leak object below.
        auto& refAllDragonBonesObjects = dragonBones::BaseObject::getAllObjects();
        SE_LOGD("After cleanup, dragonbones object remained count: %d\n", (int)refAllDragonBonesObjects.size());

        // Print leak objects
        for (auto dbObj : refAllDragonBonesObjects)
        {
            SE_LOGD("Leak dragonbones object: %s, %p\n", typeid(*dbObj).name(), dbObj);
        }

        refAllDragonBonesObjects.clear();
    });

    inst->clearException();

    return true;
}

#endif
