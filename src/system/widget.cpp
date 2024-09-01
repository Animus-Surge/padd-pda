#include "widget.h"

void render_modal(const char* title, SDL_Point position, int width, int height, std::function<void()> render_fn, PDA_MODAL_TYPE modal_type) {
    //For now, only render basic modals

    SDL_Point conf_modal[] = {
        {position.x + 12, position.y}, //position.x + 12 position.y, position.x + width/2 position.y, position.x + width/2 + 12 position.y - 20
        {position.x + ((int)(width/2)), position.y},
        {position.x + ((int)(width/2) + 20), position.y - 20},
        {position.x + width, position.y - 20},
        {position.x + width, position.y + height/2},
        {812, 310},
        {800, 322},
        {800, 450},
        {200, 450}
    };


    render_fn();
}

void render_button(const char* label, SDL_Point position, int width, int height, std::function<void()> callback, PDA_BUTTON_TYPE button_type) {

}

void render_dropdown(DropdownOption options[], SDL_Point position, int width, int height, int default_sel, std::function<void()> callback) {
    //TODO: maybe change this to be a type of modal or button?
}