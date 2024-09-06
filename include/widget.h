#pragma once

#ifndef PDA_WIDGET_H
#define PDA_WIDGET_H

#include <functional>

#include "SDL2/SDL.h"

#include "renderutil.h"

const SDL_Point BASIC_MODAL_POLY = {};

typedef struct {
    const char* option;
    int id;
} DropdownOption;

//////////
//Modals//
//////////

//Basic modal
void render_modal(const char*, SDL_Point, int, int, SDL_Color, SDL_Color, std::function<void()>);

//Dropdown button modal
void render_option_modal(DropdownOption[], SDL_Point, int, int, SDL_Color);

//App menu/selection menu modal
void render_menu_modal();

///////////
//Buttons//
///////////

//Basic button
void render_button(const char*, SDL_Point, int, int, SDL_Color, SDL_Color, bool, std::function<void()>);

#endif
