#ifndef MAIN_OBJECT_H
#define MAIN_OBJECT_H


#include "BaseObject.h"
#include "Text.h"
#include "Music.h"

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
	vector<SDL_Rect> clips;
	int currentFrame = 0;

	void initMain(SDL_Renderer* renderer);
	void initClip(SDL_Texture* _texture, int frames, const int _clips[][4]);
	void tick();
	const SDL_Rect* getCurrentClip() const;
	~MainObject();
	void reset(SDL_Renderer* renderer);
	void HandleInputAction(SDL_Event& events);
	bool collision(SDL_Rect& threat);
};

#endif