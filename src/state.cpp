#include "state.h"

#include <string>

bool running = true;
std::string uname = "";

SDL_Renderer* renderer = nullptr;
SDL_Window* window = nullptr;

bool last_click_handled = true; //Default true so we don't have any interesting issues
SDL_Point last_click_pos = {0,0};