
#include "ThreatObject.h"
#include "MusicObject.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 700;

void ThreatObject::initThreat(SDL_Renderer* renderer){

	rect.x = SCREEN_WIDTH + v;
	rect.y = rand() % 600;
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


void ThreatObject::moveControl()
{
	// x_Threat -= v;
	rect.x -= v;
	// rect = { x_Threat, y_Threat, ThreatWidth / 2, ThreatHeight / 2 };
	/*if (x_Threat + SCREEN_WIDTH < 0) {

		x_Threat = SCREEN_WIDTH + rand() % SCREEN_WIDTH;
		y_Threat = rand() % 600;
		if (y_Threat > SCREEN_HEIGHT - 150) y_Threat = y_Threat = SCREEN_HEIGHT * 0.3;
	}*/
}






