//
// Created by killer on 7/03/24.
//

#ifndef TEXTURE_H
#define TEXTURE_H

//Screen dimension constants
#include <SDL2/SDL_render.h>


#include <SDL2/SDL.h>
#include <string>

// Texture wrapper class
class LTexture {
public:
    LTexture();

    ~LTexture();

    void free();

    int getWidth();

    int getHeight();

    SDL_Texture *getTexture();

    bool setWidth(int width);

    bool setHeight(int height);

    bool setTexture(SDL_Texture *texture);


private:

    SDL_Texture *mTexture;    // Actual hardware texture
    int mWidth;
    int mHeight;
};

#endif
