#pragma once

#include "window.h"

class App {
public:
    Window main_window;
    ~App();

    void init();
};