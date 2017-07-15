/*
 * QuickPick.h
 *
 *  Created on: 14.07.2017
 *      Author: Danny
 */

#ifndef QUICKPICK_H_
#define QUICKPICK_H_
#include "Font.h"
#include "BaseObject.h"
#include "Include.h"

class QuickPick {
public:
	QuickPick();
	virtual ~QuickPick();

	// Render
	void renderQuickPickButton(SDL_Renderer* renderer);

	// Set numbers Color
	void setColor();

	// Set elements position and dimension
	void setElementsPositionDimension();

	// Load elements
	void loadElements(SDL_Renderer* renderer);

	// Set font
	void setFont();


	//Get quick pick button rect
	BaseObject& getQuickPickRect();

	//Get quick pick pushed button rect
	BaseObject& getQuickPickRectPushed();

	//Get quick pick button text
	Font& getQuickPickText();

private:

	Font m_quickPickText;

	BaseObject m_quickPickRect;
	BaseObject m_quickPickRectPushed;

};

#endif /* QUICKPICK_H_ */
