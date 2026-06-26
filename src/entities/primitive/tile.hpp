#pragma once 

class Tile {
public:
    Tile();
    ~Tile();

    bool isSolid() const;
    bool isVisible() const;

private:
    bool solid;
    bool visible;

};