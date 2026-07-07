#include "playerInput.hpp"

#include <iostream>

PlayerInput::PlayerInput(Input& input) {
    this->input = &input;
}

SystemInputs& PlayerInput::getSystemInputs() {
    return systemInputs;
}

GameInputs& PlayerInput::getGameInputs() {
    return gameInputs;
}

void PlayerInput::update() {
    systemUpdate();
    gameUpdate();
}

void PlayerInput::systemUpdate() {
    if (input->isKeyDown(SDL_SCANCODE_ESCAPE)) {
        systemInputs.paused = !systemInputs.paused;
    }
    if (input->isKeyDown(SDL_SCANCODE_LALT)){
        systemInputs.debuging = !systemInputs.debuging;
    }
    std::cout <<systemInputs.debuging;

}

void PlayerInput::gameUpdate() {
    if (input->isKeyDown(SDL_SCANCODE_LSHIFT)){
        gameInputs.sprint = true;
    } else {
        gameInputs.sprint = false;
    }
    if (input->isKeyDown(SDL_SCANCODE_W)){
        gameInputs.moveUp = true;
    } else {
        gameInputs.moveUp = false;
    }
    if (input->isKeyDown(SDL_SCANCODE_A)){
        gameInputs.moveLeft = true;
    } else {
        gameInputs.moveLeft = false;
    }
    if (input->isKeyDown(SDL_SCANCODE_S)){
        gameInputs.moveDown = true;
    } else {
        gameInputs.moveDown = false;
    }
    if (input->isKeyDown(SDL_SCANCODE_D)){
        gameInputs.moveRight = true;
    } else {
        gameInputs.moveRight = false;
    }
}