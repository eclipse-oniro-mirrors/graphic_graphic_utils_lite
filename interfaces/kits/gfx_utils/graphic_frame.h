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
 * @brief Shared graphic frame types.
 *
 * Describes one frame built from one or more memory segments.
 * C and C++ compatible.
 *
 * @since 26.1.0
 * @version 26.1.0
 */

#ifndef GRAPHIC_FRAME_H
#define GRAPHIC_FRAME_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Frame format.
 *
 * Closed value domain: only the values listed here are valid.
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
 * @brief One memory segment of a frame.
 *
 * The plane is inferred from the segment index and the format
 * (e.g. NV12 segment 0 = Y, segment 1 = UV).
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
 * @brief Maximum number of segments per frame.
 *
 * @since 26.1.0
 * @version 26.1.0
 */
#define GRAPHIC_FRAME_MAX_CHUNK_NUM 5

/**
 * @brief Complete frame description: format, dimensions and segments.
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

#ifdef __cplusplus
}
#endif

#endif /* GRAPHIC_FRAME_H */
