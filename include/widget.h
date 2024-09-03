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

typedef enum PDA_MODAL_TYPE {
    MODAL_BASIC,
    MODAL_MENU,
    MODAL_SIDEBAR,
    MODAL_NOTIFICATION
};

typedef enum PDA_BUTTON_TYPE {
    BUTTON_BASIC,
    BUTTON_MENU,
    BUTTON_APPL
};

void render_modal(const char*, SDL_Point, int, int, SDL_Color, SDL_Color, std::function<void()>, PDA_MODAL_TYPE);
void render_button(const char*, SDL_Point, int, int, std::function<void()>, PDA_BUTTON_TYPE);
void render_dropdown(DropdownOption[], SDL_Point, int, int, int, std::function<void()>);

#endif