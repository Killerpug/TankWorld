//
// Created by killer on 5/04/25.
//

#ifndef TANKWORLD_DRAWABLE_H
#define TANKWORLD_DRAWABLE_H


#include "graphics.h"
#include "texture.h"

class Drawable {
public:
    virtual SDL_Texture *getTexture() = 0;

    virtual const int getWidth() = 0;

    virtual const int getHeight() = 0;
};


#endif //TANKWORLD_DRAWABLE_H
