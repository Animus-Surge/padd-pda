#include "renderutil.h"

#include <math.h>

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