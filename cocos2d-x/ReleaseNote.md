# 升级日志

### 2024-07-16

- 添加 Worker 实现
- Android/iOS 集成 tflite
- 添加运行时 GPU 压缩纹理/缓存 支持


### 2024-04-01

- iOS 平台升级v8 到 12.0.267.10
- iOS Deployment Target 提升到12.0
- iOS 移除 x64 模拟器支持

### 2024-02-18

- v8 升级至 12.0.267.10
- 升级 rapadjson 到当前最新版本
- 调整引擎编译参数，减少到处符号，减小包体
- 新增 API
  - 添加 jsb.idleFrameRate 相关接口
  - 添加 countdowntrigger 相关实现，用于监控代码执行
  - 添加 jsb.framerate 模块，用于监控运行时的游戏帧率
- 减少 MeshBuffer 的初始内存分配
- Label 相关优化
  - 减少 fillData 调用
  - Canvas JNI 命令合批
  - unMultiplyAlpha 优化
- localStorage 合批优化
- JSB 优化
  - 简化 HelperMacros 实现，减少重复代码
  - 缓存 jsb 临时参数对象，提升调用速度
  - string_view 参数优化
- 资源加密相关
  - 移除全局资源加密（xor）
  - 重新实现 Image/Script 相关的解密方法，提升效率
- 使用 wuffs 解码部分图片资源
- 在 C++ 种 dispatch 触控事件，减少调用延迟
- 减少 图片纹理在 C++ -> JS -> OpenGL 的内存拷贝。
- 提速 node transform 的计算过程
- 部分热点函数使用 enoki 实现
- 添加 ASAN variant 到 工程模版，方便测试。
