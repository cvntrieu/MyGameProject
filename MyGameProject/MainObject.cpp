
#include "MainObject.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 700;
const int STEP = 50;

MainObject::MainObject() {

	rect.x = 0;
	rect.y = 0;
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
			rect.y -= STEP;
			if (rect.y < 90 ) rect.y += STEP;
			break;
		}
		case SDLK_DOWN:
		{
			rect.y += STEP;
			if ( rect.y + Height >=  SCREEN_HEIGHT) rect.y -= STEP;
			break;
		}
		case SDLK_RIGHT:
		{
			rect.x += STEP;
			if ( rect.x + Width >= SCREEN_WIDTH ) rect.x -= STEP;
			break;
		}
		case SDLK_LEFT:
		{
			rect.x -= STEP;
			if (rect.x < 0 ) rect.x += STEP;
			break;
		}
		default:
			break;
		}
		
	}
}
