/*
 * CreditInGame.cpp
 *
 *  Created on: 14.07.2017
 *      Author: Danny
 */

#include "CreditInGame.h"

CreditInGame::CreditInGame() {
	this->m_gameCredit = 583;

}

CreditInGame::~CreditInGame() {
	// TODO Auto-generated destructor stub
}

BaseObject& CreditInGame::getCreditsCircle() {
	return m_creditsCircle;
}

Font& CreditInGame::getCreditsInGame() {
	return m_creditsInGame;
}

BaseObject& CreditInGame::getCreditsTextRect() {
	return m_creditsTextRect;
}

int CreditInGame::getGameCredit() const {
	return m_gameCredit;
}

void CreditInGame::setGameCredit(int gameCredit) {
	m_gameCredit = gameCredit;
}

void CreditInGame::renderCreditsInGame(SDL_Renderer* renderer) {


	setFont();
	setElementsPositionDimension();
	loadElements(renderer);
	setColor();

	m_creditsTextRect.render(renderer, m_creditsTextRect.getKRect());
	m_creditsCircle.render(renderer, m_creditsCircle.getKRect());
	m_creditsText.textRender(m_creditsText.getKRect(),
			m_creditsText.getKTexture(), renderer);
	m_creditsInGame.textRender(m_creditsInGame.getKRect(),
			m_creditsInGame.getKTexture(), renderer);

}

Font& CreditInGame::getCreditsText()
{
	return m_creditsText;
}

void CreditInGame::setColor()
{
	m_creditsText.setButtonColor(254, 254, 254);
	m_creditsInGame.setButtonColor(254, 254, 254);

}

void CreditInGame::setElementsPositionDimension() {

	m_creditsCircle.setPosition(804, 562, creditsInGameWinCircle_width,
			creditsInGameWInCircle_height);
	m_creditsTextRect.setPosition(621, 573, creditsInGameWinRect_width,
			creditsInGameWinRect_height);
	m_creditsText.setPosition(654, 580, creditsInGameWinTextInRect_width,
			creditsInGameWinTextInRect_height);

	m_creditsInGame.setPosition(819, 575, creditsInGameWinTextInCircle_width,
			creditsInGameWinTextInCircle_height);
}

void CreditInGame::loadElements(SDL_Renderer* renderer) {
	setColor();

	m_creditsTextRect.loadTextureFromFile(
			"Resources/Images/minMaxNumberRect.png", renderer);
	m_creditsCircle.loadTextureFromFile("Resources/Images/buttonCircleRed.png",
			renderer);
	m_creditsInGame.LoadFromRenderedText(toString(m_gameCredit), renderer,
			m_creditsInGame.getButtonColor());
	m_creditsText.LoadFromRenderedText("CREDITS", renderer,
			m_creditsText.getButtonColor());
}

void CreditInGame::setFont() {

	m_creditsText.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
	m_creditsInGame.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
}

const char * CreditInGame::toString(int in_val) {
	std::string str = boost::lexical_cast<std::string>(in_val);
	return str.c_str();
}
