#include "app.h"

#include <stdio.h>

//Soareds app instances use at least 1 window, designated the main window. When main window exits, SOAREDS exits completely.

App::~App() {
}

void App::init() {
    //Entry

    if(!SDL_Init(SDL_INIT_EVERYTHING)) {
        printf("Failed to initialize SDL; %s", SDL_GetError());
    }

    //SDL has been initialized successfully
    main_window = Window("Test", 1024, 600);


}