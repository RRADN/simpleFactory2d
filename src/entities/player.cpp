#include "player.hpp"

#include  <iostream>

#include "../core/ids/assetsID.hpp"

Player::Player() : Entity {AssetsID::Player} {
    movement.setSpeed(100);
}

void Player::setInputs(GameInputs& input) {
    movement.setInputs(input);
}

void Player::update(float deltaTime) {
    movement.setDeltaTime(deltaTime);
    movement.update(collision);
}

int Player::getX() {
    return collision.getX();
}

int Player::getY() {
    return collision.getY();
}

void Player::testmoveR(){
    movement.moveRight(collision);
}