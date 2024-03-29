
#include "MainObject.h"
#include "Record.h"


Point::Point() {

	score = 0;
	chance = 3;
	recordPoint = loadRecord();

	rect.x = 500;
	rect.y = 3;
	rect.w = 200;
	rect.h = 50;
	texture = nullptr;
	chanceTexture = nullptr;
	recordTexture = nullptr;
	chanceRect = { 100, 3, 50, 50 };
	recordRect = { SCREEN_WIDTH * 3 / 4, 3, 200, 50 };
}

Point::~Point() {

	if (texture != nullptr) {

		SDL_DestroyTexture(texture);
		texture = nullptr;
	}

	if (chanceTexture != nullptr) {

		SDL_DestroyTexture(chanceTexture);
		chanceTexture = nullptr;
	}
}


void Point::updateTexture(SDL_Renderer* renderer) {

	texture = renderText("Score: " + to_string(score), renderer);
	chanceTexture = renderText(" " + to_string(chance), renderer);
	if (score > recordPoint) {
		recordTexture = renderText("Top 1 : " + to_string(score), renderer);
	}
	else {
		recordTexture = renderText("Top 1 : " + to_string(recordPoint), renderer);
	}
}

void MainObject::reset(SDL_Renderer* renderer) {

	initMain(renderer); // Reset lai vi tri player
	point.score = 0; // Reset score cho lan choi tiep theo
	point.chance = 3; // Reset Chance
}

void MainObject::initMain(SDL_Renderer* renderer) {

	rect.x = 1;
	rect.y = 1;
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

bool MainObject::collision(SDL_Rect& threat) // Note: Pass-by-reference
{
	int left1 = rect.x * 1.15, right1 = rect.x + rect.w * 0.85;
	int top1 = rect.y, bottom1 = rect.y + rect.h;

	int left2 = threat.x * 1.15, right2 = threat.x + threat.w * 0.85;
	int top2 = threat.y, bottom2 = threat.y + threat.h;


	if (left2 < left1 && left1 < right2 && top2 < top1 && top1 < bottom2) {
		return true;
	}
	if (left1 < left2 && left2 < right1 && top2 < top1 && top1 < bottom2) {
		return true;
	}
	if (left2 < left1 && left1 < right2 && top1 < top2 && top2 < bottom1) {
		return true;
	}
	if (left1 < left2 && left2 < right1 && top1 < top2 && top2 < bottom1) {
		return true;
	}

	return false;
}


