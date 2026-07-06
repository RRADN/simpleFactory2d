#pragma once

#include <string>
#include <unordered_map>

#include "../ids/tileID.hpp"

inline std::unordered_map<TileID, std::string> getTilesPath() {
    return {
        {TileID::Grass, "assets/textures/tiles/tile.png"}
    };
}