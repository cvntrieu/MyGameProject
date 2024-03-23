#ifndef MAIN_OBJECT_H
#define MAIN_OBJECT_H


#include "BaseObject.h"
#define Width  100 // 100
#define Height 69 // 69
const int Threat_number = 3;

class MainObject : public BaseObject
{
public:

	MainObject();
	~MainObject();

	void HandleInputAction(SDL_Event& events);
};

#endif