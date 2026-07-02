#pragma once

#include "textureMap.hpp"

//IDs
#include "../../core/ids/assetsID.hpp"
#include "../../core/ids/tileID.hpp"

//Paths
#include "../../core/paths/assetsPath.hpp"
#include "../../core/paths/tilesPaths.hpp"

class TextureManager {
public:
    TextureManager(SDL_Renderer& renderer);

    TextureMap<AssetsID> player;

    TextureMap<TileID> tiles;
};