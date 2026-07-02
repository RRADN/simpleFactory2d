#pragma once

#include "texture.hpp"

#include <unordered_map>
#include <string>
#include <stdexcept>

#include <SDL3/SDL_render.h>

template<typename ID> 
class TextureMap {
public:
    TextureMap(SDL_Renderer& renderer, const std::unordered_map<ID, std::string>& paths);
    ~TextureMap();

    SDL_Texture* getTexure(ID id);

    float getWidth(ID id);

    float getHeight(ID id);

    void clear();

private:
    bool load(SDL_Renderer& renderer, const std::unordered_map<ID, std::string>& paths);

    void verifySurface(SDL_Surface* surface);
    void verifyTexture(SDL_Texture* texture, SDL_Surface* surface);

    std::unordered_map<ID, Texture> textures;
};

#include "textureMap.tpp"