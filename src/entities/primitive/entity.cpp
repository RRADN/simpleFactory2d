#include "entity.hpp"

#include <exception>

Entity::Entity(const std::string &path) : PATH(path) {
    // Load the texture and set it to the sprite
    if (!texture.loadFromFile(PATH)) {
        throw std::runtime_error("Failed to load entity texture ");
    } else {
        sprite.setTexture(texture);
    }

}

Entity::~Entity() {
}
 
void Entity::update(sf::Vector2f movement) {
    sprite.move(movement);
}