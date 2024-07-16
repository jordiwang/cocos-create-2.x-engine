#include "scripting/js-bindings/auto/jsb_cocos2dx_editor_support_auto.hpp"
#if USE_MIDDLEWARE > 0
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "editor-support/middleware-adapter.h"
#include "editor-support/MiddlewareManager.h"

se::Object* __jsb_cocos2d_middleware_Texture2D_proto = nullptr;
se::Class* __jsb_cocos2d_middleware_Texture2D_class = nullptr;

static bool js_cocos2dx_editor_support_Texture2D_getRealTextureIndex(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::middleware::Texture2D* cobj = (cocos2d::middleware::Texture2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_editor_support_Texture2D_getRealTextureIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getRealTextureIndex();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_editor_support_Texture2D_getRealTextureIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_editor_support_Texture2D_getRealTextureIndex)

static bool js_cocos2dx_editor_support_Texture2D_setTexParamCallback(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::middleware::Texture2D* cobj = (cocos2d::middleware::Texture2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_editor_support_Texture2D_setTexParamCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void (int, unsigned int, unsigned int, unsigned int, unsigned int)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](int larg0, unsigned int larg1, unsigned int larg2, unsigned int larg3, unsigned int larg4) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(5);
                    ok &= int32_to_seval(inst, larg0, &args[0]);
                    ok &= uint32_to_seval(inst, larg1, &args[1]);
                    ok &= uint32_to_seval(inst, larg2, &args[2]);
                    ok &= uint32_to_seval(inst, larg3, &args[3]);
                    ok &= uint32_to_seval(inst, larg4, &args[4]);
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
        SE_PRECONDITION2(ok, false, "js_cocos2dx_editor_support_Texture2D_setTexParamCallback : Error processing arguments");
        cobj->setTexParamCallback(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_editor_support_Texture2D_setTexParamCallback)

static bool js_cocos2dx_editor_support_Texture2D_setPixelsHigh(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::middleware::Texture2D* cobj = (cocos2d::middleware::Texture2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_editor_support_Texture2D_setPixelsHigh : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_editor_support_Texture2D_setPixelsHigh : Error processing arguments");
        cobj->setPixelsHigh(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_editor_support_Texture2D_setPixelsHigh)

static bool js_cocos2dx_editor_support_Texture2D_getNativeTexture(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::middleware::Texture2D* cobj = (cocos2d::middleware::Texture2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_editor_support_Texture2D_getNativeTexture : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::renderer::Texture* result = cobj->getNativeTexture();
        ok &= native_ptr_to_seval<cocos2d::renderer::Texture>(inst, (cocos2d::renderer::Texture*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_editor_support_Texture2D_getNativeTexture : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_editor_support_Texture2D_getNativeTexture)

static bool js_cocos2dx_editor_support_Texture2D_setPixelsWide(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::middleware::Texture2D* cobj = (cocos2d::middleware::Texture2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_editor_support_Texture2D_setPixelsWide : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_editor_support_Texture2D_setPixelsWide : Error processing arguments");
        cobj->setPixelsWide(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_editor_support_Texture2D_setPixelsWide)

static bool js_cocos2dx_editor_support_Texture2D_getPixelsHigh(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::middleware::Texture2D* cobj = (cocos2d::middleware::Texture2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_editor_support_Texture2D_getPixelsHigh : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPixelsHigh();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_editor_support_Texture2D_getPixelsHigh : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_editor_support_Texture2D_getPixelsHigh)

static bool js_cocos2dx_editor_support_Texture2D_getPixelsWide(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::middleware::Texture2D* cobj = (cocos2d::middleware::Texture2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_editor_support_Texture2D_getPixelsWide : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getPixelsWide();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_editor_support_Texture2D_getPixelsWide : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_editor_support_Texture2D_getPixelsWide)

static bool js_cocos2dx_editor_support_Texture2D_setRealTextureIndex(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::middleware::Texture2D* cobj = (cocos2d::middleware::Texture2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_editor_support_Texture2D_setRealTextureIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_editor_support_Texture2D_setRealTextureIndex : Error processing arguments");
        cobj->setRealTextureIndex(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_editor_support_Texture2D_setRealTextureIndex)

static bool js_cocos2dx_editor_support_Texture2D_setNativeTexture(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::middleware::Texture2D* cobj = (cocos2d::middleware::Texture2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_editor_support_Texture2D_setNativeTexture : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::renderer::Texture* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_editor_support_Texture2D_setNativeTexture : Error processing arguments");
        cobj->setNativeTexture(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_editor_support_Texture2D_setNativeTexture)

static bool js_cocos2dx_editor_support_Texture2D_setTexParameters(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::middleware::Texture2D* cobj = (cocos2d::middleware::Texture2D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_editor_support_Texture2D_setTexParameters : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::middleware::Texture2D::_TexParams arg0;
        #pragma warning NO CONVERSION TO NATIVE FOR _TexParams
        ok = false;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_editor_support_Texture2D_setTexParameters : Error processing arguments");
        cobj->setTexParameters(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_editor_support_Texture2D_setTexParameters)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_middleware_Texture2D_finalize)

static bool js_cocos2dx_editor_support_Texture2D_constructor(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::middleware::Texture2D* cobj = new (std::nothrow) cocos2d::middleware::Texture2D();
    s.thisObject(inst)->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_editor_support_Texture2D_constructor, __jsb_cocos2d_middleware_Texture2D_class, js_cocos2d_middleware_Texture2D_finalize)




static bool js_cocos2d_middleware_Texture2D_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::middleware::Texture2D)", s.nativeThisObject());
    cocos2d::middleware::Texture2D* cobj = (cocos2d::middleware::Texture2D*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_middleware_Texture2D_finalize)

bool js_register_cocos2dx_editor_support_Texture2D(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Texture2D", obj, nullptr, _SE(js_cocos2dx_editor_support_Texture2D_constructor));

    cls->defineFunction(inst, "getRealTextureIndex", _SE(js_cocos2dx_editor_support_Texture2D_getRealTextureIndex));
    cls->defineFunction(inst, "setTexParamCallback", _SE(js_cocos2dx_editor_support_Texture2D_setTexParamCallback));
    cls->defineFunction(inst, "setPixelsHigh", _SE(js_cocos2dx_editor_support_Texture2D_setPixelsHigh));
    cls->defineFunction(inst, "getNativeTexture", _SE(js_cocos2dx_editor_support_Texture2D_getNativeTexture));
    cls->defineFunction(inst, "setPixelsWide", _SE(js_cocos2dx_editor_support_Texture2D_setPixelsWide));
    cls->defineFunction(inst, "getPixelsHigh", _SE(js_cocos2dx_editor_support_Texture2D_getPixelsHigh));
    cls->defineFunction(inst, "getPixelsWide", _SE(js_cocos2dx_editor_support_Texture2D_getPixelsWide));
    cls->defineFunction(inst, "setRealTextureIndex", _SE(js_cocos2dx_editor_support_Texture2D_setRealTextureIndex));
    cls->defineFunction(inst, "setNativeTexture", _SE(js_cocos2dx_editor_support_Texture2D_setNativeTexture));
    cls->defineFunction(inst, "setTexParameters", _SE(js_cocos2dx_editor_support_Texture2D_setTexParameters));
    cls->defineFinalizeFunction(_SE(js_cocos2d_middleware_Texture2D_finalize));
    cls->install(inst);
    inst->registerClass<cocos2d::middleware::Texture2D>(cls);

    __jsb_cocos2d_middleware_Texture2D_proto = cls->getProto();
    __jsb_cocos2d_middleware_Texture2D_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_cocos2d_middleware_MiddlewareManager_proto = nullptr;
se::Class* __jsb_cocos2d_middleware_MiddlewareManager_class = nullptr;

static bool js_cocos2dx_editor_support_MiddlewareManager_render(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::middleware::MiddlewareManager* cobj = (cocos2d::middleware::MiddlewareManager*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_editor_support_MiddlewareManager_render : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_editor_support_MiddlewareManager_render : Error processing arguments");
        cobj->render(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_editor_support_MiddlewareManager_render)

static bool js_cocos2dx_editor_support_MiddlewareManager_update(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::middleware::MiddlewareManager* cobj = (cocos2d::middleware::MiddlewareManager*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_editor_support_MiddlewareManager_update : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_editor_support_MiddlewareManager_update : Error processing arguments");
        cobj->update(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_editor_support_MiddlewareManager_update)

static bool js_cocos2dx_editor_support_MiddlewareManager_destroyInstance(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cocos2d::middleware::MiddlewareManager::destroyInstance();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_editor_support_MiddlewareManager_destroyInstance)

static bool js_cocos2dx_editor_support_MiddlewareManager_generateModuleID(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        uint8_t result = cocos2d::middleware::MiddlewareManager::generateModuleID();
        ok &= uint8_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_editor_support_MiddlewareManager_generateModuleID : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_editor_support_MiddlewareManager_generateModuleID)

static bool js_cocos2dx_editor_support_MiddlewareManager_getInstance(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::middleware::MiddlewareManager* result = cocos2d::middleware::MiddlewareManager::getInstance();
        ok &= native_ptr_to_seval<cocos2d::middleware::MiddlewareManager>(inst, (cocos2d::middleware::MiddlewareManager*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_editor_support_MiddlewareManager_getInstance : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_editor_support_MiddlewareManager_getInstance)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_middleware_MiddlewareManager_finalize)

static bool js_cocos2dx_editor_support_MiddlewareManager_constructor(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::middleware::MiddlewareManager* cobj = new (std::nothrow) cocos2d::middleware::MiddlewareManager();
    s.thisObject(inst)->setPrivateData(cobj);
    inst->getNoneRefNativePtrMap().emplace(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_editor_support_MiddlewareManager_constructor, __jsb_cocos2d_middleware_MiddlewareManager_class, js_cocos2d_middleware_MiddlewareManager_finalize)




static bool js_cocos2d_middleware_MiddlewareManager_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::middleware::MiddlewareManager)", s.nativeThisObject());
    auto iter = inst->getNoneRefNativePtrMap().find(s.nativeThisObject());
    if (iter != inst->getNoneRefNativePtrMap().end())
    {
        inst->getNoneRefNativePtrMap().erase(iter);
        cocos2d::middleware::MiddlewareManager* cobj = (cocos2d::middleware::MiddlewareManager*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_middleware_MiddlewareManager_finalize)

bool js_register_cocos2dx_editor_support_MiddlewareManager(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "MiddlewareManager", obj, nullptr, _SE(js_cocos2dx_editor_support_MiddlewareManager_constructor));

    cls->defineFunction(inst, "render", _SE(js_cocos2dx_editor_support_MiddlewareManager_render));
    cls->defineFunction(inst, "update", _SE(js_cocos2dx_editor_support_MiddlewareManager_update));
    cls->defineStaticFunction(inst, "destroyInstance", _SE(js_cocos2dx_editor_support_MiddlewareManager_destroyInstance));
    cls->defineStaticFunction(inst, "generateModuleID", _SE(js_cocos2dx_editor_support_MiddlewareManager_generateModuleID));
    cls->defineStaticFunction(inst, "getInstance", _SE(js_cocos2dx_editor_support_MiddlewareManager_getInstance));
    cls->defineFinalizeFunction(_SE(js_cocos2d_middleware_MiddlewareManager_finalize));
    cls->install(inst);
    inst->registerClass<cocos2d::middleware::MiddlewareManager>(cls);

    __jsb_cocos2d_middleware_MiddlewareManager_proto = cls->getProto();
    __jsb_cocos2d_middleware_MiddlewareManager_class = cls;

    inst->clearException();
    return true;
}

bool register_all_cocos2dx_editor_support(se::ScriptEngine *inst, se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("middleware", &nsVal))
    {
        se::HandleObject jsobj(se::Object::createPlainObject(inst));
        nsVal.setObject(jsobj);
        obj->setProperty("middleware", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_cocos2dx_editor_support_MiddlewareManager(inst, ns);
    js_register_cocos2dx_editor_support_Texture2D(inst, ns);
    return true;
}

#endif //#if USE_MIDDLEWARE > 0
