/*
 * VolumeButton.h
 *
 *  Created on: Jul 19, 2017
 *      Author: Memmory Of Tomorrow
 */

#ifndef VOLUMEBUTTON_H_
#define VOLUMEBUTTON_H_

#include "Font.h"
#include "BaseObject.h"
#include "Include.h"

class VolumeButton: public BaseObject
{
public:
	VolumeButton();
	virtual ~VolumeButton();

	//Render
	void renderVolumeButton(SDL_Renderer* renderer);

	void isClickedVolumeButton(SDL_Renderer* renderer,const SDL_Event& e);


	//Set elements position and dimension
	void setElementsPositionDimension();

	//Load elements
	void loadElements(SDL_Renderer* renderer);

	//Get button clear
	Font& getVolumeButton();

	//Get button rect
	BaseObject& getButtonRect();

	//Get pushed button rect
	BaseObject& getButtonRectPushed();
private:
	Font m_buttonVolume;

	BaseObject m_buttonRect;
	BaseObject m_buttonRectPushed;

};
#endif /* VOLUMEBUTTON_H_ */
