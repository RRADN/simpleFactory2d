#include "textureManager.hpp"

TextureManager::TextureManager(SDL_Renderer& renderer) :
    player(renderer, getAssetsPath()),
    tiles(renderer, getTilesPath())
{}