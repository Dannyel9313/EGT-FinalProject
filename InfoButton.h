/*
 * InfoButton.h
 *
 *  Created on: Jul 21, 2017
 *      Author: Memmory Of Tomorrow
 */

#ifndef INFOBUTTON_H_
#define INFOBUTTON_H_

#include "Font.h"
#include "BaseObject.h"
#include "Include.h"

class InfoButton: public BaseObject
{
public:
	InfoButton();
	virtual ~InfoButton();

	//Render
	void renderInfoButton(SDL_Renderer* renderer);

	void isClickedInfoButton(SDL_Renderer* renderer,const SDL_Event& e);


	//Set elements position and dimension
	void setElementsPositionDimension();

	//Load elements
	void loadElements(SDL_Renderer* renderer);

	//Get button clear
	Font& getInfoButton();

	//Get button rect
	BaseObject& getButtonRect();

	//Get pushed button rect
	BaseObject& getButtonRectPushed();
private:
	Font m_buttonInfo;

	BaseObject m_buttonRect;
	BaseObject m_buttonRectPushed;

};

#endif /* INFOBUTTON_H_ */
