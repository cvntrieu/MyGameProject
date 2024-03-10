
#include "MainObject.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

MainObject::MainObject() {

	rect.x = 0;
	rect.y = 0;
	rect.w = Width;
	rect.h = Height;
	texture = nullptr;
}


MainObject::~MainObject() { delete[] texture; }


void MainObject::HandleInputAction(SDL_Event& events) {

	if (events.type == SDL_KEYDOWN) {

		switch (events.key.keysym.sym) {

		case SDLK_UP:
		{
			rect.y -= Width;
			if (rect.y < 0 ) rect.y += 100;
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
