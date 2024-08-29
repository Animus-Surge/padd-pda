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

class IClickable {
    void onclick(SDL_Point);
};

/**
 * Base widget definitions
 *
 * Contains the position for the widget
 */
class Widget {
protected:
    SDL_Point pos;

public:
    Widget(SDL_Point);
    ~Widget();

    void update();
    void render();
};

class Modal : public Widget {

public:
    Modal(SDL_Point);
    ~Modal();

};

class Polygon : public Widget {
protected:
    std::vector<SDL_Point> points;

public:
    Polygon(SDL_Point, SDL_Point[]);
    ~Polygon();
};


#endif