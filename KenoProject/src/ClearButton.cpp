/*
 * ClearButton.cpp
 *
 *  Created on: 14.07.2017
 *      Author: Danny
 */

#include "ClearButton.h"

ClearButton::ClearButton() {
	// TODO Auto-generated constructor stub

}

ClearButton::~ClearButton() {
	// TODO Auto-generated destructor stub
}

Font& ClearButton::getButtonClear() {
	return m_buttonClear;
}

void ClearButton::renderClearButton(SDL_Renderer* renderer) {
	setFont();
	loadElements(renderer);

	setElementsPositionDimension();
	setColor(renderer);


	m_buttonRect.render(renderer, m_buttonRect.getKRect());
	m_buttonClear.textRender(m_buttonClear.getKRect(),
			m_buttonClear.getKTexture(), renderer);


}

void ClearButton::setColor(SDL_Renderer* renderer) {
	if(m_buttonClear.onMouseOver(m_buttonClear.getKRect()))
	{
	m_buttonClear.setButtonColor(24, 236, 19);
	m_buttonClear.textRender(m_buttonClear.getKRect(),m_buttonClear.getKTexture(),renderer);

	}
	else
	{
		m_buttonClear.setButtonColor(254,0,0);
		m_buttonClear.textRender(m_buttonClear.getKRect(),m_buttonClear.getKTexture(),renderer);

	}


	}

void ClearButton::setElementsPositionDimension() {

	m_buttonClear.setPosition(304, 578, buttonClearQuickPickText_width,
			buttonClearQuickPickText_height);
	m_buttonRect.setPosition(294, 573, buttonClearQuickPickRect_width,
			buttonClearQuickPickRect_height);
	m_buttonRectPushed.setPosition(294, 573, buttonClearQuickPickRect_width,
			buttonClearQuickPickRect_height);

}

void ClearButton::loadElements(SDL_Renderer* renderer) {
	setColor(renderer);
	m_buttonClear.LoadFromRenderedText("CLEAR", renderer,
			m_buttonClear.getButtonColor());
	m_buttonRect.loadTextureFromFile("Resources/Images/clearButtonYewoll.png",
			renderer);
	m_buttonRectPushed.loadTextureFromFile(
			"Resources/Images/clearButtonyewollPushed.png", renderer);
}

bool ClearButton::isClickedClearButton(SDL_Renderer* renderer,
		const SDL_Event& e) {

	bool success = false;

	if(m_buttonRect.isClicked(e,m_buttonRect.getKRect())){
		m_buttonRectPushed.render(renderer,m_buttonRectPushed.getKRect());
//		m_buttonClear.textRender(m_buttonClear.getKRect(),m_buttonClear.getKTexture(),renderer);
	//	SDL_RenderPresent(renderer);
		success = true;
	}

	return success;
}

void ClearButton::setFont() {
	m_buttonClear.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));

}

BaseObject& ClearButton::getButtonRect() {
	return m_buttonRect;
}

BaseObject& ClearButton::getButtonRectPushed() {
	return m_buttonRectPushed;
}
