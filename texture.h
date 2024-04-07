//
// Created by killer on 7/03/24.
//

#ifndef INC_02_SDL_RENDERING_TEXTURE_H
#define INC_02_SDL_RENDERING_TEXTURE_H

//Screen dimension constants
#include <SDL2/SDL_render.h>

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;

#include <SDL2/SDL.h>
#include <string>

// Texture wrapper class
class LTexture {
public:
    LTexture();

    ~LTexture();

    bool loadFromFile(const std::string &path, SDL_Renderer *sRenderer);

    void free();

    void
    render(int x, int y, double angle, SDL_Point *center, SDL_Rect *clip, SDL_Renderer *gRenderer);

    int getWidth();

    int getHeight();

private:

    SDL_Texture *mTexture;    // Actual hardware texture
    int mWidth;
    int mHeight;
};

#endif // INC_02_SDL_RENDERING_TEXTURE_H
