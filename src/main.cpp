#include <stdexcept>

#include "game/simpleFactory.hpp"

int main(){
    try {
        Game game;
    } catch (const std::exception& e) {
        std::cerr << "Program terminated: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
