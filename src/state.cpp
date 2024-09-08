#include "state.h"

#include <string>
#include <SDL2/SDL.h>

bool running = true;
std::string uname = "";

SDL_Renderer* renderer = nullptr;
SDL_Window* window = nullptr;

bool last_click_handled = true; //Default true so we don't have any interesting issues
bool common_draw_override = false;
SDL_Point last_click_pos = {0,0};
