#include "renderutil.h"

#include <math.h>
#include <vector>
#include <algorithm>

#define FONT_DELIM "_"

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
    if (num_points < 2) return;

    for (int i = 0; i < num_points - 1; ++i) {
        SDL_RenderDrawLine(renderer, points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
    }
    // Draw line from last point to the first point to close the polygon
    SDL_RenderDrawLine(renderer, points[num_points - 1].x, points[num_points - 1].y, points[0].x, points[0].y);
}
void fill_poly(Point points[], int num_points) {
    if (num_points < 3) return;

    // Find the bounding box of the polygon
    int min_x = points[0].x, max_x = points[0].x;
    int min_y = points[0].y, max_y = points[0].y;
    for (int i = 1; i < num_points; ++i) {
        if (points[i].x < min_x) min_x = points[i].x;
        if (points[i].x > max_x) max_x = points[i].x;
        if (points[i].y < min_y) min_y = points[i].y;
        if (points[i].y > max_y) max_y = points[i].y;
    }

    // Scanline algorithm to fill the polygon
    for (int y = min_y; y <= max_y; ++y) {
        // Find intersections with the polygon edges
        std::vector<int> intersections;
        for (int i = 0; i < num_points; ++i) {
            int j = (i + 1) % num_points;
            if ((points[i].y <= y && points[j].y > y) || (points[j].y <= y && points[i].y > y)) {
                int x = points[i].x + (y - points[i].y) * (points[j].x - points[i].x) / (points[j].y - points[i].y);
                intersections.push_back(x);
            }
        }

        // Sort intersections
        std::sort(intersections.begin(), intersections.end());

        // Draw horizontal lines between pairs of intersections
        for (size_t i = 0; i < intersections.size(); i += 2) {
            if (i + 1 < intersections.size()) {
                SDL_RenderDrawLine(renderer, intersections[i], y, intersections[i + 1], y);
            }
        }
    }
}

void draw_rect(Point *position, int width, int height) {
    SDL_Rect rect = SDL_Rect{position->x, position->y, width, height};
    SDL_RenderDrawRect(renderer, &rect);
}
void fill_rect(Point *position, int width, int height) {
    SDL_Rect rect = SDL_Rect{position->x, position->y, width, height};
    SDL_RenderFillRect(renderer, &rect);
}

void load_image(const char* src, const char* nick) {
}
SDL_Surface* get_image(const char* nick){return NULL;}

TTF_Font* load_font(const char* src, const char* nick, int font_size) {
    std::string nick_str(nick);

    //BREAK CASE: font already exists in our cache
    auto it = font_map.find(nick_str);
    if (it != font_map.end()) {
        return it->second;
    }

    TTF_Font* font = TTF_OpenFont(src, font_size);
    if(font) {
        font_map[nick_str] = font;
        return font;
    } else {
        printf("E: Error occured whilst loading font '%s': %s", src, SDL_GetError());
        return nullptr;
    }
}

TTF_Font *get_font(const char *nick)
{
    std::string nick_str(nick);

    auto it = font_map.find(nick);
    if(it != font_map.end()) return it->second;
    else {
        printf("N: Loading %s...\n", nick);
        char *tok, font_name[256];
        int font_size = 0;

        char font_nick[strlen(nick)+1];
        strcpy(font_nick, nick);

        //Get font name
        tok = strtok(font_nick, FONT_DELIM);
        strcpy(font_name, tok);

        //Get font size
        tok = strtok(NULL, FONT_DELIM);
        font_size = (int)strtol(tok, NULL, 10);

        //Load font
        char font_file[512];
        sprintf(font_file, "./resources/%s.ttf", font_name);
        TTF_Font* font = load_font(font_file, nick, font_size);
        return font;
    }
}

void kill_all_fonts() {
    for(auto it = font_map.begin(); it != font_map.end();) {
        TTF_CloseFont(it->second);
        it = font_map.erase(it);
    }
}

void render_text(int x, int y, char* t, const char* f, SDL_Color c) {
    //TODO: text caching
    TTF_Font* font = get_font(f);
    if(font == nullptr) return;

    SDL_Surface* text = TTF_RenderText_Solid(font, t, c);
    if(text == nullptr) {
        printf("E: Error rendering text: %s\n", TTF_GetError());
    }
    SDL_Rect rect = SDL_Rect{x, y, text->w, text->h};

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, text);
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(text);
    SDL_DestroyTexture(texture);
}