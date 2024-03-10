
#ifndef Painter_H
#define Painter_H


#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <iostream>


using namespace std;

class BaseObject {

public:
    SDL_Rect rect;
    SDL_Texture* texture;

    BaseObject();
    ~BaseObject();

};


SDL_Window* initWin();
SDL_Renderer* initRen(SDL_Window* window);
void logErrorAndExit(const char* msg, const char* error);
SDL_Texture* loadTexture(const char* filename, SDL_Renderer* renderer);
void render(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect rect);


#endif
