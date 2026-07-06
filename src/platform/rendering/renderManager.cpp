#include "renderManager.hpp"

//std
#include <stdexcept>
#include <vector>

Render::Render(SDL_Renderer& renderer) : textures{renderer} {
    this->renderer = &renderer;
}

void Render::drawPlayer(const AssetsID id, float x, float y) {
    const SDL_FRect destRect = { x, y, textures.player.getWidth(id), textures.player.getHeight(id)};
    SDL_RenderTexture(renderer, textures.player.getTexure(id), nullptr, &destRect);
}

void Render::drawTile(const TileID id, float x, float y) {
    const SDL_FRect destRect = { x, y, textures.tiles.getWidth(id), textures.tiles.getHeight(id)};
    SDL_RenderTexture(renderer, textures.tiles.getTexure(id), nullptr, &destRect);
}

void Render::drawMap(std::vector<std::vector<Tile<TileID>>> tileMap) {
    int i = 0;
    for (auto& row : tileMap) {
        for (int j = 0; j < 10; j++){
            const SDL_FRect destRect = {tileMap[i][j].getX(),tileMap[i][j].getY(),
                                    textures.tiles.getWidth(tileMap[i][j].getID()),
                                    textures.tiles.getHeight(tileMap[i][j].getID())}; 
            SDL_RenderTexture(renderer, textures.tiles.getTexure(tileMap[i][j].getID()), nullptr, &destRect);
        }
        i++;
    }
}