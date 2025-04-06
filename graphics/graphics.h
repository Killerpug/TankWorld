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

/*
 * Creates the texture from the image provided in the source path of the drawable object.
 */
    bool createObject(Drawable &object);

/*
 * renders the object in the screen.
 * pre-requirements: object must be initialized using createObject
 */
    void renderObject(Drawable &object, int x, int y, double angle, SDL_Point *center, SDL_Rect *clip);


    SDL_Window *gameWindow;
    SDL_Renderer *gameRenderer;

private:
    bool start();


};

#endif // GRAPHICS_H

