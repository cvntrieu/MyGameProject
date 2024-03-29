
#ifndef MENU_H
#define MENU_H
#include "BaseObject.h"

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
