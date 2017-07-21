#include "ClearButton.h"

ClearButton::ClearButton() {}

ClearButton::~ClearButton() {}

Font& ClearButton::getButtonClear() 
{
	return m_buttonClear;
}

void ClearButton::renderClearButton(SDL_Renderer* renderer) 
{
	loadElements(renderer);
	m_buttonRect.render(renderer, m_buttonRect.getKRect());
	m_buttonClear.textRender(m_buttonClear.getKRect(),
				m_buttonClear.getKTexture(), renderer);
}

void ClearButton::changeColorOnMouseOver(SDL_Renderer* renderer)
{
	if(m_buttonClear.onMouseOver(m_buttonClear.getKRect()))
	{
		m_buttonClear.setButtonColor(102, 0, 0);
		m_buttonClear.LoadFromRenderedText("CLEAR", renderer,
				m_buttonClear.getButtonColor());
		m_buttonRectPushed.render(renderer, m_buttonRectPushed.getKRect());
		m_buttonClear.textRender(m_buttonClear.getKRect(),
				m_buttonClear.getKTexture(), renderer);
	}
	else
	{
		m_buttonClear.setButtonColor(254,0,0);
		m_buttonClear.LoadFromRenderedText("CLEAR", renderer,
				m_buttonClear.getButtonColor());
		m_buttonClear.textRender(m_buttonClear.getKRect(),m_buttonClear.getKTexture(),renderer);
		m_buttonRect.render(renderer, m_buttonRect.getKRect());
		m_buttonClear.textRender(m_buttonClear.getKRect(),
				m_buttonClear.getKTexture(), renderer);
	}
}

void ClearButton::setElementsPositionDimension() 
{
	m_buttonClear.setPosition(340, 578, buttonClearQuickPickText_width,
			buttonClearQuickPickText_height);
	m_buttonRect.setPosition(330, 573, buttonClearQuickPickRect_width,
			buttonClearQuickPickRect_height);
	m_buttonRectPushed.setPosition(330, 573, buttonClearQuickPickRect_width,
			buttonClearQuickPickRect_height);
}

void ClearButton::loadElements(SDL_Renderer* renderer) 
{
	setElementsPositionDimension();
	m_buttonClear.setButtonColor(254, 0, 0);
	m_buttonClear.LoadFromRenderedText("CLEAR", renderer,
			m_buttonClear.getButtonColor());
	m_buttonRect.loadTextureFromFile("Resources/Images/clearButtonYewoll.png",
			renderer);
	m_buttonRectPushed.loadTextureFromFile(
			"Resources/Images/clearButtonyewollPushed.png", renderer);
}

void ClearButton::isClickedClearButton(SDL_Renderer* renderer,
		const SDL_Event& e) 
{
	if(m_buttonRect.isClicked(e,m_buttonRect.getKRect()))
	{
		m_buttonRectPushed.render(renderer,m_buttonRectPushed.getKRect());
		m_buttonClear.textRender(m_buttonClear.getKRect(),m_buttonClear.getKTexture(),renderer);
	}
}

BaseObject& ClearButton::getButtonRect() 
{
	return m_buttonRect;
}

BaseObject& ClearButton::getButtonRectPushed() 
{
	return m_buttonRectPushed;
}
