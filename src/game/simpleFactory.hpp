#pragma once

//std
#include <iostream>

//SDL
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "../platform/sdlWindow.hpp"
#include "../platform/sdlContext.hpp"

class Game {
public:
    Game();
    ~Game();
    
private:
    const int WIDTH = 1280;
    const int HEIGHT = 720;
    const std::string TITLE = "Simple Factory 2D";
    float deltaTime = 0.0f;

    Context sdl;

    Window window {TITLE, WIDTH, HEIGHT};

    void run();
};
