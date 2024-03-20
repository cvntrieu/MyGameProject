
#include "ThreatObject.h"

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 700;

ThreatObject::ThreatObject(){

	rect.x = SCREEN_WIDTH;
	rect.y = rand() % 600;
	rect.w = 0;
	rect.h = 0;

	v = 1;
	texture = nullptr;
}


ThreatObject::~ThreatObject() { 


	if (texture != nullptr) {

		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}


void ThreatObject::createThreat(int numOfThreat)
{
	threatArray.clear();
	for (int i = 0; i < numOfThreat; i++) {

		x_Threat = SCREEN_WIDTH;
		y_Threat = rand() % 600;
		rect = { x_Threat, y_Threat, ThreatWidth / 2, ThreatHeight / 2 };
		threatArray.push_back(rect);
	}
}

void ThreatObject::moveControl()
{
	for (SDL_Rect& rectOfThreat : threatArray) {
		cout << "Threat = " << rectOfThreat.x << " " << rectOfThreat.y << endl;
		rectOfThreat.x -= v;

		if (rectOfThreat.x + SCREEN_WIDTH < 0) {

			rectOfThreat.x = SCREEN_WIDTH;
			rectOfThreat.y = rand() % 600;
			if (rectOfThreat.y > SCREEN_HEIGHT - 150) rectOfThreat.y = SCREEN_HEIGHT * 0.3;
		}
	}
}





