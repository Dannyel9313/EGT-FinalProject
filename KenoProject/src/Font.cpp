/*
 * Font.cpp
 *
 *  Created on: 08.07.2017
 *      Author: Danny
 */

#include "Font.h"

Font::Font() {
	// TODO Auto-generated constructor stub

}

Font::~Font() {
	// TODO Auto-generated destructor stub
}
//Load font
void Font::LoadFromRenderedText(std::string textureText, SDL_Renderer* render,
		SDL_Color textColor) {

	BaseObject::free();

	SDL_Surface* textSurface = TTF_RenderText_Blended(m_font,
			textureText.c_str(), textColor);
	if (textSurface == NULL) {
		std::cerr << "Problem with create text surface !" << std::endl;
	} else {
		BaseObject::setKTexture(
				SDL_CreateTextureFromSurface(render, textSurface));
		if (BaseObject::getKTexture() == NULL) {
			std::cerr << "Problem with creating text texture !" << std::endl;
		}

		SDL_FreeSurface(textSurface);
	}
}

TTF_Font*& Font::getFont() {
	return m_font;
}

SDL_Color Font::getButtonColor() {
	return m_buttonColor;
}

void Font::setButtonColor(int red, int green, int blue) {
	m_buttonColor = {red,green,blue};
}

void Font::setFont(TTF_Font* font) {
	m_font = font;
}

void Font::textRender(SDL_Rect* rect, SDL_Texture* textureText,
		SDL_Renderer* renderer) {

	SDL_RenderCopy(renderer, textureText, NULL, rect);

}
