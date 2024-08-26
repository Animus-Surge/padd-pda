#include "pda.h"
#include "state.h"
#include "soareds.h"
#include "renderutil.h"

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

SDL_Color bg_color = {0, 0, 10};

/**
 * Initialization function, returns false if any system failed to init
 */
bool init() {
    //SDL systems initialization
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Failed to initialize SDL: %s\n", SDL_GetError());
        return false;
    }
    if(TTF_Init() < 0) {
        printf("Failed to initialize SDL TTF modules: %s\n", TTF_GetError());
        return false;
    }

    //Window and renderer system initialization
#ifdef PDA_DEBUG
    window = SDL_CreateWindow("PDA", 20, 20, PDA_WIDTH, PDA_HEIGHT, 0);
#else
    window = SDL_CreateWindow("PDA", 0, 0, PDA_WIDTH, PDA_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
#endif
    if(!window) {
        printf("Failed to create window: %s\n", SDL_GetError());
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!window) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        return false;
    }

    //Load fonts (I would love to be able to change this...)

    //Settings (TODO: load from json or config file)
    SDL_ShowCursor(PDA_CURSOR);

    return true;
}

/**
 * Main loop, returns when main loop exits
 */
void run() {
    SDL_Event event;

    while (running) {
        //Event handling
        while (SDL_PollEvent(&event)) {
            if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE || event.type == SDL_QUIT) {
                running = false;
            }

            if(event.type == SDL_MOUSEBUTTONUP) {
                printf("D: Mouse click at: (%d, %d)\n", event.button.x, event.button.y);
            }
        }

        //Window clear
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        //Rendering
        render_common();

        SDL_RenderPresent(renderer);
    }
}

/**
 * Shutdown function, deinits and destroys SDL resources
 */
void shutdown() {
    //Destroy window and renderer resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    //TODO: call destroy functions for fonts
    kill_all_fonts();

    //Quit SDL resources
    TTF_Quit();
    SDL_Quit();
}