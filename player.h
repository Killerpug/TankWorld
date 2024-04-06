//
// Created by killer on 15/03/24.
//

#ifndef INC_03_SDL_MOTION_PLAYER_H
#define INC_03_SDL_MOTION_PLAYER_H


#include <SDL2/SDL.h>
#include "texture.h"

class Player {
public:
    Player();

    bool loadPlayer(const std::string &texturePath, SDL_Renderer *sRenderer);

    //The dimensions of the dot


    //Maximum axis velocity of the dot
    static const int PLAYER_SPEED = 5;


    void handleEvent(SDL_Event &e);

    void move();

    //Shows the dot on the screen
    void render(SDL_Renderer *gRenderer);


private:
    int playerWidth;
    int playerHeight;
    int mPosX, mPosY;
    int mVelX, mVelY;
    double angle;

    LTexture playerTexture;
};

#endif //INC_03_SDL_MOTION_PLAYER_H
