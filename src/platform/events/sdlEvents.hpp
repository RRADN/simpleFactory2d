#pragma once 

#include <SDL3/SDL.h>

class Events {
public:
    Events();
    ~Events() = default;

    bool update();

private:
    bool shouldClose;

    void inputCase();
};