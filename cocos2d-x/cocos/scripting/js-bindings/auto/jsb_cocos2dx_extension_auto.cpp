#include "scripting/js-bindings/auto/jsb_cocos2dx_extension_auto.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "extensions/cocos-ext.h"

se::Object* __jsb_cocos2d_extension_EventAssetsManagerEx_proto = nullptr;
se::Class* __jsb_cocos2d_extension_EventAssetsManagerEx_class = nullptr;

static bool js_extension_EventAssetsManagerEx_getAssetsManagerEx(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::EventAssetsManagerEx* cobj = (cocos2d::extension::EventAssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_EventAssetsManagerEx_getAssetsManagerEx : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::extension::AssetsManagerEx* result = cobj->getAssetsManagerEx();
        ok &= native_ptr_to_seval<cocos2d::extension::AssetsManagerEx>(inst, (cocos2d::extension::AssetsManagerEx*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_EventAssetsManagerEx_getAssetsManagerEx : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_EventAssetsManagerEx_getAssetsManagerEx)

static bool js_extension_EventAssetsManagerEx_getDownloadedFiles(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::EventAssetsManagerEx* cobj = (cocos2d::extension::EventAssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_EventAssetsManagerEx_getDownloadedFiles : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getDownloadedFiles();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_EventAssetsManagerEx_getDownloadedFiles : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_EventAssetsManagerEx_getDownloadedFiles)

static bool js_extension_EventAssetsManagerEx_getTotalFiles(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::EventAssetsManagerEx* cobj = (cocos2d::extension::EventAssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_EventAssetsManagerEx_getTotalFiles : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getTotalFiles();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_EventAssetsManagerEx_getTotalFiles : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_EventAssetsManagerEx_getTotalFiles)

static bool js_extension_EventAssetsManagerEx_getAssetId(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::EventAssetsManagerEx* cobj = (cocos2d::extension::EventAssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_EventAssetsManagerEx_getAssetId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = cobj->getAssetId();
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_EventAssetsManagerEx_getAssetId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_EventAssetsManagerEx_getAssetId)

static bool js_extension_EventAssetsManagerEx_getTotalBytes(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::EventAssetsManagerEx* cobj = (cocos2d::extension::EventAssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_EventAssetsManagerEx_getTotalBytes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        double result = cobj->getTotalBytes();
        ok &= double_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_EventAssetsManagerEx_getTotalBytes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_EventAssetsManagerEx_getTotalBytes)

static bool js_extension_EventAssetsManagerEx_getCURLECode(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::EventAssetsManagerEx* cobj = (cocos2d::extension::EventAssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_EventAssetsManagerEx_getCURLECode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getCURLECode();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_EventAssetsManagerEx_getCURLECode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_EventAssetsManagerEx_getCURLECode)

static bool js_extension_EventAssetsManagerEx_getMessage(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::EventAssetsManagerEx* cobj = (cocos2d::extension::EventAssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_EventAssetsManagerEx_getMessage : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = cobj->getMessage();
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_EventAssetsManagerEx_getMessage : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_EventAssetsManagerEx_getMessage)

static bool js_extension_EventAssetsManagerEx_getCURLMCode(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::EventAssetsManagerEx* cobj = (cocos2d::extension::EventAssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_EventAssetsManagerEx_getCURLMCode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getCURLMCode();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_EventAssetsManagerEx_getCURLMCode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_EventAssetsManagerEx_getCURLMCode)

static bool js_extension_EventAssetsManagerEx_getDownloadedBytes(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::EventAssetsManagerEx* cobj = (cocos2d::extension::EventAssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_EventAssetsManagerEx_getDownloadedBytes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        double result = cobj->getDownloadedBytes();
        ok &= double_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_EventAssetsManagerEx_getDownloadedBytes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_EventAssetsManagerEx_getDownloadedBytes)

static bool js_extension_EventAssetsManagerEx_getPercentByFile(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::EventAssetsManagerEx* cobj = (cocos2d::extension::EventAssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_EventAssetsManagerEx_getPercentByFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getPercentByFile();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_EventAssetsManagerEx_getPercentByFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_EventAssetsManagerEx_getPercentByFile)

static bool js_extension_EventAssetsManagerEx_getEventCode(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::EventAssetsManagerEx* cobj = (cocos2d::extension::EventAssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_EventAssetsManagerEx_getEventCode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = (int)cobj->getEventCode();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_EventAssetsManagerEx_getEventCode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_EventAssetsManagerEx_getEventCode)

static bool js_extension_EventAssetsManagerEx_getPercent(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::EventAssetsManagerEx* cobj = (cocos2d::extension::EventAssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_EventAssetsManagerEx_getPercent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getPercent();
        ok &= float_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_EventAssetsManagerEx_getPercent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_EventAssetsManagerEx_getPercent)

static bool js_extension_EventAssetsManagerEx_isResuming(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::EventAssetsManagerEx* cobj = (cocos2d::extension::EventAssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_EventAssetsManagerEx_isResuming : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isResuming();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_EventAssetsManagerEx_isResuming : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_EventAssetsManagerEx_isResuming)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_extension_EventAssetsManagerEx_finalize)

static bool js_extension_EventAssetsManagerEx_constructor(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    std::string arg0;
    cocos2d::extension::AssetsManagerEx* arg1 = nullptr;
    cocos2d::extension::EventAssetsManagerEx::EventCode arg2;
    ok &= seval_to_std_string(inst, args[0], &arg0);
    ok &= seval_to_native_ptr(inst, args[1], &arg1);
    do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[2], &tmp); arg2 = (cocos2d::extension::EventAssetsManagerEx::EventCode)tmp; } while(false);
    SE_PRECONDITION2(ok, false, "js_extension_EventAssetsManagerEx_constructor : Error processing arguments");
    cocos2d::extension::EventAssetsManagerEx* cobj = new (std::nothrow) cocos2d::extension::EventAssetsManagerEx(arg0, arg1, arg2);
    s.thisObject(inst)->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_extension_EventAssetsManagerEx_constructor, __jsb_cocos2d_extension_EventAssetsManagerEx_class, js_cocos2d_extension_EventAssetsManagerEx_finalize)




static bool js_cocos2d_extension_EventAssetsManagerEx_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::extension::EventAssetsManagerEx)", s.nativeThisObject());
    cocos2d::extension::EventAssetsManagerEx* cobj = (cocos2d::extension::EventAssetsManagerEx*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_extension_EventAssetsManagerEx_finalize)

bool js_register_extension_EventAssetsManagerEx(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "EventAssetsManager", obj, nullptr, _SE(js_extension_EventAssetsManagerEx_constructor));

    cls->defineFunction(inst, "getAssetsManagerEx", _SE(js_extension_EventAssetsManagerEx_getAssetsManagerEx));
    cls->defineFunction(inst, "getDownloadedFiles", _SE(js_extension_EventAssetsManagerEx_getDownloadedFiles));
    cls->defineFunction(inst, "getTotalFiles", _SE(js_extension_EventAssetsManagerEx_getTotalFiles));
    cls->defineFunction(inst, "getAssetId", _SE(js_extension_EventAssetsManagerEx_getAssetId));
    cls->defineFunction(inst, "getTotalBytes", _SE(js_extension_EventAssetsManagerEx_getTotalBytes));
    cls->defineFunction(inst, "getCURLECode", _SE(js_extension_EventAssetsManagerEx_getCURLECode));
    cls->defineFunction(inst, "getMessage", _SE(js_extension_EventAssetsManagerEx_getMessage));
    cls->defineFunction(inst, "getCURLMCode", _SE(js_extension_EventAssetsManagerEx_getCURLMCode));
    cls->defineFunction(inst, "getDownloadedBytes", _SE(js_extension_EventAssetsManagerEx_getDownloadedBytes));
    cls->defineFunction(inst, "getPercentByFile", _SE(js_extension_EventAssetsManagerEx_getPercentByFile));
    cls->defineFunction(inst, "getEventCode", _SE(js_extension_EventAssetsManagerEx_getEventCode));
    cls->defineFunction(inst, "getPercent", _SE(js_extension_EventAssetsManagerEx_getPercent));
    cls->defineFunction(inst, "isResuming", _SE(js_extension_EventAssetsManagerEx_isResuming));
    cls->defineFinalizeFunction(_SE(js_cocos2d_extension_EventAssetsManagerEx_finalize));
    cls->install(inst);
    inst->registerClass<cocos2d::extension::EventAssetsManagerEx>(cls);

    __jsb_cocos2d_extension_EventAssetsManagerEx_proto = cls->getProto();
    __jsb_cocos2d_extension_EventAssetsManagerEx_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_cocos2d_extension_Manifest_proto = nullptr;
se::Class* __jsb_cocos2d_extension_Manifest_class = nullptr;

static bool js_extension_Manifest_getManifestRoot(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_Manifest_getManifestRoot : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cobj->getManifestRoot();
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_Manifest_getManifestRoot : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_Manifest_getManifestRoot)

static bool js_extension_Manifest_setUpdating(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_Manifest_setUpdating : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_extension_Manifest_setUpdating : Error processing arguments");
        cobj->setUpdating(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_extension_Manifest_setUpdating)

static bool js_extension_Manifest_getManifestFileUrl(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_Manifest_getManifestFileUrl : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cobj->getManifestFileUrl();
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_Manifest_getManifestFileUrl : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_Manifest_getManifestFileUrl)

static bool js_extension_Manifest_isVersionLoaded(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_Manifest_isVersionLoaded : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isVersionLoaded();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_Manifest_isVersionLoaded : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_Manifest_isVersionLoaded)

static bool js_extension_Manifest_parseFile(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_Manifest_parseFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_extension_Manifest_parseFile : Error processing arguments");
        cobj->parseFile(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_extension_Manifest_parseFile)

static bool js_extension_Manifest_isLoaded(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_Manifest_isLoaded : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isLoaded();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_Manifest_isLoaded : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_Manifest_isLoaded)

static bool js_extension_Manifest_getPackageUrl(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_Manifest_getPackageUrl : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cobj->getPackageUrl();
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_Manifest_getPackageUrl : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_Manifest_getPackageUrl)

static bool js_extension_Manifest_isUpdating(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_Manifest_isUpdating : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isUpdating();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_Manifest_isUpdating : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_Manifest_isUpdating)

static bool js_extension_Manifest_getVersion(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_Manifest_getVersion : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cobj->getVersion();
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_Manifest_getVersion : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_Manifest_getVersion)

static bool js_extension_Manifest_parseJSONString(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_Manifest_parseJSONString : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_extension_Manifest_parseJSONString : Error processing arguments");
        cobj->parseJSONString(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_extension_Manifest_parseJSONString)

static bool js_extension_Manifest_getVersionFileUrl(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_Manifest_getVersionFileUrl : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cobj->getVersionFileUrl();
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_Manifest_getVersionFileUrl : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_Manifest_getVersionFileUrl)

static bool js_extension_Manifest_getSearchPaths(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_Manifest_getSearchPaths : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::vector<std::string> result = cobj->getSearchPaths();
        ok &= std_vector_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_Manifest_getSearchPaths : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_Manifest_getSearchPaths)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_extension_Manifest_finalize)

static bool js_extension_Manifest_constructor(se::State &s, se::ScriptEngine *inst)
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
            cocos2d::extension::Manifest* cobj = new (std::nothrow) cocos2d::extension::Manifest(arg0, arg1);
            s.thisObject(inst)->setPrivateData(cobj);
            return true;
        }
    } while(false);
    do {
        if (argc == 0) {
            cocos2d::extension::Manifest* cobj = new (std::nothrow) cocos2d::extension::Manifest();
            s.thisObject(inst)->setPrivateData(cobj);
            return true;
        }
    } while(false);
    do {
        if (argc == 1) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::extension::Manifest* cobj = new (std::nothrow) cocos2d::extension::Manifest(arg0);
            s.thisObject(inst)->setPrivateData(cobj);
            return true;
        }
    } while(false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_CTOR(js_extension_Manifest_constructor, __jsb_cocos2d_extension_Manifest_class, js_cocos2d_extension_Manifest_finalize)




static bool js_cocos2d_extension_Manifest_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::extension::Manifest)", s.nativeThisObject());
    cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_extension_Manifest_finalize)

bool js_register_extension_Manifest(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "Manifest", obj, nullptr, _SE(js_extension_Manifest_constructor));

    cls->defineFunction(inst, "getManifestRoot", _SE(js_extension_Manifest_getManifestRoot));
    cls->defineFunction(inst, "setUpdating", _SE(js_extension_Manifest_setUpdating));
    cls->defineFunction(inst, "getManifestFileUrl", _SE(js_extension_Manifest_getManifestFileUrl));
    cls->defineFunction(inst, "isVersionLoaded", _SE(js_extension_Manifest_isVersionLoaded));
    cls->defineFunction(inst, "parseFile", _SE(js_extension_Manifest_parseFile));
    cls->defineFunction(inst, "isLoaded", _SE(js_extension_Manifest_isLoaded));
    cls->defineFunction(inst, "getPackageUrl", _SE(js_extension_Manifest_getPackageUrl));
    cls->defineFunction(inst, "isUpdating", _SE(js_extension_Manifest_isUpdating));
    cls->defineFunction(inst, "getVersion", _SE(js_extension_Manifest_getVersion));
    cls->defineFunction(inst, "parseJSONString", _SE(js_extension_Manifest_parseJSONString));
    cls->defineFunction(inst, "getVersionFileUrl", _SE(js_extension_Manifest_getVersionFileUrl));
    cls->defineFunction(inst, "getSearchPaths", _SE(js_extension_Manifest_getSearchPaths));
    cls->defineFinalizeFunction(_SE(js_cocos2d_extension_Manifest_finalize));
    cls->install(inst);
    inst->registerClass<cocos2d::extension::Manifest>(cls);

    __jsb_cocos2d_extension_Manifest_proto = cls->getProto();
    __jsb_cocos2d_extension_Manifest_class = cls;

    inst->clearException();
    return true;
}

se::Object* __jsb_cocos2d_extension_AssetsManagerEx_proto = nullptr;
se::Class* __jsb_cocos2d_extension_AssetsManagerEx_class = nullptr;

static bool js_extension_AssetsManagerEx_getDownloadedFiles(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_getDownloadedFiles : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getDownloadedFiles();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_getDownloadedFiles : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_getDownloadedFiles)

static bool js_extension_AssetsManagerEx_setEventCallback(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_setEventCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void (cocos2d::extension::EventAssetsManagerEx *)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](cocos2d::extension::EventAssetsManagerEx* larg0) -> void {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= native_ptr_to_seval<cocos2d::extension::EventAssetsManagerEx>(inst, (cocos2d::extension::EventAssetsManagerEx*)larg0, &args[0]);
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
        SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_setEventCallback : Error processing arguments");
        cobj->setEventCallback(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_setEventCallback)

static bool js_extension_AssetsManagerEx_downloadFailedAssets(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_downloadFailedAssets : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->downloadFailedAssets();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_downloadFailedAssets)

static bool js_extension_AssetsManagerEx_getTotalFiles(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_getTotalFiles : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getTotalFiles();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_getTotalFiles : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_getTotalFiles)

static bool js_extension_AssetsManagerEx_checkUpdate(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_checkUpdate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->checkUpdate();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_checkUpdate)

static bool js_extension_AssetsManagerEx_loadLocalManifest(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_extension_AssetsManagerEx_loadLocalManifest : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            bool result = cobj->loadLocalManifest(arg0);
            ok &= boolean_to_seval(inst, result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_loadLocalManifest : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            cocos2d::extension::Manifest* arg0 = nullptr;
            ok &= seval_to_native_ptr(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            bool result = cobj->loadLocalManifest(arg0, arg1);
            ok &= boolean_to_seval(inst, result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_loadLocalManifest : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_loadLocalManifest)

static bool js_extension_AssetsManagerEx_setMaxConcurrentTask(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_setMaxConcurrentTask : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(inst, args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_setMaxConcurrentTask : Error processing arguments");
        cobj->setMaxConcurrentTask(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_setMaxConcurrentTask)

static bool js_extension_AssetsManagerEx_getLocalManifest(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_getLocalManifest : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::extension::Manifest* result = cobj->getLocalManifest();
        ok &= native_ptr_to_seval<cocos2d::extension::Manifest>(inst, (cocos2d::extension::Manifest*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_getLocalManifest : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_getLocalManifest)

static bool js_extension_AssetsManagerEx_getRemoteManifest(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_getRemoteManifest : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::extension::Manifest* result = cobj->getRemoteManifest();
        ok &= native_ptr_to_seval<cocos2d::extension::Manifest>(inst, (cocos2d::extension::Manifest*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_getRemoteManifest : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_getRemoteManifest)

static bool js_extension_AssetsManagerEx_cancelUpdate(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_cancelUpdate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->cancelUpdate();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_cancelUpdate)

static bool js_extension_AssetsManagerEx_isResuming(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_isResuming : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isResuming();
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_isResuming : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_isResuming)

static bool js_extension_AssetsManagerEx_getState(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_getState : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = (int)cobj->getState();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_getState : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_getState)

static bool js_extension_AssetsManagerEx_getMaxConcurrentTask(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_getMaxConcurrentTask : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const int result = cobj->getMaxConcurrentTask();
        ok &= int32_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_getMaxConcurrentTask : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_getMaxConcurrentTask)

static bool js_extension_AssetsManagerEx_setVersionCompareHandle(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_setVersionCompareHandle : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<int (const std::string&, const std::string&)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](const std::string& larg0, const std::string& larg1) -> int {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(2);
                    ok &= std_string_to_seval(inst, larg0, &args[0]);
                    ok &= std_string_to_seval(inst, larg1, &args[1]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                    int result;
                    do { int32_t tmp = 0; ok &= seval_to_int32(inst, rval, &tmp); result = (int)tmp; } while(false);
                    SE_PRECONDITION2(ok, result, "lambda function : Error processing return value with type int");
                    return result;
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_setVersionCompareHandle : Error processing arguments");
        cobj->setVersionCompareHandle(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_setVersionCompareHandle)

static bool js_extension_AssetsManagerEx_getTotalBytes(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_getTotalBytes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        double result = cobj->getTotalBytes();
        ok &= double_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_getTotalBytes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_getTotalBytes)

static bool js_extension_AssetsManagerEx_setVerifyCallback(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_setVerifyCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<bool (const std::string&, cocos2d::extension::ManifestAsset)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject(inst));
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](const std::string& larg0, cocos2d::extension::ManifestAsset larg1) -> bool {
                    inst->clearException();
                    se::AutoHandleScope hs(inst);
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(2);
                    ok &= std_string_to_seval(inst, larg0, &args[0]);
                    ok &= ManifestAsset_to_seval(inst, larg1, &args[1]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        inst->clearException();
                    }
                    bool result;
                    ok &= seval_to_boolean(inst, rval, &result);
                    SE_PRECONDITION2(ok, result, "lambda function : Error processing return value with type bool");
                    return result;
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_setVerifyCallback : Error processing arguments");
        cobj->setVerifyCallback(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_setVerifyCallback)

static bool js_extension_AssetsManagerEx_getStoragePath(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_getStoragePath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cobj->getStoragePath();
        ok &= std_string_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_getStoragePath : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_getStoragePath)

static bool js_extension_AssetsManagerEx_update(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_update : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->update();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_update)
static bool js_extension_AssetsManagerEx_stopWhenUpdateProcess(se::State &s, se::ScriptEngine *inst)
{
    printf("1111111 js_extension_AssetsManagerEx_stopWhenUpdateProcess");
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_stopWhenUpdateProcess : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->stopWhenUpdateProcess();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_stopWhenUpdateProcess)

static bool js_extension_AssetsManagerEx_getDownloadedBytes(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_getDownloadedBytes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        double result = cobj->getDownloadedBytes();
        ok &= double_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_getDownloadedBytes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_getDownloadedBytes)

static bool js_extension_AssetsManagerEx_prepareUpdate(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_prepareUpdate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->prepareUpdate();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_prepareUpdate)

static bool js_extension_AssetsManagerEx_loadRemoteManifest(se::State &s, se::ScriptEngine *inst)
{
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_extension_AssetsManagerEx_loadRemoteManifest : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::extension::Manifest* arg0 = nullptr;
        ok &= seval_to_native_ptr(inst, args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_loadRemoteManifest : Error processing arguments");
        bool result = cobj->loadRemoteManifest(arg0);
        ok &= boolean_to_seval(inst, result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_loadRemoteManifest : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_loadRemoteManifest)

static bool js_extension_AssetsManagerEx_create(se::State &s, se::ScriptEngine *inst)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(inst, args[0], &arg0);
        ok &= seval_to_std_string(inst, args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_extension_AssetsManagerEx_create : Error processing arguments");
        auto result = cocos2d::extension::AssetsManagerEx::create(arg0, arg1);
        result->retain();
        auto obj = se::Object::createObjectWithClass(inst, __jsb_cocos2d_extension_AssetsManagerEx_class);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_extension_AssetsManagerEx_create)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_extension_AssetsManagerEx_finalize)

static bool js_extension_AssetsManagerEx_constructor(se::State &s, se::ScriptEngine *inst)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 3) {
            std::string arg0;
            ok &= seval_to_std_string(inst, args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(inst, args[1], &arg1);
            if (!ok) { ok = true; break; }
            std::function<int (const std::string&, const std::string&)> arg2;
            do {
                if (args[2].isObject() && args[2].toObject()->isFunction())
                {
                    se::Value jsThis(s.thisObject(inst));
                    se::Value jsFunc(args[2]);
                    jsThis.toObject()->attachObject(jsFunc.toObject());
                    auto lambda = [=](const std::string& larg0, const std::string& larg1) -> int {
                        inst->clearException();
                        se::AutoHandleScope hs(inst);
            
                        CC_UNUSED bool ok = true;
                        se::ValueArray args;
                        args.resize(2);
                        ok &= std_string_to_seval(inst, larg0, &args[0]);
                        ok &= std_string_to_seval(inst, larg1, &args[1]);
                        se::Value rval;
                        se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                        se::Object* funcObj = jsFunc.toObject();
                        bool succeed = funcObj->call(args, thisObj, &rval);
                        if (!succeed) {
                            inst->clearException();
                        }
                        int result;
                        do { int32_t tmp = 0; ok &= seval_to_int32(inst, rval, &tmp); result = (int)tmp; } while(false);
                        SE_PRECONDITION2(ok, result, "lambda function : Error processing return value with type int");
                        return result;
                    };
                    arg2 = lambda;
                }
                else
                {
                    arg2 = nullptr;
                }
            } while(false)
            ;
            if (!ok) { ok = true; break; }
            cocos2d::extension::AssetsManagerEx* cobj = new (std::nothrow) cocos2d::extension::AssetsManagerEx(arg0, arg1, arg2);
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
            cocos2d::extension::AssetsManagerEx* cobj = new (std::nothrow) cocos2d::extension::AssetsManagerEx(arg0, arg1);
            s.thisObject(inst)->setPrivateData(cobj);
            return true;
        }
    } while(false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_CTOR(js_extension_AssetsManagerEx_constructor, __jsb_cocos2d_extension_AssetsManagerEx_class, js_cocos2d_extension_AssetsManagerEx_finalize)




static bool js_cocos2d_extension_AssetsManagerEx_finalize(se::State &s, se::ScriptEngine *inst)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::extension::AssetsManagerEx)", s.nativeThisObject());
    cocos2d::extension::AssetsManagerEx* cobj = (cocos2d::extension::AssetsManagerEx*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_extension_AssetsManagerEx_finalize)

bool js_register_extension_AssetsManagerEx(se::ScriptEngine *inst, se::Object* obj)
{
    auto cls = se::Class::create(inst, "AssetsManager", obj, nullptr, _SE(js_extension_AssetsManagerEx_constructor));

    cls->defineFunction(inst, "getDownloadedFiles", _SE(js_extension_AssetsManagerEx_getDownloadedFiles));
    cls->defineFunction(inst, "setEventCallback", _SE(js_extension_AssetsManagerEx_setEventCallback));
    cls->defineFunction(inst, "downloadFailedAssets", _SE(js_extension_AssetsManagerEx_downloadFailedAssets));
    cls->defineFunction(inst, "getTotalFiles", _SE(js_extension_AssetsManagerEx_getTotalFiles));
    cls->defineFunction(inst, "checkUpdate", _SE(js_extension_AssetsManagerEx_checkUpdate));
    cls->defineFunction(inst, "loadLocalManifest", _SE(js_extension_AssetsManagerEx_loadLocalManifest));
    cls->defineFunction(inst, "setMaxConcurrentTask", _SE(js_extension_AssetsManagerEx_setMaxConcurrentTask));
    cls->defineFunction(inst, "getLocalManifest", _SE(js_extension_AssetsManagerEx_getLocalManifest));
    cls->defineFunction(inst, "getRemoteManifest", _SE(js_extension_AssetsManagerEx_getRemoteManifest));
    cls->defineFunction(inst, "cancelUpdate", _SE(js_extension_AssetsManagerEx_cancelUpdate));
    cls->defineFunction(inst, "isResuming", _SE(js_extension_AssetsManagerEx_isResuming));
    cls->defineFunction(inst, "getState", _SE(js_extension_AssetsManagerEx_getState));
    cls->defineFunction(inst, "getMaxConcurrentTask", _SE(js_extension_AssetsManagerEx_getMaxConcurrentTask));
    cls->defineFunction(inst, "setVersionCompareHandle", _SE(js_extension_AssetsManagerEx_setVersionCompareHandle));
    cls->defineFunction(inst, "getTotalBytes", _SE(js_extension_AssetsManagerEx_getTotalBytes));
    cls->defineFunction(inst, "setVerifyCallback", _SE(js_extension_AssetsManagerEx_setVerifyCallback));
    cls->defineFunction(inst, "getStoragePath", _SE(js_extension_AssetsManagerEx_getStoragePath));
    cls->defineFunction(inst, "update", _SE(js_extension_AssetsManagerEx_update));
    cls->defineFunction(inst, "stopWhenUpdateProcess", _SE(js_extension_AssetsManagerEx_stopWhenUpdateProcess));
    cls->defineFunction(inst, "getDownloadedBytes", _SE(js_extension_AssetsManagerEx_getDownloadedBytes));
    cls->defineFunction(inst, "prepareUpdate", _SE(js_extension_AssetsManagerEx_prepareUpdate));
    cls->defineFunction(inst, "loadRemoteManifest", _SE(js_extension_AssetsManagerEx_loadRemoteManifest));
    cls->defineStaticFunction(inst, "create", _SE(js_extension_AssetsManagerEx_create));
    cls->defineFinalizeFunction(_SE(js_cocos2d_extension_AssetsManagerEx_finalize));
    cls->install(inst);
    inst->registerClass<cocos2d::extension::AssetsManagerEx>(cls);

    __jsb_cocos2d_extension_AssetsManagerEx_proto = cls->getProto();
    __jsb_cocos2d_extension_AssetsManagerEx_class = cls;

    inst->clearException();
    return true;
}

bool register_all_extension(se::ScriptEngine *inst, se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("jsb", &nsVal))
    {
        se::HandleObject jsobj(se::Object::createPlainObject(inst));
        nsVal.setObject(jsobj);
        obj->setProperty("jsb", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_extension_AssetsManagerEx(inst, ns);
    js_register_extension_EventAssetsManagerEx(inst, ns);
    js_register_extension_Manifest(inst, ns);
    return true;
}

