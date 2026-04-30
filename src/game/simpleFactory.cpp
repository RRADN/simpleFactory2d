//std
#include <iostream>
#include <stdexcept>
#include <optional>

#include "../entities/handlers/entitiesHandler.hpp"
#include "../logic/event.hpp"

#include "simpleFactory.hpp"

Game::Game() {

}

Game::~Game() {

}

void Game::run() {
    gameLoop();
}

void Game::gameLoop() {
    float deltaTime = clock.restart().asSeconds();
    Event event(entities);

    while (!window.shouldClose()) {
        window.pollEvent(event);

        deltaTime = clock.restart().asSeconds();
        if (sf::Keyboard::W) {
            entities.player.moveUp();
        }

        render();
        update(deltaTime);
    }
}

void Game::update(float deltaTime) {
    entities.update(deltaTime);
}

void Game::render() {
    window.clear();
    window.draw(entities.getPlayerSprite());
    window.display();
}
