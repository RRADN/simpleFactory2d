#pragma once 

#include "../../logic/systems/collision.hpp"

template<typename ID>
class Tile {
public:
    Tile();
    Tile(ID id, bool solid, bool visible);
    ~Tile() = default;

    void setID (ID id);
    void setX (float x);
    void setY (float y);

    ID getID() const;
    float getX() const;
    float getY() const;

    bool isSolid() const;
    bool isVisible() const;

private:
    Collision collision {0,0,63,63};

    ID id;

    bool solid;
    bool visible;

};

#include "tile.tpp"