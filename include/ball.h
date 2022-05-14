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

#ifndef BALL_H
#define BALL_H

#include "utils.h"
#include "image.h"
typedef struct Animation Animation;

struct Ball
{
    // Ball
    Image imageball;
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
typedef struct Ball Ball;


bool Ball_load(SDL_Renderer *renderer, Ball *ball, const char *image);
void Ball_destroy(Ball *ball);

void Ball_setX(Ball *ball, int x);
void Ball_setY(Ball *ball, int y);
void Ball_setCoordinates(Ball *ball, int x, int y);

void Ball_moveX(Ball *ball, int x);
void Ball_moveY(Ball *ball, int y);

void Ball_move(Ball *ball, int screenWidth, int screenHeight, int framerate,Animation *animation);

void Ball_setDirection(Ball *ball, SDL_Keycode keycode);
void Ball_unsetDirection(Ball *ball,SDL_Keycode keycode);


void Ball_render(SDL_Renderer *renderer, Ball *ball);



#endif // BALL_H
