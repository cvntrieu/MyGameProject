
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <SDL.h>
#include <vector>
#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <ctime>
#include <cstdlib>

#define ThreatWidth  170 
#define ThreatHeight 100

 const int SCREEN_WIDTH = 1200;
 const int SCREEN_HEIGHT = 700;
 const int STEP = 50;
 const int MENU = 0, HELP = 1, PLAY = 2, EXIT = 3;
 const int Threat_number = 3;
 // const char* WINDOW_TITLE = "The Defender !"; 
 const int yPosList[] = { 10, 140, 270, 400 };
 const int xPosList[] = { 1200, 1503, 2103, 2403, 2700, 3000, 3201, 5001 };
 const int SIZE_X = sizeof(xPosList) / sizeof(int);
 const int SIZE_Y = sizeof(yPosList) / sizeof(int);

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
