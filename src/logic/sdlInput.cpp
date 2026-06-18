#include "sdlInput.hpp"

#include <iostream>
#include <algorithm>
#include <stdexcept>

Input::Input() {
}

Input::~Input() {
}  

void Input::update() {
    std::copy(
        currentKeys,
        currentKeys + SDL_SCANCODE_COUNT,
        previousKeys
    );

    SDL_PumpEvents();

    inputCase();
    
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

void Input::inputCase() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            std::cout << "Quit event received. Exiting game loop..." << std::endl;
            exit(0);
        }
    }  
}
