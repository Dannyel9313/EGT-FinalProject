/*
 * CreditInGame.h
 *
 *  Created on: 14.07.2017
 *      Author: Danny
 */

#ifndef CREDITINGAME_H_
#define CREDITINGAME_H_
#include "Font.h"
#include "Include.h"
#include "BaseObject.h"

class CreditInGame {
public:
	CreditInGame();
	virtual ~CreditInGame();


	// Render min bet
		void renderCreditsInGame(SDL_Renderer* renderer);



	// get credits circle
	BaseObject& getCreditsCircle();

	// Get credits in game
	Font& getCreditsInGame();

	// Get credits rect
	BaseObject& getCreditsTextRect();

	// Get and set credits
	int getGameCredit() const;
	void setGameCredit(int gameCredit);

	// Get credits text
	Font& getCreditsText();

private:

	int m_gameCredit;

	Font m_creditsInGame;
	Font m_creditsText;

	BaseObject m_creditsTextRect;
	BaseObject m_creditsCircle;

	const char * toString(int);

	// Set numbers Color
	void setColor();

	// Set elements position and dimension
	void setElementsPositionDimension();

	// Load elements
	void loadElements(SDL_Renderer* renderer);

	// Set font
	void setFont();
};

#endif /* CREDITINGAME_H_ */
