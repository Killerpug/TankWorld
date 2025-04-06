//
// Created by killer on 5/04/25.
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
    Graphics *graphics;


};


#endif //TANKWORLD_WORLD_H
