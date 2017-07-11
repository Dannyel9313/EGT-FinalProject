/*
 * InsertCredit.h
 *
 *  Created on: 10.07.2017
 *      Author: Danny
 */

#ifndef INSERTCREDIT_H_
#define INSERTCREDIT_H_
#include "Font.h"

class InsertCredit {
public:
	InsertCredit();
	virtual ~InsertCredit();

	// Load credit elements
	void loadCreditElements(SDL_Renderer* renderer);

	// Set font of elements
	void setElementsFont();

	// Set position and dimension of elements
	void setElementsPositionDimension();

	int getCredit() const;
	void setCredit(int credit);

	Font& getFontCredit();
	Font& getFontInsertCredit();
	Font& getFontMinus();
	Font& getFontPlus();
	Font& getFontCreditRect();

private:

	int credit;

	Font m_FontInsertCredit;
	Font m_FontPlus;
	Font m_FontMinus;
	Font m_FontCredit;
	Font m_FontCreditRect;

};

#endif /* INSERTCREDIT_H_ */