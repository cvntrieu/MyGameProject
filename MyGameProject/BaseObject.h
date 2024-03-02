#pragma once
#ifndef Base_Object_H
#define Base_Object_H

#include "Graphics.h"

class BaseObject {

public:
	BaseObject();

	~BaseObject();

	// Set image's size
	void SetRect(const int& x, const int& y) {

		rect.x = x;
		rect.y = y;
	}

	// Get the "Rect" (size) of the image
	SDL_Rect GetRect() const { return rect; }
	SDL_Texture* getTexture() const { return texture; }

	bool loadImage(string path, SDL_Renderer* window);
	void render(SDL_Renderer* dest, const SDL_Rect* clip = NULL);

private:

	SDL_Texture* texture; // p_object: Save image
	SDL_Rect rect; // Size of image, include rect.x/y/w/h
};

#endif 
