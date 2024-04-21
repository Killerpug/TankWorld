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
    World(Graphics *graphics);

    void gameLoop();

private:
    std::vector<Player> players;
    Graphics *gGraphics;

    bool handleEvents();

    bool spawnPlayer();


};


#endif //TANKWORLD_WORLD_H
