#include "scripting/js-bindings/auto/jsb_cocos2dx_dragonbones_auto.hpp"
#if USE_DRAGONBONES > 0
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "editor-support/dragonbones-creator-support/CCDragonBonesHeaders.h"

se::Object* __jsb_dragonBones_BaseObject_proto = nullptr;
se::Class* __jsb_dragonBones_BaseObject_class = nullptr;

static bool js_cocos2dx_dragonbones_BaseObject_returnToPool(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BaseObject* cobj = (dragonBones::BaseObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BaseObject_returnToPool : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->returnToPool();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseObject_returnToPool)

static bool js_cocos2dx_dragonbones_BaseObject_clearPool(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::BaseObject::clearPool();
        return true;
    }
    if (argc == 1) {
        size_t arg0 = 0;
        ok &= seval_to_size(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseObject_clearPool : Error processing arguments");
        dragonBones::BaseObject::clearPool(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseObject_clearPool)

static bool js_cocos2dx_dragonbones_BaseObject_setMaxCount(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        size_t arg0 = 0;
        unsigned int arg1 = 0;
        ok &= seval_to_size(inst, args[0], &arg0);
        ok &= seval_to_uint32(inst, args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseObject_setMaxCount : Error processing arguments");
        dragonBones::BaseObject::setMaxCount(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseObject_setMaxCount)




bool js_register_cocos2dx_dragonbones_BaseObject(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "BaseObject", obj, nullptr, nullptr);

    cls->defineFunction(inst, "returnToPool", _SE(js_cocos2dx_dragonbones_BaseObject_returnToPool));
    cls->defineStaticFunction(inst, "clearPool", _SE(js_cocos2dx_dragonbones_BaseObject_clearPool));
    cls->defineStaticFunction(inst, "setMaxCount", _SE(js_cocos2dx_dragonbones_BaseObject_setMaxCount));
    cls->install(inst);
    inst->registerClass<dragonBones::BaseObject>(cls);

    __jsb_dragonBones_BaseObject_proto = cls->getProto();
    __jsb_dragonBones_BaseObject_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_Matrix_proto = nullptr;
se::Class* __jsb_dragonBones_Matrix_class = nullptr;

static bool js_cocos2dx_dragonbones_Matrix_get_a(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Matrix* cobj = (dragonBones::Matrix*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Matrix_get_a : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->a, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Matrix_get_a)

static bool js_cocos2dx_dragonbones_Matrix_set_a(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::Matrix* cobj = (dragonBones::Matrix*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Matrix_set_a : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Matrix_set_a : Error processing new value");
    cobj->a = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_Matrix_set_a)

static bool js_cocos2dx_dragonbones_Matrix_get_b(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Matrix* cobj = (dragonBones::Matrix*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Matrix_get_b : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->b, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Matrix_get_b)

static bool js_cocos2dx_dragonbones_Matrix_set_b(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::Matrix* cobj = (dragonBones::Matrix*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Matrix_set_b : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Matrix_set_b : Error processing new value");
    cobj->b = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_Matrix_set_b)

static bool js_cocos2dx_dragonbones_Matrix_get_c(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Matrix* cobj = (dragonBones::Matrix*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Matrix_get_c : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->c, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Matrix_get_c)

static bool js_cocos2dx_dragonbones_Matrix_set_c(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::Matrix* cobj = (dragonBones::Matrix*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Matrix_set_c : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Matrix_set_c : Error processing new value");
    cobj->c = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_Matrix_set_c)

static bool js_cocos2dx_dragonbones_Matrix_get_d(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Matrix* cobj = (dragonBones::Matrix*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Matrix_get_d : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->d, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Matrix_get_d)

static bool js_cocos2dx_dragonbones_Matrix_set_d(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::Matrix* cobj = (dragonBones::Matrix*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Matrix_set_d : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Matrix_set_d : Error processing new value");
    cobj->d = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_Matrix_set_d)

static bool js_cocos2dx_dragonbones_Matrix_get_tx(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Matrix* cobj = (dragonBones::Matrix*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Matrix_get_tx : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->tx, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Matrix_get_tx)

static bool js_cocos2dx_dragonbones_Matrix_set_tx(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::Matrix* cobj = (dragonBones::Matrix*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Matrix_set_tx : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Matrix_set_tx : Error processing new value");
    cobj->tx = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_Matrix_set_tx)

static bool js_cocos2dx_dragonbones_Matrix_get_ty(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Matrix* cobj = (dragonBones::Matrix*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Matrix_get_ty : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->ty, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Matrix_get_ty)

static bool js_cocos2dx_dragonbones_Matrix_set_ty(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::Matrix* cobj = (dragonBones::Matrix*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Matrix_set_ty : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Matrix_set_ty : Error processing new value");
    cobj->ty = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_Matrix_set_ty)




bool js_register_cocos2dx_dragonbones_Matrix(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Matrix", obj, nullptr, nullptr);

    cls->defineProperty(inst, "a", _SE(js_cocos2dx_dragonbones_Matrix_get_a), _SE(js_cocos2dx_dragonbones_Matrix_set_a));
    cls->defineProperty(inst, "b", _SE(js_cocos2dx_dragonbones_Matrix_get_b), _SE(js_cocos2dx_dragonbones_Matrix_set_b));
    cls->defineProperty(inst, "c", _SE(js_cocos2dx_dragonbones_Matrix_get_c), _SE(js_cocos2dx_dragonbones_Matrix_set_c));
    cls->defineProperty(inst, "d", _SE(js_cocos2dx_dragonbones_Matrix_get_d), _SE(js_cocos2dx_dragonbones_Matrix_set_d));
    cls->defineProperty(inst, "tx", _SE(js_cocos2dx_dragonbones_Matrix_get_tx), _SE(js_cocos2dx_dragonbones_Matrix_set_tx));
    cls->defineProperty(inst, "ty", _SE(js_cocos2dx_dragonbones_Matrix_get_ty), _SE(js_cocos2dx_dragonbones_Matrix_set_ty));
    cls->install(inst);
    inst->registerClass<dragonBones::Matrix>(cls);

    __jsb_dragonBones_Matrix_proto = cls->getProto();
    __jsb_dragonBones_Matrix_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_Transform_proto = nullptr;
se::Class* __jsb_dragonBones_Transform_class = nullptr;

static bool js_cocos2dx_dragonbones_Transform_normalizeRadian(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Transform_normalizeRadian : Error processing arguments");
        float result = dragonBones::Transform::normalizeRadian(arg0);
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Transform_normalizeRadian : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Transform_normalizeRadian)

static bool js_cocos2dx_dragonbones_Transform_get_x(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Transform* cobj = (dragonBones::Transform*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Transform_get_x : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->x, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Transform_get_x)

static bool js_cocos2dx_dragonbones_Transform_set_x(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::Transform* cobj = (dragonBones::Transform*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Transform_set_x : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Transform_set_x : Error processing new value");
    cobj->x = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_Transform_set_x)

static bool js_cocos2dx_dragonbones_Transform_get_y(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Transform* cobj = (dragonBones::Transform*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Transform_get_y : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->y, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Transform_get_y)

static bool js_cocos2dx_dragonbones_Transform_set_y(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::Transform* cobj = (dragonBones::Transform*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Transform_set_y : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Transform_set_y : Error processing new value");
    cobj->y = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_Transform_set_y)

static bool js_cocos2dx_dragonbones_Transform_get_skew(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Transform* cobj = (dragonBones::Transform*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Transform_get_skew : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->skew, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Transform_get_skew)

static bool js_cocos2dx_dragonbones_Transform_set_skew(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::Transform* cobj = (dragonBones::Transform*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Transform_set_skew : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Transform_set_skew : Error processing new value");
    cobj->skew = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_Transform_set_skew)

static bool js_cocos2dx_dragonbones_Transform_get_rotation(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Transform* cobj = (dragonBones::Transform*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Transform_get_rotation : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->rotation, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Transform_get_rotation)

static bool js_cocos2dx_dragonbones_Transform_set_rotation(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::Transform* cobj = (dragonBones::Transform*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Transform_set_rotation : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Transform_set_rotation : Error processing new value");
    cobj->rotation = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_Transform_set_rotation)

static bool js_cocos2dx_dragonbones_Transform_get_scaleX(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Transform* cobj = (dragonBones::Transform*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Transform_get_scaleX : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->scaleX, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Transform_get_scaleX)

static bool js_cocos2dx_dragonbones_Transform_set_scaleX(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::Transform* cobj = (dragonBones::Transform*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Transform_set_scaleX : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Transform_set_scaleX : Error processing new value");
    cobj->scaleX = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_Transform_set_scaleX)

static bool js_cocos2dx_dragonbones_Transform_get_scaleY(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Transform* cobj = (dragonBones::Transform*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Transform_get_scaleY : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->scaleY, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Transform_get_scaleY)

static bool js_cocos2dx_dragonbones_Transform_set_scaleY(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::Transform* cobj = (dragonBones::Transform*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Transform_set_scaleY : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Transform_set_scaleY : Error processing new value");
    cobj->scaleY = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_Transform_set_scaleY)




bool js_register_cocos2dx_dragonbones_Transform(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Transform", obj, nullptr, nullptr);

    cls->defineProperty(inst, "x", _SE(js_cocos2dx_dragonbones_Transform_get_x), _SE(js_cocos2dx_dragonbones_Transform_set_x));
    cls->defineProperty(inst, "y", _SE(js_cocos2dx_dragonbones_Transform_get_y), _SE(js_cocos2dx_dragonbones_Transform_set_y));
    cls->defineProperty(inst, "skew", _SE(js_cocos2dx_dragonbones_Transform_get_skew), _SE(js_cocos2dx_dragonbones_Transform_set_skew));
    cls->defineProperty(inst, "rotation", _SE(js_cocos2dx_dragonbones_Transform_get_rotation), _SE(js_cocos2dx_dragonbones_Transform_set_rotation));
    cls->defineProperty(inst, "scaleX", _SE(js_cocos2dx_dragonbones_Transform_get_scaleX), _SE(js_cocos2dx_dragonbones_Transform_set_scaleX));
    cls->defineProperty(inst, "scaleY", _SE(js_cocos2dx_dragonbones_Transform_get_scaleY), _SE(js_cocos2dx_dragonbones_Transform_set_scaleY));
    cls->defineStaticFunction(inst, "normalizeRadian", _SE(js_cocos2dx_dragonbones_Transform_normalizeRadian));
    cls->install(inst);
    inst->registerClass<dragonBones::Transform>(cls);

    __jsb_dragonBones_Transform_proto = cls->getProto();
    __jsb_dragonBones_Transform_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_TextureAtlasData_proto = nullptr;
se::Class* __jsb_dragonBones_TextureAtlasData_class = nullptr;

static bool js_cocos2dx_dragonbones_TextureAtlasData_createTexture(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::TextureAtlasData* cobj = (dragonBones::TextureAtlasData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_TextureAtlasData_createTexture : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::TextureData* result = cobj->createTexture();
        ok &= native_ptr_to_rooted_seval<dragonBones::TextureData>(inst, (dragonBones::TextureData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_TextureAtlasData_createTexture : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_TextureAtlasData_createTexture)

static bool js_cocos2dx_dragonbones_TextureAtlasData_getTexture(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::TextureAtlasData* cobj = (dragonBones::TextureAtlasData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_TextureAtlasData_getTexture : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_TextureAtlasData_getTexture : Error processing arguments");
        dragonBones::TextureData* result = cobj->getTexture(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::TextureData>(inst, (dragonBones::TextureData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_TextureAtlasData_getTexture : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_TextureAtlasData_getTexture)

static bool js_cocos2dx_dragonbones_TextureAtlasData_addTexture(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::TextureAtlasData* cobj = (dragonBones::TextureAtlasData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_TextureAtlasData_addTexture : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::TextureData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_TextureAtlasData_addTexture : Error processing arguments");
        cobj->addTexture(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_TextureAtlasData_addTexture)

static bool js_cocos2dx_dragonbones_TextureAtlasData_get_name(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::TextureAtlasData* cobj = (dragonBones::TextureAtlasData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_TextureAtlasData_get_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= std_string_to_seval(inst, cobj->name, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_TextureAtlasData_get_name)

static bool js_cocos2dx_dragonbones_TextureAtlasData_set_name(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::TextureAtlasData* cobj = (dragonBones::TextureAtlasData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_TextureAtlasData_set_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    std::string arg0;
    ok &= seval_to_std_string(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_TextureAtlasData_set_name : Error processing new value");
    cobj->name = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_TextureAtlasData_set_name)


extern se::Object* __jsb_dragonBones_BaseObject_proto;


bool js_register_cocos2dx_dragonbones_TextureAtlasData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "TextureAtlasData", obj, __jsb_dragonBones_BaseObject_proto, nullptr);

    cls->defineProperty(inst, "name", _SE(js_cocos2dx_dragonbones_TextureAtlasData_get_name), _SE(js_cocos2dx_dragonbones_TextureAtlasData_set_name));
    cls->defineFunction(inst, "createTexture", _SE(js_cocos2dx_dragonbones_TextureAtlasData_createTexture));
    cls->defineFunction(inst, "getTexture", _SE(js_cocos2dx_dragonbones_TextureAtlasData_getTexture));
    cls->defineFunction(inst, "addTexture", _SE(js_cocos2dx_dragonbones_TextureAtlasData_addTexture));
    cls->install(inst);
    inst->registerClass<dragonBones::TextureAtlasData>(cls);

    __jsb_dragonBones_TextureAtlasData_proto = cls->getProto();
    __jsb_dragonBones_TextureAtlasData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_TextureData_proto = nullptr;
se::Class* __jsb_dragonBones_TextureData_class = nullptr;

static bool js_cocos2dx_dragonbones_TextureData_getParent(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::TextureData* cobj = (dragonBones::TextureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_TextureData_getParent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const dragonBones::TextureAtlasData* result = cobj->getParent();
        ok &= native_ptr_to_rooted_seval<dragonBones::TextureAtlasData>(inst, (dragonBones::TextureAtlasData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_TextureData_getParent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_TextureData_getParent)

static bool js_cocos2dx_dragonbones_TextureData_setFrame(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::TextureData* cobj = (dragonBones::TextureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_TextureData_setFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::Rectangle* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_TextureData_setFrame : Error processing arguments");
        cobj->setFrame(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_TextureData_setFrame)

static bool js_cocos2dx_dragonbones_TextureData_getRegion(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::TextureData* cobj = (dragonBones::TextureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_TextureData_getRegion : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Rectangle* result = cobj->getRegion();
        ok &= native_ptr_to_seval<dragonBones::Rectangle>(inst, (dragonBones::Rectangle*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_TextureData_getRegion : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_TextureData_getRegion)

static bool js_cocos2dx_dragonbones_TextureData_getFrame(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::TextureData* cobj = (dragonBones::TextureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_TextureData_getFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const dragonBones::Rectangle* result = cobj->getFrame();
        ok &= native_ptr_to_seval<dragonBones::Rectangle>(inst, (dragonBones::Rectangle*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_TextureData_getFrame : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_TextureData_getFrame)

static bool js_cocos2dx_dragonbones_TextureData_setParent(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::TextureData* cobj = (dragonBones::TextureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_TextureData_setParent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::TextureAtlasData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_TextureData_setParent : Error processing arguments");
        cobj->setParent(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_TextureData_setParent)

static bool js_cocos2dx_dragonbones_TextureData_createRectangle(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Rectangle* result = dragonBones::TextureData::createRectangle();
        ok &= native_ptr_to_seval<dragonBones::Rectangle>(inst, (dragonBones::Rectangle*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_TextureData_createRectangle : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_TextureData_createRectangle)


extern se::Object* __jsb_dragonBones_BaseObject_proto;


bool js_register_cocos2dx_dragonbones_TextureData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "TextureData", obj, __jsb_dragonBones_BaseObject_proto, nullptr);

    cls->defineFunction(inst, "getParent", _SE(js_cocos2dx_dragonbones_TextureData_getParent));
    cls->defineFunction(inst, "setFrame", _SE(js_cocos2dx_dragonbones_TextureData_setFrame));
    cls->defineFunction(inst, "getRegion", _SE(js_cocos2dx_dragonbones_TextureData_getRegion));
    cls->defineFunction(inst, "getFrame", _SE(js_cocos2dx_dragonbones_TextureData_getFrame));
    cls->defineFunction(inst, "setParent", _SE(js_cocos2dx_dragonbones_TextureData_setParent));
    cls->defineStaticFunction(inst, "createRectangle", _SE(js_cocos2dx_dragonbones_TextureData_createRectangle));
    cls->install(inst);
    inst->registerClass<dragonBones::TextureData>(cls);

    __jsb_dragonBones_TextureData_proto = cls->getProto();
    __jsb_dragonBones_TextureData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_UserData_proto = nullptr;
se::Class* __jsb_dragonBones_UserData_class = nullptr;

static bool js_cocos2dx_dragonbones_UserData_getFloat(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::UserData* cobj = (dragonBones::UserData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_UserData_getFloat : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= seval_to_uint32(inst, args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_UserData_getFloat : Error processing arguments");
        float result = cobj->getFloat(arg0);
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_UserData_getFloat : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_UserData_getFloat)

static bool js_cocos2dx_dragonbones_UserData_getFloats(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::UserData* cobj = (dragonBones::UserData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_UserData_getFloats : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::vector<float>& result = cobj->getFloats();
        ok &= std_vector_float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_UserData_getFloats : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_UserData_getFloats)

static bool js_cocos2dx_dragonbones_UserData_getString(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::UserData* cobj = (dragonBones::UserData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_UserData_getString : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= seval_to_uint32(inst, args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_UserData_getString : Error processing arguments");
        std::string result = cobj->getString(arg0);
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_UserData_getString : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_UserData_getString)

static bool js_cocos2dx_dragonbones_UserData_getInts(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::UserData* cobj = (dragonBones::UserData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_UserData_getInts : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::vector<int>& result = cobj->getInts();
        ok &= std_vector_int_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_UserData_getInts : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_UserData_getInts)

static bool js_cocos2dx_dragonbones_UserData_getInt(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::UserData* cobj = (dragonBones::UserData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_UserData_getInt : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= seval_to_uint32(inst, args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_UserData_getInt : Error processing arguments");
        int result = cobj->getInt(arg0);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_UserData_getInt : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_UserData_getInt)

static bool js_cocos2dx_dragonbones_UserData_addInt(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::UserData* cobj = (dragonBones::UserData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_UserData_addInt : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_UserData_addInt : Error processing arguments");
        cobj->addInt(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_UserData_addInt)

static bool js_cocos2dx_dragonbones_UserData_getStrings(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::UserData* cobj = (dragonBones::UserData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_UserData_getStrings : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::vector<std::string>& result = cobj->getStrings();
        ok &= std_vector_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_UserData_getStrings : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_UserData_getStrings)

static bool js_cocos2dx_dragonbones_UserData_addFloat(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::UserData* cobj = (dragonBones::UserData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_UserData_addFloat : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_UserData_addFloat : Error processing arguments");
        cobj->addFloat(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_UserData_addFloat)

static bool js_cocos2dx_dragonbones_UserData_addString(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::UserData* cobj = (dragonBones::UserData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_UserData_addString : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_UserData_addString : Error processing arguments");
        cobj->addString(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_UserData_addString)


extern se::Object* __jsb_dragonBones_BaseObject_proto;


bool js_register_cocos2dx_dragonbones_UserData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "UserData", obj, __jsb_dragonBones_BaseObject_proto, nullptr);

    cls->defineFunction(inst, "getFloat", _SE(js_cocos2dx_dragonbones_UserData_getFloat));
    cls->defineFunction(inst, "getFloats", _SE(js_cocos2dx_dragonbones_UserData_getFloats));
    cls->defineFunction(inst, "getString", _SE(js_cocos2dx_dragonbones_UserData_getString));
    cls->defineFunction(inst, "getInts", _SE(js_cocos2dx_dragonbones_UserData_getInts));
    cls->defineFunction(inst, "getInt", _SE(js_cocos2dx_dragonbones_UserData_getInt));
    cls->defineFunction(inst, "addInt", _SE(js_cocos2dx_dragonbones_UserData_addInt));
    cls->defineFunction(inst, "getStrings", _SE(js_cocos2dx_dragonbones_UserData_getStrings));
    cls->defineFunction(inst, "addFloat", _SE(js_cocos2dx_dragonbones_UserData_addFloat));
    cls->defineFunction(inst, "addString", _SE(js_cocos2dx_dragonbones_UserData_addString));
    cls->install(inst);
    inst->registerClass<dragonBones::UserData>(cls);

    __jsb_dragonBones_UserData_proto = cls->getProto();
    __jsb_dragonBones_UserData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_ArmatureData_proto = nullptr;
se::Class* __jsb_dragonBones_ArmatureData_class = nullptr;

static bool js_cocos2dx_dragonbones_ArmatureData_getBone(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_getBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getBone : Error processing arguments");
        dragonBones::BoneData* result = cobj->getBone(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::BoneData>(inst, (dragonBones::BoneData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getBone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_getBone)

static bool js_cocos2dx_dragonbones_ArmatureData_addAction(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_addAction : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        dragonBones::ActionData* arg0 = nullptr;
        bool arg1;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_boolean(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_addAction : Error processing arguments");
        cobj->addAction(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_addAction)

static bool js_cocos2dx_dragonbones_ArmatureData_setUserData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_setUserData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::UserData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_setUserData : Error processing arguments");
        cobj->setUserData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_setUserData)

static bool js_cocos2dx_dragonbones_ArmatureData_getSlot(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_getSlot : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getSlot : Error processing arguments");
        dragonBones::SlotData* result = cobj->getSlot(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::SlotData>(inst, (dragonBones::SlotData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getSlot : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_getSlot)

static bool js_cocos2dx_dragonbones_ArmatureData_getSkin(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_getSkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getSkin : Error processing arguments");
        dragonBones::SkinData* result = cobj->getSkin(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::SkinData>(inst, (dragonBones::SkinData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getSkin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_getSkin)

static bool js_cocos2dx_dragonbones_ArmatureData_setDefaultAnimation(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_setDefaultAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::AnimationData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_setDefaultAnimation : Error processing arguments");
        cobj->setDefaultAnimation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_setDefaultAnimation)

static bool js_cocos2dx_dragonbones_ArmatureData_setType(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_setType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_setType : Error processing arguments");
        cobj->setType(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_setType)

static bool js_cocos2dx_dragonbones_ArmatureData_setParent(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_setParent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::DragonBonesData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_setParent : Error processing arguments");
        cobj->setParent(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_setParent)

static bool js_cocos2dx_dragonbones_ArmatureData_getDefaultSkin(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_getDefaultSkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::SkinData* result = cobj->getDefaultSkin();
        ok &= native_ptr_to_rooted_seval<dragonBones::SkinData>(inst, (dragonBones::SkinData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getDefaultSkin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_getDefaultSkin)

static bool js_cocos2dx_dragonbones_ArmatureData_getMesh(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_getMesh : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        ok &= seval_to_std_string(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getMesh : Error processing arguments");
        dragonBones::MeshDisplayData* result = cobj->getMesh(arg0, arg1, arg2);
        ok &= native_ptr_to_seval<dragonBones::MeshDisplayData>(inst, (dragonBones::MeshDisplayData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getMesh : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_getMesh)

static bool js_cocos2dx_dragonbones_ArmatureData_setDefaultSkin(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_setDefaultSkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::SkinData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_setDefaultSkin : Error processing arguments");
        cobj->setDefaultSkin(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_setDefaultSkin)

static bool js_cocos2dx_dragonbones_ArmatureData_getAnimationNames(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_getAnimationNames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::vector<std::string>& result = cobj->getAnimationNames();
        ok &= std_vector_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getAnimationNames : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_getAnimationNames)

static bool js_cocos2dx_dragonbones_ArmatureData_getType(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_getType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getType();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getType : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_getType)

static bool js_cocos2dx_dragonbones_ArmatureData_addConstraint(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_addConstraint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::ConstraintData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_addConstraint : Error processing arguments");
        cobj->addConstraint(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_addConstraint)

static bool js_cocos2dx_dragonbones_ArmatureData_getUserData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_getUserData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const dragonBones::UserData* result = cobj->getUserData();
        ok &= native_ptr_to_seval<dragonBones::UserData>(inst, (dragonBones::UserData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getUserData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_getUserData)

static bool js_cocos2dx_dragonbones_ArmatureData_getAABB(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_getAABB : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Rectangle* result = cobj->getAABB();
        ok &= native_ptr_to_seval<dragonBones::Rectangle>(inst, (dragonBones::Rectangle*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getAABB : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_getAABB)

static bool js_cocos2dx_dragonbones_ArmatureData_getParent(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_getParent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const dragonBones::DragonBonesData* result = cobj->getParent();
        ok &= native_ptr_to_rooted_seval<dragonBones::DragonBonesData>(inst, (dragonBones::DragonBonesData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getParent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_getParent)

static bool js_cocos2dx_dragonbones_ArmatureData_getDefaultAnimation(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_getDefaultAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::AnimationData* result = cobj->getDefaultAnimation();
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationData>(inst, (dragonBones::AnimationData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getDefaultAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_getDefaultAnimation)

static bool js_cocos2dx_dragonbones_ArmatureData_getAnimation(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_getAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getAnimation : Error processing arguments");
        dragonBones::AnimationData* result = cobj->getAnimation(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationData>(inst, (dragonBones::AnimationData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_getAnimation)

static bool js_cocos2dx_dragonbones_ArmatureData_getConstraint(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_getConstraint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getConstraint : Error processing arguments");
        dragonBones::ConstraintData* result = cobj->getConstraint(arg0);
        ok &= native_ptr_to_seval<dragonBones::ConstraintData>(inst, (dragonBones::ConstraintData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_getConstraint : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_getConstraint)

static bool js_cocos2dx_dragonbones_ArmatureData_sortBones(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_sortBones : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->sortBones();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureData_sortBones)

static bool js_cocos2dx_dragonbones_ArmatureData_get_frameRate(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_get_frameRate : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= uint32_to_seval(inst, cobj->frameRate, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_ArmatureData_get_frameRate)

static bool js_cocos2dx_dragonbones_ArmatureData_set_frameRate(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_set_frameRate : Invalid Native Object");

    CC_UNUSED bool ok = true;
    unsigned int arg0 = 0;
    ok &= seval_to_uint32(inst, args[0], (uint32_t*)&arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_set_frameRate : Error processing new value");
    cobj->frameRate = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_ArmatureData_set_frameRate)

static bool js_cocos2dx_dragonbones_ArmatureData_get_name(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_get_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= std_string_to_seval(inst, cobj->name, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_ArmatureData_get_name)

static bool js_cocos2dx_dragonbones_ArmatureData_set_name(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureData_set_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    std::string arg0;
    ok &= seval_to_std_string(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureData_set_name : Error processing new value");
    cobj->name = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_ArmatureData_set_name)


extern se::Object* __jsb_dragonBones_BaseObject_proto;


bool js_register_cocos2dx_dragonbones_ArmatureData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "ArmatureData", obj, __jsb_dragonBones_BaseObject_proto, nullptr);

    cls->defineProperty(inst, "frameRate", _SE(js_cocos2dx_dragonbones_ArmatureData_get_frameRate), _SE(js_cocos2dx_dragonbones_ArmatureData_set_frameRate));
    cls->defineProperty(inst, "name", _SE(js_cocos2dx_dragonbones_ArmatureData_get_name), _SE(js_cocos2dx_dragonbones_ArmatureData_set_name));
    cls->defineFunction(inst, "getBone", _SE(js_cocos2dx_dragonbones_ArmatureData_getBone));
    cls->defineFunction(inst, "addAction", _SE(js_cocos2dx_dragonbones_ArmatureData_addAction));
    cls->defineFunction(inst, "setUserData", _SE(js_cocos2dx_dragonbones_ArmatureData_setUserData));
    cls->defineFunction(inst, "getSlot", _SE(js_cocos2dx_dragonbones_ArmatureData_getSlot));
    cls->defineFunction(inst, "getSkin", _SE(js_cocos2dx_dragonbones_ArmatureData_getSkin));
    cls->defineFunction(inst, "setDefaultAnimation", _SE(js_cocos2dx_dragonbones_ArmatureData_setDefaultAnimation));
    cls->defineFunction(inst, "setType", _SE(js_cocos2dx_dragonbones_ArmatureData_setType));
    cls->defineFunction(inst, "setParent", _SE(js_cocos2dx_dragonbones_ArmatureData_setParent));
    cls->defineFunction(inst, "getDefaultSkin", _SE(js_cocos2dx_dragonbones_ArmatureData_getDefaultSkin));
    cls->defineFunction(inst, "getMesh", _SE(js_cocos2dx_dragonbones_ArmatureData_getMesh));
    cls->defineFunction(inst, "setDefaultSkin", _SE(js_cocos2dx_dragonbones_ArmatureData_setDefaultSkin));
    cls->defineFunction(inst, "getAnimationNames", _SE(js_cocos2dx_dragonbones_ArmatureData_getAnimationNames));
    cls->defineFunction(inst, "getType", _SE(js_cocos2dx_dragonbones_ArmatureData_getType));
    cls->defineFunction(inst, "addConstraint", _SE(js_cocos2dx_dragonbones_ArmatureData_addConstraint));
    cls->defineFunction(inst, "getUserData", _SE(js_cocos2dx_dragonbones_ArmatureData_getUserData));
    cls->defineFunction(inst, "getAABB", _SE(js_cocos2dx_dragonbones_ArmatureData_getAABB));
    cls->defineFunction(inst, "getParent", _SE(js_cocos2dx_dragonbones_ArmatureData_getParent));
    cls->defineFunction(inst, "getDefaultAnimation", _SE(js_cocos2dx_dragonbones_ArmatureData_getDefaultAnimation));
    cls->defineFunction(inst, "getAnimation", _SE(js_cocos2dx_dragonbones_ArmatureData_getAnimation));
    cls->defineFunction(inst, "getConstraint", _SE(js_cocos2dx_dragonbones_ArmatureData_getConstraint));
    cls->defineFunction(inst, "sortBones", _SE(js_cocos2dx_dragonbones_ArmatureData_sortBones));
    cls->install(inst);
    inst->registerClass<dragonBones::ArmatureData>(cls);

    __jsb_dragonBones_ArmatureData_proto = cls->getProto();
    __jsb_dragonBones_ArmatureData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_BoneData_proto = nullptr;
se::Class* __jsb_dragonBones_BoneData_class = nullptr;

static bool js_cocos2dx_dragonbones_BoneData_setParent(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BoneData* cobj = (dragonBones::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoneData_setParent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::BoneData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoneData_setParent : Error processing arguments");
        cobj->setParent(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BoneData_setParent)

static bool js_cocos2dx_dragonbones_BoneData_getTransfrom(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BoneData* cobj = (dragonBones::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoneData_getTransfrom : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Transform* result = cobj->getTransfrom();
        ok &= native_ptr_to_rooted_seval<dragonBones::Transform>(inst, (dragonBones::Transform*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoneData_getTransfrom : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BoneData_getTransfrom)

static bool js_cocos2dx_dragonbones_BoneData_setUserData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BoneData* cobj = (dragonBones::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoneData_setUserData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::UserData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoneData_setUserData : Error processing arguments");
        cobj->setUserData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BoneData_setUserData)

static bool js_cocos2dx_dragonbones_BoneData_getUserData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BoneData* cobj = (dragonBones::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoneData_getUserData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const dragonBones::UserData* result = cobj->getUserData();
        ok &= native_ptr_to_seval<dragonBones::UserData>(inst, (dragonBones::UserData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoneData_getUserData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BoneData_getUserData)

static bool js_cocos2dx_dragonbones_BoneData_getParent(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BoneData* cobj = (dragonBones::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoneData_getParent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const dragonBones::BoneData* result = cobj->getParent();
        ok &= native_ptr_to_rooted_seval<dragonBones::BoneData>(inst, (dragonBones::BoneData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoneData_getParent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BoneData_getParent)

static bool js_cocos2dx_dragonbones_BoneData_get_name(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BoneData* cobj = (dragonBones::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoneData_get_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= std_string_to_seval(inst, cobj->name, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_BoneData_get_name)

static bool js_cocos2dx_dragonbones_BoneData_set_name(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::BoneData* cobj = (dragonBones::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoneData_set_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    std::string arg0;
    ok &= seval_to_std_string(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoneData_set_name : Error processing new value");
    cobj->name = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_BoneData_set_name)

static bool js_cocos2dx_dragonbones_BoneData_get_parent(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BoneData* cobj = (dragonBones::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoneData_get_parent : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= native_ptr_to_rooted_seval<dragonBones::BoneData>(inst, (dragonBones::BoneData*)cobj->parent, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_BoneData_get_parent)

static bool js_cocos2dx_dragonbones_BoneData_set_parent(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::BoneData* cobj = (dragonBones::BoneData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoneData_set_parent : Invalid Native Object");

    CC_UNUSED bool ok = true;
    dragonBones::BoneData* arg0 = nullptr;
    ok &= seval_to_native_ptr(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoneData_set_parent : Error processing new value");
    cobj->parent = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_BoneData_set_parent)


extern se::Object* __jsb_dragonBones_BaseObject_proto;


bool js_register_cocos2dx_dragonbones_BoneData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "BoneData", obj, __jsb_dragonBones_BaseObject_proto, nullptr);

    cls->defineProperty(inst, "name", _SE(js_cocos2dx_dragonbones_BoneData_get_name), _SE(js_cocos2dx_dragonbones_BoneData_set_name));
    cls->defineProperty(inst, "parent", _SE(js_cocos2dx_dragonbones_BoneData_get_parent), _SE(js_cocos2dx_dragonbones_BoneData_set_parent));
    cls->defineFunction(inst, "setParent", _SE(js_cocos2dx_dragonbones_BoneData_setParent));
    cls->defineFunction(inst, "getTransfrom", _SE(js_cocos2dx_dragonbones_BoneData_getTransfrom));
    cls->defineFunction(inst, "setUserData", _SE(js_cocos2dx_dragonbones_BoneData_setUserData));
    cls->defineFunction(inst, "getUserData", _SE(js_cocos2dx_dragonbones_BoneData_getUserData));
    cls->defineFunction(inst, "getParent", _SE(js_cocos2dx_dragonbones_BoneData_getParent));
    cls->install(inst);
    inst->registerClass<dragonBones::BoneData>(cls);

    __jsb_dragonBones_BoneData_proto = cls->getProto();
    __jsb_dragonBones_BoneData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_SlotData_proto = nullptr;
se::Class* __jsb_dragonBones_SlotData_class = nullptr;

static bool js_cocos2dx_dragonbones_SlotData_setUserData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::SlotData* cobj = (dragonBones::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_SlotData_setUserData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::UserData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_SlotData_setUserData : Error processing arguments");
        cobj->setUserData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_SlotData_setUserData)

static bool js_cocos2dx_dragonbones_SlotData_setColor(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::SlotData* cobj = (dragonBones::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_SlotData_setColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::ColorTransform* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_SlotData_setColor : Error processing arguments");
        cobj->setColor(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_SlotData_setColor)

static bool js_cocos2dx_dragonbones_SlotData_getUserData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::SlotData* cobj = (dragonBones::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_SlotData_getUserData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const dragonBones::UserData* result = cobj->getUserData();
        ok &= native_ptr_to_seval<dragonBones::UserData>(inst, (dragonBones::UserData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_SlotData_getUserData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_SlotData_getUserData)

static bool js_cocos2dx_dragonbones_SlotData_getColor(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::SlotData* cobj = (dragonBones::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_SlotData_getColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::ColorTransform* result = cobj->getColor();
        ok &= native_ptr_to_seval<dragonBones::ColorTransform>(inst, (dragonBones::ColorTransform*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_SlotData_getColor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_SlotData_getColor)

static bool js_cocos2dx_dragonbones_SlotData_setBlendMode(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::SlotData* cobj = (dragonBones::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_SlotData_setBlendMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_SlotData_setBlendMode : Error processing arguments");
        cobj->setBlendMode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_SlotData_setBlendMode)

static bool js_cocos2dx_dragonbones_SlotData_getBlendMode(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::SlotData* cobj = (dragonBones::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_SlotData_getBlendMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getBlendMode();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_SlotData_getBlendMode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_SlotData_getBlendMode)

static bool js_cocos2dx_dragonbones_SlotData_setParent(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::SlotData* cobj = (dragonBones::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_SlotData_setParent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::BoneData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_SlotData_setParent : Error processing arguments");
        cobj->setParent(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_SlotData_setParent)

static bool js_cocos2dx_dragonbones_SlotData_getParent(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::SlotData* cobj = (dragonBones::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_SlotData_getParent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const dragonBones::BoneData* result = cobj->getParent();
        ok &= native_ptr_to_rooted_seval<dragonBones::BoneData>(inst, (dragonBones::BoneData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_SlotData_getParent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_SlotData_getParent)

static bool js_cocos2dx_dragonbones_SlotData_createColor(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::ColorTransform* result = dragonBones::SlotData::createColor();
        ok &= native_ptr_to_seval<dragonBones::ColorTransform>(inst, (dragonBones::ColorTransform*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_SlotData_createColor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_SlotData_createColor)

static bool js_cocos2dx_dragonbones_SlotData_getDefaultColor(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::ColorTransform* result = dragonBones::SlotData::getDefaultColor();
        ok &= native_ptr_to_seval<dragonBones::ColorTransform>(inst, (dragonBones::ColorTransform*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_SlotData_getDefaultColor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_SlotData_getDefaultColor)

static bool js_cocos2dx_dragonbones_SlotData_get_name(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::SlotData* cobj = (dragonBones::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_SlotData_get_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= std_string_to_seval(inst, cobj->name, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_SlotData_get_name)

static bool js_cocos2dx_dragonbones_SlotData_set_name(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::SlotData* cobj = (dragonBones::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_SlotData_set_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    std::string arg0;
    ok &= seval_to_std_string(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_SlotData_set_name : Error processing new value");
    cobj->name = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_SlotData_set_name)

static bool js_cocos2dx_dragonbones_SlotData_get_parent(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::SlotData* cobj = (dragonBones::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_SlotData_get_parent : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= native_ptr_to_rooted_seval<dragonBones::BoneData>(inst, (dragonBones::BoneData*)cobj->parent, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_SlotData_get_parent)

static bool js_cocos2dx_dragonbones_SlotData_set_parent(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::SlotData* cobj = (dragonBones::SlotData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_SlotData_set_parent : Invalid Native Object");

    CC_UNUSED bool ok = true;
    dragonBones::BoneData* arg0 = nullptr;
    ok &= seval_to_native_ptr(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_SlotData_set_parent : Error processing new value");
    cobj->parent = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_SlotData_set_parent)


extern se::Object* __jsb_dragonBones_BaseObject_proto;


bool js_register_cocos2dx_dragonbones_SlotData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "SlotData", obj, __jsb_dragonBones_BaseObject_proto, nullptr);

    cls->defineProperty(inst, "name", _SE(js_cocos2dx_dragonbones_SlotData_get_name), _SE(js_cocos2dx_dragonbones_SlotData_set_name));
    cls->defineProperty(inst, "parent", _SE(js_cocos2dx_dragonbones_SlotData_get_parent), _SE(js_cocos2dx_dragonbones_SlotData_set_parent));
    cls->defineFunction(inst, "setUserData", _SE(js_cocos2dx_dragonbones_SlotData_setUserData));
    cls->defineFunction(inst, "setColor", _SE(js_cocos2dx_dragonbones_SlotData_setColor));
    cls->defineFunction(inst, "getUserData", _SE(js_cocos2dx_dragonbones_SlotData_getUserData));
    cls->defineFunction(inst, "getColor", _SE(js_cocos2dx_dragonbones_SlotData_getColor));
    cls->defineFunction(inst, "setBlendMode", _SE(js_cocos2dx_dragonbones_SlotData_setBlendMode));
    cls->defineFunction(inst, "getBlendMode", _SE(js_cocos2dx_dragonbones_SlotData_getBlendMode));
    cls->defineFunction(inst, "setParent", _SE(js_cocos2dx_dragonbones_SlotData_setParent));
    cls->defineFunction(inst, "getParent", _SE(js_cocos2dx_dragonbones_SlotData_getParent));
    cls->defineStaticFunction(inst, "createColor", _SE(js_cocos2dx_dragonbones_SlotData_createColor));
    cls->defineStaticFunction(inst, "getDefaultColor", _SE(js_cocos2dx_dragonbones_SlotData_getDefaultColor));
    cls->install(inst);
    inst->registerClass<dragonBones::SlotData>(cls);

    __jsb_dragonBones_SlotData_proto = cls->getProto();
    __jsb_dragonBones_SlotData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_DragonBonesData_proto = nullptr;
se::Class* __jsb_dragonBones_DragonBonesData_class = nullptr;

static bool js_cocos2dx_dragonbones_DragonBonesData_setUserData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::DragonBonesData* cobj = (dragonBones::DragonBonesData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_DragonBonesData_setUserData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::UserData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_DragonBonesData_setUserData : Error processing arguments");
        cobj->setUserData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_DragonBonesData_setUserData)

static bool js_cocos2dx_dragonbones_DragonBonesData_getUserData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::DragonBonesData* cobj = (dragonBones::DragonBonesData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_DragonBonesData_getUserData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const dragonBones::UserData* result = cobj->getUserData();
        ok &= native_ptr_to_seval<dragonBones::UserData>(inst, (dragonBones::UserData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_DragonBonesData_getUserData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_DragonBonesData_getUserData)

static bool js_cocos2dx_dragonbones_DragonBonesData_getFrameIndices(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::DragonBonesData* cobj = (dragonBones::DragonBonesData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_DragonBonesData_getFrameIndices : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::vector<unsigned int>* result = cobj->getFrameIndices();
        ok &= native_ptr_to_seval<std::vector<unsigned int>>(inst, (std::vector<unsigned int>*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_DragonBonesData_getFrameIndices : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_DragonBonesData_getFrameIndices)

static bool js_cocos2dx_dragonbones_DragonBonesData_getArmature(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::DragonBonesData* cobj = (dragonBones::DragonBonesData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_DragonBonesData_getArmature : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_DragonBonesData_getArmature : Error processing arguments");
        dragonBones::ArmatureData* result = cobj->getArmature(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::ArmatureData>(inst, (dragonBones::ArmatureData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_DragonBonesData_getArmature : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_DragonBonesData_getArmature)

static bool js_cocos2dx_dragonbones_DragonBonesData_getArmatureNames(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::DragonBonesData* cobj = (dragonBones::DragonBonesData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_DragonBonesData_getArmatureNames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::vector<std::string>& result = cobj->getArmatureNames();
        ok &= std_vector_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_DragonBonesData_getArmatureNames : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_DragonBonesData_getArmatureNames)

static bool js_cocos2dx_dragonbones_DragonBonesData_addArmature(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::DragonBonesData* cobj = (dragonBones::DragonBonesData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_DragonBonesData_addArmature : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::ArmatureData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_DragonBonesData_addArmature : Error processing arguments");
        cobj->addArmature(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_DragonBonesData_addArmature)

static bool js_cocos2dx_dragonbones_DragonBonesData_get_name(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::DragonBonesData* cobj = (dragonBones::DragonBonesData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_DragonBonesData_get_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= std_string_to_seval(inst, cobj->name, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_DragonBonesData_get_name)

static bool js_cocos2dx_dragonbones_DragonBonesData_set_name(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::DragonBonesData* cobj = (dragonBones::DragonBonesData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_DragonBonesData_set_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    std::string arg0;
    ok &= seval_to_std_string(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_DragonBonesData_set_name : Error processing new value");
    cobj->name = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_DragonBonesData_set_name)


extern se::Object* __jsb_dragonBones_BaseObject_proto;


bool js_register_cocos2dx_dragonbones_DragonBonesData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "DragonBonesData", obj, __jsb_dragonBones_BaseObject_proto, nullptr);

    cls->defineProperty(inst, "name", _SE(js_cocos2dx_dragonbones_DragonBonesData_get_name), _SE(js_cocos2dx_dragonbones_DragonBonesData_set_name));
    cls->defineFunction(inst, "setUserData", _SE(js_cocos2dx_dragonbones_DragonBonesData_setUserData));
    cls->defineFunction(inst, "getUserData", _SE(js_cocos2dx_dragonbones_DragonBonesData_getUserData));
    cls->defineFunction(inst, "getFrameIndices", _SE(js_cocos2dx_dragonbones_DragonBonesData_getFrameIndices));
    cls->defineFunction(inst, "getArmature", _SE(js_cocos2dx_dragonbones_DragonBonesData_getArmature));
    cls->defineFunction(inst, "getArmatureNames", _SE(js_cocos2dx_dragonbones_DragonBonesData_getArmatureNames));
    cls->defineFunction(inst, "addArmature", _SE(js_cocos2dx_dragonbones_DragonBonesData_addArmature));
    cls->install(inst);
    inst->registerClass<dragonBones::DragonBonesData>(cls);

    __jsb_dragonBones_DragonBonesData_proto = cls->getProto();
    __jsb_dragonBones_DragonBonesData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_SkinData_proto = nullptr;
se::Class* __jsb_dragonBones_SkinData_class = nullptr;

static bool js_cocos2dx_dragonbones_SkinData_addDisplay(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::SkinData* cobj = (dragonBones::SkinData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_SkinData_addDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        dragonBones::DisplayData* arg1 = nullptr;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_SkinData_addDisplay : Error processing arguments");
        cobj->addDisplay(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_SkinData_addDisplay)

static bool js_cocos2dx_dragonbones_SkinData_getDisplay(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::SkinData* cobj = (dragonBones::SkinData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_SkinData_getDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_SkinData_getDisplay : Error processing arguments");
        dragonBones::DisplayData* result = cobj->getDisplay(arg0, arg1);
        ok &= native_ptr_to_seval<dragonBones::DisplayData>(inst, (dragonBones::DisplayData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_SkinData_getDisplay : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_SkinData_getDisplay)

static bool js_cocos2dx_dragonbones_SkinData_get_name(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::SkinData* cobj = (dragonBones::SkinData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_SkinData_get_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= std_string_to_seval(inst, cobj->name, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_SkinData_get_name)

static bool js_cocos2dx_dragonbones_SkinData_set_name(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::SkinData* cobj = (dragonBones::SkinData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_SkinData_set_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    std::string arg0;
    ok &= seval_to_std_string(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_SkinData_set_name : Error processing new value");
    cobj->name = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_SkinData_set_name)


extern se::Object* __jsb_dragonBones_BaseObject_proto;


bool js_register_cocos2dx_dragonbones_SkinData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "SkinData", obj, __jsb_dragonBones_BaseObject_proto, nullptr);

    cls->defineProperty(inst, "name", _SE(js_cocos2dx_dragonbones_SkinData_get_name), _SE(js_cocos2dx_dragonbones_SkinData_set_name));
    cls->defineFunction(inst, "addDisplay", _SE(js_cocos2dx_dragonbones_SkinData_addDisplay));
    cls->defineFunction(inst, "getDisplay", _SE(js_cocos2dx_dragonbones_SkinData_getDisplay));
    cls->install(inst);
    inst->registerClass<dragonBones::SkinData>(cls);

    __jsb_dragonBones_SkinData_proto = cls->getProto();
    __jsb_dragonBones_SkinData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_BoundingBoxData_proto = nullptr;
se::Class* __jsb_dragonBones_BoundingBoxData_class = nullptr;

static bool js_cocos2dx_dragonbones_BoundingBoxData_intersectsSegment(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BoundingBoxData* cobj = (dragonBones::BoundingBoxData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoundingBoxData_intersectsSegment : Invalid Native Object");
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
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoundingBoxData_intersectsSegment : Error processing arguments");
        int result = cobj->intersectsSegment(arg0, arg1, arg2, arg3);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoundingBoxData_intersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 5) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        dragonBones::Point* arg4 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_native_ptr(inst, args[4], &arg4);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoundingBoxData_intersectsSegment : Error processing arguments");
        int result = cobj->intersectsSegment(arg0, arg1, arg2, arg3, arg4);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoundingBoxData_intersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 6) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        dragonBones::Point* arg4 = 0;
        dragonBones::Point* arg5 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_native_ptr(inst, args[4], &arg4);
        ok &= seval_to_native_ptr(inst, args[5], &arg5);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoundingBoxData_intersectsSegment : Error processing arguments");
        int result = cobj->intersectsSegment(arg0, arg1, arg2, arg3, arg4, arg5);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoundingBoxData_intersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 7) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        dragonBones::Point* arg4 = 0;
        dragonBones::Point* arg5 = 0;
        dragonBones::Point* arg6 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_native_ptr(inst, args[4], &arg4);
        ok &= seval_to_native_ptr(inst, args[5], &arg5);
        ok &= seval_to_native_ptr(inst, args[6], &arg6);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoundingBoxData_intersectsSegment : Error processing arguments");
        int result = cobj->intersectsSegment(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoundingBoxData_intersectsSegment : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 7);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BoundingBoxData_intersectsSegment)

static bool js_cocos2dx_dragonbones_BoundingBoxData_containsPoint(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BoundingBoxData* cobj = (dragonBones::BoundingBoxData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoundingBoxData_containsPoint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoundingBoxData_containsPoint : Error processing arguments");
        bool result = cobj->containsPoint(arg0, arg1);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoundingBoxData_containsPoint : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BoundingBoxData_containsPoint)

static bool js_cocos2dx_dragonbones_BoundingBoxData_getType(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BoundingBoxData* cobj = (dragonBones::BoundingBoxData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoundingBoxData_getType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getType();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoundingBoxData_getType : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BoundingBoxData_getType)

static bool js_cocos2dx_dragonbones_BoundingBoxData_setType(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BoundingBoxData* cobj = (dragonBones::BoundingBoxData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoundingBoxData_setType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoundingBoxData_setType : Error processing arguments");
        cobj->setType(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BoundingBoxData_setType)

static bool js_cocos2dx_dragonbones_BoundingBoxData_get_color(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BoundingBoxData* cobj = (dragonBones::BoundingBoxData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoundingBoxData_get_color : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= uint32_to_seval(inst, cobj->color, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_BoundingBoxData_get_color)

static bool js_cocos2dx_dragonbones_BoundingBoxData_set_color(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::BoundingBoxData* cobj = (dragonBones::BoundingBoxData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoundingBoxData_set_color : Invalid Native Object");

    CC_UNUSED bool ok = true;
    unsigned int arg0 = 0;
    ok &= seval_to_uint32(inst, args[0], (uint32_t*)&arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoundingBoxData_set_color : Error processing new value");
    cobj->color = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_BoundingBoxData_set_color)

static bool js_cocos2dx_dragonbones_BoundingBoxData_get_width(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BoundingBoxData* cobj = (dragonBones::BoundingBoxData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoundingBoxData_get_width : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->width, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_BoundingBoxData_get_width)

static bool js_cocos2dx_dragonbones_BoundingBoxData_set_width(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::BoundingBoxData* cobj = (dragonBones::BoundingBoxData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoundingBoxData_set_width : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoundingBoxData_set_width : Error processing new value");
    cobj->width = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_BoundingBoxData_set_width)

static bool js_cocos2dx_dragonbones_BoundingBoxData_get_height(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BoundingBoxData* cobj = (dragonBones::BoundingBoxData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoundingBoxData_get_height : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->height, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_BoundingBoxData_get_height)

static bool js_cocos2dx_dragonbones_BoundingBoxData_set_height(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::BoundingBoxData* cobj = (dragonBones::BoundingBoxData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BoundingBoxData_set_height : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BoundingBoxData_set_height : Error processing new value");
    cobj->height = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_BoundingBoxData_set_height)


extern se::Object* __jsb_dragonBones_BaseObject_proto;


bool js_register_cocos2dx_dragonbones_BoundingBoxData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "BoundingBoxData", obj, __jsb_dragonBones_BaseObject_proto, nullptr);

    cls->defineProperty(inst , "color", _SE(js_cocos2dx_dragonbones_BoundingBoxData_get_color), _SE(js_cocos2dx_dragonbones_BoundingBoxData_set_color));
    cls->defineProperty(inst , "width", _SE(js_cocos2dx_dragonbones_BoundingBoxData_get_width), _SE(js_cocos2dx_dragonbones_BoundingBoxData_set_width));
    cls->defineProperty(inst , "height", _SE(js_cocos2dx_dragonbones_BoundingBoxData_get_height), _SE(js_cocos2dx_dragonbones_BoundingBoxData_set_height));
    cls->defineFunction(inst , "intersectsSegment", _SE(js_cocos2dx_dragonbones_BoundingBoxData_intersectsSegment));
    cls->defineFunction(inst , "containsPoint", _SE(js_cocos2dx_dragonbones_BoundingBoxData_containsPoint));
    cls->defineFunction(inst , "getType", _SE(js_cocos2dx_dragonbones_BoundingBoxData_getType));
    cls->defineFunction(inst , "setType", _SE(js_cocos2dx_dragonbones_BoundingBoxData_setType));
    cls->install(inst);
    inst->registerClass<dragonBones::BoundingBoxData>(cls);

    __jsb_dragonBones_BoundingBoxData_proto = cls->getProto();
    __jsb_dragonBones_BoundingBoxData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_RectangleBoundingBoxData_proto = nullptr;
se::Class* __jsb_dragonBones_RectangleBoundingBoxData_class = nullptr;

static bool js_cocos2dx_dragonbones_RectangleBoundingBoxData_rectangleIntersectsSegment(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 8) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        float arg5 = 0;
        float arg6 = 0;
        float arg7 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_float(inst, args[4], &arg4);
        ok &= seval_to_float(inst, args[5], &arg5);
        ok &= seval_to_float(inst, args[6], &arg6);
        ok &= seval_to_float(inst, args[7], &arg7);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_RectangleBoundingBoxData_rectangleIntersectsSegment : Error processing arguments");
        int result = dragonBones::RectangleBoundingBoxData::rectangleIntersectsSegment(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_RectangleBoundingBoxData_rectangleIntersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 9) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        float arg5 = 0;
        float arg6 = 0;
        float arg7 = 0;
        dragonBones::Point* arg8 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_float(inst, args[4], &arg4);
        ok &= seval_to_float(inst, args[5], &arg5);
        ok &= seval_to_float(inst, args[6], &arg6);
        ok &= seval_to_float(inst, args[7], &arg7);
        ok &= seval_to_native_ptr(inst, args[8], &arg8);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_RectangleBoundingBoxData_rectangleIntersectsSegment : Error processing arguments");
        int result = dragonBones::RectangleBoundingBoxData::rectangleIntersectsSegment(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_RectangleBoundingBoxData_rectangleIntersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 10) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        float arg5 = 0;
        float arg6 = 0;
        float arg7 = 0;
        dragonBones::Point* arg8 = 0;
        dragonBones::Point* arg9 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_float(inst, args[4], &arg4);
        ok &= seval_to_float(inst, args[5], &arg5);
        ok &= seval_to_float(inst, args[6], &arg6);
        ok &= seval_to_float(inst, args[7], &arg7);
        ok &= seval_to_native_ptr(inst, args[8], &arg8);
        ok &= seval_to_native_ptr(inst, args[9], &arg9);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_RectangleBoundingBoxData_rectangleIntersectsSegment : Error processing arguments");
        int result = dragonBones::RectangleBoundingBoxData::rectangleIntersectsSegment(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_RectangleBoundingBoxData_rectangleIntersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 11) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        float arg5 = 0;
        float arg6 = 0;
        float arg7 = 0;
        dragonBones::Point* arg8 = 0;
        dragonBones::Point* arg9 = 0;
        dragonBones::Point* arg10 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_float(inst, args[4], &arg4);
        ok &= seval_to_float(inst, args[5], &arg5);
        ok &= seval_to_float(inst, args[6], &arg6);
        ok &= seval_to_float(inst, args[7], &arg7);
        ok &= seval_to_native_ptr(inst, args[8], &arg8);
        ok &= seval_to_native_ptr(inst, args[9], &arg9);
        ok &= seval_to_native_ptr(inst, args[10], &arg10);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_RectangleBoundingBoxData_rectangleIntersectsSegment : Error processing arguments");
        int result = dragonBones::RectangleBoundingBoxData::rectangleIntersectsSegment(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_RectangleBoundingBoxData_rectangleIntersectsSegment : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 11);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_RectangleBoundingBoxData_rectangleIntersectsSegment)

static bool js_cocos2dx_dragonbones_RectangleBoundingBoxData_getTypeIndex(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        size_t result = dragonBones::RectangleBoundingBoxData::getTypeIndex();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_RectangleBoundingBoxData_getTypeIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_RectangleBoundingBoxData_getTypeIndex)

SE_DECLARE_FINALIZE_FUNC(js_dragonBones_RectangleBoundingBoxData_finalize)

static bool js_cocos2dx_dragonbones_RectangleBoundingBoxData_constructor(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::RectangleBoundingBoxData* cobj = new (std::nothrow) dragonBones::RectangleBoundingBoxData();
    s.thisObject(inst)->setPrivateData(cobj);
    inst->getNoneRefNativePtrMap().emplace(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_dragonbones_RectangleBoundingBoxData_constructor, __jsb_dragonBones_RectangleBoundingBoxData_class, js_dragonBones_RectangleBoundingBoxData_finalize)



extern se::Object* __jsb_dragonBones_BoundingBoxData_proto;

static bool js_dragonBones_RectangleBoundingBoxData_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (dragonBones::RectangleBoundingBoxData)", s.nativeThisObject());
    return true;
}
SE_BIND_FINALIZE_FUNC(js_dragonBones_RectangleBoundingBoxData_finalize)

bool js_register_cocos2dx_dragonbones_RectangleBoundingBoxData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "RectangleBoundingBoxData", obj, __jsb_dragonBones_BoundingBoxData_proto, _SE(js_cocos2dx_dragonbones_RectangleBoundingBoxData_constructor));

    cls->defineStaticFunction(inst, "rectangleIntersectsSegment", _SE(js_cocos2dx_dragonbones_RectangleBoundingBoxData_rectangleIntersectsSegment));
    cls->defineStaticFunction(inst, "getTypeIndex", _SE(js_cocos2dx_dragonbones_RectangleBoundingBoxData_getTypeIndex));
    cls->defineFinalizeFunction(_SE(js_dragonBones_RectangleBoundingBoxData_finalize));
    cls->install(inst);
    inst->registerClass<dragonBones::RectangleBoundingBoxData>(cls);

    __jsb_dragonBones_RectangleBoundingBoxData_proto = cls->getProto();
    __jsb_dragonBones_RectangleBoundingBoxData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_EllipseBoundingBoxData_proto = nullptr;
se::Class* __jsb_dragonBones_EllipseBoundingBoxData_class = nullptr;

static bool js_cocos2dx_dragonbones_EllipseBoundingBoxData_getTypeIndex(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        size_t result = dragonBones::EllipseBoundingBoxData::getTypeIndex();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EllipseBoundingBoxData_getTypeIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_EllipseBoundingBoxData_getTypeIndex)

static bool js_cocos2dx_dragonbones_EllipseBoundingBoxData_ellipseIntersectsSegment(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 8) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        float arg5 = 0;
        float arg6 = 0;
        float arg7 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_float(inst, args[4], &arg4);
        ok &= seval_to_float(inst, args[5], &arg5);
        ok &= seval_to_float(inst, args[6], &arg6);
        ok &= seval_to_float(inst, args[7], &arg7);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EllipseBoundingBoxData_ellipseIntersectsSegment : Error processing arguments");
        int result = dragonBones::EllipseBoundingBoxData::ellipseIntersectsSegment(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EllipseBoundingBoxData_ellipseIntersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 9) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        float arg5 = 0;
        float arg6 = 0;
        float arg7 = 0;
        dragonBones::Point* arg8 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_float(inst, args[4], &arg4);
        ok &= seval_to_float(inst, args[5], &arg5);
        ok &= seval_to_float(inst, args[6], &arg6);
        ok &= seval_to_float(inst, args[7], &arg7);
        ok &= seval_to_native_ptr(inst, args[8], &arg8);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EllipseBoundingBoxData_ellipseIntersectsSegment : Error processing arguments");
        int result = dragonBones::EllipseBoundingBoxData::ellipseIntersectsSegment(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EllipseBoundingBoxData_ellipseIntersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 10) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        float arg5 = 0;
        float arg6 = 0;
        float arg7 = 0;
        dragonBones::Point* arg8 = 0;
        dragonBones::Point* arg9 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_float(inst, args[4], &arg4);
        ok &= seval_to_float(inst, args[5], &arg5);
        ok &= seval_to_float(inst, args[6], &arg6);
        ok &= seval_to_float(inst, args[7], &arg7);
        ok &= seval_to_native_ptr(inst, args[8], &arg8);
        ok &= seval_to_native_ptr(inst, args[9], &arg9);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EllipseBoundingBoxData_ellipseIntersectsSegment : Error processing arguments");
        int result = dragonBones::EllipseBoundingBoxData::ellipseIntersectsSegment(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EllipseBoundingBoxData_ellipseIntersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 11) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        float arg5 = 0;
        float arg6 = 0;
        float arg7 = 0;
        dragonBones::Point* arg8 = 0;
        dragonBones::Point* arg9 = 0;
        dragonBones::Point* arg10 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_float(inst, args[4], &arg4);
        ok &= seval_to_float(inst, args[5], &arg5);
        ok &= seval_to_float(inst, args[6], &arg6);
        ok &= seval_to_float(inst, args[7], &arg7);
        ok &= seval_to_native_ptr(inst, args[8], &arg8);
        ok &= seval_to_native_ptr(inst, args[9], &arg9);
        ok &= seval_to_native_ptr(inst, args[10], &arg10);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EllipseBoundingBoxData_ellipseIntersectsSegment : Error processing arguments");
        int result = dragonBones::EllipseBoundingBoxData::ellipseIntersectsSegment(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EllipseBoundingBoxData_ellipseIntersectsSegment : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 11);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_EllipseBoundingBoxData_ellipseIntersectsSegment)

SE_DECLARE_FINALIZE_FUNC(js_dragonBones_EllipseBoundingBoxData_finalize)

static bool js_cocos2dx_dragonbones_EllipseBoundingBoxData_constructor(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::EllipseBoundingBoxData* cobj = new (std::nothrow) dragonBones::EllipseBoundingBoxData();
    s.thisObject(inst)->setPrivateData(cobj);
    inst->getNoneRefNativePtrMap().emplace(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_dragonbones_EllipseBoundingBoxData_constructor, __jsb_dragonBones_EllipseBoundingBoxData_class, js_dragonBones_EllipseBoundingBoxData_finalize)



extern se::Object* __jsb_dragonBones_BoundingBoxData_proto;

static bool js_dragonBones_EllipseBoundingBoxData_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (dragonBones::EllipseBoundingBoxData)", s.nativeThisObject());
    return true;
}
SE_BIND_FINALIZE_FUNC(js_dragonBones_EllipseBoundingBoxData_finalize)

bool js_register_cocos2dx_dragonbones_EllipseBoundingBoxData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "EllipseBoundingBoxData", obj, __jsb_dragonBones_BoundingBoxData_proto, _SE(js_cocos2dx_dragonbones_EllipseBoundingBoxData_constructor));

    cls->defineStaticFunction(inst, "getTypeIndex", _SE(js_cocos2dx_dragonbones_EllipseBoundingBoxData_getTypeIndex));
    cls->defineStaticFunction(inst, "ellipseIntersectsSegment", _SE(js_cocos2dx_dragonbones_EllipseBoundingBoxData_ellipseIntersectsSegment));
    cls->defineFinalizeFunction(_SE(js_dragonBones_EllipseBoundingBoxData_finalize));
    cls->install(inst);
    inst->registerClass<dragonBones::EllipseBoundingBoxData>(cls);

    __jsb_dragonBones_EllipseBoundingBoxData_proto = cls->getProto();
    __jsb_dragonBones_EllipseBoundingBoxData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_PolygonBoundingBoxData_proto = nullptr;
se::Class* __jsb_dragonBones_PolygonBoundingBoxData_class = nullptr;

static bool js_cocos2dx_dragonbones_PolygonBoundingBoxData_getVertices(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::PolygonBoundingBoxData* cobj = (dragonBones::PolygonBoundingBoxData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_PolygonBoundingBoxData_getVertices : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::vector<float>* result = cobj->getVertices();
        ok &= native_ptr_to_seval<std::vector<float>>(inst, (std::vector<float>*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_PolygonBoundingBoxData_getVertices : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_PolygonBoundingBoxData_getVertices)

static bool js_cocos2dx_dragonbones_PolygonBoundingBoxData_getTypeIndex(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        size_t result = dragonBones::PolygonBoundingBoxData::getTypeIndex();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_PolygonBoundingBoxData_getTypeIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_PolygonBoundingBoxData_getTypeIndex)

static bool js_cocos2dx_dragonbones_PolygonBoundingBoxData_polygonIntersectsSegment(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 5) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        std::vector<float> arg4;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_std_vector_float(inst, args[4], &arg4);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_PolygonBoundingBoxData_polygonIntersectsSegment : Error processing arguments");
        int result = dragonBones::PolygonBoundingBoxData::polygonIntersectsSegment(arg0, arg1, arg2, arg3, arg4);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_PolygonBoundingBoxData_polygonIntersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 6) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        std::vector<float> arg4;
        dragonBones::Point* arg5 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_std_vector_float(inst, args[4], &arg4);
        ok &= seval_to_native_ptr(inst, args[5], &arg5);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_PolygonBoundingBoxData_polygonIntersectsSegment : Error processing arguments");
        int result = dragonBones::PolygonBoundingBoxData::polygonIntersectsSegment(arg0, arg1, arg2, arg3, arg4, arg5);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_PolygonBoundingBoxData_polygonIntersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 7) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        std::vector<float> arg4;
        dragonBones::Point* arg5 = 0;
        dragonBones::Point* arg6 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_std_vector_float(inst, args[4], &arg4);
        ok &= seval_to_native_ptr(inst, args[5], &arg5);
        ok &= seval_to_native_ptr(inst, args[6], &arg6);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_PolygonBoundingBoxData_polygonIntersectsSegment : Error processing arguments");
        int result = dragonBones::PolygonBoundingBoxData::polygonIntersectsSegment(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_PolygonBoundingBoxData_polygonIntersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 8) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        std::vector<float> arg4;
        dragonBones::Point* arg5 = 0;
        dragonBones::Point* arg6 = 0;
        dragonBones::Point* arg7 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_std_vector_float(inst, args[4], &arg4);
        ok &= seval_to_native_ptr(inst, args[5], &arg5);
        ok &= seval_to_native_ptr(inst, args[6], &arg6);
        ok &= seval_to_native_ptr(inst, args[7], &arg7);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_PolygonBoundingBoxData_polygonIntersectsSegment : Error processing arguments");
        int result = dragonBones::PolygonBoundingBoxData::polygonIntersectsSegment(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_PolygonBoundingBoxData_polygonIntersectsSegment : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 8);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_PolygonBoundingBoxData_polygonIntersectsSegment)

static bool js_cocos2dx_dragonbones_PolygonBoundingBoxData_get_x(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::PolygonBoundingBoxData* cobj = (dragonBones::PolygonBoundingBoxData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_PolygonBoundingBoxData_get_x : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->x, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_PolygonBoundingBoxData_get_x)

static bool js_cocos2dx_dragonbones_PolygonBoundingBoxData_set_x(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::PolygonBoundingBoxData* cobj = (dragonBones::PolygonBoundingBoxData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_PolygonBoundingBoxData_set_x : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_PolygonBoundingBoxData_set_x : Error processing new value");
    cobj->x = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_PolygonBoundingBoxData_set_x)

static bool js_cocos2dx_dragonbones_PolygonBoundingBoxData_get_y(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::PolygonBoundingBoxData* cobj = (dragonBones::PolygonBoundingBoxData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_PolygonBoundingBoxData_get_y : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->y, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_PolygonBoundingBoxData_get_y)

static bool js_cocos2dx_dragonbones_PolygonBoundingBoxData_set_y(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::PolygonBoundingBoxData* cobj = (dragonBones::PolygonBoundingBoxData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_PolygonBoundingBoxData_set_y : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_PolygonBoundingBoxData_set_y : Error processing new value");
    cobj->y = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_PolygonBoundingBoxData_set_y)

SE_DECLARE_FINALIZE_FUNC(js_dragonBones_PolygonBoundingBoxData_finalize)

static bool js_cocos2dx_dragonbones_PolygonBoundingBoxData_constructor(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::PolygonBoundingBoxData* cobj = new (std::nothrow) dragonBones::PolygonBoundingBoxData();
    s.thisObject(inst)->setPrivateData(cobj);
    inst->getNoneRefNativePtrMap().emplace(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_dragonbones_PolygonBoundingBoxData_constructor, __jsb_dragonBones_PolygonBoundingBoxData_class, js_dragonBones_PolygonBoundingBoxData_finalize)



extern se::Object* __jsb_dragonBones_BoundingBoxData_proto;

static bool js_dragonBones_PolygonBoundingBoxData_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (dragonBones::PolygonBoundingBoxData)", s.nativeThisObject());
    return true;
}
SE_BIND_FINALIZE_FUNC(js_dragonBones_PolygonBoundingBoxData_finalize)

bool js_register_cocos2dx_dragonbones_PolygonBoundingBoxData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "PolygonBoundingBoxData", obj, __jsb_dragonBones_BoundingBoxData_proto, _SE(js_cocos2dx_dragonbones_PolygonBoundingBoxData_constructor));

    cls->defineProperty(inst, "x", _SE(js_cocos2dx_dragonbones_PolygonBoundingBoxData_get_x), _SE(js_cocos2dx_dragonbones_PolygonBoundingBoxData_set_x));
    cls->defineProperty(inst, "y", _SE(js_cocos2dx_dragonbones_PolygonBoundingBoxData_get_y), _SE(js_cocos2dx_dragonbones_PolygonBoundingBoxData_set_y));
    cls->defineFunction(inst, "getVertices", _SE(js_cocos2dx_dragonbones_PolygonBoundingBoxData_getVertices));
    cls->defineStaticFunction(inst, "getTypeIndex", _SE(js_cocos2dx_dragonbones_PolygonBoundingBoxData_getTypeIndex));
    cls->defineStaticFunction(inst, "polygonIntersectsSegment", _SE(js_cocos2dx_dragonbones_PolygonBoundingBoxData_polygonIntersectsSegment));
    cls->defineFinalizeFunction(_SE(js_dragonBones_PolygonBoundingBoxData_finalize));
    cls->install(inst);
    inst->registerClass<dragonBones::PolygonBoundingBoxData>(cls);

    __jsb_dragonBones_PolygonBoundingBoxData_proto = cls->getProto();
    __jsb_dragonBones_PolygonBoundingBoxData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_AnimationData_proto = nullptr;
se::Class* __jsb_dragonBones_AnimationData_class = nullptr;

static bool js_cocos2dx_dragonbones_AnimationData_getActionTimeline(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_getActionTimeline : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::TimelineData* result = cobj->getActionTimeline();
        ok &= native_ptr_to_seval<dragonBones::TimelineData>(inst, (dragonBones::TimelineData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationData_getActionTimeline : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationData_getActionTimeline)

static bool js_cocos2dx_dragonbones_AnimationData_setParent(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_setParent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::ArmatureData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationData_setParent : Error processing arguments");
        cobj->setParent(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationData_setParent)

static bool js_cocos2dx_dragonbones_AnimationData_setActionTimeline(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_setActionTimeline : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::TimelineData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationData_setActionTimeline : Error processing arguments");
        cobj->setActionTimeline(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationData_setActionTimeline)

static bool js_cocos2dx_dragonbones_AnimationData_getSlotCachedFrameIndices(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_getSlotCachedFrameIndices : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationData_getSlotCachedFrameIndices : Error processing arguments");
        std::vector<int>* result = cobj->getSlotCachedFrameIndices(arg0);
        ok &= native_ptr_to_seval<std::vector<int>>(inst, (std::vector<int>*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationData_getSlotCachedFrameIndices : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationData_getSlotCachedFrameIndices)

static bool js_cocos2dx_dragonbones_AnimationData_addConstraintTimeline(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_addConstraintTimeline : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        dragonBones::ConstraintData* arg0 = nullptr;
        dragonBones::TimelineData* arg1 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationData_addConstraintTimeline : Error processing arguments");
        cobj->addConstraintTimeline(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationData_addConstraintTimeline)

static bool js_cocos2dx_dragonbones_AnimationData_getBoneCachedFrameIndices(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_getBoneCachedFrameIndices : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationData_getBoneCachedFrameIndices : Error processing arguments");
        std::vector<int>* result = cobj->getBoneCachedFrameIndices(arg0);
        ok &= native_ptr_to_seval<std::vector<int>>(inst, (std::vector<int>*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationData_getBoneCachedFrameIndices : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationData_getBoneCachedFrameIndices)

static bool js_cocos2dx_dragonbones_AnimationData_getZOrderTimeline(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_getZOrderTimeline : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::TimelineData* result = cobj->getZOrderTimeline();
        ok &= native_ptr_to_seval<dragonBones::TimelineData>(inst, (dragonBones::TimelineData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationData_getZOrderTimeline : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationData_getZOrderTimeline)

static bool js_cocos2dx_dragonbones_AnimationData_setZOrderTimeline(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_setZOrderTimeline : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::TimelineData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationData_setZOrderTimeline : Error processing arguments");
        cobj->setZOrderTimeline(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationData_setZOrderTimeline)

static bool js_cocos2dx_dragonbones_AnimationData_getParent(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_getParent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::ArmatureData* result = cobj->getParent();
        ok &= native_ptr_to_rooted_seval<dragonBones::ArmatureData>(inst, (dragonBones::ArmatureData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationData_getParent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationData_getParent)

static bool js_cocos2dx_dragonbones_AnimationData_get_frameCount(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_get_frameCount : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= uint32_to_seval(inst, cobj->frameCount, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_AnimationData_get_frameCount)

static bool js_cocos2dx_dragonbones_AnimationData_set_frameCount(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_set_frameCount : Invalid Native Object");

    CC_UNUSED bool ok = true;
    unsigned int arg0 = 0;
    ok &= seval_to_uint32(inst, args[0], (uint32_t*)&arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationData_set_frameCount : Error processing new value");
    cobj->frameCount = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_AnimationData_set_frameCount)

static bool js_cocos2dx_dragonbones_AnimationData_get_playTimes(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_get_playTimes : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= uint32_to_seval(inst, cobj->playTimes, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_AnimationData_get_playTimes)

static bool js_cocos2dx_dragonbones_AnimationData_set_playTimes(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_set_playTimes : Invalid Native Object");

    CC_UNUSED bool ok = true;
    unsigned int arg0 = 0;
    ok &= seval_to_uint32(inst, args[0], (uint32_t*)&arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationData_set_playTimes : Error processing new value");
    cobj->playTimes = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_AnimationData_set_playTimes)

static bool js_cocos2dx_dragonbones_AnimationData_get_duration(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_get_duration : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->duration, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_AnimationData_get_duration)

static bool js_cocos2dx_dragonbones_AnimationData_set_duration(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_set_duration : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationData_set_duration : Error processing new value");
    cobj->duration = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_AnimationData_set_duration)

static bool js_cocos2dx_dragonbones_AnimationData_get_fadeInTime(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_get_fadeInTime : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->fadeInTime, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_AnimationData_get_fadeInTime)

static bool js_cocos2dx_dragonbones_AnimationData_set_fadeInTime(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_set_fadeInTime : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationData_set_fadeInTime : Error processing new value");
    cobj->fadeInTime = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_AnimationData_set_fadeInTime)

static bool js_cocos2dx_dragonbones_AnimationData_get_name(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_get_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= std_string_to_seval(inst, cobj->name, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_AnimationData_get_name)

static bool js_cocos2dx_dragonbones_AnimationData_set_name(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationData_set_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    std::string arg0;
    ok &= seval_to_std_string(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationData_set_name : Error processing new value");
    cobj->name = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_AnimationData_set_name)




bool js_register_cocos2dx_dragonbones_AnimationData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "AnimationData", obj, nullptr, nullptr);

    cls->defineProperty(inst, "frameCount", _SE(js_cocos2dx_dragonbones_AnimationData_get_frameCount), _SE(js_cocos2dx_dragonbones_AnimationData_set_frameCount));
    cls->defineProperty(inst, "playTimes", _SE(js_cocos2dx_dragonbones_AnimationData_get_playTimes), _SE(js_cocos2dx_dragonbones_AnimationData_set_playTimes));
    cls->defineProperty(inst, "duration", _SE(js_cocos2dx_dragonbones_AnimationData_get_duration), _SE(js_cocos2dx_dragonbones_AnimationData_set_duration));
    cls->defineProperty(inst, "fadeInTime", _SE(js_cocos2dx_dragonbones_AnimationData_get_fadeInTime), _SE(js_cocos2dx_dragonbones_AnimationData_set_fadeInTime));
    cls->defineProperty(inst, "name", _SE(js_cocos2dx_dragonbones_AnimationData_get_name), _SE(js_cocos2dx_dragonbones_AnimationData_set_name));
    cls->defineFunction(inst, "getActionTimeline", _SE(js_cocos2dx_dragonbones_AnimationData_getActionTimeline));
    cls->defineFunction(inst, "setParent", _SE(js_cocos2dx_dragonbones_AnimationData_setParent));
    cls->defineFunction(inst, "setActionTimeline", _SE(js_cocos2dx_dragonbones_AnimationData_setActionTimeline));
    cls->defineFunction(inst, "getSlotCachedFrameIndices", _SE(js_cocos2dx_dragonbones_AnimationData_getSlotCachedFrameIndices));
    cls->defineFunction(inst, "addConstraintTimeline", _SE(js_cocos2dx_dragonbones_AnimationData_addConstraintTimeline));
    cls->defineFunction(inst, "getBoneCachedFrameIndices", _SE(js_cocos2dx_dragonbones_AnimationData_getBoneCachedFrameIndices));
    cls->defineFunction(inst, "getZOrderTimeline", _SE(js_cocos2dx_dragonbones_AnimationData_getZOrderTimeline));
    cls->defineFunction(inst, "setZOrderTimeline", _SE(js_cocos2dx_dragonbones_AnimationData_setZOrderTimeline));
    cls->defineFunction(inst, "getParent", _SE(js_cocos2dx_dragonbones_AnimationData_getParent));
    cls->install(inst);
    inst->registerClass<dragonBones::AnimationData>(cls);

    __jsb_dragonBones_AnimationData_proto = cls->getProto();
    __jsb_dragonBones_AnimationData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_Armature_proto = nullptr;
se::Class* __jsb_dragonBones_Armature_class = nullptr;

static bool js_cocos2dx_dragonbones_Armature_getBone(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_getBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getBone : Error processing arguments");
        dragonBones::Bone* result = cobj->getBone(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::Bone>(inst, (dragonBones::Bone*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getBone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getBone)

static bool js_cocos2dx_dragonbones_Armature_getClock(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_getClock : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::WorldClock* result = cobj->getClock();
        ok &= native_ptr_to_rooted_seval<dragonBones::WorldClock>(inst, (dragonBones::WorldClock*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getClock : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getClock)

static bool js_cocos2dx_dragonbones_Armature_render(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_render : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->render();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_render)

static bool js_cocos2dx_dragonbones_Armature_getSlot(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_getSlot : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getSlot : Error processing arguments");
        dragonBones::Slot* result = cobj->getSlot(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::Slot>(inst, (dragonBones::Slot*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getSlot : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getSlot)

static bool js_cocos2dx_dragonbones_Armature_setClock(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_setClock : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::WorldClock* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_setClock : Error processing arguments");
        cobj->setClock(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_setClock)

static bool js_cocos2dx_dragonbones_Armature__bufferAction(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature__bufferAction : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        dragonBones::EventObject* arg0 = nullptr;
        bool arg1;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_boolean(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature__bufferAction : Error processing arguments");
        cobj->_bufferAction(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature__bufferAction)

static bool js_cocos2dx_dragonbones_Armature__addBone(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature__addBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::Bone* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature__addBone : Error processing arguments");
        cobj->_addBone(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature__addBone)

static bool js_cocos2dx_dragonbones_Armature_getAnimatable(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_getAnimatable : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::IAnimatable* result = cobj->getAnimatable();
        ok &= native_ptr_to_seval<dragonBones::IAnimatable>(inst, (dragonBones::IAnimatable*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getAnimatable : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getAnimatable)

static bool js_cocos2dx_dragonbones_Armature_getName(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_getName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cobj->getName();
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getName)

static bool js_cocos2dx_dragonbones_Armature_dispose(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_dispose : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->dispose();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_dispose)

static bool js_cocos2dx_dragonbones_Armature_invalidUpdate(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_invalidUpdate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cobj->invalidUpdate();
        return true;
    }
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_invalidUpdate : Error processing arguments");
        cobj->invalidUpdate(arg0);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_boolean(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_invalidUpdate : Error processing arguments");
        cobj->invalidUpdate(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_invalidUpdate)

static bool js_cocos2dx_dragonbones_Armature_getCacheFrameRate(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_getCacheFrameRate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = cobj->getCacheFrameRate();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getCacheFrameRate : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getCacheFrameRate)

static bool js_cocos2dx_dragonbones_Armature_getFlipY(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_getFlipY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getFlipY();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getFlipY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getFlipY)

static bool js_cocos2dx_dragonbones_Armature_getFlipX(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_getFlipX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getFlipX();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getFlipX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getFlipX)

static bool js_cocos2dx_dragonbones_Armature_intersectsSegment(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_intersectsSegment : Invalid Native Object");
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
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_intersectsSegment : Error processing arguments");
        dragonBones::Slot* result = cobj->intersectsSegment(arg0, arg1, arg2, arg3);
        ok &= native_ptr_to_rooted_seval<dragonBones::Slot>(inst, (dragonBones::Slot*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_intersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 5) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        dragonBones::Point* arg4 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_native_ptr(inst, args[4], &arg4);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_intersectsSegment : Error processing arguments");
        dragonBones::Slot* result = cobj->intersectsSegment(arg0, arg1, arg2, arg3, arg4);
        ok &= native_ptr_to_rooted_seval<dragonBones::Slot>(inst, (dragonBones::Slot*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_intersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 6) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        dragonBones::Point* arg4 = 0;
        dragonBones::Point* arg5 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_native_ptr(inst, args[4], &arg4);
        ok &= seval_to_native_ptr(inst, args[5], &arg5);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_intersectsSegment : Error processing arguments");
        dragonBones::Slot* result = cobj->intersectsSegment(arg0, arg1, arg2, arg3, arg4, arg5);
        ok &= native_ptr_to_rooted_seval<dragonBones::Slot>(inst, (dragonBones::Slot*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_intersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 7) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        dragonBones::Point* arg4 = 0;
        dragonBones::Point* arg5 = 0;
        dragonBones::Point* arg6 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_native_ptr(inst, args[4], &arg4);
        ok &= seval_to_native_ptr(inst, args[5], &arg5);
        ok &= seval_to_native_ptr(inst, args[6], &arg6);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_intersectsSegment : Error processing arguments");
        dragonBones::Slot* result = cobj->intersectsSegment(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        ok &= native_ptr_to_rooted_seval<dragonBones::Slot>(inst, (dragonBones::Slot*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_intersectsSegment : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 7);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_intersectsSegment)

static bool js_cocos2dx_dragonbones_Armature_setCacheFrameRate(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_setCacheFrameRate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= seval_to_uint32(inst, args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_setCacheFrameRate : Error processing arguments");
        cobj->setCacheFrameRate(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_setCacheFrameRate)

static bool js_cocos2dx_dragonbones_Armature__addConstraint(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature__addConstraint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::Constraint* arg0 = 0;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature__addConstraint : Error processing arguments");
        cobj->_addConstraint(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature__addConstraint)

static bool js_cocos2dx_dragonbones_Armature_setFlipY(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_setFlipY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_setFlipY : Error processing arguments");
        cobj->setFlipY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_setFlipY)

static bool js_cocos2dx_dragonbones_Armature_setFlipX(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_setFlipX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_setFlipX : Error processing arguments");
        cobj->setFlipX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_setFlipX)

static bool js_cocos2dx_dragonbones_Armature__addSlot(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature__addSlot : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::Slot* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature__addSlot : Error processing arguments");
        cobj->_addSlot(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature__addSlot)

static bool js_cocos2dx_dragonbones_Armature_advanceTime(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_advanceTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_advanceTime : Error processing arguments");
        cobj->advanceTime(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_advanceTime)

static bool js_cocos2dx_dragonbones_Armature_getAnimation(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_getAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Animation* result = cobj->getAnimation();
        ok &= native_ptr_to_rooted_seval<dragonBones::Animation>(inst, (dragonBones::Animation*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getAnimation)

static bool js_cocos2dx_dragonbones_Armature_getParent(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_getParent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Slot* result = cobj->getParent();
        ok &= native_ptr_to_rooted_seval<dragonBones::Slot>(inst, (dragonBones::Slot*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getParent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getParent)

static bool js_cocos2dx_dragonbones_Armature_getArmatureData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_getArmatureData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const dragonBones::ArmatureData* result = cobj->getArmatureData();
        ok &= native_ptr_to_rooted_seval<dragonBones::ArmatureData>(inst, (dragonBones::ArmatureData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getArmatureData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getArmatureData)

static bool js_cocos2dx_dragonbones_Armature_getEventDispatcher(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_getEventDispatcher : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::IEventDispatcher* result = cobj->getEventDispatcher();
        ok &= native_ptr_to_seval<dragonBones::IEventDispatcher>(inst, (dragonBones::IEventDispatcher*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getEventDispatcher : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getEventDispatcher)

static bool js_cocos2dx_dragonbones_Armature_containsPoint(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_containsPoint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_containsPoint : Error processing arguments");
        dragonBones::Slot* result = cobj->containsPoint(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<dragonBones::Slot>(inst, (dragonBones::Slot*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_containsPoint : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_containsPoint)

static bool js_cocos2dx_dragonbones_Armature_getProxy(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Armature_getProxy : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::IArmatureProxy* result = cobj->getProxy();
        ok &= native_ptr_to_seval<dragonBones::IArmatureProxy>(inst, (dragonBones::IArmatureProxy*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Armature_getProxy : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getProxy)


extern se::Object* __jsb_dragonBones_BaseObject_proto;


bool js_register_cocos2dx_dragonbones_Armature(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Armature", obj, __jsb_dragonBones_BaseObject_proto, nullptr);

    cls->defineFunction(inst, "getBone", _SE(js_cocos2dx_dragonbones_Armature_getBone));
    cls->defineFunction(inst, "getClock", _SE(js_cocos2dx_dragonbones_Armature_getClock));
    cls->defineFunction(inst, "render", _SE(js_cocos2dx_dragonbones_Armature_render));
    cls->defineFunction(inst, "getSlot", _SE(js_cocos2dx_dragonbones_Armature_getSlot));
    cls->defineFunction(inst, "setClock", _SE(js_cocos2dx_dragonbones_Armature_setClock));
    cls->defineFunction(inst, "_bufferAction", _SE(js_cocos2dx_dragonbones_Armature__bufferAction));
    cls->defineFunction(inst, "_addBone", _SE(js_cocos2dx_dragonbones_Armature__addBone));
    cls->defineFunction(inst, "getAnimatable", _SE(js_cocos2dx_dragonbones_Armature_getAnimatable));
    cls->defineFunction(inst, "getName", _SE(js_cocos2dx_dragonbones_Armature_getName));
    cls->defineFunction(inst, "dispose", _SE(js_cocos2dx_dragonbones_Armature_dispose));
    cls->defineFunction(inst, "invalidUpdate", _SE(js_cocos2dx_dragonbones_Armature_invalidUpdate));
    cls->defineFunction(inst, "getCacheFrameRate", _SE(js_cocos2dx_dragonbones_Armature_getCacheFrameRate));
    cls->defineFunction(inst, "getFlipY", _SE(js_cocos2dx_dragonbones_Armature_getFlipY));
    cls->defineFunction(inst, "getFlipX", _SE(js_cocos2dx_dragonbones_Armature_getFlipX));
    cls->defineFunction(inst, "intersectsSegment", _SE(js_cocos2dx_dragonbones_Armature_intersectsSegment));
    cls->defineFunction(inst, "setCacheFrameRate", _SE(js_cocos2dx_dragonbones_Armature_setCacheFrameRate));
    cls->defineFunction(inst, "_addConstraint", _SE(js_cocos2dx_dragonbones_Armature__addConstraint));
    cls->defineFunction(inst, "setFlipY", _SE(js_cocos2dx_dragonbones_Armature_setFlipY));
    cls->defineFunction(inst, "setFlipX", _SE(js_cocos2dx_dragonbones_Armature_setFlipX));
    cls->defineFunction(inst, "_addSlot", _SE(js_cocos2dx_dragonbones_Armature__addSlot));
    cls->defineFunction(inst, "advanceTime", _SE(js_cocos2dx_dragonbones_Armature_advanceTime));
    cls->defineFunction(inst, "getAnimation", _SE(js_cocos2dx_dragonbones_Armature_getAnimation));
    cls->defineFunction(inst, "getParent", _SE(js_cocos2dx_dragonbones_Armature_getParent));
    cls->defineFunction(inst, "getArmatureData", _SE(js_cocos2dx_dragonbones_Armature_getArmatureData));
    cls->defineFunction(inst, "getEventDispatcher", _SE(js_cocos2dx_dragonbones_Armature_getEventDispatcher));
    cls->defineFunction(inst, "containsPoint", _SE(js_cocos2dx_dragonbones_Armature_containsPoint));
    cls->defineFunction(inst, "getProxy", _SE(js_cocos2dx_dragonbones_Armature_getProxy));
    cls->install(inst);
    inst->registerClass<dragonBones::Armature>(cls);

    __jsb_dragonBones_Armature_proto = cls->getProto();
    __jsb_dragonBones_Armature_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_TransformObject_proto = nullptr;
se::Class* __jsb_dragonBones_TransformObject_class = nullptr;

static bool js_cocos2dx_dragonbones_TransformObject_getOffset(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::TransformObject* cobj = (dragonBones::TransformObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_TransformObject_getOffset : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Transform* result = cobj->getOffset();
        ok &= native_ptr_to_rooted_seval<dragonBones::Transform>(inst, (dragonBones::Transform*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_TransformObject_getOffset : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_TransformObject_getOffset)

static bool js_cocos2dx_dragonbones_TransformObject_getGlobal(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::TransformObject* cobj = (dragonBones::TransformObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_TransformObject_getGlobal : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Transform* result = cobj->getGlobal();
        ok &= native_ptr_to_rooted_seval<dragonBones::Transform>(inst, (dragonBones::Transform*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_TransformObject_getGlobal : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_TransformObject_getGlobal)

static bool js_cocos2dx_dragonbones_TransformObject_getOrigin(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::TransformObject* cobj = (dragonBones::TransformObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_TransformObject_getOrigin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const dragonBones::Transform* result = cobj->getOrigin();
        ok &= native_ptr_to_rooted_seval<dragonBones::Transform>(inst, (dragonBones::Transform*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_TransformObject_getOrigin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_TransformObject_getOrigin)

static bool js_cocos2dx_dragonbones_TransformObject_getGlobalTransformMatrix(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::TransformObject* cobj = (dragonBones::TransformObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_TransformObject_getGlobalTransformMatrix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Matrix* result = cobj->getGlobalTransformMatrix();
        ok &= native_ptr_to_rooted_seval<dragonBones::Matrix>(inst, (dragonBones::Matrix*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_TransformObject_getGlobalTransformMatrix : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_TransformObject_getGlobalTransformMatrix)

static bool js_cocos2dx_dragonbones_TransformObject_getArmature(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::TransformObject* cobj = (dragonBones::TransformObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_TransformObject_getArmature : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Armature* result = cobj->getArmature();
        ok &= native_ptr_to_rooted_seval<dragonBones::Armature>(inst, (dragonBones::Armature*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_TransformObject_getArmature : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_TransformObject_getArmature)

static bool js_cocos2dx_dragonbones_TransformObject_updateGlobalTransform(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::TransformObject* cobj = (dragonBones::TransformObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_TransformObject_updateGlobalTransform : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->updateGlobalTransform();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_TransformObject_updateGlobalTransform)


extern se::Object* __jsb_dragonBones_BaseObject_proto;


bool js_register_cocos2dx_dragonbones_TransformObject(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "TransformObject", obj, __jsb_dragonBones_BaseObject_proto, nullptr);

    cls->defineFunction(inst, "getOffset", _SE(js_cocos2dx_dragonbones_TransformObject_getOffset));
    cls->defineFunction(inst, "getGlobal", _SE(js_cocos2dx_dragonbones_TransformObject_getGlobal));
    cls->defineFunction(inst, "getOrigin", _SE(js_cocos2dx_dragonbones_TransformObject_getOrigin));
    cls->defineFunction(inst, "getGlobalTransformMatrix", _SE(js_cocos2dx_dragonbones_TransformObject_getGlobalTransformMatrix));
    cls->defineFunction(inst, "getArmature", _SE(js_cocos2dx_dragonbones_TransformObject_getArmature));
    cls->defineFunction(inst, "updateGlobalTransform", _SE(js_cocos2dx_dragonbones_TransformObject_updateGlobalTransform));
    cls->install(inst);
    inst->registerClass<dragonBones::TransformObject>(cls);

    __jsb_dragonBones_TransformObject_proto = cls->getProto();
    __jsb_dragonBones_TransformObject_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_AnimationState_proto = nullptr;
se::Class* __jsb_dragonBones_AnimationState_class = nullptr;

static bool js_cocos2dx_dragonbones_AnimationState_isCompleted(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_isCompleted : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isCompleted();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_isCompleted : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_isCompleted)

static bool js_cocos2dx_dragonbones_AnimationState_play(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_play : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->play();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_play)

static bool js_cocos2dx_dragonbones_AnimationState_fadeOut(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_fadeOut : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_fadeOut : Error processing arguments");
        cobj->fadeOut(arg0);
        return true;
    }
    if (argc == 2) {
        float arg0 = 0;
        bool arg1;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_boolean(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_fadeOut : Error processing arguments");
        cobj->fadeOut(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_fadeOut)

static bool js_cocos2dx_dragonbones_AnimationState_getName(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_getName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cobj->getName();
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_getName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_getName)

static bool js_cocos2dx_dragonbones_AnimationState_stop(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_stop : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->stop();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_stop)

static bool js_cocos2dx_dragonbones_AnimationState_setCurrentTime(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_setCurrentTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_setCurrentTime : Error processing arguments");
        cobj->setCurrentTime(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_setCurrentTime)

static bool js_cocos2dx_dragonbones_AnimationState_getCurrentTime(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_getCurrentTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getCurrentTime();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_getCurrentTime : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_getCurrentTime)

static bool js_cocos2dx_dragonbones_AnimationState_getTotalTime(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_getTotalTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTotalTime();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_getTotalTime : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_getTotalTime)

static bool js_cocos2dx_dragonbones_AnimationState_init(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        dragonBones::Armature* arg0 = nullptr;
        dragonBones::AnimationData* arg1 = nullptr;
        dragonBones::AnimationConfig* arg2 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        ok &= seval_to_native_ptr(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_init : Error processing arguments");
        cobj->init(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_init)

static bool js_cocos2dx_dragonbones_AnimationState_isFadeIn(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_isFadeIn : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isFadeIn();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_isFadeIn : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_isFadeIn)

static bool js_cocos2dx_dragonbones_AnimationState_addBoneMask(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_addBoneMask : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_addBoneMask : Error processing arguments");
        cobj->addBoneMask(arg0);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_boolean(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_addBoneMask : Error processing arguments");
        cobj->addBoneMask(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_addBoneMask)

static bool js_cocos2dx_dragonbones_AnimationState_containsBoneMask(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_containsBoneMask : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_containsBoneMask : Error processing arguments");
        bool result = cobj->containsBoneMask(arg0);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_containsBoneMask : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_containsBoneMask)

static bool js_cocos2dx_dragonbones_AnimationState_removeAllBoneMask(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_removeAllBoneMask : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->removeAllBoneMask();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_removeAllBoneMask)

static bool js_cocos2dx_dragonbones_AnimationState_getAnimationData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_getAnimationData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const dragonBones::AnimationData* result = cobj->getAnimationData();
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationData>(inst, (dragonBones::AnimationData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_getAnimationData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_getAnimationData)

static bool js_cocos2dx_dragonbones_AnimationState_isFadeComplete(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_isFadeComplete : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isFadeComplete();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_isFadeComplete : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_isFadeComplete)

static bool js_cocos2dx_dragonbones_AnimationState_advanceTime(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_advanceTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_advanceTime : Error processing arguments");
        cobj->advanceTime(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_advanceTime)

static bool js_cocos2dx_dragonbones_AnimationState_isPlaying(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_isPlaying : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isPlaying();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_isPlaying : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_isPlaying)

static bool js_cocos2dx_dragonbones_AnimationState_removeBoneMask(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_removeBoneMask : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_removeBoneMask : Error processing arguments");
        cobj->removeBoneMask(arg0);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_boolean(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_removeBoneMask : Error processing arguments");
        cobj->removeBoneMask(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_removeBoneMask)

static bool js_cocos2dx_dragonbones_AnimationState_getCurrentPlayTimes(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_getCurrentPlayTimes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = cobj->getCurrentPlayTimes();
        ok &= uint32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_getCurrentPlayTimes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_getCurrentPlayTimes)

static bool js_cocos2dx_dragonbones_AnimationState_isFadeOut(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_isFadeOut : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isFadeOut();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_isFadeOut : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_isFadeOut)

static bool js_cocos2dx_dragonbones_AnimationState_get_additiveBlending(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_get_additiveBlending : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= boolean_to_seval(inst, cobj->additiveBlending, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_AnimationState_get_additiveBlending)

static bool js_cocos2dx_dragonbones_AnimationState_set_additiveBlending(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_set_additiveBlending : Invalid Native Object");

    CC_UNUSED bool ok = true;
    bool arg0;
    ok &= seval_to_boolean(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_set_additiveBlending : Error processing new value");
    cobj->additiveBlending = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_AnimationState_set_additiveBlending)

static bool js_cocos2dx_dragonbones_AnimationState_get_displayControl(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_get_displayControl : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= boolean_to_seval(inst, cobj->displayControl, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_AnimationState_get_displayControl)

static bool js_cocos2dx_dragonbones_AnimationState_set_displayControl(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_set_displayControl : Invalid Native Object");

    CC_UNUSED bool ok = true;
    bool arg0;
    ok &= seval_to_boolean(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_set_displayControl : Error processing new value");
    cobj->displayControl = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_AnimationState_set_displayControl)

static bool js_cocos2dx_dragonbones_AnimationState_get_playTimes(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_get_playTimes : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= uint32_to_seval(inst, cobj->playTimes, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_AnimationState_get_playTimes)

static bool js_cocos2dx_dragonbones_AnimationState_set_playTimes(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_set_playTimes : Invalid Native Object");

    CC_UNUSED bool ok = true;
    unsigned int arg0 = 0;
    ok &= seval_to_uint32(inst, args[0], (uint32_t*)&arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_set_playTimes : Error processing new value");
    cobj->playTimes = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_AnimationState_set_playTimes)

static bool js_cocos2dx_dragonbones_AnimationState_get_timeScale(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_get_timeScale : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->timeScale, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_AnimationState_get_timeScale)

static bool js_cocos2dx_dragonbones_AnimationState_set_timeScale(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_set_timeScale : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_set_timeScale : Error processing new value");
    cobj->timeScale = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_AnimationState_set_timeScale)

static bool js_cocos2dx_dragonbones_AnimationState_get_weight(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_get_weight : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->weight, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_AnimationState_get_weight)

static bool js_cocos2dx_dragonbones_AnimationState_set_weight(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_set_weight : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_set_weight : Error processing new value");
    cobj->weight = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_AnimationState_set_weight)

static bool js_cocos2dx_dragonbones_AnimationState_get_autoFadeOutTime(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_get_autoFadeOutTime : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->autoFadeOutTime, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_AnimationState_get_autoFadeOutTime)

static bool js_cocos2dx_dragonbones_AnimationState_set_autoFadeOutTime(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_set_autoFadeOutTime : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_set_autoFadeOutTime : Error processing new value");
    cobj->autoFadeOutTime = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_AnimationState_set_autoFadeOutTime)

static bool js_cocos2dx_dragonbones_AnimationState_get_fadeTotalTime(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_get_fadeTotalTime : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->fadeTotalTime, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_AnimationState_get_fadeTotalTime)

static bool js_cocos2dx_dragonbones_AnimationState_set_fadeTotalTime(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_set_fadeTotalTime : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_set_fadeTotalTime : Error processing new value");
    cobj->fadeTotalTime = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_AnimationState_set_fadeTotalTime)

static bool js_cocos2dx_dragonbones_AnimationState_get_name(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_get_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= std_string_to_seval(inst, cobj->name, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_AnimationState_get_name)

static bool js_cocos2dx_dragonbones_AnimationState_set_name(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AnimationState_set_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    std::string arg0;
    ok &= seval_to_std_string(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AnimationState_set_name : Error processing new value");
    cobj->name = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_AnimationState_set_name)


extern se::Object* __jsb_dragonBones_BaseObject_proto;


bool js_register_cocos2dx_dragonbones_AnimationState(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "AnimationState", obj, __jsb_dragonBones_BaseObject_proto, nullptr);

    cls->defineProperty(inst, "additiveBlending", _SE(js_cocos2dx_dragonbones_AnimationState_get_additiveBlending), _SE(js_cocos2dx_dragonbones_AnimationState_set_additiveBlending));
    cls->defineProperty(inst, "displayControl", _SE(js_cocos2dx_dragonbones_AnimationState_get_displayControl), _SE(js_cocos2dx_dragonbones_AnimationState_set_displayControl));
    cls->defineProperty(inst, "playTimes", _SE(js_cocos2dx_dragonbones_AnimationState_get_playTimes), _SE(js_cocos2dx_dragonbones_AnimationState_set_playTimes));
    cls->defineProperty(inst, "timeScale", _SE(js_cocos2dx_dragonbones_AnimationState_get_timeScale), _SE(js_cocos2dx_dragonbones_AnimationState_set_timeScale));
    cls->defineProperty(inst, "weight", _SE(js_cocos2dx_dragonbones_AnimationState_get_weight), _SE(js_cocos2dx_dragonbones_AnimationState_set_weight));
    cls->defineProperty(inst, "autoFadeOutTime", _SE(js_cocos2dx_dragonbones_AnimationState_get_autoFadeOutTime), _SE(js_cocos2dx_dragonbones_AnimationState_set_autoFadeOutTime));
    cls->defineProperty(inst, "fadeTotalTime", _SE(js_cocos2dx_dragonbones_AnimationState_get_fadeTotalTime), _SE(js_cocos2dx_dragonbones_AnimationState_set_fadeTotalTime));
    cls->defineProperty(inst, "name", _SE(js_cocos2dx_dragonbones_AnimationState_get_name), _SE(js_cocos2dx_dragonbones_AnimationState_set_name));
    cls->defineFunction(inst, "isCompleted", _SE(js_cocos2dx_dragonbones_AnimationState_isCompleted));
    cls->defineFunction(inst, "play", _SE(js_cocos2dx_dragonbones_AnimationState_play));
    cls->defineFunction(inst, "fadeOut", _SE(js_cocos2dx_dragonbones_AnimationState_fadeOut));
    cls->defineFunction(inst, "getName", _SE(js_cocos2dx_dragonbones_AnimationState_getName));
    cls->defineFunction(inst, "stop", _SE(js_cocos2dx_dragonbones_AnimationState_stop));
    cls->defineFunction(inst, "setCurrentTime", _SE(js_cocos2dx_dragonbones_AnimationState_setCurrentTime));
    cls->defineFunction(inst, "getCurrentTime", _SE(js_cocos2dx_dragonbones_AnimationState_getCurrentTime));
    cls->defineFunction(inst, "getTotalTime", _SE(js_cocos2dx_dragonbones_AnimationState_getTotalTime));
    cls->defineFunction(inst, "init", _SE(js_cocos2dx_dragonbones_AnimationState_init));
    cls->defineFunction(inst, "isFadeIn", _SE(js_cocos2dx_dragonbones_AnimationState_isFadeIn));
    cls->defineFunction(inst, "addBoneMask", _SE(js_cocos2dx_dragonbones_AnimationState_addBoneMask));
    cls->defineFunction(inst, "containsBoneMask", _SE(js_cocos2dx_dragonbones_AnimationState_containsBoneMask));
    cls->defineFunction(inst, "removeAllBoneMask", _SE(js_cocos2dx_dragonbones_AnimationState_removeAllBoneMask));
    cls->defineFunction(inst, "getAnimationData", _SE(js_cocos2dx_dragonbones_AnimationState_getAnimationData));
    cls->defineFunction(inst, "isFadeComplete", _SE(js_cocos2dx_dragonbones_AnimationState_isFadeComplete));
    cls->defineFunction(inst, "advanceTime", _SE(js_cocos2dx_dragonbones_AnimationState_advanceTime));
    cls->defineFunction(inst, "isPlaying", _SE(js_cocos2dx_dragonbones_AnimationState_isPlaying));
    cls->defineFunction(inst, "removeBoneMask", _SE(js_cocos2dx_dragonbones_AnimationState_removeBoneMask));
    cls->defineFunction(inst, "getCurrentPlayTimes", _SE(js_cocos2dx_dragonbones_AnimationState_getCurrentPlayTimes));
    cls->defineFunction(inst, "isFadeOut", _SE(js_cocos2dx_dragonbones_AnimationState_isFadeOut));
    cls->install(inst);
    inst->registerClass<dragonBones::AnimationState>(cls);

    __jsb_dragonBones_AnimationState_proto = cls->getProto();
    __jsb_dragonBones_AnimationState_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_Bone_proto = nullptr;
se::Class* __jsb_dragonBones_Bone_class = nullptr;

static bool js_cocos2dx_dragonbones_Bone_getOffsetMode(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Bone* cobj = (dragonBones::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Bone_getOffsetMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getOffsetMode();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Bone_getOffsetMode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Bone_getOffsetMode)

static bool js_cocos2dx_dragonbones_Bone_getParent(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Bone* cobj = (dragonBones::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Bone_getParent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Bone* result = cobj->getParent();
        ok &= native_ptr_to_rooted_seval<dragonBones::Bone>(inst, (dragonBones::Bone*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Bone_getParent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Bone_getParent)

static bool js_cocos2dx_dragonbones_Bone_getName(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Bone* cobj = (dragonBones::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Bone_getName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cobj->getName();
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Bone_getName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Bone_getName)

static bool js_cocos2dx_dragonbones_Bone_contains(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Bone* cobj = (dragonBones::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Bone_contains : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const dragonBones::Bone* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Bone_contains : Error processing arguments");
        bool result = cobj->contains(arg0);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Bone_contains : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Bone_contains)

static bool js_cocos2dx_dragonbones_Bone_update(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Bone* cobj = (dragonBones::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Bone_update : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Bone_update : Error processing arguments");
        cobj->update(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Bone_update)

static bool js_cocos2dx_dragonbones_Bone_updateByConstraint(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Bone* cobj = (dragonBones::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Bone_updateByConstraint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->updateByConstraint();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Bone_updateByConstraint)

static bool js_cocos2dx_dragonbones_Bone_getVisible(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Bone* cobj = (dragonBones::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Bone_getVisible : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getVisible();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Bone_getVisible : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Bone_getVisible)

static bool js_cocos2dx_dragonbones_Bone_init(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Bone* cobj = (dragonBones::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Bone_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const dragonBones::BoneData* arg0 = nullptr;
        dragonBones::Armature* arg1 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Bone_init : Error processing arguments");
        cobj->init(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Bone_init)

static bool js_cocos2dx_dragonbones_Bone_invalidUpdate(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Bone* cobj = (dragonBones::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Bone_invalidUpdate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->invalidUpdate();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Bone_invalidUpdate)

static bool js_cocos2dx_dragonbones_Bone_setOffsetMode(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Bone* cobj = (dragonBones::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Bone_setOffsetMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Bone_setOffsetMode : Error processing arguments");
        cobj->setOffsetMode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Bone_setOffsetMode)

static bool js_cocos2dx_dragonbones_Bone_setVisible(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Bone* cobj = (dragonBones::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Bone_setVisible : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Bone_setVisible : Error processing arguments");
        cobj->setVisible(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Bone_setVisible)

static bool js_cocos2dx_dragonbones_Bone_getBoneData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Bone* cobj = (dragonBones::Bone*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Bone_getBoneData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const dragonBones::BoneData* result = cobj->getBoneData();
        ok &= native_ptr_to_rooted_seval<dragonBones::BoneData>(inst, (dragonBones::BoneData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Bone_getBoneData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Bone_getBoneData)


extern se::Object* __jsb_dragonBones_TransformObject_proto;


bool js_register_cocos2dx_dragonbones_Bone(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Bone", obj, __jsb_dragonBones_TransformObject_proto, nullptr);

    cls->defineFunction(inst, "getOffsetMode", _SE(js_cocos2dx_dragonbones_Bone_getOffsetMode));
    cls->defineFunction(inst, "getParent", _SE(js_cocos2dx_dragonbones_Bone_getParent));
    cls->defineFunction(inst, "getName", _SE(js_cocos2dx_dragonbones_Bone_getName));
    cls->defineFunction(inst, "contains", _SE(js_cocos2dx_dragonbones_Bone_contains));
    cls->defineFunction(inst, "update", _SE(js_cocos2dx_dragonbones_Bone_update));
    cls->defineFunction(inst, "updateByConstraint", _SE(js_cocos2dx_dragonbones_Bone_updateByConstraint));
    cls->defineFunction(inst, "getVisible", _SE(js_cocos2dx_dragonbones_Bone_getVisible));
    cls->defineFunction(inst, "init", _SE(js_cocos2dx_dragonbones_Bone_init));
    cls->defineFunction(inst, "invalidUpdate", _SE(js_cocos2dx_dragonbones_Bone_invalidUpdate));
    cls->defineFunction(inst, "setOffsetMode", _SE(js_cocos2dx_dragonbones_Bone_setOffsetMode));
    cls->defineFunction(inst, "setVisible", _SE(js_cocos2dx_dragonbones_Bone_setVisible));
    cls->defineFunction(inst, "getBoneData", _SE(js_cocos2dx_dragonbones_Bone_getBoneData));
    cls->install(inst);
    inst->registerClass<dragonBones::Bone>(cls);

    __jsb_dragonBones_Bone_proto = cls->getProto();
    __jsb_dragonBones_Bone_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_Slot_proto = nullptr;
se::Class* __jsb_dragonBones_Slot_class = nullptr;

static bool js_cocos2dx_dragonbones_Slot__updateColor(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot__updateColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->_updateColor();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot__updateColor)

static bool js_cocos2dx_dragonbones_Slot_setRawDisplayDatas(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_setRawDisplayDatas : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const std::vector<dragonBones::DisplayData *>* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_setRawDisplayDatas : Error processing arguments");
        cobj->setRawDisplayDatas(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_setRawDisplayDatas)

static bool js_cocos2dx_dragonbones_Slot_getVisible(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_getVisible : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getVisible();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_getVisible : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_getVisible)

static bool js_cocos2dx_dragonbones_Slot_getSlotData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_getSlotData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const dragonBones::SlotData* result = cobj->getSlotData();
        ok &= native_ptr_to_rooted_seval<dragonBones::SlotData>(inst, (dragonBones::SlotData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_getSlotData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_getSlotData)

static bool js_cocos2dx_dragonbones_Slot_getName(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_getName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cobj->getName();
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_getName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_getName)

static bool js_cocos2dx_dragonbones_Slot__setZorder(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot__setZorder : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot__setZorder : Error processing arguments");
        bool result = cobj->_setZorder(arg0);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot__setZorder : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot__setZorder)

static bool js_cocos2dx_dragonbones_Slot_invalidUpdate(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_invalidUpdate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->invalidUpdate();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_invalidUpdate)

static bool js_cocos2dx_dragonbones_Slot_getChildArmature(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_getChildArmature : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Armature* result = cobj->getChildArmature();
        ok &= native_ptr_to_rooted_seval<dragonBones::Armature>(inst, (dragonBones::Armature*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_getChildArmature : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_getChildArmature)

static bool js_cocos2dx_dragonbones_Slot_intersectsSegment(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_intersectsSegment : Invalid Native Object");
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
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_intersectsSegment : Error processing arguments");
        int result = cobj->intersectsSegment(arg0, arg1, arg2, arg3);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_intersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 5) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        dragonBones::Point* arg4 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_native_ptr(inst, args[4], &arg4);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_intersectsSegment : Error processing arguments");
        int result = cobj->intersectsSegment(arg0, arg1, arg2, arg3, arg4);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_intersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 6) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        dragonBones::Point* arg4 = 0;
        dragonBones::Point* arg5 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_native_ptr(inst, args[4], &arg4);
        ok &= seval_to_native_ptr(inst, args[5], &arg5);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_intersectsSegment : Error processing arguments");
        int result = cobj->intersectsSegment(arg0, arg1, arg2, arg3, arg4, arg5);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_intersectsSegment : Error processing arguments");
        return true;
    }
    if (argc == 7) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        dragonBones::Point* arg4 = 0;
        dragonBones::Point* arg5 = 0;
        dragonBones::Point* arg6 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        ok &= seval_to_float(inst, args[3], &arg3);
        ok &= seval_to_native_ptr(inst, args[4], &arg4);
        ok &= seval_to_native_ptr(inst, args[5], &arg5);
        ok &= seval_to_native_ptr(inst, args[6], &arg6);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_intersectsSegment : Error processing arguments");
        int result = cobj->intersectsSegment(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_intersectsSegment : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 7);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_intersectsSegment)

static bool js_cocos2dx_dragonbones_Slot_update(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_update : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_update : Error processing arguments");
        cobj->update(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_update)

static bool js_cocos2dx_dragonbones_Slot_updateTransformAndMatrix(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_updateTransformAndMatrix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->updateTransformAndMatrix();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_updateTransformAndMatrix)

static bool js_cocos2dx_dragonbones_Slot_getParent(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_getParent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Bone* result = cobj->getParent();
        ok &= native_ptr_to_rooted_seval<dragonBones::Bone>(inst, (dragonBones::Bone*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_getParent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_getParent)

static bool js_cocos2dx_dragonbones_Slot_getBoundingBoxData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_getBoundingBoxData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::BoundingBoxData* result = cobj->getBoundingBoxData();
        ok &= native_ptr_to_rooted_seval<dragonBones::BoundingBoxData>(inst, (dragonBones::BoundingBoxData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_getBoundingBoxData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_getBoundingBoxData)

static bool js_cocos2dx_dragonbones_Slot_setChildArmature(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_setChildArmature : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::Armature* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_setChildArmature : Error processing arguments");
        cobj->setChildArmature(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_setChildArmature)

static bool js_cocos2dx_dragonbones_Slot_replaceDisplayData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_replaceDisplayData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        dragonBones::DisplayData* arg0 = nullptr;
        int arg1 = 0;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[1], &tmp); arg1 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_replaceDisplayData : Error processing arguments");
        cobj->replaceDisplayData(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_replaceDisplayData)

static bool js_cocos2dx_dragonbones_Slot_containsPoint(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_containsPoint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_containsPoint : Error processing arguments");
        bool result = cobj->containsPoint(arg0, arg1);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_containsPoint : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_containsPoint)

static bool js_cocos2dx_dragonbones_Slot_setVisible(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_setVisible : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_setVisible : Error processing arguments");
        cobj->setVisible(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_setVisible)

static bool js_cocos2dx_dragonbones_Slot_get_displayController(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_get_displayController : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= std_string_to_seval(inst, cobj->displayController, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Slot_get_displayController)

static bool js_cocos2dx_dragonbones_Slot_set_displayController(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_set_displayController : Invalid Native Object");

    CC_UNUSED bool ok = true;
    std::string arg0;
    ok &= seval_to_std_string(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_set_displayController : Error processing new value");
    cobj->displayController = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_Slot_set_displayController)

static bool js_cocos2dx_dragonbones_Slot_get__zOrder(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_get__zOrder : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= int32_to_seval(inst, cobj->_zOrder, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Slot_get__zOrder)

static bool js_cocos2dx_dragonbones_Slot_set__zOrder(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::Slot* cobj = (dragonBones::Slot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Slot_set__zOrder : Invalid Native Object");

    CC_UNUSED bool ok = true;
    int arg0 = 0;
    do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Slot_set__zOrder : Error processing new value");
    cobj->_zOrder = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_Slot_set__zOrder)


extern se::Object* __jsb_dragonBones_TransformObject_proto;


bool js_register_cocos2dx_dragonbones_Slot(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Slot", obj, __jsb_dragonBones_TransformObject_proto, nullptr);

    cls->defineProperty(inst, "displayController", _SE(js_cocos2dx_dragonbones_Slot_get_displayController), _SE(js_cocos2dx_dragonbones_Slot_set_displayController));
    cls->defineProperty(inst, "_zOrder", _SE(js_cocos2dx_dragonbones_Slot_get__zOrder), _SE(js_cocos2dx_dragonbones_Slot_set__zOrder));
    cls->defineFunction(inst, "_updateColor", _SE(js_cocos2dx_dragonbones_Slot__updateColor));
    cls->defineFunction(inst, "setRawDisplayDatas", _SE(js_cocos2dx_dragonbones_Slot_setRawDisplayDatas));
    cls->defineFunction(inst, "getVisible", _SE(js_cocos2dx_dragonbones_Slot_getVisible));
    cls->defineFunction(inst, "getSlotData", _SE(js_cocos2dx_dragonbones_Slot_getSlotData));
    cls->defineFunction(inst, "getName", _SE(js_cocos2dx_dragonbones_Slot_getName));
    cls->defineFunction(inst, "_setZorder", _SE(js_cocos2dx_dragonbones_Slot__setZorder));
    cls->defineFunction(inst, "invalidUpdate", _SE(js_cocos2dx_dragonbones_Slot_invalidUpdate));
    cls->defineFunction(inst, "getChildArmature", _SE(js_cocos2dx_dragonbones_Slot_getChildArmature));
    cls->defineFunction(inst, "intersectsSegment", _SE(js_cocos2dx_dragonbones_Slot_intersectsSegment));
    cls->defineFunction(inst, "update", _SE(js_cocos2dx_dragonbones_Slot_update));
    cls->defineFunction(inst, "updateTransformAndMatrix", _SE(js_cocos2dx_dragonbones_Slot_updateTransformAndMatrix));
    cls->defineFunction(inst, "getParent", _SE(js_cocos2dx_dragonbones_Slot_getParent));
    cls->defineFunction(inst, "getBoundingBoxData", _SE(js_cocos2dx_dragonbones_Slot_getBoundingBoxData));
    cls->defineFunction(inst, "setChildArmature", _SE(js_cocos2dx_dragonbones_Slot_setChildArmature));
    cls->defineFunction(inst, "replaceDisplayData", _SE(js_cocos2dx_dragonbones_Slot_replaceDisplayData));
    cls->defineFunction(inst, "containsPoint", _SE(js_cocos2dx_dragonbones_Slot_containsPoint));
    cls->defineFunction(inst, "setVisible", _SE(js_cocos2dx_dragonbones_Slot_setVisible));
    cls->install(inst);
    inst->registerClass<dragonBones::Slot>(cls);

    __jsb_dragonBones_Slot_proto = cls->getProto();
    __jsb_dragonBones_Slot_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_WorldClock_proto = nullptr;
se::Class* __jsb_dragonBones_WorldClock_class = nullptr;

static bool js_cocos2dx_dragonbones_WorldClock_render(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::WorldClock* cobj = (dragonBones::WorldClock*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_WorldClock_render : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->render();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_WorldClock_render)

static bool js_cocos2dx_dragonbones_WorldClock_clear(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::WorldClock* cobj = (dragonBones::WorldClock*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_WorldClock_clear : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->clear();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_WorldClock_clear)

static bool js_cocos2dx_dragonbones_WorldClock_contains(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::WorldClock* cobj = (dragonBones::WorldClock*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_WorldClock_contains : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const dragonBones::IAnimatable* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_WorldClock_contains : Error processing arguments");
        bool result = cobj->contains(arg0);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_WorldClock_contains : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_WorldClock_contains)

static bool js_cocos2dx_dragonbones_WorldClock_getClock(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::WorldClock* cobj = (dragonBones::WorldClock*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_WorldClock_getClock : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::WorldClock* result = cobj->getClock();
        ok &= native_ptr_to_rooted_seval<dragonBones::WorldClock>(inst, (dragonBones::WorldClock*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_WorldClock_getClock : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_WorldClock_getClock)

static bool js_cocos2dx_dragonbones_WorldClock_advanceTime(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::WorldClock* cobj = (dragonBones::WorldClock*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_WorldClock_advanceTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_WorldClock_advanceTime : Error processing arguments");
        cobj->advanceTime(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_WorldClock_advanceTime)

static bool js_cocos2dx_dragonbones_WorldClock_setClock(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::WorldClock* cobj = (dragonBones::WorldClock*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_WorldClock_setClock : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::WorldClock* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_WorldClock_setClock : Error processing arguments");
        cobj->setClock(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_WorldClock_setClock)

static bool js_cocos2dx_dragonbones_WorldClock_getStaticClock(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::WorldClock* result = dragonBones::WorldClock::getStaticClock();
        ok &= native_ptr_to_rooted_seval<dragonBones::WorldClock>(inst, (dragonBones::WorldClock*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_WorldClock_getStaticClock : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_WorldClock_getStaticClock)




bool js_register_cocos2dx_dragonbones_WorldClock(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "WorldClock", obj, nullptr, nullptr);

    cls->defineFunction(inst, "render", _SE(js_cocos2dx_dragonbones_WorldClock_render));
    cls->defineFunction(inst, "clear", _SE(js_cocos2dx_dragonbones_WorldClock_clear));
    cls->defineFunction(inst, "contains", _SE(js_cocos2dx_dragonbones_WorldClock_contains));
    cls->defineFunction(inst, "getClock", _SE(js_cocos2dx_dragonbones_WorldClock_getClock));
    cls->defineFunction(inst, "advanceTime", _SE(js_cocos2dx_dragonbones_WorldClock_advanceTime));
    cls->defineFunction(inst, "setClock", _SE(js_cocos2dx_dragonbones_WorldClock_setClock));
    cls->defineStaticFunction(inst, "getStaticClock", _SE(js_cocos2dx_dragonbones_WorldClock_getStaticClock));
    cls->install(inst);
    inst->registerClass<dragonBones::WorldClock>(cls);

    __jsb_dragonBones_WorldClock_proto = cls->getProto();
    __jsb_dragonBones_WorldClock_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_Animation_proto = nullptr;
se::Class* __jsb_dragonBones_Animation_class = nullptr;

static bool js_cocos2dx_dragonbones_Animation_init(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::Armature* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_init : Error processing arguments");
        cobj->init(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_init)

static bool js_cocos2dx_dragonbones_Animation_gotoAndPlayByTime(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByTime : Error processing arguments");
        dragonBones::AnimationState* result = cobj->gotoAndPlayByTime(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByTime : Error processing arguments");
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        float arg1 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByTime : Error processing arguments");
        dragonBones::AnimationState* result = cobj->gotoAndPlayByTime(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByTime : Error processing arguments");
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        float arg1 = 0;
        int arg2 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[2], &tmp); arg2 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByTime : Error processing arguments");
        dragonBones::AnimationState* result = cobj->gotoAndPlayByTime(arg0, arg1, arg2);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByTime : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_gotoAndPlayByTime)

static bool js_cocos2dx_dragonbones_Animation_fadeIn(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        dragonBones::AnimationState* result = cobj->fadeIn(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        float arg1 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        dragonBones::AnimationState* result = cobj->fadeIn(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        float arg1 = 0;
        int arg2 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[2], &tmp); arg2 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        dragonBones::AnimationState* result = cobj->fadeIn(arg0, arg1, arg2);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        return true;
    }
    if (argc == 4) {
        std::string arg0;
        float arg1 = 0;
        int arg2 = 0;
        int arg3 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[2], &tmp); arg2 = (int)tmp; } while(false);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[3], &tmp); arg3 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        dragonBones::AnimationState* result = cobj->fadeIn(arg0, arg1, arg2, arg3);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        return true;
    }
    if (argc == 5) {
        std::string arg0;
        float arg1 = 0;
        int arg2 = 0;
        int arg3 = 0;
        std::string arg4;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[2], &tmp); arg2 = (int)tmp; } while(false);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[3], &tmp); arg3 = (int)tmp; } while(false);
        ok &= seval_to_std_string(inst, args[4], &arg4);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        dragonBones::AnimationState* result = cobj->fadeIn(arg0, arg1, arg2, arg3, arg4);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        return true;
    }
    if (argc == 6) {
        std::string arg0;
        float arg1 = 0;
        int arg2 = 0;
        int arg3 = 0;
        std::string arg4;
        dragonBones::AnimationFadeOutMode arg5;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[2], &tmp); arg2 = (int)tmp; } while(false);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[3], &tmp); arg3 = (int)tmp; } while(false);
        ok &= seval_to_std_string(inst, args[4], &arg4);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[5], &tmp); arg5 = (dragonBones::AnimationFadeOutMode)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        dragonBones::AnimationState* result = cobj->fadeIn(arg0, arg1, arg2, arg3, arg4, arg5);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 6);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_fadeIn)

static bool js_cocos2dx_dragonbones_Animation_playConfig(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_playConfig : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::AnimationConfig* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_playConfig : Error processing arguments");
        dragonBones::AnimationState* result = cobj->playConfig(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_playConfig : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_playConfig)

static bool js_cocos2dx_dragonbones_Animation_isCompleted(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_isCompleted : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isCompleted();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_isCompleted : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_isCompleted)

static bool js_cocos2dx_dragonbones_Animation_play(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_play : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::AnimationState* result = cobj->play();
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_play : Error processing arguments");
        return true;
    }
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_play : Error processing arguments");
        dragonBones::AnimationState* result = cobj->play(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_play : Error processing arguments");
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        int arg1 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[1], &tmp); arg1 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_play : Error processing arguments");
        dragonBones::AnimationState* result = cobj->play(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_play : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_play)

static bool js_cocos2dx_dragonbones_Animation_getState(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_getState : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_getState : Error processing arguments");
        dragonBones::AnimationState* result = cobj->getState(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_getState : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_getState)

static bool js_cocos2dx_dragonbones_Animation_stop(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_stop : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_stop : Error processing arguments");
        cobj->stop(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_stop)

static bool js_cocos2dx_dragonbones_Animation_getLastAnimationName(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_getLastAnimationName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cobj->getLastAnimationName();
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_getLastAnimationName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_getLastAnimationName)

static bool js_cocos2dx_dragonbones_Animation_getLastAnimationState(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_getLastAnimationState : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::AnimationState* result = cobj->getLastAnimationState();
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_getLastAnimationState : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_getLastAnimationState)

static bool js_cocos2dx_dragonbones_Animation_getAnimationNames(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_getAnimationNames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::vector<std::string>& result = cobj->getAnimationNames();
        ok &= std_vector_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_getAnimationNames : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_getAnimationNames)

static bool js_cocos2dx_dragonbones_Animation_advanceTime(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_advanceTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_advanceTime : Error processing arguments");
        cobj->advanceTime(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_advanceTime)

static bool js_cocos2dx_dragonbones_Animation_isPlaying(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_isPlaying : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isPlaying();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_isPlaying : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_isPlaying)

static bool js_cocos2dx_dragonbones_Animation_gotoAndPlayByProgress(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByProgress : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByProgress : Error processing arguments");
        dragonBones::AnimationState* result = cobj->gotoAndPlayByProgress(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByProgress : Error processing arguments");
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        float arg1 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByProgress : Error processing arguments");
        dragonBones::AnimationState* result = cobj->gotoAndPlayByProgress(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByProgress : Error processing arguments");
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        float arg1 = 0;
        int arg2 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[2], &tmp); arg2 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByProgress : Error processing arguments");
        dragonBones::AnimationState* result = cobj->gotoAndPlayByProgress(arg0, arg1, arg2);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByProgress : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_gotoAndPlayByProgress)

static bool js_cocos2dx_dragonbones_Animation_getAnimationConfig(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_getAnimationConfig : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::AnimationConfig* result = cobj->getAnimationConfig();
        ok &= native_ptr_to_seval<dragonBones::AnimationConfig>(inst, (dragonBones::AnimationConfig*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_getAnimationConfig : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_getAnimationConfig)

static bool js_cocos2dx_dragonbones_Animation_reset(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_reset : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->reset();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_reset)

static bool js_cocos2dx_dragonbones_Animation_hasAnimation(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_hasAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_hasAnimation : Error processing arguments");
        bool result = cobj->hasAnimation(arg0);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_hasAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_hasAnimation)

static bool js_cocos2dx_dragonbones_Animation_gotoAndStopByTime(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByTime : Error processing arguments");
        dragonBones::AnimationState* result = cobj->gotoAndStopByTime(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByTime : Error processing arguments");
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        float arg1 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByTime : Error processing arguments");
        dragonBones::AnimationState* result = cobj->gotoAndStopByTime(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByTime : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_gotoAndStopByTime)

static bool js_cocos2dx_dragonbones_Animation_gotoAndStopByProgress(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByProgress : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByProgress : Error processing arguments");
        dragonBones::AnimationState* result = cobj->gotoAndStopByProgress(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByProgress : Error processing arguments");
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        float arg1 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_float(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByProgress : Error processing arguments");
        dragonBones::AnimationState* result = cobj->gotoAndStopByProgress(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByProgress : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_gotoAndStopByProgress)

static bool js_cocos2dx_dragonbones_Animation_gotoAndPlayByFrame(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByFrame : Error processing arguments");
        dragonBones::AnimationState* result = cobj->gotoAndPlayByFrame(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByFrame : Error processing arguments");
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        unsigned int arg1 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_uint32(inst, args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByFrame : Error processing arguments");
        dragonBones::AnimationState* result = cobj->gotoAndPlayByFrame(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByFrame : Error processing arguments");
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        unsigned int arg1 = 0;
        int arg2 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_uint32(inst, args[1], (uint32_t*)&arg1);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[2], &tmp); arg2 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByFrame : Error processing arguments");
        dragonBones::AnimationState* result = cobj->gotoAndPlayByFrame(arg0, arg1, arg2);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByFrame : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_gotoAndPlayByFrame)

static bool js_cocos2dx_dragonbones_Animation_gotoAndStopByFrame(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByFrame : Error processing arguments");
        dragonBones::AnimationState* result = cobj->gotoAndStopByFrame(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByFrame : Error processing arguments");
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        unsigned int arg1 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_uint32(inst, args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByFrame : Error processing arguments");
        dragonBones::AnimationState* result = cobj->gotoAndStopByFrame(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByFrame : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Animation_gotoAndStopByFrame)

static bool js_cocos2dx_dragonbones_Animation_get_timeScale(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_get_timeScale : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= float_to_seval(inst, cobj->timeScale, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_Animation_get_timeScale)

static bool js_cocos2dx_dragonbones_Animation_set_timeScale(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::Animation* cobj = (dragonBones::Animation*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_Animation_set_timeScale : Invalid Native Object");

    CC_UNUSED bool ok = true;
    float arg0 = 0;
    ok &= seval_to_float(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_Animation_set_timeScale : Error processing new value");
    cobj->timeScale = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_Animation_set_timeScale)


extern se::Object* __jsb_dragonBones_BaseObject_proto;


bool js_register_cocos2dx_dragonbones_Animation(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Animation", obj, __jsb_dragonBones_BaseObject_proto, nullptr);

    cls->defineProperty(inst, "timeScale", _SE(js_cocos2dx_dragonbones_Animation_get_timeScale), _SE(js_cocos2dx_dragonbones_Animation_set_timeScale));
    cls->defineFunction(inst, "init", _SE(js_cocos2dx_dragonbones_Animation_init));
    cls->defineFunction(inst, "gotoAndPlayByTime", _SE(js_cocos2dx_dragonbones_Animation_gotoAndPlayByTime));
    cls->defineFunction(inst, "fadeIn", _SE(js_cocos2dx_dragonbones_Animation_fadeIn));
    cls->defineFunction(inst, "playConfig", _SE(js_cocos2dx_dragonbones_Animation_playConfig));
    cls->defineFunction(inst, "isCompleted", _SE(js_cocos2dx_dragonbones_Animation_isCompleted));
    cls->defineFunction(inst, "play", _SE(js_cocos2dx_dragonbones_Animation_play));
    cls->defineFunction(inst, "getState", _SE(js_cocos2dx_dragonbones_Animation_getState));
    cls->defineFunction(inst, "stop", _SE(js_cocos2dx_dragonbones_Animation_stop));
    cls->defineFunction(inst, "getLastAnimationName", _SE(js_cocos2dx_dragonbones_Animation_getLastAnimationName));
    cls->defineFunction(inst, "getLastAnimationState", _SE(js_cocos2dx_dragonbones_Animation_getLastAnimationState));
    cls->defineFunction(inst, "getAnimationNames", _SE(js_cocos2dx_dragonbones_Animation_getAnimationNames));
    cls->defineFunction(inst, "advanceTime", _SE(js_cocos2dx_dragonbones_Animation_advanceTime));
    cls->defineFunction(inst, "isPlaying", _SE(js_cocos2dx_dragonbones_Animation_isPlaying));
    cls->defineFunction(inst, "gotoAndPlayByProgress", _SE(js_cocos2dx_dragonbones_Animation_gotoAndPlayByProgress));
    cls->defineFunction(inst, "getAnimationConfig", _SE(js_cocos2dx_dragonbones_Animation_getAnimationConfig));
    cls->defineFunction(inst, "reset", _SE(js_cocos2dx_dragonbones_Animation_reset));
    cls->defineFunction(inst, "hasAnimation", _SE(js_cocos2dx_dragonbones_Animation_hasAnimation));
    cls->defineFunction(inst, "gotoAndStopByTime", _SE(js_cocos2dx_dragonbones_Animation_gotoAndStopByTime));
    cls->defineFunction(inst, "gotoAndStopByProgress", _SE(js_cocos2dx_dragonbones_Animation_gotoAndStopByProgress));
    cls->defineFunction(inst, "gotoAndPlayByFrame", _SE(js_cocos2dx_dragonbones_Animation_gotoAndPlayByFrame));
    cls->defineFunction(inst, "gotoAndStopByFrame", _SE(js_cocos2dx_dragonbones_Animation_gotoAndStopByFrame));
    cls->install(inst);
    inst->registerClass<dragonBones::Animation>(cls);

    __jsb_dragonBones_Animation_proto = cls->getProto();
    __jsb_dragonBones_Animation_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_EventObject_proto = nullptr;
se::Class* __jsb_dragonBones_EventObject_class = nullptr;

static bool js_cocos2dx_dragonbones_EventObject_getBone(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::EventObject* cobj = (dragonBones::EventObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_EventObject_getBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Bone* result = cobj->getBone();
        ok &= native_ptr_to_rooted_seval<dragonBones::Bone>(inst, (dragonBones::Bone*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EventObject_getBone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_EventObject_getBone)

static bool js_cocos2dx_dragonbones_EventObject_getData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::EventObject* cobj = (dragonBones::EventObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_EventObject_getData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::UserData* result = cobj->getData();
        ok &= native_ptr_to_seval<dragonBones::UserData>(inst, (dragonBones::UserData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EventObject_getData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_EventObject_getData)

static bool js_cocos2dx_dragonbones_EventObject_getAnimationState(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::EventObject* cobj = (dragonBones::EventObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_EventObject_getAnimationState : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::AnimationState* result = cobj->getAnimationState();
        ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EventObject_getAnimationState : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_EventObject_getAnimationState)

static bool js_cocos2dx_dragonbones_EventObject_getArmature(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::EventObject* cobj = (dragonBones::EventObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_EventObject_getArmature : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Armature* result = cobj->getArmature();
        ok &= native_ptr_to_rooted_seval<dragonBones::Armature>(inst, (dragonBones::Armature*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EventObject_getArmature : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_EventObject_getArmature)

static bool js_cocos2dx_dragonbones_EventObject_getSlot(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::EventObject* cobj = (dragonBones::EventObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_EventObject_getSlot : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Slot* result = cobj->getSlot();
        ok &= native_ptr_to_rooted_seval<dragonBones::Slot>(inst, (dragonBones::Slot*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EventObject_getSlot : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_EventObject_getSlot)

static bool js_cocos2dx_dragonbones_EventObject_actionDataToInstance(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        const dragonBones::ActionData* arg0 = nullptr;
        dragonBones::EventObject* arg1 = nullptr;
        dragonBones::Armature* arg2 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        ok &= seval_to_native_ptr(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EventObject_actionDataToInstance : Error processing arguments");
        dragonBones::EventObject::actionDataToInstance(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_EventObject_actionDataToInstance)

static bool js_cocos2dx_dragonbones_EventObject_get_type(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::EventObject* cobj = (dragonBones::EventObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_EventObject_get_type : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= std_string_to_seval(inst, cobj->type, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_EventObject_get_type)

static bool js_cocos2dx_dragonbones_EventObject_set_type(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::EventObject* cobj = (dragonBones::EventObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_EventObject_set_type : Invalid Native Object");

    CC_UNUSED bool ok = true;
    std::string arg0;
    ok &= seval_to_std_string(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EventObject_set_type : Error processing new value");
    cobj->type = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_EventObject_set_type)

static bool js_cocos2dx_dragonbones_EventObject_get_name(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::EventObject* cobj = (dragonBones::EventObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_EventObject_get_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= std_string_to_seval(inst, cobj->name, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_EventObject_get_name)

static bool js_cocos2dx_dragonbones_EventObject_set_name(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::EventObject* cobj = (dragonBones::EventObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_EventObject_set_name : Invalid Native Object");

    CC_UNUSED bool ok = true;
    std::string arg0;
    ok &= seval_to_std_string(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EventObject_set_name : Error processing new value");
    cobj->name = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_EventObject_set_name)

static bool js_cocos2dx_dragonbones_EventObject_get_armature(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::EventObject* cobj = (dragonBones::EventObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_EventObject_get_armature : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= native_ptr_to_rooted_seval<dragonBones::Armature>(inst, (dragonBones::Armature*)cobj->armature, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_EventObject_get_armature)

static bool js_cocos2dx_dragonbones_EventObject_set_armature(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::EventObject* cobj = (dragonBones::EventObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_EventObject_set_armature : Invalid Native Object");

    CC_UNUSED bool ok = true;
    dragonBones::Armature* arg0 = nullptr;
    ok &= seval_to_native_ptr(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EventObject_set_armature : Error processing new value");
    cobj->armature = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_EventObject_set_armature)

static bool js_cocos2dx_dragonbones_EventObject_get_bone(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::EventObject* cobj = (dragonBones::EventObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_EventObject_get_bone : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= native_ptr_to_rooted_seval<dragonBones::Bone>(inst, (dragonBones::Bone*)cobj->bone, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_EventObject_get_bone)

static bool js_cocos2dx_dragonbones_EventObject_set_bone(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::EventObject* cobj = (dragonBones::EventObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_EventObject_set_bone : Invalid Native Object");

    CC_UNUSED bool ok = true;
    dragonBones::Bone* arg0 = nullptr;
    ok &= seval_to_native_ptr(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EventObject_set_bone : Error processing new value");
    cobj->bone = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_EventObject_set_bone)

static bool js_cocos2dx_dragonbones_EventObject_get_slot(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::EventObject* cobj = (dragonBones::EventObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_EventObject_get_slot : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= native_ptr_to_rooted_seval<dragonBones::Slot>(inst, (dragonBones::Slot*)cobj->slot, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_EventObject_get_slot)

static bool js_cocos2dx_dragonbones_EventObject_set_slot(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::EventObject* cobj = (dragonBones::EventObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_EventObject_set_slot : Invalid Native Object");

    CC_UNUSED bool ok = true;
    dragonBones::Slot* arg0 = nullptr;
    ok &= seval_to_native_ptr(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EventObject_set_slot : Error processing new value");
    cobj->slot = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_EventObject_set_slot)

static bool js_cocos2dx_dragonbones_EventObject_get_animationState(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::EventObject* cobj = (dragonBones::EventObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_EventObject_get_animationState : Invalid Native Object");

    CC_UNUSED bool ok = true;
    se::Value jsret;
    ok &= native_ptr_to_rooted_seval<dragonBones::AnimationState>(inst, (dragonBones::AnimationState*)cobj->animationState, &jsret);
    s.rval() = jsret;
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_EventObject_get_animationState)

static bool js_cocos2dx_dragonbones_EventObject_set_animationState(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    dragonBones::EventObject* cobj = (dragonBones::EventObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_EventObject_set_animationState : Invalid Native Object");

    CC_UNUSED bool ok = true;
    dragonBones::AnimationState* arg0 = nullptr;
    ok &= seval_to_native_ptr(inst, args[0], &arg0);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_EventObject_set_animationState : Error processing new value");
    cobj->animationState = arg0;
    return true;
}
SE_BIND_PROP_SET(js_cocos2dx_dragonbones_EventObject_set_animationState)


extern se::Object* __jsb_dragonBones_BaseObject_proto;


bool js_register_cocos2dx_dragonbones_EventObject(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "EventObject", obj, __jsb_dragonBones_BaseObject_proto, nullptr);

    cls->defineProperty(inst, "type", _SE(js_cocos2dx_dragonbones_EventObject_get_type), _SE(js_cocos2dx_dragonbones_EventObject_set_type));
    cls->defineProperty(inst, "name", _SE(js_cocos2dx_dragonbones_EventObject_get_name), _SE(js_cocos2dx_dragonbones_EventObject_set_name));
    cls->defineProperty(inst, "armature", _SE(js_cocos2dx_dragonbones_EventObject_get_armature), _SE(js_cocos2dx_dragonbones_EventObject_set_armature));
    cls->defineProperty(inst, "bone", _SE(js_cocos2dx_dragonbones_EventObject_get_bone), _SE(js_cocos2dx_dragonbones_EventObject_set_bone));
    cls->defineProperty(inst, "slot", _SE(js_cocos2dx_dragonbones_EventObject_get_slot), _SE(js_cocos2dx_dragonbones_EventObject_set_slot));
    cls->defineProperty(inst, "animationState", _SE(js_cocos2dx_dragonbones_EventObject_get_animationState), _SE(js_cocos2dx_dragonbones_EventObject_set_animationState));
    cls->defineFunction(inst, "getBone", _SE(js_cocos2dx_dragonbones_EventObject_getBone));
    cls->defineFunction(inst, "getData", _SE(js_cocos2dx_dragonbones_EventObject_getData));
    cls->defineFunction(inst, "getAnimationState", _SE(js_cocos2dx_dragonbones_EventObject_getAnimationState));
    cls->defineFunction(inst, "getArmature", _SE(js_cocos2dx_dragonbones_EventObject_getArmature));
    cls->defineFunction(inst, "getSlot", _SE(js_cocos2dx_dragonbones_EventObject_getSlot));
    cls->defineStaticFunction(inst, "actionDataToInstance", _SE(js_cocos2dx_dragonbones_EventObject_actionDataToInstance));
    cls->install(inst);
    inst->registerClass<dragonBones::EventObject>(cls);

    __jsb_dragonBones_EventObject_proto = cls->getProto();
    __jsb_dragonBones_EventObject_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_BaseFactory_proto = nullptr;
se::Class* __jsb_dragonBones_BaseFactory_class = nullptr;

static bool js_cocos2dx_dragonbones_BaseFactory_replaceSkin(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BaseFactory_replaceSkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        dragonBones::Armature* arg0 = nullptr;
        dragonBones::SkinData* arg1 = nullptr;
        bool arg2;
        std::vector<std::string> arg3;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        ok &= seval_to_boolean(inst, args[2], &arg2);
        ok &= seval_to_std_vector_string(inst, args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_replaceSkin : Error processing arguments");
        bool result = cobj->replaceSkin(arg0, arg1, arg2, arg3);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_replaceSkin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseFactory_replaceSkin)

static bool js_cocos2dx_dragonbones_BaseFactory_replaceAnimation(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BaseFactory_replaceAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        dragonBones::Armature* arg0 = nullptr;
        dragonBones::ArmatureData* arg1 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_replaceAnimation : Error processing arguments");
        bool result = cobj->replaceAnimation(arg0, arg1);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_replaceAnimation : Error processing arguments");
        return true;
    }
    if (argc == 3) {
        dragonBones::Armature* arg0 = nullptr;
        dragonBones::ArmatureData* arg1 = nullptr;
        bool arg2;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        ok &= seval_to_boolean(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_replaceAnimation : Error processing arguments");
        bool result = cobj->replaceAnimation(arg0, arg1, arg2);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_replaceAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseFactory_replaceAnimation)

static bool js_cocos2dx_dragonbones_BaseFactory_getClock(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BaseFactory_getClock : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::WorldClock* result = cobj->getClock();
        ok &= native_ptr_to_rooted_seval<dragonBones::WorldClock>(inst, (dragonBones::WorldClock*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_getClock : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseFactory_getClock)

static bool js_cocos2dx_dragonbones_BaseFactory_removeDragonBonesData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BaseFactory_removeDragonBonesData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_removeDragonBonesData : Error processing arguments");
        cobj->removeDragonBonesData(arg0);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_boolean(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_removeDragonBonesData : Error processing arguments");
        cobj->removeDragonBonesData(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseFactory_removeDragonBonesData)

static bool js_cocos2dx_dragonbones_BaseFactory_removeTextureAtlasData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BaseFactory_removeTextureAtlasData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_removeTextureAtlasData : Error processing arguments");
        cobj->removeTextureAtlasData(arg0);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_boolean(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_removeTextureAtlasData : Error processing arguments");
        cobj->removeTextureAtlasData(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseFactory_removeTextureAtlasData)

static bool js_cocos2dx_dragonbones_BaseFactory_parseDragonBonesData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BaseFactory_parseDragonBonesData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(inst, args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_parseDragonBonesData : Error processing arguments");
        dragonBones::DragonBonesData* result = cobj->parseDragonBonesData(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::DragonBonesData>(inst, (dragonBones::DragonBonesData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_parseDragonBonesData : Error processing arguments");
        return true;
    }
    if (argc == 2) {
        const char* arg0 = nullptr;
        std::string arg1;
        std::string arg0_tmp; ok &= seval_to_std_string(inst, args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_parseDragonBonesData : Error processing arguments");
        dragonBones::DragonBonesData* result = cobj->parseDragonBonesData(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<dragonBones::DragonBonesData>(inst, (dragonBones::DragonBonesData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_parseDragonBonesData : Error processing arguments");
        return true;
    }
    if (argc == 3) {
        const char* arg0 = nullptr;
        std::string arg1;
        float arg2 = 0;
        std::string arg0_tmp; ok &= seval_to_std_string(inst, args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_std_string(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_parseDragonBonesData : Error processing arguments");
        dragonBones::DragonBonesData* result = cobj->parseDragonBonesData(arg0, arg1, arg2);
        ok &= native_ptr_to_rooted_seval<dragonBones::DragonBonesData>(inst, (dragonBones::DragonBonesData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_parseDragonBonesData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseFactory_parseDragonBonesData)

static bool js_cocos2dx_dragonbones_BaseFactory_clear(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BaseFactory_clear : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cobj->clear();
        return true;
    }
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_clear : Error processing arguments");
        cobj->clear(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseFactory_clear)

static bool js_cocos2dx_dragonbones_BaseFactory_addDragonBonesData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BaseFactory_addDragonBonesData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::DragonBonesData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_addDragonBonesData : Error processing arguments");
        cobj->addDragonBonesData(arg0);
        return true;
    }
    if (argc == 2) {
        dragonBones::DragonBonesData* arg0 = nullptr;
        std::string arg1;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_addDragonBonesData : Error processing arguments");
        cobj->addDragonBonesData(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseFactory_addDragonBonesData)

static bool js_cocos2dx_dragonbones_BaseFactory_buildArmature(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BaseFactory_buildArmature : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_buildArmature : Error processing arguments");
        dragonBones::Armature* result = cobj->buildArmature(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::Armature>(inst, (dragonBones::Armature*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_buildArmature : Error processing arguments");
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_buildArmature : Error processing arguments");
        dragonBones::Armature* result = cobj->buildArmature(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<dragonBones::Armature>(inst, (dragonBones::Armature*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_buildArmature : Error processing arguments");
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        ok &= seval_to_std_string(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_buildArmature : Error processing arguments");
        dragonBones::Armature* result = cobj->buildArmature(arg0, arg1, arg2);
        ok &= native_ptr_to_rooted_seval<dragonBones::Armature>(inst, (dragonBones::Armature*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_buildArmature : Error processing arguments");
        return true;
    }
    if (argc == 4) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        ok &= seval_to_std_string(inst, args[2], &arg2);
        ok &= seval_to_std_string(inst, args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_buildArmature : Error processing arguments");
        dragonBones::Armature* result = cobj->buildArmature(arg0, arg1, arg2, arg3);
        ok &= native_ptr_to_rooted_seval<dragonBones::Armature>(inst, (dragonBones::Armature*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_buildArmature : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseFactory_buildArmature)

static bool js_cocos2dx_dragonbones_BaseFactory_addTextureAtlasData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BaseFactory_addTextureAtlasData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::TextureAtlasData* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_addTextureAtlasData : Error processing arguments");
        cobj->addTextureAtlasData(arg0);
        return true;
    }
    if (argc == 2) {
        dragonBones::TextureAtlasData* arg0 = nullptr;
        std::string arg1;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_addTextureAtlasData : Error processing arguments");
        cobj->addTextureAtlasData(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseFactory_addTextureAtlasData)

static bool js_cocos2dx_dragonbones_BaseFactory_getArmatureData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BaseFactory_getArmatureData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_getArmatureData : Error processing arguments");
        dragonBones::ArmatureData* result = cobj->getArmatureData(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::ArmatureData>(inst, (dragonBones::ArmatureData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_getArmatureData : Error processing arguments");
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_getArmatureData : Error processing arguments");
        dragonBones::ArmatureData* result = cobj->getArmatureData(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<dragonBones::ArmatureData>(inst, (dragonBones::ArmatureData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_getArmatureData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseFactory_getArmatureData)

static bool js_cocos2dx_dragonbones_BaseFactory_replaceSlotDisplay(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BaseFactory_replaceSlotDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 5) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        dragonBones::Slot* arg4 = nullptr;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        ok &= seval_to_std_string(inst, args[2], &arg2);
        ok &= seval_to_std_string(inst, args[3], &arg3);
        ok &= seval_to_native_ptr(inst, args[4], &arg4);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_replaceSlotDisplay : Error processing arguments");
        bool result = cobj->replaceSlotDisplay(arg0, arg1, arg2, arg3, arg4);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_replaceSlotDisplay : Error processing arguments");
        return true;
    }
    if (argc == 6) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        dragonBones::Slot* arg4 = nullptr;
        int arg5 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        ok &= seval_to_std_string(inst, args[2], &arg2);
        ok &= seval_to_std_string(inst, args[3], &arg3);
        ok &= seval_to_native_ptr(inst, args[4], &arg4);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[5], &tmp); arg5 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_replaceSlotDisplay : Error processing arguments");
        bool result = cobj->replaceSlotDisplay(arg0, arg1, arg2, arg3, arg4, arg5);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_replaceSlotDisplay : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 6);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseFactory_replaceSlotDisplay)

static bool js_cocos2dx_dragonbones_BaseFactory_changeSkin(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BaseFactory_changeSkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        dragonBones::Armature* arg0 = nullptr;
        dragonBones::SkinData* arg1 = nullptr;
        std::vector<std::string> arg2;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        ok &= seval_to_std_vector_string(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_changeSkin : Error processing arguments");
        bool result = cobj->changeSkin(arg0, arg1, arg2);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_changeSkin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseFactory_changeSkin)

static bool js_cocos2dx_dragonbones_BaseFactory_replaceDisplay(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BaseFactory_replaceDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        dragonBones::Slot* arg0 = nullptr;
        dragonBones::DisplayData* arg1 = nullptr;
        int arg2 = 0;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[2], &tmp); arg2 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_replaceDisplay : Error processing arguments");
        cobj->replaceDisplay(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseFactory_replaceDisplay)

static bool js_cocos2dx_dragonbones_BaseFactory_getDragonBonesData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_BaseFactory_getDragonBonesData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_getDragonBonesData : Error processing arguments");
        dragonBones::DragonBonesData* result = cobj->getDragonBonesData(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::DragonBonesData>(inst, (dragonBones::DragonBonesData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_BaseFactory_getDragonBonesData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_BaseFactory_getDragonBonesData)




bool js_register_cocos2dx_dragonbones_BaseFactory(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "BaseFactory", obj, nullptr, nullptr);

    cls->defineFunction(inst, "replaceSkin", _SE(js_cocos2dx_dragonbones_BaseFactory_replaceSkin));
    cls->defineFunction(inst, "replaceAnimation", _SE(js_cocos2dx_dragonbones_BaseFactory_replaceAnimation));
    cls->defineFunction(inst, "getClock", _SE(js_cocos2dx_dragonbones_BaseFactory_getClock));
    cls->defineFunction(inst, "removeDragonBonesData", _SE(js_cocos2dx_dragonbones_BaseFactory_removeDragonBonesData));
    cls->defineFunction(inst, "removeTextureAtlasData", _SE(js_cocos2dx_dragonbones_BaseFactory_removeTextureAtlasData));
    cls->defineFunction(inst, "parseDragonBonesData", _SE(js_cocos2dx_dragonbones_BaseFactory_parseDragonBonesData));
    cls->defineFunction(inst, "clear", _SE(js_cocos2dx_dragonbones_BaseFactory_clear));
    cls->defineFunction(inst, "addDragonBonesData", _SE(js_cocos2dx_dragonbones_BaseFactory_addDragonBonesData));
    cls->defineFunction(inst, "buildArmature", _SE(js_cocos2dx_dragonbones_BaseFactory_buildArmature));
    cls->defineFunction(inst, "addTextureAtlasData", _SE(js_cocos2dx_dragonbones_BaseFactory_addTextureAtlasData));
    cls->defineFunction(inst, "getArmatureData", _SE(js_cocos2dx_dragonbones_BaseFactory_getArmatureData));
    cls->defineFunction(inst, "replaceSlotDisplay", _SE(js_cocos2dx_dragonbones_BaseFactory_replaceSlotDisplay));
    cls->defineFunction(inst, "changeSkin", _SE(js_cocos2dx_dragonbones_BaseFactory_changeSkin));
    cls->defineFunction(inst, "replaceDisplay", _SE(js_cocos2dx_dragonbones_BaseFactory_replaceDisplay));
    cls->defineFunction(inst, "getDragonBonesData", _SE(js_cocos2dx_dragonbones_BaseFactory_getDragonBonesData));
    cls->install(inst);
    inst->registerClass<dragonBones::BaseFactory>(cls);

    __jsb_dragonBones_BaseFactory_proto = cls->getProto();
    __jsb_dragonBones_BaseFactory_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_CCTextureAtlasData_proto = nullptr;
se::Class* __jsb_dragonBones_CCTextureAtlasData_class = nullptr;

static bool js_cocos2dx_dragonbones_CCTextureAtlasData_setRenderTexture(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCTextureAtlasData* cobj = (dragonBones::CCTextureAtlasData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCTextureAtlasData_setRenderTexture : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::middleware::Texture2D* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCTextureAtlasData_setRenderTexture : Error processing arguments");
        cobj->setRenderTexture(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCTextureAtlasData_setRenderTexture)

static bool js_cocos2dx_dragonbones_CCTextureAtlasData_getRenderTexture(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCTextureAtlasData* cobj = (dragonBones::CCTextureAtlasData*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCTextureAtlasData_getRenderTexture : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::middleware::Texture2D* result = cobj->getRenderTexture();
        ok &= native_ptr_to_seval<cocos2d::middleware::Texture2D>(inst, (cocos2d::middleware::Texture2D*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCTextureAtlasData_getRenderTexture : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCTextureAtlasData_getRenderTexture)


extern se::Object* __jsb_dragonBones_TextureAtlasData_proto;


bool js_register_cocos2dx_dragonbones_CCTextureAtlasData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "CCTextureAtlasData", obj, __jsb_dragonBones_TextureAtlasData_proto, nullptr);

    cls->defineFunction(inst, "setRenderTexture", _SE(js_cocos2dx_dragonbones_CCTextureAtlasData_setRenderTexture));
    cls->defineFunction(inst, "getRenderTexture", _SE(js_cocos2dx_dragonbones_CCTextureAtlasData_getRenderTexture));
    cls->install(inst);
    inst->registerClass<dragonBones::CCTextureAtlasData>(cls);

    __jsb_dragonBones_CCTextureAtlasData_proto = cls->getProto();
    __jsb_dragonBones_CCTextureAtlasData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_CCTextureData_proto = nullptr;
se::Class* __jsb_dragonBones_CCTextureData_class = nullptr;


extern se::Object* __jsb_dragonBones_TextureData_proto;


bool js_register_cocos2dx_dragonbones_CCTextureData(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "CCTextureData", obj, __jsb_dragonBones_TextureData_proto, nullptr);

    cls->install(inst);
    inst->registerClass<dragonBones::CCTextureData>(cls);

    __jsb_dragonBones_CCTextureData_proto = cls->getProto();
    __jsb_dragonBones_CCTextureData_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_CCSlot_proto = nullptr;
se::Class* __jsb_dragonBones_CCSlot_class = nullptr;

static bool js_cocos2dx_dragonbones_CCSlot_getTexture(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCSlot* cobj = (dragonBones::CCSlot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCSlot_getTexture : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::middleware::Texture2D* result = cobj->getTexture();
        ok &= native_ptr_to_seval<cocos2d::middleware::Texture2D>(inst, (cocos2d::middleware::Texture2D*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCSlot_getTexture : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCSlot_getTexture)

static bool js_cocos2dx_dragonbones_CCSlot_updateWorldMatrix(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCSlot* cobj = (dragonBones::CCSlot*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCSlot_updateWorldMatrix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->updateWorldMatrix();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCSlot_updateWorldMatrix)


extern se::Object* __jsb_dragonBones_Slot_proto;


bool js_register_cocos2dx_dragonbones_CCSlot(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "CCSlot", obj, __jsb_dragonBones_Slot_proto, nullptr);

    cls->defineFunction(inst, "getTexture", _SE(js_cocos2dx_dragonbones_CCSlot_getTexture));
    cls->defineFunction(inst, "updateWorldMatrix", _SE(js_cocos2dx_dragonbones_CCSlot_updateWorldMatrix));
    cls->install(inst);
    inst->registerClass<dragonBones::CCSlot>(cls);

    __jsb_dragonBones_CCSlot_proto = cls->getProto();
    __jsb_dragonBones_CCSlot_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_CCArmatureDisplay_proto = nullptr;
se::Class* __jsb_dragonBones_CCArmatureDisplay_class = nullptr;

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_dbInit(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_dbInit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::Armature* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_dbInit : Error processing arguments");
        cobj->dbInit(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_dbInit)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_addDBEventListener(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_addDBEventListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::function<void (dragonBones::EventObject *)> arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        do {
            if (args[1].isObject() && args[1].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[1]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](dragonBones::EventObject* larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= native_ptr_to_rooted_seval<dragonBones::EventObject>(inst, (dragonBones::EventObject*)larg0, &args[0]);
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
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_addDBEventListener : Error processing arguments");
        cobj->addDBEventListener(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_addDBEventListener)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_getRootDisplay(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_getRootDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::CCArmatureDisplay* result = cobj->getRootDisplay();
        ok &= native_ptr_to_seval<dragonBones::CCArmatureDisplay>(inst, (dragonBones::CCArmatureDisplay*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_getRootDisplay : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_getRootDisplay)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_setAttachUtil(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_setAttachUtil : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::RealTimeAttachUtil* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_setAttachUtil : Error processing arguments");
        cobj->setAttachUtil(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_setAttachUtil)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_removeDBEventListener(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_removeDBEventListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::function<void (dragonBones::EventObject *)> arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        do {
            if (args[1].isObject() && args[1].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[1]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](dragonBones::EventObject* larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= native_ptr_to_rooted_seval<dragonBones::EventObject>(inst, (dragonBones::EventObject*)larg0, &args[0]);
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
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_removeDBEventListener : Error processing arguments");
        cobj->removeDBEventListener(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_removeDBEventListener)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_setEffect(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_setEffect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::renderer::EffectVariant* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_setEffect : Error processing arguments");
        cobj->setEffect(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_setEffect)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_dispose(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_dispose : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cobj->dispose();
        return true;
    }
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_dispose : Error processing arguments");
        cobj->dispose(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_dispose)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_setOpacityModifyRGB(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_setOpacityModifyRGB : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_setOpacityModifyRGB : Error processing arguments");
        cobj->setOpacityModifyRGB(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_setOpacityModifyRGB)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_dbClear(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_dbClear : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->dbClear();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_dbClear)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_dispatchDBEvent(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_dispatchDBEvent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        dragonBones::EventObject* arg1 = nullptr;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_dispatchDBEvent : Error processing arguments");
        cobj->dispatchDBEvent(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_dispatchDBEvent)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_getDebugData(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_getDebugData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        se_object_ptr result = cobj->getDebugData();
        s.rval().setObject(result);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_getDebugData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_getDebugData)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_hasDBEventListener(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_hasDBEventListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_hasDBEventListener : Error processing arguments");
        bool result = cobj->hasDBEventListener(arg0);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_hasDBEventListener : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_hasDBEventListener)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_dbUpdate(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_dbUpdate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->dbUpdate();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_dbUpdate)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_setDBEventCallback(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_setDBEventCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void (dragonBones::EventObject *)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](dragonBones::EventObject* larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= native_ptr_to_rooted_seval<dragonBones::EventObject>(inst, (dragonBones::EventObject*)larg0, &args[0]);
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
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_setDBEventCallback : Error processing arguments");
        cobj->setDBEventCallback(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_setDBEventCallback)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_setDebugBonesEnabled(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_setDebugBonesEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_setDebugBonesEnabled : Error processing arguments");
        cobj->setDebugBonesEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_setDebugBonesEnabled)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_getAnimation(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_getAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Animation* result = cobj->getAnimation();
        ok &= native_ptr_to_rooted_seval<dragonBones::Animation>(inst, (dragonBones::Animation*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_getAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_getAnimation)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_setColor(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_setColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Color4B arg0;
        ok &= seval_to_Color4B(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_setColor : Error processing arguments");
        cobj->setColor(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_setColor)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_bindNodeProxy(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_bindNodeProxy : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::renderer::NodeProxy* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_bindNodeProxy : Error processing arguments");
        cobj->bindNodeProxy(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_bindNodeProxy)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_setBatchEnabled(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_setBatchEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_setBatchEnabled : Error processing arguments");
        cobj->setBatchEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_setBatchEnabled)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_dbRender(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_dbRender : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->dbRender();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_dbRender)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_getArmature(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_getArmature : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Armature* result = cobj->getArmature();
        ok &= native_ptr_to_rooted_seval<dragonBones::Armature>(inst, (dragonBones::Armature*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_getArmature : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_getArmature)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_convertToRootSpace(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_convertToRootSpace : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec2 arg0;
        ok &= seval_to_Vec2(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_convertToRootSpace : Error processing arguments");
        cocos2d::Vec2 result = cobj->convertToRootSpace(arg0);
        ok &= Vec2_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_convertToRootSpace : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_convertToRootSpace)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_create(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = dragonBones::CCArmatureDisplay::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(inst, __jsb_dragonBones_CCArmatureDisplay_class);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_create)

SE_DECLARE_FINALIZE_FUNC(js_dragonBones_CCArmatureDisplay_finalize)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_constructor(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureDisplay* cobj = new (std::nothrow) dragonBones::CCArmatureDisplay();
    s.thisObject(inst)->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_dragonbones_CCArmatureDisplay_constructor, __jsb_dragonBones_CCArmatureDisplay_class, js_dragonBones_CCArmatureDisplay_finalize)




static bool js_dragonBones_CCArmatureDisplay_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (dragonBones::CCArmatureDisplay)", s.nativeThisObject());
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_dragonBones_CCArmatureDisplay_finalize)

bool js_register_cocos2dx_dragonbones_CCArmatureDisplay(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "CCArmatureDisplay", obj, nullptr, _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_constructor));

    cls->defineFunction(inst, "dbInit", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_dbInit));
    cls->defineFunction(inst, "addDBEventListener", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_addDBEventListener));
    cls->defineFunction(inst, "getRootDisplay", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_getRootDisplay));
    cls->defineFunction(inst, "setAttachUtil", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_setAttachUtil));
    cls->defineFunction(inst, "removeDBEventListener", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_removeDBEventListener));
    cls->defineFunction(inst, "setEffect", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_setEffect));
    cls->defineFunction(inst, "dispose", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_dispose));
    cls->defineFunction(inst, "setOpacityModifyRGB", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_setOpacityModifyRGB));
    cls->defineFunction(inst, "dbClear", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_dbClear));
    cls->defineFunction(inst, "dispatchDBEvent", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_dispatchDBEvent));
    cls->defineFunction(inst, "getDebugData", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_getDebugData));
    cls->defineFunction(inst, "hasDBEventListener", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_hasDBEventListener));
    cls->defineFunction(inst, "dbUpdate", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_dbUpdate));
    cls->defineFunction(inst, "setDBEventCallback", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_setDBEventCallback));
    cls->defineFunction(inst, "setDebugBonesEnabled", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_setDebugBonesEnabled));
    cls->defineFunction(inst, "getAnimation", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_getAnimation));
    cls->defineFunction(inst, "setColor", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_setColor));
    cls->defineFunction(inst, "bindNodeProxy", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_bindNodeProxy));
    cls->defineFunction(inst, "setBatchEnabled", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_setBatchEnabled));
    cls->defineFunction(inst, "dbRender", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_dbRender));
    cls->defineFunction(inst, "armature", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_getArmature));
    cls->defineFunction(inst, "convertToRootSpace", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_convertToRootSpace));
    cls->defineStaticFunction(inst, "create", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_create));
    cls->defineFinalizeFunction(_SE(js_dragonBones_CCArmatureDisplay_finalize));
    cls->install(inst);
    inst->registerClass<dragonBones::CCArmatureDisplay>(cls);

    __jsb_dragonBones_CCArmatureDisplay_proto = cls->getProto();
    __jsb_dragonBones_CCArmatureDisplay_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_CCFactory_proto = nullptr;
se::Class* __jsb_dragonBones_CCFactory_class = nullptr;

static bool js_cocos2dx_dragonbones_CCFactory_setTimeScale(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCFactory_setTimeScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_setTimeScale : Error processing arguments");
        cobj->setTimeScale(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_setTimeScale)

static bool js_cocos2dx_dragonbones_CCFactory_getSoundEventManager(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCFactory_getSoundEventManager : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::CCArmatureDisplay* result = cobj->getSoundEventManager();
        ok &= native_ptr_to_seval<dragonBones::CCArmatureDisplay>(inst, (dragonBones::CCArmatureDisplay*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_getSoundEventManager : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_getSoundEventManager)

static bool js_cocos2dx_dragonbones_CCFactory_render(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCFactory_render : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_render : Error processing arguments");
        cobj->render(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_render)

static bool js_cocos2dx_dragonbones_CCFactory_removeDragonBonesDataByUUID(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCFactory_removeDragonBonesDataByUUID : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_removeDragonBonesDataByUUID : Error processing arguments");
        cobj->removeDragonBonesDataByUUID(arg0);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_boolean(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_removeDragonBonesDataByUUID : Error processing arguments");
        cobj->removeDragonBonesDataByUUID(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_removeDragonBonesDataByUUID)

static bool js_cocos2dx_dragonbones_CCFactory_update(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCFactory_update : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_update : Error processing arguments");
        cobj->update(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_update)

static bool js_cocos2dx_dragonbones_CCFactory_remove(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCFactory_remove : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::Armature* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_remove : Error processing arguments");
        cobj->remove(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_remove)

static bool js_cocos2dx_dragonbones_CCFactory_getTextureAtlasDataByIndex(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCFactory_getTextureAtlasDataByIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        int arg1 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[1], &tmp); arg1 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_getTextureAtlasDataByIndex : Error processing arguments");
        dragonBones::CCTextureAtlasData* result = cobj->getTextureAtlasDataByIndex(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<dragonBones::CCTextureAtlasData>(inst, (dragonBones::CCTextureAtlasData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_getTextureAtlasDataByIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_getTextureAtlasDataByIndex)

static bool js_cocos2dx_dragonbones_CCFactory_getDragonBones(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCFactory_getDragonBones : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::DragonBones* result = cobj->getDragonBones();
        ok &= native_ptr_to_seval<dragonBones::DragonBones>(inst, (dragonBones::DragonBones*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_getDragonBones : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_getDragonBones)

static bool js_cocos2dx_dragonbones_CCFactory_parseDragonBonesDataByPath(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCFactory_parseDragonBonesDataByPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_parseDragonBonesDataByPath : Error processing arguments");
        dragonBones::DragonBonesData* result = cobj->parseDragonBonesDataByPath(arg0);
        ok &= native_ptr_to_rooted_seval<dragonBones::DragonBonesData>(inst, (dragonBones::DragonBonesData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_parseDragonBonesDataByPath : Error processing arguments");
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_parseDragonBonesDataByPath : Error processing arguments");
        dragonBones::DragonBonesData* result = cobj->parseDragonBonesDataByPath(arg0, arg1);
        ok &= native_ptr_to_rooted_seval<dragonBones::DragonBonesData>(inst, (dragonBones::DragonBonesData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_parseDragonBonesDataByPath : Error processing arguments");
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        float arg2 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        ok &= seval_to_float(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_parseDragonBonesDataByPath : Error processing arguments");
        dragonBones::DragonBonesData* result = cobj->parseDragonBonesDataByPath(arg0, arg1, arg2);
        ok &= native_ptr_to_rooted_seval<dragonBones::DragonBonesData>(inst, (dragonBones::DragonBonesData*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_parseDragonBonesDataByPath : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_parseDragonBonesDataByPath)

static bool js_cocos2dx_dragonbones_CCFactory_add(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCFactory_add : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::Armature* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_add : Error processing arguments");
        cobj->add(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_add)

static bool js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay : Error processing arguments");
        dragonBones::CCArmatureDisplay* result = cobj->buildArmatureDisplay(arg0);
        ok &= native_ptr_to_seval<dragonBones::CCArmatureDisplay>(inst, (dragonBones::CCArmatureDisplay*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay : Error processing arguments");
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay : Error processing arguments");
        dragonBones::CCArmatureDisplay* result = cobj->buildArmatureDisplay(arg0, arg1);
        ok &= native_ptr_to_seval<dragonBones::CCArmatureDisplay>(inst, (dragonBones::CCArmatureDisplay*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay : Error processing arguments");
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        ok &= seval_to_std_string(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay : Error processing arguments");
        dragonBones::CCArmatureDisplay* result = cobj->buildArmatureDisplay(arg0, arg1, arg2);
        ok &= native_ptr_to_seval<dragonBones::CCArmatureDisplay>(inst, (dragonBones::CCArmatureDisplay*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay : Error processing arguments");
        return true;
    }
    if (argc == 4) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        ok &= seval_to_std_string(inst, args[2], &arg2);
        ok &= seval_to_std_string(inst, args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay : Error processing arguments");
        dragonBones::CCArmatureDisplay* result = cobj->buildArmatureDisplay(arg0, arg1, arg2, arg3);
        ok &= native_ptr_to_seval<dragonBones::CCArmatureDisplay>(inst, (dragonBones::CCArmatureDisplay*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay)

static bool js_cocos2dx_dragonbones_CCFactory_stopSchedule(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCFactory_stopSchedule : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->stopSchedule();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_stopSchedule)

static bool js_cocos2dx_dragonbones_CCFactory_removeTextureAtlasDataByIndex(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCFactory_removeTextureAtlasDataByIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        int arg1 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[1], &tmp); arg1 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_removeTextureAtlasDataByIndex : Error processing arguments");
        cobj->removeTextureAtlasDataByIndex(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_removeTextureAtlasDataByIndex)

static bool js_cocos2dx_dragonbones_CCFactory_getTimeScale(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCFactory_getTimeScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTimeScale();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_getTimeScale : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_getTimeScale)

static bool js_cocos2dx_dragonbones_CCFactory_isInit(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = dragonBones::CCFactory::isInit();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_isInit : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_isInit)

static bool js_cocos2dx_dragonbones_CCFactory_destroyFactory(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        dragonBones::CCFactory::destroyFactory();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_destroyFactory)

static bool js_cocos2dx_dragonbones_CCFactory_getClock(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::WorldClock* result = dragonBones::CCFactory::getClock();
        ok &= native_ptr_to_rooted_seval<dragonBones::WorldClock>(inst, (dragonBones::WorldClock*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_getClock : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_getClock)

static bool js_cocos2dx_dragonbones_CCFactory_getFactory(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::CCFactory* result = dragonBones::CCFactory::getFactory();
        ok &= native_ptr_to_seval<dragonBones::CCFactory>(inst, (dragonBones::CCFactory*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCFactory_getFactory : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_getFactory)

SE_DECLARE_FINALIZE_FUNC(js_dragonBones_CCFactory_finalize)

static bool js_cocos2dx_dragonbones_CCFactory_constructor(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCFactory* cobj = new (std::nothrow) dragonBones::CCFactory();
    s.thisObject(inst)->setPrivateData(cobj);
    inst->getNoneRefNativePtrMap().emplace(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_dragonbones_CCFactory_constructor, __jsb_dragonBones_CCFactory_class, js_dragonBones_CCFactory_finalize)



extern se::Object* __jsb_dragonBones_BaseFactory_proto;

static bool js_dragonBones_CCFactory_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (dragonBones::CCFactory)", s.nativeThisObject());
    auto iter = inst->getNoneRefNativePtrMap().find(s.nativeThisObject());
    if (iter != inst->getNoneRefNativePtrMap().end())
    {
        inst->getNoneRefNativePtrMap().erase(iter);
        dragonBones::CCFactory* cobj = (dragonBones::CCFactory*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_dragonBones_CCFactory_finalize)

bool js_register_cocos2dx_dragonbones_CCFactory(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "CCFactory", obj, __jsb_dragonBones_BaseFactory_proto, _SE(js_cocos2dx_dragonbones_CCFactory_constructor));

    cls->defineFunction(inst, "setTimeScale", _SE(js_cocos2dx_dragonbones_CCFactory_setTimeScale));
    cls->defineFunction(inst, "getSoundEventManager", _SE(js_cocos2dx_dragonbones_CCFactory_getSoundEventManager));
    cls->defineFunction(inst, "render", _SE(js_cocos2dx_dragonbones_CCFactory_render));
    cls->defineFunction(inst, "removeDragonBonesDataByUUID", _SE(js_cocos2dx_dragonbones_CCFactory_removeDragonBonesDataByUUID));
    cls->defineFunction(inst, "update", _SE(js_cocos2dx_dragonbones_CCFactory_update));
    cls->defineFunction(inst, "remove", _SE(js_cocos2dx_dragonbones_CCFactory_remove));
    cls->defineFunction(inst, "getTextureAtlasDataByIndex", _SE(js_cocos2dx_dragonbones_CCFactory_getTextureAtlasDataByIndex));
    cls->defineFunction(inst, "getDragonBones", _SE(js_cocos2dx_dragonbones_CCFactory_getDragonBones));
    cls->defineFunction(inst, "parseDragonBonesDataByPath", _SE(js_cocos2dx_dragonbones_CCFactory_parseDragonBonesDataByPath));
    cls->defineFunction(inst, "add", _SE(js_cocos2dx_dragonbones_CCFactory_add));
    cls->defineFunction(inst, "buildArmatureDisplay", _SE(js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay));
    cls->defineFunction(inst, "stopSchedule", _SE(js_cocos2dx_dragonbones_CCFactory_stopSchedule));
    cls->defineFunction(inst, "removeTextureAtlasDataByIndex", _SE(js_cocos2dx_dragonbones_CCFactory_removeTextureAtlasDataByIndex));
    cls->defineFunction(inst, "getTimeScale", _SE(js_cocos2dx_dragonbones_CCFactory_getTimeScale));
    cls->defineStaticFunction(inst, "isInit", _SE(js_cocos2dx_dragonbones_CCFactory_isInit));
    cls->defineStaticFunction(inst, "destroyFactory", _SE(js_cocos2dx_dragonbones_CCFactory_destroyFactory));
    cls->defineStaticFunction(inst, "getClock", _SE(js_cocos2dx_dragonbones_CCFactory_getClock));
    cls->defineStaticFunction(inst, "getInstance", _SE(js_cocos2dx_dragonbones_CCFactory_getFactory));
    cls->defineFinalizeFunction(_SE(js_dragonBones_CCFactory_finalize));
    cls->install(inst);
    inst->registerClass<dragonBones::CCFactory>(cls);

    __jsb_dragonBones_CCFactory_proto = cls->getProto();
    __jsb_dragonBones_CCFactory_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_ArmatureCacheMgr_proto = nullptr;
se::Class* __jsb_dragonBones_ArmatureCacheMgr_class = nullptr;

static bool js_cocos2dx_dragonbones_ArmatureCacheMgr_removeArmatureCache(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureCacheMgr* cobj = (dragonBones::ArmatureCacheMgr*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureCacheMgr_removeArmatureCache : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureCacheMgr_removeArmatureCache : Error processing arguments");
        cobj->removeArmatureCache(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureCacheMgr_removeArmatureCache)

static bool js_cocos2dx_dragonbones_ArmatureCacheMgr_buildArmatureCache(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::ArmatureCacheMgr* cobj = (dragonBones::ArmatureCacheMgr*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_ArmatureCacheMgr_buildArmatureCache : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        ok &= seval_to_std_string(inst, args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureCacheMgr_buildArmatureCache : Error processing arguments");
        dragonBones::ArmatureCache* result = cobj->buildArmatureCache(arg0, arg1, arg2);
        ok &= native_ptr_to_seval<dragonBones::ArmatureCache>(inst, (dragonBones::ArmatureCache*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureCacheMgr_buildArmatureCache : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureCacheMgr_buildArmatureCache)

static bool js_cocos2dx_dragonbones_ArmatureCacheMgr_destroyInstance(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        dragonBones::ArmatureCacheMgr::destroyInstance();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureCacheMgr_destroyInstance)

static bool js_cocos2dx_dragonbones_ArmatureCacheMgr_getInstance(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::ArmatureCacheMgr* result = dragonBones::ArmatureCacheMgr::getInstance();
        ok &= native_ptr_to_seval<dragonBones::ArmatureCacheMgr>(inst, (dragonBones::ArmatureCacheMgr*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_ArmatureCacheMgr_getInstance : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_ArmatureCacheMgr_getInstance)



static bool js_dragonBones_ArmatureCacheMgr_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (dragonBones::ArmatureCacheMgr)", s.nativeThisObject());
    auto iter = inst->getNoneRefNativePtrMap().find(s.nativeThisObject());
    if (iter != inst->getNoneRefNativePtrMap().end())
    {
        inst->getNoneRefNativePtrMap().erase(iter);
        dragonBones::ArmatureCacheMgr* cobj = (dragonBones::ArmatureCacheMgr*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_dragonBones_ArmatureCacheMgr_finalize)

bool js_register_cocos2dx_dragonbones_ArmatureCacheMgr(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "ArmatureCacheMgr", obj, nullptr, nullptr);

    cls->defineFunction(inst, "removeArmatureCache", _SE(js_cocos2dx_dragonbones_ArmatureCacheMgr_removeArmatureCache));
    cls->defineFunction(inst, "buildArmatureCache", _SE(js_cocos2dx_dragonbones_ArmatureCacheMgr_buildArmatureCache));
    cls->defineStaticFunction(inst, "destroyInstance", _SE(js_cocos2dx_dragonbones_ArmatureCacheMgr_destroyInstance));
    cls->defineStaticFunction(inst, "getInstance", _SE(js_cocos2dx_dragonbones_ArmatureCacheMgr_getInstance));
    cls->defineFinalizeFunction(_SE(js_dragonBones_ArmatureCacheMgr_finalize));
    cls->install(inst);
    inst->registerClass<dragonBones::ArmatureCacheMgr>(cls);

    __jsb_dragonBones_ArmatureCacheMgr_proto = cls->getProto();
    __jsb_dragonBones_ArmatureCacheMgr_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_CCArmatureCacheDisplay_proto = nullptr;
se::Class* __jsb_dragonBones_CCArmatureCacheDisplay_class = nullptr;

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setTimeScale(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setTimeScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setTimeScale : Error processing arguments");
        cobj->setTimeScale(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setTimeScale)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_render(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_render : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_render : Error processing arguments");
        cobj->render(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_render)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_addDBEventListener(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_addDBEventListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_addDBEventListener : Error processing arguments");
        cobj->addDBEventListener(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_addDBEventListener)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setAttachUtil(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setAttachUtil : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        dragonBones::CacheModeAttachUtil* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setAttachUtil : Error processing arguments");
        cobj->setAttachUtil(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setAttachUtil)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_removeDBEventListener(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_removeDBEventListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_removeDBEventListener : Error processing arguments");
        cobj->removeDBEventListener(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_removeDBEventListener)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_onEnable(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_onEnable : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->onEnable();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_onEnable)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setEffect(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setEffect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::renderer::EffectVariant* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setEffect : Error processing arguments");
        cobj->setEffect(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setEffect)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_dispose(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_dispose : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->dispose();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_dispose)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setOpacityModifyRGB(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setOpacityModifyRGB : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setOpacityModifyRGB : Error processing arguments");
        cobj->setOpacityModifyRGB(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setOpacityModifyRGB)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_dispatchDBEvent(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_dispatchDBEvent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        dragonBones::EventObject* arg1 = nullptr;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_dispatchDBEvent : Error processing arguments");
        cobj->dispatchDBEvent(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_dispatchDBEvent)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_beginSchedule(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_beginSchedule : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->beginSchedule();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_beginSchedule)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_updateAllAnimationCache(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_updateAllAnimationCache : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->updateAllAnimationCache();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_updateAllAnimationCache)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_update(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_update : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_update : Error processing arguments");
        cobj->update(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_update)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_playAnimation(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_playAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        int arg1 = 0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[1], &tmp); arg1 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_playAnimation : Error processing arguments");
        cobj->playAnimation(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_playAnimation)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setDBEventCallback(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setDBEventCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void (dragonBones::EventObject *)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](dragonBones::EventObject* larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= native_ptr_to_rooted_seval<dragonBones::EventObject>(inst, (dragonBones::EventObject*)larg0, &args[0]);
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
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setDBEventCallback : Error processing arguments");
        cobj->setDBEventCallback(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setDBEventCallback)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_updateAnimationCache(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_updateAnimationCache : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_updateAnimationCache : Error processing arguments");
        cobj->updateAnimationCache(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_updateAnimationCache)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_getTimeScale(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_getTimeScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTimeScale();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_getTimeScale : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_getTimeScale)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_getAnimation(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_getAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Animation* result = cobj->getAnimation();
        ok &= native_ptr_to_rooted_seval<dragonBones::Animation>(inst, (dragonBones::Animation*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_getAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_getAnimation)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_onDisable(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_onDisable : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->onDisable();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_onDisable)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setColor(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Color4B arg0;
        ok &= seval_to_Color4B(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setColor : Error processing arguments");
        cobj->setColor(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setColor)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_bindNodeProxy(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_bindNodeProxy : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::renderer::NodeProxy* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_bindNodeProxy : Error processing arguments");
        cobj->bindNodeProxy(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_bindNodeProxy)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setBatchEnabled(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setBatchEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setBatchEnabled : Error processing arguments");
        cobj->setBatchEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setBatchEnabled)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_getArmature(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_getArmature : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        dragonBones::Armature* result = cobj->getArmature();
        ok &= native_ptr_to_rooted_seval<dragonBones::Armature>(inst, (dragonBones::Armature*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_getArmature : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_getArmature)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_stopSchedule(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_stopSchedule : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->stopSchedule();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_stopSchedule)

SE_DECLARE_FINALIZE_FUNC(js_dragonBones_CCArmatureCacheDisplay_finalize)

static bool js_cocos2dx_dragonbones_CCArmatureCacheDisplay_constructor(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    std::string arg0;
    std::string arg1;
    std::string arg2;
    bool arg3;
    ok &= seval_to_std_string(inst, args[0], &arg0);
    ok &= seval_to_std_string(inst, args[1], &arg1);
    ok &= seval_to_std_string(inst, args[2], &arg2);
    ok &= seval_to_boolean(inst, args[3], &arg3);
    SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_CCArmatureCacheDisplay_constructor : Error processing arguments");
    dragonBones::CCArmatureCacheDisplay* cobj = new (std::nothrow) dragonBones::CCArmatureCacheDisplay(arg0, arg1, arg2, arg3);
    s.thisObject(inst)->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_constructor, __jsb_dragonBones_CCArmatureCacheDisplay_class, js_dragonBones_CCArmatureCacheDisplay_finalize)




static bool js_dragonBones_CCArmatureCacheDisplay_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (dragonBones::CCArmatureCacheDisplay)", s.nativeThisObject());
    dragonBones::CCArmatureCacheDisplay* cobj = (dragonBones::CCArmatureCacheDisplay*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_dragonBones_CCArmatureCacheDisplay_finalize)

bool js_register_cocos2dx_dragonbones_CCArmatureCacheDisplay(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "CCArmatureCacheDisplay", obj, nullptr, _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_constructor));

    cls->defineFunction(inst, "setTimeScale", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setTimeScale));
    cls->defineFunction(inst, "render", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_render));
    cls->defineFunction(inst, "addDBEventListener", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_addDBEventListener));
    cls->defineFunction(inst, "setAttachUtil", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setAttachUtil));
    cls->defineFunction(inst, "removeDBEventListener", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_removeDBEventListener));
    cls->defineFunction(inst, "onEnable", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_onEnable));
    cls->defineFunction(inst, "setEffect", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setEffect));
    cls->defineFunction(inst, "dispose", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_dispose));
    cls->defineFunction(inst, "setOpacityModifyRGB", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setOpacityModifyRGB));
    cls->defineFunction(inst, "dispatchDBEvent", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_dispatchDBEvent));
    cls->defineFunction(inst, "beginSchedule", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_beginSchedule));
    cls->defineFunction(inst, "updateAllAnimationCache", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_updateAllAnimationCache));
    cls->defineFunction(inst, "update", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_update));
    cls->defineFunction(inst, "playAnimation", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_playAnimation));
    cls->defineFunction(inst, "setDBEventCallback", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setDBEventCallback));
    cls->defineFunction(inst, "updateAnimationCache", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_updateAnimationCache));
    cls->defineFunction(inst, "getTimeScale", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_getTimeScale));
    cls->defineFunction(inst, "getAnimation", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_getAnimation));
    cls->defineFunction(inst, "onDisable", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_onDisable));
    cls->defineFunction(inst, "setColor", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setColor));
    cls->defineFunction(inst, "bindNodeProxy", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_bindNodeProxy));
    cls->defineFunction(inst, "setBatchEnabled", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_setBatchEnabled));
    cls->defineFunction(inst, "armature", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_getArmature));
    cls->defineFunction(inst, "stopSchedule", _SE(js_cocos2dx_dragonbones_CCArmatureCacheDisplay_stopSchedule));
    cls->defineFinalizeFunction(_SE(js_dragonBones_CCArmatureCacheDisplay_finalize));
    cls->install(inst);
    inst->registerClass<dragonBones::CCArmatureCacheDisplay>(cls);

    __jsb_dragonBones_CCArmatureCacheDisplay_proto = cls->getProto();
    __jsb_dragonBones_CCArmatureCacheDisplay_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_AttachUtilBase_proto = nullptr;
se::Class* __jsb_dragonBones_AttachUtilBase_class = nullptr;

static bool js_cocos2dx_dragonbones_AttachUtilBase_associateAttachedNode(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::AttachUtilBase* cobj = (dragonBones::AttachUtilBase*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_dragonbones_AttachUtilBase_associateAttachedNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        dragonBones::Armature* arg0 = nullptr;
        cocos2d::renderer::NodeProxy* arg1 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        ok &= seval_to_native_ptr(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_dragonbones_AttachUtilBase_associateAttachedNode : Error processing arguments");
        cobj->associateAttachedNode(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AttachUtilBase_associateAttachedNode)




bool js_register_cocos2dx_dragonbones_AttachUtilBase(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "AttachUtilBase", obj, nullptr, nullptr);

    cls->defineFunction(inst, "associateAttachedNode", _SE(js_cocos2dx_dragonbones_AttachUtilBase_associateAttachedNode));
    cls->install(inst);
    inst->registerClass<dragonBones::AttachUtilBase>(cls);

    __jsb_dragonBones_AttachUtilBase_proto = cls->getProto();
    __jsb_dragonBones_AttachUtilBase_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_RealTimeAttachUtil_proto = nullptr;
se::Class* __jsb_dragonBones_RealTimeAttachUtil_class = nullptr;

SE_DECLARE_FINALIZE_FUNC(js_dragonBones_RealTimeAttachUtil_finalize)

static bool js_cocos2dx_dragonbones_RealTimeAttachUtil_constructor(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::RealTimeAttachUtil* cobj = new (std::nothrow) dragonBones::RealTimeAttachUtil();
    s.thisObject(inst)->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_dragonbones_RealTimeAttachUtil_constructor, __jsb_dragonBones_RealTimeAttachUtil_class, js_dragonBones_RealTimeAttachUtil_finalize)



extern se::Object* __jsb_dragonBones_AttachUtilBase_proto;

static bool js_dragonBones_RealTimeAttachUtil_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (dragonBones::RealTimeAttachUtil)", s.nativeThisObject());
    dragonBones::RealTimeAttachUtil* cobj = (dragonBones::RealTimeAttachUtil*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_dragonBones_RealTimeAttachUtil_finalize)

bool js_register_cocos2dx_dragonbones_RealTimeAttachUtil(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "RealTimeAttachUtil", obj, __jsb_dragonBones_AttachUtilBase_proto, _SE(js_cocos2dx_dragonbones_RealTimeAttachUtil_constructor));

    cls->defineFinalizeFunction(_SE(js_dragonBones_RealTimeAttachUtil_finalize));
    cls->install(inst);
    inst->registerClass<dragonBones::RealTimeAttachUtil>(cls);

    __jsb_dragonBones_RealTimeAttachUtil_proto = cls->getProto();
    __jsb_dragonBones_RealTimeAttachUtil_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_dragonBones_CacheModeAttachUtil_proto = nullptr;
se::Class* __jsb_dragonBones_CacheModeAttachUtil_class = nullptr;

SE_DECLARE_FINALIZE_FUNC(js_dragonBones_CacheModeAttachUtil_finalize)

static bool js_cocos2dx_dragonbones_CacheModeAttachUtil_constructor(se::State &s, se::ScriptEngine *inst)
{
    dragonBones::CacheModeAttachUtil* cobj = new (std::nothrow) dragonBones::CacheModeAttachUtil();
    s.thisObject(inst)->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_dragonbones_CacheModeAttachUtil_constructor, __jsb_dragonBones_CacheModeAttachUtil_class, js_dragonBones_CacheModeAttachUtil_finalize)



extern se::Object* __jsb_dragonBones_AttachUtilBase_proto;

static bool js_dragonBones_CacheModeAttachUtil_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (dragonBones::CacheModeAttachUtil)", s.nativeThisObject());
    dragonBones::CacheModeAttachUtil* cobj = (dragonBones::CacheModeAttachUtil*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_dragonBones_CacheModeAttachUtil_finalize)

bool js_register_cocos2dx_dragonbones_CacheModeAttachUtil(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "CacheModeAttachUtil", obj, __jsb_dragonBones_AttachUtilBase_proto, _SE(js_cocos2dx_dragonbones_CacheModeAttachUtil_constructor));

    cls->defineFinalizeFunction(_SE(js_dragonBones_CacheModeAttachUtil_finalize));
    cls->install(inst);
    inst->registerClass<dragonBones::CacheModeAttachUtil>(cls);

    __jsb_dragonBones_CacheModeAttachUtil_proto = cls->getProto();
    __jsb_dragonBones_CacheModeAttachUtil_class = cls;

    inst->clearException();
    return true;
}

bool register_all_cocos2dx_dragonbones(se::ScriptEngine *inst, se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("dragonBones", &nsVal))
    {
        se::HandleObject jsobj(se::Object::createPlainObject(inst));
        nsVal.setObject(jsobj);
        obj->setProperty("dragonBones", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_cocos2dx_dragonbones_BaseObject(inst, ns);
    js_register_cocos2dx_dragonbones_TransformObject(inst, ns);
    js_register_cocos2dx_dragonbones_Slot(inst, ns);
    js_register_cocos2dx_dragonbones_AttachUtilBase(inst, ns);
    js_register_cocos2dx_dragonbones_RealTimeAttachUtil(inst, ns);
    js_register_cocos2dx_dragonbones_Matrix(inst, ns);
    js_register_cocos2dx_dragonbones_BoundingBoxData(inst, ns);
    js_register_cocos2dx_dragonbones_PolygonBoundingBoxData(inst, ns);
    js_register_cocos2dx_dragonbones_Transform(inst, ns);
    js_register_cocos2dx_dragonbones_Animation(inst, ns);
    js_register_cocos2dx_dragonbones_TextureData(inst, ns);
    js_register_cocos2dx_dragonbones_CCTextureData(inst, ns);
    js_register_cocos2dx_dragonbones_BaseFactory(inst, ns);
    js_register_cocos2dx_dragonbones_CCFactory(inst, ns);
    js_register_cocos2dx_dragonbones_WorldClock(inst, ns);
    js_register_cocos2dx_dragonbones_TextureAtlasData(inst, ns);
    js_register_cocos2dx_dragonbones_CCArmatureDisplay(inst, ns);
    js_register_cocos2dx_dragonbones_AnimationState(inst, ns);
    js_register_cocos2dx_dragonbones_BoneData(inst, ns);
    js_register_cocos2dx_dragonbones_EllipseBoundingBoxData(inst, ns);
    js_register_cocos2dx_dragonbones_ArmatureData(inst, ns);
    js_register_cocos2dx_dragonbones_CCTextureAtlasData(inst, ns);
    js_register_cocos2dx_dragonbones_CCSlot(inst, ns);
    js_register_cocos2dx_dragonbones_Armature(inst, ns);
    js_register_cocos2dx_dragonbones_Bone(inst, ns);
    js_register_cocos2dx_dragonbones_UserData(inst, ns);
    js_register_cocos2dx_dragonbones_RectangleBoundingBoxData(inst, ns);
    js_register_cocos2dx_dragonbones_CacheModeAttachUtil(inst, ns);
    js_register_cocos2dx_dragonbones_ArmatureCacheMgr(inst, ns);
    js_register_cocos2dx_dragonbones_SkinData(inst, ns);
    js_register_cocos2dx_dragonbones_EventObject(inst, ns);
    js_register_cocos2dx_dragonbones_SlotData(inst, ns);
    js_register_cocos2dx_dragonbones_DragonBonesData(inst, ns);
    js_register_cocos2dx_dragonbones_AnimationData(inst, ns);
    js_register_cocos2dx_dragonbones_CCArmatureCacheDisplay(inst, ns);
    return true;
}

#endif //#if USE_DRAGONBONES > 0
