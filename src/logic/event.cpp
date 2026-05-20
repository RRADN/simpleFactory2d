#include "event.hpp"

#include "SFML/System.hpp"
#include <iostream>

Event::Event(Entities &entities) {
    this->entities = &entities;
}

Event::~Event() {
    entities = nullptr;
    delete entities;
}

void Event::playerMove() {
    if (const std::optional event = window->pollEvent()){
        if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()){
        
        }
    }
    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            entities->player.update(entities->player.moveUp());
            return;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            entities->player.update(entities->player.moveDown());
            return;
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            entities->player.update(entities->player.moveLeft());
            return;
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            entities->player.update(entities->player.moveRight());
            return;
        }
    }
    
}