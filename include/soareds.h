#pragma once

#ifndef PDA_SOAREDS_H
#define PDA_SOAREDS_H

#include "pda.h"

#include <SDL2/SDL.h>

//OK colors
extern SDL_Color SOAREDS_OK_1;
extern SDL_Color SOAREDS_OK_2;
extern SDL_Color SOAREDS_OK_3;
extern SDL_Color SOAREDS_OK_4;
extern SDL_Color SOAREDS_OK_5;

//OK colors alt theme
extern SDL_Color SOAREDS_OK_ALT_1;
extern SDL_Color SOAREDS_OK_ALT_2;
extern SDL_Color SOAREDS_OK_ALT_3;
extern SDL_Color SOAREDS_OK_ALT_4;
extern SDL_Color SOAREDS_OK_ALT_5;

//Code Yellow
//Code Red
//Code Gray
//Code Purple
//Code Green
//Code Blue
//Code Orange

// Scenes and common rendering stuff

//Common rendering stuff, header bar and clock
void render_common();

//On screen keyboard
void render_osk();

#endif