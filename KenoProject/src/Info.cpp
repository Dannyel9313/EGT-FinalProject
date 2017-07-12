/*
 * Info.cpp
 *
 *  Created on: 12.07.2017
 *      Author: Danny
 */

#include "Info.h"

Info::Info() {
	// TODO Auto-generated constructor stub

}

Info::~Info() {
	// TODO Auto-generated destructor stub
}

Font& Info::getBackgroundInfo() {
	return m_backgroundInfo;
}

Font& Info::getButtonBack() {
	return m_buttonBack;
}

Font& Info::getButtonBackPushed() {
	return m_buttonBackPushed;
}

Font& Info::getSecondBackgroundInfo() {
	return m_secondBackgroundInfo;
}

void Info::loadInfoScreen(SDL_Renderer* renderer) {

	setElementsColor();
	setElementsFont();
	setElementsPositionDimension();

	m_backgroundInfo.loadTexture("InfoBackground.png",renderer);
	SDL_RenderCopy(renderer, m_backgroundInfo.getKTexture(),NULL,NULL);

	m_secondBackgroundInfo.loadTexture("introBackgroundMoney.png",renderer);

	m_textInfo.LoadFromRenderedText("Write the rules of game keno",renderer,m_textInfo.getButtonColor());
	m_textInfo.textRender(m_textInfo.getKRect(),m_textInfo.getKTexture(),renderer);

}

void Info::setElementsFont() {
	m_textInfo.setFont(TTF_OpenFont("Disko.ttf",40));
	m_textInformation.setFont(TTF_OpenFont("Disko.ttf",40));
}

void Info::setElementsPositionDimension() {

	m_textInfo.setPosition(40,40,infoText_width,infoText_height);
//	m_textInformation.setPosition(190,38,)

}

void Info::setElementsColor() {
	m_textInfo.setButtonColor(129,268,69);
	m_textInformation.setButtonColor(129,268,69);
}

Font& Info::getTextInfo() {
	return m_textInfo;
}

Font& Info::getTextInformation(){
	return m_textInformation;
}
