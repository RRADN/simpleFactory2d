#include "renderManager.hpp"

#include <stdexcept>

Render::Render(SDL_Renderer& renderer) : textures{renderer}{
    this->renderer = &renderer;
}

void Render::draw(AssetsID id, float x, float y){
    const SDL_FRect destRect = { x, y, textures.player.getWidth(AssetsID::Player), textures.player.getHeight(AssetsID::Player)};
    SDL_RenderTexture(renderer, textures.player.getTexure(AssetsID::Player), nullptr, &destRect);
}