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

//Scenes
void suspend_scene();
void main_scene();

#endif