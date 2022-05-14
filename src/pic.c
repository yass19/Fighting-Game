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

#include "pic.h"
#include "animation.h"

bool Pic_load(SDL_Renderer *renderer, Pic *pic, const char *image)
{
    // Load pic image
    if(!Image_load(renderer, &pic->image, image))
    {

        return false;
    }
    return true;
}

void Pic_destroy(Pic *pic)
{
    Image_destroy(&pic->image);

}

void Pic_setX(Pic *pic, int x)
{
    // Pic x coordinate
      pic->image.rect.x = x;

}

void Pic_setY(Pic *pic, int y)
{
    // Pic y coordinate
    pic->image.rect.y = y;

}
void Pic_setCoordinates(Pic *pic, int x, int y)
{
    Pic_setX(pic, x);
    Pic_setY(pic, y);
}


void Pic_render(SDL_Renderer *renderer, Pic *pic)
{
    //if(pic->kick==false && pic->push==false)
     //{
     Image_render(renderer, &pic->image);
     //}
     //Render pic ball
     //else if(pic->push == true)
      //{
       //  Image_render(renderer, &pic->imagepush);
     //}

     //else if(pic->kick == true)
      //{
        // Image_render(renderer, &pic->imagekick);
     //}



}

