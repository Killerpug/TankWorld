//
// Created by killer on 21/04/24.
//

#ifndef TANKWORLD_DRAWABLE_H
#define TANKWORLD_DRAWABLE_H

#include "graphics.h"

class Drawable {
public:
    virtual const LTexture &getTexture() = 0;
};

#endif //TANKWORLD_DRAWABLE_H
