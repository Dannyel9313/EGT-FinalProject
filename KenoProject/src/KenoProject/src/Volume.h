/*
 * Volume.h
 *
 *  Created on: 10.07.2017
 *      Author: Danny
 */

#ifndef VOLUME_H_
#define VOLUME_H_
#include "Include.h"
#include "Font.h"

class Volume {
public:
	Volume();
	virtual ~Volume();

	// Load volume elements
	void LoadVolumeElements(SDL_Renderer* renderer);

	// Set position and dimension of elements
	void setElementsPositionDimension();

	// Set font
	void setElementsFont();

	// Get elements
	Font& getFontDot();
	Font& getFontDotLine();
	Font& getFontMinus();
	Font& getFontPlus();
	Font& getFontVolume();

private:

	Font m_FontPlus;
	Font m_FontMinus;
	Font m_FontVolume;
	Font m_FontDot;
	Font m_FontDotLine;

};

#endif /* VOLUME_H_ */
