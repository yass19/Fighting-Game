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

#include "fighter.h"
#include "animation.h"

bool Fighter_load(SDL_Renderer *renderer, Fighter *fighter, const char *image,const char *imagepush,const char *imagekick)
{
    // Load fighter image
    if(!Image_load(renderer, &fighter->image, image))
    {

        return false;
    }

   // Load the image of fighterball
   if(!Image_load(renderer, &fighter->imagepush, imagepush))
    {
       Image_destroy(&fighter->image);
        return false;
    }
   //Load the image of the kick
   if(!Image_load(renderer, &fighter->imagekick, imagekick))
    {
       Image_destroy(&fighter->image);
        return false;
    }


    return true;
}

void Fighter_destroy(Fighter *fighter)
{
    Image_destroy(&fighter->image);
      Image_destroy(&fighter->imagepush);
      Image_destroy(&fighter->imagekick);
    Image_destroy(&fighter->shadow);
}

void Fighter_setX(Fighter *fighter, int x)
{
    // Fighter x coordinate
      fighter->image.rect.x = x;
      fighter->imagepush.rect.x = x;
      fighter->imagekick.rect.x = x;
    // Fighter shadow x coordinate
    fighter->shadow.rect.x = fighter->image.rect.x
                            + (fighter->image.rect.w - fighter->shadow.rect.w) / 2
                            + fighter->shadowOffset.x;
}

void Fighter_setY(Fighter *fighter, int y)
{
    // Fighter y coordinate
    fighter->image.rect.y = y;
    fighter->imagepush.rect.y = y;
    fighter->imagekick.rect.y = y;
    // Fighter shadow y coordinate
    fighter->shadow.rect.y = fighter->image.rect.y
                            + (fighter->image.rect.h - fighter->shadow.rect.h) / 2
                            + fighter->shadowOffset.y;
}

void Fighter_setCoordinates(Fighter *fighter, int x, int y)
{
    Fighter_setX(fighter, x);
    Fighter_setY(fighter, y);
}

void Fighter_moveX(Fighter *fighter, int x)
{
    Fighter_setX(fighter, fighter->image.rect.x + x);
    Fighter_setX(fighter, fighter->imagepush.rect.x + x);
    Fighter_setX(fighter, fighter->imagekick.rect.x + x);
}

void Fighter_moveY(Fighter *fighter, int y)
{
    Fighter_setY(fighter, fighter->image.rect.y + y);
     Fighter_setY(fighter, fighter->imagepush.rect.y + y);
      Fighter_setY(fighter, fighter->imagekick.rect.y + y);
}

void Fighter_setDirection(Fighter *fighter, SDL_Keycode keycode)
{
    switch (keycode)
    {


    case SDLK_UP:
        fighter->direction &= ~DIRECTION_DOWN;
        fighter->direction |= DIRECTION_UP;
        break;

    case SDLK_DOWN:
        fighter->direction &= ~SDLK_UP;
        fighter->direction |= DIRECTION_DOWN;
        break;

    case SDLK_RIGHT:
        fighter->direction &= ~SDLK_LEFT;
        fighter->direction |= DIRECTION_RIGHT;
        break;

    case SDLK_LEFT:
        fighter->direction &= ~DIRECTION_RIGHT;
        fighter->direction |= DIRECTION_LEFT;
        break;

    }
}

void Fighter_unsetDirection(Fighter *fighter , SDL_Keycode keycode)
{
    switch (keycode)
    {

    case SDLK_UP:
        fighter->direction &= ~DIRECTION_UP;
        break;

    case SDLK_DOWN:
        fighter->direction &= ~DIRECTION_DOWN;
        break;

    case SDLK_RIGHT:
        fighter->direction &= ~DIRECTION_RIGHT;
        break;

    case SDLK_LEFT:
        fighter->direction &= ~DIRECTION_LEFT;
        break;

    }
}

void Fighter_render(SDL_Renderer *renderer, Fighter *fighter)
{
    if(fighter->kick==false && fighter->push==false)
     {
     Image_render(renderer, &fighter->image);
     }
     //Render fighter ball
     else if(fighter->push == true)
      {
         Image_render(renderer, &fighter->imagepush);
     }

     else if(fighter->kick == true)
      {
         Image_render(renderer, &fighter->imagekick);
     }

}

void Fighter_move(Fighter *fighter, int screenWidth, int screenHeight, int framerate,Animation *animation)
{
    int fighterStep = fighter->speed / framerate;

    if((fighter->direction & DIRECTION_UP)
            && fighter->image.rect.y - fighterStep >= fighter->margin)
    {
        Fighter_moveY(fighter, -fighterStep);
        if (fighter->image.rect.y  <1000)
        {
            Fighter_setDirection(fighter, SDLK_DOWN);
        }
    }
    else if( (fighter->direction & DIRECTION_DOWN)
             && fighter->image.rect.y + fighter->image.rect.h + fighterStep <= screenHeight - fighter->margin)
    {
        Fighter_moveY(fighter, fighterStep);
    }

    if( (fighter->direction & DIRECTION_RIGHT)
            && fighter->image.rect.x + fighter->image.rect.w + fighterStep <= screenWidth - fighter->margin)
    {
        Fighter_moveX(fighter, fighterStep);
         }
         else if( (fighter->direction & DIRECTION_LEFT)
                  && fighter->image.rect.x - fighterStep >=fighter->margin)
         {
            Fighter_moveX(fighter, -fighterStep);
            int fighter_left_side = fighter->image.rect.x;
            int fighter_right_side = fighter->image.rect.x + fighter->image.rect.w;
            int fighter2_left_side = animation->fighter2.image.rect.x;
            int fighter2_right_side = animation->fighter2.image.rect.x + animation->fighter2.image.rect.w;

            int fighter_top = fighter->image.rect.y;
            int fighter2_bottom = animation->fighter2.image.rect.y + animation->fighter2.image.rect.h;

            if(fighter_left_side <= fighter2_right_side && fighter_right_side  >= fighter2_left_side && fighter_top <= fighter2_bottom )
            {
             //animation->fighter2.destroyed = true;

            //animation->fighter.direction = DIRECTION_STOP;

Fighter_setX(fighter,animation->fighter2.image.rect.x+animation->fighter2.image.rect.w);


            }
         }


}

