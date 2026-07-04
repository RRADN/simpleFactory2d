#pragma once 

#include <vector>

#include "tile/tile.hpp"

#include "../core/ids/tileID.hpp"

class Map {
public:
    Map();
    ~Map() = default;

    void update();

private:
    std::vector<Tile<TileID>> tiles;
};