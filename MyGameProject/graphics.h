
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL_image.h>
#include <string>
#include "defs.h"

using namespace std;


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "Hello World!"; // Const value in .cpp, not in .h !!!



    void logErrorAndExit(const char* msg, const char* error);

    SDL_Window* initWindows();
    SDL_Renderer* initRenderer(SDL_Window* window);

    void prepareScene(SDL_Texture* background, SDL_Renderer* renderer);
    void presentScene(SDL_Renderer* renderer);

    /*void goUp();*/

    SDL_Texture* loadTexture(const char* filename, SDL_Renderer* renderer);

    void renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y);

    void updatePos(SDL_Texture* texture, SDL_Renderer* renderer);


#endif
