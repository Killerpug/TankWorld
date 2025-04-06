//
// Created by killer on 15/03/24.
//

#ifndef INC_03_SDL_MOTION_PLAYER_H
#define INC_03_SDL_MOTION_PLAYER_H


#include <SDL2/SDL.h>
#include "texture.h"

class Player {
public:
    Player(const std::string &texturePath);


    //The dimensions of the dot


    //Maximum axis velocity of the dot
    static const int PLAYER_SPEED = 5;


    void handleEvent(SDL_Event &e);

    void move();

    //Shows the dot on the screen
    void render(SDL_Renderer *gRenderer);

    LTexture playerTexture;
    std::string resourcePath;
    int playerWidth;
    int playerHeight;
    int mPosX, mPosY;
private:


    int mVelX, mVelY;
    double angle;


};

#endif //INC_03_SDL_MOTION_PLAYER_H
