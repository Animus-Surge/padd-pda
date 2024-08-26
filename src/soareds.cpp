//SOAREDS interface function definitions

#include "event.h"
#include "renderutil.h"
#include "soareds.h"

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

//Common flags
bool cfg_modal_visible = false;
bool sys_menu_modal_visible = false;
bool act_menu_modal_visible = false;

bool b1_toggle = false;
bool b2_toggle = false;
bool b3_toggle = false;

//Modals
void render_cfg_modal() {}
void render_sys_menu_modal() {}
void render_act_menu_modal() {}

//Common Rendering
void render_common() {

    //Button polygons
    SDL_Point button1[] = {
        {5, 5},
        {85, 5},
        {65, 75},
        {5, 75}
    };

    SDL_Point button2[] = {
        {90, 5},
        {150, 5},
        {120, 75},
        {70, 75}
    };

    SDL_Point button3[] = {
        {155, 5},
        {265, 5},
        {195, 75},
        {125, 75}
    };

    SDL_Point header_lines[] = {
        {0, 80},
        {200, 80},
        {280, 0},
        {250, 30},
        {400, 30},
        {431, -1},
        {799, -1},
        {820, 20},
        {900, 20},
        {880, 0},
        {930, 50},
        {1024, 50}
    };

    SDL_Point footer_lines[] = {
        {0, 560},
        {100, 560},
        {140, 600},
        {120, 580},
        {200, 580},
        {220, 600}
    };

    int header_count = sizeof(header_lines) / sizeof(header_lines[0]);
    int footer_count = sizeof(footer_lines) / sizeof(footer_lines[0]);
    
    int button1_count = sizeof(button1) / sizeof(button1[0]);
    int button2_count = sizeof(button2) / sizeof(button2[0]);
    int button3_count = sizeof(button3) / sizeof(button3[0]);


    //Event handling
    if (!last_click_handled) {

        if(point_in_poly(&last_click_pos, button1, button1_count)) {
            b1_toggle = !b1_toggle;
        }
        else if(point_in_poly(&last_click_pos, button2, button2_count)) {
            b2_toggle = !b2_toggle;
        }
        else if(point_in_poly(&last_click_pos, button3, button3_count)) {
            b3_toggle = !b3_toggle;
        }

        last_click_handled = true;
    }
    
    // set_color(&PDA_WHITE);

    // SDL_RenderDrawPoint(renderer, last_click_pos.x, last_click_pos.y);

    set_color(&SOAREDS_OK_5);

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


    set_color(&SOAREDS_OK_ALT_5);

    if (b1_toggle) {
        fill_poly(button1, button1_count);
        render_text(10, 8, "SYS_M", "iceberg_16", PDA_BLACK);
    } else {
        draw_poly(button1, button1_count);
        render_text(10, 8, "SYS_M", "iceberg_16", SOAREDS_OK_ALT_5);
    }

    set_color(&SOAREDS_OK_4);

    if(b2_toggle) {
        fill_poly(button2, button2_count);
        render_text(95, 8, "CFG_S", "iceberg_16", PDA_BLACK);
    }
    else {
        draw_poly(button2, button2_count);
        render_text(95, 8, "CFG_S", "iceberg_16", SOAREDS_OK_4);
    }
    
    set_color(&SOAREDS_OK_ALT_3);

    if(b3_toggle) {
        fill_poly(button3, button3_count);
        render_text(160, 8, "ACT_M", "iceberg_16", PDA_BLACK);
    }
    else {
        draw_poly(button3, button3_count);
        render_text(160, 8, "ACT_M", "iceberg_16", PDA_WHITE);
    }

}