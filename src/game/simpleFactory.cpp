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

void Game::init(){
    player.setInputs(input.getGameInputs());  
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
    render.drawMap(map.getMap());
    render.drawTile(TileID::Grass, 700, 700);
    render.drawPlayer(AssetsID(player.getID()), static_cast<float>(player.getX()), static_cast<float>(player.getY()));
    player.update(timer.getDeltaTime());
}