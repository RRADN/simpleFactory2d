#include "playerMovement.hpp"

#include <iostream>

PlayerMovement::PlayerMovement() {}

void PlayerMovement::update(Collision& collision) {
    if (input->isKeyDown(SDL_SCANCODE_W)){
        moveUp(collision);
    }
    if (input->isKeyDown(SDL_SCANCODE_A)){
        moveLeft(collision);
    }
    if (input->isKeyDown(SDL_SCANCODE_S)){
        moveDown(collision);
    }
    if (input->isKeyDown(SDL_SCANCODE_D)){
        moveRight(collision);
    }
}

void PlayerMovement::setInputs(Input& input) {
    this->input = &input;
}