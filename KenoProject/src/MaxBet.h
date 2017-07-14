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




	// Set numbers Color
		void setNumbersColor();

		// Set elements position and dimension
		void setElementsPositionDimension();

		// Load elements
		void loadElements(SDL_Renderer* renderer);

		// Render min bet
		void renderMaxBet(SDL_Renderer* renderer);

		// Set font
		void setFont();


		BaseObject& getButtonRectMax();
		BaseObject& getButtonStartCircleMax();
		Font& getMaxBet();
		Font& getNumFiftyMax();
		Font& getNumFiveMax();
		Font& getNumFourtyMax();
		Font& getNumTenMax();
		Font& getNumThirtyMax();
		Font& getNumTwentyMax();

private:

	Font m_numFiveMax;
	Font m_numTenMax;
	Font m_numTwentyMax;
	Font m_numThirtyMax;
	Font m_numFourtyMax;
	Font m_numFiftyMax;

	Font m_maxBet;

	BaseObject m_buttonRectMax;
	BaseObject m_buttonStartCircleMax;
};

#endif /* MAXBET_H_ */
