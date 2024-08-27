#pragma once

#ifndef PDA_WIDGET_POLYGON_H
#define PDA_WIDGET_POLYGON_H

#include "widget/widget.h"

#include "SDL2/SDL.h"

class Polygon : public Widget {
private:
    SDL_Color fg_color;
    SDL_Color bg_color;

public:
    Polygon(SDL_Point[]);
    ~Polygon();

};

class Rectangle : public Polygon {

};

#endif