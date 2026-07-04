#pragma once

#include <unordered_map>
#include <string>
#include "../ids/assetsID.hpp"

const std::unordered_map<AssetsID, std::string> AssetsPath = {
    {AssetsID::Player,  "assets/textures/player/player.png"},
    {AssetsID::Tiles,   "assets/textures/noTexture.png"},
    {AssetsID::NoTexture, "assets/textures/noTexture.png"}
};