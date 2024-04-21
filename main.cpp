#include <SDL2/SDL.h>

#include <SDL2/SDL_image.h>
#include "entities/player.h"
#include "graphics/graphics.h"
#include "game/World.h"
#include <iostream>

using namespace std;

//Frees media and shuts down SDL subsystems


int main(int argc, char *args[]) {
    Graphics graphics;
    World game(&graphics); //iniciar juego con graficos.
    game.gameLoop();
    //Free resources and close SDL
    return 0;
}