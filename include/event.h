#pragma once

#ifndef PDA_EVENT_H
#define PDA_EVENT_H

#include <SDL2/SDL.h>

bool point_in_rect(SDL_Point, SDL_Rect);
bool point_in_poly(SDL_Point*, SDL_Point[], int);

//TODO: keyboard state (if needed)

#endif