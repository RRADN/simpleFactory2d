#pragma once 

#include "collision.hpp"

class Movement {
public:
    Movement();
    ~Movement();

    void setSpeed(int speed);
    void setDeltaTime(double deltaTime);

    void moveRight(Collision& collision);
    void moveLeft(Collision& collision);
    void moveUp(Collision& collision);
    void moveDown(Collision& collision);

private:
    int speed;
    double deltaTime;
};
