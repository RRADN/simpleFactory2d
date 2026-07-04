#include "tile.hpp"

template<typename ID>
Tile<ID>::Tile(ID id, bool solid, bool visible) {
    this->id = id;
    this->solid = solid;
    this->visible = visible;
}

template<typename ID>
Tile<ID>::~Tile() {}

template<typename ID>
void Tile<ID>::setID(ID id){
    this->getID = id;
}

template<typename ID>
void Tile<ID>::setX(float x){
    collision.setXPosition(x);
}

template<typename ID>
void Tile<ID>::setY(float y){
    collision.setYPosition(y);
}

template<typename ID>
ID Tile<ID>::getID() const {
    return id;
}

template<typename ID>
bool Tile<ID>::isSolid() const {
    return solid;
}

template<typename ID>
bool Tile<ID>::isVisible() const {
    return visible;
}
