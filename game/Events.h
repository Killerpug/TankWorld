//
// Created by killer on 11/04/24.
//

#ifndef TANKWORLD_EVENTS_H
#define TANKWORLD_EVENTS_H

#include <SDL2/SDL_events.h>

enum Key {
    KEYUP = SDL_SCANCODE_UP,
    KEYDOWN = SDL_SCANCODE_DOWN,
    KEYLEFT = SDL_SCANCODE_LEFT,
    KEYRIGHT = SDL_SCANCODE_RIGHT,
    QUIT = SDL_SCANCODE_ESCAPE,
};


class Events {

public:
    bool isKeyPressed(int key);

    void update();

private:


    const uint8_t *keyboard;

};


#endif //TANKWORLD_EVENTS_H
