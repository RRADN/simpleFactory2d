#pragma once

//sfml
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "../logic/event.hpp"

class SfmlWindow {
private:
    unsigned int WIDTH;
    unsigned int HEIGHT;
    std::string TITLE;
    
    bool isFullscreen;

    sf::RenderWindow *window;
    sf::Event event;
    sf::Image icon;

    void initWindow(const unsigned int width, const unsigned int height, const std::string &title);
    void setImageIcon();
    
    void eventSwitch(Event keyboardEvent);
    void resize();
   
public:

    void pollEvent(Event keyboardEvent);
    bool shouldClose();

    void draw(sf::Sprite sprite);
    void clear();
    void display();

    SfmlWindow(const unsigned int width, const unsigned int height, const std::string &title);
    ~SfmlWindow();
};
