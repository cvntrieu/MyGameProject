
#include "ThreatObject.h"
#include "MusicObject.h"
#include <ctime>
#include <cstdlib>
// const int SCREEN_WIDTH = 1200;

// srand(time(nullptr));

void ThreatObject::initThreat(SDL_Renderer* renderer){

	rect.x = xPosList[rand() % SIZE_X];   // SCREEN_WIDTH + v;
	rect.y = yPosList[rand() % SIZE_Y];   // rand() % 600;
	rect.w = ThreatWidth / 2;
	rect.h = ThreatHeight / 2;

	v = 20;
	texture = loadTexture("Threat.png", renderer);
	threatAppearance = loadSound("Wind.wav");
}


ThreatObject::~ThreatObject() {


	if (texture != nullptr) {

		SDL_DestroyTexture(texture);
		texture = nullptr;
	}

	Mix_FreeChunk(threatAppearance);
	threatAppearance = nullptr;
}


void ThreatObject::moveControl() { rect.x -= v; }






