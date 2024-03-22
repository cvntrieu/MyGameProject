
#include "MainObject.h"

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 700;

MainObject::MainObject() {

	rect.x = 1;
	rect.y = 1;
	rect.w = Width;
	rect.h = Height;
	texture = nullptr;
}


MainObject::~MainObject() { 


	if (texture != nullptr) {

		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}


void MainObject::HandleInputAction(SDL_Event& events) {

	if (events.type == SDL_KEYDOWN) {

		switch (events.key.keysym.sym) {

		case SDLK_UP:
		{
			rect.y -= Width;
			if (rect.y < 90 ) rect.y = 90;
			break;
		}
		case SDLK_DOWN:
		{
			rect.y += Width;
			if ( rect.y + Height >  SCREEN_HEIGHT) rect.y -= 100;
			break;
		}
		case SDLK_RIGHT:
		{
			rect.x += Width;
			if ( rect.x + Width > SCREEN_WIDTH ) rect.x -= 100;
			break;
		}
		case SDLK_LEFT:
		{
			rect.x -= Width;
			if (rect.x < 0 ) rect.x += 100;
			break;
		}
		default:
			break;
		}
		
	}
}
