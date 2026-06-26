#pragma once 

#include "../../logic/Systems/health.hpp"
#include "../../logic/Systems/collision.hpp"

class Entity {
public:
    Entity();
    ~Entity();

protected:
    Health health {};
    Collision Collision {};

};