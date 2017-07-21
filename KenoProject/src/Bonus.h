/*
 * Bonus.h
 *
 *  Created on: 8.07.2017 ã.
 *      Author: ddada
 */

#ifndef BONUS_H_
#define BONUS_H_

#include "Font.h"
#include "BaseObject.h"

class Bonus {
public:
	Bonus();
	virtual ~Bonus();
//	void bonusWindow(SDL_Renderer *,double);
//	void addBonusPercent(double );

	// Set position and dimension
	void setPositionAndDimension(SDL_Renderer* renderer);

	//Render bonus
	void renderBonus(SDL_Renderer* renderer);

	// Load bonus elements
	void loadBonusElements(SDL_Renderer* renderer);

	//Set bonus text font
	void setFont();

	// Set color
	void setColor();


	// Get bonus logo
	BaseObject& getBonusLogo();

	// Get bonus rectangle
	BaseObject& getBonusRectangle();

	// Get bonus
	int getBonus() const;

	// Get bonus text
	Font& getBonusText();

	//Set bonus
	void setBonus(int bonus);

private:

	int m_bonus;

	BaseObject m_bonusLogo;
	BaseObject m_bonusRectangle;

	Font m_bonusText;

	const char * toString(int);

};

#endif /* BONUS_H_ */
