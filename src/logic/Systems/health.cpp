#include "health.hpp"

Health::Health() {
    healthPoints = 100;
}

Health::~Health() {
}

int Health::getHealthPoints() const {
    return healthPoints;
}

void Health::setHealthPoints(int hp) {
    healthPoints = hp;
}

void  Health::takeDamage(int damage) {
    healthPoints -= damage;
    
    if (healthPoints < 0) {
        healthPoints = 0;
    }
}

void Health::heal(int amount) {
    healthPoints += amount;
    
    if (healthPoints > 100) {
        healthPoints = 100;
    }
}