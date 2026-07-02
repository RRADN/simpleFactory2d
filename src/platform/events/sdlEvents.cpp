#include "sdlEvents.hpp"

#include <iostream>

Events::Events() {
    shouldClose = false;
}

Events::~Events() {}  

bool Events::update() {
    inputCase();
    
    return !shouldClose;
}


void Events::inputCase() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            shouldClose = true;
        }
    }  
}
