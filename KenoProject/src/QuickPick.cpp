/*
 * QuickPick.cpp
 *
 *  Created on: 14.07.2017
 *      Author: Danny
 */

#include "QuickPick.h"

QuickPick::QuickPick() {
	// TODO Auto-generated constructor stub

}

QuickPick::~QuickPick() {
	// TODO Auto-generated destructor stub
}

BaseObject& QuickPick::getQuickPickRect(){
	return m_quickPickRect;
}

BaseObject& QuickPick::getQuickPickRectPushed(){
	return m_quickPickRectPushed;
}

Font& QuickPick::getQuickPickText(){
	return m_quickPickText;
}
void QuickPick::renderQuickPickButton(SDL_Renderer* renderer) {
	setFont();
	loadElements(renderer);

	setElementsPositionDimension();
	setColor();

	m_quickPickRect.render(renderer, m_quickPickRect.getKRect());
	m_quickPickText.textRender(m_quickPickText.getKRect(),
			m_quickPickText.getKTexture(), renderer);


}

void QuickPick::setColor() {
	m_quickPickText.setButtonColor(254, 0, 0);
}

void QuickPick::setElementsPositionDimension() {

	m_quickPickText.setPosition(304, 519, buttonClearQuickPickText_width,
			buttonClearQuickPickText_height);
	m_quickPickRect.setPosition(294, 513, buttonClearQuickPickRect_width,
			buttonClearQuickPickRect_height);
	m_quickPickRectPushed.setPosition(294, 513, buttonClearQuickPickRect_width,
			buttonClearQuickPickRect_height);

}

void QuickPick::loadElements(SDL_Renderer* renderer) {
	setColor();
	m_quickPickText.LoadFromRenderedText("QUICK PICK", renderer,
			m_quickPickText.getButtonColor());
	m_quickPickRect.loadTextureFromFile("Resources/Images/clearButtonYewoll.png",
			renderer);
	m_quickPickRectPushed.loadTextureFromFile(
			"Resources/Images/clearButtonyewollPushed.png", renderer);
}

void QuickPick::setFont() {
	m_quickPickText.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));

}

void QuickPick::changeColorOnMouseOver(SDL_Renderer* renderer)
{
	if(m_quickPickText.onMouseOver(m_quickPickText.getKRect()))
	{
		m_quickPickText.setButtonColor(102, 0, 0);
		m_quickPickText.LoadFromRenderedText("QUICK PICK", renderer,
				m_quickPickText.getButtonColor());
		m_quickPickRectPushed.render(renderer, m_quickPickRectPushed.getKRect());
		m_quickPickText.textRender(m_quickPickText.getKRect(),
				m_quickPickText.getKTexture(), renderer);
	}
	else
	{
		m_quickPickText.setButtonColor(254,0,0);
		m_quickPickText.LoadFromRenderedText("QUICK PICK", renderer,
				m_quickPickText.getButtonColor());
		m_quickPickText.textRender(m_quickPickText.getKRect(),m_quickPickText.getKTexture(),renderer);
		m_quickPickRect.render(renderer, m_quickPickRect.getKRect());
		m_quickPickText.textRender(m_quickPickText.getKRect(),
				m_quickPickText.getKTexture(), renderer);
	}


}
