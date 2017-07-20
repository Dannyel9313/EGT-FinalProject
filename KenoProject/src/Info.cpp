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

Font& Info::getSecondBackgroundInfo() {
	return m_secondBackgroundInfo;
}

void Info::renderInfoScreen(SDL_Renderer* renderer) {

	setElementsColor();
	setElementsFont();
	setElementsPositionDimension();
	loadInfoElements(renderer);

	m_backgroundInfo.render(renderer, NULL);
	m_buttonBack.render(renderer, m_buttonBack.getKRect());
	m_buttonBackText.textRender(m_buttonBackText.getKRect(),
			m_buttonBackText.getKTexture(), renderer);
	m_buttonNext.render(renderer, m_buttonNext.getKRect());
	m_buttonReturn.render(renderer, m_buttonReturn.getKRect());
	m_buttonNextText.render(renderer, m_buttonNextText.getKRect());
	m_buttonReturnText.render(renderer, m_buttonReturnText.getKRect());
}

void Info::setElementsFont() {

	m_buttonReturnText.setFont(TTF_OpenFont("Resources/Fonts/AUDI.TTF", 40));
	m_buttonNextText.setFont(TTF_OpenFont("Resources/Fonts/AUDI.TTF", 40));
	m_buttonBackText.setFont(TTF_OpenFont("Resources/Fonts/AUDI.TTF", 40));
}

void Info::setElementsPositionDimension() {

	m_queficients.setPosition(130,130, 500, 300);

	m_buttonBack.setPosition(580, 560, infoButtonBack_width,
			infoButtonBack_height);
	m_buttonNextText.setPosition(680, 520, infoButtonBackText_width,
			infoButtonBackText_height);
	m_buttonReturnText.setPosition(17, 520, infoButtonBackText_width,
			infoButtonBackText_height);
	m_buttonBackText.setPosition(555, 520, infoButtonBackText_width,
			infoButtonBackText_height);
	m_buttonNext.setPosition(705, 560, infoButtonBack_width,
			infoButtonBack_height);
	m_buttonReturn.setPosition(30, 563, infoButtonBack_width,
			infoButtonBack_height);

}

void Info::setElementsColor() {

	m_buttonReturnText.setButtonColor(251, 211, 72);
	m_buttonNextText.setButtonColor(251, 211, 72);
	m_buttonBackText.setButtonColor(251, 211, 72);

}

Font& Info::getButtonNext() {
	return m_buttonNext;
}

Font& Info::getButtonReturn() {
	return m_buttonReturn;
}

Font& Info::getButtonNextText() {
	return m_buttonNextText;
}

Font& Info::getButtonReturnText() {
	return m_buttonReturnText;
}

void Info::renderButtonDown(SDL_Renderer* renderer, const SDL_Event& e) {

	if (m_buttonNext.isClicked(e, m_buttonNext.getKRect()))
	{
		std::cout << "NExt ->" << m_buttonNext.isClicked(e, m_buttonNext.getKRect()) << std::endl;

		m_secondBackgroundInfo.render(renderer,NULL);
//		m_queficients.render(renderer,m_queficients.getKRect());
		m_buttonBack.render(renderer, m_buttonBack.getKRect());
		m_buttonBackText.textRender(m_buttonBackText.getKRect(),
				m_buttonBackText.getKTexture(), renderer);
		m_buttonNext.render(renderer, m_buttonNext.getKRect());
		m_buttonReturn.render(renderer, m_buttonReturn.getKRect());
		m_buttonNextText.render(renderer, m_buttonNextText.getKRect());
		m_buttonReturnText.render(renderer, m_buttonReturnText.getKRect());

	}
	if (m_buttonBack.isClicked(e, m_buttonBack.getKRect()))
	{
		std::cout << "back ->" << m_buttonBack.isClicked(e, m_buttonBack.getKRect()) << std::endl;
		m_backgroundInfo.render(renderer, NULL);
		m_buttonBack.render(renderer, m_buttonBack.getKRect());
		m_buttonBackText.textRender(m_buttonBackText.getKRect(),
				m_buttonBackText.getKTexture(), renderer);
		m_buttonNext.render(renderer, m_buttonNext.getKRect());
		m_buttonReturn.render(renderer, m_buttonReturn.getKRect());
		m_buttonNextText.render(renderer, m_buttonNextText.getKRect());
		m_buttonReturnText.render(renderer, m_buttonReturnText.getKRect());
	}

}

void Info::buttonReturn(bool* introMode, const SDL_Event& e)
{

	if (m_buttonReturn.isClicked(e, m_buttonReturn.getKRect()))
	{
		*introMode = true;
	}

}

Font& Info::getQueficients(){
	return m_queficients;
}

void Info::loadInfoElements(SDL_Renderer* renderer) {

//	m_queficients.loadTextureFromFile(	"Resources/Images/queficientTable.png", renderer);
	m_secondBackgroundInfo.loadTextureFromFile(
			"Resources/Images/InfoBackgroundSecond (2).jpg", renderer);
	m_backgroundInfo.loadTextureFromFile(
			"Resources/Images/kenoInformationBackground.png", renderer);
	m_buttonBack.loadTextureFromFile(
			"Resources/Images/buttonBackYewollArrow.png", renderer);
	m_buttonNext.loadTextureFromFile(
			"Resources/Images/buttonNextYewollArrow.png", renderer);
	m_buttonReturn.loadTextureFromFile("Resources/Images/Button retur.png",
			renderer);
	m_buttonBackText.LoadFromRenderedText("BACK", renderer,
			m_buttonBackText.getButtonColor());
	m_buttonNextText.LoadFromRenderedText("NEXT", renderer,
			m_buttonNextText.getButtonColor());
	m_buttonReturnText.LoadFromRenderedText("RETURN", renderer,
			m_buttonReturnText.getButtonColor());
}

Font& Info::getButtonBackText() {
	return m_buttonBackText;
}
