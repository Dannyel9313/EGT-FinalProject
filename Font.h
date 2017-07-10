/*
 * Font.h
 *
 *  Created on: 08.07.2017
 *      Author: Danny
 */

#ifndef FONT_H_
#define FONT_H_

#include "BaseObject.h"

class Font: public BaseObject {
public:
	Font();
	virtual ~Font();

	//Load font
	void LoadFromRenderedText(std::string textureText,SDL_Renderer* render,
				SDL_Color textColor);

	void textRender(int x, int y, SDL_Texture* textureText,SDL_Renderer* renderer);

	//get font
	TTF_Font*& getFont();

	//get color
	SDL_Color getButtonColor();

	//set color
	SDL_Color setButtonColor(int red, int green, int blue);

	//set font
	void setFont(TTF_Font* font);

private:
	SDL_Color m_buttonColor;
	TTF_Font* m_font;
};

#endif /* FONT_H_ */
