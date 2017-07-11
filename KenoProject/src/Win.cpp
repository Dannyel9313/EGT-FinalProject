/*
 * Win.cpp
 *
 *  Created on: Jul 11, 2017
 *      Author: Memmory Of Tomorrow
 */

#include "Win.h"

Win::Win()
{

}

Win::~Win()
{

}

void Win::writeOnScreen(SDL_Renderer* renderer)
{
	int height, width;
	SDL_Rect rect = {160, 270, 500, 100};
	loadTexture("blueScreen.gif", renderer);
	render(renderer, NULL);

	f.setFont(TTF_OpenFont("Pozo.ttf", 48));
	f.LoadFromRenderedText("YOU HAVE WON!", renderer,
			f.getButtonColor());
	f.textRender(&rect, f.getKTexture(), renderer);
	for(int i = 0; i < 640; i += 10){
		for(int j = 0; j < 820; i += 10){
			render(renderer, NULL);
			f.textRender(&rect, f.getKTexture(), renderer);
			SDL_RenderPresent(renderer);
		}
	}

}
