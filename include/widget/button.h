#pragma once

#ifndef PDA_WIDGET_BUTTON_H
#define PDA_WIDGET_BUTTON_H

#include <functional>

#include "widget/widget.h"

class Button : public Widget {
private:
    std::function<void()> callback;


};

#endif