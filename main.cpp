#include <SDL2/SDL.h>

#include <SDL2/SDL_image.h>
#include "player.h"
#include "texture.h"
#include <iostream>
#include "graphics.h"

using namespace std;

bool init();

void close();

//The window and what we will be rendering
SDL_Window *gWindow = nullptr;
SDL_Renderer *gRenderer = nullptr;

//Start up SDL and create window


//Frees media and shuts down SDL subsystems
void close() {
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char *args[]) {
    Graphics graphics;
    Player player01("../Gun_07.png");

    if (!graphics.createObject(player01)) {
        cout << "Failed to load media " << endl;
    } else {
        //Main loop flag
        bool quit = false;

        //Event handler
        SDL_Event e;

        //While application is running
        while (!quit) {
            //Handle events on queue
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
            SDL_SetRenderDrawColor(graphics.gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(graphics.gameRenderer);

            //Render objects
            graphics.render(player01, player01.mPosX, player01.mPosY, 0, nullptr, nullptr);

            //Update screen
            SDL_RenderPresent(graphics.gameRenderer);
        }
    }


    //Free resources and close SDL
    close();

    return 0;
}