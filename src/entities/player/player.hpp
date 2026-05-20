#pragma once 

#include "../primitive/entity.hpp"
#include "../../logic/movement/movement.hpp"

class Player : public Entity, public Movement {
public:    
    Player();
    virtual ~Player();
};
