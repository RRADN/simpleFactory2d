#include "renderManager.hpp"

#include <stdexcept>

Render::Render(SDL_Renderer& renderer) : textures{renderer} {
    this->renderer = &renderer;
}

void Render::drawPlayer(AssetsID id, float x, float y) {
    const SDL_FRect destRect = { x, y, textures.player.getWidth(id), textures.player.getHeight(id)};
    SDL_RenderTexture(renderer, textures.player.getTexure(id), nullptr, &destRect);
}

void Render::drawTile(TileID id, float x, float y) {
    const SDL_FRect destRect = { x, y, textures.tiles.getWidth(id), textures.tiles.getHeight(id)};
    SDL_RenderTexture(renderer, textures.tiles.getTexure(id), nullptr, &destRect);
}