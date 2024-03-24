
#include "CommonFuctions.h"

void init() {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
    }
}

SDL_Window* initWin() {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logErrorAndExit("SDL_Init", SDL_GetError());

    SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);
    if (window == nullptr)
        logErrorAndExit("CreateWindow", SDL_GetError());
    return window;
}


SDL_Renderer* initRen(SDL_Window* window) {

    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
        logErrorAndExit("SDL_image error:", IMG_GetError());

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


    if (renderer == nullptr)
        logErrorAndExit("CreateRenderer", SDL_GetError());

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    return renderer;
}



void logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
        "%s: %s", msg, error);
    SDL_Quit();
}

void Quit(SDL_Window* window, SDL_Renderer* renderer)
{

    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
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


void render(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect rect) {

    SDL_RenderCopy(renderer, texture, NULL, &rect);
}



bool CheckRectFocus(int x, int y, SDL_Rect rect) {

    if (x >= rect.x && x < rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h) {
        return true;
    }
    return false;
}


void destroyTexture(SDL_Texture* texture)
{
    SDL_DestroyTexture(texture);
    texture = NULL;
}

bool collision(SDL_Rect& player, SDL_Rect& threat) // Note: Pass-by-reference
{
    int left1 = player.x * 1.15, right1 = player.x + player.w * 0.85;
    int top1 = player.y, bottom1 = player.y + player.h;

    int left2 = threat.x * 1.15, right2 = threat.x + threat.w * 0.85;
    int top2 = threat.y, bottom2 = threat.y + threat.h;


    if (left2 < left1 && left1 < right2 && top2 < top1 && top1 < bottom2) {
        return true;
    }
    if (left1 < left2 && left2 < right1 && top2 < top1 && top1 < bottom2) {
        return true;
    }
    if (left2 < left1 && left1 < right2 && top1 < top2 && top2 < bottom1) {
        return true;
    }
    if (left1 < left2 && left2 < right1 && top1 < top2 && top2 < bottom1) {
        return true;
    }

    return false;
}
