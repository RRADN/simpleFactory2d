#pragma once

//std
#include <iostream>

//SDL
#include <SDL3/SDL.h>

#include "../core/timer/timer.hpp"

#include "../entities/player.hpp"

#include "../logic/input/inputManager.hpp"

#include "../platform/window/sdlWindow.hpp"
#include "../platform/window/sdlContext.hpp"
#include "../platform/events/sdlEvents.hpp"
#include "../platform/rendering/renderManager.hpp"
#include "../platform/rendering/textureManager.hpp"

class Game {
public:
    Game();
    ~Game();
    
private:
    const int WIDTH = 1920;
    const int HEIGHT = 1080;
    const std::string TITLE = "Simple Factory 2D";

    Context sdl {};

    Window window {TITLE, WIDTH, HEIGHT};

    Events events {};

    Input input {};

    Render render {*window.getRenderer()};
    
    Player player {};

    Timer timer {};

    void init();
    void run();
    void update();

};
