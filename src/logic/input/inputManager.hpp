#pragma once

#include "inputs.hpp"
#include "keysManager.hpp"

class Input {
public: 
    Input();
    ~Input() = default;

    void update();

    SystemInputs& getSystemInputs();
    GameInputs& getGameInputs();
    
private:
    void systemUpdate();
    void gameUpdate();

    Keys keys {};

    SystemInputs systemInputs {};
    GameInputs gameInputs {};
    
};