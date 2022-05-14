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

#ifndef HEALTHBAR2_H
#define HEALTHBAR2_H

#include "utils.h"
#include "image.h"
typedef struct Animation Animation;
struct HealthBar2
{
    // HealthBar2
    Image image;


    // Direction
    Direction direction;

    // Margin
    int margin;


};
typedef struct HealthBar2 HealthBar2;


bool HealthBar2_load(SDL_Renderer *renderer, HealthBar2 *healthBar2, const char *image );
void HealthBar2_destroy(HealthBar2 *healthBar2);

void HealthBar2_setX(HealthBar2 *healthBar2, int x);
void HealthBar2_setY(HealthBar2 *healthBar2, int y);
void HealthBar2_setCoordinates(HealthBar2 *healthBar2, int x, int y);

void HealthBar2_render(SDL_Renderer *renderer, HealthBar2 *healthBar2);




#endif // HEALTHBAR2_H
