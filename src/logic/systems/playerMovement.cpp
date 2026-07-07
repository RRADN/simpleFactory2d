#include "playerMovement.hpp"

#include <iostream>

PlayerMovement::PlayerMovement() {}

void PlayerMovement::update(Collision& collision) {
    if (inputs->sprint){
        setSpeed(200);// sprint need work
    } else {
        setSpeed(100);
    }
    if (inputs->moveUp){
        moveUp(collision);
    }
    if (inputs->moveLeft){
        moveLeft(collision);
    }
    if (inputs->moveDown){
        moveDown(collision);
    }
    if (inputs->moveRight){
        moveRight(collision);
    }
}

void PlayerMovement::setInputs(GameInputs& inputs) {
    this->inputs = &inputs;
}