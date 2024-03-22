//
// Created by killer on 7/03/24.
//

#include "texture.h"
#include <SDL2/SDL_image.h>
#include <iostream>

int LTexture::getWidth() { return mWidth; }

int LTexture::getHeight() { return mHeight; }

// Set rendering space and render to screen.
// Prerequisite: have a loaded texture.
void LTexture::render(int x, int y, SDL_Renderer *sRenderer) {
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};
    SDL_RenderCopy(sRenderer, mTexture, NULL, &renderQuad);
}

void LTexture::free() {
    // Free texture if it exists
    if (mTexture != NULL) {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

bool LTexture::loadFromFile(const std::string &path, SDL_Renderer *sRenderer) {
    free();                             // Get rid of preexisting texture
    SDL_Texture *newTexture = NULL;     // The final texture

    // Load image
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        std::cout << "Unable to load image %s! SDL_image Error: " << path.c_str() << " "
                  << IMG_GetError() << std::endl;
    } else {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(sRenderer, loadedSurface);
        if (newTexture == NULL) {
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
    mTexture = newTexture;
    return mTexture != NULL;
}

LTexture::LTexture() {
    // Initialize
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture() {
    free();
}
