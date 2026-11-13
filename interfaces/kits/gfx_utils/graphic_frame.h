/*
 * Copyright (c) 2026 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @addtogroup GraphicFrame
 * @{
 *
 * @brief Shared frame types for HAL and framework.
 *
 * This header is the interface contract between the camera/display HAL and
 * the graphics framework. It is C-compatible (pure structs and enums, no
 * C++ dependencies beyond stdint.h) so both C HAL adapters and C++ framework
 * code can include it directly.
 *
 * All types are declared at global scope on purpose: C and C++ translations
 * see exactly the same symbols (no namespace wrapper in either language),
 * so a HAL prototype written once binds identically in both. C++ framework
 * code inside the OHOS namespace reaches them through normal scope lookup
 * without qualification.
 *
 * @since 26.1.0
 * @version 26.1.0
 */

#ifndef GRAPHIC_FRAME_H
#define GRAPHIC_FRAME_H

#include <stdint.h>

/**
 * @brief Frame format (what kind of data the frame contains).
 *
 * This is a closed domain: the buffer-level tag is validated against these
 * values. It is intentionally independent of the ImageFormat enum (which
 * drives memory allocation) to prevent mixing the two value spaces.
 *
 * @since 26.1.0
 * @version 26.1.0
 */
enum GraphicFrameFormat {
    GRAPHIC_FRAME_FORMAT_NONE = 0,
    GRAPHIC_FRAME_FORMAT_NV12,
    GRAPHIC_FRAME_FORMAT_NV21,
    GRAPHIC_FRAME_FORMAT_JPEG,
    GRAPHIC_FRAME_FORMAT_H264,
};

/**
 * @brief One data segment of a frame.
 *
 * The consumer infers the plane from the chunk index and the format
 * (e.g. NV12 chunk 0 = Y, chunk 1 = UV), so no explicit planeId is needed.
 *
 * @since 26.1.0
 * @version 26.1.0
 */
struct GraphicFrameChunk {
    /** Virtual address of the segment. */
    void* virAddr;
    /** Physical address of the segment (driver allocated). */
    uint64_t phyAddr;
    /** Size of the segment in bytes. */
    uint32_t size;
    /** Stride of the segment in bytes. */
    uint32_t stride;
};

/**
 * @brief Maximum number of data segments per frame.
 *
 * @since 26.1.0
 * @version 26.1.0
 */
#define GRAPHIC_FRAME_MAX_CHUNK_NUM 5

/**
 * @brief Complete frame view: the producer sets everything in one call
 *        (SetFrame), the consumer gets everything in one call (GetFrame).
 *
 * @since 26.1.0
 * @version 26.1.0
 */
struct GraphicFrame {
    /** Frame format (GraphicFrameFormat value). */
    enum GraphicFrameFormat format;
    /** Frame width in pixels. */
    uint32_t width;
    /** Frame height in pixels. */
    uint32_t height;
    /** Number of valid chunks (1 to GRAPHIC_FRAME_MAX_CHUNK_NUM). */
    uint8_t chunkCount;
    /** Alignment padding, must be zero. */
    uint8_t reserved1[3];
    /** Reserved for future extension, must be zero. */
    uint32_t reserved2[4];
    /** Data segments. */
    struct GraphicFrameChunk chunks[GRAPHIC_FRAME_MAX_CHUNK_NUM];
};

#endif /* GRAPHIC_FRAME_H */
