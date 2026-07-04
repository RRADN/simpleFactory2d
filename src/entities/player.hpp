#pragma once 

#include "primitive/entity.hpp"
#include "../logic/systems/playerMovement.hpp"
#include "../logic/systems/health.hpp"

#include "../core/ids/assetsID.hpp"

#include <string>

class Player : public Entity<AssetsID>{
public:
    Player();
    ~Player() = default;

    void testmoveR ();
    void setInputs(Input& input);
    void update(float deltaTime);

    int getX();
    int getY();

private:
    std::string name;

    Health health {};
    
    PlayerMovement movement {};

};