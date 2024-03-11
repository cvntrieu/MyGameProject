

#include "BaseObject.h"
#include "MainObject.h"
#include "ThreatObject.h"
#include "TextObject.h"

#define ThreatWidth  200
#define ThreatHeight 131

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 700;

using namespace std;


void waitUntilKeyPressed()
{
	SDL_Event e;
	while (true) {
		if (SDL_PollEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT)) return;
		SDL_Delay(1);
	}
}


int main(int argc, char* argv[])
{

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
		return 1;
	}

	TTF_Font* fontOfText = NULL;
	initText(fontOfText);
	SDL_Window* window = initWin();
	SDL_Renderer* renderer = initRen(window);
	SDL_Texture* intro = loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\Menu.png", renderer);
	SDL_Texture* playButton = loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\StartButton.png", renderer);
	SDL_Rect playButtonRect = { 300, 400, 200, 100 };

	SDL_Texture* background = loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\vecteezy_cartoon-colorful-panorama-of-spring-summer-beautiful-nature_7633071-1.jpg", renderer);
	SDL_RenderCopy(renderer, background, NULL, NULL);

	MainObject player;
	player.texture = loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\medium.png", renderer);
	render(renderer, player.texture, player.rect);

	ThreatObject threat;
	threat.texture = loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\Threat.png", renderer);



	bool quit = false;
	while (!quit)
	{
		drawIntro(renderer, intro, playButton, playButtonRect);
		SDL_RenderPresent(renderer);
		SDL_Event event;
		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				quit = true;
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN) {
				int mouseX, mouseY;
				SDL_GetMouseState(&mouseX, &mouseY);
				if (CheckRectFocus(mouseX, mouseY, playButtonRect) == true) {

					destroyTexture(intro);
					destroyTexture(playButton);
					bool gameQuit = false;
					while (!gameQuit) {
						SDL_Event e;
						while (SDL_PollEvent(&e)) {

							if (e.type == SDL_QUIT) {
								quit = true;
							}
							else if (e.type == SDL_KEYDOWN) {

								player.HandleInputAction(e);
								cout << player.rect.x << " " << player.rect.y << endl;
							}
						}

						threat.moveControl();
						SDL_RenderClear(renderer);
						SDL_RenderCopy(renderer, background, NULL, NULL);
						render(renderer, player.texture, player.rect);
						render(renderer, threat.texture, threat.rect);
						SDL_RenderPresent(renderer);
					}
				//	quit = true;
				}
			}
		}
	}

	destroyTexture(threat.texture);
	destroyTexture(player.texture);
	destroyTexture(background);
	Quit(window, renderer);
	return 0;
}


