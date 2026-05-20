#pragma once 

#include <SFML/Graphics.hpp>

class Tile {
private:
    const std::string PATH = " ";
    sf::Texture texture = sf::Texture();
    int layer = 0;

protected:
    sf::Sprite sprite;

public:
    Tile(const std::string& path);
    virtual ~Tile();
    
    void draw();
};
 