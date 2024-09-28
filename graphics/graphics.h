//
// Created by killer on 7/03/24.
//

#ifndef INC_02_SDL_RENDERING_TEXTURE_H
#define INC_02_SDL_RENDERING_TEXTURE_H


#include <SDL2/SDL_render.h>
#include <SDL2/SDL.h>
#include <string>
#include "drawable.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;


class Graphics {
public:
    Graphics();

    ~Graphics();

    void render(Drawable *drawable, int x, int y, double angle, SDL_Point *center, SDL_Rect *clip);
    

private:
    SDL_Window *gameWindow;
    SDL_Renderer *gameRenderer;

    bool start();

    bool initSDL();


};


#endif // INC_02_SDL_RENDERING_TEXTURE_H
