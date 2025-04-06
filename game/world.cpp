//
// Created by killer on 5/04/25.
//

#include "world.h"
#include "../entities/player.h"
#include "../graphics/graphics.h"

using namespace std;


World::World(Graphics *graphics) : graphics(graphics) {

}


// https://en.wikipedia.org/wiki/Model%E2%80%93view%E2%80%93controller -> Model View Controller Pattern

void World::gameLoop() {

    Player player01("../res/Gun_07.png");
    graphics->createObject(player01.playerTexture);

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while (!quit) {
        // Handle all events on queue before rendering
        // each time SDL_PollEvent is called, it takes the most recent event and consumes it. when queue is empty this returns 0
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            //Handle input for the player
            player01.handleEvent(e);
        }

        //Move the dot
        player01.move();

        //Clear screen
        SDL_SetRenderDrawColor(graphics->gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(graphics->gameRenderer);

        //Render objects
        graphics->renderObject(player01.playerTexture, player01.mPosX, player01.mPosY, player01.angle, nullptr, nullptr);

        //Update screen
        SDL_RenderPresent(graphics->gameRenderer);
    }


}