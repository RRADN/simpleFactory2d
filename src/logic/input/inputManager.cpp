#include "inputManager.hpp"

#include <algorithm>


Input::Input() {}

void Input::update() {
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

bool Input::isKeyDown(SDL_Scancode key) const {
    return currentKeys[key];
}

bool Input::isKeyUp(SDL_Scancode key) const {
    return !currentKeys[key];
}

bool Input::isKeyPressed(SDL_Scancode key) const {
    return currentKeys[key] && !previousKeys[key];
}

bool Input::isKeyReleased(SDL_Scancode key) const {
    return !currentKeys[key] && previousKeys[key];
}
