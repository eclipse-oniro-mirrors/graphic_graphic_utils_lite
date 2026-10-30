# Utils<a name="EN-US_TOPIC_0000001123083525"></a>

-   [Introduction](#section11660541593)
-   [Directory Structure](#section161941989596)
-   [Compilation and Building](#section137768191623)
-   [Description](#section1312121216216)
    -   [Usage](#section129654513264)

-   [Repositories Involved](#section1371113476307)

## Introduction<a name="section11660541593"></a>

The Utils module defines the common data structure in the graphics subsystem and provides a lite OS adaptation layer, which includes the lock, thread, and file system.

**Figure  1**  Dependency between modules of the graphics subsystem<a name="fig717664212591"></a>  
![](figures/dependency-between-modules-of-the-graphics-subsystem.png "dependency-between-modules-of-the-graphics-subsystem")

## Directory Structure<a name="section161941989596"></a>

```
/foundation/graphic/graphic_utils_lite
├── frameworks               # Framework code
│   ├── diagram              # 2d graphic engine implementation
│   │   ├── depiction        # Smooth curve point generation algorithm
│   │   ├── rasterizer       # rasterizer handling
│   │   ├── vertexgenerate   # vertex generation
│   │   └── vertexprimitive  # vertex primitive generation
│   └── hals                 # Hardware adaptation layer
├── interfaces               # APIs
│   ├── innerkits            # APIs between modules
│   │   └── hals             # APIs of the hardware adaptation layer
│   └── kits                 # External APIs
│       └── gfx_utils
└── test                     # Unit testing
```

## Compilation and Building<a name="section137768191623"></a>

```
# Generate the libgraphic_utils.so file in the out directory of the product folder through GN compilation.
hb build graphic_utils_lite
```

## Description<a name="section1312121216216"></a>

### Usage<a name="section129654513264"></a>

-   Utils is used in UI, surface, and WMS modules. For details, see the related source code.
-   The  **test**  folder provides unit testing for each utils API. Refer to it for the usage of utils.

## Repositories Involved<a name="section1371113476307"></a>

[Graphic subsystem](https://gitee.com/openharmony/docs/blob/master/en/readme/graphics.md)

[window_window_manager_lite](https://gitee.com/openharmony/window_window_manager_lite/blob/master/README.md)

[graphic_surface_lite](https://gitee.com/openharmony/graphic_surface_lite/blob/master/README.md)

[arkui_ui_lite](https://gitee.com/openharmony/arkui_ui_lite/blob/master/README.md)

# Hals<a name="EN-US_TOPIC_0000001124625243"></a>

-   [Introduction](#section11660541593)
-   [Directory Structure](#section161941989596)
-   [Compilation and Building](#section137768191623)
-   [Description](#section1312121216216)
    -   [Usage](#section129654513264)

-   [Repositories Involved](#section1371113476307)

## Introduction<a name="section11660541593"></a>

The Hals module adapts and encapsulates the functions related to the driver subsystem and platform, including FrameBuffer, graphics \(GFX\), and single instruction, multiple data \(SIMD\).

**Figure  1**  Dependency between modules of the graphics subsystem and that between graphics modules and the driver subsystem<a name="fig717664212591"></a>  
![](figures/dependency-between-modules-of-the-graphics-subsystem-and-that-between-graphics-modules-and-the-drive.png "dependency-between-modules-of-the-graphics-subsystem-and-that-between-graphics-modules-and-the-drive")

## Directory Structure<a name="section161941989596"></a>

```
/foundation/graphic/graphic_utils_lite
├── frameworks      # Framework code
│   ├── hals        # Hardware adaptation layer
│   ├── linux       # Linux platform adaptation layer
│   ├── liteos      # LiteOS platform adaptation layer
│   └── windows     # Windows platform adaptation layer
├── interfaces      # APIs
│   ├── innerkits   # APIs between modules
│   │   └── hals    # APIs of the hardware adaptation layer
│   └── kits        # External APIs
└── test            # Unit testing
```

## Compilation and Building<a name="section137768191623"></a>

```
# Generate the libgraphic_hals.so file in the out directory of the product folder through GN compilation.
hb build graphic_utils_lite
```

## Description<a name="section1312121216216"></a>

### Usage<a name="section129654513264"></a>

-   Hals is used in UI, surface, and WMS modules. For details, see the related source code.

## Repositories Involved<a name="section1371113476307"></a>

[Graphic subsystem](https://gitee.com/openharmony/docs/blob/master/en/readme/graphics.md)

[window_window_manager_lite](https://gitee.com/openharmony/window_window_manager_lite/blob/master/README.md)

[graphic_surface_lite](https://gitee.com/openharmony/graphic_surface_lite/blob/master/README.md)

[arkui_ui_lite](https://gitee.com/openharmony/arkui_ui_lite/blob/master/README.md)

**graphic_graphic_utils_lite**

# Changes in This Release<a name="section_changes_en"></a>

This repository is adapted for the HiSpark AiFly (Hi3403V100) development board. For clarity, the changes are described in two parts: **Added Features** and **Enhanced Existing Features**.

## Added Features

1. Added the Gralloc memory allocation engine
    -   Added `interfaces/innerkits/hals/gralloc_engines.h` and `frameworks/hals/gralloc_engines.cpp`, exposing `Init()`, `AllocBuffer()` and `FreeBuffer()` as a singleton: memory is allocated and freed via BufferHandle, with a virtual-address-to-handle map maintained internally.

2. Added custom image-cache memory allocation
    -   Added `frameworks/mem_custom.cpp`, together with the new `IMG_CACHE_MEMORY_CUSTOM` macro and the new `phyAddr` field of `ImageInfo`: the image cache is allocated through Gralloc (`HBM_USE_ASSIGN_SIZE | HBM_USE_MEM_MMZ`) and the physical/virtual addresses are written back for hardware copying.

3. Added a hardware composition API with options
    -   Added `GfxEngines::GfxBlitWithOpt()` in `interfaces/innerkits/hals/gfx_engines.h` and `frameworks/hals/gfx_engines.cpp`, supporting pixel alpha, SRCOVER blending, scaling and global alpha, with a fallback to software composition on failure.

4. Added an ARM64 NEON memory-copy implementation
    -   Added an `__aarch64__` branch in `interfaces/innerkits/graphic_neon_utils.h`, implementing the NEON copy with LD1/ST1 and PRFM prefetch instructions.

5. Added configuration macros and a feature switch
    -   Added the `CACHE_JPEG_AND_PNG` macro in `interfaces/innerkits/graphic_config.h`, and the `graphic_utils_lite_enable_drm_display_hal` feature in `bundle.json`.

## Enhanced Existing Features

1. The existing hardware graphics engine enablement is enhanced
    -   Original functionality: `ENABLE_GFX_ENGINES` was always enabled by default.
    -   Enhancement: it is now determined by `MEDIA_INTERFACE_V1_0` (1 when the macro is defined, 0 otherwise).

2. The existing build configuration is enhanced
    -   Original functionality: `BUILD.gn`/`utils.gni` build `graphic_utils_lite` and `graphic_hals`.
    -   Enhancement: `board_macro_defines` is forwarded; under `media_interface_upgrade`, `frameworks/mem_custom.cpp` is added and `IMG_CACHE_MEMORY_CUSTOM` is defined; `graphic_hals` adds the gralloc source and adjusts its dependencies (removing `:utils_lite`, adding `//third_party/bounds_checking_function:libsec_shared`), while `graphic_utils_lite` adds the `:graphic_hals` dependency; `//drivers/peripheral/base` and other include paths as well as `interfaces/kits` are added.

3. The existing image-cache API implementation is adjusted
    -   Original functionality: `frameworks/mem_api.cpp` always provided `ImageCacheMalloc`/`ImageCacheFree`.
    -   Enhancement: they are now provided only when `IMG_CACHE_MEMORY_CUSTOM` is not defined, avoiding a duplicate definition with the custom implementation.

4. The existing open-source compliance configuration is enhanced
    -   Original functionality: `OAT.xml` configures open-source compliance scanning.
    -   Enhancement: a `projectPolicy` is added, registering the HiSilicon copyright.