
#include "BaseObject.h"
#include "MainObject.h"
#include "ThreatObject.h"
#include "TextObject.h"
#include "MusicObject.h"
#include "MenuObject.h"
#include "Record.h"
#include "CommonFuctions.h"

using namespace std;

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

	SDL_Rect playButtonRect1 = { 390, 413, 280, 80 };
	Menu menu;
	menu.initMenu(renderer);

	SDL_Texture* background = loadTexture("vecteezy_cartoon-colorful-panorama-of-spring-summer-beautiful-nature_7633071-1.jpg", renderer);
	SDL_Texture* heart = loadTexture("Saver.png", renderer);
	SDL_Rect heartRect = { 5, 3, 100, 100 };

	SDL_RenderCopy(renderer, background, NULL, NULL);

	MainObject player;
	player.initMain(renderer);
	render(renderer, player.texture, player.rect);

	vector <ThreatObject> troop (Threat_number);
	for (int i = 0; i < Threat_number; i++) { troop[i].initThreat(renderer); }

	ThreatObject gift;
	gift.initThreat(renderer);
	gift.texture = loadTexture("Gift.png", renderer);

	Mix_Music* backgroundMusic = loadMusic("BackgroundMusic.mp3");
	Mix_Chunk* welcome = loadSound("Open.wav");
	Mix_Chunk* end = loadSound("GameOver.wav");

	bool quit = false, again = true;
	playChunk(welcome);
	while (!quit)
	{
		// Uint32 startTime = SDL_GetTicks() / 1000;
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, menu.texture, NULL, NULL);
		SDL_RenderPresent(renderer); // Show Menu

		SDL_Event event;
		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) { 
				quit = true;
				cout << "Quit! " << endl;
				break;
			}

			else if (event.type == SDL_MOUSEBUTTONDOWN) {

			    menu.CheckRectFocus(); // => status

					if (menu.status == EXIT) { // = 3 ===================================================================

						quit = true;
						cout << "Quit! " << endl;
						break;
					}

					else if (menu.status == HELP) { // // = 1 ===================================================================

						SDL_RenderClear(renderer);
						SDL_RenderCopy(renderer, menu.helpTexture, NULL, NULL);
						SDL_RenderPresent(renderer);

						bool exitHelp = false;
						while (!exitHelp) {
							while (SDL_PollEvent(&event)) {

								if (event.type == SDL_QUIT) {
									exitHelp = true;
									quit = true;
									cout << "Quit! " << endl;
									break;
								}
								else if (event.type == SDL_MOUSEBUTTONDOWN) {

									if (menu.CheckExitHelp()) { // reset status = MENU
										exitHelp = true;
										break;
									}
								}
								// If not, wait for user to read Instruction and event Exit
							}
						}
					}

					else if (menu.status == PLAY) { // // = 2 ===================================================================

						while (again) {

							cout << "START AGAIN! " << endl;
							bool gameQuit = false;
							while (!gameQuit) {

								// Uint32 currentTime = SDL_GetTicks() / 1000;
								// cout << "Time: " << currentTime << endl;
								playMusic(backgroundMusic);
								while (SDL_PollEvent(&event)) {

									if (event.type == SDL_QUIT) {
										gameQuit = true;
										quit = true;
									}
									else if (event.type == SDL_KEYDOWN) {

										player.HandleInputAction(event);
										cout << "Player: " << player.rect.x << " " << player.rect.y << endl;
									}
								}

								// Player 
								SDL_RenderClear(renderer);
								SDL_RenderCopy(renderer, background, NULL, NULL);
								player.point.updateTexture(renderer); 

								render(renderer, player.point.texture, player.point.rect);
								render(renderer, player.point.chanceTexture, player.point.chanceRect);
								render(renderer, player.point.recordTexture, player.point.recordRect);
								render(renderer, player.texture, player.rect);
								render(renderer, heart, heartRect);

								// Gift
								gift.moveControl();
								cout << "Gift: " << gift.rect.x << " " << gift.rect.y << endl;
								render(renderer, gift.texture, gift.rect);
								if (gift.rect.x <= 0) {
									gift.rect.x = 10000;
								}
								bool getGift = collision(player.rect, gift.rect);
								if (getGift) {
									gift.rect.x = 10000;
									player.point.score += 5;
								}

								// Threat
								for (int i = 0; i < Threat_number; i++) {

									troop[i].moveControl();
									cout << "i = " << i << endl;
									cout << "Start render" << endl;

									if (troop[i].rect.x == SCREEN_WIDTH)
										playChunk(troop[i].threatAppearance);

									if (troop[i].rect.x + ThreatWidth <= 0) {
										player.point.score++;
										troop[i].rect.x = xPosList[rand() % SIZE_X];
										troop[i].rect.y = yPosList[rand() % SIZE_Y];
										cout << "Get Point: " << player.point.score << endl;
									}

									render(renderer, troop[i].texture, troop[i].rect);
									cout << "Threat: " << troop[i].rect.x << " " << troop[i].rect.y << endl;

									bool isCollision = collision(player.rect, troop[i].rect);
									if (isCollision) {

										playChunk(player.collisionSound);
										if (player.point.chance == 0) {
											
											SDL_Delay(2000);
											for (int i = 0; i < Threat_number; i++) troop[i].initThreat(renderer);
											Mix_HaltMusic();
											playChunk(end);
											// Reset lai vi tri cho threat chuan bi lan choi moi
											if (player.point.score > player.point.recordPoint) {
												saveRecord(player.point.score);
												player.point.recordPoint = player.point.score;
											}
											cout << "Game Over! " << endl;
											gameQuit = true;
											// menu.status = EXIT; 
										}
										else { 
											player.point.chance--;
											for (int i = 0; i < Threat_number; i++) troop[i].initThreat(renderer);
											// Phai reset lai neu ko se xay ra tiep dien va cham lien tuc, mang ve 0 rat nhanh
										}
									}
								}
								SDL_RenderPresent(renderer);
								SDL_Delay(20); // De CPU do lag, tranh bi giat man hinh
							} // gameQuit == true

							player.reset(renderer);

							bool overQuit = false;
							while (!overQuit) {

								SDL_RenderClear(renderer);
								SDL_RenderCopy(renderer, menu.gameOverTexture, NULL, NULL);
								SDL_RenderPresent(renderer);

								while (SDL_PollEvent(&event)) {

									if (event.type == SDL_QUIT) {
										overQuit = true;
										again = false;
										quit = true;
										break;
									}
									else if (event.type == SDL_MOUSEBUTTONDOWN) {

										menu.CheckGameOver();
										if (menu.status == EXIT) {
											// cout << "Exit for Over! " << endl;
											overQuit = true;
											again = false;
											quit = true;
											break;
										}
										else if (menu.status == PLAY) {
											// cout << "Play after Over! " << endl;
											overQuit = true;
											cout << "READY! " << endl;
											break;
										}
									} // mouse
								} // event
							} // overQuit = true

						} // again?
					} // status == play (*) ============================================================================
			} // mouse
		} // pollEvent
	} // quit

	player.~MainObject();
	for (int i = 0; i < Threat_number; i++) troop[i].~ThreatObject();
	gift.~ThreatObject();

	if (welcome != nullptr) Mix_FreeChunk(welcome);
	if (end != nullptr) Mix_FreeChunk(end);
	if (backgroundMusic != nullptr) Mix_FreeMusic(backgroundMusic);

	destroyTexture(background);
	Quit(window, renderer);

	return 0;
}


