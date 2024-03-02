
#include "Graphics.h"

using namespace std;

void logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

SDL_Window* initWindows()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logErrorAndExit("SDL_Init", SDL_GetError());
    SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
        logErrorAndExit("SDL_image error:", IMG_GetError());

    return window;
}


SDL_Renderer* initRenderer(SDL_Window* window) {
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    return renderer;
}


void prepareScene(SDL_Texture* background, SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, NULL, NULL);
}

void presentScene(SDL_Renderer* renderer)
{
    SDL_RenderPresent(renderer);
}


SDL_Texture* loadTexture(const char* filename, SDL_Renderer* renderer)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
        "Loading %s", filename);
    SDL_Texture* texture = IMG_LoadTexture(renderer, filename);
    if (texture == NULL)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
            SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

    return texture;
}



void renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y) {

    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(renderer, texture, NULL, &dest);
}


//void updatePos(SDL_Texture* texture, SDL_Renderer* renderer) {
//
//    SDL_Rect dest;
//    dest.x += 2;
//    dest.y += 2;
//    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
//    SDL_RenderCopy(renderer, texture, NULL, &dest);
//
//    presentScene(renderer);
//}



