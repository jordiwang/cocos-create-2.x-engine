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

#include <cstdint>
#include <vector>
#include <string>
#include <cassert>

#include "../HandleObject.hpp"

namespace se {

    class Object;
    class ScriptEngine;
    /**
     *  se::Value represents a JavaScript Value.
     *  It could be undefined, null, number, boolean, string and object which exists in JavaScript.
     */
    class Value final
    {
    public:
        enum class Type : char
        {
            Undefined = 0,
            Null,
            Number,
            Boolean,
            String,
            Object
        };

        static Value Null;
        static Value Undefined;

        /**
         *  @brief The default constructor.
         */
        Value() {
            memset(&_u, 0, sizeof(_u));
        }

        /**
         *  @brief The copy constructor.
         */
        Value(const Value& v) {
            *this = v;
        }

        /**
         *  @brief The move constructor.
         */
        Value(Value&& v) noexcept {
            *this = std::move(v);
        }

        /**
         *  @brief The constructor with a boolean arguement.
         */
         // FIXME: cause string convertion error
        explicit Value(bool v) {
            setBoolean(v);
        }

        /**
         *  @brief The constructor with a int8_t arguement.
         */
        explicit Value(int8_t v) {
            setInt8(v);
        }

        /**
         *  @brief The constructor with a uint8_t arguement.
         */
        explicit Value(uint8_t v) {
            setUint8(v);
        }

        /**
         *  @brief The constructor with a int16_t arguement.
         */
        explicit Value(int16_t v) {
            setInt16(v);
        }

        /**
         *  @brief The constructor with a uint16_t arguement.
         */
        explicit Value(uint16_t v){
            setUint16(v);
        }

        /**
         *  @brief The constructor with a int32_t arguement.
         */
        explicit Value(int32_t v) {
            setInt32(v);
        }

        /**
         *  @brief The constructor with a uint32_t arguement.
         */
        explicit Value(uint32_t v) {
            setUint32(v);
        }

        /**
         *  @brief The constructor with a long arguement.
         */
        explicit Value(long v) {
            setLong(v);
        }

        /**
         *  @brief The constructor with a unsigned long arguement.
         */
        explicit Value(unsigned long v) {
            setUlong(v);
        }

        /**
         *  @brief The constructor with a float arguement.
         */
        explicit Value(float v) {
            setFloat(v);
        }

        /**
         *  @brief The constructor with a double arguement.
         */
        explicit Value(double v) {
            setNumber(v);
        }

        /**
         *  @brief The constructor with an UTF8 null-terminated string argument.
         */
        explicit Value(const char *str) {
            setString(str);
        }

        explicit Value(const std::string &str) {
            setString(str);
        }

        /**
         *  @brief The constructor with an Object.
         *  @param o A se::Object to be set.
         *  @param[in] autoRootUnroot Whether to root se::Object and unroot it in se::Value's destructor or unroot it while object is replaced. Default value is false.
         */
        explicit Value(Object* o, bool autoRootUnroot = false) {
            setObject(o, autoRootUnroot);
        }

        /**
         *  @brief The constructor with a HandleObject.
         *  @param o A se::HandleObject to be set.
         *  @param[in] autoRootUnroot Whether to root se::HandleObject and unroot it in se::Value's destructor or unroot it while object is replaced. Default value is false.
         */
        explicit Value(const HandleObject& o, bool autoRootUnroot = false) {
            setObject(o, autoRootUnroot);
        }

        /**
         *  @brief The destructor of se::Value
         */
        ~Value() {
            reset(Type::Undefined);
        }

        /**
         *  @brief The copy assignment operator.
         */
        Value& operator=(const Value& v);

        /**
         *  @brief The move assignment operator.
         */
        Value& operator=(Value&& v) noexcept;

        /**
         *  @brief Sets se::Value to undefined.
         */
        void setUndefined() {
            reset(Type::Undefined);
        }

        /**
         *  @brief Sets se::Value to null.
         */
        void setNull() {
            reset(Type::Null);
        }

        /**
         *  @brief Sets se::Value to a boolean value.
         *  @param[in] v The boolean value to be set.
         */
        void setBoolean(bool v) {
            reset(Type::Boolean);
            _u._boolean = v;
        }

        /**
         *  @brief Sets se::Value to a int8_t value.
         *  @param[in] v The int8_t value to be set.
         */
        void setInt8(int8_t v) {
            reset(Type::Number);
            _u._number = (double)v;
        }

        /**
         *  @brief Sets se::Value to a uint8_t value.
         *  @param[in] v The uint8_t value to be set.
         */
        void setUint8(uint8_t v) {
            reset(Type::Number);
            _u._number = (double)v;
        }

        /**
         *  @brief Sets se::Value to a int16_t value.
         *  @param[in] v The int16_t value to be set.
         */
        void setInt16(int16_t v) {
            reset(Type::Number);
            _u._number = (double)v;
        }

        /**
         *  @brief Sets se::Value to a uint16_t value.
         *  @param[in] v The uint16_t value to be set.
         */
        void setUint16(uint16_t v) {
            reset(Type::Number);
            _u._number = (double)v;
        }

        /**
         *  @brief Sets se::Value to a int32_t value.
         *  @param[in] v The int32_t value to be set.
         */
        void setInt32(int32_t v) {
            reset(Type::Number);
            _u._number = (double)v;
        }

        /**
         *  @brief Sets se::Value to a uint32_t value.
         *  @param[in] v The uint32_t value to be set.
         */
        void setUint32(uint32_t v) {
            reset(Type::Number);
            _u._number = (double)v;
        }

        /**
         *  @brief Sets se::Value to a long value.
         *  @param[in] v The long value to be set.
         */
        void setLong(long v) {
            reset(Type::Number);
            _u._number = (double)v;
        }

        /**
         *  @brief Sets se::Value to a unsigned long value.
         *  @param[in] v The unsigned long value to be set.
         */
        void setUlong(unsigned long v) {
            reset(Type::Number);
            _u._number = (double)v;
        }

        /**
         *  @brief Sets se::Value to a float value.
         *  @param[in] v The float value to be set.
         */
        void setFloat(float v) {
            reset(Type::Number);
            _u._number = (double)v;
        }

        /**
         *  @brief Sets se::Value to a double value.
         *  @param[in] v The double value to be set.
         */
        void setNumber(double v) {
            reset(Type::Number);
            _u._number = (double)v;
        }

        /**
         *  @brief Sets se::Value to an UTF8 null-terminated string value.
         *  @param[in] v The UTF8 null-terminated string value to be set.
         */
        void setString(std::string_view v);

        /**
         *  @brief Sets se::Value to se::Object value.
         *  @param[in] o The se::Object to be set.
         *  @param[in] autoRootUnroot Whether to root se::Object and unroot it in se::Value's destructor or unroot it while object is replaced. Default value is false.
         */
        void setObject(Object* o, bool autoRootUnroot = false);

        /**
         *  @brief Sets se::Value to se::HandleObject value.
         *  @param[in] o The se::Object to be set.
         *  @param[in] autoRootUnroot Whether to root se::HandleObject and unroot it in se::Value's destructor or unroot it while object is replaced. Default value is false.
         */
        void setObject(const HandleObject& o, bool autoRootUnroot = false) {
            setObject(o.get(), autoRootUnroot);
        }

        /**
         *  @brief Converts se::Value to int8_t.
         *  @return int8_t integer.
         */
        int8_t toInt8() const {
            return static_cast<int8_t>(toNumber());
        }

        /**
         *  @brief Converts se::Value to uint8_t.
         *  @return uint8_t integer.
         */
        uint8_t toUint8() const {
            return static_cast<uint8_t>(toNumber());
        }

        /**
         *  @brief Converts se::Value to int16_t.
         *  @return int16_t integer.
         */
        int16_t toInt16() const {
            return static_cast<int16_t>(toNumber());
        }

        /**
         *  @brief Converts se::Value to uint16_t.
         *  @return uint16_t integer.
         */
        uint16_t toUint16() const {
            return static_cast<uint16_t>(toNumber());
        }

        /**
         *  @brief Converts se::Value to int32_t.
         *  @return int32_t integer.
         */
        int32_t toInt32() const {
            return static_cast<int32_t>(toNumber());
        }

        /**
         *  @brief Converts se::Value to uint32_t.
         *  @return uint32_t integer.
         */
        uint32_t toUint32() const {
            return static_cast<uint32_t>(toNumber());
        }

        /**
         *  @brief Converts se::Value to long.
         *  @return long integer.
         */
        long toLong() const {
            return static_cast<long>(toNumber());
        }

        /**
         *  @brief Converts se::Value to unsigned long.
         *  @return unsigned long integer.
         */
        unsigned long toUlong() const {
            return static_cast<unsigned long>(toNumber());
        }

        /**
         *  @brief Converts se::Value to float number.
         *  @return float number.
         */
        float toFloat() const {
            return  static_cast<float>(toNumber());
        }

        /**
         *  @brief Converts se::Value to double number.
         *  @return double number.
         */
        double toNumber() const {
            if (__builtin_expect(_type != Type::Boolean, 1)) {
                return _u._number;
            }
            return _u._boolean ? 1.0 : 0.0;
        }

        /**
         *  @brief Converts se::Value to boolean.
         *  @return boolean.
         */
        bool toBoolean() const {
            assert(_type == Type::Boolean);
            return _u._boolean;
        }

        /**
         *  @brief Gets std::string if se::Value stores a string. It will trigger an assertion if se::Value isn't a string.
         *  @return A std::string reference.
         *  @see toStringForce
         */
        const std::string& toString() const {
            assert(_type == Type::String);
            return *_u._string;
        }

        /**
         *  @brief Converts a se::Value to std::string. Could be invoked even when se::Value isn't a string.
         *  @return A copied std::string value.
         *  @see toString
         */
        std::string toStringForce() const;

        /**
         *  @brief Gets the se::Object pointer if se::Value stores an object. It will trigger an assertion if se::Value isn't a object.
         *  @return A se::Object pointer.
         */
        Object* toObject() const {
            assert(isObject());
            return _u._object;
        }

        /**
         *  @brief Gets the type of se::Value.
         *  @return The type of se::Value.
         */
        inline Type getType() const { return _type; }

        /**
         *  @brief Tests whether se::Value stores a number.
         *  @return true if se::Value stores a number, otherwise false.
         */
        inline bool isNumber() const { return _type == Type::Number; }

        /**
         *  @brief Tests whether se::Value stores a string.
         *  @return true if se::Value stores a string, otherwise false.
         */
        inline bool isString() const { return _type == Type::String; }

        /**
         *  @brief Tests whether se::Value stores an object.
         *  @return true if se::Value stores an object, otherwise false.
         */
        inline bool isObject() const { return _type == Type::Object; }

        /**
         *  @brief Tests whether se::Value stores a boolean.
         *  @return true if se::Value stores a boolean, otherwise false.
         */
        inline bool isBoolean() const { return _type == Type::Boolean; }

        /**
         *  @brief Tests whether se::Value stores an undefined value.
         *  @return true if se::Value stores an undefined value, otherwise false.
         */
        inline bool isUndefined() const { return _type == Type::Undefined; }

        /**
         *  @brief Tests whether se::Value stores a null value.
         *  @return true if se::Value stores a null value, otherwise false.
         */
        inline bool isNull() const { return _type == Type::Null; }

        /**
         *  @brief Tests whether se::Value stores a null or an undefined value.
         *  @return true if se::Value stores a null or an undefined value, otherwise false.
         */
        inline bool isNullOrUndefined() const { return (isNull() || isUndefined()); }

    private:
        explicit Value(Type type) {
            memset(&_u, 0, sizeof(_u));
            reset(type);
        }
        void reset(Type type);

        union {
            bool _boolean;
            double _number;
            std::string* _string;
            Object* _object;
        } _u;

        Type _type{Type::Undefined};
        bool _autoRootUnroot{false};
    };

    using ValueArray = std::vector<Value>;
    extern ValueArray EmptyValueArray;

} // namespace se {

typedef se::Object* se_object_ptr;
