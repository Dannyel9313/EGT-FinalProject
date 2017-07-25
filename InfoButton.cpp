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
	setElementsPositionDimension();
	loadElements(renderer);
	setElementsPositionDimension();
	m_buttonRect.render(renderer, m_buttonRect.getKRect());

}

void InfoButton::setElementsPositionDimension()
{

	m_buttonRect.setPosition(INFO_BUTTON_POSITION_X, INFO_BUTTON_POSITION_Y,
			INFO_BUTTON_WIDTH, INFO_BUTTON_HEIGHT);

}

void InfoButton::loadElements(SDL_Renderer* renderer)
{


	m_buttonRect.loadTextureFromFile("Resources/Images/infoButtonGame.png",
			renderer);
}

void InfoButton::isClickedInfoButton(SDL_Renderer* renderer,
		const SDL_Event& e)
{
	if(m_buttonRect.isClicked(e, m_buttonRect.getKRect()))
	{
		m_buttonRectPushed.loadTextureFromFile("Resources/Images/GameInformation.png",renderer);
		m_buttonRectPushed.render(renderer,NULL);
		m_buttonRect.render(renderer,m_buttonRect.getKRect());

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
