#include "sdlWindow.hpp"
#include <stdexcept>

Window::Window( const std::string& title, int width, int height)
: width(width),
  height(height) 
  {
    window = SDL_CreateWindow(
        title.c_str(),
        width,
        height,
        SDL_WINDOW_RESIZABLE
    );

    if (!window)
        throw std::runtime_error(SDL_GetError());

    renderer = SDL_CreateRenderer(
        window,
        nullptr
    );

    if (!renderer)
    {
        SDL_DestroyWindow(window);
        throw std::runtime_error(SDL_GetError());
    }
}

Window::~Window() {
    if (renderer)
        SDL_DestroyRenderer(renderer);

    if (window)
        SDL_DestroyWindow(window);
}

void Window::clear() {
    SDL_SetRenderDrawColor(
        renderer,
        255,
        255,
        255,
        255
    );

    SDL_RenderClear(renderer);
}

void Window::present() {
    SDL_RenderPresent(renderer);
}

void Window::setTitle(const std::string& title) {
    SDL_SetWindowTitle(
        window,
        title.c_str()
    );
}

SDL_Renderer* Window::getRenderer() const {
    return renderer;
}