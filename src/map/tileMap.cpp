#include "tileMap.hpp"

#include <iostream>

Map::Map() {
    tiles.resize(height);
    int i = 0;

    for (auto& row : tiles) {
        row.resize(width);
        for (int j = 0; j < 10; j++){
            Tile tile {TileID::Grass, false, true};
            tile.setX(j * 64);
            tile.setY(i * 64);
            tiles[i][j] = tile;
        }
        i++;
    }
}

std::vector<std::vector<Tile<TileID>>> Map::getMap() {
    return tiles;
}