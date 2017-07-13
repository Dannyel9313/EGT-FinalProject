#include "Win.h"

Win::Win()
{

}

Win::~Win()
{

}

void Win::writeOnScreen(SDL_Renderer* renderer)
{
	loadTextureFromFile("Resources/Images/blueScreen.gif", renderer);
	render(renderer, NULL);

	firstText.setButtonColor(255, 0, 0);
	secondText.setButtonColor(255, 0, 0);
	thirdText.setButtonColor(255, 0, 0);
	fourthText.setButtonColor(255, 0, 0);
	fifthText.setButtonColor(255, 0, 0);

	firstText.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 50));
	firstText.LoadFromRenderedText("YOU HAVE WON!", renderer,
				firstText.getButtonColor());
	secondText.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 50));
	secondText.LoadFromRenderedText("YOU HAVE WON!", renderer,
				secondText.getButtonColor());
	thirdText.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 50));
	thirdText.LoadFromRenderedText("YOU HAVE WON!", renderer,
			thirdText.getButtonColor());
	fourthText.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 50));
	fourthText.LoadFromRenderedText("YOU HAVE WON!", renderer,
			fourthText.getButtonColor());
	fifthText.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 50));
	fifthText.LoadFromRenderedText("YOU HAVE WON!", renderer,
			fifthText.getButtonColor());

	for(int i = 0; i < 300; i += 5){
			mBackground.loadTextureFromFile("Resources/Images/blueScreen.gif", renderer);
			SDL_RenderCopy(renderer, mBackground.getKTexture(), NULL, NULL);

			firstText.setPosition(i, i, introButton_width, introButton_height);
			firstText.textRender(firstText.getKRect(), firstText.getKTexture(), renderer);

		SDL_RenderPresent(renderer);
	}
	for(int i = 0; i < 300; i += 5){
			mBackground.loadTextureFromFile("Resources/Images/blueScreen.gif", renderer);
			SDL_RenderCopy(renderer, mBackground.getKTexture(), NULL, NULL);

			firstText.setPosition(300, 300, introButton_width, introButton_height);
			firstText.textRender(firstText.getKRect(), firstText.getKTexture(), renderer);

			secondText.setPosition((SCREEN_WIDTH - 220) - i, 0 + i, introButton_width, introButton_height);
			secondText.textRender(secondText.getKRect(), secondText.getKTexture(), renderer);

		SDL_RenderPresent(renderer);
	}
	for(int i = 0; i < 300; i += 5){
				mBackground.loadTextureFromFile("Resources/Images/blueScreen.gif", renderer);
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
					mBackground.loadTextureFromFile("Resources/Images/blueScreen.gif", renderer);
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
						mBackground.loadTextureFromFile("Resurces/Images/blueScreen.gif", renderer);
						SDL_RenderCopy(renderer, getKTexture(), NULL, NULL);

						firstText.setPosition(300, 300, introButton_width, introButton_height);
						firstText.textRender(firstText.getKRect(), firstText.getKTexture(), renderer);

						secondText.setPosition(300, 300, introButton_width, introButton_height);
						secondText.textRender(secondText.getKRect(), secondText.getKTexture(), renderer);

						thirdText.setPosition(300, 300, introButton_width, introButton_height);
						thirdText.textRender(thirdText.getKRect(), thirdText.getKTexture(), renderer);

						fourthText.setPosition(300, 300, introButton_width, introButton_height);
						fourthText.textRender(fourthText.getKRect(), fourthText.getKTexture(), renderer);

						fifthText.setPosition(300, 300, introButton_width + i, introButton_height + i);
						fifthText.textRender(fifthText.getKRect(), fifthText.getKTexture(), renderer);

					SDL_RenderPresent(renderer);
				}
}

