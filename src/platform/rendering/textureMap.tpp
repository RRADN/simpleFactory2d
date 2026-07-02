#include "textureMap.hpp"
#include "texture.hpp"

#include <unordered_map>
#include <string>

#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_render.h>

template<typename ID>
TextureMap<ID>::TextureMap(SDL_Renderer& renderer, const std::unordered_map<ID, std::string>& paths) {
    load(renderer,paths);
}

template<typename ID>
TextureMap<ID>::~TextureMap() {
    for (auto& [id, data] : textures) {
        (void)id;
        if (data.texture) {
            SDL_DestroyTexture(data.texture);
            data.texture = nullptr;
        }
    }
}

template<typename ID>
bool TextureMap<ID>::load(SDL_Renderer& renderer, const std::unordered_map<ID, std::string>& paths) {
    for(const auto& [id,path] : paths) {
        SDL_Surface* surface = IMG_Load(path.c_str());
        verifySurface(surface);

        SDL_Texture* texture = SDL_CreateTextureFromSurface(&renderer, surface);
        verifyTexture(texture, surface);

        auto existing = textures.find(id);
        if (existing != textures.end() && existing->second.texture) {
            SDL_DestroyTexture(existing->second.texture);
        }   

        Texture data;
        data.texture = texture;
        data.width = static_cast<float>(surface->w);
        data.height = static_cast<float>(surface->h);
        textures[id] = data;

        SDL_DestroySurface(surface);
    }
    return true;
}

template<typename ID>
SDL_Texture* TextureMap<ID>::getTexure(ID id) {
    auto it = textures.find(id);

    if(it == textures.end())
        return nullptr;

    return it->second.texture;
}

template<typename ID>
float TextureMap<ID>::getWidth(ID id)
{
    auto it = textures.find(id);

    if(it == textures.end())
        return 0.f;

    return it->second.width;
}

template<typename ID>
float TextureMap<ID>::getHeight(ID id)
{
    auto it = textures.find(id);

    if(it == textures.end())
        return 0.f;

    return it->second.height;
}

template<typename ID> 
void TextureMap<ID>::verifySurface(SDL_Surface* surface) {
    if (!surface) {
    throw std::runtime_error(std::string("Failed to load image ") + " | " + SDL_GetError());
    }
}

template<typename ID> 
void TextureMap<ID>::verifyTexture(SDL_Texture* texture, SDL_Surface* surface) {
    if (!texture) {
    SDL_DestroySurface(surface);
    throw std::runtime_error(std::string("Failed to create texture: ") + " | " + SDL_GetError());
    }
}
