

#include "BaseObject.h"
#include "TextObject.h"

using namespace std;


BaseObject::BaseObject() {

    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;
    texture = nullptr;
}

BaseObject::~BaseObject() { 

    if (texture != nullptr) {

        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}









