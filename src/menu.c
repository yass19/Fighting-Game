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

#include "menu.h"

bool Menu_start(SDL_Renderer *renderer, int width, int height)
{
    Menu menu = {0};
    menu.renderer  = renderer;
    menu.width     = width;
    menu.height    = height;
    menu.playGame = false;

    // Loat menu assets
    if(!Menu_load(&menu))
        return false;



    // Initialize framerate manager : 30 FPS
    FPSmanager fpsmanager;
    SDL_initFramerate(&fpsmanager);
    SDL_setFramerate(&fpsmanager,30);

    // Initialize start frame
    int frame = SDL_getFramecount(&fpsmanager);


    // Event loop exit flag
    bool quit = false;

    // Event loop
    while(!quit && !menu.playGame)
    {
        SDL_Event e;

        // Get available event
        while(SDL_PollEvent(&e))
        {
            // Handle menu events
            quit = Menu_handleEvent(&menu, &e);
        }

        // Each new frame
        int currentFrame = SDL_getFramecount(&fpsmanager);
        if(currentFrame != frame)
        {
            // Update menu frame
            Menu_update(&menu, SDL_getFramerate(&fpsmanager));

            currentFrame = frame;
        }

        // Render menu
        Menu_render(&menu);

        // Update screen
        SDL_RenderPresent(renderer);

        // Delay
        SDL_framerateDelay(&fpsmanager);
    }

    Menu_destroy(&menu);

    return menu.playGame;
}


bool Menu_load(Menu *menu)
{
    // Load the ocean image
    if(!Background_load(menu->renderer, &menu->background, MENU_IMG))
        return false;

    menu->background.image.rect.x = 0;
    menu->background.image.rect.y = 0;

    if(!Play_load(menu->renderer, &menu->play, PLAY_IMG))
    {
        Background_destroy(&menu->background);
        return false;
    }

    menu->play.margin = PLAY_MARGIN;

    if(!Quit_load(menu->renderer, &menu->quit, QUIT_IMG))
    {
        Background_destroy(&menu->background);
        return false;
    }
      menu->quit.margin = QUIT_MARGIN;

    int menuPos = 300;

    // Set play initial position
    Play_setX(&menu->play, (menu->width - menu->play.image.rect.w)/ 2); // Horiz. center
    Play_setY(&menu->play, menuPos);

    // Set quit initial position
    Quit_setX(&menu->quit, (menu->width - menu->quit.image.rect.w) / 2); // Horiz. center
    Quit_setY(&menu->quit, menuPos + menu->play.image.rect.h + 30);


    return true;
}

void Menu_destroy(Menu *menu)
{
    Play_destroy(&menu->play);

    Quit_destroy(&menu->quit);

    Background_destroy(&menu->background);
}


void Menu_render(Menu *menu)
{
    // Render ocean
    Background_render(menu->renderer, &menu->background, menu->width, menu->height);

    // Render fighter
    Play_render(menu->renderer, &menu->play);
    Quit_render(menu->renderer, &menu->quit);
}
bool Menu_handleEvent(Menu *menu ,SDL_Event *e)
{
    bool quit = false;

    // User requests quit
    if(e->type == SDL_QUIT)
    {
        quit = true;
    }
    else if(e->type == SDL_KEYDOWN)

    {
        { 

        }

    }
    else if(e->type == SDL_KEYUP)
    {



    }
    else if(e->type == SDL_MOUSEBUTTONDOWN)
    {
        if(e->button.button == SDL_BUTTON_LEFT) {

            // Play button clicked
            if(e->button.x >= menu->play.image.rect.x && e->button.x <= menu->play.image.rect.x  + menu->play.image.rect.w
                    && e->button.y >= menu->play.image.rect.y && e->button.y <= menu->play.image.rect.y  + menu->play.image.rect.h)
            {
                menu->playGame= true;
            }
            else if(e->button.x >= menu->quit.image.rect.x && e->button.x <= menu->quit.image.rect.x  + menu->quit.image.rect.w
                    && e->button.y >= menu->quit.image.rect.y && e->button.y <= menu->quit.image.rect.y  + menu->quit.image.rect.h) // Quit button
            {
                 exit(0);
            }
        }
    }
       return quit;


}
void Menu_update(Menu *menu, int framerate)
{
    // Move ocean
   // Background_move(&menu->background, framerate);

}
