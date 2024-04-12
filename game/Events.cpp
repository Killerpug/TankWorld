//
// Created by killer on 11/04/24.
//

#include "Events.h"
#include "../entities/player.h"

void Events::update() {
    keyboard = SDL_GetKeyboardState(nullptr);

}

bool Events::isKeyPressed(int key) {
    return keyboard[key] == 1;
}
