LOCAL_PATH := $(call my-dir)
#======================================
include $(CLEAR_VARS)

LOCAL_MODULE := cocos_zlib_static
LOCAL_MODULE_FILENAME := zlib
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libz.a

include $(PREBUILT_STATIC_LIBRARY)

#======================================
include $(CLEAR_VARS)

LOCAL_MODULE := cocos_jpeg_static
LOCAL_MODULE_FILENAME := jpeg
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libjpeg.a

include $(PREBUILT_STATIC_LIBRARY)

#======================================
include $(CLEAR_VARS)

LOCAL_MODULE := cocos_png_static
LOCAL_MODULE_FILENAME := png
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libpng.a

include $(PREBUILT_STATIC_LIBRARY)

#======================================
include $(CLEAR_VARS)

ifeq ($(USE_TIFF),1)
LOCAL_MODULE := cocos_tiff_static
LOCAL_MODULE_FILENAME := tiff
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libtiff.a
include $(PREBUILT_STATIC_LIBRARY)
endif

#======================================
include $(CLEAR_VARS)

LOCAL_MODULE := cocos_webp_static
LOCAL_MODULE_FILENAME := webp
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libwebp.a

LOCAL_WHOLE_STATIC_LIBRARIES := cpufeatures

ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
   LOCAL_CFLAGS := -DHAVE_NEON=1
endif

include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos_crypto_static
LOCAL_MODULE_FILENAME := crypto
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libcrypto.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/$(TARGET_ARCH_ABI)/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := cocos_ssl_static
LOCAL_MODULE_FILENAME := ssl
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libssl.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/$(TARGET_ARCH_ABI)/include
include $(PREBUILT_STATIC_LIBRARY)

#======================================
include $(CLEAR_VARS)

LOCAL_MODULE := websockets_static
LOCAL_MODULE_FILENAME := libwebsockets_static
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libwebsockets.a

LOCAL_CPPFLAGS := -D__STDC_LIMIT_MACROS=1
LOCAL_EXPORT_CPPFLAGS := -D__STDC_LIMIT_MACROS=1

include $(PREBUILT_STATIC_LIBRARY)

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := v8_inspector
ifeq ($(TARGET_ARCH),arm64)
   # LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/v8-debug/libinspector.a
   LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/v8/libinspector.a
else
   LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/v8/libinspector.a
endif
include $(PREBUILT_STATIC_LIBRARY)

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := v8_static
ifeq ($(TARGET_ARCH),arm64)
   # LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/v8-debug/libv8_monolith.a
   LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/v8/libv8_monolith.a
else
   LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/v8/libv8_monolith.a
endif
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/$(TARGET_ARCH_ABI)/include/v8

ifeq ($(TARGET_ARCH),arm64)
   LOCAL_EXPORT_CPPFLAGS := \
 -DV8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64 \
 -DOBJECT_PRINT \
 -DVERIFY_HEAP \
 -DV8_TRACE_MAPS \
 -DV8_ENABLE_ALLOCATION_TIMEOUT \
 -DV8_ENABLE_FORCE_SLOW_PATH \
 -DV8_ENABLE_DOUBLE_CONST_STORE_CHECK \
 -DENABLE_HANDLE_ZAPPING \
 -DV8_CODE_COMMENTS \
 -DV8_ENABLE_DEBUG_CODE \
 -DV8_ENABLE_HEAP_SNAPSHOT_VERIFY \
 -DV8_SNAPSHOT_NATIVE_CODE_COUNTERS \
 -DV8_ATOMIC_OBJECT_FIELD_WRITES \
 -DV8_ENABLE_LAZY_SOURCE_POSITIONS \
 -DV8_SHARED_RO_HEAP \
 -DV8_WIN64_UNWINDING_INFO \
 -DV8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH \
 -DV8_SNAPSHOT_COMPRESSION \
 -DV8_ENABLE_CONTROL_FLOW_INTEGRITY \
 -DV8_SHORT_BUILTIN_CALLS \
 -DV8_EXTERNAL_CODE_SPACE \
 -DV8_ENABLE_SPARKPLUG \
 -DV8_ENABLE_MAGLEV \
 -DV8_ENABLE_TURBOFAN \
 -DV8_ENABLE_WEBASSEMBLY \
 -DV8_ALLOCATION_FOLDING \
 -DV8_ALLOCATION_SITE_TRACKING \
 -DV8_USE_ZLIB \
 -DV8_USE_LIBM_TRIG_FUNCTIONS \
 -DV8_ENABLE_MAGLEV_GRAPH_PRINTER \
 -DV8_ENABLE_SLOW_TRACING \
 -DV8_ENABLE_EXTENSIBLE_RO_SNAPSHOT \
 -DV8_COMPRESS_POINTERS \
 -DV8_COMPRESS_POINTERS_IN_SHARED_CAGE \
 -DV8_31BIT_SMIS_ON_64BIT_ARCH \
 -DV8_DEPRECATION_WARNINGS \
 -DV8_IMMINENT_DEPRECATION_WARNINGS \
 -DCPPGC_CAGED_HEAP \
 -DCPPGC_YOUNG_GENERATION \
 -DCPPGC_POINTER_COMPRESSION \
 -DCPPGC_SLIM_WRITE_BARRIER \
 -DV8_TARGET_ARCH_ARM64 \
 -DV8_HAVE_TARGET_OS \
 -DV8_TARGET_OS_ANDROID 

 #-DV8_ENABLE_CHECKS \

LOCAL_EXPORT_CFLAGS := \
 -DV8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64 \
 -DOBJECT_PRINT \
 -DVERIFY_HEAP \
 -DV8_TRACE_MAPS \
 -DV8_ENABLE_ALLOCATION_TIMEOUT \
 -DV8_ENABLE_FORCE_SLOW_PATH \
 -DV8_ENABLE_DOUBLE_CONST_STORE_CHECK \
 -DENABLE_HANDLE_ZAPPING \
 -DV8_CODE_COMMENTS \
 -DV8_ENABLE_DEBUG_CODE \
 -DV8_ENABLE_HEAP_SNAPSHOT_VERIFY \
 -DV8_SNAPSHOT_NATIVE_CODE_COUNTERS \
 -DV8_ATOMIC_OBJECT_FIELD_WRITES \
 -DV8_ENABLE_LAZY_SOURCE_POSITIONS \
 -DV8_SHARED_RO_HEAP \
 -DV8_WIN64_UNWINDING_INFO \
 -DV8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH \
 -DV8_SNAPSHOT_COMPRESSION \
 -DV8_ENABLE_CONTROL_FLOW_INTEGRITY \
 -DV8_SHORT_BUILTIN_CALLS \
 -DV8_EXTERNAL_CODE_SPACE \
 -DV8_ENABLE_SPARKPLUG \
 -DV8_ENABLE_MAGLEV \
 -DV8_ENABLE_TURBOFAN \
 -DV8_ENABLE_WEBASSEMBLY \
 -DV8_ALLOCATION_FOLDING \
 -DV8_ALLOCATION_SITE_TRACKING \
 -DV8_USE_ZLIB \
 -DV8_USE_LIBM_TRIG_FUNCTIONS \
 -DV8_ENABLE_MAGLEV_GRAPH_PRINTER \
 -DV8_ENABLE_SLOW_TRACING \
 -DV8_ENABLE_EXTENSIBLE_RO_SNAPSHOT \
 -DV8_COMPRESS_POINTERS \
 -DV8_COMPRESS_POINTERS_IN_SHARED_CAGE \
 -DV8_31BIT_SMIS_ON_64BIT_ARCH \
 -DV8_DEPRECATION_WARNINGS \
 -DV8_IMMINENT_DEPRECATION_WARNINGS \
 -DCPPGC_CAGED_HEAP \
 -DCPPGC_YOUNG_GENERATION \
 -DCPPGC_POINTER_COMPRESSION \
 -DCPPGC_SLIM_WRITE_BARRIER \
 -DV8_TARGET_ARCH_ARM64 \
 -DV8_HAVE_TARGET_OS \
 -DV8_TARGET_OS_ANDROID 

# -DV8_ENABLE_CHECKS \

endif

ifeq ($(TARGET_ARCH),x86_64)
 LOCAL_EXPORT_CPPFLAGS := \
 -DV8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64 \
 -DOBJECT_PRINT \
 -DVERIFY_HEAP \
 -DV8_TRACE_MAPS \
 -DV8_ENABLE_ALLOCATION_TIMEOUT \
 -DV8_ENABLE_FORCE_SLOW_PATH \
 -DV8_ENABLE_DOUBLE_CONST_STORE_CHECK \
 -DENABLE_HANDLE_ZAPPING \
 -DV8_CODE_COMMENTS \
 -DV8_ENABLE_DEBUG_CODE \
 -DV8_ENABLE_HEAP_SNAPSHOT_VERIFY \
 -DV8_SNAPSHOT_NATIVE_CODE_COUNTERS \
 -DV8_ATOMIC_OBJECT_FIELD_WRITES \
 -DV8_ENABLE_LAZY_SOURCE_POSITIONS \
 -DV8_SHARED_RO_HEAP \
 -DV8_WIN64_UNWINDING_INFO \
 -DV8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH \
 -DV8_SNAPSHOT_COMPRESSION \
 -DV8_ENABLE_CONTROL_FLOW_INTEGRITY \
 -DV8_SHORT_BUILTIN_CALLS \
 -DV8_EXTERNAL_CODE_SPACE \
 -DV8_ENABLE_SPARKPLUG \
 -DV8_ENABLE_MAGLEV \
 -DV8_ENABLE_TURBOFAN \
 -DV8_ENABLE_WEBASSEMBLY \
 -DV8_ALLOCATION_FOLDING \
 -DV8_ALLOCATION_SITE_TRACKING \
 -DV8_USE_ZLIB \
 -DV8_USE_LIBM_TRIG_FUNCTIONS \
 -DV8_ENABLE_MAGLEV_GRAPH_PRINTER \
 -DV8_ENABLE_SLOW_TRACING \
 -DV8_ENABLE_EXTENSIBLE_RO_SNAPSHOT \
 -DV8_COMPRESS_POINTERS \
 -DV8_COMPRESS_POINTERS_IN_SHARED_CAGE \
 -DV8_31BIT_SMIS_ON_64BIT_ARCH \
 -DV8_DEPRECATION_WARNINGS \
 -DV8_IMMINENT_DEPRECATION_WARNINGS \
 -DCPPGC_CAGED_HEAP \
 -DCPPGC_YOUNG_GENERATION \
 -DCPPGC_POINTER_COMPRESSION \
 -DCPPGC_SLIM_WRITE_BARRIER \
 -DV8_TARGET_ARCH_ARM64 \
 -DV8_HAVE_TARGET_OS \
 -DV8_TARGET_OS_ANDROID 

LOCAL_EXPORT_CFLAGS := \
 -DV8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64 \
 -DOBJECT_PRINT \
 -DVERIFY_HEAP \
 -DV8_TRACE_MAPS \
 -DV8_ENABLE_ALLOCATION_TIMEOUT \
 -DV8_ENABLE_FORCE_SLOW_PATH \
 -DV8_ENABLE_DOUBLE_CONST_STORE_CHECK \
 -DENABLE_HANDLE_ZAPPING \
 -DV8_CODE_COMMENTS \
 -DV8_ENABLE_DEBUG_CODE \
 -DV8_ENABLE_HEAP_SNAPSHOT_VERIFY \
 -DV8_SNAPSHOT_NATIVE_CODE_COUNTERS \
 -DV8_ATOMIC_OBJECT_FIELD_WRITES \
 -DV8_ENABLE_LAZY_SOURCE_POSITIONS \
 -DV8_SHARED_RO_HEAP \
 -DV8_WIN64_UNWINDING_INFO \
 -DV8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH \
 -DV8_SNAPSHOT_COMPRESSION \
 -DV8_ENABLE_CONTROL_FLOW_INTEGRITY \
 -DV8_SHORT_BUILTIN_CALLS \
 -DV8_EXTERNAL_CODE_SPACE \
 -DV8_ENABLE_SPARKPLUG \
 -DV8_ENABLE_MAGLEV \
 -DV8_ENABLE_TURBOFAN \
 -DV8_ENABLE_WEBASSEMBLY \
 -DV8_ALLOCATION_FOLDING \
 -DV8_ALLOCATION_SITE_TRACKING \
 -DV8_USE_ZLIB \
 -DV8_USE_LIBM_TRIG_FUNCTIONS \
 -DV8_ENABLE_MAGLEV_GRAPH_PRINTER \
 -DV8_ENABLE_SLOW_TRACING \
 -DV8_ENABLE_EXTENSIBLE_RO_SNAPSHOT \
 -DV8_COMPRESS_POINTERS \
 -DV8_COMPRESS_POINTERS_IN_SHARED_CAGE \
 -DV8_31BIT_SMIS_ON_64BIT_ARCH \
 -DV8_DEPRECATION_WARNINGS \
 -DV8_IMMINENT_DEPRECATION_WARNINGS \
 -DCPPGC_CAGED_HEAP \
 -DCPPGC_YOUNG_GENERATION \
 -DCPPGC_POINTER_COMPRESSION \
 -DCPPGC_SLIM_WRITE_BARRIER \
 -DV8_TARGET_ARCH_X64 \
 -DV8_HAVE_TARGET_OS \
 -DV8_TARGET_OS_ANDROID 
endif

include $(PREBUILT_STATIC_LIBRARY)

#======================================
include $(CLEAR_VARS)

LOCAL_MODULE := uv_static
LOCAL_MODULE_FILENAME := libuv
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libuv.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/$(TARGET_ARCH_ABI)/include/uv
include $(PREBUILT_STATIC_LIBRARY)

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := cocos_freetype_static
LOCAL_MODULE_FILENAME := libfreetype
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libfreetype.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/$(TARGET_ARCH_ABI)/include/freetype
include $(PREBUILT_STATIC_LIBRARY)

#======================================
ifneq ($(TARGET_ARCH),x86_64)
   include $(CLEAR_VARS)

   LOCAL_MODULE := cocos2djni
   LOCAL_MODULE_FILENAME := libcocos2djni
   LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libcocos2djni.a
   include $(PREBUILT_STATIC_LIBRARY)
endif
# import libXNNPACK.a

# import libXNNPACK.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := XNNPACK
LOCAL_MODULE_FILENAME := XNNPACK
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libXNNPACK.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libcpuinfo.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := cpuinfo
LOCAL_MODULE_FILENAME := cpuinfo
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libcpuinfo.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libeight_bit_int_gemm.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := eight_bit_int_gemm
LOCAL_MODULE_FILENAME := eight_bit_int_gemm
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libeight_bit_int_gemm.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libfft2d_fftsg.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := fft2d_fftsg
LOCAL_MODULE_FILENAME := fft2d_fftsg
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libfft2d_fftsg.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libfft2d_fftsg2d.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := fft2d_fftsg2d
LOCAL_MODULE_FILENAME := fft2d_fftsg2d
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libfft2d_fftsg2d.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libflatbuffers.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := flatbuffers
LOCAL_MODULE_FILENAME := flatbuffers
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libflatbuffers.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libpthreadpool.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := pthreadpool
LOCAL_MODULE_FILENAME := pthreadpool
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libpthreadpool.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_allocator.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_allocator
LOCAL_MODULE_FILENAME := ruy_allocator
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_allocator.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_apply_multiplier.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_apply_multiplier
LOCAL_MODULE_FILENAME := ruy_apply_multiplier
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_apply_multiplier.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_block_map.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_block_map
LOCAL_MODULE_FILENAME := ruy_block_map
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_block_map.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_blocking_counter.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_blocking_counter
LOCAL_MODULE_FILENAME := ruy_blocking_counter
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_blocking_counter.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_context.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_context
LOCAL_MODULE_FILENAME := ruy_context
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_context.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_context_get_ctx.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_context_get_ctx
LOCAL_MODULE_FILENAME := ruy_context_get_ctx
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_context_get_ctx.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_cpuinfo.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_cpuinfo
LOCAL_MODULE_FILENAME := ruy_cpuinfo
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_cpuinfo.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_ctx.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_ctx
LOCAL_MODULE_FILENAME := ruy_ctx
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_ctx.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_denormal.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_denormal
LOCAL_MODULE_FILENAME := ruy_denormal
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_denormal.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_frontend.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_frontend
LOCAL_MODULE_FILENAME := ruy_frontend
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_frontend.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_have_built_path_for_avx.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_have_built_path_for_avx
LOCAL_MODULE_FILENAME := ruy_have_built_path_for_avx
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_have_built_path_for_avx.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_have_built_path_for_avx2_fma.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_have_built_path_for_avx2_fma
LOCAL_MODULE_FILENAME := ruy_have_built_path_for_avx2_fma
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_have_built_path_for_avx2_fma.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_have_built_path_for_avx512.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_have_built_path_for_avx512
LOCAL_MODULE_FILENAME := ruy_have_built_path_for_avx512
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_have_built_path_for_avx512.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_kernel_arm.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_kernel_arm
LOCAL_MODULE_FILENAME := ruy_kernel_arm
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_kernel_arm.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_kernel_avx.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_kernel_avx
LOCAL_MODULE_FILENAME := ruy_kernel_avx
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_kernel_avx.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_kernel_avx2_fma.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_kernel_avx2_fma
LOCAL_MODULE_FILENAME := ruy_kernel_avx2_fma
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_kernel_avx2_fma.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_kernel_avx512.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_kernel_avx512
LOCAL_MODULE_FILENAME := ruy_kernel_avx512
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_kernel_avx512.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_pack_arm.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_pack_arm
LOCAL_MODULE_FILENAME := ruy_pack_arm
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_pack_arm.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_pack_avx.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_pack_avx
LOCAL_MODULE_FILENAME := ruy_pack_avx
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_pack_avx.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_pack_avx2_fma.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_pack_avx2_fma
LOCAL_MODULE_FILENAME := ruy_pack_avx2_fma
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_pack_avx2_fma.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_pack_avx512.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_pack_avx512
LOCAL_MODULE_FILENAME := ruy_pack_avx512
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_pack_avx512.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_prepacked_cache.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_prepacked_cache
LOCAL_MODULE_FILENAME := ruy_prepacked_cache
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_prepacked_cache.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_prepare_packed_matrices.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_prepare_packed_matrices
LOCAL_MODULE_FILENAME := ruy_prepare_packed_matrices
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_prepare_packed_matrices.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_profiler_instrumentation.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_profiler_instrumentation
LOCAL_MODULE_FILENAME := ruy_profiler_instrumentation
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_profiler_instrumentation.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_profiler_profiler.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_profiler_profiler
LOCAL_MODULE_FILENAME := ruy_profiler_profiler
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_profiler_profiler.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_system_aligned_alloc.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_system_aligned_alloc
LOCAL_MODULE_FILENAME := ruy_system_aligned_alloc
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_system_aligned_alloc.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_thread_pool.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_thread_pool
LOCAL_MODULE_FILENAME := ruy_thread_pool
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_thread_pool.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libfarmhash.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := farmhash
LOCAL_MODULE_FILENAME := farmhash
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libfarmhash.a
include $(PREBUILT_STATIC_LIBRARY) 
# import libruy_trmul.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_trmul
LOCAL_MODULE_FILENAME := ruy_trmul
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_trmul.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_tune.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_tune
LOCAL_MODULE_FILENAME := ruy_tune
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_tune.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libruy_wait.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ruy_wait
LOCAL_MODULE_FILENAME := ruy_wait
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libruy_wait.a
include $(PREBUILT_STATIC_LIBRARY) 

# import libtensorflow-lite.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := tensorflow-lite
LOCAL_MODULE_FILENAME := tensorflow-lite 
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libtensorflow-lite.a
LOCAL_EXPORT_C_INCLUDES += ${TARGET_ARCH_ABI}/include/tf
include $(PREBUILT_STATIC_LIBRARY) 

# import libwrapper.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := tfwrapper
LOCAL_MODULE_FILENAME := tfwrapper
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/libwrapper.a
include $(PREBUILT_STATIC_LIBRARY) 
#======================================

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := GenericCodeGen
LOCAL_MODULE_FILENAME := GenericCodeGen
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/ncnn/libGenericCodeGen.a
include $(PREBUILT_STATIC_LIBRARY) 
#======================================

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := glsl-default-resource-limits
LOCAL_MODULE_FILENAME := glsl-default-resource-limits
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/ncnn/libglslang-default-resource-limits.a
include $(PREBUILT_STATIC_LIBRARY) 
#======================================

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := MachineIndependent
LOCAL_MODULE_FILENAME := MachineIndependent
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/ncnn/libMachineIndependent.a
include $(PREBUILT_STATIC_LIBRARY) 
#======================================

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ncnn
LOCAL_MODULE_FILENAME := ncnn
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/ncnn/libncnn.a
include $(PREBUILT_STATIC_LIBRARY) 
#======================================

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := OGLCompiler
LOCAL_MODULE_FILENAME := OGLCompiler
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/ncnn/libOGLCompiler.a
include $(PREBUILT_STATIC_LIBRARY) 
#======================================

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := OSDependent
LOCAL_MODULE_FILENAME := OSDependent
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/ncnn/libOSDependent.a
include $(PREBUILT_STATIC_LIBRARY) 
#======================================

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := SPIRV
LOCAL_MODULE_FILENAME := SPIRV
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/ncnn/libSPIRV.a
include $(PREBUILT_STATIC_LIBRARY) 
#======================================
# import libtexdec.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := texdec
LOCAL_MODULE_FILENAME := texdec
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libtexdec.a
include $(PREBUILT_STATIC_LIBRARY) 
#======================================
# import libzstd.a

#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := zstd
LOCAL_MODULE_FILENAME := zstd
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libzstd.a
include $(PREBUILT_STATIC_LIBRARY) 
#======================================
#$(call import-module,android/cpufeatures)
