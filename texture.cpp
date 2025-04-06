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


LTexture::LTexture() : mTexture(nullptr), mWidth(0), mHeight(0) {

}

LTexture::~LTexture() {
    free();
}

bool LTexture::setTexture(SDL_Texture *texture) {
    mTexture = texture;
    return true;

}

SDL_Texture *LTexture::getTexture() {
    return mTexture;
}
