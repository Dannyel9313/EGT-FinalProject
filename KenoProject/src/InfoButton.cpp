/*
 * InfoButton.cpp
 *
 *  Created on: Jul 21, 2017
 *      Author: Memmory Of Tomorrow
 */

#include "InfoButton.h"


InfoButton::InfoButton()
{

}

InfoButton::~InfoButton()
{

}

Font& InfoButton::getInfoButton()
{
	return m_buttonInfo;
}

void InfoButton::renderInfoButton(SDL_Renderer* renderer)
{
	loadElements(renderer);
	m_buttonRect.render(renderer, m_buttonRect.getKRect());
	m_buttonInfo.textRender(m_buttonInfo.getKRect(),
				m_buttonInfo.getKTexture(), renderer);
}

void InfoButton::setElementsPositionDimension()
{
	m_buttonInfo.setPosition(INFO_BUTTON_POSITION_X, INFO_BUTTON_POSITION_Y,
			INFO_BUTTON_WIDTH, INFO_BUTTON_HEIGHT);
	m_buttonRect.setPosition(INFO_BUTTON_POSITION_X, INFO_BUTTON_POSITION_Y,
			INFO_BUTTON_WIDTH, INFO_BUTTON_HEIGHT);
	m_buttonRectPushed.setPosition(INFO_BUTTON_POSITION_X, INFO_BUTTON_POSITION_Y,
			INFO_BUTTON_WIDTH, INFO_BUTTON_HEIGHT);
}

void InfoButton::loadElements(SDL_Renderer* renderer)
{
	setElementsPositionDimension();
	m_buttonInfo.setButtonColor(254, 0, 0);
	m_buttonRect.loadTextureFromFile("Resources/Images/gameInfoButton.jpg",
			renderer);
}

void InfoButton::isClickedInfoButton(SDL_Renderer* renderer,
		const SDL_Event& e)
{
	if(m_buttonRect.isClicked(e, m_buttonRect.getKRect()))
	{
		m_buttonRectPushed.render(renderer, m_buttonRectPushed.getKRect());
		m_buttonInfo.textRender(m_buttonInfo.getKRect(), m_buttonInfo.getKTexture(), renderer);
	}
}

BaseObject& InfoButton::getButtonRect()
{
	return m_buttonRect;
}

BaseObject& InfoButton::getButtonRectPushed()
{
	return m_buttonRectPushed;
}
