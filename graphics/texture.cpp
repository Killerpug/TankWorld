//
// Created by killer on 7/03/24.
//

#include "texture.h"
#include <SDL2/SDL_image.h>
#include <iostream>


void Texture::free() {
    // Free texture if it exists
    if (mTexture != nullptr) {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
    }
}


Texture::Texture(const std::string &texturePath) : mResourcePath(texturePath), mTexture(nullptr), mWidth(0), mHeight(0) {

}

Texture::~Texture() {
    free();
}

const int Texture::getWidth() { return mWidth; }

const int Texture::getHeight() { return mHeight; }

SDL_Texture *Texture::getTexture() {
    return mTexture;
}

std::string Texture::getResourcePath() {
    return mResourcePath;
}

bool Texture::setWidth(int width) {
    mWidth = width;
    return true;
}

bool Texture::setHeight(int height) {
    mHeight = height;
    return true;
}

bool Texture::setTexture(SDL_Texture *texture) {
    mTexture = texture;
    return true;

}


bool Texture::setResourcePath(const std::string &resourcePath) {
    mResourcePath = resourcePath;
    return true;
}

