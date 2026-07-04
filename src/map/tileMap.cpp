#include "tileMap.hpp"

Map::Map() {
    for (int i; sizeof(tiles); i++) {
        Tile tile {TileID::Grass,0,0};
        tiles[i] = tile;
    }
}