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

#include "ball.h"
#include "animation.h"

bool Ball_load(SDL_Renderer *renderer, Ball *ball, const char *image)
{
    // Load ball image
    if(!Image_load(renderer, &ball->imageball, image))
    {
        return false;
    }
    ball->shown=false;

    return true;
}

void Ball_destroy(Ball *ball)
{

    Image_destroy(&ball->imageball);
    Image_destroy(&ball->shadow);
}

void Ball_setX(Ball *ball, int x)
{
    // Ball x coordinate
    ball->imageball.rect.x =x;

    // Ball shadow x coordinate
    ball->shadow.rect.x = ball->imageball.rect.x
                            + (ball->imageball.rect.w - ball->shadow.rect.w) / 2
                            + ball->shadowOffset.x;
}

void Ball_setY(Ball *ball, int y)
{
    // Ball y coordinate
    ball->imageball.rect.y = y-150;

    // Ball shadow y coordinate
    ball->shadow.rect.y = ball->imageball.rect.y
                            + (ball->imageball.rect.h - ball->shadow.rect.h) / 2
                            + ball->shadowOffset.y;
}

void Ball_setCoordinates(Ball *ball, int x, int y)
{
    Ball_setX(ball, x);
    Ball_setY(ball, y);
}

void Ball_moveX(Ball *ball, int x)
{
    Ball_setX(ball, ball->imageball.rect.x + x);
}

void Ball_moveY(Ball *ball, int y)
{
    Ball_setY(ball, ball->imageball.rect.y + y);
}

void Ball_setDirection(Ball *ball, SDL_Keycode keycode)
{
    switch (keycode)
    {

    case SDLK_SPACE:

        ball->direction &= ~SDLK_LEFT;
        ball->direction |= DIRECTION_RIGHT;
        break;
    }
}

void Ball_unsetDirection(Ball *ball, SDL_Keycode keycode)
{
    switch (keycode)
    {


    case SDLK_SPACE:
        ball->direction &= ~DIRECTION_RIGHT;
        ball->direction |= ~DIRECTION_LEFT;
        break;


    }
}

void Ball_render(SDL_Renderer *renderer, Ball *ball)
{

if (ball->shown)
{
    // Render ball
    Image_render(renderer, &ball->imageball);
}
if (ball->imageball.rect.w==ball->margin)
{
   ball->shown=false;
    Image_destroy(&ball->imageball);
}
}
void Ball_move(Ball *ball, int screenWidth, int screenHeight, int framerate, Animation *animation)
{
    int ballStep = ball->speed / framerate;
    //if((ball->direction & DIRECTION_UP)
      //      && ball->imageball.rect.y - ballStep >= ball->margin)
    //{
      //  Ball_moveY(ball, -ballStep);
    //}
    //else if( (ball->direction & DIRECTION_DOWN)
      //       && ball->imageball.rect.y + ball->imageball.rect.h + ballStep <= screenHeight - ball->margin)
    //{
      //  Ball_moveY(ball, ballStep);
    //}


    if( (ball->direction & DIRECTION_LEFT)
            && ball->imageball.rect.x + ball->imageball.rect.w + ballStep <= screenWidth - ball->margin)
    {
        Ball_moveX(ball, ballStep);
     }
     else if( (ball->direction & DIRECTION_RIGHT)
              && ball->imageball.rect.x - ballStep >=ball->margin)
     {
        Ball_moveX(ball, -ballStep);
        int ball_left_side = ball->imageball.rect.x;
        int ball_right_side = ball->imageball.rect.x + ball->imageball.rect.w;
        int fighter2_left_side = animation->fighter2.image.rect.x;
        int fighter2_right_side = animation->fighter2.image.rect.x + animation->fighter2.image.rect.w;

        int ball_top = ball->imageball.rect.y;
        int fighter2_bottom = animation->fighter2.image.rect.y + animation->fighter2.image.rect.h;

        if(ball_left_side  <= fighter2_right_side  )
        {
         animation->fighter2.destroyed = true;
         Ball_setX(ball,300000);
        }

     }
   }

