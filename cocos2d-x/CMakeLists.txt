

set(CWD ${CMAKE_CURRENT_LIST_DIR})

set(COCOS_SRC_LIST)

list(APPEND COCOS_SRC_LIST
    ${CWD}/cocos/cocos2d.cpp
    ${CWD}/cocos/platform/CCFileUtils.cpp
    ${CWD}/cocos/platform/CCImage.cpp
    ${CWD}/cocos/platform/CCTimer.cpp
    ${CWD}/cocos/platform/CCSAXParser.cpp
    ${CWD}/cocos/platform/CountdownTrigger.cpp
    ${CWD}/cocos/math/CCGeometry.cpp
    ${CWD}/cocos/math/CCVertex.cpp
    ${CWD}/cocos/math/Mat4.cpp
    ${CWD}/cocos/math/Quaternion.cpp
    ${CWD}/cocos/math/Vec2.cpp
    ${CWD}/cocos/math/Vec3.cpp
    ${CWD}/cocos/math/Vec4.cpp
    ${CWD}/cocos/math/Mat3.cpp
    ${CWD}/cocos/math/MathUtil.cpp
    ${CWD}/cocos/base/CCAutoreleasePool.cpp
    ${CWD}/cocos/base/CCConfiguration.cpp
    ${CWD}/cocos/base/CCData.cpp
    ${CWD}/cocos/base/CCRef.cpp
    ${CWD}/cocos/base/CCValue.cpp
    ${CWD}/cocos/base/CCThreadPool.cpp
    ${CWD}/cocos/base/TGAlib.cpp
    ${CWD}/cocos/base/ZipUtils.cpp
    ${CWD}/cocos/base/base64.cpp
    ${CWD}/cocos/base/ccCArray.cpp
    ${CWD}/cocos/base/ccRandom.cpp
    ${CWD}/cocos/base/ccTypes.cpp
    ${CWD}/cocos/base/ccUTF8.cpp
    ${CWD}/cocos/base/ccUtils.cpp
    ${CWD}/cocos/base/astc.cpp
    ${CWD}/cocos/base/etc1.cpp
    ${CWD}/cocos/base/etc2.cpp
    ${CWD}/cocos/base/pvr.cpp
    ${CWD}/cocos/base/CCLog.cpp
    ${CWD}/cocos/base/csscolorparser.cpp
    ${CWD}/cocos/base/CCGLUtils.cpp
    ${CWD}/cocos/base/CCRenderTexture.cpp
    ${CWD}/cocos/base/resdec.cpp
    ${CWD}/cocos/storage/local-storage/LocalStorage-android.cpp
    ${CWD}/cocos/network/CCDownloader.cpp
    ${CWD}/cocos/network/CCDownloader-android.cpp
    ${CWD}/cocos/network/Uri.cpp
    ${CWD}/cocos/network/HttpClient-android.cpp
    ${CWD}/cocos/scripting/js-bindings/auto/jsb_cocos2dx_auto.cpp
    ${CWD}/cocos/scripting/js-bindings/auto/jsb_cocos2dx_extension_auto.cpp
    ${CWD}/cocos/scripting/js-bindings/auto/jsb_cocos2dx_network_auto.cpp
    ${CWD}/cocos/scripting/js-bindings/manual/JavaScriptJavaBridge.cpp
    ${CWD}/cocos/scripting/js-bindings/manual/jsb_opengl_manual.cpp
    ${CWD}/cocos/scripting/js-bindings/manual/jsb_opengl_utils.cpp
    ${CWD}/cocos/scripting/js-bindings/manual/jsb_classtype.cpp
    ${CWD}/cocos/scripting/js-bindings/manual/jsb_conversions.cpp
    ${CWD}/cocos/scripting/js-bindings/manual/jsb_cocos2dx_manual.cpp
    ${CWD}/cocos/scripting/js-bindings/manual/jsb_global.cpp
    ${CWD}/cocos/scripting/js-bindings/manual/jsb_xmlhttprequest.cpp
    ${CWD}/cocos/scripting/js-bindings/manual/jsb_cocos2dx_network_manual.cpp
    ${CWD}/cocos/scripting/js-bindings/manual/jsb_platform_android.cpp
    ${CWD}/cocos/scripting/js-bindings/manual/jsb_worker_manual.cpp
    ${CWD}/cocos/scripting/js-bindings/jswrapper/config.cpp
    ${CWD}/cocos/scripting/js-bindings/jswrapper/ValueArrayPool.cpp
    ${CWD}/cocos/scripting/js-bindings/jswrapper/HandleObject.cpp
    ${CWD}/cocos/scripting/js-bindings/jswrapper/MappingUtils.cpp
    ${CWD}/cocos/scripting/js-bindings/jswrapper/RefCounter.cpp
    ${CWD}/cocos/scripting/js-bindings/jswrapper/Value.cpp
    ${CWD}/cocos/scripting/js-bindings/jswrapper/State.cpp
    ${CWD}/cocos/scripting/js-bindings/jswrapper/v8-12.x/Class.cpp
    ${CWD}/cocos/scripting/js-bindings/jswrapper/v8-12.x/HelperMacros.cpp
    ${CWD}/cocos/scripting/js-bindings/jswrapper/v8-12.x/Object.cpp
    ${CWD}/cocos/scripting/js-bindings/jswrapper/v8-12.x/ObjectWrap.cpp
    ${CWD}/cocos/scripting/js-bindings/jswrapper/v8-12.x/ScriptEngine.cpp
    ${CWD}/cocos/scripting/js-bindings/jswrapper/v8-12.x/Utils.cpp
    ${CWD}/cocos/scripting/js-bindings/jswrapper/v8-12.x/WebWorker.cpp
    ${CWD}/cocos/scripting/js-bindings/event/EventDispatcher.cpp
    ${CWD}/external/sources/xxtea/xxtea.cpp
    ${CWD}/external/sources/tinyxml2/tinyxml2.cpp
    ${CWD}/external/sources/unzip/ioapi_mem.cpp
    ${CWD}/external/sources/unzip/ioapi.cpp
    ${CWD}/external/sources/unzip/unzip.cpp
    ${CWD}/external/sources/ConvertUTF/ConvertUTFWrapper.cpp
    ${CWD}/external/sources/ConvertUTF/ConvertUTF.c
    ${CWD}/external/sources/edtaa3func/edtaa3func.cpp
    ${CWD}/external/sources/edtaa3func/edtaa3func.h
    ${CWD}/cocos/ui/edit-box/EditBox-android.cpp
    ${CWD}/cocos/2d/CCFontAtlas.cpp
    ${CWD}/cocos/2d/CCFontFreetype.cpp
    ${CWD}/cocos/2d/CCLabelLayout.cpp
    ${CWD}/cocos/2d/CCTTFLabelAtlasCache.cpp
    ${CWD}/cocos/2d/CCTTFLabelRenderer.cpp
    ${CWD}/cocos/2d/CCTTFTypes.cpp
)

if(USE_V8_DEBUGGER)
    list(APPEND COCOS_SRC_LIST
        ${CWD}/cocos/scripting/js-bindings/jswrapper/v8-12.x/debugger/SHA1.cpp
        ${CWD}/cocos/scripting/js-bindings/jswrapper/v8-12.x/debugger/util.cc
        ${CWD}/cocos/scripting/js-bindings/jswrapper/v8-12.x/debugger/env.cc
        ${CWD}/cocos/scripting/js-bindings/jswrapper/v8-12.x/debugger/inspector_agent.cc
        ${CWD}/cocos/scripting/js-bindings/jswrapper/v8-12.x/debugger/inspector_io.cc
        ${CWD}/cocos/scripting/js-bindings/jswrapper/v8-12.x/debugger/inspector_socket.cc
        ${CWD}/cocos/scripting/js-bindings/jswrapper/v8-12.x/debugger/inspector_socket_server.cc
        ${CWD}/cocos/scripting/js-bindings/jswrapper/v8-12.x/debugger/node.cc
        ${CWD}/cocos/scripting/js-bindings/jswrapper/v8-12.x/debugger/node_debug_options.cc
        ${CWD}/cocos/scripting/js-bindings/jswrapper/v8-12.x/debugger/http_parser.c
    )
endif()


if(USE_GFX_RENDERER)
    list(APPEND COCOS_SRC_LIST
        ${CWD}/cocos/renderer/Types.cpp
        ${CWD}/cocos/renderer/gfx/DeviceGraphics.cpp
        ${CWD}/cocos/renderer/gfx/FrameBuffer.cpp
        ${CWD}/cocos/renderer/gfx/GFX.cpp
        ${CWD}/cocos/renderer/gfx/GraphicsHandle.cpp
        ${CWD}/cocos/renderer/gfx/IndexBuffer.cpp
        ${CWD}/cocos/renderer/gfx/Program.cpp
        ${CWD}/cocos/renderer/gfx/RenderBuffer.cpp
        ${CWD}/cocos/renderer/gfx/RenderTarget.cpp
        ${CWD}/cocos/renderer/gfx/State.cpp
        ${CWD}/cocos/renderer/gfx/Texture.cpp
        ${CWD}/cocos/renderer/gfx/Texture2D.cpp
        ${CWD}/cocos/renderer/gfx/VertexBuffer.cpp
        ${CWD}/cocos/renderer/gfx/VertexFormat.cpp
        ${CWD}/cocos/renderer/renderer/BaseRenderer.cpp
        ${CWD}/cocos/renderer/renderer/Camera.cpp
        ${CWD}/cocos/renderer/renderer/Config.cpp
        ${CWD}/cocos/renderer/renderer/Effect.cpp
        ${CWD}/cocos/renderer/renderer/InputAssembler.cpp
        ${CWD}/cocos/renderer/renderer/Light.cpp
        ${CWD}/cocos/renderer/renderer/Model.cpp
        ${CWD}/cocos/renderer/renderer/Pass.cpp
        ${CWD}/cocos/renderer/renderer/ProgramLib.cpp
        ${CWD}/cocos/renderer/renderer/Scene.cpp
        ${CWD}/cocos/renderer/renderer/Technique.cpp
        ${CWD}/cocos/renderer/renderer/View.cpp
        ${CWD}/cocos/renderer/renderer/ForwardRenderer.cpp
        ${CWD}/cocos/renderer/scene/assembler/Assembler.cpp
        ${CWD}/cocos/renderer/scene/assembler/AssemblerBase.cpp
        ${CWD}/cocos/renderer/scene/assembler/CustomAssembler.cpp
        ${CWD}/cocos/renderer/scene/assembler/MaskAssembler.cpp
        ${CWD}/cocos/renderer/scene/assembler/RenderData.cpp
        ${CWD}/cocos/renderer/scene/assembler/RenderDataList.cpp
        ${CWD}/cocos/renderer/scene/assembler/TiledMapAssembler.cpp
        ${CWD}/cocos/renderer/scene/assembler/AssemblerSprite.cpp
        ${CWD}/cocos/renderer/scene/assembler/SimpleSprite2D.cpp
        ${CWD}/cocos/renderer/scene/assembler/SlicedSprite2D.cpp
        ${CWD}/cocos/renderer/scene/assembler/SimpleSprite3D.cpp
        ${CWD}/cocos/renderer/scene/assembler/SlicedSprite3D.cpp
        ${CWD}/cocos/renderer/scene/assembler/MeshAssembler.cpp
        ${CWD}/cocos/renderer/scene/assembler/Particle3DAssembler.cpp
        ${CWD}/cocos/renderer/scene/MeshBuffer.cpp
        ${CWD}/cocos/renderer/scene/ModelBatcher.cpp
        ${CWD}/cocos/renderer/scene/NodeProxy.cpp
        ${CWD}/cocos/renderer/scene/RenderFlow.cpp
        ${CWD}/cocos/renderer/scene/StencilManager.cpp
        ${CWD}/cocos/renderer/scene/MemPool.cpp
        ${CWD}/cocos/renderer/scene/NodeMemPool.cpp
        ${CWD}/cocos/renderer/scene/ParallelTask.cpp
        ${CWD}/cocos/renderer/memop/RecyclePool.hpp
        ${CWD}/cocos/renderer/renderer/EffectVariant.cpp
        ${CWD}/cocos/renderer/renderer/EffectBase.cpp
        ${CWD}/cocos/scripting/js-bindings/auto/jsb_gfx_auto.cpp
        ${CWD}/cocos/scripting/js-bindings/auto/jsb_renderer_auto.cpp
        ${CWD}/cocos/scripting/js-bindings/manual/jsb_renderer_manual.cpp
        ${CWD}/cocos/scripting/js-bindings/manual/jsb_gfx_manual.cpp
        ${CWD}/cocos/renderer/gfx/GFXUtils.cpp
    )
endif()


if(USE_VIDEO)
    list(APPEND COCOS_SRC_LIST
        ${CWD}/cocos/ui/videoplayer/VideoPlayer-android.cpp
        ${CWD}/cocos/scripting/js-bindings/auto/jsb_video_auto.cpp
    )
endif()

if(USE_WEB_VIEW)
    list(APPEND COCOS_SRC_LIST
        ${CWD}/cocos/ui/webview/WebViewImpl-android.cpp
        ${CWD}/cocos/scripting/js-bindings/auto/jsb_webview_auto.cpp
    )
endif()

if(USE_AUDIO)
    list(APPEND COCOS_SRC_LIST
        ${CWD}/cocos/scripting/js-bindings/auto/jsb_cocos2dx_audioengine_auto.cpp
    )
endif()

if(USE_SOCKET)
    list(APPEND COCOS_SRC_LIST
        ${CWD}/cocos/network/SocketIO.cpp
        ${CWD}/cocos/network/WebSocket-libwebsockets.cpp
        ${CWD}/cocos/network/WebSocketServer.cpp
        ${CWD}/cocos/scripting/js-bindings/manual/jsb_socketio.cpp
        ${CWD}/cocos/scripting/js-bindings/manual/jsb_websocket.cpp
        ${CWD}/cocos/scripting/js-bindings/manual/jsb_websocket_server.cpp
    )
endif()


add_library(libcocos2d STATIC
    ${COCOS_SRC_LIST}
)