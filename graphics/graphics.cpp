//
// Created by killer on 7/03/24.
//

#include "graphics.h"
#include <SDL2/SDL_image.h>
#include <iostream>


using namespace std;

Graphics::Graphics() {
    std::cout << "graphics" << '\n';
    gWindow = nullptr;
    gRenderer = nullptr;
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
    gWindow = SDL_CreateWindow("SDL example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                               SDL_WINDOW_SHOWN);
    if (gWindow == nullptr) {
        cout << "Window could not be created! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (gRenderer == nullptr) {
        cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }

    cout << "sdl done";
    return true;
}

Graphics::~Graphics() {

    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;
    IMG_Quit();
    SDL_Quit();
}

int LTexture::getWidth() { return mWidth; }

int LTexture::getHeight() { return mHeight; }

// Set rendering space and render to screen.
// Prerequisite: have a loaded texture.
void LTexture::render(int x, int y, double angle, SDL_Point *center, SDL_Rect *clip,
                      SDL_Renderer *sRenderer) {
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};
    SDL_RenderCopyEx(sRenderer, mTexture, nullptr, &renderQuad, angle, nullptr, flip);
}

void LTexture::free() {
    // Free texture if it exists
    if (mTexture != nullptr) {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
    }
}

bool LTexture::loadFromFile(const std::string &path, SDL_Renderer *sRenderer) {
    free();                             // Get rid of preexisting texture

    // Load image
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cout << "Unable to load image %s! SDL_image Error: " << path.c_str() << " "
                  << IMG_GetError() << std::endl;
    } else {
        // Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface(sRenderer, loadedSurface);
        if (mTexture == nullptr) {
            std::cout << "Unable to create texture from %s! SDL Error: "
                      << path.c_str() << " " << SDL_GetError() << std::endl;
        } else {
            // Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    // Return success
    return mTexture != nullptr;
}

LTexture::LTexture() : mTexture(nullptr), mWidth(0), mHeight(0) {

}

LTexture::~LTexture() {
    free();
}


