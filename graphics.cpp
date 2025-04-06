#include <iostream>
#include "graphics.h"


Graphics::Graphics() : gameWindow(nullptr), gameRenderer(nullptr) {
    start();
}

Graphics::~Graphics() {
    if (gameRenderer) {
        SDL_DestroyRenderer(gameRenderer);
    }
    if (gameWindow) {
        SDL_DestroyWindow(gameWindow);
    }
    SDL_Quit();
}

bool Graphics::initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    gameWindow = SDL_CreateWindow("TankWorld", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!gameWindow) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }

    gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!gameRenderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "IMG_Init Error: " << IMG_GetError() << std::endl;
        return false;
    }

    return true;
}

bool Graphics::start() {
    if (!initSDL()) {
        return false;
    }

    // Additional initialization steps can be performed here if needed
    return true;
}

bool Graphics::createObject(Player &player) {

    // Load image
    SDL_Surface *loadedSurface = IMG_Load(player.resourcePath.c_str());
    if (loadedSurface == nullptr) {
        std::cout << "Unable to load image %s! SDL_image Error: " << player.resourcePath.c_str() << " "
                  << IMG_GetError() << std::endl;
    } else {
        // Create texture from surface pixels
        player.playerTexture.setTexture(SDL_CreateTextureFromSurface(gameRenderer, loadedSurface));
        if (player.playerTexture.getTexture() == nullptr) {
            std::cout << "Unable to create texture from %s! SDL Error: "
                      << player.resourcePath.c_str() << " " << SDL_GetError() << std::endl;
        } else {
            // Get image dimensions
            player.playerWidth = loadedSurface->w;
            player.playerHeight = loadedSurface->h;
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    // Return success
    return player.playerTexture.getTexture() != nullptr;
}


void Graphics::render(Player &player, int x, int y, double angle, SDL_Point *center, SDL_Rect *clip) {
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_Rect renderQuad = {x, y, player.playerWidth, player.playerHeight};
    SDL_RenderCopyEx(gameRenderer, player.playerTexture.getTexture(), nullptr, &renderQuad, angle, nullptr, flip);
}