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
#include "Value.hpp"
#include "Object.hpp"

namespace se {

    ValueArray EmptyValueArray;

    Value Value::Null = Value(Type::Null);
    Value Value::Undefined = Value(Type::Undefined);


    Value& Value::operator=(const Value& v)
    {
        if (this != &v)
        {
            reset(v.getType());

            switch (_type) {
                case Type::Null:
                case Type::Undefined:
                {
                    memset(&_u, 0, sizeof(_u));
                    break;
                }
                case Type::Number:
                    _u._number = v._u._number;
                    break;
                case Type::String:
                    *_u._string = *v._u._string;
                    break;
                case Type::Boolean:
                    _u._boolean = v._u._boolean;
                    break;
                case Type::Object:
                {
                    setObject(v._u._object, v._autoRootUnroot);
                }
                    break;
                default:
                    break;
            }
        }
        return *this;
    }

    Value& Value::operator=(Value&& v) noexcept
    {
        if (this != &v)
        {
            reset(v.getType());

            switch (_type) {
                case Type::Null:
                case Type::Undefined:
                {
                    memset(&_u, 0, sizeof(_u));
                    break;
                }
                case Type::Number:
                    _u._number = v._u._number;
                    break;
                case Type::String:
                    *_u._string = std::move(*v._u._string);
                    break;
                case Type::Boolean:
                    _u._boolean = v._u._boolean;
                    break;
                case Type::Object:
                {
                    if (_u._object != nullptr) // When old value is also an Object, reset will take no effect, therefore, _u._object may not be nullptr.
                    {
                        if (_autoRootUnroot)
                        {
                            _u._object->unroot();
                        }
                        _u._object->decRef();
                    }
                    _u._object = v._u._object;
                    _autoRootUnroot = v._autoRootUnroot;
                    v._u._object = nullptr; // Reset to nullptr here to avoid 'release' operation in v.reset(Type::Undefined) since it's a move operation here.
                    v._autoRootUnroot = false;
                }
                    break;
                default:
                    break;
            }

            v.reset(Type::Undefined);
        }
        return *this;
    }

    void Value::setString(std::string_view v)
    {
        if(v.data()) {
            reset(Type::String);
            *_u._string = v;
        } else {
            reset(Type::Null);
        }
    }

   	void Value::setObject(Object* object, bool autoRootUnroot/* = false*/)
    {
        if (object == nullptr)
        {
            reset(Type::Null);
            return;
        }

        if (_type != Type::Object)
        {
            reset(Type::Object);
        }

        if (_u._object != object)
        {
            if (object != nullptr)
            {
                object->incRef();
                if (autoRootUnroot)
                {
                    object->root();
                }
            }

            if (_u._object != nullptr) // When old value is also an Object, reset will take no effect, therefore, _u._object may not be nullptr.
            {
                if (_autoRootUnroot)
                {
                    _u._object->unroot();
                }
                _u._object->decRef();
            }
            _u._object = object;
            _autoRootUnroot = autoRootUnroot;
        }
        else
        {
            _autoRootUnroot = autoRootUnroot;
            if (_autoRootUnroot)
            {
                _u._object->root();
            }
        }
    }

    std::string Value::toStringForce() const
    {
        std::string ret;
        if (_type == Type::String)
        {
            ret = *_u._string;
        }
        else if (_type == Type::Boolean)
        {
            ret = _u._boolean ? "true" : "false";
        }
        else if (_type == Type::Number)
        {
            char tmp[50] = {0};
            snprintf(tmp, sizeof(tmp), "%.17g", _u._number);
            ret = tmp;
        }
        else if (_type == Type::Object)
        {
            ret = toObject()->toString();
        }
        else if (_type == Type::Null)
        {
            ret = "null";
        }
        else if (_type == Type::Undefined)
        {
            ret = "undefined";
        }
        else
        {
            assert(false);
        }

        return ret;
    }

    void Value::reset(Type type)
    {
        if (_type != type)
        {
            switch (_type) {
                case Type::String:
                    delete _u._string;
                    break;
                case Type::Object:
                {
                    if (_u._object != nullptr)
                    {
                        if (_autoRootUnroot)
                        {
                            _u._object->unroot();
                        }
                        _u._object->decRef();
                        _u._object = nullptr;
                    }

                    _autoRootUnroot = false;
                    break;
                }
                default:
                    break;
            }

            memset(&_u, 0, sizeof(_u));

            switch (type) {
                case Type::String:
                    _u._string = new std::string();
                    break;
                default:
                    break;
            }
            _type = type;
        }
    }

} // namespace se {
