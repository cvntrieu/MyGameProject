

#include "BaseObject.h"
#include "MainObject.h"
#include "ThreatObject.h"
#include "TextObject.h"
#include "MusicObject.h"

using namespace std;
const int SCREEN_WIDTH = 1200;
const int yPosList[] = {10, 140, 270, 400};
const int xPosList[] = {1200, 1503, 2103, 2403, 2700, 3000, 3201};
const int SIZE_X = sizeof(xPosList) / sizeof(int);
const int SIZE_Y = sizeof(yPosList) / sizeof(int);

void waitUntilKeyPressed()
{
	SDL_Event e;
	while (true) {
		if (SDL_PollEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT)) return;
		SDL_Delay(1);
	}
}


int main(int argc, char* argv[]) {

	init();
	initMusic();
	initText();
	
	SDL_Window* window = initWin();
	SDL_Renderer* renderer = initRen(window);
	SDL_Texture* intro = loadTexture("Menu.png", renderer);
	SDL_Texture* playButton = loadTexture("StartButton.png", renderer);
	SDL_Rect playButtonRect = { 300, 400, 200, 100 };

	SDL_Texture* background = loadTexture("vecteezy_cartoon-colorful-panorama-of-spring-summer-beautiful-nature_7633071-1.jpg", renderer);
	SDL_RenderCopy(renderer, background, NULL, NULL);

	MainObject player;
	player.initMain(renderer);
	render(renderer, player.texture, player.rect);

	vector <ThreatObject> troop (Threat_number);
	for (int i = 0; i < Threat_number; i++) {

		troop[i].initThreat(renderer);
		troop[i].rect.y = yPosList[rand() % SIZE_Y];
	}

	Mix_Music* backgroundMusic = loadMusic("BackgroundMusic.mp3");
	Mix_Chunk* welcome = loadSound("Open.wav");
	Mix_Chunk* end = loadSound("GameOver.wav");

	bool quit = false;
	playChunk(welcome);
	while (!quit)
	{
		Uint32 startTime = SDL_GetTicks() / 1000;
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

						Uint32 currentTime = SDL_GetTicks() / 1000;
						// cout << "Time: " << currentTime << endl;
						playMusic(backgroundMusic);
						SDL_Event e;
						while (SDL_PollEvent(&e)) {

							if (e.type == SDL_QUIT) {
								gameQuit = true;
							}
							else if (e.type == SDL_KEYDOWN) {

								player.HandleInputAction(e);
								// cout << "Player: " << player.rect.x << " " << player.rect.y << endl;
							}
						}

						SDL_RenderClear(renderer);
						SDL_RenderCopy(renderer, background, NULL, NULL);
						player.point.updateTexture(renderer);
						render(renderer, player.point.texture, player.point.rect);
						render(renderer, player.texture, player.rect);
						
						for (int i = 0; i < Threat_number; i++) {

							troop[i].moveControl(); 
							// cout << "i = " << i << endl;
							// ThreatObject* threat = troop + i; // troop khai bao o tren
							// cout << "Start render" << endl;

							if (troop[i].rect.x == SCREEN_WIDTH) 
								playChunk(troop[i].threatAppearance);
							if (troop[i].rect.x + ThreatWidth <= 0) {
								player.point.score++;
								cout << "Get Point: " << player.point.score << endl;
							}


							render(renderer, troop[i].texture, troop[i].rect);
							// cout << "Threat: " << troop[i].rect.x << " " << troop[i].rect.y << endl;

							if (troop[i].rect.x + ThreatWidth <= 0) {
								troop[i].rect.x = xPosList[rand() % SIZE_X];
								troop[i].rect.y = yPosList[rand() % SIZE_Y];
							}

							bool isCollision = collision(player.rect, troop[i].rect);
							if (isCollision || currentTime - startTime == 10) {
								
								// Show "Game Over!"
								playChunk(player.collisionSound);
							    cout << "Game Over! " << endl;
								SDL_Delay(2000);
								gameQuit = true;
								quit = true;
							}
						}

					SDL_RenderPresent(renderer);
					} // gameQuit == true
				
				player.~MainObject();
				for (int i = 0; i < Threat_number; i++) troop[i].~ThreatObject();

				if (welcome != nullptr) Mix_FreeChunk(welcome);
				if (end != nullptr) Mix_FreeChunk(end);
				if (backgroundMusic != nullptr) Mix_FreeMusic(backgroundMusic);

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


