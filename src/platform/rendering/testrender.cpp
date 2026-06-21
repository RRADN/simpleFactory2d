#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class Render {
    private:

    SDL_Texture* texture = nullptr;

    float width = 200;
    float height = 200;

public:
    Render(){};
    ~Render(){}; 

    bool load(SDL_Renderer* renderer, const std::string& path) {
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface) {
        std::cerr << "Failed to load image: " << SDL_GetError() << std::endl;
        return false;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
        SDL_DestroySurface(surface);
        return false;
    } else {
        this->width = surface->w;
        this->height = surface->h;
    }
    SDL_DestroySurface(surface);
    return true;
    }

    void draw(SDL_Renderer* renderer, float x, float y){
    if (!texture) {
        std::cerr << "Texture not loaded. Cannot draw." << std::endl;
        return;
    }
    std::cout << "Drawing texture at (" << x << ", " << y << ") with size (" << width << ", " << height << ")" << std::endl;
    const SDL_FRect destRect = { x, y , width, height };
    SDL_RenderTexture(renderer, texture, nullptr, &destRect);
    }
};