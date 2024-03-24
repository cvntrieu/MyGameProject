
#ifndef MENU_H
#define MENU_H
#include "BaseObject.h"

const int MENU = 0, HELP = 1, PLAY = 2, EXIT = 3;

class Menu : public BaseObject {

public:

	SDL_Texture* helpTexture;
	SDL_Texture* gameOverTexture;
	int status;

	void initMenu(SDL_Renderer* renderer);
	void CheckRectFocus(); 
	bool CheckExitHelp();
	void CheckGameOver();
	~Menu();
};

#endif
