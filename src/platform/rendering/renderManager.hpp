#pragma once

#include <SDL3/SDL.h>

#include "../../core/ids/assetsID.hpp"

#include "textureManager.hpp"

#include "../../map/tile/tile.hpp"

#include "../../logic/input/inputs.hpp"

//std
#include <stdexcept>
#include <vector>

class Render{
public:
    Render(SDL_Renderer& renderer, SystemInputs& inputs);
    ~Render() = default;

    void drawPlayer(const AssetsID id, float x, float y);
    void drawTile(const TileID id, float x, float y);
    void drawMap(std::vector<std::vector<Tile<TileID>>> tileMap);
private:
    SystemInputs* inputs;

    SDL_Renderer* renderer;

    TextureManager textures;
};