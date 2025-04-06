//
// Created by killer on 15/03/24.
//

#include "player.h"
#include <iostream>

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;

//Takes key presses and adjusts the dot's velocity
void Player::handleEvent(SDL_Event &e) {
    // do action
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_UP:
                mVelY -= PLAYER_SPEED;
                angle = 0;
                break;
            case SDLK_DOWN:
                mVelY += PLAYER_SPEED;
                angle = 180;
                break;
            case SDLK_LEFT:
                mVelX -= PLAYER_SPEED;
                angle = 270;
                break;
            case SDLK_RIGHT:
                mVelX += PLAYER_SPEED;
                angle = 90;
                break;
        }
    } // cancel action
    else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_UP:
                mVelY += PLAYER_SPEED;
                break;
            case SDLK_DOWN:
                mVelY -= PLAYER_SPEED;
                break;
            case SDLK_LEFT:
                mVelX += PLAYER_SPEED;
                break;
            case SDLK_RIGHT:
                mVelX -= PLAYER_SPEED;
                break;
        }
    }
    std::cout << "ball speed: x = " << mVelX << " y = " << mVelY << std::endl;
}

void Player::move() {
    //Move the dot up/down or left/right
    //If the dot went too far
    //Move back
    mPosY += mVelY;
    if ((mPosY < 0) || (mPosY + playerHeight > SCREEN_HEIGHT)) {
        mPosY -= mVelY;
    }
    mPosX += mVelX;
    if ((mPosX < 0) || (mPosX + playerWidth > SCREEN_WIDTH)) {
        mPosX -= mVelX;
    }
}


Player::Player(const std::string &texturePath) {
    mPosX = 0;
    mPosY = 0;
    mVelX = 0;
    mVelY = 0;
    playerWidth = 0;
    playerHeight = 0;
    resourcePath = texturePath;
}

