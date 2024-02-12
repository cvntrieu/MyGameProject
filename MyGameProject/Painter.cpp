
#include <iostream>
#include <cstdlib>
#include "Painter.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>
// #include "main.cpp"
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int STEPS = 10;
const float MAX_LENGTH = 100;
const string WINDOW_TITLE = "An Implementation of Code.org Painter";

Painter::Painter(SDL_Window* window, SDL_Renderer* renderer_)
	: renderer(renderer_)
{
	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT / 2;
	angle = 0;

	int width, height;
	SDL_RenderGetLogicalSize(renderer, &width, &height);

	if (width == 0 && height == 0)
		SDL_GetWindowSize(window, &width, &height);

	setPosition(width / 2, height / 2);
	setAngle(0);
	setColor(WHITE_COLOR);
	clearWithBgColor(BLUE_COLOR);
}

void Painter::setPosition(float x, float y) {
	this->x = x;
	this->y = y;
}

void Painter::setAngle(float angle) {
	this->angle = angle - floor(angle / 360) * 360;
}

void Painter::setColor(SDL_Color color) {
	this->color = color;
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 0);
}

void Painter::clearWithBgColor(SDL_Color bgColor) {
	SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, 0);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 0);
}


