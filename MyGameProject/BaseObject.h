
#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include "CommonFuctions.h"

using namespace std;

class BaseObject {

public:
    SDL_Rect rect;
    SDL_Texture* texture;

    BaseObject();
    ~BaseObject();

};


#endif
