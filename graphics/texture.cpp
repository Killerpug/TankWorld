//
// Created by killer on 7/03/24.
//

#include "texture.h"
#include <SDL2/SDL_image.h>
#include <iostream>

int LTexture::getWidth() { return mWidth; }

int LTexture::getHeight() { return mHeight; }


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

bool LTexture::setWidth(int width) {
    mWidth = width;
    return true;
}

bool LTexture::setHeight(int height) {
    mHeight = height;
    return true;
}

bool LTexture::setTexture(SDL_Texture *texture) {
    mTexture = texture;
    return true;

}

SDL_Texture *LTexture::getTexture() {
    return mTexture;
}


