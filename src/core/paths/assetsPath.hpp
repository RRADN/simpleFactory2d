#pragma once

#include <string>
#include <unordered_map>

#include "../ids/assetsID.hpp"

inline std::unordered_map<AssetsID, std::string> getAssetsPath() {
    return {
        {AssetsID::Player, "assets/textures/player/player.png"},
        {AssetsID::Tiles, "assets/textures/noTexture.png"},
        {AssetsID::NoTexture, "assets/textures/noTexture.png"}
    };
}