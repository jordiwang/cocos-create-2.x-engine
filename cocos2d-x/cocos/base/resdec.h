#pragma once

#include <cstdint>
#include <string_view>

#define decodeResource shgver3_ifkytext
#define encodeResource x342sghs2499hjs_

namespace hsext {
   bool decodeResource(const uint8_t *header, size_t headerLen,
                       const uint8_t *key, size_t keyLen,
                       const uint8_t *src, size_t srcLen,
                       uint8_t *output, size_t *outLen);
}