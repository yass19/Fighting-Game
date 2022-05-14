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

#include "ball2.h"
#include "animation.h"

bool Ball2_load(SDL_Renderer *renderer, Ball2 *ball2, const char *image)
{
    // Load ball2 image
    if(!Image_load(renderer, &ball2->imageball2, image))
    {
        return false;
    }
    ball2->shown=false;


    return true;
}

void Ball2_destroy(Ball2 *ball2)
{

    Image_destroy(&ball2->imageball2);
    Image_destroy(&ball2->shadow);
}

void Ball2_setX(Ball2 *ball2, int x)
{
    // Ball2 x coordinate
    ball2->imageball2.rect.x =x;

    // Ball2 shadow x coordinate
    ball2->shadow.rect.x = ball2->imageball2.rect.x
                            + (ball2->imageball2.rect.w - ball2->shadow.rect.w) / 2
                            + ball2->shadowOffset.x;
}

void Ball2_setY(Ball2 *ball2, int y)
{
    // Ball2 y coordinate
    ball2->imageball2.rect.y = y-150;

    // Ball2 shadow y coordinate
    ball2->shadow.rect.y = ball2->imageball2.rect.y
                            + (ball2->imageball2.rect.h - ball2->shadow.rect.h) / 2
                            + ball2->shadowOffset.y;
}

void Ball2_setCoordinates(Ball2 *ball2, int x, int y)
{
    Ball2_setX(ball2, x);
    Ball2_setY(ball2, y);
}

void Ball2_moveX(Ball2 *ball2, int x)
{
    Ball2_setX(ball2, ball2->imageball2.rect.x + x);
}

void Ball2_moveY(Ball2 *ball2, int y)
{
    Ball2_setY(ball2, ball2->imageball2.rect.y + y);
}

void Ball2_setDirection(Ball2 *ball2, SDL_Keycode keycode)
{
    switch (keycode)
    {

    case SDLK_x:

        ball2->direction &= ~SDLK_LEFT;
        ball2->direction |= DIRECTION_RIGHT;
        break;

    }
}

void Ball2_unsetDirection(Ball2 *ball2, SDL_Keycode keycode)
{
    switch (keycode)
    {


    case SDLK_x:
        ball2->direction &= ~DIRECTION_RIGHT;
        ball2->direction |= ~DIRECTION_LEFT;
        break;
    }
}

void Ball2_render(SDL_Renderer *renderer, Ball2 *ball2)
{
if (ball2->shown)
{
    // Render ball2
    Image_render(renderer, &ball2->imageball2);
}
if (ball2->imageball2.rect.w==ball2->margin)
{
   ball2->shown=false;
    Image_destroy(&ball2->imageball2);
}
}
void Ball2_move(Ball2 *ball2, int screenWidth, int screenHeight, int framerate, Animation *animation)
{
    int ball2Step = ball2->speed / framerate;
    //if((ball2->direction & DIRECTION_UP)
      //      && ball2->imageball2.rect.y - ball2Step >= ball2->margin)
    //{
      //  Ball2_moveY(ball2, -ball2Step);
    //}
    //else if( (ball2->direction & DIRECTION_DOWN)
      //       && ball2->imageball2.rect.y + ball2->imageball2.rect.h + ball2Step <= screenHeight - ball2->margin)
    //{
      //  Ball2_moveY(ball2, ball2Step);
    //}


    if( (ball2->direction & DIRECTION_LEFT)
            && ball2->imageball2.rect.x + ball2->imageball2.rect.w + ball2Step <= screenWidth - ball2->margin)
    {
        Ball2_moveX(ball2, -ball2Step);

    }

     else if( (ball2->direction & DIRECTION_RIGHT)
              && ball2->imageball2.rect.x - ball2Step >=ball2->margin)
     {
        Ball2_moveX(ball2, ball2Step);
        int ball2_left_side = ball2->imageball2.rect.x;
        int ball2_right_side = ball2->imageball2.rect.x + ball2->imageball2.rect.w;
        int fighter_left_side = animation->fighter.image.rect.x;
        int fighter_right_side = animation->fighter.image.rect.x + animation->fighter.image.rect.w;

       int ball2_top = ball2->imageball2.rect.y;
        int fighter2_bottom = animation->fighter.image.rect.y + animation->fighter.image.rect.h;

        if( fighter_right_side <=  ball2_left_side && ball2_right_side  >= fighter_right_side )
        {
         animation->fighter.destroyed = true;
         Ball2_setX(ball2,300000);

        }

     }
   }

