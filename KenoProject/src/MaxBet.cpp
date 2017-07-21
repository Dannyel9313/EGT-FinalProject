/*
 * MaxBet.cpp
 *
 *  Created on: 14.07.2017
 *      Author: Danny
 */

#include "MaxBet.h"

MaxBet::MaxBet():m_maximalBet(0)
{
	// TODO Auto-generated constructor stub

}

MaxBet::~MaxBet()
{
	// TODO Auto-generated destructor stub
}


void MaxBet::setNumbersColor()
{

	m_numFiveMax.setButtonColor(254, 254, 254);
	m_numTenMax.setButtonColor(254, 254, 254);
	m_numTwentyMax.setButtonColor(254, 254, 254);
	m_numThirtyMax.setButtonColor(254, 254, 254);
	m_numFourtyMax.setButtonColor(254, 254, 254);
	m_numFiftyMax.setButtonColor(254, 254, 254);
	m_maxBet.setButtonColor(254 , 254, 254);

}

void MaxBet::setElementsPositionDimension()
{

	m_buttonStartCircleMax.setPosition(20, 562, minMaxBetCircle_width,
			minMaxBetCircle_height);
	m_buttonRectMax.setPosition(67, 573, minMaxBetRectangle_width,
			minMaxBetRectangle_height);
	m_maxBet.setPosition(30, 575, minMaxBetText_width,
			minMaxBetText_height);
	m_numFiveMax.setPosition(82,579,betNumbers_width,betNumbersMax_height);
	m_numTenMax.setPosition(110,579,betNumbersMax_width,betNumbersMax_height);
	m_numTwentyMax.setPosition(138,579,betNumbersMax_width,betNumbersMax_height);
	m_numThirtyMax.setPosition(166,579,betNumbersMax_width,betNumbersMax_height);
	m_numFourtyMax.setPosition(194,579,betNumbersMax_width,betNumbersMax_height);
	m_numFiftyMax.setPosition(222,579,betNumbersMax_width,betNumbersMax_height);

}

void MaxBet::loadElements(SDL_Renderer* renderer)
{

	setNumbersColor();

	m_buttonRectMax.loadTextureFromFile("Resources/Images/minMaxNumberRect.png",
			renderer);
	m_buttonStartCircleMax.loadTextureFromFile(
			"Resources/Images/buttonCircleRed.png", renderer);

	m_numFiveMax.LoadFromRenderedText("5", renderer, m_numFiveMax.getButtonColor());
	m_numTenMax.LoadFromRenderedText("10", renderer, m_numTenMax.getButtonColor());
	m_numTwentyMax.LoadFromRenderedText("20", renderer, m_numTwentyMax.getButtonColor());
	m_numThirtyMax.LoadFromRenderedText("30", renderer, m_numThirtyMax.getButtonColor());
	m_numFourtyMax.LoadFromRenderedText("40", renderer, m_numFourtyMax.getButtonColor());
	m_numFiftyMax.LoadFromRenderedText("50", renderer, m_numFiftyMax.getButtonColor());

	m_maxBet.LoadFromRenderedText("MAX", renderer, m_maxBet.getButtonColor());

}

void MaxBet::choiceNumberFive(SDL_Renderer* renderer, const SDL_Event& e)
{
	if(m_numFiveMax.isClicked(e,m_numFiveMax.getKRect()))
			{

				m_buttonRectMax.render(renderer,m_buttonRectMax.getKRect());

				m_buttonStartCircleMax.render(renderer,m_buttonStartCircleMax.getKRect());

				m_maxBet.render(renderer,m_maxBet.getKRect());
				m_numFiveMax.setButtonColor(251,211,72);
				m_numFiveMax.LoadFromRenderedText("5", renderer, m_numFiveMax.getButtonColor());
				m_numFiveMax.render(renderer,m_numFiveMax.getKRect());

				m_numTwentyMax.setButtonColor(254, 254, 254);
				m_numTwentyMax.LoadFromRenderedText("20",renderer,m_numTwentyMax.getButtonColor());
				m_numTwentyMax.render(renderer,m_numTwentyMax.getKRect());

				m_numThirtyMax.setButtonColor(254, 254, 254);
				m_numThirtyMax.LoadFromRenderedText("30",renderer,m_numThirtyMax.getButtonColor());
				m_numThirtyMax.render(renderer, m_numThirtyMax.getKRect());

				m_numFourtyMax.setButtonColor(254, 254, 254);
				m_numFourtyMax.LoadFromRenderedText("40",renderer,m_numFourtyMax.getButtonColor());
				m_numFourtyMax.render(renderer, m_numFourtyMax.getKRect());

				m_numFiftyMax.setButtonColor(254, 254, 254);
				m_numFiftyMax.LoadFromRenderedText("50",renderer,m_numFiftyMax.getButtonColor());
				m_numFiftyMax.render(renderer,m_numFiftyMax.getKRect());

				m_numTenMax.setButtonColor(254, 254, 254);
				m_numTenMax.LoadFromRenderedText("10",renderer,m_numTenMax.getButtonColor());
				m_numTenMax.render(renderer,m_numTenMax.getKRect());
				setMaximalBet(5);
			}


}

void MaxBet::choiceNumberTwenty(SDL_Renderer* renderer, const SDL_Event& e)
{
	if(m_numTwentyMax.isClicked(e,m_numTwentyMax.getKRect()))
			{

				m_buttonRectMax.render(renderer,m_buttonRectMax.getKRect());

				m_buttonStartCircleMax.render(renderer,m_buttonStartCircleMax.getKRect());

				m_maxBet.render(renderer,m_maxBet.getKRect());
				m_numFiveMax.setButtonColor(254, 254, 254);
				m_numFiveMax.LoadFromRenderedText("5", renderer, m_numFiveMax.getButtonColor());
				m_numFiveMax.render(renderer,m_numFiveMax.getKRect());

				m_numTwentyMax.setButtonColor(251, 211, 72);
				m_numTwentyMax.LoadFromRenderedText("20",renderer,m_numTwentyMax.getButtonColor());
				m_numTwentyMax.render(renderer,m_numTwentyMax.getKRect());

				m_numThirtyMax.setButtonColor(254, 254, 254);
				m_numThirtyMax.LoadFromRenderedText("30",renderer,m_numThirtyMax.getButtonColor());
				m_numThirtyMax.render(renderer, m_numThirtyMax.getKRect());

				m_numFourtyMax.setButtonColor(254, 254, 254);
				m_numFourtyMax.LoadFromRenderedText("40",renderer,m_numFourtyMax.getButtonColor());
				m_numFourtyMax.render(renderer, m_numFourtyMax.getKRect());

				m_numFiftyMax.setButtonColor(254, 254, 254);
				m_numFiftyMax.LoadFromRenderedText("50",renderer,m_numFiftyMax.getButtonColor());
				m_numFiftyMax.render(renderer,m_numFiftyMax.getKRect());

				m_numTenMax.setButtonColor(254, 254, 254);
				m_numTenMax.LoadFromRenderedText("10",renderer,m_numTenMax.getButtonColor());
				m_numTenMax.render(renderer,m_numTenMax.getKRect());
				setMaximalBet(20);
			}
}

void MaxBet::choiceNumberThirty(SDL_Renderer* renderer, const SDL_Event& e)
{
	if(m_numThirtyMax.isClicked(e,m_numThirtyMax.getKRect()))
				{

					m_buttonRectMax.render(renderer,m_buttonRectMax.getKRect());

					m_buttonStartCircleMax.render(renderer,m_buttonStartCircleMax.getKRect());

					m_maxBet.render(renderer,m_maxBet.getKRect());
					m_numFiveMax.setButtonColor(254, 254, 254);
					m_numFiveMax.LoadFromRenderedText("5", renderer, m_numFiveMax.getButtonColor());
					m_numFiveMax.render(renderer,m_numFiveMax.getKRect());

					m_numTwentyMax.setButtonColor(254, 254, 254);
					m_numTwentyMax.LoadFromRenderedText("20",renderer,m_numTwentyMax.getButtonColor());
					m_numTwentyMax.render(renderer,m_numTwentyMax.getKRect());

					m_numThirtyMax.setButtonColor(251, 211, 72);
					m_numThirtyMax.LoadFromRenderedText("30",renderer,m_numThirtyMax.getButtonColor());
					m_numThirtyMax.render(renderer, m_numThirtyMax.getKRect());

					m_numFourtyMax.setButtonColor(254, 254, 254);
					m_numFourtyMax.LoadFromRenderedText("40",renderer,m_numFourtyMax.getButtonColor());
					m_numFourtyMax.render(renderer, m_numFourtyMax.getKRect());

					m_numFiftyMax.setButtonColor(254, 254, 254);
					m_numFiftyMax.LoadFromRenderedText("50",renderer,m_numFiftyMax.getButtonColor());
					m_numFiftyMax.render(renderer,m_numFiftyMax.getKRect());

					m_numTenMax.setButtonColor(254, 254, 254);
					m_numTenMax.LoadFromRenderedText("10",renderer,m_numTenMax.getButtonColor());
					m_numTenMax.render(renderer,m_numTenMax.getKRect());
					setMaximalBet(30);
				}
}

void MaxBet::choiceNumberFourty(SDL_Renderer* renderer, const SDL_Event& e)
{
	if(m_numFourtyMax.isClicked(e,m_numFourtyMax.getKRect()))
				{

					m_buttonRectMax.render(renderer,m_buttonRectMax.getKRect());

					m_buttonStartCircleMax.render(renderer,m_buttonStartCircleMax.getKRect());

					m_maxBet.render(renderer,m_maxBet.getKRect());
					m_numFiveMax.setButtonColor(254, 254, 254);
					m_numFiveMax.LoadFromRenderedText("5", renderer, m_numFiveMax.getButtonColor());
					m_numFiveMax.render(renderer,m_numFiveMax.getKRect());

					m_numTwentyMax.setButtonColor(254, 254, 254);
					m_numTwentyMax.LoadFromRenderedText("20",renderer,m_numTwentyMax.getButtonColor());
					m_numTwentyMax.render(renderer,m_numTwentyMax.getKRect());

					m_numThirtyMax.setButtonColor(254, 254, 254);
					m_numThirtyMax.LoadFromRenderedText("30",renderer,m_numThirtyMax.getButtonColor());
					m_numThirtyMax.render(renderer, m_numThirtyMax.getKRect());

					m_numFourtyMax.setButtonColor(251, 211, 72);
					m_numFourtyMax.LoadFromRenderedText("40",renderer,m_numFourtyMax.getButtonColor());
					m_numFourtyMax.render(renderer, m_numFourtyMax.getKRect());

					m_numFiftyMax.setButtonColor(254, 254, 254);
					m_numFiftyMax.LoadFromRenderedText("50",renderer,m_numFiftyMax.getButtonColor());
					m_numFiftyMax.render(renderer,m_numFiftyMax.getKRect());

					m_numTenMax.setButtonColor(254, 254, 254);
					m_numTenMax.LoadFromRenderedText("10",renderer,m_numTenMax.getButtonColor());
					m_numTenMax.render(renderer,m_numTenMax.getKRect());
					setMaximalBet(40);
				}
}

void MaxBet::betChoiceMax(SDL_Renderer* renderer, const SDL_Event& e)
{
choiceNumberFive(renderer, e);
choiceNumberTen(renderer, e);
choiceNumberTwenty(renderer, e);
choiceNumberThirty(renderer, e);
choiceNumberFourty(renderer, e);
choiceNumberFifty(renderer, e);

}

int MaxBet::getMaximalBet() const {
	return m_maximalBet;
}

void MaxBet::setMaximalBet(int maximalBet) {
	m_maximalBet = maximalBet;
}

void MaxBet::choiceNumberFifty(SDL_Renderer* renderer, const SDL_Event& e)
{
	if(m_numFiftyMax.isClicked(e,m_numFiftyMax.getKRect()))
				{

					m_buttonRectMax.render(renderer,m_buttonRectMax.getKRect());

					m_buttonStartCircleMax.render(renderer,m_buttonStartCircleMax.getKRect());

					m_maxBet.render(renderer,m_maxBet.getKRect());
					m_numFiveMax.setButtonColor(254, 254, 254);
					m_numFiveMax.LoadFromRenderedText("5", renderer, m_numFiveMax.getButtonColor());
					m_numFiveMax.render(renderer,m_numFiveMax.getKRect());

					m_numTwentyMax.setButtonColor(254, 254, 254);
					m_numTwentyMax.LoadFromRenderedText("20",renderer,m_numTwentyMax.getButtonColor());
					m_numTwentyMax.render(renderer,m_numTwentyMax.getKRect());

					m_numThirtyMax.setButtonColor(254, 254, 254);
					m_numThirtyMax.LoadFromRenderedText("30",renderer,m_numThirtyMax.getButtonColor());
					m_numThirtyMax.render(renderer, m_numThirtyMax.getKRect());

					m_numFourtyMax.setButtonColor(254, 254, 254);
					m_numFourtyMax.LoadFromRenderedText("40",renderer,m_numFourtyMax.getButtonColor());
					m_numFourtyMax.render(renderer, m_numFourtyMax.getKRect());

					m_numFiftyMax.setButtonColor(251, 211, 74);
					m_numFiftyMax.LoadFromRenderedText("50",renderer,m_numFiftyMax.getButtonColor());
					m_numFiftyMax.render(renderer,m_numFiftyMax.getKRect());

					m_numTenMax.setButtonColor(254, 254, 254);
					m_numTenMax.LoadFromRenderedText("10",renderer,m_numTenMax.getButtonColor());
					m_numTenMax.render(renderer,m_numTenMax.getKRect());
					setMaximalBet(50);
				}
}

void MaxBet::choiceNumberTen(SDL_Renderer* renderer, const SDL_Event& e)
{
	if(m_numTenMax.isClicked(e,m_numTenMax.getKRect()))
				{

					m_buttonRectMax.render(renderer,m_buttonRectMax.getKRect());

					m_buttonStartCircleMax.render(renderer,m_buttonStartCircleMax.getKRect());

					m_maxBet.render(renderer,m_maxBet.getKRect());
					m_numFiveMax.setButtonColor(254, 254, 254);
					m_numFiveMax.LoadFromRenderedText("5", renderer, m_numFiveMax.getButtonColor());
					m_numFiveMax.render(renderer,m_numFiveMax.getKRect());

					m_numTwentyMax.setButtonColor(254, 254, 254);
					m_numTwentyMax.LoadFromRenderedText("20",renderer,m_numTwentyMax.getButtonColor());
					m_numTwentyMax.render(renderer,m_numTwentyMax.getKRect());

					m_numThirtyMax.setButtonColor(254, 254, 254);
					m_numThirtyMax.LoadFromRenderedText("30",renderer,m_numThirtyMax.getButtonColor());
					m_numThirtyMax.render(renderer, m_numThirtyMax.getKRect());

					m_numFourtyMax.setButtonColor(254, 254, 254);
					m_numFourtyMax.LoadFromRenderedText("40",renderer,m_numFourtyMax.getButtonColor());
					m_numFourtyMax.render(renderer, m_numFourtyMax.getKRect());

					m_numFiftyMax.setButtonColor(254, 254, 254);
					m_numFiftyMax.LoadFromRenderedText("50",renderer,m_numFiftyMax.getButtonColor());
					m_numFiftyMax.render(renderer,m_numFiftyMax.getKRect());

					m_numTenMax.setButtonColor(251, 211, 72);
					m_numTenMax.LoadFromRenderedText("10",renderer,m_numTenMax.getButtonColor());
					m_numTenMax.render(renderer,m_numTenMax.getKRect());
					setMaximalBet(10);
				}
}

void MaxBet::setFont() {

	m_numFiveMax.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
	m_numTenMax.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
	m_numTwentyMax.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
	m_numThirtyMax.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
	m_numFourtyMax.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
	m_numFiftyMax.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
	m_maxBet.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));

}

void MaxBet::renderMaxBet(SDL_Renderer* renderer) {

	setFont();
	loadElements(renderer);
	setElementsPositionDimension();
	setNumbersColor();

	m_buttonRectMax.render(renderer, m_buttonRectMax.getKRect());
	m_buttonStartCircleMax.render(renderer, m_buttonStartCircleMax.getKRect());
	m_maxBet.textRender(m_maxBet.getKRect(),m_maxBet.getKTexture(),renderer);
	m_numFiveMax.textRender(m_numFiveMax.getKRect(),m_numFiveMax.getKTexture(),renderer);
	m_numTenMax.textRender(m_numTenMax.getKRect(),m_numTenMax.getKTexture(),renderer);
	m_numTwentyMax.textRender(m_numTwentyMax.getKRect(),m_numTwentyMax.getKTexture(),renderer);
	m_numThirtyMax.textRender(m_numThirtyMax.getKRect(),m_numThirtyMax.getKTexture(),renderer);
	m_numFourtyMax.textRender(m_numFourtyMax.getKRect(),m_numFourtyMax.getKTexture(),renderer);
	m_numFiftyMax.textRender(m_numFiftyMax.getKRect(),m_numFiftyMax.getKTexture(),renderer);

}

BaseObject& MaxBet::getButtonRectMax(){
	return m_buttonRectMax;
}

BaseObject& MaxBet::getButtonStartCircleMax() {
	return m_buttonStartCircleMax;
}

Font& MaxBet::getMaxBet(){
	return m_maxBet;
}

Font& MaxBet::getNumFiftyMax() {
	return m_numFiftyMax;
}

Font& MaxBet::getNumFiveMax() {
	return m_numFiveMax;
}

Font& MaxBet::getNumFourtyMax(){
	return m_numFourtyMax;
}

Font& MaxBet::getNumTenMax() {
	return m_numTenMax;
}

 Font& MaxBet::getNumThirtyMax(){
	return m_numThirtyMax;
}

Font& MaxBet::getNumTwentyMax() {
	return m_numTwentyMax;
}

void MaxBet::changeColorOnMouseOver(SDL_Renderer* renderer)
{
	if(m_buttonStartCircleMax.onMouseOver(m_buttonStartCircleMax.getKRect()))
	{
		m_maxBet.setButtonColor(251, 211, 72);
		m_maxBet.LoadFromRenderedText("MAX", renderer, m_maxBet.getButtonColor());
		m_buttonStartCircleMax.render(renderer, m_buttonStartCircleMax.getKRect());
		m_maxBet.textRender(m_maxBet.getKRect(),
				m_maxBet.getKTexture(), renderer);
	}
	else
	{
		m_maxBet.setButtonColor(254, 254, 254);
		m_maxBet.LoadFromRenderedText("MAX", renderer, m_maxBet.getButtonColor());
			m_buttonStartCircleMax.render(renderer, m_buttonStartCircleMax.getKRect());
			m_maxBet.textRender(m_maxBet.getKRect(),
					m_maxBet.getKTexture(), renderer);
	}



}

void MaxBet::activateMaxButton(SDL_Renderer* renderer) {
	m_buttonRectMax.loadTextureFromFile("Resources/Images/minMaxNumberRect.png",
						renderer);
	m_buttonRectMax.setPosition(67, 573, minMaxBetRectangle_width,
				minMaxBetRectangle_height);
	m_buttonRectMax.render(renderer,m_buttonRectMax.getKRect());

m_buttonStartCircleMax.loadTextureFromFile("Resources/Images/maxMinBettPushedGreen.png",
		renderer);
m_buttonStartCircleMax.render(renderer,m_buttonStartCircleMax.getKRect());

m_maxBet.render(renderer,m_maxBet.getKRect());
m_numFiveMax.render(renderer,m_numFiveMax.getKRect());
m_numTenMax.render(renderer,m_numTenMax.getKRect());
m_numTwentyMax.render(renderer,m_numTwentyMax.getKRect());
m_numThirtyMax.render(renderer,m_numThirtyMax.getKRect());
m_numFourtyMax.render(renderer,m_numFourtyMax.getKRect());
m_numFiftyMax.render(renderer,m_numFiftyMax.getKRect());




}

void MaxBet::deactivateMaxButton(SDL_Renderer* renderer) {

	m_buttonRectMax.setPosition(65, 573, minMaxBetRectangleGrey_width,
				minMaxBetRectangleGrey_height);
	m_buttonRectMax.loadTextureFromFile("Resources/Images/greyMinMaxButton.png",
				renderer);
	m_buttonRectMax.render(renderer,m_buttonRectMax.getKRect());


		m_buttonStartCircleMax.loadTextureFromFile(
				"Resources/Images/buttonCircleGrey.png", renderer);
		m_buttonStartCircleMax.render(renderer,m_buttonStartCircleMax.getKRect());
		m_maxBet.textRender(m_maxBet.getKRect(),m_maxBet.getKTexture(),renderer);

}
