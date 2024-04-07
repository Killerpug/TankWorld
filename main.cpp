#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "player.h"
#include "texture.h"
#include <iostream>

using namespace std;

bool init();

void close();

//The window and what we will be rendering
SDL_Window *gWindow = nullptr;
SDL_Renderer *gRenderer = nullptr;

//Start up SDL and create window
bool init() {
    bool result = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL could not initialize, error: " << SDL_GetError() << endl;
        result = false;
    } else {
        // hints allow us to give desired behavior of the application
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            cout << "Warning: Linear texture filtering not enabled! " << SDL_GetError() << endl;
        }
        gWindow = SDL_CreateWindow("SDL example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                   SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == nullptr) {
            cout << "Window could not be created! SDL Error: " << SDL_GetError() << endl;
            result = false;
        } else {
            //Create vsynced renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1,
                                           SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == nullptr) {
                cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
                result = false;
            } else {
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    cout << "SDL_image could not initialize! SDL_image Error: " << SDL_GetError()
                         << endl;
                    result = false;
                }
            }
        }
    }

    return result;
}

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
    Player player01;
    if (!init()) {
        cout << "Failed to initialize! " << endl;
    } else {
        if (!player01.loadPlayer("../Gun_07.png", gRenderer)) {
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
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);

                //Render objects
                player01.render(gRenderer);

                //Update screen
                SDL_RenderPresent(gRenderer);
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}