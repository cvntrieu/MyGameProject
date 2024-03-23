
#include "TextObject.h"

TextObject::TextObject() {

	rect.x = 500;
	rect.y = 500;
	rect.w = 700;
	rect.h = 200;
	// Default white Color:
	textColor.r = 255;
	textColor.g = 255;
	textColor.b = 255;
	content = "";
	texture = NULL;
}


TextObject::~TextObject() {

	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

void TextObject::SetText(string text) {content = text;}

void TextObject::SetColor(int type)
{
	switch (type) {
		 
	case RED_TEXT:
		 {

			SDL_Color color = { 255, 0, 0 };
			textColor = color;
		 }
	case BLUE_TEXT:
		 {

			SDL_Color color = { 0, 255, 255 };
			textColor = color;
		 }
	case WHITE_TEXT:	
		 {

			SDL_Color color = { 255, 255, 255 }; // white
			textColor = color;
		 }
	}
}

void TextObject::createText(TTF_Font* font, SDL_Renderer* renderer)
{

	SDL_Surface* surface = TTF_RenderText_Solid(font, content.c_str(), textColor);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_RenderPresent(renderer);
}
