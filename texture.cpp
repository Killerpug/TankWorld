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
        if (mTexture == NULL) {
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
