#pragma once

#ifndef PDA_WIDGET_WIDGET_H
#define PDA_WIDGET_WIDGET_H

#include "SDL2/SDL.h"

#include "renderutil.h"

class Widget {
private:
    SDL_Point position;

public:
    Widget(SDL_Point);
    ~Widget();

    void update();
    void render();
};

#endif