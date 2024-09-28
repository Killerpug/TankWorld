#include <SDL2/SDL.h>

#include <SDL2/SDL_image.h>
#include "entities/player.h"
#include "graphics/graphics.h"
#include "game/World.h"
#include <iostream>

using namespace std;

int main(int argc, char *args[]) {
    Graphics graphics;
    World game(&graphics);
    game.gameLoop();
    //Free resources and close SDL
    return 0;
}