#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Graphics {

private:
		SDL_Renderer* renderer;

public:
	Graphics(SDL_Renderer* renderer) : renderer(renderer) {};

	SDL_Texture* loadTexture(string path) {
// Neu de la string& path, duong dan o main se bi nhan dang la const char (loi)
			SDL_Surface* surface = IMG_Load(path.c_str());
			if (!surface) {
				cerr << "Unable to load image" << path << " SDL_image Error: "
					<< IMG_GetError() << endl;
				return nullptr;
			}
			
			SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
			if (!texture) {
				cerr << "Unable to create texture from" << path << " SDL Error: " << SDL_GetError() << endl;
			}

			SDL_FreeSurface(surface);
			return texture;
	}

	void renderTexture(SDL_Texture* texture, int x, int y) {
		SDL_Rect dest = { x, y, 0, 0 };
// Hcn o toa do (x,y) con w, h tam khoi tao = 0
		SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
		SDL_RenderCopy(renderer, texture, NULL, &dest);
	}
};