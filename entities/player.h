//
// Created by killer on 15/03/24.
//

#ifndef PLAYER_H
#define PLAYER_H


#include <SDL2/SDL.h>
#include "../graphics/texture.h"

class Player {
public:
    Player(const std::string &texturePath);

    //Maximum axis velocity of the dot
    static const int PLAYER_SPEED = 5;


    void handleEvent(SDL_Event &e);

    void move();

    Texture playerTexture;
    int mPosX, mPosY;
    double angle;
private:


    int mVelX, mVelY;


};

#endif
