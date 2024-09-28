//
// Created by killer on 7/03/24.
//

#include "graphics.h"
#include <SDL2/SDL_image.h>
#include <iostream>


using namespace std;

Graphics::Graphics() : gameWindow(nullptr), gameRenderer(nullptr) {
    std::cout << "graphics" << '\n';
    start();
}

bool Graphics::initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL could not initialize, error: " << SDL_GetError() << '\n';
        return false;
    }
    if (SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1") == SDL_FALSE) {
        cout << "Warning: Linear texture filtering not enabled! " << SDL_GetError() << '\n';
        return false;
    }

    const int imgFlags = IMG_INIT_PNG;
    if ((IMG_Init(imgFlags) & imgFlags) == 0) {
        cout << "SDL_image could not initialize! SDL_image Error: " << SDL_GetError()
             << '\n';
        return false;
    }
    return true;
}

//Start up SDL and create window
bool Graphics::start() {
    initSDL();
    gameWindow = SDL_CreateWindow("SDL example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
    if (gameWindow == nullptr) {
        cout << "Window could not be created! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (gameRenderer == nullptr) {
        cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }

    cout << "sdl done";
    return true;
}

Graphics::~Graphics() {

    SDL_DestroyRenderer(gameRenderer);
    SDL_DestroyWindow(gameWindow);
    gameWindow = nullptr;
    gameRenderer = nullptr;
    IMG_Quit();
    SDL_Quit();
}

void Graphics::render(Drawable *drawable, int x, int y, double angle, SDL_Point *center, SDL_Rect *clip) {
    SDL_RendererFlip const flip = SDL_FLIP_NONE;

    SDL_Rect renderQuad = {x, y, drawable->getWidth(), drawable->getHeight()};
    SDL_RenderCopyEx(gameRenderer, drawable->getTexture(), nullptr, &renderQuad, angle, nullptr, flip);

}




