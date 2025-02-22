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

#ifndef SRC_NODE_OBJECT_WRAP_H_
#define SRC_NODE_OBJECT_WRAP_H_

#include "../config.hpp"

#if SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8

#include "Base.h"

#define CC_DEBUG_GC_CRASH 0

namespace se {

    class Object;

    class ObjectWrap {
    public:
        ObjectWrap();
        ~ObjectWrap();

        bool init(v8::Isolate *isolate, v8::Local<v8::Object> handle, bool hasNativeClass);
        void setFinalizeCallback(V8FinalizeFunc finalizeCb);

        v8::Local<v8::Object> handle() = delete;
        v8::Local<v8::Object> handle(v8::Isolate *isolate);
        v8::Persistent<v8::Object> &persistent();


#if CC_DEBUG_GC_CRASH
        void wrap(void *nativeObj, const char *className);
#else
        void wrap(v8::Isolate *isolate, void *nativeObj);
#endif
        static void* unwrap(v8::Local<v8::Object> handle);

        /* Ref() marks the object as being attached to an event loop.
         * Refed objects will not be garbage collected, even if
         * all references are lost.
         */
        void ref();

        /* Unref() marks an object as detached from the event loop.  This is its
         * default state.  When an object with a "weak" reference changes from
         * attached to detached state it will be freed. Be careful not to access
         * the object after making this call as it might be gone!
         * (A "weak reference" means an object that only has a
         * persistent handle.)
         *
         * DO NOT CALL THIS FROM DESTRUCTOR
         */
        void unref();

        Object* getObject() const;

    private:
        static void weakCallback(const v8::WeakCallbackInfo<ObjectWrap> &data);
        void makeWeak();

        v8::Persistent<v8::Object> handle_;
        void *_nativeObj;
        V8FinalizeFunc _finalizeCb;
        int refs_;  // ro
        bool _hasNativeClass{false};


        friend class Object;
    };

}  // namespace se

#endif // #if SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8

#endif  // SRC_NODE_OBJECT_WRAP_H_
