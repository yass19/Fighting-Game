/*
 * Copyright (c) 2018 Amine Ben Hassouna <amine.benhassouna@gmail.com>
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any
 * person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the
 * Software without restriction, including without
 * limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice
 * shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
 * ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 * IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef PIC2_H
#define PIC2_H

#include "utils.h"
#include "image.h"
typedef struct Animation Animation;
struct Pic2
{
    // Pic2
    Image image;


    // Direction
    Direction direction;

    // Margin
    int margin;


};
typedef struct Pic2 Pic2;


bool Pic2_load(SDL_Renderer *renderer, Pic2 *pic2, const char *image );
void Pic2_destroy(Pic2 *pic2);

void Pic2_setX(Pic2 *pic2, int x);
void Pic2_setY(Pic2 *pic2, int y);
void Pic2_setCoordinates(Pic2 *pic2, int x, int y);

void Pic2_render(SDL_Renderer *renderer, Pic2 *pic2);




#endif // PIC2_H
