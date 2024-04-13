
#ifndef TEXT_OBJECT_H
#define TEXT_OBJECT_H

#include "BaseObject.h"

void initText();
SDL_Texture* renderText(string text, SDL_Renderer* renderer);

#endif
