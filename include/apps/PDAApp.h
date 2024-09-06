#pragma once

#ifndef APP_PDAAPP_H
#define APP_PDAAPP_H

#include <functional>

//Application struct
typedef struct {
    int id;
    const char* name;
    std::function<void()> init_fun;
    std::function<void()> loop_fun;
    std::function<void()> shutdown_fun;
} PDA_App;

//Frontend
void init();
bool register_app(const char*);
PDA_App* get_app(int id);
int get_app_id(const char*);
void delete_app(int id);

//Backend
void app_init(int id);
void app_loop(int id);
void app_shutdown(int id);

#endif
