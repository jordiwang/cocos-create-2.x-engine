#include "resdec.h"

#if __ARM_NEON
#include <arm_neon.h>
#endif
#include <string_view>
#include <cstring>
#include <cassert>

#define QBYTES 16

namespace hsext {
    bool decodeResource(const uint8_t *header, size_t headerLen,
                   const uint8_t *key, size_t keyLen,
                   const uint8_t *src, size_t srcLen,
                   uint8_t *output, size_t *outLen) {
        assert(headerLen > 0);
        assert(keyLen > 0);
        assert(keyLen <= 16);
        if (srcLen < headerLen || memcmp(header, src, headerLen) != 0) return false;
        src += headerLen;
        int32_t remainBytes = srcLen - headerLen;
        if(outLen) *outLen = remainBytes;
#if __ARM_NEON
        if (keyLen <= QBYTES && remainBytes >= QBYTES) {
            uint8_t keyBlock[QBYTES] = {};
            int keyChunks = QBYTES / keyLen;
            int batchSize = keyChunks * keyLen;
            for(int i = 0;i < keyChunks; i++) {
                memcpy(keyBlock + i * keyLen, key, keyLen);
            }
            uint8x16_t qKey = vld1q_u8(keyBlock);
            size_t batchCnt = remainBytes / batchSize;
            size_t batchRemain = remainBytes % batchSize;
            int batchAlign = QBYTES - batchSize;
            if(batchRemain < batchAlign){
                batchCnt-=1; // prevent memory overflow
                batchRemain += batchSize;
            }
            for(int i = 0 ;i < batchCnt; i++) {
                uint8x16_t chunk = vld1q_u8(src);
                uint8x16_t chunkResult = veorq_u8(chunk, qKey);
                vst1q_u8(output, chunkResult);
                src += batchSize;
                output += batchSize;
            }
            for(int i = 0; i < batchRemain; i++) {
                *output = keyBlock[i % batchSize] ^ (*src);
                src +=1;
                output += 1;
            }
        } else {
            for(int i = 0; i < remainBytes; i++) {
                *output = key[i % keyLen] ^ (*src);
                src +=1;
                output += 1;
            }
        }
#else
        for(int i = 0; i < remainBytes; i++) {
            *output = key[i % keyLen] ^ (*src);
            src +=1;
            output += 1;
        }
#endif
        return true;
    }

}

