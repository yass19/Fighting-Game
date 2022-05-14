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

#include "fighter2.h"
#include "animation.h"

bool Fighter2_load(SDL_Renderer *renderer, Fighter2 *fighter2, const char *image,const char *imagepush,const char *imagekick)
{
    // Load fighter image
    if(!Image_load(renderer, &fighter2->image, image))
    {
        return false;
    }
      fighter2->destroyed=false ;

      // Load the image of fighterball
      if(!Image_load(renderer, &fighter2->imagepush, imagepush))
       {
          Image_destroy(&fighter2->image);
           return false;
       }
      //Load the image of the kick
      if(!Image_load(renderer, &fighter2->imagekick, imagekick))
       {
          Image_destroy(&fighter2->image);
           return false;
       }

    return true;
}

void Fighter2_setDirection(Fighter2 *fighter2, SDL_Keycode keycode)
{
    switch (keycode)
    {

    case SDLK_z:
        fighter2->direction &= ~DIRECTION_DOWN;
        fighter2->direction |= DIRECTION_UP;
        break;

    case SDLK_s:
        fighter2->direction &= ~SDLK_UP;
        fighter2->direction |= DIRECTION_DOWN;
        break;

    case SDLK_d:
        fighter2->direction &= ~SDLK_LEFT;
        fighter2->direction |= DIRECTION_RIGHT;
        break;

    case SDLK_q:
        fighter2->direction &= ~DIRECTION_RIGHT;
        fighter2->direction |= DIRECTION_LEFT;
        break;
    }
}

void Fighter2_unsetDirection(Fighter2 *fighter2, SDL_Keycode keycode)
{
    switch (keycode)
    {


    case SDLK_z:
        fighter2->direction &= ~DIRECTION_UP;
        break;

    case SDLK_s:
        fighter2->direction &= ~DIRECTION_DOWN;
        break;

    case SDLK_d:
        fighter2->direction &= ~DIRECTION_RIGHT;
        break;

    case SDLK_q:
        fighter2->direction &= ~DIRECTION_LEFT;
        break;
    }
}

void Fighter2_destroy(Fighter2 *fighter2)
{
    Image_destroy(&fighter2->image);
    Image_destroy(&fighter2->imagepush);
    Image_destroy(&fighter2->imagekick);

   //Image_destroy(&fighter2->shadow);
}

void Fighter2_setX(Fighter2 *fighter2, int x)
{
    // Fighter x coordinate
    fighter2->image.rect.x = x;
    fighter2->imagepush.rect.x = x;
    fighter2->imagekick.rect.x = x;

    // Fighter shadow x coordinate
    fighter2->shadow.rect.x = fighter2->image.rect.x
                            + (fighter2->image.rect.w - fighter2->shadow.rect.w) / 2
                            + fighter2->shadowOffset.x;
}

void Fighter2_setY(Fighter2 *fighter2, int y)
{
    // Fighter y coordinate
    fighter2->image.rect.y = y;
    fighter2->imagepush.rect.y = y;
    fighter2->imagekick.rect.y = y;

    // Fighter shadow y coordinate
    fighter2->shadow.rect.y = fighter2->image.rect.y
                            + (fighter2->image.rect.h - fighter2->shadow.rect.h) / 2
                            + fighter2->shadowOffset.y;
}

void Fighter2_setCoordinates(Fighter2 *fighter2, int x, int y)
{
    Fighter2_setX(fighter2, x);
    Fighter2_setY(fighter2, y);
}

void Fighter2_moveX(Fighter2 *fighter2, int x)
{
    Fighter2_setX(fighter2, fighter2->image.rect.x + x);
    Fighter2_setX(fighter2, fighter2->imagepush.rect.x + x);
    Fighter2_setX(fighter2, fighter2->imagekick.rect.x + x);
}

void Fighter2_moveY(Fighter2 *fighter2, int y)
{
    Fighter2_setY(fighter2, fighter2->image.rect.y + y);
    Fighter2_setY(fighter2, fighter2->imagepush.rect.y + y);
     Fighter2_setY(fighter2, fighter2->imagekick.rect.y + y);
}

void Fighter2_render(SDL_Renderer *renderer, Fighter2 *fighter2)
{
    if(fighter2->kick==false && fighter2->push==false)
     {
     Image_render(renderer, &fighter2->image);
     }
     //Render fighter ball
     else if(fighter2->push == true)
      {
         Image_render(renderer, &fighter2->imagepush);
     }

     else if(fighter2->kick == true)
      {
         Image_render(renderer, &fighter2->imagekick);
     }
}

void Fighter2_move(Fighter2 *fighter2, int screenWidth, int screenHeight, int framerate,Animation *animation)
{
    int fighterStep = fighter2->speed / framerate;

    if( (fighter2->direction & DIRECTION_UP)
            && fighter2->image.rect.y - fighterStep >= fighter2->margin)
    {
         Fighter2_moveY(fighter2, -fighterStep);
        if (fighter2->image.rect.y  <1600)
      {
        Fighter2_setDirection(fighter2,SDLK_s);
      }
    }
    else if( (fighter2->direction & DIRECTION_DOWN)
             && fighter2->image.rect.y + fighter2->image.rect.h + fighterStep <= screenHeight - fighter2->margin)
    {
        Fighter2_moveY(fighter2, fighterStep);
    }

    if( (fighter2->direction & DIRECTION_LEFT)
            && fighter2->image.rect.x + fighter2->image.rect.w + fighterStep <= screenWidth - fighter2->margin)
    {
        Fighter2_moveX(fighter2, -fighterStep);

    }
    else if( (fighter2->direction & DIRECTION_RIGHT)
             && fighter2->image.rect.x - fighterStep >= fighter2->margin)
    {
        Fighter2_moveX(fighter2, fighterStep);
        int fighter2_left_side = fighter2->image.rect.x;
        int fighter2_right_side = fighter2->image.rect.x + fighter2->image.rect.w;
        int fighter_left_side = animation->fighter.image.rect.x;
        int fighter_right_side = animation->fighter.image.rect.x + animation->fighter.image.rect.w;

        int fighter_top = fighter2->image.rect.y;
        int fighter2_bottom = animation->fighter.image.rect.y + animation->fighter.image.rect.h;

        if(fighter_left_side <= fighter2_right_side && fighter_right_side  >= fighter2_left_side && fighter_top <= fighter2_bottom )
        {
         //animation->fighter2.destroyed = true;

        //animation->fighter.direction = DIRECTION_STOP;

            Fighter2_setX(fighter2,animation->fighter.image.rect.x-animation->fighter.image.rect.w);


        }
    }
}
