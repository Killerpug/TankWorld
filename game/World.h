//
// Created by killer on 11/04/24.
//

#ifndef TANKWORLD_WORLD_H
#define TANKWORLD_WORLD_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "../graphics/graphics.h"
#include <vector>
#include "../entities/player.h"

class World {
public:
    World();

    void gameLoop();

    Graphics *gGraphics;

private:


    std::vector<Player> players;


    bool spawnPlayer();


};


#endif //TANKWORLD_WORLD_H