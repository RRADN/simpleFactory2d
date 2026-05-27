#include "entity.hpp"

#include <exception>

Entity::Entity(const std::string &PATH) : PATH(PATH), texture(PATH), sprite(texture) {
    
}

Entity::~Entity() {
}
 
void Entity::update(sf::Vector2f movement) {
    sprite.move(movement);
}