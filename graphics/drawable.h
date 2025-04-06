//
// Created by killer on 5/04/25.
//

#ifndef TANKWORLD_DRAWABLE_H
#define TANKWORLD_DRAWABLE_H


class Drawable {
public:
    virtual SDL_Texture *getTexture() = 0;


    virtual const int getWidth() = 0;

    virtual const int getHeight() = 0;

    virtual std::string getResourcePath() = 0;

    virtual bool setTexture(SDL_Texture *texture) = 0;

    virtual bool setWidth(int width) = 0;

    virtual bool setHeight(int height) = 0;
};


#endif //TANKWORLD_DRAWABLE_H
