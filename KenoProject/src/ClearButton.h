/*
 * ClearButton.h
 *
 *  Created on: 14.07.2017
 *      Author: Danny
 */

#ifndef CLEARBUTTON_H_
#define CLEARBUTTON_H_
#include "Font.h"
#include "Include.h"
#include "BaseObject.h"

class ClearButton {
public:
	ClearButton();
	virtual ~ClearButton();

	// Render
	void renderClearButton(SDL_Renderer* renderer);

    bool isClickedClearButton(SDL_Renderer* renderer,const SDL_Event& e);

	// Get button clear
	Font& getButtonClear();

	// Get button rect
	BaseObject& getButtonRect();

	// Get pushed button rect
	BaseObject& getButtonRectPushed();

private:

	Font m_buttonClear;

	BaseObject m_buttonRect;
	BaseObject m_buttonRectPushed;

	// Set numbers Color
	void setColor(SDL_Renderer* renderer);

	// Set elements position and dimension
	void setElementsPositionDimension();

	// Load elements
	void loadElements(SDL_Renderer* renderer);

	// Set font
	void setFont();




};

#endif /* CLEARBUTTON_H_ */
