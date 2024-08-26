//SOAREDS interface function definitions

#include "soareds.h"
#include "renderutil.h"

#include <ctime>

#include <unistd.h>

// OK colors
SDL_Color SOAREDS_OK_1 = {75, 59, 64, 255};
SDL_Color SOAREDS_OK_2 = {130, 115, 92, 255};
SDL_Color SOAREDS_OK_3 = {157, 177, 124, 255};
SDL_Color SOAREDS_OK_4 = {156, 222, 159, 255};
SDL_Color SOAREDS_OK_5 = {209, 245, 190, 255};

// OK colors alt theme
SDL_Color SOAREDS_OK_ALT_1 = {83, 55, 71, 255};
SDL_Color SOAREDS_OK_ALT_2 = {95, 80, 107, 255};
SDL_Color SOAREDS_OK_ALT_3 = {106, 107, 131, 255};
SDL_Color SOAREDS_OK_ALT_4 = {118, 148, 159, 255};
SDL_Color SOAREDS_OK_ALT_5 = {134, 187, 189, 255};

void render_common() {
    //TODO: maybe combine to a single drawLines call?

    set_color(&SOAREDS_OK_5);

    Point rect_pos = {0, 0};
    // draw_rect(&rect_pos, 1024, 600);

    Point header_lines[] = {
        Point{0, 80},
        Point{200, 80},
        Point{280, 0},
        Point{250, 30},
        Point{400, 30},
        Point{431, -1},
        Point{799, -1},
        Point{820, 20},
        Point{900, 20},
        Point{880, 0},
        Point{930, 50},
        Point{1024, 50}
    };

    Point footer_lines[] = {
        Point{0, 560},
        Point{100, 560},
        Point{140, 600},
        Point{120, 580},
        Point{200, 580},
        Point{220, 600}
    };

    int header_count = sizeof(header_lines) / sizeof(header_lines[0]);
    int footer_count = sizeof(footer_lines) / sizeof(footer_lines[0]);

    //Screen borders
    draw_lines(header_lines, header_count, 1);
    draw_lines(footer_lines, footer_count, 1);

    //Clock label
    time_t timer = time(NULL);
    std::tm* cal = localtime(&timer);
    char timestr[30] = {0};
    char datestr[30] = {0};

    strftime(timestr, sizeof(timestr), "%H:%M:%S", cal);
    strftime(datestr, sizeof(datestr), "%m / %d / %y", cal);

    render_text(5, 560, timestr, "iceberg_20", PDA_WHITE);
    render_text(5, 580, datestr, "iceberg_13", SOAREDS_OK_4);

    //Username label
    char uname[64] = {0};
    getlogin_r(uname, sizeof(uname));
    render_text(820, -3, uname, "iceberg_20", SOAREDS_OK_4);

    //Button polygons
    Point button1[] = {
        {5, 5},
        {115, 5},
        {95, 75},
        {5, 75}
    };

    Point button2[] = {
        {120, 5},
        {265, 5},
        {195, 75},
        {100, 75}
    };

    set_color(&SOAREDS_OK_ALT_5);

    int num_button1 = sizeof(button1) / sizeof(button1[0]);
    draw_poly(button1, num_button1);

    render_text(10, 8, "SYS_M", "iceberg_15", SOAREDS_OK_ALT_5);

    set_color(&SOAREDS_OK_4);

    int num_button2 = sizeof(button2) / sizeof(button2[0]);
    fill_poly(button2, num_button2);

    render_text(125, 8, "ACT_M", "iceberg_15", PDA_BLACK);

}