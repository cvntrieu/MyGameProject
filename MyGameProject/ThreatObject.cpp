
#include "ThreatObject.h"
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

ThreatObject::ThreatObject(){

	rect.x = 0;
	rect.y = 0;
	rect.w = 0;
	rect.h = 0;

	x_Threat = SCREEN_WIDTH;
	y_Threat = SCREEN_HEIGHT * 0.3;
	v = 5;
	texture = nullptr;
}


ThreatObject::~ThreatObject() { delete[] texture; }


void ThreatObject::moveControl()
{
	x_Threat -= v;
	rect = { x_Threat, y_Threat, ThreatWidth / 2, ThreatHeight / 2 };
	if (x_Threat + SCREEN_WIDTH < 0) x_Threat = SCREEN_WIDTH;
}





