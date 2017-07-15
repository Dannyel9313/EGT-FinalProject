#include "Win.h"

Win::Win()
{
 this->m_winCredits = 583;
}

Win::~Win()
{

}

BaseObject& Win::getWinGameCircle() {
	return m_winGameCircle;
}

BaseObject& Win::getWinGameRect() {
	return m_winGameRect;
}

Font& Win::getWinInGame() {
	return m_winInGame;
}

Font& Win::getWinTextRect() {
	return m_winTextRect;
}


void Win::renderWinInGame(SDL_Renderer* renderer) {


	setFont();
	setElementsPositionDimension();
	loadElements(renderer);
	setColor();

	m_winGameRect.render(renderer, m_winGameRect.getKRect());
	m_winGameCircle.render(renderer, m_winGameCircle.getKRect());
	m_winTextRect.textRender(m_winTextRect.getKRect(),
			m_winTextRect.getKTexture(), renderer);
	m_winInGame.textRender(m_winInGame.getKRect(),
			m_winInGame.getKTexture(), renderer);

}


void Win::setColor() {
	m_winTextRect.setButtonColor(0, 0, 0);
	m_winInGame.setButtonColor(0, 0, 0);

}

void Win::setElementsPositionDimension() {

	m_winGameCircle.setPosition(604, 502, creditsInGameWinCircle_width,
			creditsInGameWInCircle_height);
	m_winGameRect.setPosition(421, 513, creditsInGameWinRect_width,
			creditsInGameWinRect_height);
	m_winTextRect.setPosition(454, 519, creditsInGameWinTextInRect_width,
			creditsInGameWinTextInRect_height);

	m_winInGame.setPosition(619, 515, creditsInGameWinTextInCircle_width,
			creditsInGameWinTextInCircle_height);
}

void Win::loadElements(SDL_Renderer* renderer) {
	setColor();

	m_winGameRect.loadTextureFromFile(
			"Resources/Images/minMaxNumberRect.png", renderer);
	m_winGameCircle.loadTextureFromFile("Resources/Images/buttonCircleRed.png",
			renderer);
	m_winInGame.LoadFromRenderedText(toString(m_winCredits), renderer,
			m_winInGame.getButtonColor());
	m_winTextRect.LoadFromRenderedText("YOU WIN", renderer,
			m_winTextRect.getButtonColor());
}

void Win::setFont() {

	m_winTextRect.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
	m_winInGame.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
}

const char * Win::toString(int in_val) {
	std::string str = boost::lexical_cast<std::string>(in_val);
	return str.c_str();
}
//void Win::writeOnScreen(SDL_Renderer* renderer)
//{
//	loadTextureFromFile("Resources/Images/blueScreen.gif", renderer);
//	render(renderer, NULL);
//
//	firstText.setButtonColor(255, 0, 0);
//	secondText.setButtonColor(255, 0, 0);
//	thirdText.setButtonColor(255, 0, 0);
//	fourthText.setButtonColor(255, 0, 0);
//	fifthText.setButtonColor(255, 0, 0);
//
//	firstText.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 50));
//	firstText.LoadFromRenderedText("YOU HAVE WON!", renderer,
//				firstText.getButtonColor());
//	secondText.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 50));
//	secondText.LoadFromRenderedText("YOU HAVE WON!", renderer,
//				secondText.getButtonColor());
//	thirdText.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 50));
//	thirdText.LoadFromRenderedText("YOU HAVE WON!", renderer,
//			thirdText.getButtonColor());
//	fourthText.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 50));
//	fourthText.LoadFromRenderedText("YOU HAVE WON!", renderer,
//			fourthText.getButtonColor());
//	fifthText.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 50));
//	fifthText.LoadFromRenderedText("YOU HAVE WON!", renderer,
//			fifthText.getButtonColor());
//
//	for(int i = 0; i < 300; i += 5){
//			mBackground.loadTextureFromFile("Resources/Images/blueScreen.gif", renderer);
//			SDL_RenderCopy(renderer, mBackground.getKTexture(), NULL, NULL);
//
//			firstText.setPosition(i, i, introButton_width, introButton_height);
//			firstText.textRender(firstText.getKRect(), firstText.getKTexture(), renderer);
//
//		SDL_RenderPresent(renderer);
//	}
//	for(int i = 0; i < 300; i += 5){
//			mBackground.loadTextureFromFile("Resources/Images/blueScreen.gif", renderer);
//			SDL_RenderCopy(renderer, mBackground.getKTexture(), NULL, NULL);
//
//			firstText.setPosition(300, 300, introButton_width, introButton_height);
//			firstText.textRender(firstText.getKRect(), firstText.getKTexture(), renderer);
//
//			secondText.setPosition((SCREEN_WIDTH - 220) - i, 0 + i, introButton_width, introButton_height);
//			secondText.textRender(secondText.getKRect(), secondText.getKTexture(), renderer);
//
//		SDL_RenderPresent(renderer);
//	}
//	for(int i = 0; i < 300; i += 5){
//				mBackground.loadTextureFromFile("Resources/Images/blueScreen.gif", renderer);
//				SDL_RenderCopy(renderer, mBackground.getKTexture(), NULL, NULL);
//
//				firstText.setPosition(300, 300, introButton_width, introButton_height);
//				firstText.textRender(firstText.getKRect(), firstText.getKTexture(), renderer);
//
//				secondText.setPosition(300, 300, introButton_width, introButton_height);
//				secondText.textRender(secondText.getKRect(), secondText.getKTexture(), renderer);
//
//				thirdText.setPosition(SCREEN_WIDTH - 220 - i, SCREEN_HEIGHT - i - 45,
//						introButton_width, introButton_height);
//				thirdText.textRender(thirdText.getKRect(), thirdText.getKTexture(), renderer);
//
//			SDL_RenderPresent(renderer);
//		}
//	for(int i = 0; i < 300; i += 5){
//					mBackground.loadTextureFromFile("Resources/Images/blueScreen.gif", renderer);
//					SDL_RenderCopy(renderer, mBackground.getKTexture(), NULL, NULL);
//
//					firstText.setPosition(300, 300, introButton_width, introButton_height);
//					firstText.textRender(firstText.getKRect(), firstText.getKTexture(), renderer);
//
//					secondText.setPosition(300, 300, introButton_width, introButton_height);
//					secondText.textRender(secondText.getKRect(), secondText.getKTexture(), renderer);
//
//					thirdText.setPosition(300, 300, introButton_width, introButton_height);
//					thirdText.textRender(thirdText.getKRect(), thirdText.getKTexture(), renderer);
//
//					fourthText.setPosition(0 + i, SCREEN_HEIGHT - i - 40, introButton_width, introButton_height);
//					fourthText.textRender(fourthText.getKRect(), fourthText.getKTexture(), renderer);
//
//
//				SDL_RenderPresent(renderer);
//			}
//	for(int i = 0; i < 300; i += 5){
//						mBackground.loadTextureFromFile("Resurces/Images/blueScreen.gif", renderer);
//						SDL_RenderCopy(renderer, getKTexture(), NULL, NULL);
//
//						firstText.setPosition(300, 300, introButton_width, introButton_height);
//						firstText.textRender(firstText.getKRect(), firstText.getKTexture(), renderer);
//
//						secondText.setPosition(300, 300, introButton_width, introButton_height);
//						secondText.textRender(secondText.getKRect(), secondText.getKTexture(), renderer);
//
//						thirdText.setPosition(300, 300, introButton_width, introButton_height);
//						thirdText.textRender(thirdText.getKRect(), thirdText.getKTexture(), renderer);
//
//						fourthText.setPosition(300, 300, introButton_width, introButton_height);
//						fourthText.textRender(fourthText.getKRect(), fourthText.getKTexture(), renderer);
//
//						fifthText.setPosition(300, 300, introButton_width + i, introButton_height + i);
//						fifthText.textRender(fifthText.getKRect(), fifthText.getKTexture(), renderer);
//
//					SDL_RenderPresent(renderer);
//				}
//}

