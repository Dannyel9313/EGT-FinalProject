/*
 * Outro.cpp
 *
 *  Created on: 8.07.2017 ã.
 *      Author: ddada
 */

#include "Outro.h"

Outro::Outro()
{
	setWinningMoney(0);
}

Outro::~Outro() {
	// TODO Auto-generated destructor stub
}

void Outro::setWinningMoney(double count)
{
	winningMoney = count;
}

int Outro::getWinningMoney()
{
	return winningMoney;
}


void Outro::winingWindow(SDL_Renderer * renderer) {
	SDL_Rect Message_rect;
		Message_rect.x = 200;
		Message_rect.y = 200;
		Message_rect.w = 400;
		Message_rect.h = 400;

		render(renderer, &Message_rect);

}

void Outro::writingOnScreen(SDL_Renderer * renderer) {



/*	int count=0;
	if (winningMoney>0){
			count++;

	}

	TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);

	SDL_Color White = {255, 255, 255};
	//SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, count, White);
	//SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_Rect Message_rect;
	Message_rect.x = 0;
	Message_rect.y = 0;
	Message_rect.w = 100;
	Message_rect.h = 100;

	//SDL_RenderCopy(renderer, Message, NULL, &Message_rect); */
}
