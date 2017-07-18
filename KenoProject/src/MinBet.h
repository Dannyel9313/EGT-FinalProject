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

	// Change color on mouse button
	void changeColorOnMouseOver(SDL_Renderer* renderer);

	//Activate min bet
	void activateMinButton(SDL_Renderer* renderer);

	// Bet choice min
	void betChoiceMin(SDL_Renderer* renderer, const SDL_Event& e);

	//Deactivate min bet
	void deactivateMinButton(SDL_Renderer* renderer);

	Font& getMinBet();
	Font& getNumFive();
	Font& getNumFour();
	Font& getNumOne();
	Font& getNumTen();
	Font& getNumThree();
	Font& getNumTwo();
	BaseObject& getButtonRect();
	BaseObject& getButtonStartCircle();


	//Set and Get minimal bet
	int getMinimalBet() const;
	void setMinimalBet(int minimalBet);

private:
	int m_MinimalBet = 0;

	Font m_numOne;
	Font m_numTwo;
	Font m_numThree;
	Font m_numFour;
	Font m_numFive;
	Font m_numTen;

	Font m_minBet;

	BaseObject m_buttonRect;
	BaseObject m_buttonStartCircle;

	// Set font
	void setFont();

	// Set numbers Color
	void setNumbersColor();

	// Set elements position and dimension
	void setElementsPositionDimension();

	// Load elements
	void loadElements(SDL_Renderer* renderer);

	// change color of number one
	void choiceNumberOne(SDL_Renderer* renderer, const SDL_Event& e);

	// change color of number two
	void choiceNumberTwo(SDL_Renderer* renderer, const SDL_Event& e);

	// change color of number tree
	void choiceNumberThree(SDL_Renderer* renderer, const SDL_Event& e);

	// change color of number four
	void choiceNumberFour(SDL_Renderer* renderer, const SDL_Event& e);

	// change color of number five
	void choiceNumberFive(SDL_Renderer* renderer, const SDL_Event& e);

	// change color of number ten
	void choiceNumberTen(SDL_Renderer* renderer, const SDL_Event& e);

};

#endif /* MINBET_H_ */
