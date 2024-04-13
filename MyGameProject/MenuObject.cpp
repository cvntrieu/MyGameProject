
#include "MenuObject.h"

void Menu::initMenu(SDL_Renderer* renderer) {

	status = MENU;
	texture = loadTexture("OfficialMenu.jpg", renderer);
	helpTexture = loadTexture("OfficialHelp.jpg", renderer);
	gameOverTexture = loadTexture("OfficialOver.jpg", renderer);
}

void Menu::CheckRectFocus()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	cout << "Menu: " << x << " " << y << endl;
	
	if ( 400 <= x && x <= 690 && 380 <= y && y <= 450) {
		status = PLAY;
	}
	else if ( 405 <= x && x <= 685 && 470 <= y && y <= 540 ) {
		status = HELP;
	}
	else if ( 405 <= x && x <= 690 && 570 <= y && y <= 640 ) {
		status = EXIT;
	}
	else {
		status = MENU;
	}
}

bool Menu::CheckExitHelp()
{   
	int x, y;
	SDL_GetMouseState(&x, &y);
	cout << "Help: " << x << " " << y << endl;
	if (580 <= x && x <= 860 && 500 <= y && y <= 570) {
		status = MENU;
		return true;
	}

return false;
}

void Menu::CheckGameOver() {

	int x, y;
	SDL_GetMouseState(&x, &y);
	cout << "Over: " << x << " " << y << endl;
	if (405 <= x && x <= 740 && 440 <= y && y <= 520) {
		status = PLAY;
	}
	else if (420 <= x && x <= 700 && 555 <= y && y <= 630) {
		status = EXIT;
	}
}

Menu::~Menu() {

	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(helpTexture);
	SDL_DestroyTexture(gameOverTexture);
}