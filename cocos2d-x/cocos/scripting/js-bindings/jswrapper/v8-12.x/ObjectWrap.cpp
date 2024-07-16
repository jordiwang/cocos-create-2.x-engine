// Copyright Joyent, Inc. and other Node contributors.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.
#include "ObjectWrap.h"
#include "Object.hpp"

#if SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8

#include <sstream>
#include <tuple>

#if CC_DEBUG_GC_CRASH
extern std::unordered_map<void *, std::vector<std::tuple<void*,const char*, bool /* alive*/>>> gPtr2Class;

namespace {
    std::string getClassNames(void *ptr) {
        std::stringstream ss;
        auto itr = gPtr2Class.find(ptr);
        if(itr == gPtr2Class.end()) {
            return "";
        }
        ss << itr->second.size() << ": ";
        for(auto &t : itr->second) {
            ss << std::get<1>(t) << "@" << std::get<0>(t) << ","<< (std::get<2>(t) ? "alive" : "dead") << " ";
        }
        return ss.str();
    }
}
#endif

namespace se {

    ObjectWrap::ObjectWrap() {
        refs_ = 0;
        _nativeObj = nullptr;
        _finalizeCb = nullptr;

#if CC_DEBUG_GC_CRASH
        gPtr2Class[this].push_back(std::make_tuple(nullptr, "[init]", true));
#endif
    }

    bool ObjectWrap::init(v8::Isolate *isolate, v8::Local<v8::Object> handle, bool hasNativeClass) {
        assert(persistent().IsEmpty());
        _hasNativeClass = hasNativeClass;
        persistent().Reset(isolate, handle);
        makeWeak();
        return true;
    }

    void ObjectWrap::setFinalizeCallback(V8FinalizeFunc finalizeCb) {
        _finalizeCb = finalizeCb;
    }

    ObjectWrap::~ObjectWrap() {
        if (persistent().IsEmpty())
            return;
//        persistent().ClearWeak(); // pt
        persistent().Reset();
    }


/*static*/
    void *ObjectWrap::unwrap(v8::Local<v8::Object> handle) {
        assert(!handle.IsEmpty());
        assert(handle->InternalFieldCount() > 0);
        return handle->GetAlignedPointerFromInternalField(0);
    }

    v8::Local<v8::Object> ObjectWrap::handle(v8::Isolate *isolate) {
        return v8::Local<v8::Object>::New(isolate, persistent());
    }


    v8::Persistent<v8::Object> &ObjectWrap::persistent() {
        return handle_;
    }

#if CC_DEBUG_GC_CRASH
    void ObjectWrap::wrap(void *nativeObj, const char *className) {
#else
    void ObjectWrap::wrap(v8::Isolate *isolate, void *nativeObj) {
#endif
        assert(handle(isolate)->InternalFieldCount() > 0);
        _nativeObj = nativeObj;
        assert((reinterpret_cast<uintptr_t>(nativeObj) & 0x1) == 0);
        assert(_hasNativeClass);
        handle(isolate)->SetAlignedPointerInInternalField(0, nativeObj);
#if CC_DEBUG_GC_CRASH
        gPtr2Class[this].push_back(std::make_tuple(nativeObj, className, true));
#endif
    }

    void ObjectWrap::makeWeak() {
        if(_hasNativeClass && _nativeObj) {
            persistent().SetWeak(this, weakCallback, v8::WeakCallbackType::kParameter);
        } else {
            persistent().SetWeak();
        }
//        persistent().MarkIndependent();
    }


    void ObjectWrap::ref() {
        assert(!persistent().IsEmpty());
        persistent().ClearWeak();
        refs_++;
    }

    void ObjectWrap::unref() {
        assert(!persistent().IsEmpty());
        assert(!persistent().IsWeak());
        assert(refs_ > 0);
        if (--refs_ == 0)
            makeWeak();
    }

/*static*/
    void ObjectWrap::weakCallback(const v8::WeakCallbackInfo<ObjectWrap> &data) {
        auto *wrap = data.GetParameter();
//        SE_LOGD("weakCallback: %p, nativeObj = %p, finalize: %p\n", wrap, wrap->_nativeObj, wrap->_finalizeCb);
#if CC_DEBUG_GC_CRASH
        auto *obj = wrap->getObject();
        std::string name = getClassNames(wrap);
        SE_LOGD("wrap %p", wrap);
        SE_LOGD("   seobj %p, class : %s", obj, name.c_str());
#endif
        assert(wrap->refs_ == 0);
        wrap->handle_.Reset();
        if (wrap->_finalizeCb != nullptr)
        {
            wrap->_finalizeCb(wrap->_nativeObj); // wrap will be destroyed in wrap->_finalizeCb, should not use any wrap object after this line.
        }
        else
        {
            assert(false);
        }
    }

} // namespace se {

#endif // #if SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8
