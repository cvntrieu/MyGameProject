
#ifndef GAME_H
#define GAME_H

#include "BaseObject.h"
#include "MainObject.h"
#include "ThreatObject.h"
#include "Text.h"
#include "Music.h"
#include "MenuObject.h"
#include "Record.h"
#include "CommonFuctions.h"

using namespace std;

class Game {

private:

	SDL_Window* window;
	SDL_Renderer* renderer;
	Menu menu;
	SDL_Texture* background;
	SDL_Texture* heart;
	SDL_Rect heartRect;
	MainObject player;
	ThreatObject troop[Threat_number];
	ThreatObject gift;
	Mix_Music* backgroundMusic;
	Mix_Chunk* welcome;
	Mix_Chunk* end;

public:
	void initGame();
	void renderClip(MainObject& myBird);
	void playGame();
	~Game();
};

#endif


