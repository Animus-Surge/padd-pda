#pragma once

#ifndef PDA_TIMER_H
#define PDA_TIMER_H

#include <functional>

void set_timer(long int millis, std::function<void()> callback);

#endif