#pragma once 

#include <vector>

#include "tile/tile.hpp"

#include "../core/ids/tileID.hpp"

class Map {
public:
    Map();
    ~Map() = default;

    void update();

    std::vector<std::vector<Tile<TileID>>> getMap();

private:
    int width = 10;
    int height = 10;
    std::vector<std::vector<Tile<TileID>>> tiles;
};