# Utils<a name="EN-US_TOPIC_0000001123083525"></a>

-   [Introduction](#section11660541593)
-   [Directory Structure](#section161941989596)
-   [Compilation and Building](#section137768191623)
-   [Description](#section1312121216216)
    -   [Usage](#section129654513264)

-   [Repositories Involved](#section1371113476307)

## Introduction<a name="section11660541593"></a>

The Utils module defines the common data structure in the graphics subsystem and provides a lite OS adaptation layer, which includes the lock, thread, and file system.

-   Custom image-cache memory allocation: through frameworks/mem_custom.cpp together with the IMG_CACHE_MEMORY_CUSTOM macro and the phyAddr field of ImageInfo, the image cache is allocated through Gralloc (HBM_USE_ASSIGN_SIZE | HBM_USE_MEM_MMZ) and the physical/virtual addresses are written back for hardware copying.
-   ARM64 NEON memory-copy implementation: an __aarch64__ branch in graphic_neon_utils.h implements the NEON copy with LD1/ST1 and PRFM prefetch instructions.
-   Configuration macros and feature switch: the CACHE_JPEG_AND_PNG macro in graphic_config.h and the graphic_utils_lite_enable_drm_display_hal feature in bundle.json.
-   Hardware graphics engine enablement: ENABLE_GFX_ENGINES is determined by MEDIA_INTERFACE_V1_0 (1 when the macro is defined, 0 otherwise).
-   Build configuration: board_macro_defines is forwarded; under media_interface_upgrade, frameworks/mem_custom.cpp is included and IMG_CACHE_MEMORY_CUSTOM is defined; graphic_hals contains the gralloc source and depends on //third_party/bounds_checking_function:libsec_shared, while graphic_utils_lite depends on :graphic_hals; //drivers/peripheral/base and other include paths as well as interfaces/kits are included.
-   Image-cache API implementation: frameworks/mem_api.cpp provides ImageCacheMalloc/ImageCacheFree only when IMG_CACHE_MEMORY_CUSTOM is not defined, avoiding a duplicate definition with the custom implementation.
-   Open-source compliance configuration: OAT.xml registers the HiSilicon copyright through projectPolicy.

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

-   Gralloc memory allocation engine: provides Init(), AllocBuffer() and FreeBuffer() as a singleton; memory is allocated and freed via BufferHandle, with a virtual-address-to-handle map maintained internally.
-   Hardware composition API with options: GfxEngines::GfxBlitWithOpt() supports pixel alpha, SRCOVER blending, scaling and global alpha, with a fallback to software composition on failure.

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