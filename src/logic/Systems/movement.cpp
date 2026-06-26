#include "movement.hpp"

#include "collision.hpp"

Movement::Movement() {
}

Movement::~Movement() {
}

void Movement::setSpeed(int speed){
    this->speed = speed;
}

void Movement::setDeltaTime(double deltaTime){
    this->deltaTime = deltaTime;
}

void Movement::moveRight(Collision& collision) {
    collision.setXPosition(collision.getX() + deltaTime * speed);
}

void Movement::moveLeft(Collision& collision) {
    collision.setXPosition(collision.getX() - deltaTime * speed);
}

void Movement::moveUp(Collision& collision) {
    collision.setYPosition(collision.getY() - deltaTime * speed);
}

void Movement::moveDown(Collision& collision) {
    collision.setYPosition(collision.getY() + deltaTime * speed);
}