#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <string>
#include "player.h"
#include <SDL2/SDL_image.h>
#include <iostream>

class Drawable; // Forward declaration

class Graphics {
public:
    Graphics();

    ~Graphics();

    void render(Player &player, int x, int y, double angle, SDL_Point *center, SDL_Rect *clip);

    bool createObject(Player &player);

    bool start();

    bool initSDL();
    
    SDL_Window *gameWindow;
    SDL_Renderer *gameRenderer;

private:


};

#endif // GRAPHICS_H
