#pragma once

#include <iostream>
#include "../platform/sfmlWindow.hpp"
#include "../entities/handlers/entitiesHandler.hpp"

class Game {
public:
    const unsigned int WIDTH = 1280;
    const unsigned int HEIGHT = 720;
    const std::string TITLE = "Simple Factory 2D";
    float deltaTime = 0.0f;

    Game();
    virtual ~Game();
    void run();
private:
    adn::SfmlWindow window {WIDTH, HEIGHT, TITLE};

    Entities entities;

    sf::Clock clock;
    void gameLoop();
    
    void update(float deltaTime);
    void render();
};
