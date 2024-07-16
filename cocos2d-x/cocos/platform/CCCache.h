#pragma once

#include <initializer_list>
#include <string>
#include <string_view>
#include <unordered_map>
#include <memory>
#include <span>
#include <mutex>

namespace cocos2d {
class CacheDB final{
private:
    static CacheDB* gInstance;
public:
    static CacheDB *getInstance();

protected:
    CacheDB() = default;
public:
    ~CacheDB() = default;

    void init();

    template<typename T>
    bool load(const std::string& path, T &t, std::vector<uint8_t> &output) {
        return loadWithHeader(path, &t, sizeof(t), output);
    }

    template<typename T>
    void store(const std::string& path,const T &t, const std::span<uint8_t> &list) {
        saveWithHeader(path, &t, sizeof(T), list);
    }


    void clear();
    
private:
    std::string createDirForPath(const std::string& path);
    bool cacheExists(const std::string& path);
    bool loadWithHeader(const std::string& path, void *, size_t, std::vector<uint8_t> &);
    void saveWithHeader(const std::string& path, const void *, size_t, const std::span<uint8_t> &);
    const std::string &getHash(const std::string& path);
    std::string getWritablePath() const;
    std::string getCacheDir() const;
    std::unordered_map<std::string, bool> _dirCache;
    std::unordered_map<std::string, std::string> _hashCache;
    std::unordered_map<std::string, std::tuple<std::vector<uint8_t>, uint64_t>> _fileCache;
    size_t _fileCacheTotalSize{0};
    uint64_t _fileCacheVer {1};

    std::mutex _hashCodeMtx;
    std::mutex _dirCacheMtx;
    std::mutex _fileCacheMtx;
//    std::string _writableDir;
};
} // namespace cocos2d