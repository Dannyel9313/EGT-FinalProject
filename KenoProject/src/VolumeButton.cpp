/*
 * VolumeButton.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: Memmory Of Tomorrow
 */

#include "VolumeButton.h"

VolumeButton::VolumeButton()
{

}

VolumeButton::~VolumeButton()
{

}

Font& VolumeButton::getVolumeButton()
{
	return m_buttonVolume;
}

void VolumeButton::renderVolumeButton(SDL_Renderer* renderer)
{
	loadElements(renderer);
	m_buttonRect.render(renderer, m_buttonRect.getKRect());
	m_buttonVolume.textRender(m_buttonVolume.getKRect(),
				m_buttonVolume.getKTexture(), renderer);
}

void VolumeButton::setElementsPositionDimension()
{
	m_buttonVolume.setPosition(VOLUME_BUTTON_POSITION_X, VOLUME_BUTTON_POSITION_Y,
			VOLUME_BUTTON_WIDTH, VOLUME_BUTTON_HEIGHT);
	m_buttonRect.setPosition(VOLUME_BUTTON_POSITION_X, VOLUME_BUTTON_POSITION_Y,
			VOLUME_BUTTON_WIDTH, VOLUME_BUTTON_HEIGHT);
	m_buttonRectPushed.setPosition(VOLUME_BUTTON_POSITION_X, VOLUME_BUTTON_POSITION_Y,
			VOLUME_BUTTON_WIDTH, VOLUME_BUTTON_HEIGHT);
}

void VolumeButton::loadElements(SDL_Renderer* renderer)
{
	setElementsPositionDimension();
	m_buttonVolume.setButtonColor(254, 0, 0);
	m_buttonRect.loadTextureFromFile("Resources/Images/speaker-volume-button.jpg",
			renderer);
	m_buttonRectPushed.loadTextureFromFile(
			"Resources/Images/Mute volume button.png", renderer);
}

void VolumeButton::isClickedVolumeButton(SDL_Renderer* renderer,
		const SDL_Event& e)
{
	if(m_buttonRect.isClicked(e, m_buttonRect.getKRect()))
	{
		m_buttonRectPushed.render(renderer, m_buttonRectPushed.getKRect());
		m_buttonVolume.textRender(m_buttonVolume.getKRect(), m_buttonVolume.getKTexture(), renderer);
	}
}

BaseObject& VolumeButton::getButtonRect()
{
	return m_buttonRect;
}

BaseObject& VolumeButton::getButtonRectPushed()
{
	return m_buttonRectPushed;
}


