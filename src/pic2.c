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

#include "pic2.h"
#include "animation.h"

bool Pic2_load(SDL_Renderer *renderer, Pic2 *pic2, const char *image)
{
    // Load pic2 image
    if(!Image_load(renderer, &pic2->image, image))
    {

        return false;
    }
    return true;
}

void Pic2_destroy(Pic2 *pic2)
{
    Image_destroy(&pic2->image);

}

void Pic2_setX(Pic2 *pic2, int x)
{
    // Pic2 x coordinate
      pic2->image.rect.x = x;

}

void Pic2_setY(Pic2 *pic2, int y)
{
    // Pic2 y coordinate
    pic2->image.rect.y = y;

}
void Pic2_setCoordinates(Pic2 *pic2, int x, int y)
{
    Pic2_setX(pic2, x);
    Pic2_setY(pic2, y);
}


void Pic2_render(SDL_Renderer *renderer, Pic2 *pic2)
{
    //if(pic2->kick==false && pic2->push==false)
     //{
     Image_render(renderer, &pic2->image);
     //}
     //Render pic2 ball
     //else if(pic2->push == true)
      //{
       //  Image_render(renderer, &pic2->imagepush);
     //}

     //else if(pic2->kick == true)
      //{
        // Image_render(renderer, &pic2->imagekick);
     //}



}

