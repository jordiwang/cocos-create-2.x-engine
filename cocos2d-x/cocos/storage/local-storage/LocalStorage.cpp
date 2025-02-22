/*

 Copyright (c) 2012 - Zynga Inc.
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

 */

/*
 Local Storage support for the JS Bindings for iOS.
 Works on cocos2d-iphone and cocos2d-x.
 */

#include "storage/local-storage/LocalStorage.h"
#include "base/ccMacros.h"

#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include <sqlite3/sqlite3.h>
#else
#include <sqlite3.h>
#endif

#include <unordered_map>

namespace  {
int _initialized = 0;
sqlite3 *_db;
sqlite3_stmt *_stmt_select;
sqlite3_stmt *_stmt_remove;
sqlite3_stmt *_stmt_update;
sqlite3_stmt *_stmt_clear;
sqlite3_stmt *_stmt_key;
sqlite3_stmt *_stmt_count;

void localStorageCreateTable()
{
    const char *sql_createtable = "CREATE TABLE IF NOT EXISTS data(key TEXT PRIMARY KEY,value TEXT);";
    sqlite3_stmt *stmt;
    int ok = sqlite3_prepare_v2(_db, sql_createtable, -1, &stmt, nullptr);
    ok |= sqlite3_step(stmt);
    ok |= sqlite3_finalize(stmt);

    if( ok != SQLITE_OK && ok != SQLITE_DONE)
        printf("Error in CREATE TABLE\n");
}

struct CacheItem {
    std::optional<std::string> value;
    bool isDeleted{false};
    bool isDirty{false};
};

std::unique_ptr<std::unordered_map<std::string, CacheItem>> gCache;

void flushCache();

/** sets an item in the LS */
void localStorageSetItem_( const std::string& key, const std::string& value)
{
    assert( _initialized );
    int ok = sqlite3_bind_text(_stmt_update, 1, key.c_str(), -1, SQLITE_TRANSIENT);
    ok |= sqlite3_bind_text(_stmt_update, 2, value.c_str(), -1, SQLITE_TRANSIENT);

    ok |= sqlite3_step(_stmt_update);

    ok |= sqlite3_reset(_stmt_update);

    if( ok != SQLITE_OK && ok != SQLITE_DONE)
        printf("Error in localStorage.setItem()\n");
}

/** gets an item from the LS */
bool localStorageGetItem_( const std::string& key, std::string *outItem )
{
    assert( _initialized );
    int ok = sqlite3_reset(_stmt_select);

    ok |= sqlite3_bind_text(_stmt_select, 1, key.c_str(), -1, SQLITE_TRANSIENT);
    ok |= sqlite3_step(_stmt_select);
    const unsigned char *text = sqlite3_column_text(_stmt_select, 0);

    if ( ok != SQLITE_OK && ok != SQLITE_DONE && ok != SQLITE_ROW )
    {
        printf("Error in localStorage.getItem()\n");
        return false;
    }
    else if (!text)
    {
        return false;
    }
    else
    {
        outItem->assign((const char*)text);
        return true;
    }
}

/** removes an item from the LS */
void localStorageRemoveItem_( const std::string& key )
{
    assert( _initialized );
    int ok = sqlite3_bind_text(_stmt_remove, 1, key.c_str(), -1, SQLITE_TRANSIENT);

    ok |= sqlite3_step(_stmt_remove);

    ok |= sqlite3_reset(_stmt_remove);

    if( ok != SQLITE_OK && ok != SQLITE_DONE)
        printf("Error in localStorage.removeItem()\n");
}

/** removes all items from the LS */
void localStorageClear_()
{
    assert( _initialized );
    int ok = sqlite3_step(_stmt_clear);

    ok |= sqlite3_reset(_stmt_clear);

    if( ok != SQLITE_OK && ok != SQLITE_DONE)
        printf("Error in localStorage.clear()\n");
}


void flushCache() {
    if(!gCache) return;
    for(auto it = gCache->begin(); it != gCache->end();) {
        if(it->second.isDeleted) {
            localStorageRemoveItem_(it->first);
            it = gCache->erase(it);
            continue;
        } else if(it->second.isDirty && it->second.value.has_value()) {
            localStorageSetItem_(it->first, it->second.value.value());
            it->second.isDirty = false;
            it->second.isDeleted = false;
        }
        it++;
    }
}

}

void localStorageInit( const std::string& fullpath/* = "" */)
{
    if (!_initialized) {

        int ret = 0;

        if (fullpath.empty())
            ret = sqlite3_open(":memory:", &_db);
        else
            ret = sqlite3_open(fullpath.c_str(), &_db);

        localStorageCreateTable();

        // SELECT
        const char *sql_select = "SELECT value FROM data WHERE key=?;";
        ret |= sqlite3_prepare_v2(_db, sql_select, -1, &_stmt_select, nullptr);

        // REPLACE
        const char *sql_update = "REPLACE INTO data (key, value) VALUES (?,?);";
        ret |= sqlite3_prepare_v2(_db, sql_update, -1, &_stmt_update, nullptr);

        // DELETE
        const char *sql_remove = "DELETE FROM data WHERE key=?;";
        ret |= sqlite3_prepare_v2(_db, sql_remove, -1, &_stmt_remove, nullptr);
        
        // Clear
        const char *sql_clear = "DELETE FROM data;";
        ret |= sqlite3_prepare_v2(_db, sql_clear, -1, &_stmt_clear, nullptr);

        // key
        const char *sql_key = "SELECT key FROM data ORDER BY ROWID ASC;";
        ret |= sqlite3_prepare_v2(_db, sql_key, -1, &_stmt_key, nullptr);

        //count
        const char *sql_count = "SELECT COUNT(*) FROM data;";
        ret |= sqlite3_prepare_v2(_db, sql_count, -1, &_stmt_count, nullptr);

        if( ret != SQLITE_OK ) {
            printf("Error initializing DB\n");
            // report error
        }
        gCache = std::make_unique<std::unordered_map<std::string, CacheItem>>();
        _initialized = 1;
    }
    
}

/** Sets an item in the JS. */
void localStorageSetItem( const std::string& key, const std::string& value) {
    auto &item = (*gCache)[key];
    item.isDeleted = false;
    if(item.value.has_value()) {
        item.isDirty = item.value.value() != value;
    }else{
        item.isDirty = true;
    }
    item.value = value;
}

/** Gets an item from the JS. */
bool localStorageGetItem( const std::string& key, std::string *outItem ){
    auto itr = gCache->find(key);
    if(itr == gCache->end()) {
        auto &item = (*gCache)[key];
        bool ret = localStorageGetItem_(key, outItem);
        if(ret) {
            item.value = *outItem;
        } else {
            item.value = std::nullopt;
        }
        item.isDirty = false;
        item.isDeleted = false;
        return ret;
    }
    
    auto &v = itr->second.value;
    if(itr->second.isDeleted) {
        return false;
    }
    if(v.has_value()) {
        *outItem = v.value();
    }
    return v.has_value();

}

/** Removes an item from the JS. */
void localStorageRemoveItem( const std::string& key ) {
    auto &item = (*gCache)[key];
    item.isDeleted = true;
}

/** Removes all items from the JS. */
void localStorageClear() {
    flushCache();
    gCache->clear();
    localStorageClear_();
}

void localStorageFree()
{
    if (_initialized) {
        flushCache();
        sqlite3_finalize(_stmt_select);
        sqlite3_finalize(_stmt_remove);
        sqlite3_finalize(_stmt_update);
        sqlite3_finalize(_stmt_clear);
        sqlite3_finalize(_stmt_key);
        sqlite3_finalize(_stmt_count);

        sqlite3_close_v2(_db);
        gCache.reset();
        _initialized = 0;
    }
}




/** gets an key from the JS. */
void localStorageGetKey( const int nIndex, std::string *outKey )
{
    assert( _initialized );
    flushCache();
    if (nIndex < 0)
    {
        printf("Error in input localStorage index Less than zero\n");
        return;
    }
    int ok = sqlite3_reset(_stmt_key);

    ok |= sqlite3_step(_stmt_key);

    int nCount = 0;
    const unsigned char *text = nullptr;
    while (ok == SQLITE_ROW)
    {
        if (nCount == nIndex)
        {
            text = sqlite3_column_text(_stmt_key, 0);
            break;
        }

        ok |= sqlite3_step(_stmt_key);
        nCount++;
    }

    if ( ok != SQLITE_OK && ok != SQLITE_DONE && ok != SQLITE_ROW )
    {
        printf("Error in localStorage.key(n)\n");
    }
    else if (!text)
    {
        return;
    }
    else
    {
        outKey->assign((const char*)text);
    }
}

/** gets all items count in the JS. */
void localStorageGetLength( int& outLength )
{
    assert( _initialized );
    flushCache();
    int ok = sqlite3_reset(_stmt_count);

    ok |= sqlite3_step(_stmt_count);

    if ( ok != SQLITE_OK && ok != SQLITE_DONE && ok != SQLITE_ROW )
    {
        printf("Error in localStorage.length\n");
        outLength = 0;
    }
    else
    {
        outLength = sqlite3_column_int(_stmt_count, 0);
    }
}

void localStorageCacheSync() {
    flushCache();
}

#endif // #if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
