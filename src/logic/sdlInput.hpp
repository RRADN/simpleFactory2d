#pragma once 

#include <SDL3/SDL.h>

class Input {
public:
    Input();
    ~Input();

    void update();

    bool isKeyDown(SDL_Scancode key) const;

    bool isKeyUp(SDL_Scancode key) const;

    bool isKeyPressed(SDL_Scancode key) const;

    bool isKeyReleased(SDL_Scancode key) const;

private:
    void inputCase();

    bool currentKeys[SDL_SCANCODE_COUNT]{};

    bool previousKeys[SDL_SCANCODE_COUNT]{};

};