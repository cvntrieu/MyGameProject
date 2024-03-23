
#include "MainObject.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 700;
const int STEP = 50;


Point::Point() {

	score = 0;
	rect.x = 500;
	rect.y = 3;
	rect.w = 100;
	rect.h = 50;
	texture = nullptr;
}

Point::~Point() {

	if (texture != nullptr) {

		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}


void Point::updateTexture(SDL_Renderer* renderer) {

	texture = renderText("Score: " + to_string(score), renderer);
}

void MainObject::initMain(SDL_Renderer* renderer) {

	rect.x = 0;
	rect.y = 0;
	rect.w = Width;
	rect.h = Height;
	texture = loadTexture("medium.png", renderer);
	collisionSound = loadSound("Collision.wav");
}

MainObject::~MainObject() {


	if (texture != nullptr) {

		SDL_DestroyTexture(texture);
		texture = nullptr;
	}

	Mix_FreeChunk(collisionSound);
	collisionSound = nullptr;
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


