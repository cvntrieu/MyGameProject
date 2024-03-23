
#include "TextObject.h"

void initText() {

    if (TTF_Init() != 0) {
       cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
    } 
}


SDL_Texture* renderText(string text, SDL_Renderer* renderer) {

    TTF_Font* font = TTF_OpenFont("ARLRDBD.TTF", 100);
    if (font == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
            SDL_LOG_PRIORITY_ERROR,
            "Load font %s", TTF_GetError());
    }

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), {255, 0, 0, 255});
    if (textSurface == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
            SDL_LOG_PRIORITY_ERROR,
            "Render text surface %s", TTF_GetError());
        return nullptr;
    }


    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (texture == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
            SDL_LOG_PRIORITY_ERROR,
            "Create texture from text %s", SDL_GetError());
    }
    SDL_FreeSurface(textSurface);
    return texture;
}
