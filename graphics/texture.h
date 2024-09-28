//
// Created by killer on 21/04/24.
//

#ifndef TANKWORLD_TEXTURE_H
#define TANKWORLD_TEXTURE_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "drawable.h"

// Texture wrapper class
class Texture : public Drawable {
public:
    Texture();

    ~Texture();

    void free();

    bool createTextureFromFile(const std::string &path);


    const int getWidth() override;

    const int getHeight() override;

    SDL_Texture *getTexture() override;

private:

    SDL_Texture *texture;    // Actual hardware texture
    int imgWidth;
    int imgHeight;
};

#endif //TANKWORLD_TEXTURE_H
