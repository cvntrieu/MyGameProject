

#include "BaseObject.h"
#include "MainObject.h"
#include "ThreatObject.h"
#include "TextObject.h"

using namespace std;
const int SCREEN_WIDTH = 900;

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

	ThreatObject* troop = new ThreatObject[Threat_number];
	for (int i = 0; i < Threat_number; i++) {

		ThreatObject* threat = troop + i;
		threat->texture = loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\Threat.png", renderer);
	}

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

					bool gameQuit = false;
					while (!gameQuit) {
						SDL_Event e;
						while (SDL_PollEvent(&e)) {

							if (e.type == SDL_QUIT) {
								gameQuit = true;
							}
							else if (e.type == SDL_KEYDOWN) {

								player.HandleInputAction(e);
								cout << "Player: " << player.rect.x << " " << player.rect.y << endl;
							}
						}

						SDL_RenderClear(renderer);
						SDL_RenderCopy(renderer, background, NULL, NULL);
						render(renderer, player.texture, player.rect);

						for (int i = 0; i < Threat_number; i++) {

							cout << "i = " << i << endl;
							ThreatObject* threat = troop + i;
							cout << "Start render" << endl;
							threat->moveControl();
							render(renderer, threat->texture, threat->rect);
							cout << "Threat: " << threat->rect.x << " " << threat->rect.y << endl;
						}
						SDL_RenderPresent(renderer);
					}

				destroyTexture(intro);
				destroyTexture(playButton);
				destroyTexture(background);
				Quit(window, renderer);
				}
			}
		}
	}

	return 0;
}


