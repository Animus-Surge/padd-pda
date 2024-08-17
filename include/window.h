#pragma once

#include <SDL2/SDL.h>
#include <stdint.h>

class Window {
private:
    SDL_Window* p_window;
    SDL_Renderer* p_renderer;
    bool p_running;

public:
    Window(const char* title, size_t width, size_t height);
    ~Window();

    void win_Loop();
};