
#include "BaseObject.h"

BaseObject::BaseObject() { 

	texture = NULL;
	// Components of rect (rectangle of image)
	rect.x = 0;
	rect.y = 0;
	rect.w = 0;
	rect.h = 0;
}

BaseObject::~BaseObject() {

	//...
}

bool BaseObject::loadImage(string path, SDL_Renderer* screen) {


}