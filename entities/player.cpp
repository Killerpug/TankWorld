//
// Created by killer on 15/03/24.
//

#include "player.h"
#include <iostream>

bool Player::loadPlayer(const std::string &texturePath) {
    texture.createTextureFromFile(texturePath);
    playerTexture = texture;
    if (!playerTexture.createTextureFromFile()) {
        return false;
    }
    playerWidth = playerTexture.getWidth();
    playerHeight = playerTexture.getHeight();
    return true;
}

//Takes key presses and adjusts the dot's velocity
void Player::handleEvent(Events *event) {

    if (event->isKeyPressed(SDL_SCANCODE_UP)) {
        mVelY = -PLAYER_SPEED;
        mVelX = 0;
        angle = 0;
    } else if (event->isKeyPressed(SDL_SCANCODE_DOWN)) {
        mVelY = PLAYER_SPEED;
        mVelX = 0;
        angle = 180;
    } else if (event->isKeyPressed(SDL_SCANCODE_LEFT)) {
        mVelX = -PLAYER_SPEED;
        mVelY = 0;
        angle = 270;
    } else if (event->isKeyPressed(SDL_SCANCODE_RIGHT)) {
        mVelX = PLAYER_SPEED;
        mVelY = 0;
        angle = 90;
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


Player::Player() {
    mPosX = 0;
    mPosY = 0;
    mVelX = 0;
    mVelY = 0;
    playerWidth = 0;
    playerHeight = 0;
    playerTexture = nullptr;
}




