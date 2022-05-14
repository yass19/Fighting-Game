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

#include "animation.h"

bool Animation_start(SDL_Renderer *renderer, int width, int height)
{
    Animation animation = {0};
    animation.renderer  = renderer;
    animation.width     = width;
    animation.height    = height;

    // Loat animation assets
    if(!Animation_load(&animation))
        return false;



    // Initialize framerate manager : 30 FPS
    FPSmanager fpsmanager;
    SDL_initFramerate(&fpsmanager);
    SDL_setFramerate(&fpsmanager, 60);

    // Initialize start frame
    int frame = SDL_getFramecount(&fpsmanager);


    // Event loop exit flag
    bool quit = false;

    // Event loop
    while(!quit)
    {
        SDL_Event e;

        // Get available event
        while(SDL_PollEvent(&e))
        {
            // Handle animation events
            quit = Animation_handleEvent(&animation, &e);
        }

        // Each new frame
        int currentFrame = SDL_getFramecount(&fpsmanager);
        if(currentFrame != frame)
        {
            // Update animation frame
            Animation_update(&animation, SDL_getFramerate(&fpsmanager));

            currentFrame = frame;
        }

        // Render animation
        Animation_render(&animation);

        // Update screen
        SDL_RenderPresent(renderer);

        // Delay
        SDL_framerateDelay(&fpsmanager);
    }

    Animation_destroy(&animation);

    return true;
}


bool Animation_load(Animation *animation)
{
    // Load the ocean image
    if(!Background_load(animation->renderer, &animation->background, OCEAN_IMG))
        return false;

    // Background move direction
    animation->background.direction = DIRECTION_DOWN;

    // Background speed in pixel/second
    animation->background.speed = OCEAN_SPEED;

    if(!Fighter_load(animation->renderer, &animation->fighter, FIGHTER_IMG,FIGHTER_PUSH_IMG,FIGHTER_KICK_IMG))
    {
        Background_destroy(&animation->background);
        return false;
    }
    if(!HealthBar_load(animation->renderer, &animation->healthBar, HEALTHBAR_IMG))
    {
        Background_destroy(&animation->background);
        return false;
    }

    if(!HealthBar2_load(animation->renderer, &animation->healthBar2, HEALTHBAR2_IMG))
    {
        Background_destroy(&animation->background);
        return false;
    }

    if(!Pic_load(animation->renderer, &animation->pic, PIC_IMG))
    {
        Background_destroy(&animation->background);
        return false;
    }

    if(!Pic2_load(animation->renderer, &animation->pic2, PIC2_IMG))
    {
        Background_destroy(&animation->background);
        return false;
    }

    if(!Fighter2_load(animation->renderer, &animation->fighter2, FIGHTER2_IMG,FIGHTER2_PUSH_IMG,FIGHTER2_KICK_IMG))
    {
        Background_destroy(&animation->background);
        return false;
     }
    if(!Ball_load(animation->renderer, &animation->ball, FIGHTER_BALL_IMG))
        {
            Background_destroy(&animation->background);
            return false;
    }
    if(!Ball2_load(animation->renderer, &animation->ball2, FIGHTER2_BALL_IMG))
        {
            Background_destroy(&animation->background);
            return false;
    }

    animation->fighter.push = false ;
      animation->fighter.kick = false ;

    animation->fighter.margin = FIGHTER_MARGIN; 

    animation->healthBar.margin = HEALTHBAR_MARGIN;
    animation->healthBar2.margin = HEALTHBAR2_MARGIN;

    animation->pic.margin = PIC_MARGIN;
    animation->pic2.margin = PIC2_MARGIN;


    animation->fighter.shadowOffset.x = FIGHTER_SHADOW_X;
    animation->fighter.shadowOffset.y = FIGHTER_SHADOW_Y;

      animation->fighter2.push = false ;
       animation->fighter2.kick = false ;
    animation->fighter2.margin = FIGHTER2_MARGIN;
    animation->fighter2.shadowOffset.x = FIGHTER_SHADOW_X;
    animation->fighter2.shadowOffset.y = FIGHTER_SHADOW_Y;

   animation->ball.margin = FIGHTER_BALL_MARGIN;
    animation->ball2.margin = FIGHTER2_BALL_MARGIN;

    // Set fighter initial position
    Fighter_setX(&animation->fighter, ((animation->width - animation->fighter.image.rect.w)+200) / 2); // Horiz. center
    Fighter_setY(&animation->fighter, animation->height - animation->fighter.image.rect.h - animation->fighter.margin);

    // Set health bar initial position
    HealthBar_setX(&animation->healthBar, (animation->width - animation->healthBar.image.rect.w-90) );
    HealthBar_setY(&animation->healthBar,  animation->healthBar.image.rect.h - animation->healthBar.margin-70);

    // Set health bar2 initial position
    HealthBar2_setX(&animation->healthBar2, (animation->width - animation->healthBar2.image.rect.w-1000) );
    HealthBar2_setY(&animation->healthBar2,  animation->healthBar2.image.rect.h - animation->healthBar2.margin-30);

    // Set pic initial position
    Pic_setX(&animation->pic, (animation->width - animation->pic.image.rect.w) );
    Pic_setY(&animation->pic,  animation->pic.image.rect.h - animation->pic.margin-80);

    // Set pic2 initial position
    Pic2_setX(&animation->pic2, (animation->width - animation->pic2.image.rect.w)-1340);
    Pic2_setY(&animation->pic2,  animation->pic2.image.rect.h - animation->pic2.margin-80);


    // Fighter move direction
    animation->fighter.direction = DIRECTION_STOP;



    // fighter move speed in pixel/second
    animation->fighter.speed = FIGHTER_SPEED;


    // Fighter2 move direction
    animation->fighter2.direction = DIRECTION_STOP;

    // Fighter2 move speed in pixel/second
    animation->fighter2.speed = FIGHTER2_SPEED;

    // Set ball initial position
   Ball_setX(&animation->ball, (animation->width - animation->ball.imageball.rect.w) / 2);
   Ball_setY(&animation->ball, animation->height - animation->ball.imageball.rect.h - animation->ball.margin);

    // Ball move direction
    animation->ball.direction = DIRECTION_STOP;

    // Ball move speed in pixel/second
    animation->ball.speed = FIGHTER_BALL_SPEED;


    // Set fighter2 initial position
    Fighter2_setX(&animation->fighter2, ((animation->width - animation->fighter2.image.rect.w)-400) / 2); // Horiz. center
    Fighter2_setY(&animation->fighter2, animation->height - animation->fighter2.image.rect.h - animation->fighter2.margin);



    // Set ball2 initial position
   Ball2_setX(&animation->ball2, (animation->width - animation->ball2.imageball2.rect.w) / 2); // Horiz. center
   Ball2_setY(&animation->ball2, animation->height - animation->ball2.imageball2.rect.h - animation->ball2.margin);

    // Ball2 move direction
    animation->ball2.direction = DIRECTION_STOP;

    // Ball2 move speed in pixel/second
    animation->ball2.speed = FIGHTER2_BALL_SPEED;

    return true;
}

void Animation_destroy(Animation *animation)
{
    Fighter_destroy(&animation->fighter);
     HealthBar_destroy(&animation->healthBar);
      HealthBar2_destroy(&animation->healthBar2);
       Pic_destroy(&animation->pic);
       Pic2_destroy(&animation->pic2);
     Fighter2_destroy(&animation->fighter2);
       Ball_destroy(&animation->ball);
       Ball2_destroy(&animation->ball2);
    Background_destroy(&animation->background);
}

bool Animation_handleEvent(Animation *animation, SDL_Event *e)
{
    bool quit = false;

    // User requests quit
    if(e->type == SDL_QUIT)
    {
        quit = true;
    }
    else if(e->type == SDL_KEYDOWN)
    {
        switch (e->key.keysym.sym)
        {
        case SDLK_ESCAPE:
            quit = true;
            break;

        case SDLK_UP:
        case SDLK_DOWN:
        case SDLK_RIGHT:
        case SDLK_LEFT:
           Fighter_setDirection(&animation->fighter, e->key.keysym.sym);
            break;
        }
        switch (e->key.keysym.sym)
        {
        case SDLK_ESCAPE:
            quit = true;
            break;
        case SDLK_z:
        case SDLK_s:
        case SDLK_d:
        case SDLK_q:
            Fighter2_setDirection(&animation->fighter2, e->key.keysym.sym);
            break ;
        }
        switch (e->key.keysym.sym)
        {
        case SDLK_o:
           animation->fighter2.kick=true ;
            break;
        }

        //switch (e->key.keysym.sym)
        //{
       // case SDLK_p:
         //animation->fighter2.push=true ;
           // break;
        //}
        switch (e->key.keysym.sym)
        {
        case SDLK_SPACE:
           animation->ball.shown=true ;
           animation->fighter.push=true ;

           Ball_setDirection(&animation->ball, e->key.keysym.sym);

            break ;
        }
        switch (e->key.keysym.sym)
        {
        case SDLK_x:
           animation->ball2.shown=true ;
           animation->fighter2.push=true ;

           Ball2_setDirection(&animation->ball2, e->key.keysym.sym);

            break ;
       }

        switch (e->key.keysym.sym)
        {
        case SDLK_t:
         animation->fighter.kick=true ;
            break;

        }

    }
    else if(e->type == SDL_KEYUP)
    {
        switch (e->key.keysym.sym)
        {

        case SDLK_UP:
        case SDLK_DOWN:
        case SDLK_RIGHT:
        case SDLK_LEFT:
 Fighter_unsetDirection(&animation->fighter, e->key.keysym.sym);
            break ;
        }
       switch (e->key.keysym.sym)
       {
        case SDLK_z:
        case SDLK_s:
        case SDLK_d:
        case SDLK_q:

            Fighter2_unsetDirection(&animation->fighter2, e->key.keysym.sym);
            break;
       }
       switch (e->key.keysym.sym)
      {
       case SDLK_SPACE:
       animation->fighter.push=false ;
         //  animation->ball.shown=false ;
       Ball_unsetDirection(&animation->ball, e->key.keysym.sym);
           break ;
        }
       switch (e->key.keysym.sym)
      {
       case SDLK_x:
       animation->fighter2.push=false ;
       Ball2_unsetDirection(&animation->ball2, e->key.keysym.sym);
           break ;
        }
       switch (e->key.keysym.sym)
      {  case SDLK_o:
        animation->fighter2.kick=false ;
           break;
       }

      // switch (e->key.keysym.sym)
      //{  case SDLK_p:
        //animation->fighter2.push=false ;
          // break;
       //}

       switch (e->key.keysym.sym)
      {
       case SDLK_t:
   animation->fighter.kick=false ;
           break ;
        }

}
       return quit;


}
void Animation_update(Animation *animation, int framerate)
{
    // Move ocean
    Background_move(&animation->background, framerate);

    // Move fighter
    Fighter_move(&animation->fighter, animation->width, animation->height, framerate,animation);
    // Move fighter2
    Fighter2_move(&animation->fighter2 ,animation->width, animation->height, framerate, animation);
   //Move ball
    Ball_move(&animation->ball,animation->height,animation->width,framerate,animation );
    //Move2 ball
     Ball2_move(&animation->ball2,animation->height,animation->width,framerate,animation );
}

void Animation_render(Animation *animation)
{
    // Render ocean
    Background_render(animation->renderer, &animation->background, animation->width, animation->height);
    // Render fighter
    Fighter_render(animation->renderer, &animation->fighter);
    // Render fighter2
    Fighter2_render(animation->renderer, &animation->fighter2);
    // Render ball
    if (&animation->ball.imageball.rect.x < &animation->width)
  {
        animation->ball.shown=false ;

    }
    else{  Ball_render(animation->renderer, &animation->ball);}
    // Render ball2
    if (&animation->ball2.imageball2.rect.x < &animation->width)
  {
        animation->ball2.shown=false ;

    }
    else{  Ball2_render(animation->renderer, &animation->ball2);}
    // Render health bar
    HealthBar_render(animation->renderer, &animation->healthBar);
    // Render health bar2
    HealthBar2_render(animation->renderer, &animation->healthBar2);
    // Render pic
    Pic_render(animation->renderer, &animation->pic);
    // Render pic2
    Pic2_render(animation->renderer, &animation->pic2);
}
