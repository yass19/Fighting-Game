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

#ifndef ANIMATION_H
#define ANIMATION_H

#include "utils.h"
#include "fighter.h"
#include "fighter2.h"
#include "background.h"
#include "ball.h"
#include "ball2.h"
#include "health bar.h"
#include "health bar2.h"
#include "pic.h"
#include "pic2.h"


#define FIGHTER_IMG       "assets/f.png"
#define FIGHTER_SPEED    200
#define FIGHTER_MARGIN   20

#define HEALTHBAR_IMG       "assets/yellowbar1.png"
#define HEALTHBAR_MARGIN   20

#define HEALTHBAR2_IMG       "assets/bluebar1.png"
#define HEALTHBAR2_MARGIN   20

#define PIC_IMG       "assets/pic.png"
#define PIC_MARGIN   0

#define PIC2_IMG       "assets/pic2.png"
#define PIC2_MARGIN   0


#define FIGHTER_PUSH_IMG       "assets/fire2.png"
#define FIGHTER_PUSH_SPEED     250
#define FIGHTER_PUSH_MARGIN    20

#define FIGHTER2_PUSH_IMG       "assets/f4.png"
#define FIGHTER2_PUSH_SPEED     250
#define FIGHTER2_PUSH_MARGIN   0

#define FIGHTER_KICK_IMG       "assets/kick.png"
#define FIGHTER_KICK_SPEED     250
#define FIGHTER_KICK_MARGIN    20

#define FIGHTER2_KICK_IMG       "assets/kick2.png"
#define FIGHTER2_KICK_SPEED     250
#define FIGHTER2_KICK_MARGIN    20


#define FIGHTER_BALL_IMG       "assets/fireball.png"
#define FIGHTER_BALL_SPEED     600
#define FIGHTER_BALL_MARGIN    0

#define FIGHTER2_BALL_IMG       "assets/fireball2.png"
#define FIGHTER2_BALL_SPEED     600
#define FIGHTER2_BALL_MARGIN    20


#define FIGHTER2_IMG       "assets/sec2.png"
#define FIGHTER2_SPEED       250
#define FIGHTER2_MARGIN    20

#define FIGHTER_SHADOW    "assets/fighter-shadow.png"
#define FIGHTER_SHADOW_X  50
#define FIGHTER_SHADOW_Y  10

#define OCEAN_IMG       "assets/best.jpg"
#define OCEAN_SPEED    0
//#define NUM_ENEMY    1
struct Animation
{
    // Animation screen dimensions
    int width;
    int height;


    // Animation renderer
    SDL_Renderer *renderer;

    // Background and Fighter and fighter2 and ball and ball2
    Background background;
    Fighter fighter;
    Fighter2 fighter2;
    HealthBar healthBar ;
    HealthBar2 healthBar2 ;
    Pic pic ;
    Pic2 pic2 ;
    Ball ball ;
    Ball2 ball2;
};
typedef struct Animation Animation;


bool Animation_start(SDL_Renderer *renderer, int width, int height);

bool Animation_load(Animation *animation);
void Animation_destroy(Animation *animation);

bool Animation_handleEvent(Animation *animation, SDL_Event *e);
void Animation_update(Animation *animation, int framerate);
void Animation_render(Animation *animation);

#endif // ANIMATION_H
