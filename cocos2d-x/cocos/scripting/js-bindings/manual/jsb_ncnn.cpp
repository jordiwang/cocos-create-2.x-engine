#include "jsb_conversions.hpp"

#include "base/CCScheduler.h"
#include "jsb_global.h"
#include "ncnn/net.h"
#include "platform/CCApplication.h"

#include <cmath>
#include <cstdio>
#include <unordered_map>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <syscall.h>

static int modelId = 3000;

static std::unordered_map<int, ncnn::Net *> gNets;

bool jsb_ncnn_loadModel(se::State &state) {
    auto &args = state.args();
    if (args.size() < 2) {
        SE_REPORT_ERROR("2 arguments required");
        return false;
    }
    if (!args[0].isObject() || !args[0].toObject()->isArrayBuffer()) {
        SE_REPORT_ERROR("parameter 0 should be an ArrayBuffer");
        return false;
    }
    if (!args[1].isObject() || !args[1].toObject()->isArrayBuffer()) {
        SE_REPORT_ERROR("parameter 1 should be an ArrayBuffer");
        return false;
    }
    auto *v1 = args[0].toObject();
    auto *v2 = args[1].toObject();

    uint8_t *parameters{nullptr};
    size_t parametersSize;
    uint8_t *model{nullptr};
    size_t modelSize;
    v1->getArrayBufferData(&parameters, &parametersSize);
    v2->getArrayBufferData(&model, &modelSize);
    auto *net = new ncnn::Net();
#if __ANDROID_API__ >= 23
    FILE *fparam = fmemopen(parameters, parametersSize, "rb");
#else
    int param_fd = syscall(SYS_memfd_create, "parameter_file", 0);
    if(param_fd < 0) {
        SE_LOGE("failed to memfd_create: %s\n", strerror(errno));
        return false;
    }
    if(ftruncate(param_fd, parametersSize)) {
        SE_LOGE("failed to resize parameter file\n");
        close(param_fd);
        return false;
    }
    void *ptr = mmap(nullptr, parametersSize, PROT_READ|PROT_WRITE, MAP_SHARED, param_fd, 0);
    if(ptr == MAP_FAILED) {
        SE_LOGE("faild to call mmap for parameter file\n");
        close(param_fd);
        return false;
    }
    memcpy(ptr, parameters, parametersSize);
    FILE *fparam = fdopen(param_fd, "rb");
#endif
    if (net->load_param(fparam)) {
        SE_REPORT_ERROR("failed to load parameters");
        state.rval().setInt32(-1);
        fclose(fparam);
        return false;
    }

#if __ANDROID_API__ >= 23
    FILE *fmodel = fmemopen(model, modelSize, "rb");
#else

    int model_fd = syscall(SYS_memfd_create, "model_file", 0);
    if(model_fd < 0) {
        SE_LOGE("failed to memfd_create: %s\n", strerror(errno));
        return false;
    }
    if(ftruncate(model_fd, modelSize)) {
        SE_LOGE("failed to resize model file\n");
        close(param_fd);
        return false;
    }
    void *mptr = mmap(nullptr, modelSize, PROT_READ|PROT_WRITE, MAP_SHARED, model_fd, 0);
    if(mptr == MAP_FAILED) {
        SE_LOGE("faild to call mmap for model file\n");
        close(model_fd);
        return false;
    }
    memcpy(mptr, model, modelSize);
    FILE *fmodel = fdopen(model_fd, "rb");

#endif
    if (net->load_model(fmodel)) {
        SE_REPORT_ERROR("failed to load model");
        state.rval().setInt32(-1);
        fclose(fparam);
        return false;
    }

#if __ANDROID_API__ < 23
    munmap(ptr, parametersSize);
    munmap(mptr, modelSize);
#endif

    fclose(fparam);
    fclose(fmodel);
#if COCOS2D_DEBUG > 0
    const auto& layers = net->layers();
    for(const auto *l : layers) {
        SE_LOGD("layer -> %s\n", l->name.c_str());
    }
#endif

    gNets[++modelId] = net;
    state.rval().setInt32(modelId);

    return true;
}
SE_BIND_FUNC(jsb_ncnn_loadModel);

bool jsb_ncnn_executeModel(se::State &state) {
    auto &args = state.args();
    if (args.size() < 3) {
        SE_LOGE("3/4 parameters expected, but got %d", static_cast<int>(args.size()));
        return false;
    }
    se::Value id = args[0];
    se::Value inVal = args[1];
    se::Value outVal = args[2];
    se::Value callback;

    if (args.size() == 4) callback = args[3];

    if (!id.isNumber()) {
        SE_LOGE("arg 0 should be a number");
        return false;
    }
    if (!inVal.isObject() || !inVal.toObject()->isTypedArray()) {
        SE_LOGE("arg 1 should be a float32 array");
        return false;
    }
    if (!outVal.isObject() || !outVal.toObject()->isTypedArray()) {
        SE_LOGE("arg 2 should be a float32 array");
        return false;
    }

    if (!callback.isNullOrUndefined()) {
        if (!callback.isObject() || !callback.toObject()->isFunction()) {
            SE_LOGE("arg 3 should be a function");
            return false;
        }
    }

    se::Object *inArr = inVal.toObject();
    se::Object *outArr = outVal.toObject();
    if (inArr->getTypedArrayType() != se::Object::TypedArrayType::FLOAT32) {
        SE_LOGE("arg1 is not flaot32 array");
        return false;
    }
    if (outArr->getTypedArrayType() != se::Object::TypedArrayType::FLOAT32) {
        SE_LOGE("arg2 is not flaot32 array");
        return false;
    }

    uint8_t *inFloats;
    uint8_t *outFloats;
    size_t inSize;
    size_t outSize;

    if (!inArr->getTypedArrayData(&inFloats, &inSize)) {
        SE_LOGE("failed to read inFloats");
        return false;
    }
    if (!outArr->getTypedArrayData(&outFloats, &outSize)) {
        SE_LOGE("failed to read outFloats");
        return false;
    }

    bool execOk = false;
    auto modelId = id.toInt32();
    auto itr = gNets.find(modelId);
    if (itr == gNets.end()) {
        state.rval().setBoolean(false);
        return true;
    }

    auto *net = itr->second;

    //TODO: 参数名称需要协商
    static const char *inputBlobName = "in0";
    static const char *outputBlobName = "out0";
    
    if (callback.isNullOrUndefined()) {
        cocos2d::Perf perf("ncnn::extract");
        ncnn::Extractor ex = net->create_extractor();
        ncnn::Mat in(8, 8, 3);
        ncnn::Mat out(43);
        in.fill(0.0F);
        out.fill(0.0F);
        memcpy((float *)in, inFloats, inSize);
//        auto inputNames = net->input_names();
        if(ex.input("in0", in)) {
            SE_LOGE("failed to set input for model\n");
            return false;
        }
//        auto outputNames = net->output_names();
        if(ex.extract("out0", out)) {
            SE_LOGE("failed to extract for model\n");
            return false;
        }
        memcpy(outFloats, (float*)out, outSize);
        execOk = true;
    } else {
        auto modelId = id.toInt32();
        std::thread tsk([net, inFloats, inSize, outSize, outFloats, callback]() {
            ncnn::Extractor ex = net->create_extractor();
            ncnn::Mat in(inSize / sizeof(float), sizeof(float));
            ncnn::Mat out(outSize / sizeof(float), sizeof(float));
            memcpy((float *)in, inFloats, inSize);
            ex.input(inputBlobName, in);
            ex.extract(outputBlobName, out);
            memcpy(outFloats, (float *)out, outSize);
            cocos2d::Application::getInstance()->getScheduler()->performFunctionInCocosThread([callback]() {
                se::AutoHandleScope scope;
                se::Value jsRt;
                jsRt.setBoolean(true);
                callback.toObject()->call({jsRt}, nullptr);
            });
        });
        tsk.detach();
        execOk = true;
    }
    state.rval().setBoolean(execOk);
    return true;
}
SE_BIND_FUNC(jsb_ncnn_executeModel);

bool jsb_ncnn_unloadModel(se::State &state) {
    auto &args = state.args();
    if (args.size() < 1) {
        SE_REPORT_ERROR("model id required\n");
        return false;
    }
    auto id = args[0].toInt32();
    auto itr = gNets.find(id);
    if (itr != gNets.end()) {
        itr->second->clear();
        delete itr->second;
        gNets.erase(itr);
        return true;
    }

    return false;
}
SE_BIND_FUNC(jsb_ncnn_unloadModel);

bool jsb_register_ncnn(se::Object *nsObj) {
    nsObj->defineFunction("ncnnLoadModel", _SE(jsb_ncnn_loadModel));
    nsObj->defineFunction("ncnnUnloadModel", _SE(jsb_ncnn_unloadModel));
    nsObj->defineFunction("ncnnExecuteModel", _SE(jsb_ncnn_executeModel));
    return true;
}