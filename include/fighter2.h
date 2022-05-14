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

#ifndef FIGHTER2_H
#define FIGHTER2_H

#include "utils.h"
#include "image.h"
typedef struct Animation Animation;
struct Fighter2
{
    // Fighter2
    Image image;
    Image imagepush ;
    Image imagekick;

    bool push ;
    bool kick ;


    // Shadow
    Image shadow;
    SDL_Point shadowOffset;

    // Direction
    Direction direction;

    // Speed in pixel/second
    int speed;

    // Margin
    int margin;
    bool destroyed ;
};
typedef struct Fighter2 Fighter2;



bool Fighter2_load(SDL_Renderer *renderer, Fighter2 *fighter2, const char *image,const char *imagepush,const char *imagekick);
void Fighter2_setDirection( Fighter2 *fighter2, SDL_Keycode keycode);
void Fighter2_unsetDirection(Fighter2 *fighter2, SDL_Keycode keycode);
void Fighter2_destroy(Fighter2 *fighter2);

void Fighter2_setX(Fighter2 *fighter2, int x);
void Fighter2_setY(Fighter2 *fighter2, int y);
void Fighter2_setCoordinates(Fighter2 *fighter2, int x, int y);

void Fighter2_moveX(Fighter2 *fighter2, int x);
void Fighter2_moveY(Fighter2 *fighter2, int y);

void Fighter2_move(Fighter2 *fighter2, int screenWidth, int screenHeight, int framerate,Animation *animation);
void Fighter2_render(SDL_Renderer *renderer, Fighter2 *fighter2);


#endif // FIGHTER2_H
