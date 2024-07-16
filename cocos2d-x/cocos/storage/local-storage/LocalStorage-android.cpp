/***************************************************************************
 Copyright (c) 2012 Zynga Inc.
 Copyright (c) 2013 cocos2d-x.org
 Copyright (c) 2013-2016 Chukong Technologic Inc.
 Copyright (c) 2013-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

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
***************************************************************************/


/*
 Local Storage support for the JS Bindings for iOS.
 Works on cocos2d-iphone and cocos2d-x.
 */

#include "storage/local-storage/LocalStorage.h"
#include "base/ccMacros.h"
#include <optional>

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <unordered_map>
#include <vector>
#include "jni.h"
#include "platform/android/jni/JniHelper.h"

#ifndef JCLS_LOCALSTORAGE
#define JCLS_LOCALSTORAGE  "org/cocos2dx/lib/Cocos2dxLocalStorage"
#endif

USING_NS_CC;
static int _initialized = 0;

static void localStorageSetItemListNoCache(const std::vector<std::string> &);
static void localStorageRemoveItemNoCache( const std::string& key );

namespace {
    struct ValueItem {
        bool isDirty = false;
        bool isDeleted = false;
        std::optional<std::string> value;
    };
    std::unordered_map<std::string, ValueItem> gStorageCache;
    bool gCacheEnabled = true;
    bool gCacheDirty = false;

    bool cachePut(const std::string &key, const std::optional<std::string> &value) {

        if(!gCacheEnabled) return false;
        gCacheDirty = true;
        auto itr = gStorageCache.find(key);
        if(itr == gStorageCache.end()) {
            auto &item = gStorageCache[key];
            item.value = value;
            item.isDirty = true;
            item.isDeleted = false;
            return true;
        }
        if(itr->second.value != value) {
            itr->second.value = value;
            itr->second.isDirty = true;
        }
        itr->second.isDeleted = false;
        return true;
    }


    bool cacheGet(const std::string &key, std::optional<std::string> &value) {
        if(!gCacheEnabled) {
            value = std::nullopt;
            return false;
        }
        auto itr = gStorageCache.find(key);
        if(itr == gStorageCache.end()) {
            value = std::nullopt;
            return false;
        }
        if(itr->second.isDeleted || itr->second.value->empty()) {
            value = std::nullopt;
        } else {
            value = itr->second.value;
        }
        return true;
    }

    bool cacheDelete(const std::string &key) {
        if(!gCacheEnabled) return false;
        gCacheDirty = true;
        auto itr = gStorageCache.find(key);
        if(itr != gStorageCache.end()) {
            itr->second.isDeleted = true;
            return true;
        }
        return false;
    }

    void cacheReset() {
        if(!_initialized) return;
        gStorageCache.clear();
        gCacheDirty = false;
    }

    void cacheSync() {
        if(!_initialized) return;
        if(!gCacheDirty) return;
        std::vector<std::string> toUpdate;
        for(auto itr = gStorageCache.begin(); itr != gStorageCache.end(); )  {
            auto &key = itr->first;
            auto &item = itr->second;
            if(item.isDeleted) {
               localStorageRemoveItemNoCache(key);
               itr = gStorageCache.erase(itr);
               continue;
            } else if(item.isDirty) {
                if(item.value.has_value()) {
                    toUpdate.push_back(key);
                    toUpdate.push_back(item.value.value());
                }
                item.isDirty = false;
            }
            itr++;
        }
        if(!toUpdate.empty()) {
            localStorageSetItemListNoCache(toUpdate);
        }

        gCacheDirty = false;
    }
}

static void splitFilename (std::string& str)
{
    size_t found = 0;
    found=str.find_last_of("/\\");
    if (found != std::string::npos)
    {
        str = str.substr(found+1);
    }
}

void localStorageInit( const std::string& fullpath)
{
    if (fullpath.empty())
        return;

    if( ! _initialized )
    {
        std::string strDBFilename = fullpath;
        splitFilename(strDBFilename);
        if (JniHelper::callStaticBooleanMethod(JCLS_LOCALSTORAGE, "init", strDBFilename, "data")) {
            _initialized = 1;
        }
    }
}

void localStorageFree()
{
    if (_initialized) {
        JniHelper::callStaticVoidMethod(JCLS_LOCALSTORAGE, "destroy");
        _initialized = 0;
    }
}

/** sets an item in the LS */
void localStorageSetItem( const std::string& key, const std::string& value)
{
    assert( _initialized );
    if(cachePut(key, value)) return;
    JniHelper::callStaticVoidMethod(JCLS_LOCALSTORAGE, "setItem", key, value);
}

void localStorageSetItemListNoCache(const std::vector<std::string> &pairs)
{
    assert( _initialized );
    auto *env = JniHelper::getEnv();
    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray pairArray = env->NewObjectArray(pairs.size(), stringClass, nullptr);
    int strIndex = 0;
    for(auto &value : pairs) {
       jstring str = env->NewStringUTF(value.c_str());
       env->SetObjectArrayElement(pairArray, strIndex, str);
       env->DeleteLocalRef(str);
       strIndex++;
    }
    JniMethodInfo setItemList;
    static const char signature[] = "([Ljava/lang/String;)V";
    if(JniHelper::getStaticMethodInfo(setItemList, JCLS_LOCALSTORAGE, "setItemList", signature)) {
        env->CallStaticVoidMethod(setItemList.classID, setItemList.methodID, pairArray);
        env->DeleteLocalRef(setItemList.classID);
    }else{
        assert(false);
    }
    env->DeleteLocalRef(pairArray);
    env->DeleteLocalRef(stringClass);
}

/** gets an item from the LS */
bool localStorageGetItem( const std::string& key, std::string *outItem )
{
    assert( _initialized );
    JniMethodInfo t;

    std::optional<std::string> outOpt;
    if(cacheGet(key, outOpt)){
        if(outOpt.has_value()) {
            *outItem = outOpt.value();
        }
        return outOpt.has_value();
    }

    if (JniHelper::getStaticMethodInfo(t, JCLS_LOCALSTORAGE, "getItem", "(Ljava/lang/String;)Ljava/lang/String;"))
    {
        jstring jkey = t.env->NewStringUTF(key.c_str());
        jstring jret = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID, jkey);
        if (jret == nullptr)
        {
            cachePut(key, std::nullopt);

            t.env->DeleteLocalRef(jret);
            t.env->DeleteLocalRef(jkey);
            t.env->DeleteLocalRef(t.classID);
            return false;
        }
        else
        {
            outItem->assign(JniHelper::jstring2string(jret));
            // store value to cache
            cachePut(key, *outItem);

            t.env->DeleteLocalRef(jret);
            t.env->DeleteLocalRef(jkey);
            t.env->DeleteLocalRef(t.classID);
            return true;
        }
    }
    else
    {
        return false;
    }
}

/** removes an item from the LS */
void localStorageRemoveItem( const std::string& key )
{
    assert( _initialized );
    if(cacheDelete(key)){return;}
    JniHelper::callStaticVoidMethod(JCLS_LOCALSTORAGE, "removeItem", key);
}

/** removes an item from the LS */
void localStorageRemoveItemNoCache( const std::string& key )
{
    assert( _initialized );
    JniHelper::callStaticVoidMethod(JCLS_LOCALSTORAGE, "removeItem", key);
}

/** removes all items from the LS */
void localStorageClear()
{
    assert( _initialized );
    cacheReset();
    JniHelper::callStaticVoidMethod(JCLS_LOCALSTORAGE, "clear");
}

/** gets an key from the JS. */
void localStorageGetKey( const int nIndex, std::string *outKey )
{
    assert( _initialized );
    cacheSync();
    outKey->assign(JniHelper::callStaticStringMethod(JCLS_LOCALSTORAGE,"getKey",nIndex));
}

/** gets all items count in the JS. */
void localStorageGetLength( int& outLength )
{
    assert( _initialized );
    cacheSync();
    outLength = JniHelper::callStaticIntMethod(JCLS_LOCALSTORAGE,"getLength");
}

#if __ANDROID__
void localStorageCacheSync() {
    cacheSync();
}

void localStorageCacheEnable(bool enable) {
    if(gCacheEnabled != enable) {
        if(!enable) {
            cacheSync();
            cacheReset();
        }
        gCacheEnabled = enable;
    }
}

bool localStorageCache_IsEnable() {
    return gCacheEnabled;
}
#endif // #if __ANDROID__

#endif // #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
