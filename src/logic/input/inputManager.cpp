#include "inputManager.hpp"

#include <iostream>

#include <SDL3/SDL_scancode.h>

Input::Input() {}

SystemInputs& Input::getSystemInputs() {
    return systemInputs;
}

GameInputs& Input::getGameInputs() {
    return gameInputs;
}

void Input::update() {
    keys.update();
    systemUpdate();
    gameUpdate();
}

void Input::systemUpdate() {
    if (keys.isKeyPressed (SDL_SCANCODE_ESCAPE)) {
        systemInputs.paused = !systemInputs.paused;
    }
    if (keys.isKeyPressed(SDL_SCANCODE_LALT)){
        systemInputs.debuging = !systemInputs.debuging;
    }
}

void Input::gameUpdate() {
    gameInputs.SHIFT = keys.isKeyDown(SDL_SCANCODE_LSHIFT);
    gameInputs.Q = keys.isKeyDown(SDL_SCANCODE_Q);
    gameInputs.W = keys.isKeyDown(SDL_SCANCODE_W);
    gameInputs.E = keys.isKeyDown(SDL_SCANCODE_E);
    gameInputs.A = keys.isKeyDown(SDL_SCANCODE_A);
    gameInputs.S = keys.isKeyDown(SDL_SCANCODE_S);
    gameInputs.D = keys.isKeyDown(SDL_SCANCODE_D);
    gameInputs.Z = keys.isKeyDown(SDL_SCANCODE_Z);
    gameInputs.X = keys.isKeyDown(SDL_SCANCODE_X);
    gameInputs.C = keys.isKeyDown(SDL_SCANCODE_C);
}