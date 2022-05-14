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

#include "health bar2.h"
#include "animation.h"

bool HealthBar2_load(SDL_Renderer *renderer, HealthBar2 *healthBar2, const char *image)
{
    // Load healthBar2 image
    if(!Image_load(renderer, &healthBar2->image, image))
    {

        return false;
    }
    return true;
}

void HealthBar2_destroy(HealthBar2 *healthBar2)
{
    Image_destroy(&healthBar2->image);

}

void HealthBar2_setX(HealthBar2 *healthBar2, int x)
{
    // HealthBar2 x coordinate
      healthBar2->image.rect.x = x;

}

void HealthBar2_setY(HealthBar2 *healthBar2, int y)
{
    // HealthBar2 y coordinate
    healthBar2->image.rect.y = y;

}
void HealthBar2_setCoordinates(HealthBar2 *healthBar2, int x, int y)
{
    HealthBar2_setX(healthBar2, x);
    HealthBar2_setY(healthBar2, y);
}


void HealthBar2_render(SDL_Renderer *renderer, HealthBar2 *healthBar2)
{

     Image_render(renderer, &healthBar2->image);

}

