/*
 * MaxBet.h
 *
 *  Created on: 14.07.2017
 *      Author: Danny
 */

#ifndef MAXBET_H_
#define MAXBET_H_
#include "Font.h"
#include "BaseObject.h"
#include "Globals.h"

class MaxBet {
public:
	MaxBet();
	virtual ~MaxBet();

	// Render min bet
	void renderMaxBet(SDL_Renderer* renderer);

	//Change color on mouse over
	void changeColorOnMouseOver(SDL_Renderer* renderer);

	//Activate max bet
	void activateMaxButton(SDL_Renderer* renderer);

	//Deactivate min bet
	void deactivateMaxButton(SDL_Renderer* renderer);

	// Bet choice max
	void betChoiceMax(SDL_Renderer* renderer, const SDL_Event& e);

	BaseObject& getButtonRectMax();
	BaseObject& getButtonStartCircleMax();
	Font& getMaxBet();
	Font& getNumFiftyMax();
	Font& getNumFiveMax();
	Font& getNumFourtyMax();
	Font& getNumTenMax();
	Font& getNumThirtyMax();
	Font& getNumTwentyMax();

	// Set and Get maximal bet
	int getMaximalBet() const;
	void setMaximalBet(int maximalBet);

private:
	int m_maximalBet;

	Font m_numFiveMax;
	Font m_numTenMax;
	Font m_numTwentyMax;
	Font m_numThirtyMax;
	Font m_numFourtyMax;
	Font m_numFiftyMax;

	Font m_maxBet;

	BaseObject m_buttonRectMax;
	BaseObject m_buttonStartCircleMax;

	// Set numbers Color
	void setNumbersColor();

	// Set elements position and dimension
	void setElementsPositionDimension();

	// Load elements
	void loadElements(SDL_Renderer* renderer);

	// Set font
	void setFont();

	// change color of number five
	void choiceNumberFive(SDL_Renderer* renderer, const SDL_Event& e);

	// change color of number ten
	void choiceNumberTen(SDL_Renderer* renderer, const SDL_Event& e);

	// change color of number twenty
	void choiceNumberTwenty(SDL_Renderer* renderer, const SDL_Event& e);

	// change color of number thirty
	void choiceNumberThirty(SDL_Renderer* renderer, const SDL_Event& e);

	// change color of number fourty
	void choiceNumberFourty(SDL_Renderer* renderer, const SDL_Event& e);

	// change color of number fifti
	void choiceNumberFifty(SDL_Renderer* renderer, const SDL_Event& e);

};

#endif /* MAXBET_H_ */
