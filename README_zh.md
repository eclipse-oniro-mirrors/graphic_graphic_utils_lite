# 图形HALS组件<a name="ZH-CN_TOPIC_0000001124625243"></a>

-   [简介](#section11660541593)
-   [目录](#section161941989596)
-   [编译构建](#section137768191623)
-   [说明](#section1312121216216)
    -   [使用说明](#section129654513264)

-   [相关仓](#section1371113476307)

## 简介<a name="section11660541593"></a>

HALS组件中实现了对驱动子系统和平台相关功能的适配封装，包括了FrameBuffer/GFX/SIMD等。

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

**graphic_graphic_utils_lite**

# 本次改动<a name="section_changes_zh"></a>

本仓针对 HiSpark AiFly（Hi3403V100）开发板进行功能适配。为便于区分，以下按“新增能力”与“原有功能增强”两部分说明。

## 新增能力

1. 新增 Gralloc 显存分配引擎
    -   新增 `interfaces/innerkits/hals/gralloc_engines.h` 与 `frameworks/hals/gralloc_engines.cpp`：以单例方式提供 `Init()`、`AllocBuffer()`、`FreeBuffer()`，基于 BufferHandle 完成显存分配与释放，并维护虚拟地址到句柄的映射。

2. 新增图片缓存显存分配能力
    -   新增 `frameworks/mem_custom.cpp`，配合新增的 `IMG_CACHE_MEMORY_CUSTOM` 宏与 `ImageInfo` 新增的 `phyAddr` 字段：图片缓存改由 Gralloc（`HBM_USE_ASSIGN_SIZE | HBM_USE_MEM_MMZ`）分配，并回填物理地址与虚拟地址，供硬件搬运使用。

3. 新增硬件合成带选项接口
    -   在 `interfaces/innerkits/hals/gfx_engines.h`、`frameworks/hals/gfx_engines.cpp` 中新增 `GfxEngines::GfxBlitWithOpt()`，支持像素 Alpha、SRCOVER 混合、缩放与全局透明度，失败时回退软合成。

4. 新增 ARM64 NEON 内存拷贝实现
    -   在 `interfaces/innerkits/graphic_neon_utils.h` 中新增 `__aarch64__` 分支，使用 LD1/ST1 与 PRFM 预取指令实现 NEON 拷贝。

5. 新增配置宏与特性开关
    -   在 `interfaces/innerkits/graphic_config.h` 中新增 `CACHE_JPEG_AND_PNG` 宏，并在 `bundle.json` 中新增 `graphic_utils_lite_enable_drm_display_hal` 特性开关。

## 原有功能增强

1. 原有硬件图形引擎使能配置增强
    -   原有功能：`ENABLE_GFX_ENGINES` 固定默认使能。
    -   本次增强：改为按 `MEDIA_INTERFACE_V1_0` 决定，定义该宏时为 1，否则为 0。

2. 原有编译构建配置增强
    -   原有功能：`BUILD.gn`/`utils.gni` 编译 `graphic_utils_lite` 与 `graphic_hals`。
    -   本次增强：支持透传 `board_macro_defines`；按 `media_interface_upgrade` 引入 `frameworks/mem_custom.cpp` 并定义 `IMG_CACHE_MEMORY_CUSTOM`；`graphic_hals` 新增 gralloc 源文件并调整依赖（移除 `:utils_lite`、新增 `//third_party/bounds_checking_function:libsec_shared`），`graphic_utils_lite` 新增依赖 `:graphic_hals`；补充 `//drivers/peripheral/base` 等头文件路径及 `interfaces/kits`。

3. 原有图片缓存接口实现调整
    -   原有功能：`frameworks/mem_api.cpp` 无条件提供 `ImageCacheMalloc`/`ImageCacheFree`。
    -   本次增强：改为仅在未定义 `IMG_CACHE_MEMORY_CUSTOM` 时提供，避免与自定义实现重复定义。

4. 原有开源合规配置增强
    -   原有功能：`OAT.xml` 用于开源合规扫描配置。
    -   本次增强：新增 projectPolicy，登记 HiSilicon 版权声明。