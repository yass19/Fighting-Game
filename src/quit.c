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

#include "quit.h"
#include "animation.h"

bool Quit_load(SDL_Renderer *renderer, Quit *quit, const char *image)
{
    // Load quit image
    if(!Image_load(renderer, &quit->image, image))
    {

        return false;
    }
    return true;
}

void Quit_destroy(Quit *quit)
{
    Image_destroy(&quit->image);

}

void Quit_setX(Quit *quit, int x)
{
    // Quit x coordinate
      quit->image.rect.x = x;

}

void Quit_setY(Quit *quit, int y)
{
    // Quit y coordinate
    quit->image.rect.y = y;

}
void Quit_setCoordinates(Quit *quit, int x, int y)
{
    Quit_setX(quit, x);
    Quit_setY(quit, y);
}


void Quit_render(SDL_Renderer *renderer, Quit *quit)
{

     Image_render(renderer, &quit->image);




}

