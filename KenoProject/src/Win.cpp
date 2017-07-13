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
	Mix_Chunk* winningMusic = NULL;
	winningMusic = Mix_LoadWAV("Victory sound effect.wav");
	if(winningMusic == NULL){
		std::cerr << "Music file could not be loaded" << std::endl;
	}
	Mix_PlayChannel(-1, winningMusic, 0);
	loadTexture("blueScreen.gif", renderer);
	render(renderer, NULL);

	firstText.setFont(TTF_OpenFont("arial_narrow_7.ttf", 50));
	firstText.LoadFromRenderedText("YOU HAVE WON!", renderer,
				firstText.setButtonColor(255, 0, 0));
	secondText.setFont(TTF_OpenFont("arial_narrow_7.ttf", 50));
	secondText.LoadFromRenderedText("YOU HAVE WON!", renderer,
				secondText.setButtonColor(255, 0, 0));
	thirdText.setFont(TTF_OpenFont("arial_narrow_7.ttf", 50));
	thirdText.LoadFromRenderedText("YOU HAVE WON!", renderer,
			thirdText.setButtonColor(255, 0, 0));
	fourthText.setFont(TTF_OpenFont("arial_narrow_7.ttf", 50));
	fourthText.LoadFromRenderedText("YOU HAVE WON!", renderer,
			fourthText.setButtonColor(255, 0, 0));
	fifthText.setFont(TTF_OpenFont("arial_narrow_7.ttf", 50));
	fifthText.LoadFromRenderedText("YOU HAVE WON!", renderer,
			fifthText.setButtonColor(255, 0, 0));

	for(int i = 0; i < 300; i += 5){
			mBackground.loadTexture("blueScreen.gif", renderer);
			SDL_RenderCopy(renderer, mBackground.getKTexture(), NULL, NULL);

			firstText.setPosition(i, i, introButton_width, introButton_height);
			firstText.textRender(firstText.getKRect(), firstText.getKTexture(), renderer);

		SDL_RenderPresent(renderer);
	}
	for(int i = 0; i < 300; i += 5){
			mBackground.loadTexture("blueScreen.gif", renderer);
			SDL_RenderCopy(renderer, mBackground.getKTexture(), NULL, NULL);

			firstText.setPosition(300, 300, introButton_width, introButton_height);
			firstText.textRender(firstText.getKRect(), firstText.getKTexture(), renderer);

			secondText.setPosition((SCREEN_WIDTH - 220) - i, 0 + i, introButton_width, introButton_height);
			secondText.textRender(secondText.getKRect(), secondText.getKTexture(), renderer);

		SDL_RenderPresent(renderer);
	}
	for(int i = 0; i < 300; i += 5){
				mBackground.loadTexture("blueScreen.gif", renderer);
				SDL_RenderCopy(renderer, mBackground.getKTexture(), NULL, NULL);

				firstText.setPosition(300, 300, introButton_width, introButton_height);
				firstText.textRender(firstText.getKRect(), firstText.getKTexture(), renderer);

				secondText.setPosition(300, 300, introButton_width, introButton_height);
				secondText.textRender(secondText.getKRect(), secondText.getKTexture(), renderer);

				thirdText.setPosition(SCREEN_WIDTH - 220 - i, SCREEN_HEIGHT - i - 45,
						introButton_width, introButton_height);
				thirdText.textRender(thirdText.getKRect(), thirdText.getKTexture(), renderer);

			SDL_RenderPresent(renderer);
		}
	for(int i = 0; i < 300; i += 5){
					mBackground.loadTexture("blueScreen.gif", renderer);
					SDL_RenderCopy(renderer, mBackground.getKTexture(), NULL, NULL);

					firstText.setPosition(300, 300, introButton_width, introButton_height);
					firstText.textRender(firstText.getKRect(), firstText.getKTexture(), renderer);

					secondText.setPosition(300, 300, introButton_width, introButton_height);
					secondText.textRender(secondText.getKRect(), secondText.getKTexture(), renderer);

					thirdText.setPosition(300, 300, introButton_width, introButton_height);
					thirdText.textRender(thirdText.getKRect(), thirdText.getKTexture(), renderer);

					fourthText.setPosition(0 + i, SCREEN_HEIGHT - i - 40, introButton_width, introButton_height);
					fourthText.textRender(fourthText.getKRect(), fourthText.getKTexture(), renderer);


				SDL_RenderPresent(renderer);
			}
	for(int i = 0; i < 300; i += 5){
						mBackground.loadTexture("blueScreen.gif", renderer);
						SDL_RenderCopy(renderer, mBackground.getKTexture(), NULL, NULL);

						fifthText.setPosition(300 - i, 300 - i, introButton_width + i*2, introButton_height + i*2);
						fifthText.textRender(fifthText.getKRect(), fifthText.getKTexture(), renderer);

					SDL_RenderPresent(renderer);
				}

}

std::string Win::floatToString(float var){
	std::string dtostr = boost::lexical_cast<std::string> (var);
	return dtostr.c_str();
}
