#pragma once

#include <SDL3/SDL_scancode.h>

class Keys {
public:
    Keys();
    ~Keys() = default;
    
    void update();

    bool isKeyDown(SDL_Scancode key) const;

    bool isKeyUp(SDL_Scancode key) const;

    bool isKeyPressed(SDL_Scancode key) const;

    bool isKeyReleased(SDL_Scancode key) const;

private:
    bool currentKeys[SDL_SCANCODE_COUNT]{};

    bool previousKeys[SDL_SCANCODE_COUNT]{};

};