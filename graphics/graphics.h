#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <string>
#include "../entities/player.h"
#include <SDL2/SDL_image.h>
#include <iostream>

class Graphics {
public:
    Graphics();

    ~Graphics();

    void render(Player &player, int x, int y, double angle, SDL_Point *center, SDL_Rect *clip);

    bool createObject(Player &player);


    SDL_Window *gameWindow;
    SDL_Renderer *gameRenderer;

private:
    bool start();

};

#endif // GRAPHICS_H
