#pragma once

#ifndef PDA_RENDERUTIL_H
#define PDA_RENDERUTIL_H

//TODO: documentation

#include "pda.h"
#include "state.h"

#include <map>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

extern std::map<std::string, TTF_Font*> font_map;
extern std::map<std::string, SDL_Surface*> image_map;

static inline void set_color(SDL_Color *color) {
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

//Image handling
void load_image(const char* src, const char* nick);
SDL_Surface* get_image(const char* nick);

//Font handling
TTF_Font* get_font(const char* nick);
void kill_all_fonts();
void kill_font(const char* nick);

void render_text(int, int, char*, const char*, SDL_Color);

#endif