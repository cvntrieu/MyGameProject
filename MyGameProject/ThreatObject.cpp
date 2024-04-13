
#include "ThreatObject.h"
#include "Music.h"
#include <ctime>
#include <cstdlib>


void ThreatObject::initThreat(SDL_Renderer* renderer){

	rect.x = xPosList[rand() % SIZE_X];   
	rect.y = yPosList[rand() % SIZE_Y];   
	rect.w = ThreatWidth / 2;
	rect.h = ThreatHeight / 2;

	v = 40;
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






