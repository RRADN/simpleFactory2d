#pragma once 

#include "../entity.hpp"
#include "../../logic/movement/movement.hpp"

class Player : public Entity, public Movement {
public:

    void update(float deltaTime) override;
    
    Player();
    virtual ~Player();
};
