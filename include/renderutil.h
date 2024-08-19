#pragma once

#ifndef PDA_RENDERUTIL_H
#define PDA_RENDERUTIL_H

//TODO

#include "pda.h"
#include "state.h"

#include <SDL2/SDL.h>

static inline void set_color(Color *color) {
    SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
}

static inline void clear() {
    set_color(&bg_color);
    SDL_RenderClear(renderer);
}

//Line rendering
void draw_line(Point *start, Point *end, int thickness);
void draw_lines(Point points[], int num_points, int thickness);

//Polygon rendering
void draw_poly(Point points[], int num_points);
void fill_poly(Point points[], int num_points);

//Rectangle rendering
void draw_rect(Point *position, int width, int height);
void fill_rect(Point *position, int width, int height);

#endif