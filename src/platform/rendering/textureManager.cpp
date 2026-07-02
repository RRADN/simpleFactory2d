#include "textureManager.hpp"

TextureManager::TextureManager(SDL_Renderer& renderer) :
    player(renderer, AssetsPath),
    tiles(renderer, TilesPath)
{}