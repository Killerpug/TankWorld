//
// Created by killer on 11/04/24.
//

#include "World.h"
#include "../entities/player.h"
#include "../graphics/graphics.h"

using namespace std;


World::World(Graphics *graphics) : graphics(graphics) {

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

bool World::handleEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        //User requests quit
        if (e.type == SDL_QUIT) {
        }
    }
}

// https://en.wikipedia.org/wiki/Model%E2%80%93view%E2%80%93controller -> Model View Controller Pattern

void World::gameLoop() {
    //Main loop flag
    Player player01 = Player{};
    graphics->render(player01.playerTexture, player01.mPosX, player01.mPosY, player01.angle, nullptr, nullptr);
    if (!player01.loadPlayer("../res/Gun_07.png", gGraphics->gRenderer)) {
        cout << "Failed to load media " << endl;
    }
    players.push_back(player01);
    cout << "Player loaded";
    //Event handler
    Events event;
    // TODO: fix spawn player logic

    while (true) {
        auto shouldExit = handleEvents();
        if (shouldExit) {
            break;
        }

        //Clear screen
        SDL_SetRenderDrawColor(gGraphics->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gGraphics->gRenderer);
        //Handle Events on queue
        event.update();

        //player01.handleEvent(&event);
        //player01.move();
        //player01.render(gGraphics->gRenderer);

        graphics->render(&player01);
        //Handle input for the player
        for (int i = 0; i < players.size(); i++) {
            players[i].handleEvent(&event);
            players[i].move();
            players[i].render(gGraphics->gRenderer); // TODO: reverse order, pass player to graphics, Drawable interface
        }
        //Render objects
        SDL_RenderPresent(gGraphics->gRenderer);
    }

}
