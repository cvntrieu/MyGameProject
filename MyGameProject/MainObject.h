#ifndef MAIN_OBJECT_H
#define MAIN_OBJECT_H


#include "BaseObject.h"
#include "TextObject.h"
#include "MusicObject.h"

#define Width  180
#define Height 110
//const int Threat_number = 3;
//const int SCREEN_WIDTH = 1200;
//const int SCREEN_HEIGHT = 700;
//const int STEP = 50;

class Point : public BaseObject {

public:

	int score, chance, recordPoint;
	SDL_Texture* chanceTexture;
	SDL_Texture* recordTexture;
	SDL_Rect chanceRect;
	SDL_Rect recordRect;

	Point();
	~Point();
	void updateTexture(SDL_Renderer* renderer);
};


class MainObject : public BaseObject
{
public:

	Point point;
	Mix_Chunk* collisionSound;

	void initMain(SDL_Renderer* renderer);
	~MainObject();

	void HandleInputAction(SDL_Event& events);
};

#endif