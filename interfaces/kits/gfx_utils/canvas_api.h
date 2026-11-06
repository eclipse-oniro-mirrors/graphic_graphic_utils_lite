/*
 * Copyright (c) 2026-2026 Huawei Device Co., Ltd.
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
 * @addtogroup Canvas
 * @{
 *
 * @brief Provides canvas 2D graphics rendering capabilities.
 *
 * @since 26.1.0
 */

/**
 * @file canvas_api.h
 *
 * @brief Canvas 2D graphics rendering API.
 *
 * Defines the canvas rendering API for 2D graphics operations.
 * Provides canvas creation and destruction, path drawing, shape filling,
 * text rendering, image processing, and other features.
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing.Slim
 * @library libnative_drawing.so
 * @kit ArkGraphics2D
 * @since 26.1.0
 */

#ifndef CANVAS_API_H
#define CANVAS_API_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates touch event types.
 *
 * Defines the types of touch events that can be detected on the canvas.
 * It is used to process user touch interactions, such as pressing, moving, and releasing.
 * @since 26.1.0
 */
typedef enum OH_Canvas_TouchType {
    /**
     * Touch press event, indicating that a finger has touched the screen.
     * @since 26.1.0
     */
    OH_CANVAS_TOUCH_PRESS = 0,

    /**
     * Touch long press event, indicating that a finger has been held on the screen for an extended period.
     * @since 26.1.0
     */
    OH_CANVAS_TOUCH_LONG_PRESS = 1,

    /**
     * Touch start event, indicating that a touch interaction has begun.
     * @since 26.1.0
     */
    OH_CANVAS_TOUCH_START = 2,

    /**
     * Touch move event, indicating that a finger is moving on the screen.
     * @since 26.1.0
     */
    OH_CANVAS_TOUCH_MOVE = 3,

    /**
     * Touch end event, indicating that a finger has left the screen.
     * @since 26.1.0
     */
    OH_CANVAS_TOUCH_END = 4,

    /**
     * Touch release event, indicating that a touch interaction has ended.
     * @since 26.1.0
     */
    OH_CANVAS_TOUCH_RELEASE = 5,

    /**
     * Touch cancel event, indicating that a touch interaction has been cancelled.
     * @since 26.1.0
     */
    OH_CANVAS_TOUCH_CANCEL = 6,

    /**
     * Unknown touch event, used when the event type cannot be determined.
     * @since 26.1.0
     */
    OH_CANVAS_TOUCH_UNKNOWN,
} OH_Canvas_TouchType;

/**
 * @brief Enumerates rotating crown event types.
 *
 * Defines the rotating crown event types of a wearable device.
 * It is used to process the rotating input from the watch crown or rotating bezel.
 * @since 26.1.0
 */
typedef enum OH_Canvas_RotateType {
    /**
     * Rotation start event, indicating that a rotation interaction has begun.
     * @since 26.1.0
     */
    OH_CANVAS_ROTATE_START = 0,

    /**
     * Rotation move event, indicating that rotational movement has been detected.
     * @since 26.1.0
     */
    OH_CANVAS_ROTATE_MOVE = 1,

    /**
     * Rotation end event, indicating that a rotation interaction has ended.
     * @since 26.1.0
     */
    OH_CANVAS_ROTATE_END = 2,

    /**
     * Unknown rotation event, used when the event type cannot be determined.
     * @since 26.1.0
     */
    OH_CANVAS_ROTATE_UNKNOWN,
} OH_Canvas_RotateType;

/**
 * @brief Enumerates line cap styles.
 *
 * Defines the endpoint style of a line drawn on the canvas.
 * It is used to control the appearance of the endpoints of a line segment.
 * @since 26.1.0
 */
typedef enum OH_Canvas_LineCapType {
    /**
     * Butt line cap, no additional decoration at line endpoints.
     * @since 26.1.0
     */
    OH_CANVAS_LINE_CAP_BUTT = 0,

    /**
     * Square line cap, line endpoints extend as a square.
     * @since 26.1.0
     */
    OH_CANVAS_LINE_CAP_SQUARE = 1,

    /**
     * Round line cap, line endpoints extend as a circle.
     * @since 26.1.0
     */
    OH_CANVAS_LINE_CAP_ROUND = 2,

    /**
     * Maximum line cap type, used for boundary checking.
     * @since 26.1.0
     */
    OH_CANVAS_LINE_CAP_MAX,
} OH_Canvas_LineCapType;

/**
 * @brief Enumerates line join styles.
 *
 * Defines the style of the joint between two line segments on the canvas.
 * It is used to control the appearance of the corners of a line segment.
 * @since 26.1.0
 */
typedef enum OH_Canvas_LineJoinType {
    /**
     * Miter join, line corners extend to a sharp point.
     * @since 26.1.0
     */
    OH_CANVAS_LINE_JOIN_MITER = 0,

    /**
     * Round join, line corners are filled with an arc.
     * @since 26.1.0
     */
    OH_CANVAS_LINE_JOIN_ROUND = 1,

    /**
     * Bevel join, line corners are filled with a flat edge.
     * @since 26.1.0
     */
    OH_CANVAS_LINE_JOIN_BEVEL = 2,

    /**
     * Maximum line join type, used for boundary checking.
     * @since 26.1.0
     */
    OH_CANVAS_LINE_JOIN_MAX,
} OH_Canvas_LineJoinType;

/**
 * @brief Enumerates the blend modes.
 *
 * Defines the blend mode for image compositing on the canvas.
 * It is used to control how the source color and destination color are combined.
 * @since 26.1.0
 */
typedef enum OH_Canvas_BlendType {
    /**
     * No blend mode, no compositing is applied.
     * @since 26.1.0
     */
    OH_CANVAS_BLEND_TYPE_NONE = 0,

    /**
     * Source color completely overwrites the destination color.
     * @since 26.1.0
     */
    OH_CANVAS_BLEND_TYPE_SRC = 1,

    /**
     * Source color overwrites the destination color; this is the default blend mode.
     * @since 26.1.0
     */
    OH_CANVAS_BLEND_TYPE_SRCOVER = 2,

    /**
     * Destination color overwrites the source color.
     * @since 26.1.0
     */
    OH_CANVAS_BLEND_TYPE_DSTOVER = 3,

    /**
     * Only the intersection of source color and destination is displayed.
     * @since 26.1.0
     */
    OH_CANVAS_BLEND_TYPE_SRCIN = 4,

    /**
     * Only the intersection of destination and source color is displayed.
     * @since 26.1.0
     */
    OH_CANVAS_BLEND_TYPE_DSTIN = 5,

    /**
     * Only the non-intersecting area of source color and destination is displayed.
     * @since 26.1.0
     */
    OH_CANVAS_BLEND_TYPE_SRCOUT = 6,

    /**
     * Only the non-intersecting area of destination and source color is displayed.
     * @since 26.1.0
     */
    OH_CANVAS_BLEND_TYPE_DSTOUT = 7,

    /**
     * Maximum blend type, used for boundary checking.
     * @since 26.1.0
     */
    OH_CANVAS_BLEND_TYPE_MAX,
} OH_Canvas_BlendType;

/**
 * @brief Enumerates text alignment modes.
 *
 * Defines the alignment mode of the rendered text on the canvas.
 * It is used to control the horizontal and vertical positioning of the text.
 * @since 26.1.0
 */
typedef enum OH_Canvas_TextAlign {
    /**
     * Left alignment, text is aligned to the left edge.
     * @since 26.1.0
     */
    OH_CANVAS_TEXT_ALIGN_LEFT = 0,

    /**
     * Right alignment, text is aligned to the right edge.
     * @since 26.1.0
     */
    OH_CANVAS_TEXT_ALIGN_RIGHT = 1,

    /**
     * Center alignment, text is horizontally centered.
     * @since 26.1.0
     */
    OH_CANVAS_TEXT_ALIGN_CENTER = 2,

    /**
     * Top alignment, text is aligned to the top edge.
     * @since 26.1.0
     */
    OH_CANVAS_TEXT_ALIGN_TOP = 3,

    /**
     * Bottom alignment, text is aligned to the bottom edge.
     * @since 26.1.0
     */
    OH_CANVAS_TEXT_ALIGN_BOTTOM = 4,

    /**
     * Maximum text alignment type, used for boundary checking.
     * @since 26.1.0
     */
    OH_CANVAS_TEXT_ALIGN_MAX,
} OH_Canvas_TextAlign;

/**
 * @brief Defines the text size.
 *
 * Defines the width and height used for text rendering.
 * It is used to obtain the size of the text on the canvas.
 * @since 26.1.0
 */
typedef struct OH_Canvas_TextPos {
    /**
     * Text width (pixels).
     * @since 26.1.0
     */
    int16_t x;

    /**
     * Text height (pixels).
     * @since 26.1.0
     */
    int16_t y;
} OH_Canvas_TextPos;

/**
 * @brief Defines the canvas image information struct.
 *
 * It is used to transfer image data during canvas operations.
 * It contains the image header information and pixel data buffer.
 * This struct is opaque. Use **OH_Canvas_LoadImagePath** or **OH_Canvas_CreateImageData**.
 * Create an instance and use **OH_Canvas_FreeImageData** to free the instance.
 * @since 26.1.0
 */
typedef struct OH_Canvas_ImageInfo OH_Canvas_ImageInfo;

/**
 * @brief Rectangle structure for canvas drawing operations.
 * Used to specify a rectangular area with position and dimensions.
 * @since 26.1.0
 */
typedef struct OH_Canvas_Rect {
    /**
     * X-coordinate of the rectangle's top-left corner, relative to the reference origin (pixels).
     * @since 26.1.0
     */
    int16_t x;

    /**
     * Y-coordinate of the rectangle's top-left corner, relative to the reference origin (pixels).
     * @since 26.1.0
     */
    int16_t y;

    /**
     * Rectangle width (pixels).
     * @since 26.1.0
     */
    uint16_t width;

    /**
     * Rectangle height (pixels).
     * @since 26.1.0
     */
    uint16_t height;
} OH_Canvas_Rect;

/**
 * @brief Canvas callback type enumeration.
 *
 * Defines the types of callbacks that can be triggered by canvas events.
 * Used to identify and dispatch different event types to the appropriate handler.
 * @since 26.1.0
 */
typedef enum {
    /**
     * General event callback.
     * Triggered when the canvas framework needs to notify the application layer of
     * general state changes, trigger initialization logic, or perform internal state synchronization.
     * @since 26.1.0
     */
    OH_CANVAS_CALLBACK_TE_EVENT = 0,

    /**
     * Touch event callback.
     * Triggered when a user generates touch interactions (such as press, move, release, long press, etc.)
     * in the canvas area.
     * @since 26.1.0
     */
    OH_CANVAS_CALLBACK_TOUCH = 1,

    /**
     * Rotation event callback.
     * Triggered when gesture rotation is detected (such as two-finger pinch rotation).
     * @since 26.1.0
     */
    OH_CANVAS_CALLBACK_ROTATE = 2,

    /**
     * Maximum callback type, used for boundary checking.
     * @since 26.1.0
     */
    OH_CANVAS_CALLBACK_MAX,
} OH_Canvas_CallbackType;

/**
 * @brief Create a canvas handle.
 *
 * Allocates and initializes a new canvas rendering context.
 * This function is not thread-safe; the same canvas handle should not be used concurrently
 * in multiple threads. The caller must ensure mutual exclusion when accessing the same
 * canvas handle from multiple threads.
 * @param componentId [in] Unique component identifier string.
 *        Used to identify the business component or view instance to which the canvas belongs.
 *        - This string will be saved internally by the framework for subsequent node mounting.
 *        - **Length limit**: The maximum effective length of this string must not exceed
 *          **255 characters** (excluding the null terminator ' ').
 *        - Example values: "TextView_01", "CustomView_Main", "Chart_Canvas_1", etc.
 *        - If NULL is passed, the framework may use a default identifier; if the 255-character
 *          length limit is exceeded, the framework will truncate. Both cases may result in
 *          incorrect node mounting.
 *        - Note: The string pointer passed in is copied internally by the framework after
 *          calling this function; the caller does not need to maintain the string's lifetime
 *          afterwards.
 * @param invokeCallbackName [in] function name for canvas event callback.
 *        - This function name will be used by the framework to invoke user-side callbacks
 *          when canvas events (such as touch, rotation, etc.) occur.
 *        - The specified function must be registered on the user side.
 *        - **Length limit**: The maximum effective length of this string must not exceed
 *          **255 characters**.
 *        - If NULL is passed, the framework will not trigger any event callbacks.
 *        - **Callback function signature**: int32_t HandleCanvasEvent(
 *              uint32_t callbackType,
 *              uint32_t eventType,
 *              uint8_t *buffer,
 *              uint32_t bufferLen);
 *        - **Callback type parameter (callbackType)**:
 *          - OH_CANVAS_CALLBACK_TE_EVENT: TE event
 *          - OH_CANVAS_CALLBACK_TOUCH: Touch event
 *          - OH_CANVAS_CALLBACK_ROTATE: Rotation event
 *        - **Event type parameter (eventType)**:
 *          - For TE_EVENT: Ignored
 *          - For TOUCH/ROTATE: Event type value
 *        - **Buffer parameter (buffer)**:
 *          - For TE_EVENT: Ignored
 *          - For TOUCH: Data buffer pointer (uint8_t*)
 *            - OH_CANVAS_TOUCH_MOVE: Two points {previous point, current point}
 *            - Other event types: One point (current point)
 *            - Single point format: {float x, float y}
 *          - For ROTATE: Rotation angle value (int16_t)
 *          - Note: The buffer is managed by the system. Users do not need to allocate or free it.
 *            However, the data is only valid during the callback. If you need to retain the data,
 *            you must copy it to your own memory immediately.
 *        - **Buffer length parameter (bufferLen)**:
 *          - For TE_EVENT: Ignored
 *          - For TOUCH: Data buffer length
 *          - For ROTATE: Ignored
 *        - **Return value**: Processing result, varies by event type.
 * @param offScreenRender [in] Whether to use offscreen rendering.
 *        - true: Creates an offscreen rendering context (Offscreen Canvas), content is not
 *          directly displayed on screen, typically used for offscreen drawing, image compositing,
 *          or screenshot scenarios.
 *        - false: Creates a normal onscreen rendering context (default behavior), content is
 *          directly rendered to the display surface.
 * @return Returns the canvas handle on success, 0 on failure. Possible failure reasons include
 *         insufficient memory, etc.
 * @release canvas/OH_Canvas_DestroyHandle {return}
 * @since 26.1.0
 */
uint32_t OH_Canvas_CreateHandle(const char *componentId, const char *invokeCallbackName, bool offScreenRender);

/**
 * @brief Destroys a canvas handle.
 *
 * Before calling this function, free the image data memory created by **OH_Canvas_CreateImageData**,
 * **OH_Canvas_LoadImagePath** and **OH_Canvas_GetImageData**.
 * After calling **OH_Canvas_FreeImageData**,
 * the handle becomes invalid and cannot be used again.
 * @param canvas Canvas handle to be destroyed.
 * @return No return value (**void**).
 *         If the parameter is invalid (for example, NULL or an invalid handle), the function behavior is
 *         undefined or may trigger an assertion (depending on the underlying implementation constraints).
 *         You are advised to ensure that the canvas is valid before calling this function.
 * @see OH_Canvas_CreateHandle
 * @since 26.1.0
 */
void OH_Canvas_DestroyHandle(uint32_t canvas);

/**
 * @brief Sets the fill style to a solid color (in RGBA format).
 * This configuration takes effect for all subsequent fill operations.
 *
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param color Color in RGBA format, in the format of 0xRRGGBBAA. For example, **0xFF0000FF** indicates opaque red.
 *              The default fill color is black.
 * @return No return value (**void**).
 *         When the call is successful, the fill style is updated.
 *         If **canvas** is set to **0** or invalid, the function behavior is undefined or may trigger an assertion
 *         (depending on the underlying implementation constraints).
 *         You are advised to ensure that the input canvas handle is valid.
 * @since 26.1.0
 */
void OH_Canvas_FillStyle_Color(uint32_t canvas, uint32_t color);

/**
 * @brief Sets the stroke style to a solid color (in RGBA format).
 * This configuration takes effect for all subsequent stroke operations.
 *
 * @param canvas [in] Canvas handle, the value of which cannot be **0**.
 * @param color [in] Color in RGBA format, in the format of 0xAARRGGBB. For example, **0xFFFF0000** indicates opaque red.
 *              The default stroke color is black.
 * @return No return value (**void**).
 *         When the call is successful, the stroke style is updated.
 *         If **canvas** is set to **0** or invalid, the function behavior is undefined or may trigger an assertion
 *         (depending on the underlying implementation constraints).
 *         You are advised to ensure that the input canvas handle is valid.
 * @since 26.1.0
 */
void OH_Canvas_StrokeStyle_Color(uint32_t canvas, uint32_t color);

/**
 * @brief Sets the line width. This configuration takes effect for all subsequent stroke operations.
 *
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param width Line width in pixels. The default value is **2**. The recommended value range is 1 to 100.
 *              Behavior beyond this range is undefined.
 * @return No return value (**void**).
 *         When the call is successful, the stroke width is updated to the specified value.
 *         If **canvas** is set to **0** or invalid, the function behavior is undefined or may trigger an assertion
 *         (depending on the underlying implementation constraints).
 *         You are advised to ensure that the input canvas handle is valid.
 * @since 26.1.0
 */
void OH_Canvas_SetLineWidth(uint32_t canvas, uint16_t width);

/**
 * @brief Sets the line cap style, which defines the appearance of the endpoints of a line segment in a stroke operation.
 * This configuration takes effect for all subsequent stroke operations.
 *
 * @param canvas [in] Canvas handle, the value of which cannot be **0**.
 * @param cap [in] Enumerated value of the line cap style. The default value is **butt**.
 * @return No return value (**void**).
 *         When the call is successful, the line cap style is updated.
 *         If **canvas** is set to **0** or invalid, the function behavior is undefined or may trigger an assertion
 *         (depending on the underlying implementation constraints).
 *         You are advised to ensure that the input canvas handle is valid.
 * @since 26.1.0
 */
void OH_Canvas_SetLineCap(uint32_t canvas, OH_Canvas_LineCapType cap);

/**
 * @brief Sets the line join style, which controls the appearance of the corners of a line segment in a stroke
 * operation. This configuration takes effect for all subsequent stroke operations.
 *
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param join Enumerated value of the line join style. By default, rounded corners are used.
 * @return No return value (**void**).
 *         When the call is successful, the line join style is updated.
 *         If **canvas** is set to **0** or invalid, the function behavior is undefined or may trigger an assertion
 *         (depending on the underlying implementation constraints).
 *         You are advised to ensure that the input canvas handle is valid.
 * @since 26.1.0
 */
void OH_Canvas_SetLineJoin(uint32_t canvas, OH_Canvas_LineJoinType join);

/**
 * @brief Sets the miter limit for sharp corner joins. When the angle of a line join exceeds this limit,
 * it will be converted to a miter join.
 * This configuration takes effect for all subsequent stroke operations.
 *
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param limit Miter limit. The recommended value range is 1 to 10. The default value is **10**.
 * @return No return value (**void**).
 *         When the call is successful, the miter limit is updated.
 *         If **canvas** is set to **0** or invalid, the function behavior is undefined or may trigger an assertion
 *         (depending on the underlying implementation constraints).
 *         You are advised to ensure that the input canvas handle is valid.
 * @since 26.1.0
 */
void OH_Canvas_SetMiterLimit(uint32_t canvas, float limit);

/**
 * @brief Builds a rectangular path.
 * The coordinate origin is at the top-left corner of the canvas, with the Y-axis pointing downward.
 * If filling is needed, the OH_Canvas_Fill function must also be called;
 * if stroking is needed, the OH_Canvas_Stroke function must be called.
 *
 * @param canvas [in] Canvas handle, must not be 0.
 * @param rect [in] Rectangle structure containing the build area coordinates and dimensions.
 * @return No return value (void).
 * @since 26.1.0
 */
void OH_Canvas_BuildRect(uint32_t canvas, OH_Canvas_Rect rect);

/**
 * @brief Draws and fills the specified rectangular area using the current fill style.
 * The coordinate origin is at the top-left corner of the canvas, with the Y-axis pointing downward.
 *
 * @param canvas [in] Canvas handle, must not be 0.
 * @param rect [in] Rectangle structure containing the fill area coordinates and dimensions.
 * @return No return value (void).
 * @since 26.1.0
 */
void OH_Canvas_FillRect(uint32_t canvas, OH_Canvas_Rect rect);

/**
 * @brief Draws a rectangle outline using the current stroke style.
 * The coordinate origin is at the top-left corner of the canvas, with the Y-axis pointing downward.
 *
 * @param canvas [in] Canvas handle, must not be 0.
 * @param rect [in] Rectangle structure containing the stroke area coordinates and dimensions.
 * @return No return value (void).
 * @since 26.1.0
 */
void OH_Canvas_StrokeRect(uint32_t canvas, OH_Canvas_Rect rect);

/**
 * @brief Clears a rectangular area. Sets the pixels within the rectangle to transparent black.
 * The coordinate origin is at the top-left corner of the canvas, with the Y-axis pointing downward.
 *
 * @param canvas [in] Canvas handle, must not be 0.
 * @param rect [in] Rectangle structure containing the clear area coordinates and dimensions.
 * @return No return value (void).
 * @since 26.1.0
 */
void OH_Canvas_ClearRect(uint32_t canvas, OH_Canvas_Rect rect);

/**
 * @brief Fills the current path.
 *
 * Fills the interior of the current path using the current fill style, including
 * the non-zero and even-odd filling rules.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @return No return value (**void**).
 * @see OH_Canvas_BeginPath
 * @since 26.1.0
 */
void OH_Canvas_Fill(uint32_t canvas);

/**
 * @brief Strokes the current path.
 *
 * Strokes the outline of the current path using the current stroke style.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @return No return value (**void**).
 * @see OH_Canvas_BeginPath
 * @since 26.1.0
 */
void OH_Canvas_Stroke(uint32_t canvas);

/**
 * @brief Starts a new path and clears all previously accumulated path data.
 * This function is used to reset the current path before constructing a new shape.
 *
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @return No return value (**void**).
 * @see OH_Canvas_ClosePath
 * @see OH_Canvas_Fill
 * @see OH_Canvas_Stroke
 * @since 26.1.0
 */
void OH_Canvas_BeginPath(uint32_t canvas);

/**
 * @brief Closes the current path.
 * Closes the current subpath by drawing a straight line back to the start point.
 *
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @return No return value (**void**).
 * @see OH_Canvas_BeginPath
 * @since 26.1.0
 */
void OH_Canvas_ClosePath(uint32_t canvas);

/**
 * @brief Moves the pen to the specified coordinates and sets the current pen position without drawing a line.
 * Subsequent drawing operations will start from this point.
 * The coordinate origin is located at the upper left corner of the canvas, and the Y axis points downward.
 *
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param x Target X coordinate, relative to the upper left corner of the canvas.
 * @param y Target Y coordinate, relative to the upper left corner of the canvas.
 * @return No return value (**void**).
 * @see OH_Canvas_LineTo
 * @since 26.1.0
 */
void OH_Canvas_MoveTo(uint32_t canvas, float x, float y);

/**
 * @brief Draws a straight line from the current point to the specified coordinates.
 * The coordinate origin is located at the upper left corner of the canvas, and the Y axis points downward.
 *
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param x Target X coordinate, relative to the upper left corner of the canvas.
 * @param y Target Y coordinate, relative to the upper left corner of the canvas.
 * @return No return value (**void**).
 * @see OH_Canvas_MoveTo
 * @since 26.1.0
 */
void OH_Canvas_LineTo(uint32_t canvas, float x, float y);

/**
 * @brief Draws a quadratic Bezier curve.
 *
 * Draws a quadratic Bezier curve from the current pen position to the end point.
 * The shape of the curve is determined by the specified control point.
 * The coordinate origin is located at the upper left corner of the canvas, and the Y axis points downward.
 * @param canvas [in] Canvas handle, the value of which cannot be **0**.
 * @param cpx [in] X coordinate of the control point, relative to the upper left corner of the canvas.
 * @param cpy [in] Y coordinate of the control point, relative to the upper left corner of the canvas.
 * @param x [in] X coordinate of the end point, relative to the upper left corner of the canvas.
 * @param y [in] Y coordinate of the end point, relative to the upper left corner of the canvas.
 * @return No return value (**void**).
 * @since 26.1.0
 */
void OH_Canvas_QuadraticCurveTo(uint32_t canvas, float cpx, float cpy, float x, float y);

/**
 * @brief Draws a cubic Bezier curve.
 *
 * This function draws a curve from the current pen position to the end point. The shape of the curve is determined by
 * two specified control points.
 * The coordinate origin is located at the upper left corner of the canvas, and the Y axis points downward.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param cp1x X coordinate of the first control point, relative to the upper left corner of the canvas.
 * @param cp1y Y coordinate of the first control point, relative to the upper left corner of the canvas.
 * @param cp2x X coordinate of the second control point, relative to the upper left corner of the canvas.
 * @param cp2y Y coordinate of the second control point, relative to the upper left corner of the canvas.
 * @param x X coordinate of the end point, relative to the upper left corner of the canvas.
 * @param y Y coordinate of the end point, relative to the upper left corner of the canvas.
 * @return No return value (**void**).
 * @since 26.1.0
 */
void OH_Canvas_BezierCurveTo(uint32_t canvas, float cp1x, float cp1y, float cp2x, float cp2y, float x, float y);

/**
 * @brief Draws an arc tangent to the line connecting the current point to two specified points.
 *
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param x1 X coordinate of the first point, relative to the upper left corner of the canvas.
 * @param y1 Y coordinate of the first point, relative to the upper left corner of the canvas.
 * @param x2 X coordinate of the second point, relative to the upper left corner of the canvas.
 * @param y2 Y coordinate of the second point, relative to the upper left corner of the canvas.
 * @param radius Radius of the arc, in pixels. The value must be greater than **0**.
 * @return No return value (**void**).
 * @since 26.1.0
 */
void OH_Canvas_ArcTo(uint32_t canvas, float x1, float y1, float x2, float y2, float radius);

/**
 * @brief Draws an arc with the specified center, radius, and angle range.
 *
 * The coordinate origin is located at the upper left corner of the canvas, and the Y axis points downward.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param x X coordinate of the center point, relative to the upper left corner of the canvas.
 * @param y Y coordinate of the center point, relative to the upper left corner of the canvas.
 * @param r Radius of the arc, in pixels. The value must be greater than **0**.
 * @param start Start angle, in radians, starting from the positive X axis.
 * @param end End angle, in radians, starting from the positive X axis.
 * @param anticlockwise Specifies whether to draw the arc counterclockwise.
 * @return No return value (**void**).
 * @since 26.1.0
 */
void OH_Canvas_Arc(uint32_t canvas, float x, float y, float r, float start, float end, bool anticlockwise);

/**
 * @brief Scales the canvas coordinate system.
 * This function affects only subsequent drawing operations and does not change the content that has been drawn.
 * The default scaling center is the origin (0, 0). To change the center, call **translate()** first.
 *
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param scaleX Scaling factor on the X axis. The value **1.0** indicates no scaling, a value less than **1.0**
 *               indicates scaling down, and a value greater than **1.0** indicates scaling up.
 * @param scaleY Scaling factor on the Y axis. The value **1.0** indicates no scaling, a value less than **1.0**
 *               indicates scaling down, and a value greater than **1.0** indicates scaling up.
 * @return No return value (**void**).
 * @see OH_Canvas_Rotate
 * @see OH_Canvas_Translate
 * @see OH_Canvas_Transform
 * @since 26.1.0
 */
void OH_Canvas_Scale(uint32_t canvas, float scaleX, float scaleY);

/**
 * @brief Rotates a canvas.
 *
 * Rotates the canvas clockwise by a specified angle. The default rotation center is the canvas origin (0, 0).
 * To change the center, call **translate()** first.
 * All subsequent drawing operations are based on this rotated coordinate system.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param angle Rotation angle (in radians), measured clockwise.
 * @return No return value (**void**).
 * @see OH_Canvas_Scale
 * @see OH_Canvas_Translate
 * @see OH_Canvas_Transform
 * @since 26.1.0
 */
void OH_Canvas_Rotate(uint32_t canvas, float angle);

/**
 * @brief Translates a canvas.
 *
 * Applies translation transformation to a canvas. In practice, this is usually used to change the center point of the
 * transformation method.
 * All subsequent drawing operations are based on this translated coordinate system.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param x Translation distance along the X axis, in pixels. A positive value indicates a rightward movement,
 *          while a negative value indicates a leftward movement.
 * @param y Translation distance along the Y axis, in pixels. A positive value indicates a downward movement,
 *          while a negative value indicates an upward movement.
 * @return No return value (**void**).
 * @see OH_Canvas_Scale
 * @see OH_Canvas_Rotate
 * @see OH_Canvas_Transform
 * @since 26.1.0
 */
void OH_Canvas_Translate(uint32_t canvas, float x, float y);

/**
 * @brief Applies a 2D affine transformation matrix to the canvas.
 * The transformation is right-multiplied with the existing transformation matrix
 * (i.e., the existing transformation is applied first, then the new transformation)
 * to achieve scaling, rotation, stretching, or translation effects.
 *
 * Transformation matrix format (row-major):
 * | scaleX  shearX  translateX |
 * | shearY  scaleY  translateY |
 * | 0       0       1          |
 *
 * @param canvas [in] Canvas handle, must not be 0.
 * @param scaleX [in] Horizontal scale factor.
 * @param shearX [in] Horizontal shear factor.
 * @param shearY [in] Vertical shear factor.
 * @param scaleY [in] Vertical scale factor.
 * @param translateX [in] Horizontal translation distance.
 * @param translateY [in] Vertical translation distance.
 * @return No return value (void).
 * @see OH_Canvas_SetTransform
 * @see OH_Canvas_Save
 * @see OH_Canvas_Restore
 * @since 26.1.0
 */
void OH_Canvas_Transform(uint32_t canvas, float scaleX, float shearX, float shearY, float scaleY,
                         float translateX, float translateY);

/**
 * @brief Resets the canvas transformation matrix.
 *
 * Unlike OH_Canvas_Transform, this function completely resets the existing transformation,
 * whereas OH_Canvas_Transform accumulates transformations.
 *
 * Transformation matrix format (row-major):
 * | scaleX  shearX  translateX |
 * | shearY  scaleY  translateY |
 * | 0       0       1          |
 *
 * @param canvas [in] Canvas handle, must not be 0.
 * @param scaleX [in] Horizontal scale factor.
 * @param shearX [in] Horizontal shear factor.
 * @param shearY [in] Vertical shear factor.
 * @param scaleY [in] Vertical scale factor.
 * @param translateX [in] Horizontal translation distance.
 * @param translateY [in] Vertical translation distance.
 * @return No return value (void).
 * @see OH_Canvas_Transform
 * @see OH_Canvas_Save
 * @see OH_Canvas_Restore
 * @since 26.1.0
 */
void OH_Canvas_SetTransform(uint32_t canvas, float scaleX, float shearX, float shearY, float scaleY,
                            float translateX, float translateY);

/**
 * @brief Sets the font style for a canvas.
 *
 * This function is used to configure the font for subsequent text rendering operations.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param fontName Font name. The font can be a system font or a custom font registered in the system.
 *                 The following system font names and corresponding languages are supported:
 *                    - Simplified Chinese and traditional Chinese: HarmonyOSHans-Medium.ttf
 *                    - English: HarmonyOSCondensed-Regular.ttf
 * @param fontSize Font size, in pixels. The value ranges from 0 to 255.
 * @return No return value (**void**).
 * @see OH_Canvas_FillText
 * @see OH_Canvas_StrokeText
 * @see OH_Canvas_MeasureText
 * @since 26.1.0
 */
void OH_Canvas_SetFont(uint32_t canvas, const char *fontName, uint32_t fontSize);

/**
 * @brief Sets the text alignment mode.
 *
 * Sets the horizontal and vertical alignment modes for text rendering.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param horizontalAlign Horizontal alignment mode, which affects left alignment, right alignment, and center
 *                         alignment. The default mode is left alignment.
 * @param verticalAlign Vertical alignment mode, which affects top alignment, bottom alignment, and center alignment.
 *                      The default mode is top alignment.
 * @return No return value (**void**).
 * @since 26.1.0
 */
void OH_Canvas_SetTextAlign(uint32_t canvas, OH_Canvas_TextAlign horizontalAlign, OH_Canvas_TextAlign verticalAlign);

/**
 * @brief Renders the filled text at the specified canvas coordinates using the current font and fill style.
 *
 * The coordinate origin is located at the upper left corner of the canvas, and the Y axis points downward.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param text Text content to be filled, which cannot be **NULL** or empty.
 Note: The text string cannot exceed 4,096 characters. Otherwise, the rendering fails.
 * @param x X coordinate of the upper left corner of the text, relative to the upper left corner of the canvas.
 * @param y Y coordinate of the upper left corner of the text, relative to the upper left corner of the canvas.
 * @return No return value (**void**).
 * @see OH_Canvas_SetFont
 * @see OH_Canvas_StrokeText
 * @since 26.1.0
 */
void OH_Canvas_FillText(uint32_t canvas, const char *text, int16_t x, int16_t y);

/**
 * @brief Renders the stroked text at the specified canvas coordinates using the current font and stroke style.
 *
 * The coordinate origin is located at the upper left corner of the canvas, and the Y axis points downward.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param text Text content to be stroked, which cannot be **NULL** or empty.
 Note: The text string cannot exceed 4,096 characters. Otherwise, the rendering fails.
 * @param x X coordinate of the upper left corner of the text, relative to the upper left corner of the canvas.
 * @param y Y coordinate of the upper left corner of the text, relative to the upper left corner of the canvas.
 * @return No return value (**void**).
 * @see OH_Canvas_SetFont
 * @see OH_Canvas_FillText
 * @since 26.1.0
 */
void OH_Canvas_StrokeText(uint32_t canvas, const char *text, int16_t x, int16_t y);

/**
 * @brief Measures the text width and height.
 *
 * Calculates the size of the specified text using the current font.
 * In the returned struct, **x** indicates the text width (in pixels), and **y** indicates the text height (in pixels).
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param text Text content to be measured, which cannot be **NULL** or empty.
 Note: The text string cannot exceed 4,096 characters. Otherwise, the measurement fails.
 * @return **OH_Canvas_TextPos** struct that contains the text size, where **x** indicates the width and **y**
 *         indicates the height. If the operation fails, **0** is returned.
 * @see OH_Canvas_TextPos
 * @since 26.1.0
 */
OH_Canvas_TextPos OH_Canvas_MeasureText(uint32_t canvas, const char *text);

/**
 * @brief Loads image data from a specified file path and automatically allocates the required memory space.
 *
 * Reads an image file and returns the filled **OH_Canvas_ImageInfo** struct.
 * The returned struct contains the image header and pixel data.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param imagePath Image file path. The path can be an absolute path or a relative path. The value cannot be **NULL**.
 *                  Note: The path string cannot exceed 4,096 characters. Otherwise,
 *                  a buffer overflow may occur or the loading may fail.
 * @return **OH_Canvas_ImageInfo** struct containing the image data if the operation is successful;
 *          **NULL** if the operation fails.
 * @release canvas/OH_Canvas_FreeImageData {return}
 * @since 26.1.0
 */
OH_Canvas_ImageInfo *OH_Canvas_LoadImagePath(uint32_t canvas, const char *imagePath);

/**
 * @brief Draws an image. Renders an image at the specified canvas coordinates with its original size.
 *
 * The coordinate origin is located at the upper left corner of the canvas, and the Y axis points downward.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param image Image to be drawn. The image must be valid and successfully loaded.
 * @param dx Target X coordinate, relative to the upper left corner of the canvas.
 * @param dy Target Y coordinate, relative to the upper left corner of the canvas.
 * @return No return value (**void**).
 * @see OH_Canvas_DrawImage_Size
 * @see OH_Canvas_DrawImage_Area
 * @since 26.1.0
 */
void OH_Canvas_DrawImage_Position(uint32_t canvas, const OH_Canvas_ImageInfo *image, int16_t dx, int16_t dy);

/**
 * @brief Renders an image at the specified canvas coordinates, scaled to fit the target dimensions.
 *
 * The coordinate origin is at the top-left corner of the canvas, with the Y-axis pointing downward.
 * @param canvas [in] Canvas handle, must not be 0.
 * @param image [in] The image to draw. Must be valid and successfully loaded.
 * @param dstRect [in] Target rectangle specifying the position and dimensions.
 * @return No return value (void).
 * @see OH_Canvas_DrawImage_Position
 * @see OH_Canvas_DrawImage_Area
 * @since 26.1.0
 */
void OH_Canvas_DrawImage_Size(uint32_t canvas, const OH_Canvas_ImageInfo *image, OH_Canvas_Rect dstRect);

/**
 * @brief Renders a specified rectangular area of the image at the specified canvas rendering area,
 * scaling the image region to fit the target dimensions.
 *
 * The coordinate origin is at the top-left corner of the canvas, with the Y-axis pointing downward.
 * @param canvas [in] Canvas handle, must not be 0.
 * @param image [in] The image to draw. Must be valid and successfully loaded.
 * @param srcRect [in] Source rectangle specifying the image region to draw.
 * @param dstRect [in] Target rectangle specifying the canvas position and dimensions.
 * @return No return value (void).
 * @see OH_Canvas_DrawImage_Position
 * @see OH_Canvas_DrawImage_Size
 * @since 26.1.0
 */
void OH_Canvas_DrawImage_Area(uint32_t canvas, const OH_Canvas_ImageInfo *image, OH_Canvas_Rect srcRect,
    OH_Canvas_Rect dstRect);

/**
 * @brief Creates image data.
 *
 * Allocates a new image data buffer with the specified size.
 * The image data is initialized to transparent black.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param sw Image width, in pixels.
 * @param sh Image height, in pixels.
 * @return **OH_Canvas_ImageInfo** struct containing the image data if the operation is successful;
 *          **NULL** if the operation fails.
 * @release canvas/OH_Canvas_FreeImageData {return}
 * @since 26.1.0
 */
OH_Canvas_ImageInfo *OH_Canvas_CreateImageData(uint32_t canvas, uint16_t sw, uint16_t sh);

/**
 * @brief Releases image data.
 *
 * After this function is called, the **OH_Canvas_ImageInfo** struct should not be used again.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param image Image data to be released.
 * @return No return value (**void**).
 * @see OH_Canvas_CreateImageData
 * @since 26.1.0
 */
void OH_Canvas_FreeImageData(uint32_t canvas, OH_Canvas_ImageInfo *image);

/**
 * @brief Gets image data from the canvas.
 *
 * Copies the pixel data of the specified canvas area into an uint32_t structure.
 * The coordinate origin is at the top-left corner of the canvas, with the Y-axis pointing downward.
 * @param canvas [in] Canvas handle, must not be 0.
 * @param srcRect [in] Source rectangle specifying the image region to draw.
 * @return Returns an OH_Canvas_ImageInfo * structure containing image data on success;
 *         returns NULL data on failure.
 * @release canvas/OH_Canvas_FreeImageData {return}
 * @see OH_Canvas_PutImageData
 * @since 26.1.0
 */
OH_Canvas_ImageInfo* OH_Canvas_GetImageData(uint32_t canvas, OH_Canvas_Rect srcRect);

/**
 * @brief Draws image data at the specified canvas coordinates and renders the canvas.
 *
 * The coordinate origin is located at the upper left corner of the canvas, and the Y axis points downward.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param image Data of the image to be drawn. The image must be valid and successfully loaded.
 * @param dx Target X coordinate, relative to the upper left corner of the canvas.
 * @param dy Target Y coordinate, relative to the upper left corner of the canvas.
 * @return No return value (**void**).
 * @see OH_Canvas_GetImageData
 * @see OH_Canvas_PutImageData_Area
 * @since 26.1.0
 */
void OH_Canvas_PutImageData(uint32_t canvas, const OH_Canvas_ImageInfo *image, int16_t dx, int16_t dy);

/**
 * @brief Draws data from a specified area of the image at the specified canvas coordinates
 * and renders the canvas.
 *
 * The coordinate origin is at the top-left corner of the canvas, with the Y-axis pointing downward.
 * @param canvas [in] Canvas handle, must not be 0.
 * @param image [in] The image data to draw. Must be valid and successfully loaded.
 * @param dx [in] Target X-coordinate, relative to the canvas top-left corner.
 * @param dy [in] Target Y-coordinate, relative to the canvas top-left corner.
 * @param srcRect [in] Source rectangle specifying the image region to draw.
 * @return No return value (void).
 * @see OH_Canvas_PutImageData
 * @see OH_Canvas_GetImageData
 * @since 26.1.0
 */
void OH_Canvas_PutImageData_Area(uint32_t canvas, const OH_Canvas_ImageInfo *image, int16_t dx, int16_t dy,
    OH_Canvas_Rect srcRect);

/**
 * @brief Clips a rectangular area of the canvas.
 *
 * Sets the clipping area to the specified rectangle.
 * Only pixels within the clipping area will be affected by subsequent drawing operations.
 * If a clipping area already exists, it is directly replaced with the new area.
 * The clipping area cannot exceed the canvas boundaries.
 * The coordinate origin is at the top-left corner of the canvas, with the Y-axis pointing downward.
 * @param canvas [in] Canvas handle, must not be 0.
 * @param rect [in] Rectangle structure containing the clipping area coordinates and dimensions.
 * @return No return value (void).
 * @see OH_Canvas_Save
 * @see OH_Canvas_Restore
 * @since 26.1.0
 */
void OH_Canvas_ClipRect(uint32_t canvas, OH_Canvas_Rect rect);

/**
 * @brief Sets the global opacity.
 *
 * This function sets the global opacity for all subsequent drawing operations.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param alpha Opacity value, ranging from 0 (completely transparent) to 255 (completely opaque).
 *              The default value is **255**.
 * @return No return value (**void**).
 * @since 26.1.0
 */
void OH_Canvas_SetGlobalAlpha(uint32_t canvas, uint8_t alpha);

/**
 * @brief Sets the global blending operation.
 *
 * Sets the blend mode for image compositing on the canvas.
 * The blend mode determines how the newly drawn image (source) is combined with the existing image (target).
 *
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param operation Enumerated value of the blending operation. The default value is **OH_BLEND_TYPE_SRCOVER**.
 * @return No return value (**void**).
 * @see OH_Canvas_BlendType
 * @since 26.1.0
 */
void OH_Canvas_SetGlobalCompositeOperation(uint32_t canvas, OH_Canvas_BlendType operation);

/**
 * @brief Sets the canvas width.
 *
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param width Canvas width, in pixels. The recommended value range is 1 to 600.
 * @return No return value (**void**).
 * @see OH_Canvas_GetWidth
 * @see OH_Canvas_SetHeight
 * @since 26.1.0
 */
void OH_Canvas_SetWidth(uint32_t canvas, uint32_t width);

/**
 * @brief Obtains the canvas width.
 *
 * Returns the current width of the canvas rendering surface.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @return Canvas width, in pixels.
 *         If **canvas** is set to **0** or invalid, the return value may be **0**.
 *         You are advised to ensure that the input canvas handle is valid.
 * @see OH_Canvas_SetWidth
 * @since 26.1.0
 */
uint32_t OH_Canvas_GetWidth(uint32_t canvas);

/**
 * @brief Sets the canvas height.
 *
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @param height Canvas height, in pixels. The recommended value range is 1 to 600.
 * @return No return value (**void**).
 * @see OH_Canvas_GetHeight
 * @see OH_Canvas_SetWidth
 * @since 26.1.0
 */
void OH_Canvas_SetHeight(uint32_t canvas, uint32_t height);

/**
 * @brief Obtains the canvas height.
 *
 * Returns the current height of the canvas rendering surface.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @return Canvas height, in pixels.
 *         If **canvas** is set to **0** or invalid, the return value may be **0**.
 *         You are advised to ensure that the input canvas handle is valid.
 * @see OH_Canvas_SetHeight
 * @since 26.1.0
 */
uint32_t OH_Canvas_GetHeight(uint32_t canvas);

/**
 * @brief Saves the current canvas state.
 *
 * The state includes the transformation matrix, cropping region, and style settings.
 * You can use **OH_Canvas_Restore** to restore the saved state.
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @return No return value (**void**).
 * @see OH_Canvas_Restore
 * @since 26.1.0
 */
void OH_Canvas_Save(uint32_t canvas);

/**
 * @brief Restores the previously saved canvas state.
 *
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @return No return value (**void**).
 * @see OH_Canvas_Save
 * @since 26.1.0
 */
void OH_Canvas_Restore(uint32_t canvas);

/**
 * @brief Clears the canvas content.
 *
 * Resets the entire canvas to transparent black.
 * All drawing content will be removed.
 * This operation does not clear the saved canvas state (such as the transformation matrix, cropping region,
 * and style settings).
 * @param canvas Canvas handle, the value of which cannot be **0**.
 * @return No return value (**void**).
 * @since 26.1.0
 */
void OH_Canvas_Clear(uint32_t canvas);

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CANVAS_API_H */