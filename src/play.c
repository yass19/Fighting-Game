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

#include "play.h"
#include "menu.h"

bool Play_load(SDL_Renderer *renderer, Play  *play, const char *image)
{
    // Load play image
    if(!Image_load(renderer, &play->image, image))
    {

        return false;
    }
    return true;
}

void Play_destroy(Play  *play)
{
    Image_destroy(&play->image);

}

void Play_setX(Play  *play, int x)
{
    // Play x coordinate
      play->image.rect.x = x;

}

void Play_setY(Play  *play, int y)
{
    // Play y coordinate
    play->image.rect.y = y;

}
void Play_setCoordinates(Play  *play, int x, int y)
{
    Play_setX(play, x);
    Play_setY(play, y);
}


void Play_render(SDL_Renderer *renderer, Play  *play)
{
     Image_render(renderer, &play->image);



}

