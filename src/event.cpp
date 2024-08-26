#include "event.h"

#include <cmath>
#include <algorithm>

bool point_in_rect(SDL_Point* point, SDL_Rect* rect) {
    return (point->x >= rect->x && point->x <= rect->x + rect->w) && (point->y >= rect->y && point->y <= rect->y + rect->h);
}

//Determining if a point is in a polygon, we will use the winding number algorithm

double xp(SDL_Point* p1, SDL_Point* p2, SDL_Point* p3) {
    return (p2->x - p1->x) * (p3->y - p1->y)
           - (p2->y - p1->y) * (p3->x - p1->x);
}

bool point_on_edge(SDL_Point* point, SDL_Point* edge1, SDL_Point* edge2) {
    return xp(edge1, edge2, point) == 0 
        && point->x >= std::min(edge1->x, edge2->x)
        && point->x <= std::max(edge1->x, edge2->x)
        && point->y >= std::min(edge1->y, edge2->y)
        && point->y <= std::max(edge1->y, edge2->y);
}

int wn(SDL_Point* point, SDL_Point points[], int num_points) {
    int winding_number = 0;

    for (int i = 0; i < num_points; i++) {
        SDL_Point p1 = points[i];
        SDL_Point p2 = points[(i+1)%num_points];

        if(point_on_edge(point, &p1, &p2)) return 0;

        double xp_c = xp(&p1, &p2, point);

        if(p1.y <= point->y) {
            if(p2.y > point->y && xp(&p1, &p2, point) > 0) {
                winding_number++;
            }
        }
        else {
            if(p2.y <= point->y && xp(&p1, &p2, point) < 0) {
                winding_number--;
            }
        }
    }

    return winding_number;
}

bool point_in_poly(SDL_Point* point, SDL_Point poly_points[], int num_points) {
    return wn(point, poly_points, num_points) != 0;
}