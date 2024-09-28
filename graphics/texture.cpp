//
// Created by killer on 21/04/24.
//

#include "texture.h"

using namespace std;

const int Texture::getWidth() { return imgWidth; }

const int Texture::getHeight() { return imgHeight; }

SDL_Texture *Texture::getTexture() { return texture; }

// Set rendering space and render to screen.
// Prerequisite: have a loaded texture.


void Texture::free() {
    // Free texture if it exists
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        imgWidth = 0;
        imgHeight = 0;
    }
}


Texture::Texture() : texture(nullptr), imgWidth(0), imgHeight(0) {

}

Texture::~Texture() {
    free();
}

bool Texture::createTextureFromFile(const string &path) {
    free();\
    // Load image
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    texture = nullptr;
    if (loadedSurface == nullptr) {
        cout << "Unable to load image %s! SDL_image Error: " << path.c_str() << " "
             << IMG_GetError() << '\n';
    } else {
        // Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface(nullptr, loadedSurface); // we dont need to render at the moment
        if (texture == nullptr) {
            std::cout << "Unable to create texture from %s! SDL Error: "
                      << path.c_str() << " " << SDL_GetError() << '\n';
        } else {
            // Get image dimensions
            imgWidth = loadedSurface->w;
            imgHeight = loadedSurface->h;
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    // Return success
    return texture != nullptr;

}



