#include "timer.h"

#include <thread>

void set_timer(long int millis, std::function<void()> callback) {
    std::thread timer_thread(callback);
}