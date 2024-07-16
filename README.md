# Cocos Creator 定制引擎

基于 Cocos 官方引擎 [2.4.11](https://github.com/cocos/engine-native/tree/v2.4.11) 版本改造。

## 主要目标

- 提升性能
- 提升易用性

[新增接口说明](./cocos2d-x/Extension.md)

## 主要修改

- 升级 V8 到 12.0.267.10, 基准性能提升 25%。
- 优化文本纹理渲染流程，减少纹理拷贝和 JNI 调用。
- [wuffs](https://github.com/google/wuffs) 替代 libpng。解码提速 8%。
- 节点 RTS 计算 SIMD 优化，局部提升 14%。
- LocalStorage 添加缓存, 合并部分读写
- 添加 [Web Worker](https://developer.mozilla.org/en-US/docs/Web/API/Web_Workers_API/Using_web_workers)，释放多核性能。
- 添加运行时 GPU 纹理支持，动态选择支持格式。
- 内建 Tensorflow Lite，方便集成 AI 能力。

[具体改动](./cocos2d-x/ReleaseNote.md)

## 已知问题

- 不支持 Windows
- 不支持 Mac Intel 平台

## 后续路线

- 提供基础文档
- 其他： *欢迎反馈*

