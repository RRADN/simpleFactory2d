#include "keysManager.hpp"

#include <algorithm>
#include <SDL3/SDL.h>


Keys::Keys() {}

void Keys::update() {
    std::copy(
        currentKeys,
        currentKeys + SDL_SCANCODE_COUNT,
        previousKeys
    );
    
    SDL_PumpEvents();

    const bool* keyboard = SDL_GetKeyboardState(nullptr);

    std::copy(
        keyboard,
        keyboard + SDL_SCANCODE_COUNT,
        currentKeys
    );
}

bool Keys::isKeyDown(SDL_Scancode key) const {
    return currentKeys[key];
}

bool Keys::isKeyUp(SDL_Scancode key) const {
    return !currentKeys[key];
}

bool Keys::isKeyPressed(SDL_Scancode key) const {
    return currentKeys[key] && !previousKeys[key];
}

bool Keys::isKeyReleased(SDL_Scancode key) const {
    return !currentKeys[key] && previousKeys[key];
}
