LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := cocos_worker_encdec 
LOCAL_SRC_FILES := scripting/js-bindings/jswrapper/v8-12.x/WebWorkerEndec.cpp 
LOCAL_CPPFLAGS  += -fno-rtti
LOCAL_C_INCLUDES := $(LOCAL_PATH) \
  $(LOCAL_PATH)/../external/android/arm64-v8a/include \
  $(LOCAL_PATH)/../external/android/arm64-v8a/include/v8

LOCAL_STATIC_LIBRARIES += v8_static
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dx_static
LOCAL_MODULE_FILENAME := libcocos2d

LOCAL_ARM_MODE := arm

ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
MATHNEONFILE := math/MathUtil.cpp.neon
else
MATHNEONFILE := math/MathUtil.cpp
endif

ifeq ($(TARGET_ARCH_ABI),x86)
  USE_V8_DEBUGGER := 0
endif

ifeq ($(USE_V8_DEBUGGER),0)
  LOCAL_CPPFLAGS += -DUSE_V8_DEBUGGER=0
  LOCAL_CFLAGS += -DUSE_V8_DEBUGGER=0
endif

LOCAL_SRC_FILES := \
cocos2d.cpp \
platform/CCFileUtils.cpp \
platform/CCCache.cpp \
platform/CCImage.cpp \
platform/CCTimer.cpp \
platform/CCSAXParser.cpp \
platform/CountdownTrigger.cpp \
platform/CCCache.cpp \
$(MATHNEONFILE) \
math/CCGeometry.cpp \
math/CCVertex.cpp \
math/Mat4.cpp \
math/Quaternion.cpp \
math/Vec2.cpp \
math/Vec3.cpp \
math/Vec4.cpp \
math/Mat3.cpp \
base/CCAutoreleasePool.cpp \
base/CCConfiguration.cpp \
base/CCData.cpp \
base/CCRef.cpp \
base/CCValue.cpp \
base/CCThreadPool.cpp \
base/TGAlib.cpp \
base/ZipUtils.cpp \
base/base64.cpp \
base/ccCArray.cpp \
base/ccRandom.cpp \
base/ccTypes.cpp \
base/ccUTF8.cpp \
base/ccUtils.cpp \
base/astc.cpp \
base/etc1.cpp \
base/etc2.cpp \
base/pvr.cpp \
base/CCLog.cpp \
base/csscolorparser.cpp \
base/CCGLUtils.cpp \
base/CCRenderTexture.cpp \
base/resdec.cpp \
base/md5.cpp \
base/lz4.cpp \
storage/local-storage/LocalStorage-android.cpp \
network/CCDownloader.cpp \
network/CCDownloader-android.cpp \
network/Uri.cpp \
network/HttpClient-android.cpp \
scripting/js-bindings/auto/jsb_cocos2dx_auto.cpp \
scripting/js-bindings/auto/jsb_cocos2dx_extension_auto.cpp \
scripting/js-bindings/auto/jsb_cocos2dx_network_auto.cpp \
scripting/js-bindings/manual/JavaScriptJavaBridge.cpp \
scripting/js-bindings/manual/jsb_opengl_manual.cpp \
scripting/js-bindings/manual/jsb_opengl_utils.cpp \
scripting/js-bindings/manual/jsb_classtype.cpp \
scripting/js-bindings/manual/jsb_conversions.cpp \
scripting/js-bindings/manual/jsb_cocos2dx_manual.cpp \
scripting/js-bindings/manual/jsb_global.cpp \
scripting/js-bindings/manual/jsb_xmlhttprequest.cpp \
scripting/js-bindings/manual/jsb_cocos2dx_network_manual.cpp \
scripting/js-bindings/manual/jsb_platform_android.cpp \
scripting/js-bindings/manual/jsb_worker_manual.cpp \
scripting/js-bindings/jswrapper/config.cpp \
scripting/js-bindings/jswrapper/ValueArrayPool.cpp \
scripting/js-bindings/jswrapper/HandleObject.cpp \
scripting/js-bindings/jswrapper/MappingUtils.cpp \
scripting/js-bindings/jswrapper/RefCounter.cpp \
scripting/js-bindings/jswrapper/Value.cpp \
scripting/js-bindings/jswrapper/State.cpp \
scripting/js-bindings/jswrapper/v8-12.x/Class.cpp \
scripting/js-bindings/jswrapper/v8-12.x/HelperMacros.cpp \
scripting/js-bindings/jswrapper/v8-12.x/Object.cpp \
scripting/js-bindings/jswrapper/v8-12.x/ObjectWrap.cpp \
scripting/js-bindings/jswrapper/v8-12.x/ScriptEngine.cpp \
scripting/js-bindings/jswrapper/v8-12.x/Utils.cpp \
scripting/js-bindings/jswrapper/v8-12.x/WebWorker.cpp \
scripting/js-bindings/event/EventDispatcher.cpp \
../external/sources/xxtea/xxtea.cpp \
../external/sources/tinyxml2/tinyxml2.cpp \
../external/sources/unzip/ioapi_mem.cpp \
../external/sources/unzip/ioapi.cpp \
../external/sources/unzip/unzip.cpp \
../external/sources/ConvertUTF/ConvertUTFWrapper.cpp \
../external/sources/ConvertUTF/ConvertUTF.c \
../external/sources/edtaa3func/edtaa3func.cpp \
../external/sources/edtaa3func/edtaa3func.h \
ui/edit-box/EditBox-android.cpp \
2d/CCFontAtlas.cpp \
2d/CCFontFreetype.cpp \
2d/CCLabelLayout.cpp \
2d/CCTTFLabelAtlasCache.cpp \
2d/CCTTFLabelRenderer.cpp \
2d/CCTTFTypes.cpp

ifeq ($(USE_V8_DEBUGGER), 1)
# v8 debugger source files, always enable it
LOCAL_SRC_FILES += \
scripting/js-bindings/jswrapper/v8-12.x/debugger/SHA1.cpp \
scripting/js-bindings/jswrapper/v8-12.x/debugger/util.cc \
scripting/js-bindings/jswrapper/v8-12.x/debugger/env.cc \
scripting/js-bindings/jswrapper/v8-12.x/debugger/inspector_agent.cc \
scripting/js-bindings/jswrapper/v8-12.x/debugger/inspector_io.cc \
scripting/js-bindings/jswrapper/v8-12.x/debugger/inspector_socket.cc \
scripting/js-bindings/jswrapper/v8-12.x/debugger/inspector_socket_server.cc \
scripting/js-bindings/jswrapper/v8-12.x/debugger/node.cc \
scripting/js-bindings/jswrapper/v8-12.x/debugger/node_debug_options.cc \
scripting/js-bindings/jswrapper/v8-12.x/debugger/http_parser.c
# uv_static only used in v8 debugger
LOCAL_STATIC_LIBRARIES += v8_inspector
endif

LOCAL_STATIC_LIBRARIES += uv_static
LOCAL_STATIC_LIBRARIES += cocos_extension_static

# opengl bindings depend on GFXUtils "_JSB_GL_CHECK"
LOCAL_SRC_FILES += \
renderer/gfx/GFXUtils.cpp

ifeq ($(USE_GFX_RENDERER),1)
LOCAL_SRC_FILES += \
renderer/Types.cpp \
renderer/gfx/DeviceGraphics.cpp \
renderer/gfx/FrameBuffer.cpp \
renderer/gfx/GFX.cpp \
renderer/gfx/GraphicsHandle.cpp \
renderer/gfx/IndexBuffer.cpp \
renderer/gfx/Program.cpp \
renderer/gfx/RenderBuffer.cpp \
renderer/gfx/RenderTarget.cpp \
renderer/gfx/State.cpp \
renderer/gfx/Texture.cpp \
renderer/gfx/Texture2D.cpp \
renderer/gfx/VertexBuffer.cpp \
renderer/gfx/VertexFormat.cpp \
renderer/renderer/BaseRenderer.cpp \
renderer/renderer/Camera.cpp \
renderer/renderer/Config.cpp \
renderer/renderer/Effect.cpp \
renderer/renderer/InputAssembler.cpp \
renderer/renderer/Light.cpp \
renderer/renderer/Model.cpp \
renderer/renderer/Pass.cpp \
renderer/renderer/ProgramLib.cpp \
renderer/renderer/Scene.cpp \
renderer/renderer/Technique.cpp \
renderer/renderer/View.cpp \
renderer/renderer/ForwardRenderer.cpp \
renderer/scene/assembler/Assembler.cpp \
renderer/scene/assembler/AssemblerBase.cpp \
renderer/scene/assembler/CustomAssembler.cpp \
renderer/scene/assembler/MaskAssembler.cpp \
renderer/scene/assembler/RenderData.cpp \
renderer/scene/assembler/RenderDataList.cpp \
renderer/scene/assembler/TiledMapAssembler.cpp \
renderer/scene/assembler/AssemblerSprite.cpp \
renderer/scene/assembler/SimpleSprite2D.cpp \
renderer/scene/assembler/SlicedSprite2D.cpp \
renderer/scene/assembler/SimpleSprite3D.cpp \
renderer/scene/assembler/SlicedSprite3D.cpp \
renderer/scene/assembler/MeshAssembler.cpp \
renderer/scene/assembler/Particle3DAssembler.cpp \
renderer/scene/MeshBuffer.cpp \
renderer/scene/ModelBatcher.cpp \
renderer/scene/NodeProxy.cpp \
renderer/scene/RenderFlow.cpp \
renderer/scene/StencilManager.cpp \
renderer/scene/MemPool.cpp \
renderer/scene/NodeMemPool.cpp \
renderer/scene/ParallelTask.cpp \
renderer/memop/RecyclePool.hpp \
renderer/renderer/EffectVariant.cpp \
renderer/renderer/EffectBase.cpp \
scripting/js-bindings/auto/jsb_gfx_auto.cpp \
scripting/js-bindings/auto/jsb_renderer_auto.cpp \
scripting/js-bindings/manual/jsb_renderer_manual.cpp \
scripting/js-bindings/manual/jsb_gfx_manual.cpp
endif # USE_GFX_RENDERER

ifeq ($(USE_VIDEO),1)
LOCAL_SRC_FILES += \
ui/videoplayer/VideoPlayer-android.cpp \
scripting/js-bindings/auto/jsb_video_auto.cpp
endif # USE_VIDEO

ifeq ($(USE_WEB_VIEW),1)
LOCAL_SRC_FILES += \
ui/webview/WebViewImpl-android.cpp \
scripting/js-bindings/auto/jsb_webview_auto.cpp
endif # USE_WEB_VIEW

ifeq ($(USE_AUDIO),1)
LOCAL_SRC_FILES += \
scripting/js-bindings/auto/jsb_cocos2dx_audioengine_auto.cpp
LOCAL_STATIC_LIBRARIES += audioengine_static
endif # USE_AUDIO

ifeq ($(USE_SOCKET),1)
LOCAL_SRC_FILES += \
network/SocketIO.cpp \
network/WebSocket-libwebsockets.cpp \
network/WebSocketServer.cpp \
scripting/js-bindings/manual/jsb_socketio.cpp \
scripting/js-bindings/manual/jsb_websocket.cpp \
scripting/js-bindings/manual/jsb_websocket_server.cpp

LOCAL_STATIC_LIBRARIES += libwebsockets_static
LOCAL_STATIC_LIBRARIES += cocos_ssl_static
LOCAL_STATIC_LIBRARIES += cocos_crypto_static
LOCAL_STATIC_LIBRARIES += uv_static
endif # USE_SOCKET

ifneq ($(USE_MIDDLEWARE),0)
LOCAL_STATIC_LIBRARIES += editor_support_static
endif # USE_MIDDLEWARE

LOCAL_C_INCLUDES := $(LOCAL_PATH) \
                    $(LOCAL_PATH)/.. \
                    $(LOCAL_PATH)/platform \
                    $(LOCAL_PATH)/editor-support \
                    $(LOCAL_PATH)/../external/android/$(TARGET_ARCH_ABI)/include \
                    $(LOCAL_PATH)/../external/sources \
                    $(LOCAL_PATH)/renderer \
                    $(LOCAL_PATH)/scripting/js-bindings/manual \
                    $(LOCAL_PATH)/scripting/js-bindings/manual/platform/android \
                    $(LOCAL_PATH)/scripting/js-bindings/auto \
                    $(LOCAL_PATH)/renderer/gfx

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH) \
                    $(LOCAL_PATH)/.. \
                    $(LOCAL_PATH)/platform \
                    $(LOCAL_PATH)/base \
                    $(LOCAL_PATH)/network \
                    $(LOCAL_PATH)/../external/android/$(TARGET_ARCH_ABI)/include \
                    $(LOCAL_PATH)/../external/sources \
                    $(LOCAL_PATH)/renderer

ifneq ($(USE_WUFFS), 1)
LOCAL_STATIC_LIBRARIES += cocos_png_static
LOCAL_STATIC_LIBRARIES += cocos_jpeg_static
else
  ifneq (${REMOVE_IMAGE_ENCODER}, 1)
  LOCAL_STATIC_LIBRARIES += cocos_png_static
  LOCAL_STATIC_LIBRARIES += cocos_jpeg_static
  endif
endif

ifeq ($(USE_TIFF),1)
LOCAL_STATIC_LIBRARIES += cocos_tiff_static
endif

LOCAL_STATIC_LIBRARIES += cocos_webp_static
LOCAL_STATIC_LIBRARIES += cocos_zlib_static
LOCAL_STATIC_LIBRARIES += v8_static
LOCAL_STATIC_LIBRARIES += cocos_freetype_static
LOCAL_STATIC_LIBRARIES += cocos_worker_encdec

ifeq ($(USE_TFLITE), 1)
LOCAL_STATIC_LIBRARIES += XNNPACK
LOCAL_STATIC_LIBRARIES += cpuinfo
LOCAL_STATIC_LIBRARIES += eight_bit_int_gemm
LOCAL_STATIC_LIBRARIES += fft2d_fftsg
LOCAL_STATIC_LIBRARIES += fft2d_fftsg2d
LOCAL_STATIC_LIBRARIES += flatbuffers
LOCAL_STATIC_LIBRARIES += pthreadpool
LOCAL_STATIC_LIBRARIES += ruy_allocator
LOCAL_STATIC_LIBRARIES += ruy_apply_multiplier
LOCAL_STATIC_LIBRARIES += ruy_block_map
LOCAL_STATIC_LIBRARIES += ruy_blocking_counter
LOCAL_STATIC_LIBRARIES += ruy_context
LOCAL_STATIC_LIBRARIES += ruy_context_get_ctx
LOCAL_STATIC_LIBRARIES += ruy_cpuinfo
LOCAL_STATIC_LIBRARIES += ruy_ctx
LOCAL_STATIC_LIBRARIES += ruy_denormal
LOCAL_STATIC_LIBRARIES += ruy_frontend
LOCAL_STATIC_LIBRARIES += ruy_have_built_path_for_avx
LOCAL_STATIC_LIBRARIES += ruy_have_built_path_for_avx2_fma
LOCAL_STATIC_LIBRARIES += ruy_have_built_path_for_avx512
LOCAL_STATIC_LIBRARIES += ruy_kernel_arm
LOCAL_STATIC_LIBRARIES += ruy_kernel_avx
LOCAL_STATIC_LIBRARIES += ruy_kernel_avx2_fma
LOCAL_STATIC_LIBRARIES += ruy_kernel_avx512
LOCAL_STATIC_LIBRARIES += ruy_pack_arm
LOCAL_STATIC_LIBRARIES += ruy_pack_avx
LOCAL_STATIC_LIBRARIES += ruy_pack_avx2_fma
LOCAL_STATIC_LIBRARIES += ruy_pack_avx512
LOCAL_STATIC_LIBRARIES += ruy_prepacked_cache
LOCAL_STATIC_LIBRARIES += ruy_prepare_packed_matrices
LOCAL_STATIC_LIBRARIES += ruy_profiler_instrumentation
LOCAL_STATIC_LIBRARIES += ruy_profiler_profiler
LOCAL_STATIC_LIBRARIES += ruy_system_aligned_alloc
LOCAL_STATIC_LIBRARIES += ruy_thread_pool
LOCAL_STATIC_LIBRARIES += ruy_trmul
LOCAL_STATIC_LIBRARIES += ruy_tune
LOCAL_STATIC_LIBRARIES += ruy_wait
LOCAL_STATIC_LIBRARIES += farmhash
LOCAL_STATIC_LIBRARIES += tensorflow-lite
LOCAL_STATIC_LIBRARIES += tfwrapper
endif


ifeq ($(USE_NCNN), 1)
LOCAL_STATIC_LIBRARIES += GenericCodeGen
LOCAL_STATIC_LIBRARIES += glsl-default-resource-limits
LOCAL_STATIC_LIBRARIES += MachineIndependent
LOCAL_STATIC_LIBRARIES += ncnn
LOCAL_STATIC_LIBRARIES += OGLCompiler
LOCAL_STATIC_LIBRARIES += OSDependent
LOCAL_STATIC_LIBRARIES += SPIRV

LOCAL_SRC_FILES += scripting/js-bindings/manual/jsb_ncnn.cpp

endif
LOCAL_STATIC_LIBRARIES += texdec
LOCAL_STATIC_LIBRARIES += zstd

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dxandroid_static
LOCAL_WHOLE_STATIC_LIBRARIES += cpufeatures 

# define the macro to compile through support/zip_support/ioapi.c
LOCAL_CFLAGS += -DUSE_FILE32API -fexceptions -fvisibility=hidden -ffunction-sections -fdata-sections

# Issues #9968
#ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
#    LOCAL_CFLAGS += -DHAVE_NEON=1
#endif

# enable enoki 
ifeq ($(TARGET_ARCH),arm)
    LOCAL_CFLAGS += -mfpu=neon-fp16
    LOCAL_CPPFLAGS += -mfpu=neon-fp16
endif


LOCAL_CPPFLAGS += -Wno-deprecated-declarations -fvisibility=hidden -ffunction-sections -fdata-sections
LOCAL_EXPORT_CFLAGS   := -DUSE_FILE32API
LOCAL_EXPORT_CPPFLAGS := -Wno-deprecated-declarations

include $(BUILD_STATIC_LIBRARY)


#==============================================================
#$(call import-module,.)
$(call import-module,android)
$(call import-module,editor-support)
$(call import-module,platform/android)
$(call import-module,audio/android)
$(call import-module,extensions)
$(call import-module,android/cpufeatures)
