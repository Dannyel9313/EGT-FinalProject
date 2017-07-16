/*
 * MinBet.h
 *
 *  Created on: 14.07.2017
 *      Author: Danny
 */

#ifndef MINBET_H_
#define MINBET_H_
#include "Font.h"
#include "BaseObject.h"

class MinBet {
public:
	MinBet();
	virtual ~MinBet();

	// Render min bet
	void renderMinBet(SDL_Renderer* renderer);

	void changeColorOnMouseover(SDL_Renderer* renderer);

	Font& getMinBet();
	Font& getNumFive();
	Font& getNumFour();
	Font& getNumOne();
	Font& getNumTen();
	Font& getNumThree();
	Font& getNumTwo();
	BaseObject& getButtonRect();
	BaseObject& getButtonStartCircle();

private:
	Font m_numOne;
	Font m_numTwo;
	Font m_numThree;
	Font m_numFour;
	Font m_numFive;
	Font m_numTen;

	Font m_minBet;

	BaseObject m_buttonRect;
	BaseObject m_buttonStartCircle;
	BaseObject m_buttonMinBetCirclePushed;

	// Set font
	void setFont();

	// Set numbers Color
	void setNumbersColor();

	// Set elements position and dimension
	void setElementsPositionDimension();

	// Load elements
	void loadElements(SDL_Renderer* renderer);

};

#endif /* MINBET_H_ */
