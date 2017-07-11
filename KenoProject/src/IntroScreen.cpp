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

void IntroScreen::loadIntroScreen(SDL_Renderer* renderer) {

	int offset = 130;

	m_introSong =
			Mix_LoadMUS(
					"Deya Dova - Footsteps In The Stars Temple Step Project  DJ Dakini Remix.mp3");

	setElementsFont();
	setElementsColor();

	m_startNewGameButton.LoadFromRenderedText("START NEW GAME", renderer,
			m_startNewGameButton.getButtonColor());

	m_resumeGameButton.LoadFromRenderedText("RESUME GAME", renderer,
			m_resumeGameButton.getButtonColor());

	m_infoButton.LoadFromRenderedText("INFO", renderer,
			m_infoButton.getButtonColor());

	for (int i = 640; i > offset; i -= 5) {

		m_background.loadTexture("IntroKenoImage2.png", renderer);
		SDL_RenderCopy(renderer, m_background.getKTexture(), NULL, NULL);

		m_startNewGameButton.setPosition(530, i, introButton_width,
				introButton_height);
		m_startNewGameButton.textRender(m_startNewGameButton.getKRect(),
				m_startNewGameButton.getKTexture(), renderer);

		SDL_RenderPresent(renderer);
	}
	offset += 80;
	for (int i = 640; i > offset; i -= 5) {

		m_background.loadTexture("IntroKenoImage2.png", renderer);
		SDL_RenderCopy(renderer, m_background.getKTexture(), NULL, NULL);

		m_startNewGameButton.setPosition(530, 130, introButton_width,
				introButton_height);
		m_startNewGameButton.textRender(m_startNewGameButton.getKRect(),
				m_startNewGameButton.getKTexture(), renderer);

		m_resumeGameButton.setPosition(530, i, introButton_width,
				introButton_height);
		m_resumeGameButton.textRender(m_resumeGameButton.getKRect(),
				m_resumeGameButton.getKTexture(), renderer);
		SDL_RenderPresent(renderer);

	}
	offset += 80;
	for (int i = 640; i > offset; i -= 5) {
		m_background.loadTexture("IntroKenoImage2.png", renderer);
		SDL_RenderCopy(renderer, m_background.getKTexture(), NULL, NULL);

		m_startNewGameButton.setPosition(530, 130, introButton_width,
				introButton_height);
		m_startNewGameButton.textRender(m_startNewGameButton.getKRect(),
				m_startNewGameButton.getKTexture(), renderer);

		m_resumeGameButton.setPosition(530, 220, introButton_width,
				introButton_height);
		m_resumeGameButton.textRender(m_resumeGameButton.getKRect(),
				m_resumeGameButton.getKTexture(), renderer);

		m_infoButton.setPosition(530, i, introButton_width, introButton_height);
		m_infoButton.textRender(m_infoButton.getKRect(),
				m_infoButton.getKTexture(), renderer);

		SDL_RenderPresent(renderer);

	}
	m_volume.LoadVolumeElements(renderer);
	m_insertCredit.loadCreditElements(renderer);

	SDL_RenderPresent(renderer);
}

Volume& IntroScreen::getVolume() {
	return m_volume;
}

void IntroScreen::setVolume(Volume& volume) {
	m_volume = volume;
}

InsertCredit& IntroScreen::getInsertCredit() {
	return m_insertCredit;
}

void IntroScreen::setPositionDimension() {
	m_startNewGameButton.setPosition(530, 130, introButton_width,
			introButton_height);
	m_resumeGameButton.setPosition(530, 220, introButton_width,
				introButton_height);
	m_infoButton.setPosition(530, 300, introButton_width, introButton_height);

}

void IntroScreen::setElementsColor() {
	if (m_startNewGameButton.isClicked(m_startNewGameButton.getKRect())) {
		m_startNewGameButton.setButtonColor(255, 0, 39);
	} else {
		m_startNewGameButton.setButtonColor(255, 255, 255);
	}
	if (m_resumeGameButton.isClicked(m_resumeGameButton.getKRect())) {
		m_resumeGameButton.setButtonColor(255, 0, 39);
	} else {
		m_resumeGameButton.setButtonColor(255, 255, 255);
	}
	if (m_infoButton.isClicked(m_infoButton.getKRect())) {
		m_infoButton.setButtonColor(255, 0, 39);
	} else {
		m_infoButton.setButtonColor(255, 255, 255);
	}
}

void IntroScreen::setElementsFont() {
	m_startNewGameButton.setFont(TTF_OpenFont("Pozo.ttf", 50));
	m_resumeGameButton.setFont(TTF_OpenFont("Pozo.ttf", 50));
	m_infoButton.setFont(TTF_OpenFont("Pozo.ttf", 50));
}

void IntroScreen::introScreenPresent(SDL_Renderer* renderer) {
	setElementsFont();
	setPositionDimension();
	setElementsColor();

	m_startNewGameButton.LoadFromRenderedText("START NEW GAME", renderer,
				m_startNewGameButton.getButtonColor());

		m_resumeGameButton.LoadFromRenderedText("RESUME GAME", renderer,
				m_resumeGameButton.getButtonColor());

		m_infoButton.LoadFromRenderedText("INFO", renderer,
				m_infoButton.getButtonColor());

	m_background.loadTexture("IntroKenoImage2.png", renderer);
	SDL_RenderCopy(renderer, m_background.getKTexture(), NULL, NULL);


	m_startNewGameButton.textRender(m_startNewGameButton.getKRect(),
			m_startNewGameButton.getKTexture(), renderer);


	m_resumeGameButton.textRender(m_resumeGameButton.getKRect(),
			m_resumeGameButton.getKTexture(), renderer);


	m_infoButton.textRender(m_infoButton.getKRect(), m_infoButton.getKTexture(),
			renderer);

	m_volume.LoadVolumeElements(renderer);
	m_insertCredit.loadCreditElements(renderer);

	SDL_RenderPresent(renderer);
}

void IntroScreen::setInsertCredit(InsertCredit& insertCredit) {
	m_insertCredit = insertCredit;
}

Mix_Chunk*& IntroScreen::getChunkClic() {
	return m_chunkClic;
}

Mix_Music*& IntroScreen::getIntroSong() {
	return m_introSong;
}
//void IntroScreen::handleEvent( SDL_Event& e,int x, int y)
//{
//
//
//
//	if( e.type == SDL_MOUSEMOTION ){
//		if(m_infoButton.isClicked(x,y)){
//
//		m_infoButton.changeColor();
//		}
//	}
//
//
//
//
//
//
////
////		switch( e.window.event )
////		{
////
////			case SDL_WINDOWEVENT_SIZE_CHANGED:
////			mWidth = e.window.data1;
////			mHeight = e.window.data2;
////			SDL_RenderPresent( gRenderer );
////			break;
////
////
////			case SDL_WINDOWEVENT_EXPOSED:
////			SDL_RenderPresent( gRenderer );
////			break;
////
////
////			case SDL_WINDOWEVENT_ENTER:
////			mMouseFocus = true;
////			updateCaption = true;
////			break;
////
////
////			case SDL_WINDOWEVENT_LEAVE:
////			mMouseFocus = false;
////			updateCaption = true;
////			break;
////
////			//Window has keyboard focus
////			case SDL_WINDOWEVENT_FOCUS_GAINED:
////			mKeyboardFocus = true;
////			updateCaption = true;
////			break;
////
////			//Window lost keyboard focus
////			case SDL_WINDOWEVENT_FOCUS_LOST:
////			mKeyboardFocus = false;
////			updateCaption = true;
////			break;
////
////			//Window minimized
////			case SDL_WINDOWEVENT_MINIMIZED:
////            mMinimized = true;
////            break;
////
////			//Window maxized
////			case SDL_WINDOWEVENT_MAXIMIZED:
////			mMinimized = false;
////            break;
////
////			//Window restored
////			case SDL_WINDOWEVENT_RESTORED:
////			mMinimized = false;
////            break;
//		}
