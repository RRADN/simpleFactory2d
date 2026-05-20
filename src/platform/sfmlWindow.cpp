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
    window->setIcon(icon);
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

void SfmlWindow::resize(const sf::Event &event, const auto* resized) {
    sf::FloatRect visibleArea({0.0f, 0.0f}, {static_cast<float>(resized->size.x), static_cast<float>(resized->size.y)});
    window->setView(sf::View(visibleArea));
}

bool SfmlWindow::shouldClose() {
    return !window->isOpen();
}

void SfmlWindow::pollEvent(Event keyboardEvent) {
    while (const std::optional event = window->pollEvent())
    {
        eventSwitch(*event, keyboardEvent);
    }
}

void SfmlWindow::eventSwitch(const sf::Event &event, Event keyboardEvent) {
    keyboardEvent.playerMove();
    
    if (event.is<sf::Event::Closed>()) {   
        window->close();
        throw std::runtime_error("Window closed by user.");
    }
    else if (const auto* resized = event.getIf<sf::Event::Resized>()) {
        resize(event, resized);
    }
    else if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->code == sf::Keyboard::Key::F11) {
            if (isFullscreen) {
                window->create(sf::VideoMode({WIDTH, HEIGHT}), TITLE, sf::Style::Default);
                isFullscreen = false;
            } else {
                window->create(sf::VideoMode::getDesktopMode(), TITLE, sf::State::Fullscreen);
                isFullscreen = true;
            }
        }
    }
}
