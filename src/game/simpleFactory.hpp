#pragma once

//std
#include <iostream>

//SDL
#include <SDL3/SDL.h>

#include "../platform/sdlWindow.hpp"
#include "../platform/sdlContext.hpp"
#include "../logic/sdlInput.hpp"
#include "../platform/rendering/testrender.cpp"

class Game {
public:
    Game();
    ~Game();
    
private:
    const int WIDTH = 1920;
    const int HEIGHT = 1080;
    const std::string TITLE = "Simple Factory 2D";
    float deltaTime = 0.0f;

    Context sdl {};

    Window window {TITLE, WIDTH, HEIGHT};

    Input input {};

    Render render {};
    
    void run();
};
