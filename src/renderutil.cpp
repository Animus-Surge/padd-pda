#include "renderutil.h"

#include <math.h>

//Fonts map for caching loaded fonts
std::map<std::string, TTF_Font*> font_map = {};
//Images map for caching loaded images
std::map<std::string, SDL_Surface*> image_map = {};

void draw_line(Point *start, Point *end, int thickness) {
    //Determine thickness offset
    int th_offset = (thickness - 1) / 2;

    //Determine if more vertical or more horizontal
    bool vertical = abs(end->x - start->x) < abs(end->y - start->y);

    //Render lines (TODO: thickness)
    SDL_RenderDrawLine(renderer, start->x, start->y, end->x, end->y);

}
void draw_lines(Point points[], int num_points, int thickness) {
    if(thickness == 0) thickness = 1; //No zero thickness allowed

    //Render lines
    int i;
    for(i = 0; i < num_points - 1; i++) {
        Point start = points[i];
        Point end = points[i+1];

        draw_line(&start, &end, thickness);
    }
}

void draw_poly(Point points[], int num_points) {
}
void fill_poly(Point points[], int num_points) {
}

void draw_rect(Point *position, int width, int height) {
}
void fill_rect(Point *position, int width, int height) {
}

void load_image(const char* src, const char* nick) {
}
SDL_Surface* get_image(const char* nick){}

void load_font(const char* src, const char* nick, int size) {
    std::string nick_str(nick);

    //BREAK CASE: font already exists in our cache
    if (font_map.find(nick_str) != font_map.end()) {
        return;
    }

    TTF_Font* font = TTF_OpenFont(src, size);
    if(font) {
        font_map[nick_str] = font;
    } else {
        printf("Error occured whilst loading font: %s; %s", src, SDL_GetError());
    }
}
TTF_Font* get_font(const char* nick) {
    std::string nick_str(nick);

    auto it = font_map.find(nick);
    if(it != font_map.end()) return it->second;
    else return nullptr;
}

void kill_all_fonts() {
    //TODO
}