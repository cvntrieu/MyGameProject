#pragma once
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <iostream>

#ifndef Painter_H
#define Painter_H

using namespace std;

struct Graphics {
    SDL_Renderer* renderer;
    SDL_Window* window;

   // Graphics() {};

    void init();
    void prepareScene(SDL_Texture* background);
    void presentScene();
    SDL_Texture* loadTexture(string path);
    void renderTexture(SDL_Texture* texture, int x, int y);
    void logErrorAndExit(const char* msg, const char* error);
    void quit();
  //  void drawSomething(SDL_Window* window, SDL_Renderer* renderer);
   
    
};





#endif 
