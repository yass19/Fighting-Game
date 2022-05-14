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

#ifndef BALL2_H
#define BALL2_H

#include "utils.h"
#include "image.h"
typedef struct Animation Animation;

struct Ball2
{
    // Ball
    Image imageball2;
    bool shown ;

    // Shadow
    Image shadow;
    SDL_Point shadowOffset;

    // Direction
    Direction direction;

    // Speed in pixel/second
    int speed;

    // Margin
    int margin;
};
typedef struct Ball2 Ball2;


bool Ball2_load(SDL_Renderer *renderer, Ball2 *ball2, const char *image);
void Ball2_destroy(Ball2 *ball2);

void Ball2_setX(Ball2 *ball2, int x);
void Ball2_setY(Ball2 *ball2, int y);
void Ball2_setCoordinates(Ball2 *ball2, int x, int y);

void Ball2_moveX(Ball2 *ball2, int x);
void Ball2_moveY(Ball2 *ball2, int y);

void Ball2_move(Ball2 *ball2, int screenWidth, int screenHeight, int framerate,Animation *animation);

void Ball2_setDirection(Ball2 *ball2, SDL_Keycode keycode);
void Ball2_unsetDirection(Ball2 *ball2,SDL_Keycode keycode);


void Ball2_render(SDL_Renderer *renderer, Ball2 *ball2);



#endif // BALL2_H
