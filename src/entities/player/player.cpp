#include "player.hpp"

Player::Player() : Entity("assets/entities/player.png"), Movement() {

}

Player::~Player() {
}

void Player::update(float deltaTime) {
    sprite.setPosition(posX, posY);
}
