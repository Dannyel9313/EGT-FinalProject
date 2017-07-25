/*
 * CashOut.cpp
 *
 *  Created on: 16.07.2017
 *      Author: Danny
 */

#include "CashOut.h"

CashOut::CashOut() {
	// TODO Auto-generated constructor stub

}

CashOut::~CashOut() {
	// TODO Auto-generated destructor stub
}

BaseObject& CashOut::getCashOutRect() {
	return m_cashOutRect;
}

BaseObject& CashOut::getCashOutRectPushed() {
	return m_cashOutRectPushed;
}

Font& CashOut::getCashOutText() {
	return m_cashOutText;
}

void CashOut::renderCashOutButton(SDL_Renderer* renderer) {
	setFont();
	loadElements(renderer);

	setElementsPositionDimension();
	setColor();

	m_cashOutRect.render(renderer, m_cashOutRect.getKRect());
	m_cashOutText.textRender(m_cashOutText.getKRect(),
			m_cashOutText.getKTexture(), renderer);


}

void CashOut::setColor() {
	m_cashOutText.setButtonColor(254, 0, 0);
}

void CashOut::setElementsPositionDimension() {

	m_cashOutText.setPosition(900,519, cashOutButtonText_width,
			cashOutButtonText_height);
	m_cashOutRect.setPosition(890, 513, cashOutRect_width,
			cashOutRect_height);
	m_cashOutRectPushed.setPosition(890, 513, cashOutRect_width,
			cashOutRect_height);

}

void CashOut::loadElements(SDL_Renderer* renderer) {
	setColor();
	m_cashOutText.LoadFromRenderedText("CASH OUT", renderer,
			m_cashOutText.getButtonColor());
	m_cashOutRect.loadTextureFromFile("Resources/Images/clearButtonYewoll.png",
			renderer);
	m_cashOutRectPushed.loadTextureFromFile(
			"Resources/Images/clearButtonyewollPushed.png", renderer);
}

void CashOut::setFont() {
	m_cashOutText.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));

}

void CashOut::changeColorOnMouseOver(SDL_Renderer* renderer)
{
	if(m_cashOutText.onMouseOver(m_cashOutText.getKRect()))
	{
		m_cashOutText.setButtonColor(102, 0, 0);
		m_cashOutText.LoadFromRenderedText("CASH OUT", renderer,
				m_cashOutText.getButtonColor());
		m_cashOutText.textRender(m_cashOutText.getKRect(),m_cashOutText.getKTexture(),renderer);
		m_cashOutRectPushed.render(renderer, m_cashOutRectPushed.getKRect());
		m_cashOutText.textRender(m_cashOutText.getKRect(),
				m_cashOutText.getKTexture(), renderer);
	}
	else
	{
		m_cashOutText.setButtonColor(254,0,0);
		m_cashOutText.LoadFromRenderedText("CASH OUT", renderer,
				m_cashOutText.getButtonColor());
		m_cashOutText.textRender(m_cashOutText.getKRect(),m_cashOutText.getKTexture(),renderer);
		m_cashOutRect.render(renderer, m_cashOutRect.getKRect());
		m_cashOutText.textRender(m_cashOutText.getKRect(),
				m_cashOutText.getKTexture(), renderer);
	}


}
