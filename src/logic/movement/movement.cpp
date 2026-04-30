#include "movement.hpp"

#include "../../entities/player/player.hpp"

Movement::Movement() {

}

Movement::~Movement() {

}

void Movement::moveUp() {
    posY -= speed * deltaTime;
    std::cout << "posY: " << posY << "\n";
}

void Movement::moveDown() {
    posY += speed * deltaTime;
}

void Movement::moveLeft() {
    posX -= speed * deltaTime;
}

void Movement::moveRight() {
    posX += speed * deltaTime;
}

void Movement::getDeltaTime(float deltaTime) {
    this->deltaTime = deltaTime;
}