#include "event.hpp"

#include "SFML/System.hpp"
#include <iostream>

Event::Event(Entities &entities, adn::SfmlWindow &window) {
    this->entities = &entities;
    this->window = &window;
}

Event::~Event() {
    entities = nullptr;
}

void Event::playerMove(const sf::Event &event) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {

        entities->player.update(entities->player.moveUp());
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {

        entities->player.update(entities->player.moveDown());
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {

        entities->player.update(entities->player.moveLeft());
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {

        entities->player.update(entities->player.moveRight());
    }
}
    
