#include "pda.h"

#include <X11/Xlib.h>

#include <stdio.h>

/**
 * WARNING: THIS IS ALL TEST CODE TO MAKE SURE EVERYTHING IS WORKING
 */

int main() {
    //TODO: Get system info and pass to pda
    Display* disp = XOpenDisplay(NULL);
    Screen* scr = XDefaultScreenOfDisplay(disp);

    int screen_width = XWidthOfScreen(scr);
    int screen_height = XHeightOfScreen(scr);

    printf("Found screen with size (%d, %d)\n", screen_width, screen_height);

    setvbuf(stdout, NULL, _IOLBF, 0);

    init();
    run();
    shutdown();
}