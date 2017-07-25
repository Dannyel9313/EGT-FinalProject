/*
 * CashOut.h
 *
 *  Created on: 16.07.2017
 *      Author: Danny
 */

#ifndef CASHOUT_H_
#define CASHOUT_H_
#include "Font.h"
#include "BaseObject.h"
#include "Include.h"

class CashOut {
public:
	CashOut();
	virtual ~CashOut();

	// Render
	void renderCashOutButton(SDL_Renderer* renderer);

	// Change button color on mouse over
	void changeColorOnMouseOver(SDL_Renderer* renderer);

	// Get cash out rect
	BaseObject& getCashOutRect();

	// Get cash out rect pushed
	BaseObject& getCashOutRectPushed();

	// Get cash out text
	Font& getCashOutText();

private:

	Font m_cashOutText;

	BaseObject m_cashOutRect;
	BaseObject m_cashOutRectPushed;

	// Set numbers Color
		void setColor();

		// Set elements position and dimension
		void setElementsPositionDimension();

		// Load elements
		void loadElements(SDL_Renderer* renderer);

		// Set font
		void setFont();


};

#endif /* CASHOUT_H_ */
