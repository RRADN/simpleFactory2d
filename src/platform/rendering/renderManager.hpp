#pragma once

#include <SDL3/SDL.h>

#include <string>

class Render{
public:
    Render();
    ~Render();

    bool load(SDL_Renderer* renderer);
    void draw(SDL_Renderer* renderer);

private:
    void loadTexture(SDL_Renderer* renderer, const std::string& path);

};