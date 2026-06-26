#include "tile.hpp"

Tile::Tile() {
}

Tile::~Tile() {
}

bool Tile::isSolid() const {
    return solid;
}

bool Tile::isVisible() const {
    return visible;
}
