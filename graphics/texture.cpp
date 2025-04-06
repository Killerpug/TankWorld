//
// Created by killer on 7/03/24.
//

#include "texture.h"
#include <SDL2/SDL_image.h>
#include <iostream>


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

const int LTexture::getWidth() { return mWidth; }

const int LTexture::getHeight() { return mHeight; }

SDL_Texture *LTexture::getTexture() {
    return mTexture;
}

std::string LTexture::getResourcePath() {
    return mResourcePath;
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


bool LTexture::setResourcePath(const std::string &resourcePath) {
    mResourcePath = resourcePath;
    return true;
}




