//SOAREDS interface function definitions

#include "soareds.h"
#include "renderutil.h"

// OK colors
Color SOAREDS_OK_1 = {75, 59, 64};
Color SOAREDS_OK_2 = {130, 115, 92};
Color SOAREDS_OK_3 = {157, 177, 124};
Color SOAREDS_OK_4 = {156, 222, 159};
Color SOAREDS_OK_5 = {209, 245, 190};

// OK colors alt theme
Color SOAREDS_OK_ALT_1 = {83, 55, 71};
Color SOAREDS_OK_ALT_2 = {95, 80, 107};
Color SOAREDS_OK_ALT_3 = {106, 107, 131};
Color SOAREDS_OK_ALT_4 = {118, 148, 159};
Color SOAREDS_OK_ALT_5 = {134, 187, 189};

void render_common() {
    //TODO: maybe combine to a single drawLines call?

    set_color(&SOAREDS_OK_5);

    Point header_lines[] = {
        Point{0, 80},
        Point{200, 80},
        Point{250, 30},
        Point{400, 30},
        Point{430, 0}
    };

    int header_count = sizeof(header_lines) / sizeof(header_lines[0]);

    draw_lines(header_lines, header_count, 1);

}