#pragma once 

#include "collision.hpp"

class Movement {
public:
    Movement();
    ~Movement() = default;

    void setSpeed(float speed);
    void setDeltaTime(float deltaTime);
    
    void moveRight(Collision& collision);
    void moveLeft(Collision& collision);
    void moveUp(Collision& collision);
    void moveDown(Collision& collision);

private:
    float speed;
    float deltaTime;
};
