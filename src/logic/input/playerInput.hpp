#pragma once

#include "inputManager.hpp"
#include "inputs.hpp"

class PlayerInput {
public: 
    PlayerInput(Input &input);
    ~PlayerInput() = default;

    void update();

    SystemInputs& getSystemInputs();
    GameInputs& getGameInputs();
    
private:
    void systemUpdate();
    void gameUpdate();

    Input* input;

    SystemInputs systemInputs {};
    GameInputs gameInputs {};
    
};