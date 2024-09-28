//
// Created by killer on 15/03/24.
//

#ifndef INC_03_SDL_MOTION_PLAYER_H
#define INC_03_SDL_MOTION_PLAYER_H


#include <SDL2/SDL.h>
#include "../graphics/graphics.h"
#include "../game/Events.h"

//TODO: Implement an interface so that player can send information to graphics, instead of player receiving the graphics.
class Player {
public:
    Player();

    bool loadPlayer(const std::string &texturePath);

    //Maximum axis velocity of the dot
    const int PLAYER_SPEED = 5;

    void handleEvent(Events *events);

    void move();

    int mPosX, mPosY;
    int mVelX, mVelY;
    double angle;

    Texture *playerTexture;
private:
    Texture texture;
    int playerWidth;
    int playerHeight;


};


#endif //INC_03_SDL_MOTION_PLAYER_H
