#pragma once

#include <SDL3/SDL.h>

class Context
{
public:
    Context()
    {
        SDL_Init(SDL_INIT_VIDEO);
    }

    ~Context()
    {
        SDL_Quit();
    }
};