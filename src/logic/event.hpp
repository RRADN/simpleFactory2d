#pragma once

#include <SFML/Window.hpp>

#include "../platform/sfmlWindow.hpp"
#include "../entities/handlers/entitiesHandler.hpp"

class Event {
private:
    Entities *entities;
    SfmlWindow *window;
public:
    Event(Entities &entities);
    virtual ~Event();

    void playerMove();    
};
