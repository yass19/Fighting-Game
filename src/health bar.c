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

#include "health bar.h"
#include "animation.h"

bool HealthBar_load(SDL_Renderer *renderer, HealthBar *healthBar, const char *image)
{
    // Load healthBar image
    if(!Image_load(renderer, &healthBar->image, image))
    {

        return false;
    }
    return true;
}

void HealthBar_destroy(HealthBar *healthBar)
{
    Image_destroy(&healthBar->image);

}

void HealthBar_setX(HealthBar *healthBar, int x)
{
    // HealthBar x coordinate
      healthBar->image.rect.x = x;

}

void HealthBar_setY(HealthBar *healthBar, int y)
{
    // HealthBar y coordinate
    healthBar->image.rect.y = y;

}
void HealthBar_setCoordinates(HealthBar *healthBar, int x, int y)
{
    HealthBar_setX(healthBar, x);
    HealthBar_setY(healthBar, y);
}


void HealthBar_render(SDL_Renderer *renderer, HealthBar *healthBar)
{
    //if(healthBar->kick==false && healthBar->push==false)
     //{
     Image_render(renderer, &healthBar->image);
     //}
     //Render healthBar ball
     //else if(healthBar->push == true)
      //{
       //  Image_render(renderer, &healthBar->imagepush);
     //}

     //else if(healthBar->kick == true)
      //{
        // Image_render(renderer, &healthBar->imagekick);
     //}



}

