#include "collision.hpp"

Collision::Collision(){}

Collision::Collision(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

Collision::~Collision() {}

void Collision::setXYPosition(int x, int y){
    this->x = x;
    this->y = y;
}

void Collision::setXPosition(int x){
    this->x = x;
}

void Collision::setYPosition(int y){
    this->y = y;
}