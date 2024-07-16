#pragma once

#include <cstdint>

extern "C" {

struct decode_image_info_t {
    uint8_t *data;
    uint32_t dataLen;
    uint32_t width;
    uint32_t height;
    bool has_alpha;
    bool is_compressed;
};

void decode_image_init();

void decode_image_set_logger(void (*log)(const char *msg));

bool decode_image_buffer(const uint8_t *data, uint32_t dataSize, const char *format, decode_image_info_t *info, void *(*allocate)(size_t len));

}
