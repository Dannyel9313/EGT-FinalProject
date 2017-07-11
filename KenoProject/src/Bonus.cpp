/*
 * Bonus.cpp
 *
 *  Created on: 8.07.2017 ã.
 *      Author: ddada
 */

#include "Bonus.h"
#include "Outro.h"

Bonus::Bonus() {
	// TODO Auto-generated constructor stub

}

Bonus::~Bonus() {
	// TODO Auto-generated destructor stub
}

void Bonus::bonusWindow(SDL_Renderer*renderer, double bonusCredit) {
	TTF_Font *  font;
	font = TTF_OpenFont("Italic.ttf", 24);

		TTF_SetFontStyle(font, TTF_STYLE_ITALIC);

		SDL_Color color={0,0,0};
			SDL_Rect rect = {200,0 , 100, 100};

			std::string str = boost::lexical_cast<std::string> (bonusCredit);

		loadTextureFromFont(str.c_str(), renderer, font, color);
			render(renderer, &rect);



}

void Bonus::addBonusPercent(double credit) {
	double percent;
	double winningMoney;
int round=1;

for(round=1; round<=10;round++ ){

	percent=(winningMoney+credit)/100;

}
credit+=percent;


}
