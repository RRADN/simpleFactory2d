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
    Event event(entities, window);

    while (!window.shouldClose()) {
        deltaTime = clock.restart().asSeconds();

        window.pollEvent(event);

        update(deltaTime);
        render();
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
