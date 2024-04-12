#include <SDL2/SDL.h>

#include <SDL2/SDL_image.h>
#include "entities/player.h"
#include "graphics/graphics.h"
#include "game/World.h"
#include <iostream>

using namespace std;

//Frees media and shuts down SDL subsystems


int main(int argc, char *args[]) {

    World game;
    Graphics graphics;
    game.gGraphics = &graphics;
    game.gameLoop();
    //Free resources and close SDL
    return 0;
}