#pragma once
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <iostream>


#ifndef Painter_H
#define Painter_H

using namespace std;

class BaseObject {

public:
    SDL_Rect rect;
    BaseObject();
    ~BaseObject();

    void SetRect(const int& x, const int& y) {

        rect.x = x;
        rect.y = y;
    }

    SDL_Rect GetRect() const { return rect; }


protected:

    SDL_Texture* texture;
};

SDL_Window* initWin();
SDL_Renderer* initRen(SDL_Window* window);
void logErrorAndExit(const char* msg, const char* error);
SDL_Texture* loadTexture(const char* filename, SDL_Renderer* renderer);
void render(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect rect);



#endif
