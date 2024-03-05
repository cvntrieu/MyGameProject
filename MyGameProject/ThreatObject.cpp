
#include "ThreatObject.h"
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

ThreatObject::ThreatObject(){

	// Vi tri ban dau ma Threat xuat hien
	rect.x = SCREEN_WIDTH - 201;
	rect.y = SCREEN_HEIGHT / 2;
	rect.w = ThreatWidth;
	rect.h = ThreatHeight;
	texture = nullptr;

	x_val = 0;
	y_val = 0;
}


ThreatObject::~ThreatObject() {}



void ThreatObject::setX(double& val) { x_val = val; }
void ThreatObject::setY(double& val) { y_val = val; }
double ThreatObject::getX() const    { return x_val; }
double ThreatObject::getY() const    { return y_val; }


void ThreatObject::moveControl(const double xBorder, const double yBorder)
{

	rect.x -= x_val;
	if (rect.x < 0) rect.x = SCREEN_WIDTH;
}


void ThreatObject::HandleInputAction(SDL_Event& e)
{
	

}


