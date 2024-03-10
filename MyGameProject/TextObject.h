
#ifndef TEXT_OBJECT_H
#define TEXT_OBJECT_H

#include "BaseObject.h"
#include <string>

using namespace std;

class TextObject : public BaseObject
{
public:

	enum textColor
	{
		RED_TEXT = 0,
		BLUE_TEXT = 1,
		WHITE_TEXT = 2,
	};

	TextObject();
	~TextObject();

	void SetText(string text);
	void SetColor(int type);
	void createText(TTF_Font* font, SDL_Renderer* renderer);

private:

	string content;
	SDL_Color textColor;
};


#endif
