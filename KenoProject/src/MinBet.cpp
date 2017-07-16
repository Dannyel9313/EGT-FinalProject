/*
 * MinBet.cpp
 *
 *  Created on: 14.07.2017
 *      Author: Danny
 */

#include "MinBet.h"

MinBet::MinBet() {
	// TODO Auto-generated constructor stub

}

MinBet::~MinBet() {
	// TODO Auto-generated destructor stub
}

Font& MinBet::getMinBet() {
	return m_minBet;
}

Font& MinBet::getNumFive() {
	return m_numFive;
}

Font& MinBet::getNumFour() {
	return m_numFour;
}

Font& MinBet::getNumOne() {
	return m_numOne;
}

Font& MinBet::getNumTen() {
	return m_numTen;
}

Font& MinBet::getNumThree() {
	return m_numThree;
}

Font& MinBet::getNumTwo() {
	return m_numTwo;
}

BaseObject& MinBet::getButtonRect() {
	return m_buttonRect;
}

void MinBet::setNumbersColor() {

	m_numOne.setButtonColor(0, 0, 0);
	m_numTwo.setButtonColor(0, 0, 0);
	m_numThree.setButtonColor(0, 0, 0);
	m_numFour.setButtonColor(0, 0, 0);
	m_numFive.setButtonColor(0, 0, 0);
	m_numTen.setButtonColor(0, 0, 0);
	m_minBet.setButtonColor(0, 0, 0);

}

void MinBet::setElementsPositionDimension() {

	m_buttonStartCircle.setPosition(20, 502, minMaxBetCircle_width,
			minMaxBetCircle_height);
	m_buttonRect.setPosition(67, 513, minMaxBetRectangle_width,
			minMaxBetRectangle_height);
	m_minBet.setPosition(30, 515, minMaxBetText_width,
			minMaxBetText_height);
	m_numOne.setPosition(82,519,betNumbers_width,betNumbers_height);
	m_numTwo.setPosition(110,519,betNumbers_width,betNumbers_height);
	m_numThree.setPosition(138,519,betNumbers_width,betNumbers_height);
	m_numFour.setPosition(166,519,betNumbers_width,betNumbers_height);
	m_numFive.setPosition(194,519,betNumbers_width,betNumbers_height);
	m_numTen.setPosition(222,519,betNumbersMax_width,betNumbersMax_height);

}

void MinBet::loadElements(SDL_Renderer* renderer) {

	setNumbersColor();

	m_buttonRect.loadTextureFromFile("Resources/Images/minMaxNumberRect.png",
			renderer);
	m_buttonStartCircle.loadTextureFromFile(
			"Resources/Images/buttonCircleRed.png", renderer);

	m_numOne.LoadFromRenderedText("1", renderer, m_numOne.getButtonColor());
	m_numTwo.LoadFromRenderedText("2", renderer, m_numTwo.getButtonColor());
	m_numThree.LoadFromRenderedText("3", renderer, m_numThree.getButtonColor());
	m_numFour.LoadFromRenderedText("4", renderer, m_numFour.getButtonColor());
	m_numFive.LoadFromRenderedText("5", renderer, m_numFive.getButtonColor());
	m_numTen.LoadFromRenderedText("10", renderer, m_numTen.getButtonColor());

	m_minBet.LoadFromRenderedText("MIN", renderer, m_minBet.getButtonColor());

}

void MinBet::setFont() {

	m_numOne.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
	m_numTwo.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
	m_numThree.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
	m_numFour.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
	m_numFive.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
	m_numTen.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
	m_minBet.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));

}

void MinBet::renderMinBet(SDL_Renderer* renderer) {

	setFont();
	loadElements(renderer);
	setElementsPositionDimension();
	setNumbersColor();

	m_buttonRect.render(renderer, m_buttonRect.getKRect());
	m_buttonStartCircle.render(renderer, m_buttonStartCircle.getKRect());
	m_minBet.textRender(m_minBet.getKRect(),m_minBet.getKTexture(),renderer);
	m_numOne.textRender(m_numOne.getKRect(),m_numOne.getKTexture(),renderer);
	m_numTwo.textRender(m_numTwo.getKRect(),m_numTwo.getKTexture(),renderer);
	m_numThree.textRender(m_numThree.getKRect(),m_numThree.getKTexture(),renderer);
	m_numFour.textRender(m_numFour.getKRect(),m_numFour.getKTexture(),renderer);
	m_numFive.textRender(m_numFive.getKRect(),m_numFive.getKTexture(),renderer);
	m_numTen.textRender(m_numTen.getKRect(),m_numTen.getKTexture(),renderer);

}

BaseObject& MinBet::getButtonStartCircle() {
	return m_buttonStartCircle;
}

void MinBet::changeColorOnMouseover(SDL_Renderer* renderer)
{
	if(m_buttonStartCircle.onMouseOver(m_buttonStartCircle.getKRect()))
	{
		m_minBet.setButtonColor(24, 236, 19);
		m_minBet.LoadFromRenderedText("MIN", renderer, m_minBet.getButtonColor());
		m_buttonStartCircle.render(renderer, m_buttonStartCircle.getKRect());
		m_minBet.textRender(m_minBet.getKRect(),
				m_minBet.getKTexture(), renderer);
	}
	else
	{
		m_minBet.setButtonColor(0, 0, 0);
			m_minBet.LoadFromRenderedText("MIN", renderer, m_minBet.getButtonColor());
			m_buttonStartCircle.render(renderer, m_buttonStartCircle.getKRect());
			m_minBet.textRender(m_minBet.getKRect(),
					m_minBet.getKTexture(), renderer);
	}



}
