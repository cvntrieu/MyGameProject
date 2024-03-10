

#include "BaseObject.h"
#include "TextObject.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "The Defender !";

BaseObject::BaseObject() {

    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;
    texture = nullptr;
}

BaseObject::~BaseObject() { delete[] texture; }


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


void initText(TTF_Font* fontOfText)
{

    if (TTF_Init() != 0) {
        cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
    }
    else {

        fontOfText = TTF_OpenFont("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\FontsFree-Net-COMICATE.ttf", 20);
        if (fontOfText == NULL) {
            cout << "Failed to load font: " << TTF_GetError() << endl;
        }
    }
}



void logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
        "%s: %s", msg, error);
    SDL_Quit();
}

void Quit(SDL_Window* window, SDL_Renderer* renderer)
{

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

int ShowMenu(SDL_Texture* des, TTF_Font* font)
{
    return 0;
}


bool CheckRectFocus(int x, int y, SDL_Rect rect) {

    if (x >= rect.x && x < rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h) {
        return true;
    }
    return false;
}


void ShowMenu(SDL_Window* window, SDL_Renderer* renderer, TTF_Font* font)
{

    SDL_Texture* menu = loadTexture("C:\\Users\\ADMIN\\source\\repos\\yGameProject\\Menu.jpg", renderer);
    if (menu == nullptr) {
        cout << "Cannot create Menu! " << endl;
    }
    else {

        SDL_Rect pos_arr;
        pos_arr.x = 200;
        pos_arr.y = 400;

        TextObject text_menu;
        text_menu.SetText("PLAY NOW !");
        text_menu.SetColor(TextObject::WHITE_TEXT); // Kieu enum pr goi nhu nay !
        text_menu.rect = { pos_arr.x, pos_arr.y, 700, 200 };


        bool MouseSelected = 0; // Kiem tra viec focus 
        bool mouse_quit = false;
        SDL_Event mouse;
        int mouseX = 0, mouseY = 0; // Toa do con chuot

        while (!mouse_quit)
        {
            while (SDL_PollEvent(&mouse)) {
                switch(mouse.type)
                { 
                case SDL_QUIT: {
                    mouse_quit = true;
                    break;
                }

                case SDL_MOUSEMOTION: {
                    // Bat su kien chuot di chuyen 
                    mouseX = mouse.motion.x;
                    mouseY = mouse.motion.y;

                    if (CheckRectFocus(mouseX, mouseY, text_menu.rect)) {
                        if (!MouseSelected) {
                            MouseSelected = 1;
                            text_menu.SetColor(TextObject::RED_TEXT);
                        }
                        else { // Neu chuot o ngoai vung
                            MouseSelected = 0; // reset
                            text_menu.SetColor(TextObject::WHITE_TEXT);
                        }
                    }
                    break;
                }

                case SDL_MOUSEBUTTONDOWN: {

                    mouseX = mouse.motion.x;
                    mouseY = mouse.motion.y;

                    if (CheckRectFocus(mouseX, mouseY, text_menu.rect)) {
                        // Start playing ...
                    }
                    break;
                }
                
                case SDL_KEYDOWN: {
                    if (mouse.key.keysym.sym == SDLK_ESCAPE) { // Nhan phim thoat X hoac esc
                        Quit(window, renderer);
                    }
                }

                }
            }
        }

    }
}


