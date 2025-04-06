

#include "graphics/graphics.h"
#include "game/world.h"

using namespace std;

int main(int argc, char *args[]) {
    Graphics graphics;
    World game(&graphics);
    game.gameLoop();


    return 0;
}