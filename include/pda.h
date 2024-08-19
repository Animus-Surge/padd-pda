#pragma once

#ifndef PDA_H
#define PDA_H

//TEMPORARY: Will update to allow for on-the-fly window sizing, for now sized to PDA device specs
#define PDA_WIDTH 1024
#define PDA_HEIGHT 600

//TEMPORARY: config options
#define PDA_CURSOR 0

#include <stdint.h>

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a = 255;
} Color;

typedef struct {
    int32_t x;
    int32_t y;
} Point;

extern Color bg_color;

bool init();
void run();
void shutdown();

#endif