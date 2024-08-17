#include <SDL2/SDL.h>
#include <stdio.h>

#define WIDTH 1024
#define HEIGHT 600

//TODO: make this happen in cmake instead
#define __SOAREDS_DEBUG

/**
 * WARNING: THIS IS ALL TEST CODE TO MAKE SURE EVERYTHING IS WORKING
 */

int main() {
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Failed to initialize SDL2: %s", SDL_GetError());
        exit(1);
    }

    //Gathering system info


    SDL_Window* window;
    SDL_Renderer* renderer;
    //TODO: debug mode stuff
    window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    bool running = true;

    SDL_Event event;

    while (running) {
        //Event handling
        while (SDL_PollEvent(&event)) {
            if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE || event.type == SDL_QUIT) {
                running = false;
            }
        }

        //Window clear
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        //Rendering
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawLine(renderer, 0, 0, 100, 100);
        SDL_RenderDrawLine(renderer, 1, 0, 100, 99);
        SDL_RenderDrawLine(renderer, 0, 1, 99, 100);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

}