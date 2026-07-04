#pragma once 

#include "../../logic/systems/collision.hpp"

template<typename ID>
class Entity {
public:
    Entity(ID id);
    ~Entity() = default;

    ID getID() const;

protected:
    Collision collision {0,0,0,0};

private:
    ID id;

};

#include "entity.tpp"