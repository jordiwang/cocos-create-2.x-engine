#include "platform/CCCanvasRenderingContext2D.h"
#include "base/ccTypes.h"
#include "base/csscolorparser.hpp"

#include "base/ccUTF8.h"
#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"
#include "platform/android/jni/JniHelper.h"
#include "platform/android/jni/JniImp.h"
#include "platform/CCApplication.h"

#include <android/bitmap.h>

#include <cstdint>
#include <vector>
#include <regex>
#include <string_view>

#ifndef JCLS_CANVASIMPL
#define JCLS_CANVASIMPL  "org/cocos2dx/lib/CanvasRenderingContext2DImpl"
#endif

using namespace cocos2d;

enum class CanvasTextAlign {
    LEFT,
    CENTER,
    RIGHT
};

enum class CanvasTextBaseline {
    TOP,
    MIDDLE,
    BOTTOM
};

#define ENABLE_CANVAS_QUEUE 1

#if ENABLE_CANVAS_QUEUE
namespace {
    enum class CanvasCmd : uint8_t {
        ERROR_CMD = 0,
        BEGIN_PATH = 1,
        CLOSE_PATH,
        MOVE_TO,
        LINE_TO,
        STOKE,
        FILL,
        SAVE_CONTEXT,
        RESTORE_CONTEXT,
        RECT,
        CLEAR_RECT,
        FILL_RECT,
        FILL_TEXT,
        STORKE_TEXT,
        UPDATE_FONT,
        SET_LINE_CAP,
        SET_LINE_JOIN,
        SET_TEXT_ALIGN,
        SET_TEXT_BASE_LINE,
        SET_FILL_STYLE,
        SET_STROKE_STYLE,
        SET_LINE_WIDTH,
        RECREATE_BUFFER,
    };

    class CommandBuffer final {
    public:
        explicit CommandBuffer(int dftSize) {
            data.resize(dftSize);
        }

        void drop() {
            current = 0;
        }

        bool empty() const { return current == 0; }

        int byteLength() const { return current; }

        void *getData() { return data.data(); }

    private:
        void encodeCmd(CanvasCmd cmd) {
            requestFor(1);
            data[current] = static_cast<uint8_t>(cmd);
            current += 1;
        }

        void encodeItem(float value) {
            requestFor(4);
            memcpy(data.data() + current, &value, sizeof(float));
            current += sizeof(float);
        }

        void encodeItem(int value) {
            requestFor(4);
            memcpy(data.data() + current, &value, sizeof(int));
            current += sizeof(int);
        }

        void encodeItem(bool value) {
            requestFor(1);
            data[current] = value ? 1 : 0;
            current += 1;
        }

        void encodeItem(std::string_view text) {
            uint32_t len = text.length();
            requestFor(sizeof(len) + text.length());
            memcpy(data.data() + current, &len, sizeof(len));
            memcpy(data.data() + current + sizeof(len), text.data(), text.length());
            current += (sizeof(len) + text.length());
        }

        template<typename T, typename ... ARGS>
        void encodeArgs(T t, ARGS &&... args) {
            encodeItem(t);
            if constexpr (sizeof...(args) != 0) encodeArgs(std::forward<ARGS>(args)...);
        }

    public:
        template<typename ... ARGS>
        void encode(CanvasCmd cmd, ARGS &&... args) {
            encodeCmd(cmd);
            if constexpr (sizeof...(args) != 0) encodeArgs(std::forward<ARGS>(args)...);
        }

    private:
        void requestFor(uint32_t bytes) {
            if (data.size() - current < bytes) {
                data.resize(data.size() + std::max(128, (int)bytes * 2));
            }
        }

        size_t current{0};
        std::vector<uint8_t> data;
    };


}
#endif

class CanvasRenderingContext2DImpl {
public:
    CanvasRenderingContext2DImpl() {
        jobject obj = JniHelper::newObject(JCLS_CANVASIMPL);
        _env = JniHelper::getEnv();
        _obj = _env->NewGlobalRef(obj);
        JniHelper::getEnv()->DeleteLocalRef(obj);
        {
            se::AutoHandleScope scope(Application::getInstance()->getScriptEngine());
            _data.setNull();
        }

#if ENABLE_CANVAS_QUEUE
        if (!_getBitmap) {
            JniMethodInfo method;
            JniHelper::getMethodInfo(method, JCLS_CANVASIMPL, "getBitmap", "()Ljava/lang/Object;");
            _getBitmap = method.methodID;
            _env->DeleteLocalRef(method.classID);
        }
        if (!_recreateBuffer) {
            JniMethodInfo method;
            JniHelper::getMethodInfo(method, JCLS_CANVASIMPL, "recreateBuffer", "(FF)V");
            _recreateBuffer = method.methodID;
            _env->DeleteLocalRef(method.classID);
        }
        if (!_flushCommandBuffer) {
            JniMethodInfo method;
            JniHelper::getMethodInfo(method, JCLS_CANVASIMPL, "flushCommandBuffer", "([B)V");
            _flushCommandBuffer = method.methodID;
            _env->DeleteLocalRef(method.classID);
        }
        if (!_measureText) {
            JniMethodInfo method;
            JniHelper::getMethodInfo(method, JCLS_CANVASIMPL, "measureText",
                                     "(Ljava/lang/String;)F");
            _measureText = method.methodID;
            _env->DeleteLocalRef(method.classID);
        }
#endif
    }

    ~CanvasRenderingContext2DImpl() {
        _env->DeleteGlobalRef(_obj);
    }

    void recreateBuffer(float w, float h) {
        _bufferWidth = w;
        _bufferHeight = h;
        if (_bufferWidth < 1.0f || _bufferHeight < 1.0f)
            return;

#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::RECREATE_BUFFER, w, h);
        flushCommandBuffer();
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "recreateBuffer", w, h);
#endif
        markDirty();

    }

    void beginPath() {
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::BEGIN_PATH);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "beginPath");
#endif

    }

    void closePath() {
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::CLOSE_PATH);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "closePath");
#endif
    }

    void moveTo(float x, float y) {
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::MOVE_TO, x, y);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "moveTo", x, y);
#endif
    }

    void lineTo(float x, float y) {
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::LINE_TO, x, y);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "lineTo", x, y);
#endif
    }

    void stroke() {
        if (_bufferWidth < 1.0f || _bufferHeight < 1.0f)
            return;

#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::STOKE);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "stroke");
#endif
        markDirty();
    }

    void fill() {
        if (_bufferWidth < 1.0f || _bufferHeight < 1.0f)
            return;

#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::FILL);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "fill");
#endif
        markDirty();
    }

    void saveContext() {
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::SAVE_CONTEXT);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "saveContext");
#endif
    }

    void restoreContext() {
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::RESTORE_CONTEXT);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "restoreContext");
#endif
    }

    void rect(float x, float y, float w, float h) {
        if (_bufferWidth < 1.0f || _bufferHeight < 1.0f)
            return;
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::RECT, x, y, w, h);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "rect", x, y, w, h);
#endif
        markDirty();
    }

    void clearRect(float x, float y, float w, float h) {
        if (_bufferWidth < 1.0f || _bufferHeight < 1.0f)
            return;
        if (x >= _bufferWidth || y >= _bufferHeight)
            return;
        if (x + w > _bufferWidth)
            w = _bufferWidth - x;
        if (y + h > _bufferHeight)
            h = _bufferHeight - y;
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::CLEAR_RECT, x, y, w, h);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "clearRect", x, y, w, h);
#endif
        markDirty();
    }

    void fillRect(float x, float y, float w, float h) {
        if (_bufferWidth < 1.0f || _bufferHeight < 1.0f)
            return;
        if (x >= _bufferWidth || y >= _bufferHeight)
            return;
        if (x + w > _bufferWidth)
            w = _bufferWidth - x;
        if (y + h > _bufferHeight)
            h = _bufferHeight - y;
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::FILL_RECT, x, y, w, h);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "fillRect", x, y, w, h);
#endif
        markDirty();
    }

    void fillText(const std::string &text, float x, float y, float maxWidth) {
        if (text.empty() || _bufferWidth < 1.0f || _bufferHeight < 1.0f)
            return;
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::FILL_TEXT, text, x, y, maxWidth);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "fillText", text, x, y, maxWidth);
#endif
        markDirty();
    }

    void strokeText(const std::string &text, float x, float y, float maxWidth) {
        if (text.empty() || _bufferWidth < 1.0f || _bufferHeight < 1.0f)
            return;
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::STORKE_TEXT, text, x, y, maxWidth);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "strokeText", text, x, y, maxWidth);
#endif
        markDirty();
    }

    float measureText(const std::string &text) {
        if (text.empty())
            return 0.0f;
        flushCommandBuffer();
#if ENABLE_CANVAS_QUEUE
        jstring textJ = cocos2d::StringUtils::newStringUTFJNI(_env, text);
        jfloat ret = _env->CallFloatMethod(_obj, _measureText, textJ);
        _env->DeleteLocalRef(textJ);
        checkException();
        return ret;
#else
        return JniHelper::callObjectFloatMethod(_obj, JCLS_CANVASIMPL, "measureText", text);
#endif
    }

    void
    updateFont(const std::string &fontName, float fontSize, bool bold, bool italic, bool oblique,
               bool smallCaps) {
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::UPDATE_FONT, fontName, fontSize, bold, italic, oblique,
                          smallCaps);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "updateFont", fontName, fontSize, bold, italic, oblique, smallCaps);
#endif
    }

    void setLineCap(const std::string &lineCap) {
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::SET_LINE_CAP, lineCap);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "setLineCap", lineCap);
#endif
    }

    void setLineJoin(const std::string &lineJoin) {
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::SET_LINE_JOIN, lineJoin);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "setLineJoin", lineJoin);
#endif
    }

    void setTextAlign(CanvasTextAlign align) {
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::SET_TEXT_ALIGN, (int) align);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "setTextAlign", (int)align);
#endif
    }

    void setTextBaseline(CanvasTextBaseline baseline) {
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::SET_TEXT_BASE_LINE, (int) baseline);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "setTextBaseline", (int)baseline);
#endif
    }

    void setFillStyle(float r, float g, float b, float a) {
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::SET_FILL_STYLE, r, g, b, a);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "setFillStyle", r, g, b, a);
#endif
    }

    void setStrokeStyle(float r, float g, float b, float a) {
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::SET_STROKE_STYLE, r, g, b, a);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "setStrokeStyle", r, g, b, a);
#endif
    }

    void setLineWidth(float lineWidth) {
#if ENABLE_CANVAS_QUEUE
        _cmdBuffer.encode(CanvasCmd::SET_LINE_WIDTH, lineWidth);
#else
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "setLineWidth", lineWidth);
#endif
    }

    void _fillImageData(const Data &imageData, float imageWidth, float imageHeight, float offsetX,
                        float offsetY) {
        if (_bufferWidth < 1.0f || _bufferHeight < 1.0f)
            return;

        flushCommandBuffer();
        jbyteArray arr = _env->NewByteArray(imageData.getSize());
        _env->SetByteArrayRegion(arr, 0, imageData.getSize(),
                                 (const jbyte *) imageData.getBytes());
        JniHelper::callObjectVoidMethod(_obj, JCLS_CANVASIMPL, "_fillImageData", arr, imageWidth,
                                        imageHeight, offsetX, offsetY);
        _env->DeleteLocalRef(arr);

        markDirty();
    }

    [[nodiscard]] const se::Value &getDataRef() {
        if (_dataDirty) fillData();
        return _data;
    }

    void setPremultiply(bool multiply) {
        _premultiply = multiply;
    }

#define CLAMP(V, HI) std::min( (V), (HI) )

    void unMultiplyAlpha(unsigned char *ptr, ssize_t size) {
        // Android source data is not premultiplied alpha when API >= 19
        // please refer CanvasRenderingContext2DImpl::recreateBuffer(float w, float h)
        // in CanvasRenderingContext2DImpl.java
        // pt: should be enable for most devices!
        // if (getAndroidSDKInt() >= 19)
        // return;
        static std::unique_ptr<uint8_t, std::function<void(void*)>> transform(reinterpret_cast<uint8_t*>(malloc(256 * 256)), [](void *d){free(d);});
        static bool initialized = false;
        uint8_t * trMap = transform.get();
        if (!initialized) {
            for(int a = 1;a < 256;a ++) {
                for(int c = 0;c < 256; c++) {
                    trMap[(a << 8) + c] = CLAMP((int) ((float) c / a * 255), 255);
                }
            }
            initialized = true;
        }

        uint32_t alpha;
        uint8_t *row;
        for (auto *end = ptr + size; ptr < end; ptr += 4) {
            alpha = ptr[3];
            if (alpha > 0) {
                row = trMap + (alpha << 8);
                ptr[0] = row[ptr[0]];
                ptr[1] = row[ptr[1]];
                ptr[2] = row[ptr[2]];
            }
        }
    }

    void fillData() {
        flushCommandBuffer();
#if ENABLE_CANVAS_QUEUE
        jobject bmpObj = _env->CallObjectMethod(_obj, _getBitmap);
        checkException();
#else
        jobject bmpObj = JniHelper::callObjectObjectMethod(_obj, JCLS_CANVASIMPL, "getBitmap");
#endif
        do {
            se::AutoHandleScope scope(Application::getInstance()->getScriptEngine());
            _data.setNull();
            if (nullptr == bmpObj) {
                break;
            }
            AndroidBitmapInfo bmpInfo;
            if (AndroidBitmap_getInfo(_env, bmpObj, &bmpInfo) != ANDROID_BITMAP_RESULT_SUCCESS) {
                CCLOGERROR("AndroidBitmap_getInfo() failed ! error");
                break;
            }
            if (bmpInfo.width < 1 || bmpInfo.height < 1) {
                break;
            }

            void *pixelData;
            if (AndroidBitmap_lockPixels(_env, bmpObj, &pixelData) !=
                ANDROID_BITMAP_RESULT_SUCCESS) {
                CCLOGERROR("AndroidBitmap_lockPixels() failed ! error");
                break;
            }

            uint32_t size = bmpInfo.stride * bmpInfo.height;
            auto *bmpData = static_cast<jbyte *>(malloc(size));
            memcpy(bmpData, pixelData, size);
            if (!_premultiply) {
                unMultiplyAlpha(reinterpret_cast<unsigned char *>(bmpData), size);
            }
            auto *inst = cocos2d::Application::getInstance()->getScriptEngine();
            se::HandleObject arrayBufer(se::Object::createExternalUint8ArrayObject(inst, bmpData, size,
                                                                                   +[](void *data,
                                                                                       size_t,
                                                                                       void *) {
                                                                                       free(data);
                                                                                   }));
            _data.setObject(arrayBufer, true);

            AndroidBitmap_unlockPixels(_env, bmpObj);
        } while (false);
        if (bmpObj) {
            _env->DeleteLocalRef(bmpObj);
        }
    }

private:

#if ENABLE_CANVAS_QUEUE

    void flushCommandBuffer() {
        if (_cmdBuffer.empty()) return;
        jbyteArray commands = _env->NewByteArray(_cmdBuffer.byteLength());
        _env->SetByteArrayRegion(commands, 0, _cmdBuffer.byteLength(),
                                 reinterpret_cast<jbyte *>(_cmdBuffer.getData()));
        _env->CallVoidMethod(_obj, _flushCommandBuffer, commands);
        _env->DeleteLocalRef(commands);
        checkException();
        _cmdBuffer.drop();
    }

    void checkException() {
        if (_env->ExceptionCheck()) {
            _env->ExceptionDescribe();
            _env->ExceptionClear();
        }
    }

#endif

    void markDirty() { _dataDirty = true; }

    JNIEnv *_env = nullptr;
    jobject _obj = nullptr;
    se::Value _data;
    float _bufferWidth = 0.0f;
    float _bufferHeight = 0.0f;
#if ENABLE_CANVAS_QUEUE
    CommandBuffer _cmdBuffer{128};
    static jmethodID _getBitmap;
    static jmethodID _recreateBuffer;
    static jmethodID _flushCommandBuffer;
    static jmethodID _measureText;
#endif
    bool _premultiply = true;
    bool _dataDirty = false;
};

#if ENABLE_CANVAS_QUEUE
jmethodID CanvasRenderingContext2DImpl::_getBitmap = nullptr;
jmethodID CanvasRenderingContext2DImpl::_recreateBuffer = nullptr;
jmethodID CanvasRenderingContext2DImpl::_flushCommandBuffer = nullptr;
jmethodID CanvasRenderingContext2DImpl::_measureText = nullptr;
#endif

namespace {
    void fillRectWithColor(uint8_t *buf, uint32_t totalWidth, uint32_t totalHeight, uint32_t x,
                           uint32_t y, uint32_t width, uint32_t height, uint8_t r, uint8_t g,
                           uint8_t b) {
        assert(x + width <= totalWidth);
        assert(y + height <= totalHeight);

        uint32_t y0 = totalHeight - (y + height);
        uint32_t y1 = totalHeight - y;
        uint8_t *p;
        for (uint32_t offsetY = y0; offsetY < y1; ++offsetY) {
            for (uint32_t offsetX = x; offsetX < (x + width); ++offsetX) {
                p = buf + (totalWidth * offsetY + offsetX) * 3;
                *p++ = r;
                *p++ = g;
                *p++ = b;
            }
        }
    }
}

NS_CC_BEGIN

    CanvasGradient::CanvasGradient() {
        // SE_LOGD("CanvasGradient constructor: %p\n", this);
    }

    CanvasGradient::~CanvasGradient() {
        // SE_LOGD("CanvasGradient destructor: %p\n", this);
    }

    void CanvasGradient::addColorStop(float offset, const std::string &color) {
        // SE_LOGD("CanvasGradient::addColorStop: %p\n", this);
    }

// CanvasRenderingContext2D

    CanvasRenderingContext2D::CanvasRenderingContext2D(float width, float height)
            : __width(width), __height(height) {
        // SE_LOGD("CanvasRenderingContext2D constructor: %p, width: %f, height: %f\n", this, width, height);
        _impl = new CanvasRenderingContext2DImpl();
        recreateBufferIfNeeded();
    }

    CanvasRenderingContext2D::~CanvasRenderingContext2D() {
        // SE_LOGD("CanvasRenderingContext2D destructor: %p\n", this);
        delete _impl;
    }

    void CanvasRenderingContext2D::recreateBufferIfNeeded() {
        if (_isBufferSizeDirty) {
            _isBufferSizeDirty = false;
            _impl->recreateBuffer(__width, __height);
        }
        if (_canvasBufferUpdatedCB != nullptr)
            _canvasBufferUpdatedCB(_impl->getDataRef());
    }

    void CanvasRenderingContext2D::rect(float x, float y, float width, float height) {
//    SE_LOGD("CanvasRenderingContext2D::rect: %p, %f, %f, %f, %f\n", this, x, y, width, height);
        recreateBufferIfNeeded();
        _impl->rect(x, y, width, height);
    }

    void CanvasRenderingContext2D::clearRect(float x, float y, float width, float height) {
//    SE_LOGD("CanvasRenderingContext2D::clearRect: %p, %f, %f, %f, %f\n", this, x, y, width, height);
        recreateBufferIfNeeded();
        _impl->clearRect(x, y, width, height);
    }

    void CanvasRenderingContext2D::fillRect(float x, float y, float width, float height) {
        recreateBufferIfNeeded();
        _impl->fillRect(x, y, width, height);

        if (_canvasBufferUpdatedCB != nullptr)
            _canvasBufferUpdatedCB(_impl->getDataRef());
    }

    void
    CanvasRenderingContext2D::fillText(const std::string &text, float x, float y, float maxWidth) {
//    SE_LOGD("CanvasRenderingContext2D::fillText: %s, %f, %f, %f\n", text.c_str(), x, y, maxWidth);
        if (text.empty())
            return;
        recreateBufferIfNeeded();

        _impl->fillText(text, x, y, maxWidth);
        if (_canvasBufferUpdatedCB != nullptr)
            _canvasBufferUpdatedCB(_impl->getDataRef());
    }

    void CanvasRenderingContext2D::strokeText(const std::string &text, float x, float y,
                                              float maxWidth) {
//    SE_LOGD("CanvasRenderingContext2D::strokeText: %s, %f, %f, %f\n", text.c_str(), x, y, maxWidth);
        if (text.empty())
            return;
        recreateBufferIfNeeded();

        _impl->strokeText(text, x, y, maxWidth);

        if (_canvasBufferUpdatedCB != nullptr)
            _canvasBufferUpdatedCB(_impl->getDataRef());
    }

    cocos2d::Size CanvasRenderingContext2D::measureText(const std::string &text) {
//    SE_LOGD("CanvasRenderingContext2D::measureText: %s\n", text.c_str());
        return cocos2d::Size(_impl->measureText(text), 0);
    }

    CanvasGradient *
    CanvasRenderingContext2D::createLinearGradient(float x0, float y0, float x1, float y1) {
        return nullptr;
    }

    void CanvasRenderingContext2D::save() {
        _impl->saveContext();
    }

    void CanvasRenderingContext2D::beginPath() {
        _impl->beginPath();
    }

    void CanvasRenderingContext2D::closePath() {
        _impl->closePath();
    }

    void CanvasRenderingContext2D::moveTo(float x, float y) {
        _impl->moveTo(x, y);
    }

    void CanvasRenderingContext2D::lineTo(float x, float y) {
        _impl->lineTo(x, y);
    }

    void CanvasRenderingContext2D::stroke() {
        _impl->stroke();

        if (_canvasBufferUpdatedCB != nullptr)
            _canvasBufferUpdatedCB(_impl->getDataRef());
    }

    void CanvasRenderingContext2D::fill() {
        _impl->fill();

        if (_canvasBufferUpdatedCB != nullptr)
            _canvasBufferUpdatedCB(_impl->getDataRef());
    }

    void CanvasRenderingContext2D::restore() {
        _impl->restoreContext();
    }

    void CanvasRenderingContext2D::setCanvasBufferUpdatedCallback(
            const CanvasBufferUpdatedCallback &cb) {
        _canvasBufferUpdatedCB = cb;
    }

    void CanvasRenderingContext2D::setPremultiply(bool multiply) {
        _impl->setPremultiply(multiply);
    }

    void CanvasRenderingContext2D::set__width(float width) {
//    SE_LOGD("CanvasRenderingContext2D::set__width: %f\n", width);
        __width = width;
        _isBufferSizeDirty = true;
        recreateBufferIfNeeded();
    }

    void CanvasRenderingContext2D::set__height(float height) {
//    SE_LOGD("CanvasRenderingContext2D::set__height: %f\n", height);
        __height = height;
        _isBufferSizeDirty = true;
        recreateBufferIfNeeded();
    }

    void CanvasRenderingContext2D::set_lineWidth(float lineWidth) {
        _lineWidth = lineWidth;
        _impl->setLineWidth(lineWidth);
    }

    void CanvasRenderingContext2D::set_lineJoin(const std::string &lineJoin) {
        if (lineJoin.empty()) return;
        _impl->setLineJoin(lineJoin);
    }

    void CanvasRenderingContext2D::set_lineCap(const std::string &lineCap) {
        if (lineCap.empty()) return;
        _impl->setLineCap(lineCap);
    }

/*
 * support format e.g.: "oblique bold small-caps 18px Arial"
 *                      "italic bold small-caps 25px Arial"
 *                      "italic 25px Arial"
 * */
    void CanvasRenderingContext2D::set_font(const std::string &font) {
        if (_font != font) {
            _font = font;
            std::string fontName = "sans-serif";
            std::string fontSizeStr = "30";
            std::regex re("\\s*((\\d+)([\\.]\\d+)?)px\\s+([^\\r\\n]*)");
            std::match_results<std::string::const_iterator> results;
            if (std::regex_search(_font.cbegin(), _font.cend(), results, re)) {
                fontSizeStr = results[2].str();
                // support get font name from `60px American` or `60px "American abc-abc_abc"`
                // support get font name contain space,example `times new roman`
                // if regex rule that does not conform to the rules,such as Chinese,it defaults to sans-serif
                std::match_results<std::string::const_iterator> fontResults;
                std::regex fontRe("([\\w\\s-]+|\"[\\w\\s-]+\"$)");
                std::string tmp = results[4].str();
                if (std::regex_match(tmp, fontResults, fontRe)) {
                    fontName = results[4].str();
                }
            }

            float fontSize = atof(fontSizeStr.c_str());
            bool isBold = font.find("bold", 0) != std::string::npos;
            bool isItalic = font.find("italic", 0) != std::string::npos;
            bool isSmallCaps = font.find("small-caps", 0) != std::string::npos;
            bool isOblique = font.find("oblique", 0) != std::string::npos;
            //font-style: italic, oblique, normal
            //font-weight: normal, bold
            //font-variant: normal, small-caps
            _impl->updateFont(fontName, fontSize, isBold, isItalic, isOblique, isSmallCaps);

        }
    }

    void CanvasRenderingContext2D::set_textAlign(const std::string &textAlign) {
        // SE_LOGD("CanvasRenderingContext2D::set_textAlign: %s\n", textAlign.c_str());
        if (textAlign == "left") {
            _impl->setTextAlign(CanvasTextAlign::LEFT);
        } else if (textAlign == "center" || textAlign == "middle") {
            _impl->setTextAlign(CanvasTextAlign::CENTER);
        } else if (textAlign == "right") {
            _impl->setTextAlign(CanvasTextAlign::RIGHT);
        } else {
            assert(false);
        }
    }

    void CanvasRenderingContext2D::set_textBaseline(const std::string &textBaseline) {
        // SE_LOGD("CanvasRenderingContext2D::set_textBaseline: %s\n", textBaseline.c_str());
        if (textBaseline == "top") {
            _impl->setTextBaseline(CanvasTextBaseline::TOP);
        } else if (textBaseline == "middle") {
            _impl->setTextBaseline(CanvasTextBaseline::MIDDLE);
        } else if (textBaseline == "bottom" || textBaseline ==
                                               "alphabetic") //REFINE:, how to deal with alphabetic, currently we handle it as bottom mode.
        {
            _impl->setTextBaseline(CanvasTextBaseline::BOTTOM);
        } else {
            assert(false);
        }
    }

    void CanvasRenderingContext2D::set_fillStyle(const std::string &fillStyle) {
        CSSColorParser::Color color = CSSColorParser::parse(fillStyle);
        _impl->setFillStyle(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a);
        // SE_LOGD("CanvasRenderingContext2D::set_fillStyle: %s, (%d, %d, %d, %f)\n", fillStyle.c_str(), color.r, color.g, color.b, color.a);
    }

    void CanvasRenderingContext2D::set_strokeStyle(const std::string &strokeStyle) {
        CSSColorParser::Color color = CSSColorParser::parse(strokeStyle);
        _impl->setStrokeStyle(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a);
    }

    void CanvasRenderingContext2D::set_globalCompositeOperation(
            const std::string &globalCompositeOperation) {
        // SE_LOGE("%s isn't implemented!\n", __FUNCTION__);
    }

    void CanvasRenderingContext2D::_fillImageData(const Data &imageData, float imageWidth,
                                                  float imageHeight, float offsetX, float offsetY) {
        _impl->_fillImageData(imageData, imageWidth, imageHeight, offsetX, offsetY);
        if (_canvasBufferUpdatedCB != nullptr)
            _canvasBufferUpdatedCB(_impl->getDataRef());
    }
// transform
//REFINE:

    void CanvasRenderingContext2D::translate(float x, float y) {
        // SE_LOGE("%s isn't implemented!\n", __FUNCTION__);
    }

    void CanvasRenderingContext2D::scale(float x, float y) {
        // SE_LOGE("%s isn't implemented!\n", __FUNCTION__);
    }

    void CanvasRenderingContext2D::rotate(float angle) {
        // SE_LOGE("%s isn't implemented!\n", __FUNCTION__);
    }

    void CanvasRenderingContext2D::transform(float a, float b, float c, float d, float e, float f) {
        // SE_LOGE("%s isn't implemented!\n", __FUNCTION__);
    }

    void
    CanvasRenderingContext2D::setTransform(float a, float b, float c, float d, float e, float f) {
        // SE_LOGE("%s isn't implemented!\n", __FUNCTION__);
    }

NS_CC_END