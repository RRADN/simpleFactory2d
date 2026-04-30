// SFML - Simple and Fast Multimedia Library
#include <SFML/Graphics.hpp>
#include "../logic/event.hpp"

//std
#include <optional>

#include "sfmlWindow.hpp"

SfmlWindow::SfmlWindow(const unsigned int width, const unsigned int height, const std::string &title) {
    this->WIDTH = width;
    this->HEIGHT = height;
    this->TITLE = title;
    this->isFullscreen = false;

    initWindow(WIDTH, HEIGHT, TITLE);
}

SfmlWindow::~SfmlWindow() {
    delete window;
}

void SfmlWindow::initWindow(const unsigned int width, const unsigned int height, const std::string &title) {
    window = new sf::RenderWindow(sf::VideoMode({width, height}), title, sf::Style::Default);
    if (window == NULL) {
        throw std::runtime_error("Failed to create the window.");
    }
    setImageIcon();
}

void SfmlWindow::setImageIcon() {
    if (!icon.loadFromFile("assets/logo/logo.png")) {
        throw std::runtime_error("Failed to load the window icon.");
    }
    window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void SfmlWindow::clear() {
    window->clear(sf::Color::White);
}

void SfmlWindow::draw(sf::Sprite sprite) {
    window->draw(sprite);
}

void SfmlWindow::display(){
    window->display();
}

void SfmlWindow::resize() {
    sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
    window->setView(sf::View(visibleArea));
}

bool SfmlWindow::shouldClose() {
    return !window->isOpen();
}

void SfmlWindow::pollEvent(Event keyboardEvent) {
    while(window->pollEvent(event)) {
        eventSwitch(keyboardEvent);
    }
}

void SfmlWindow::eventSwitch(Event keyboardEvent) {
    switch(event.type) {
        case sf::Event::Closed:
            window->close();
            throw std::runtime_error("Window closed by user.");
            break;  

        case sf::Event::Resized:
            resize();
            break;

        case sf::Event::LostFocus:
            break;

        case sf::Event::GainedFocus:
            break;

        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::F11){
                if (isFullscreen) {
                    window->create(sf::VideoMode({WIDTH, HEIGHT}), TITLE, sf::Style::Default);
                    isFullscreen = false;
                    resize();
                } else {
                    window->create(sf::VideoMode::getDesktopMode(), TITLE, sf::Style::Fullscreen);
                    isFullscreen = true;
                    resize();
                }
            } else{
                keyboardEvent.keyboardSwitch(event);
            }
            break;
    }
}
