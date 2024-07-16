/****************************************************************************
 Copyright (c) 2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#pragma once

#include "Value.hpp"
#include "Object.hpp"
#include "v8-12.x/Value.hpp"

namespace se {

    class Object;
    class ScriptEngine;

    /**
     *  State represents an environment while a function or an accesstor is invoked from JavaScript.
     */
    class State final
    {
    public:
        /**
         *  @brief Gets void* pointer of `this` object's private data.
         *  @return A void* pointer of `this` object's private data.
         */
        void* nativeThisObject() const {return _nativeThisObject;}

        /**
         *  @brief Gets the arguments of native binding functions or accesstors.
         *  @return The arguments of native binding functions or accesstors.
         */
        const ValueArray& args() const { return _args ? *_args : EmptyValueArray;}

        /**
         *  @brief Gets the JavaScript `this` object wrapped in se::Object.
         *  @return The JavaScript `this` object wrapped in se::Object.
         */
        Object* thisObject(ScriptEngine *inst) {
            if(!_thisObject && _nativeThisObject) {
                _thisObject = se::Object::getObjectWithPtr(inst, _nativeThisObject);
            }
            return _thisObject;
        }

        /**
         *  @brief Gets the return value reference. Used for setting return value for a function.
         *  @return The return value reference.
         */
        Value& rval() {return _retVal;}

        // Private API used in wrapper
        /**
         *  @brief
         *  @param[in]
         *  @return
         */
        State() = default;

        /**
         *  @brief
         *  @param[in]
         *  @return
         */
        ~State() {
            SAFE_DEC_REF(_thisObject);
        }

        /**
         *  @brief
         *  @param[in]
         *  @return
         */
        State(void* nativeThisObject): _nativeThisObject(nativeThisObject) {}

        /**
         *  @brief
         *  @param[in]
         *  @return
         */
        State(void* nativeThisObject, const ValueArray& args): _nativeThisObject(nativeThisObject), _args(&args) {}

        /**
         *  @brief
         *  @param[in]
         *  @return
         */
        State(Object* thisObject, const ValueArray& args): _thisObject(thisObject), _args(&args) {
            SAFE_INC_REF(thisObject);
        }

    private:

        // Disable copy/move constructor, copy/move assigment
        State(const State&) = delete;
        State(State&&) = delete;
        State& operator=(const State&);
        State& operator=(State&&);

        void* _nativeThisObject = nullptr;  //weak ref
        Object* _thisObject = nullptr; //weak ref
        const ValueArray* _args = nullptr; //weak ref
        Value _retVal; //weak ref
    };
}
