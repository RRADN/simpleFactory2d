#include "event.hpp"

Event::Event(Entities &entities) {
    this->entities = &entities;
}

Event::~Event() {
    entities = nullptr;
    delete entities;
}

void Event::keyboardSwitch(sf::Event event) {

    switch (event.key.code)
    {
    case sf::Keyboard::W:
        std::cout << "W\n";
        entities->player.moveUp();
        break;

    case sf::Keyboard::S:
        std::cout << "S\n";
        entities->player.moveDown();
        break;

    case sf::Keyboard::A:
        std::cout << "A\n";
        entities->player.moveLeft();
        break;

    case sf::Keyboard::D:
        std::cout << "D\n";
        entities->player.moveRight();
        break;

    default:
        std::cout << "default";
        break;
    }
}
