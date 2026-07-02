//std
#include <iostream>
#include <stdexcept>
#include <optional>

//SDL
#include <SDL3/SDL.h>

#include "../core/ids/assetsID.hpp"
#include "simpleFactory.hpp"

Game::Game() {
    init();
    run();
}

Game::~Game() {}

void Game::init(){
    player.setInputs(input);  
}

void Game::run() {
    while (events.update()) {  
        window.clear();
        update();
        window.present();
    }
}

void Game::update() {
    timer.update();
    input.update();
    render.drawTile(TileID::Grass, 100, 100);
    render.drawTile(TileID::Grass, 164, 100);
    render.drawPlayer(AssetsID(player.getID()), static_cast<float>(player.getX()), static_cast<float>(player.getY()));
    player.update(timer.getDeltaTime());
}