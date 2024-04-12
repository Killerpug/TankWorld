//
// Created by killer on 11/04/24.
//

#include "World.h"
#include "../entities/player.h"
#include "../graphics/graphics.h"

using namespace std;


World::World() {


}


bool World::spawnPlayer() {


    return true;
}

/*
bool World::spawnPlayer() {
    Player player01;
    if (!player01.loadPlayer("../res/Gun_07.png", gGraphics->gRenderer)) {
        cout << "Failed to load media " << endl;
        return false;
    }
    cout << "Player loaded";
    player01.render(gGraphics->gRenderer);
    SDL_RenderPresent(gGraphics->gRenderer);
    players.push_back(player01);
    return true;
}
 * */

void World::gameLoop() {
    //Main loop flag
    bool quit = false;
    Player player01 = Player{};
    if (!player01.loadPlayer("../res/Gun_07.png", gGraphics->gRenderer)) {
        cout << "Failed to load media " << endl;
    }
    players.push_back(player01);
    cout << "Player loaded";
    //Event handler
    Events event;
    spawnPlayer();
    //Event handler
    SDL_Event e;
    //While application is running
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        //Clear screen
        SDL_SetRenderDrawColor(gGraphics->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gGraphics->gRenderer);
        //Handle Events on queue
        event.update();

        //player01.handleEvent(&event);
        //player01.move();
        //player01.render(gGraphics->gRenderer);


        //Handle input for the player
        for (int i = 0; i < players.size(); i++) {
            players[i].handleEvent(&event);
            players[i].move();
            players[i].render(gGraphics->gRenderer);
        }
        //Render objects
        SDL_RenderPresent(gGraphics->gRenderer);
    }

}
