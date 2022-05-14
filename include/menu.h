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

#ifndef MENU_H
#define MENU_H

#include "utils.h"
#include "background.h"
#include "play.h"
#include "quit.h"


#define MENU_IMG       "assets/menu.png"
#define MENU_MARGIN   20

#define PLAY_IMG       "assets/play.png"
#define PLAY_MARGIN   20

#define QUIT_IMG       "assets/quit.png"
#define QUIT_MARGIN   20



struct Menu
{
    // Menu screen dimensions
    int width;
    int height;


    // Menu renderer
    SDL_Renderer *renderer;

    // Background and Play and quit
    Background background;
    Play play ;
    Quit quit ;

    bool playGame;
    bool quitGame;

};
typedef struct Menu Menu;


bool Menu_start(SDL_Renderer *renderer, int width, int height);

bool Menu_load(Menu *menu);
void Menu_destroy(Menu *menu);
void Menu_render(Menu *menu);

bool Menu_handleEvent(Menu *menu, SDL_Event *e);
void Menu_update(Menu *animation, int framerate);

#endif // MENU_H
