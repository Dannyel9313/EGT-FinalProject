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

//Font& Info::getSecondBackgroundInfo() {
//	return m_secondBackgroundInfo;
//}

void Info::renderInfoScreen(SDL_Renderer* renderer) {


	setElementsColor();
	setElementsFont();
	setElementsPositionDimension();
	loadInfoElements(renderer);


	m_backgroundInfo.render(renderer, NULL);

	m_textInfo.render(renderer,m_textInfo.getKRect());

if(m_buttonBack.onMouseOver(m_buttonBack.getKRect())){

	m_buttonBack.render(renderer, m_buttonBack.getKRect());

}else{

	m_buttonBackPushed.render(renderer,m_buttonBackPushed.getKRect());

}

	m_textInformation.textRender(m_textInformation.getKRect(),
			m_textInformation.getKTexture(), renderer);

	m_buttonBackText.textRender(m_buttonBackText.getKRect(),m_buttonBackText.getKTexture(),renderer);

	SDL_RenderPresent(renderer);

}

void Info::setElementsFont() {

	m_textInformation.setFont(TTF_OpenFont("Resources/Fonts/AUDI.TTF", 40));
	m_buttonBackText.setFont(TTF_OpenFont("Resources/Fonts/AUDI.TTF", 40));
}

void Info::setElementsPositionDimension() {

	m_textInfo.setPosition(40,140,infoText_width,infoText_height);
	m_textInformation.setPosition(210, 40, infoLogo_Width, infoLogo_height);
	m_buttonBack.setPosition(30, 560, infoButtonBack_width,
			infoButtonBack_height);
	m_buttonBackPushed.setPosition(30, 559, infoButtonBack_width,
			infoButtonBack_height);
	m_buttonBackText.setPosition(15,530, infoButtonBackText_width,infoButtonBackText_height);

}

void Info::setElementsColor() {

	m_textInformation.setButtonColor(129, 268, 69);
	m_buttonBackText.setButtonColor(129,268,69);

}

Font& Info::getTextInfo() {
	return m_textInfo;
}

void Info::loadInfoElements(SDL_Renderer* renderer) {
	m_backgroundInfo.loadTextureFromFile("Resources/Images/infoBackground2.png", renderer);
	m_buttonBack.loadTextureFromFile("Resources/Images/buttonArrowBackIntro.png", renderer);
	m_buttonBackPushed.loadTextureFromFile("Resources/Images/buttonArrowBackIntropushed.png",renderer);
	m_textInfo.loadTextureFromFile("Resources/Images/kenoInfoText.png",renderer);

	m_textInformation.LoadFromRenderedText("Information", renderer,
			m_textInformation.getButtonColor());

	m_buttonBackText.LoadFromRenderedText("BACK",renderer,m_buttonBackText.getButtonColor());

}

Font& Info::getTextInformation() {
	return m_textInformation;
}

Font& Info::getButtonBackText(){
	return m_buttonBackText;
}
