#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <string>
#include "../entities/player.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include "drawable.h"

class Graphics {
public:
    Graphics();

    ~Graphics();

    void render(Drawable &object, int x, int y, double angle, SDL_Point *center, SDL_Rect *clip);

    bool createObject(Drawable &object);


    SDL_Window *gameWindow;
    SDL_Renderer *gameRenderer;

private:
    bool start();

};

#endif // GRAPHICS_H
