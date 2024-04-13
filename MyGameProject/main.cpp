
#include "GameObject.h"

int main(int argc, char* argv[]) {

	Game game;
	game.initGame();
	game.playGame();
	game.~Game();

	return 0;
}


