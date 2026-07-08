#include "playerMovement.hpp"

#include <iostream>

PlayerMovement::PlayerMovement() {}

void PlayerMovement::update(Collision& collision) {
    if (inputs->SHIFT){
        setSpeed(200);// sprint need work
    } else {
        setSpeed(100);
    }
    if (inputs->W){
        moveUp(collision);
    }
    if (inputs->A){
        moveLeft(collision);
    }
    if (inputs->S){
        moveDown(collision);
    }
    if (inputs->D){
        moveRight(collision);
    }
}

void PlayerMovement::setInputs(GameInputs& inputs) {
    this->inputs = &inputs;
}