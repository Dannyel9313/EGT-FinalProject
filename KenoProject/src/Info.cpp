/*
 * Info.cpp
 *
 *  Created on: 12.07.2017
 *      Author: Danny
 */

#include "Info.h"

Info::Info()
{
	this->m_infoPage = 1;

}

Info::~Info()
{

}

Font& Info::getBackgroundInfo()
{
	return m_backgroundInfo;
}

Font& Info::getButtonBack()
{
	return m_buttonBack;
}



void Info::renderInfoScreen(SDL_Renderer* renderer)
{

	setElementsColor();
	setElementsFont();
	setElementsPositionDimension();
	loadInfoElements(renderer);

	m_backgroundInfo.render(renderer, NULL);
	SDL_SetTextureAlphaMod(m_buttonBack.getKTexture(),100);
	m_buttonBack.render(renderer, m_buttonBack.getKRect());
	m_buttonBackText.textRender(m_buttonBackText.getKRect(),
			m_buttonBackText.getKTexture(), renderer);
	SDL_SetTextureAlphaMod(m_buttonNext.getKTexture(),100);
	m_buttonNext.render(renderer, m_buttonNext.getKRect());
	SDL_SetTextureAlphaMod(m_buttonReturn.getKTexture(),100);
	m_buttonReturn.render(renderer, m_buttonReturn.getKRect());
	m_buttonNextText.render(renderer, m_buttonNextText.getKRect());
	m_buttonReturnText.render(renderer, m_buttonReturnText.getKRect());
}

void Info::setElementsFont()
{

	m_buttonReturnText.setFont(TTF_OpenFont("Resources/Fonts/AUDI.TTF", 40));
	m_buttonNextText.setFont(TTF_OpenFont("Resources/Fonts/AUDI.TTF", 40));
	m_buttonBackText.setFont(TTF_OpenFont("Resources/Fonts/AUDI.TTF", 40));
}

void Info::setElementsPositionDimension()
{



	m_buttonBack.setPosition(780, 560, infoButtonBack_width,
			infoButtonBack_height);
	m_buttonNextText.setPosition(880, 520, infoButtonBackText_width,
			infoButtonBackText_height);
	m_buttonReturnText.setPosition(17, 520, infoButtonBackText_width,
			infoButtonBackText_height);
	m_buttonBackText.setPosition(755, 520, infoButtonBackText_width,
			infoButtonBackText_height);
	m_buttonNext.setPosition(905, 560, infoButtonBack_width,
			infoButtonBack_height);
	m_buttonReturn.setPosition(30, 563, infoButtonBack_width,
			infoButtonBack_height);

}

void Info::setElementsColor()
{

	m_buttonReturnText.setButtonColor(251, 211, 72);
	m_buttonNextText.setButtonColor(251, 211, 72);
	m_buttonBackText.setButtonColor(251, 211, 72);

}

Font& Info::getButtonNext()
{
	return m_buttonNext;
}

Font& Info::getButtonReturn()
{
	return m_buttonReturn;
}

Font& Info::getButtonNextText()
{
	return m_buttonNextText;
}

Font& Info::getButtonReturnText()
{
	return m_buttonReturnText;
}

void Info::renderButtonDown(SDL_Renderer* renderer, const SDL_Event& e)
{

	if (m_buttonNext.isClicked(e, m_buttonNext.getKRect()))
	{
		setInfoPage(2);
		m_backgroundInfo.loadTextureFromFile("Resources/Images/infoTable.png", renderer);
		m_backgroundInfo.render(renderer,NULL);
		m_buttonBack.render(renderer, m_buttonBack.getKRect());
		m_buttonBackText.textRender(m_buttonBackText.getKRect(),
				m_buttonBackText.getKTexture(), renderer);
		SDL_SetTextureAlphaMod(m_buttonNext.getKTexture(),100);
		m_buttonNext.render(renderer, m_buttonNext.getKRect());
		m_buttonReturn.render(renderer, m_buttonReturn.getKRect());
		m_buttonNextText.render(renderer, m_buttonNextText.getKRect());
		m_buttonReturnText.render(renderer, m_buttonReturnText.getKRect());

	}
	if (m_buttonBack.isClicked(e, m_buttonBack.getKRect()))
	{
		setInfoPage(1);
		m_backgroundInfo.loadTextureFromFile(
					"Resources/Images/kenoInformationBackground.png", renderer);
		m_backgroundInfo.render(renderer, NULL);
		SDL_SetTextureAlphaMod(m_buttonBack.getKTexture(),100);
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

void Info::renderButtonReturnOnMouseOver(SDL_Renderer* renderer,
		const SDL_Event& e)
{
	if(m_buttonReturn.onMouseOver(m_buttonReturn.getKRect()))
	{

		SDL_SetTextureAlphaMod(m_buttonReturn.getKTexture(),255);
		m_buttonReturn.render(renderer, m_buttonReturn.getKRect());
	}
	else
	{
		SDL_SetTextureAlphaMod(m_buttonReturn.getKTexture(),100);
					m_backgroundInfo.render(renderer,NULL);
					m_buttonBack.render(renderer, m_buttonBack.getKRect());
					m_buttonBackText.render(renderer,m_buttonBackText.getKRect());
					m_buttonNext.render(renderer, m_buttonNext.getKRect());
					m_buttonNextText.render(renderer,m_buttonNextText.getKRect());
					m_buttonReturn.render(renderer, m_buttonReturn.getKRect());
					m_buttonReturnText.render(renderer, m_buttonReturnText.getKRect());
	}



}

void Info::renderButtonBackOnMauseOver(SDL_Renderer* renderer,
		const SDL_Event& e)
{
if(m_infoPage == 2)
{
	if(m_buttonBack.onMouseOver(m_buttonBack.getKRect()))
		{



			SDL_SetTextureAlphaMod(m_buttonBack.getKTexture(),255);
			m_buttonBack.render(renderer, m_buttonBack.getKRect());
		}
		else
		{


			SDL_SetTextureAlphaMod(m_buttonBack.getKTexture(),100);
			m_backgroundInfo.render(renderer,NULL);
			m_buttonBack.render(renderer, m_buttonBack.getKRect());
			m_buttonBackText.render(renderer,m_buttonBackText.getKRect());
			m_buttonNext.render(renderer, m_buttonNext.getKRect());
			m_buttonNextText.render(renderer,m_buttonNextText.getKRect());
			m_buttonReturn.render(renderer, m_buttonReturn.getKRect());
			m_buttonReturnText.render(renderer, m_buttonReturnText.getKRect());
		}
}
}

void Info::renderButtonNextOnMauseOver(SDL_Renderer* renderer,
		const SDL_Event& e)
{
	if(m_infoPage == 1)
	{
	if(m_buttonNext.onMouseOver(m_buttonNext.getKRect()))
			{

			SDL_SetTextureAlphaMod(m_buttonNext.getKTexture(),255);
			m_buttonNext.render(renderer, m_buttonNext.getKRect());
			}
			else
			{
				SDL_SetTextureAlphaMod(m_buttonNext.getKTexture(),100);
				m_backgroundInfo.render(renderer,NULL);
							m_buttonBack.render(renderer, m_buttonBack.getKRect());
							m_buttonBackText.render(renderer,m_buttonBackText.getKRect());
							m_buttonNext.render(renderer, m_buttonNext.getKRect());
							m_buttonNextText.render(renderer,m_buttonNextText.getKRect());
							m_buttonReturn.render(renderer, m_buttonReturn.getKRect());
							m_buttonReturnText.render(renderer, m_buttonReturnText.getKRect());
			}
	}
}

int Info::getInfoPage() const {
	return m_infoPage;
}

void Info::setInfoPage(int infoPage) {
	m_infoPage = infoPage;
}

void Info::loadInfoElements(SDL_Renderer* renderer)
{



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

void Info::renderOnMauseOver(SDL_Renderer* renderer, const SDL_Event& e)
{
	renderButtonReturnOnMouseOver(renderer, e);
	renderButtonBackOnMauseOver(renderer, e);
	renderButtonNextOnMauseOver(renderer, e);
}
