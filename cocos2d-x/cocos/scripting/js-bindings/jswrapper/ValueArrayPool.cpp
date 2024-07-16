/****************************************************************************
 Copyright (c) 2016 Chukong Technologies Inc.
 Copyright (c) 2017-2023 Xiamen Yaji Software Co., Ltd.

 http://www.cocos.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 of the Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:

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

#include "ValueArrayPool.h"
#include "base/ccMacros.h"
#include <cassert>

#ifdef __GNUC__
# define LIKELY(X) __builtin_expect(!!(X), 1)
# define UNLIKELY(X) __builtin_expect(!!(X), 0)
#else
# define LIKELY(X) (X)
# define UNLIKELY(X) (X)
#endif

namespace se {

thread_local ValueArrayPool gValueArrayPool;

#define SE_DEFAULT_MAX_DEPTH (5)

ValueArrayPool::ValueArrayPool() {
    _pools.resize(SE_DEFAULT_MAX_DEPTH);
    for (uint32_t i = 0; i < SE_DEFAULT_MAX_DEPTH; ++i) {
        initPool(i);
    }
}

ValueArray &ValueArrayPool::get(uint32_t argc, bool &outNeedDelete) {
    if (UNLIKELY(_depth >= _pools.size())) {
        outNeedDelete = true;
        auto *ret = new ValueArray();
        ret->resize(argc);
        return *ret;
    }

    outNeedDelete = false;
    assert(argc < MAX_ARGS);
    auto &ret = _pools[_depth][argc];
    assert(ret.size() == argc);
    return ret;
}

void ValueArrayPool::initPool(uint32_t index) {
    auto &pool = _pools[index];
    uint32_t i = 0;
    for (; i < pool.size(); i++) {
        pool[i].resize(i);
    }
}

} // namespace se
