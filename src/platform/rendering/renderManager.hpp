#pragma once

#include <SDL3/SDL.h>

#include "../../core/ids/assetsID.hpp"
#include "textureManager.hpp"

class Render{
public:
    Render(SDL_Renderer& renderer);
    ~Render() = default;

    void drawPlayer(AssetsID id, float x, float y);
    void drawTile(TileID id, float x, float y);
    
private:
    SDL_Renderer* renderer;

    TextureManager textures;
};