#pragma once

#include <SDL3/SDL.h>
#include <string>

class Window {
public:

    Window(
        const std::string& title,
        int width,
        int height
    );

    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    Window(Window&&) noexcept;
    Window& operator=(Window&&) noexcept;

    void clear();
    void present();

    void setTitle(const std::string& title);

    int getWidth() const;
    int getHeight() const;

    SDL_Renderer* getRenderer() const;

private:

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    int width;
    int height;
};