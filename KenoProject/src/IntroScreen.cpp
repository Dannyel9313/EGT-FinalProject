/*
 * IntroScreen.cpp
 *
 *  Created on: 08.07.2017
 *      Author: Danny
 */

#include "IntroScreen.h"

IntroScreen::IntroScreen() {
	// TODO Auto-generated constructor stub

}

IntroScreen::~IntroScreen() {
	// TODO Auto-generated destructor stub
}

BaseObject& IntroScreen::getBackground() {
	return m_background;
}

void IntroScreen::setBackground(const BaseObject& background) {
	m_background = background;
}

Font& IntroScreen::getInfoButton() {
	return m_infoButton;
}

void IntroScreen::setInfoButton(const Font& infoButton) {
	m_infoButton = infoButton;
}

Font& IntroScreen::getInsertCredit() {
	return m_insertCredit;
}

void IntroScreen::setInsertCredit(const Font& insertCredit) {
	m_insertCredit = insertCredit;
}

Font& IntroScreen::getResumeGameButton() {
	return m_resumeGameButton;
}

void IntroScreen::setResumeGameButton(const Font& resumeGameButton) {
	m_resumeGameButton = resumeGameButton;
}

Font& IntroScreen::getStartNewGameButton() {
	return m_startNewGameButton;
}

void IntroScreen::setStartNewGameButton(const Font& startNewGameButton) {
	m_startNewGameButton = startNewGameButton;
}

//Font& IntroScreen::getVolumeButton() {
//	return m_volumeButton;
//}

void IntroScreen::setButtonsPositionDimension(SDL_Renderer* renderer) {

	m_startNewGameButton.setPosition(530, 130);
	m_startNewGameButton.setDimensions(introButton_width, introButton_height);

}

void IntroScreen::loadButtonFont(SDL_Renderer* renderer) {
<<<<<<< HEAD
	m_background.loadTexture("IntroKenoImage2.png", renderer);
	SDL_RenderCopy(renderer, m_background.getKTexture(), NULL, NULL);
=======

	int offset = 130;
>>>>>>> 37632bf4ba0d482259692b9c2f55e758cd2eaba8

	m_startNewGameButton.setFont(TTF_OpenFont("Pozo.ttf", 50));
	m_resumeGameButton.setFont(TTF_OpenFont("Pozo.ttf", 50));
	m_insertCredit.setFont(TTF_OpenFont("Pozo.ttf", 50));
	m_infoButton.setFont(TTF_OpenFont("Pozo.ttf", 50));
//	m_volumeButton.setFont(TTF_OpenFont("Pozo.ttf", 50));

<<<<<<< HEAD
	m_startNewGameButton.LoadFromRenderedText("START GAME", renderer,
			m_startNewGameButton.setButtonColor(255, 255, 255));
	m_startNewGameButton.textRender(530, 130,
			m_startNewGameButton.getKTexture(), renderer);
	m_resumeGameButton.LoadFromRenderedText("RESUME GAME", renderer,
			m_resumeGameButton.setButtonColor(255, 255, 255));
	m_resumeGameButton.textRender(530, 220, m_resumeGameButton.getKTexture(),
			renderer);
=======
	m_startNewGameButton.LoadFromRenderedText("START NEW GAME", renderer,
			m_startNewGameButton.setButtonColor(255, 255, 255));

	m_resumeGameButton.LoadFromRenderedText("RESUME GAME", renderer,
			m_resumeGameButton.setButtonColor(255, 255, 255));

	m_infoButton.LoadFromRenderedText("INFO", renderer,
			m_infoButton.setButtonColor(255, 255, 255));

	for (int i = 640; i > offset; i -= 5) {

		m_background.loadTexture("IntroKenoImage2.png", renderer);
		SDL_RenderCopy(renderer, m_background.getKTexture(), NULL, NULL);

		m_startNewGameButton.textRender(530, i,
				m_startNewGameButton.getKTexture(), renderer);

		SDL_RenderPresent(renderer);
	}
	offset += 80;
	for (int i = 640; i > offset; i -= 5) {

		m_background.loadTexture("IntroKenoImage2.png", renderer);
		SDL_RenderCopy(renderer, m_background.getKTexture(), NULL, NULL);

		m_startNewGameButton.textRender(530, 130,
				m_startNewGameButton.getKTexture(), renderer);

		m_resumeGameButton.textRender(530, i, m_resumeGameButton.getKTexture(),
				renderer);
		SDL_RenderPresent(renderer);

	}
	offset += 80;
	for (int i = 640; i > offset; i -= 5) {
		m_background.loadTexture("IntroKenoImage2.png", renderer);
		SDL_RenderCopy(renderer, m_background.getKTexture(), NULL, NULL);

		m_startNewGameButton.textRender(530, 130,
				m_startNewGameButton.getKTexture(), renderer);

		m_resumeGameButton.textRender(530, 220,
				m_resumeGameButton.getKTexture(), renderer);

		m_infoButton.textRender(530, i, m_infoButton.getKTexture(),
				renderer);

		SDL_RenderPresent(renderer);

	}
>>>>>>> 37632bf4ba0d482259692b9c2f55e758cd2eaba8

	m_volumeButtonPlus.loadTexture("volumeButton.png", renderer);
	m_volumeButtonPlus.buttonRender(69, 76, 170, 490,
			m_volumeButtonPlus.getKTexture(), renderer);
	m_volumeButtonMinus.loadTexture("volumeButton.png", renderer);
	m_volumeButtonMinus.buttonRender(366, 78, 11, 490,
			m_volumeButtonMinus.getKTexture(), renderer);

}

//void IntroScreen::setVolumeButton(const Font& volumeButton) {
//	m_volumeButton = volumeButton;
//}

BaseObject& IntroScreen::getVolumeButtonMinus() {
	return m_volumeButtonMinus;
}

BaseObject& IntroScreen::getVolumeButtonPlus() {
	return m_volumeButtonPlus;
}
