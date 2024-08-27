#pragma once

#ifndef PDA_WIDGET_H
#define PDA_WIDGET_H

/**
 * PDA - widget.h
 * 
 * Widget class and struct definitions
 */

#include <vector>

#include "SDL2/SDL.h"

/**
 * Base widget definitions
 * 
 * Contains the position for the widget
 */
class Widget {
protected:
    SDL_Rect bounding;

public:
    Widget(SDL_Rect);
    ~Widget();

    void update();
    void render();
};


class Polygon : public Widget {
protected:
    std::vector<SDL_Point> points;

public:
    Polygon(SDL_Point, SDL_Point[]);
    ~Polygon();
};


#endif