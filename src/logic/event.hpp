#pragma once

#include <SFML/Window.hpp>

#include "../platform/sfmlWindow.hpp"
#include "../entities/handlers/entitiesHandler.hpp"

class Event {
private:
    Entities *entities;
    adn::SfmlWindow *window;
    
public:
    Event(Entities &entities, adn::SfmlWindow &window);
    virtual ~Event();

    void playerMove(const sf::Event &event);    
};
