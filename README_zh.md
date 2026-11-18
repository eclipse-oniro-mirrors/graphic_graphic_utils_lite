# 图形HALS组件<a name="ZH-CN_TOPIC_0000001124625243"></a>

-   [简介](#section11660541593)
-   [目录](#section161941989596)
-   [编译构建](#section137768191623)
-   [说明](#section1312121216216)
    -   [使用说明](#section129654513264)

-   [相关仓](#section1371113476307)

## 简介<a name="section11660541593"></a>

HALS组件中实现了对驱动子系统和平台相关功能的适配封装，包括了FrameBuffer/GFX/SIMD等。

-   提供 Gralloc 显存分配引擎：以单例方式提供 Init()、AllocBuffer()、FreeBuffer()，基于 BufferHandle 完成显存分配与释放，并维护虚拟地址到句柄的映射。
-   提供硬件合成带选项接口：GfxEngines::GfxBlitWithOpt() 支持像素 Alpha、SRCOVER 混合、缩放与全局透明度，失败时回退软合成。

**图 1**  图形子系统组件间以及与驱动子系统的依赖关系<a name="fig717664212591"></a>  
![](figures/图形子系统组件间以及与驱动子系统的依赖关系.png "图形子系统组件间以及与驱动子系统的依赖关系")

## 目录<a name="section161941989596"></a>

```
/foundation/graphic/graphic_utils_lite
├── frameworks               # 框架代码
│   ├── diagram              # 2d图形引擎
│   │   ├── depiction        # 光滑曲线点生成算法
│   │   ├── rasterizer       # 光栅化处理
│   │   ├── vertexgenerate   # 顶点生成器
│   │   └── vertexprimitive  # 顶点几何图元
│   └── hals                 # 硬件适配层
├── interfaces               # 接口
│   ├── innerkits            # 模块间接口
│   │   └── hals             # 硬件适配层接口
│   └── kits                 # 对外接口
│       └── gfx_utils
└── test                     # 单元测试
```

## 编译构建<a name="section137768191623"></a>

```
# 通过gn编译,在out目录下对应产品的文件夹中生成libgraphic_hals.so
hb build graphic_utils_lite
```

## 说明<a name="section1312121216216"></a>

### 使用说明<a name="section129654513264"></a>

-   图形UI/SURFACE/WMS组件均使用了HALS组件，可参考相关源码；

## 相关仓<a name="section1371113476307"></a>

[图形子系统](https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/%E5%9B%BE%E5%BD%A2%E5%AD%90%E7%B3%BB%E7%BB%9F.md)

[window_window_manager_lite](https://gitee.com/openharmony/window_window_manager_lite/blob/master/README.md)

[graphic_surface_lite](https://gitee.com/openharmony/graphic_surface_lite/blob/master/README.md)

[arkui_ui_lite](https://gitee.com/openharmony/arkui_ui_lite/blob/master/README.md)

# 图形UTILS组件<a name="ZH-CN_TOPIC_0000001123083525"></a>

-   [简介](#section11660541593)
-   [目录](#section161941989596)
-   [编译构建](#section137768191623)
-   [说明](#section1312121216216)
    -   [使用说明](#section129654513264)

-   [相关仓](#section1371113476307)

## 简介<a name="section11660541593"></a>

UTILS组件中定义了图形子系统中的公共数据结构，并提供了一层轻薄的操作系统适配层（如锁、线程、文件系统）。

-   提供图片缓存显存分配能力：图片缓存由 Gralloc 分配，并回填物理地址与虚拟地址供硬件搬运使用。
-   提供 ARM64 NEON 内存拷贝实现：使用 LD1/ST1 与 PRFM 预取指令实现 NEON 拷贝。
-   提供配置宏与特性开关：提供 CACHE_JPEG_AND_PNG 宏与 graphic_utils_lite_enable_drm_display_hal 特性开关。
-   硬件图形引擎使能配置：ENABLE_GFX_ENGINES 按 MEDIA_INTERFACE_V1_0 决定。
-   编译构建与开源合规配置：支持透传 board_macro_defines 等构建参数，并通过 projectPolicy 登记 HiSilicon 版权声明。

**图 1**  图形子系统组件间依赖关系<a name="fig717664212591"></a>  
![](figures/图形子系统组件间依赖关系.png "图形子系统组件间依赖关系")

## 目录<a name="section161941989596"></a>

```
/foundation/graphic/graphic_utils_lite
├── frameworks      # 框架代码
│   ├── hals        # 硬件适配层
│   ├── linux       # linux平台适配层
│   ├── liteos      # liteos平台适配层
│   └── windows     # windows平台适配层
├── interfaces      # 接口
│   ├── innerkits   # 模块间接口
│   │   └── hals    # 硬件适配层接口
│   └── kits        # 对外接口
└── test            # 单元测试
```

## 编译构建<a name="section137768191623"></a>

```
# 通过gn编译,在out目录下对应产品的文件夹中生成libgraphic_utils.so
hb build graphic_utils_lite
```

## 说明<a name="section1312121216216"></a>

### 使用说明<a name="section129654513264"></a>

-   图形UI/SURFACE/WMS组件均使用了UTILS组件，可参考相关源码；
-   test提供了UTILS组件各接口的单元测试，也可参考使用。

## 相关仓<a name="section1371113476307"></a>

[图形子系统](https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/%E5%9B%BE%E5%BD%A2%E5%AD%90%E7%B3%BB%E7%BB%9F.md)

[window_window_manager_lite](https://gitee.com/openharmony/window_window_manager_lite/blob/master/README.md)

[graphic_surface_lite](https://gitee.com/openharmony/graphic_surface_lite/blob/master/README.md)

[arkui_ui_lite](https://gitee.com/openharmony/arkui_ui_lite/blob/master/README.md)