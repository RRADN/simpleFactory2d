 #pragma once
 
 #include <iostream>
 #include "SFML/Graphics.hpp"

class Entity {    
protected:
    const std::string PATH = " ";
    sf::Texture texture = sf::Texture();

public:
    sf::Sprite sprite;
    
    void update(sf::Vector2f movement);

    Entity(const std::string &path);
    virtual ~Entity();
    
};
