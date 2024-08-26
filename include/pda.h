#pragma once

#ifndef PDA_H
#define PDA_H

//TEMPORARY: Will update to allow for on-the-fly window sizing, for now sized to PDA device specs
#define PDA_WIDTH 1024
#define PDA_HEIGHT 600

//TEMPORARY: config options
#define PDA_CURSOR 0

#include <stdint.h>

#include "SDL2/SDL.h"

typedef struct {
    int32_t x;
    int32_t y;
} Point;

extern SDL_Color bg_color;

const SDL_Color PDA_BLACK = {0, 0, 0, 255};
const SDL_Color PDA_WHITE = {255, 255, 255, 255};

bool init();
void run();
void shutdown();

#endif