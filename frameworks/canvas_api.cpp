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

#include "canvas_api.h"

uint32_t OH_Canvas_CreateHandle(const char *componentId, const char *invokeCallbackName, bool offScreenRender)
{
    (void)componentId;
    (void)invokeCallbackName;
    (void)offScreenRender;
    return 0;
}

void OH_Canvas_DestroyHandle(uint32_t canvas)
{
    (void)canvas;
}

void OH_Canvas_FillStyle_Color(uint32_t canvas, uint32_t color)
{
    (void)canvas;
    (void)color;
}

void OH_Canvas_StrokeStyle_Color(uint32_t canvas, uint32_t color)
{
    (void)canvas;
    (void)color;
}

void OH_Canvas_SetLineWidth(uint32_t canvas, uint16_t width)
{
    (void)canvas;
    (void)width;
}

void OH_Canvas_SetLineCap(uint32_t canvas, OH_Canvas_LineCapType cap)
{
    (void)canvas;
    (void)cap;
}

void OH_Canvas_SetLineJoin(uint32_t canvas, OH_Canvas_LineJoinType join)
{
    (void)canvas;
    (void)join;
}

void OH_Canvas_SetMiterLimit(uint32_t canvas, float limit)
{
    (void)canvas;
    (void)limit;
}

void OH_Canvas_BuildRect(uint32_t canvas, OH_Canvas_Rect rect)
{
    (void)canvas;
    (void)rect;
}

void OH_Canvas_FillRect(uint32_t canvas, OH_Canvas_Rect rect)
{
    (void)canvas;
    (void)rect;
}

void OH_Canvas_StrokeRect(uint32_t canvas, OH_Canvas_Rect rect)
{
    (void)canvas;
    (void)rect;
}

void OH_Canvas_ClearRect(uint32_t canvas, OH_Canvas_Rect rect)
{
    (void)canvas;
    (void)rect;
}

void OH_Canvas_Fill(uint32_t canvas)
{
    (void)canvas;
}

void OH_Canvas_Stroke(uint32_t canvas)
{
    (void)canvas;
}

void OH_Canvas_BeginPath(uint32_t canvas)
{
    (void)canvas;
}

void OH_Canvas_ClosePath(uint32_t canvas)
{
    (void)canvas;
}

void OH_Canvas_MoveTo(uint32_t canvas, float x, float y)
{
    (void)canvas;
    (void)x;
    (void)y;
}

void OH_Canvas_LineTo(uint32_t canvas, float x, float y)
{
    (void)canvas;
    (void)x;
    (void)y;
}

void OH_Canvas_QuadraticCurveTo(uint32_t canvas, float cpx, float cpy, float x, float y)
{
    (void)canvas;
    (void)cpx;
    (void)cpy;
    (void)x;
    (void)y;
}

void OH_Canvas_BezierCurveTo(uint32_t canvas, float cp1x, float cp1y, float cp2x, float cp2y, float x, float y)
{
    (void)canvas;
    (void)cp1x;
    (void)cp1y;
    (void)cp2x;
    (void)cp2y;
    (void)x;
    (void)y;
}

void OH_Canvas_ArcTo(uint32_t canvas, float x1, float y1, float x2, float y2, float radius)
{
    (void)canvas;
    (void)x1;
    (void)y1;
    (void)x2;
    (void)y2;
    (void)radius;
}

void OH_Canvas_Arc(uint32_t canvas, float x, float y, float r, float start, float end, bool anticlockwise)
{
    (void)canvas;
    (void)x;
    (void)y;
    (void)r;
    (void)start;
    (void)end;
    (void)anticlockwise;
}

void OH_Canvas_Scale(uint32_t canvas, float scaleX, float scaleY)
{
    (void)canvas;
    (void)scaleX;
    (void)scaleY;
}

void OH_Canvas_Rotate(uint32_t canvas, float angle)
{
    (void)canvas;
    (void)angle;
}

void OH_Canvas_Translate(uint32_t canvas, float x, float y)
{
    (void)canvas;
    (void)x;
    (void)y;
}

void OH_Canvas_Transform(uint32_t canvas, float scaleX, float shearX, float shearY, float scaleY,
                         float translateX, float translateY)
{
    (void)canvas;
    (void)scaleX;
    (void)shearX;
    (void)shearY;
    (void)scaleY;
    (void)translateX;
    (void)translateY;
}

void OH_Canvas_SetTransform(uint32_t canvas, float scaleX, float shearX, float shearY, float scaleY,
                            float translateX, float translateY)
{
    (void)canvas;
    (void)scaleX;
    (void)shearX;
    (void)shearY;
    (void)scaleY;
    (void)translateX;
    (void)translateY;
}

void OH_Canvas_SetFont(uint32_t canvas, const char *fontName, uint32_t fontSize)
{
    (void)canvas;
    (void)fontName;
    (void)fontSize;
}

void OH_Canvas_SetTextAlign(uint32_t canvas, OH_Canvas_TextAlign horizontalAlign, OH_Canvas_TextAlign verticalAlign)
{
    (void)canvas;
    (void)horizontalAlign;
    (void)verticalAlign;
}

void OH_Canvas_FillText(uint32_t canvas, const char *text, int16_t x, int16_t y)
{
    (void)canvas;
    (void)text;
    (void)x;
    (void)y;
}

void OH_Canvas_StrokeText(uint32_t canvas, const char *text, int16_t x, int16_t y)
{
    (void)canvas;
    (void)text;
    (void)x;
    (void)y;
}

OH_Canvas_TextPos OH_Canvas_MeasureText(uint32_t canvas, const char *text)
{
    (void)canvas;
    (void)text;
    OH_Canvas_TextPos pos = {};
    return pos;
}

OH_Canvas_ImageInfo *OH_Canvas_LoadImagePath(uint32_t canvas, const char *imagePath)
{
    (void)canvas;
    (void)imagePath;
    return nullptr;
}

void OH_Canvas_DrawImage_Position(uint32_t canvas, const OH_Canvas_ImageInfo *image, int16_t dx, int16_t dy)
{
    (void)canvas;
    (void)image;
    (void)dx;
    (void)dy;
}

void OH_Canvas_DrawImage_Size(uint32_t canvas, const OH_Canvas_ImageInfo *image, OH_Canvas_Rect dstRect)
{
    (void)canvas;
    (void)image;
    (void)dstRect;
}

void OH_Canvas_DrawImage_Area(uint32_t canvas, const OH_Canvas_ImageInfo *image, OH_Canvas_Rect srcRect,
                              OH_Canvas_Rect dstRect)
{
    (void)canvas;
    (void)image;
    (void)srcRect;
    (void)dstRect;
}

OH_Canvas_ImageInfo *OH_Canvas_CreateImageData(uint32_t canvas, uint16_t sw, uint16_t sh)
{
    (void)canvas;
    (void)sw;
    (void)sh;
    return nullptr;
}

void OH_Canvas_FreeImageData(uint32_t canvas, OH_Canvas_ImageInfo *image)
{
    (void)canvas;
    (void)image;
}

OH_Canvas_ImageInfo* OH_Canvas_GetImageData(uint32_t canvas, OH_Canvas_Rect srcRect)
{
    (void)canvas;
    (void)srcRect;
    return nullptr;
}

void OH_Canvas_PutImageData(uint32_t canvas, const OH_Canvas_ImageInfo *image, int16_t dx, int16_t dy)
{
    (void)canvas;
    (void)image;
    (void)dx;
    (void)dy;
}

void OH_Canvas_PutImageData_Area(uint32_t canvas, const OH_Canvas_ImageInfo *image, int16_t dx, int16_t dy,
                                 OH_Canvas_Rect srcRect)
{
    (void)canvas;
    (void)image;
    (void)dx;
    (void)dy;
    (void)srcRect;
}

void OH_Canvas_ClipRect(uint32_t canvas, OH_Canvas_Rect rect)
{
    (void)canvas;
    (void)rect;
}

void OH_Canvas_SetGlobalAlpha(uint32_t canvas, uint8_t alpha)
{
    (void)canvas;
    (void)alpha;
}

void OH_Canvas_SetGlobalCompositeOperation(uint32_t canvas, OH_Canvas_BlendType operation)
{
    (void)canvas;
    (void)operation;
}

void OH_Canvas_SetWidth(uint32_t canvas, uint32_t width)
{
    (void)canvas;
    (void)width;
}

uint32_t OH_Canvas_GetWidth(uint32_t canvas)
{
    (void)canvas;
    return 0;
}

void OH_Canvas_SetHeight(uint32_t canvas, uint32_t height)
{
    (void)canvas;
    (void)height;
}

uint32_t OH_Canvas_GetHeight(uint32_t canvas)
{
    (void)canvas;
    return 0;
}

void OH_Canvas_Save(uint32_t canvas)
{
    (void)canvas;
}

void OH_Canvas_Restore(uint32_t canvas)
{
    (void)canvas;
}

void OH_Canvas_Clear(uint32_t canvas)
{
    (void)canvas;
}