#include "platform/CCPlatformConfig.h"
#if __ANDROID__ || CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include "./v8-12.x/Value.cpp"
#else
#include "./v8-8.x/Value.cpp"
#endif
