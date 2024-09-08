/**
 * PADD-PDA STATE.H
 *
 * State machine and scene function definitions
 */

#pragma once

#ifndef PDA_STATE_H
#define PDA_STATE_H

#define __SOAREDS_DEBUG

#include <SDL2/SDL.h>

//State
extern bool running;

//Globals
extern SDL_Renderer* renderer;
extern SDL_Window* window;
extern bool last_click_handled;
extern SDL_Point last_click_pos;
extern bool common_draw_override;

//Scenes
void suspend_scene();
void main_scene();

#endif
