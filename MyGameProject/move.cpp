
#include "defs.h"
#include "Graphics.h"

void updatePos(SDL_Texture* texture, SDL_Renderer* renderer) {

    SDL_Rect dest;
    dest.x =+ 2;
    dest.y =+ 2;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(renderer, texture, NULL, &dest);
}
