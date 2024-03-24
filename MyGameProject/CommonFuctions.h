
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <SDL.h>
#include <vector>
#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>

#define ThreatWidth  170 
#define ThreatHeight 100

static const int SCREEN_WIDTH = 1200;
static const int SCREEN_HEIGHT = 700;
static const const int STEP = 50;
static const char* WINDOW_TITLE = "The Defender !";

using namespace std;

void init();
SDL_Window* initWin();
SDL_Renderer* initRen(SDL_Window* window);
void logErrorAndExit(const char* msg, const char* error);
void Quit(SDL_Window* window, SDL_Renderer* renderer);
SDL_Texture* loadTexture(const char* filename, SDL_Renderer* renderer);
void render(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect rect);

void destroyTexture(SDL_Texture* texture);
bool collision(SDL_Rect& player, SDL_Rect& threat);

#endif 
