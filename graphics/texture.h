//
// Created by killer on 7/03/24.
//

#ifndef TEXTURE_H
#define TEXTURE_H

//Screen dimension constants
#include <SDL2/SDL_render.h>


#include <SDL2/SDL.h>
#include <string>
#include "drawable.h"

// Texture wrapper class
class Texture : public Drawable {
public:
    Texture(const std::string &texturePath);

    ~Texture();

    void free();

    const int getWidth() override;

    const int getHeight() override;

    SDL_Texture *getTexture() override;

    std::string getResourcePath() override;

    bool setWidth(int width) override;

    bool setHeight(int height) override;

    bool setTexture(SDL_Texture *texture) override;

/*
 * select a new sprite for the texture
 */
    bool setResourcePath(const std::string &resourcePath);

private:
    std::string mResourcePath;
    SDL_Texture *mTexture;    // Actual hardware texture
    int mWidth;
    int mHeight;
};

#endif
