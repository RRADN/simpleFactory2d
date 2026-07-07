#pragma once 

#include "../input/inputs.hpp"

#include "movement.hpp"

class PlayerMovement : public Movement {
public:
    PlayerMovement();
    ~PlayerMovement() = default;

    void setInputs(GameInputs &inputs);
    void update(Collision& collision);

private:
    GameInputs* inputs;
};