/*
 * Volume.cpp
 *
 *  Created on: 10.07.2017
 *      Author: Danny
 */

#include "Volume.h"

Volume::Volume() {
	// TODO Auto-generated constructor stub
	m_movingPoint = 59;
	m_volumePoint = 0;
}

Volume::~Volume() {
	// TODO Auto-generated destructor stub
}

Font& Volume::getFontDot() {
	return m_FontDot;
}

Font& Volume::getFontDotLine() {
	return m_FontDotLine;
}

Font& Volume::getFontMinus() {
	return m_FontMinus;
}

Font& Volume::getFontPlus() {
	return m_FontPlus;
}

void Volume::LoadVolumeElements(SDL_Renderer* renderer) {

	setElementsFont();
	setElementsPositionDimension();
	setElementsColor();

	m_FontDotLine.loadTexture("volumeSlider.png", renderer);

	SDL_RenderCopy(renderer, m_FontDotLine.getKTexture(), NULL,
			m_FontDotLine.getKRect());

	m_FontDot.loadTexture("volumeDot.png", renderer);

	SDL_RenderCopy(renderer, m_FontDot.getKTexture(), NULL,
			m_FontDot.getKRect());

	m_FontPlus.LoadFromRenderedText("+", renderer, m_FontPlus.getButtonColor());

	m_FontPlus.textRender(m_FontPlus.getKRect(), m_FontPlus.getKTexture(),
			renderer);

	m_FontMinus.LoadFromRenderedText("-", renderer,
			m_FontMinus.getButtonColor());

	m_FontMinus.textRender(m_FontMinus.getKRect(), m_FontMinus.getKTexture(),
			renderer);

	m_FontVolume.LoadFromRenderedText("VOLUME", renderer,
			m_FontVolume.getButtonColor());

	m_FontVolume.textRender(m_FontVolume.getKRect(), m_FontVolume.getKTexture(),
			renderer);

}

void Volume::setElementsPositionDimension() {
	m_FontDotLine.setPosition(63, 481, introVolumeSlider_width,
			introVolumeSlider_height);

	m_FontDot.setPosition(m_movingPoint, 498, introVolumeDot_width,
			introVolumeDot_height);

	m_FontPlus.setPosition(183, 495, introVolumeButtons_width,
			introVolumeButtons_height);

	m_FontMinus.setPosition(23, 495, introVolumeButtons_width,

	introVolumeButtons_height);

	m_FontVolume.setPosition(23, 395, introButton_width, introButton_height);
}

void Volume::setElementsFont() {

	m_FontPlus.setFont(TTF_OpenFont("Pozo.ttf", 40));
	m_FontMinus.setFont(TTF_OpenFont("Pozo.ttf", 40));
	m_FontVolume.setFont(TTF_OpenFont("Pozo.ttf", 40));
}

void Volume::moveVolumeDot(SDL_Event* e) {

	if (e->type == SDL_MOUSEBUTTONDOWN) {
		if (m_FontPlus.isClicked(m_FontPlus.getKRect())) {
			if (m_volumePoint > -1 && m_volumePoint < 101 && m_movingPoint > 58
					&& m_movingPoint < 158) {
				m_volumePoint+=10;
				m_movingPoint+=10;
				std::cout << "->" << m_movingPoint << "<-" << "->" << m_volumePoint << "<-" << std::endl;
				Mix_VolumeMusic(m_volumePoint);
			}
		}
		if(m_FontMinus.isClicked(m_FontMinus.getKRect())) {
			if (m_volumePoint > -1 && m_volumePoint < 101 && m_movingPoint > 58
					&& m_movingPoint < 158) {
				m_volumePoint-=10;
				m_movingPoint-=10;
				std::cout << "->" << m_movingPoint << "<-" << std::endl;
				Mix_VolumeMusic(m_volumePoint);
			}
		}
		std::cout << "->" << m_movingPoint << "<-" << "->" << m_volumePoint << "<-" << std::endl;
	}
}

void Volume::setElementsColor() {
	if (m_FontPlus.isClicked(m_FontPlus.getKRect())) {
		m_FontPlus.setButtonColor(255, 0, 39);
	} else {
		m_FontPlus.setButtonColor(255, 255, 255);
	}
	if (m_FontMinus.isClicked(m_FontMinus.getKRect())) {
		m_FontMinus.setButtonColor(255, 0, 39);
	} else {
		m_FontMinus.setButtonColor(255, 255, 255);
	}
	m_FontVolume.setButtonColor(255, 255, 255);
}

Font& Volume::getFontVolume() {
	return m_FontVolume;
}

int Volume::getMovingPoint() const {
	return m_movingPoint;
}

void Volume::setMovingPoint(int movingPoint) {
	m_movingPoint = movingPoint;
}
