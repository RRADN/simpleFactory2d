#include "collision.hpp"

Collision::Collision(){}

Collision::Collision(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Collision::setXYPosition(int x, int y){
    this->x = x;
    this->y = y;
}

void Collision::setXPosition(float x){
    this->x = x;
}

void Collision::setYPosition(float y){
    this->y = y;
}