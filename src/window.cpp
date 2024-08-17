#include "window.h"

Window::Window(const char* title, size_t width, size_t height) {
    p_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    p_renderer = SDL_CreateRenderer(p_window, -1, 0);
}

Window::~Window() {
    SDL_DestroyRenderer(p_renderer);
    SDL_DestroyWindow(p_window);
}

void Window::win_Loop() {
    
}