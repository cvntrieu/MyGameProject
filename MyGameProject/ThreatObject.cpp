
#include "ThreatObject.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 700;

ThreatObject::ThreatObject(){

	rect.x = SCREEN_WIDTH;
	rect.y = rand() % 600;
	rect.w = 0;
	rect.h = 0;

	x_Threat = SCREEN_WIDTH;
	y_Threat = rand() % 600;
	v = 3;
	texture = nullptr;
}


ThreatObject::~ThreatObject() { 


	if (texture != nullptr) {

		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}


void ThreatObject::moveControl()
{
	x_Threat -= v;

	rect = { x_Threat, y_Threat, ThreatWidth / 2, ThreatHeight / 2 };
	if (x_Threat + SCREEN_WIDTH < 0) {

		x_Threat = SCREEN_WIDTH + rand() % SCREEN_WIDTH;
		y_Threat = rand() % 600;
		if (y_Threat > SCREEN_HEIGHT - 150) y_Threat = y_Threat = SCREEN_HEIGHT * 0.3;
	}
}






