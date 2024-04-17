
#include "GameObject.h"


void Game::initGame() {

	init();
	initMusic();
	initText();

	window = initWin();
	renderer = initRen(window);

	background = loadTexture("vecteezy_cartoon-colorful-panorama-of-spring-summer-beautiful-nature_7633071-1.jpg", renderer);
	heart = loadTexture("Saver.png", renderer);
	heartRect = { 5, 3, 100, 100 };
	backgroundMusic = loadMusic("BackgroundMusic.mp3");
	welcome = loadSound("Open.wav");
	end = loadSound("GameOver.wav");

	menu.initMenu(renderer);
	player.initMain(renderer);
	player.initClip(player.texture, FRAME_NUMBERS, BIRD);
	for (int i = 0; i < Threat_number; i++) { troop[i].initThreat(renderer); }
	gift.initThreat(renderer);
	gift.texture = loadTexture("Gift.png", renderer); // Sua lai texture so voi ham initThreat
}


void Game::renderGame() {

	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, background, NULL, NULL);
	SDL_RenderCopy(renderer, gift.texture, NULL, &gift.rect);
	for (int i = 0; i < Threat_number; i++) {
		SDL_RenderCopy(renderer, troop[i].texture, NULL, &troop[i].rect); // Hien ra troop[i] sau moi lan -v
	}
    SDL_RenderCopy(renderer, heart, NULL, &heartRect);

	player.renderBird(renderer);

	SDL_RenderPresent(renderer); // Bay gio moi Present
	SDL_Delay(20); // De CPU do lag, tranh bi giat man hinh
}


void Game::showMenu(SDL_Texture* menuTexture) {

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, menuTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}


void Game::playGame() {

	bool quit = false, again = true;
	playChunk(welcome);
	while (!quit)
	{
		showMenu(menu.texture);

		SDL_Event event;
		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				quit = true;
				cout << "Quit! " << endl;
				break;
			}

			else if (event.type == SDL_MOUSEBUTTONDOWN) {

				menu.CheckRectFocus(); // => Set status

				if (menu.status == EXIT) { // = 3 ===================================================================

					quit = true;
					cout << "Quit! " << endl;
					break;
				}

				else if (menu.status == HELP) { // // = 1 ===================================================================

					showMenu(menu.helpTexture);

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

						Uint32 preTime = SDL_GetTicks();

						cout << "START AGAIN! " << endl;
						bool gameQuit = false;
						while (!gameQuit) {

							playMusic(backgroundMusic);
							while (SDL_PollEvent(&event)) {

								if (event.type == SDL_QUIT) {
									gameQuit = true;
									Mix_HaltMusic();
									playChunk(end);
								}
								else if (event.type == SDL_KEYDOWN) {

									player.HandleInputAction(event);
									cout << "Player: " << player.rect.x << " " << player.rect.y << endl;
								}
							}

							player.point.updateTexture(renderer);

							// Gift
							gift.moveControl();
							cout << "Gift: " << gift.rect.x << " " << gift.rect.y << endl;

							if (gift.rect.x <= 0) {
								gift.rect.x = 10000;
							}
							bool getGift = player.collision(gift.rect);
							if (getGift) {
								gift.rect.x = 10000;
								player.point.score += 5;
							}

							// Threat
							for (int i = 0; i < Threat_number; i++) {

								troop[i].moveControl(); // Moi lan hien ra thi -v
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

								cout << "Threat: " << troop[i].rect.x << " " << troop[i].rect.y << endl;

								bool isCollision = player.collision(troop[i].rect);
								if (isCollision) {

									playChunk(player.collisionSound);
									if (player.point.chance == 0) {

										SDL_Delay(2000);
										// -> Reset lai vi tri cho threat chuan bi lan choi moi:
										for (int i = 0; i < Threat_number; i++) troop[i].initThreat(renderer);
										gift.initThreat(renderer);
										Mix_HaltMusic();
										playChunk(end);
										
										if (player.point.score > player.point.recordPoint) {
											saveRecord(player.point.score);
											player.point.recordPoint = player.point.score;
										}

										cout << "Game Over! " << endl;
										gameQuit = true;
									}
									else {
										player.point.chance--;
										for (int i = 0; i < Threat_number; i++) troop[i].initThreat(renderer);
										gift.initThreat(renderer);
										// Phai reset lai neu ko se xay ra tiep dien va cham lien tuc, score ve 0 rat nhanh
									}
								}
							}

							renderGame();
							Uint32 currentTime = SDL_GetTicks();
							if (currentTime - preTime >= 80) {
								player.tick();
								preTime = currentTime;
							}
						} // gameQuit == true

						player.reset(); // reset lai bird, da reset threat o tren

						bool overQuit = false;
						while (!overQuit) {

							showMenu(menu.gameOverTexture);

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
}


Game::~Game() {

	player.~MainObject();
	for (int i = 0; i < Threat_number; i++) troop[i].~ThreatObject();
	gift.~ThreatObject();

	if (welcome != nullptr) Mix_FreeChunk(welcome);
	if (end != nullptr) Mix_FreeChunk(end);
	if (backgroundMusic != nullptr) Mix_FreeMusic(backgroundMusic);

	destroyTexture(background);
	Quit(window, renderer);
}


