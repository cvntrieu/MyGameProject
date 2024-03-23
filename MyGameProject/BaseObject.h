
#ifndef Painter_H
#define Painter_H

#include <SDL.h>
#include <vector>
#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>

using namespace std;

class BaseObject {

public:
    SDL_Rect rect;
    SDL_Texture* texture;

    BaseObject();
    ~BaseObject();

};

void init();
SDL_Window* initWin();
SDL_Renderer* initRen(SDL_Window* window);
void logErrorAndExit(const char* msg, const char* error);
void Quit(SDL_Window* window, SDL_Renderer* renderer);
SDL_Texture* loadTexture(const char* filename, SDL_Renderer* renderer);
void render(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect rect);

void drawIntro(SDL_Renderer* renderer, SDL_Texture* intro, SDL_Texture* button, SDL_Rect rect);
bool CheckRectFocus(int x, int y, SDL_Rect rect); // Kiem tra toa do 1 diem voi 1 rect cho truoc
void destroyTexture(SDL_Texture* texture);
bool collision(SDL_Rect& player, SDL_Rect& threat);



#endif
