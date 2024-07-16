#include "CCCache.h"
#include <memory>
#include <mutex>
#include <cassert>
#include <string_view>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <dirent.h>


#include <vector>
#include <thread>

#include "base/ccUtils.h"
#include "base/ccMacros.h"
#include "base/md5.h"
#include "platform/CCFileUtils.h"

#define COMPRESS_WITH_LZ4 1

#ifndef GPU_TEXTURE_CACHE_SIZE
#define GPU_TEXTURE_CACHE_SIZE (10 * 1024 * 1024)
#endif

#if COMPRESS_WITH_LZ4
#include "base/lz4.h"
namespace {
    std::vector<char> compress(const char *data, size_t len) {
        cocos2d::Perf perf("[CacheDB] compress file");
        auto newSize = LZ4_compressBound(len);
        std::vector<char> output(newSize);
        auto compressedSize = LZ4_compress_default(data, output.data(), len, newSize);
        if (compressedSize <= 0) {
            CCLOGERROR("[CacheDB] failed to compress data");
            output.clear();
        } else {
            CCLOG("[CacheDB] compress from %d -> %d", len, static_cast<int>(compressedSize));
            output.resize(compressedSize);
        }
        return output;
    }
    std::vector<char> decompress(const char *data, size_t len, size_t originSize) {
        cocos2d::Perf perf("[CacheDB] decompress file");
        // cocos2d::log("[CacheDB] decompress file %d", static_cast<int>(originSize));
        std::vector<char> output(originSize);
        auto decompressSize = LZ4_decompress_safe(data, output.data(), len, originSize);
        if(decompressSize <=0) {
            CCLOGERROR("[CacheDB] failed to decompress data: %d", static_cast<int>(originSize));
            output.clear();
            return output;
        }
        return output;
    }

    void removeDirectory(const std::string &path, bool removeSelf) {
        DIR *dir = opendir(path.c_str());
        if(!dir) {
            return;
        }
        std::vector<std::string> subdirs;
        struct dirent *ent;
        while((ent = readdir(dir))) {
            if(strcmp(ent->d_name, ".") == 0){
                continue;
            }
            if(strcmp(ent->d_name, "..") == 0){
                continue;
            }
            if (ent->d_type & DT_DIR) {
                subdirs.push_back(path + "/" + ent->d_name);
            } else {
                if(unlink((path + "/" + ent->d_name).c_str())) {
                    CCLOGERROR("[CacheDB] failed to remove file %s, err: %s", ent->d_name, strerror(errno));
                }
            }
        }
        closedir(dir);
        for(auto &s : subdirs) {
            removeDirectory(s, true);
        }
        if(removeSelf && rmdir(path.c_str())){
            CCLOGERROR("[CacheDB] failed to remove file %s, err: %s", path.c_str(), strerror(errno));
        }
    }
}
#endif

namespace cocos2d {

    constexpr int SIGNATURE_SIZE = 4;
#if COMPRESS_WITH_LZ4
    constexpr int CONTLEN_SIZE =4 ;
#endif

static std::mutex gMtx;
CacheDB* CacheDB::gInstance;

CacheDB *CacheDB::getInstance() {
    std::lock_guard<std::mutex> guard(gMtx);
    if (!gInstance) {
        gInstance = new CacheDB();
        gInstance->init();
    }
    return gInstance;
}

void CacheDB::init() {
    auto imageCache = getCacheDir();
    struct stat st;
    if(stat(imageCache.c_str(), &st)) {
        if(mkdir(imageCache.c_str(), 0700)) {
            CCLOGERROR("Failed to create folder %s, err: %s", imageCache.c_str(), strerror(errno));
            return;
        }
    }
}

std::string CacheDB::createDirForPath(const std::string &path) {
    std::lock_guard<std::mutex> guard(_dirCacheMtx);
    auto hash = getHash(path);
    auto dir = hash.substr(0, 2);
    auto fulldir = getCacheDir() + "/" + dir;
    auto dirit = _dirCache.find(fulldir);
    if(dirit == _dirCache.end()) {
        struct stat st;
        if(stat(fulldir.c_str(), &st)) {
            CCLOG("[CacheDB] create dir: %s", fulldir.c_str());
            if(mkdir(fulldir.c_str(), 0744)){
                _dirCache[fulldir] = false;
                CCLOGERROR("failed to create dir: %s, err: %s", fulldir.c_str(), strerror(errno));
                return {};
            }
        }
        _dirCache[fulldir] = true;
    } else {
        assert(dirit->second); // 目录不应该无法创建
    }
    return fulldir + "/" + hash;
}

bool CacheDB::cacheExists(const std::string & path) {
    auto hash = getHash(path);
    auto dir = hash.substr(0, 2);
    auto fulldir = getCacheDir() + "/" + dir;
    {
        std::lock_guard<std::mutex> guard(_dirCacheMtx);
        auto dirit = _dirCache.find(fulldir);
        if (dirit != _dirCache.end() && !dirit->second) return false;
    }

    auto fullpath = fulldir + "/" + hash;
    struct stat st;
    if(stat(fullpath.c_str(), &st)) {
        CCLOG("[CacheDB] file %s not exists", fullpath.c_str());
        return false;
    }
    return true;
}

bool CacheDB::loadWithHeader(const std::string& path, void *header, size_t headerSize, std::vector<uint8_t> &data) {
    cocos2d::Perf perf("[CacheDB] load from cache");
    std::unique_lock<std::mutex> fileLock(_fileCacheMtx);
    auto itr = _fileCache.find(path);
    char *charmp = nullptr;
    void *mp = nullptr;
    int fd = -1;
    size_t totalSize;
    if(itr == _fileCache.end()) {
        fileLock.unlock();
        if (!cacheExists(path)) return false;
        struct stat st;
        auto fullPath = createDirForPath(path);
        fd = open(fullPath.c_str(), O_RDONLY);
        if (fd < 0) {
            CCLOGERROR("[CacheDB] failed to load file: %s, err: %s\n", fullPath.c_str(),
                       strerror(errno));
            return false;
        }
        if (fstat(fd, &st)) {
            CCLOGERROR("[CacheDB] failed to call fstat: %s, err: %s\n", fullPath.c_str(),
                       strerror(errno));
            close(fd);
            return false;
        }
        totalSize = st.st_size;

        mp = mmap(nullptr, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
        if (mp == MAP_FAILED) {
            CCLOGERROR("[CacheDB] failed to call mmap: %s, err: %s\n", fullPath.c_str(),
                       strerror(errno));
            close(fd);
            return false;
        }
        charmp = reinterpret_cast<char *>(mp);
        if (memcmp(charmp, "xfl", 3) != 0) {
            CCLOGERROR("[CacheDB] file signature invalid: %s, err: %s\n", fullPath.c_str(),
                       strerror(errno));
            munmap(mp, st.st_size);
            close(fd);
            return false;
        }
        fileLock.lock();
        // copy to cache
        auto &cacheItem = _fileCache[path];
        auto &cacheBuffer = std::get<0>(cacheItem);
        std::get<1>(cacheItem) = _fileCacheVer++;
        _fileCacheTotalSize += st.st_size;
        while(_fileCacheTotalSize > GPU_TEXTURE_CACHE_SIZE && _fileCache.size() > 3) {
            auto oldest = std::min_element(_fileCache.begin(), _fileCache.end(), [](const auto &a, const auto &b){
                return std::get<1>(a) > std::get<1>(b);
            });
            _fileCacheTotalSize -= std::get<1>(oldest->second);
            _fileCache.erase(oldest);
        }

        fileLock.unlock();
        cacheBuffer.resize(st.st_size);
        memcpy(cacheBuffer.data(), mp, cacheBuffer.size());
    } else {
        auto &cacheBuffer = std::get<0>(itr->second);
        charmp = reinterpret_cast<char*>(cacheBuffer.data());
        totalSize = cacheBuffer.size();
        std::get<1>(itr->second) = _fileCacheVer++;
        fileLock.unlock();
    }

    // TODO version check
    assert(charmp[3] == 1);

    charmp += SIGNATURE_SIZE;
    memcpy(header, charmp, headerSize);
    charmp += headerSize;
#if COMPRESS_WITH_LZ4
    int32_t originSize;
    memcpy(&originSize, charmp, sizeof(originSize));
    charmp += sizeof(originSize);
    auto output = decompress(charmp, totalSize - headerSize - 8, originSize);
    data = std::move(*reinterpret_cast<std::vector<uint8_t>*>(&output));
#else
    data.resize(totalSize - headerSize - SIGNATURE_SIZE);
    memcpy(data.data(), charmp, data.size());
#endif
    if(fd > 0) {
        close(fd);
    }
    if(mp) {
       munmap(mp, totalSize);
    }
    return true;
}

void CacheDB::saveWithHeader(const std::string& path, const void *header, size_t headerSize, const std::span<uint8_t> &data) {

    static char tag[4]= {'x','f','l', 1};

    auto fullPath = createDirForPath(path);
    int fd = open(fullPath.c_str(), O_RDWR | O_TRUNC|O_CREAT, 0644);
    if(fd < 0) {
        CCLOGERROR("[CacheDB] faild to create file: %s, err:%s", fullPath.c_str(), strerror(errno));
        return;
    }
#if COMPRESS_WITH_LZ4
    auto originSize = static_cast<int32_t>(data.size());
    auto compressedData = compress(reinterpret_cast<const char*>(data.data()), data.size());
    // - [4B-signature][NB-imageinfo][4B-contentLength][compressedData];
    auto totalSize = headerSize + compressedData.size() + SIGNATURE_SIZE + CONTLEN_SIZE;
#else
    // - [4B-signature][NB-imageinfo][compressedData];
    auto totalSize = headerSize + data.size() + SIGNATURE_SIZE;
#endif
    if(ftruncate(fd, totalSize)) {
        CCLOGERROR("[CacheDB] faild to truncate file: %s to %d, err:%s", fullPath.c_str(), (int)totalSize ,strerror(errno));
        close(fd);
        return;
    }
    void *mp = mmap(nullptr, totalSize, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    char *charmp = reinterpret_cast<char*>(mp);

    memcpy(charmp, tag , SIGNATURE_SIZE);
    charmp += SIGNATURE_SIZE;
    memcpy(charmp, header, headerSize);
    charmp += headerSize;
#if COMPRESS_WITH_LZ4
    memcpy(charmp, &originSize, sizeof(originSize));
    charmp += CONTLEN_SIZE;
    memcpy(charmp, compressedData.data(), compressedData.size());
#else
    memcpy(charmp, data.data(), data.size());
#endif
    munmap(mp, totalSize);
    close(fd);
}


const std::string & CacheDB::getHash(const std::string& path) {
    std::lock_guard<std::mutex> guard(_hashCodeMtx);
    auto it = _hashCache.find(path);
    if(it == _hashCache.end()) {
        MD5 md5;
        auto hash = md5(path.data(), path.length());
        return _hashCache[path] = hash;
    }
    return it->second;
}

std::string CacheDB::getWritablePath() const { // NOLINT
    return cocos2d::FileUtils::getInstance()->getWritablePath();
}

std::string CacheDB::getCacheDir() const {
    static std::string cacheDir;
    if(cacheDir.empty()) {
        auto p = getWritablePath();
        cacheDir = p.ends_with('/') ? p + "image_cache" : p + "/image_cache";
    }
    return cacheDir;
}


void CacheDB::clear() {
    {
        std::unique_lock<std::mutex> guard(_fileCacheMtx);
        _fileCache.clear();
        _fileCacheVer = 1;
        _fileCacheTotalSize = 0;
    }
    _dirCacheMtx.lock();
    _dirCache.clear();
    auto root = getCacheDir();
    std::thread task([root, mtx = &_dirCacheMtx](){
        struct stat st;
        if(stat(root.c_str(), &st)){
            return;
        }
        removeDirectory(root, false);
        mtx->unlock();
    });
    task.detach();
}

} // namespace cocos2d