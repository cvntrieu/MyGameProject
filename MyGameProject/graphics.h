#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Graphics {

private:
		SDL_Renderer* renderer;

public:
	Graphics(SDL_Renderer* renderer);
	SDL_Texture* loadTexture(string path);
	void renderTexture(SDL_Texture* texture, int x, int y);
};