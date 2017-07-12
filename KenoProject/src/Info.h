/*
 * Info.h
 *
 *  Created on: 12.07.2017
 *      Author: Danny
 */

#ifndef INFO_H_
#define INFO_H_
#include "Font.h"

class Info {
public:
	Info();
	virtual ~Info();

	// Load info screen
	void loadInfoScreen(SDL_Renderer* renderer);

	// Set font elements
	void setElementsFont();

	// Set Elements position and dimension
	void setElementsPositionDimension();

	// Set elements color
	void setElementsColor();


	// Get background
	Font& getBackgroundInfo();

	// Get button back
	Font& getButtonBack();

	// Get pushed button back
	Font& getButtonBackPushed();

	// Get Second
	Font& getSecondBackgroundInfo();

	// Get info text
	Font& getTextInfo();

	// Get text "Information"
	Font& getTextInformation();

private:

	Font m_backgroundInfo;
	Font m_secondBackgroundInfo;
	Font m_buttonBack;
	Font m_buttonBackPushed;
	Font m_textInformation;
	Font m_textInfo;



};

#endif /* INFO_H_ */
