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

	void loadInfoScreen(SDL_Renderer* renderer);

	void setElementsFont();

	void setElementsPositionDimension();

	void setElementsColor();

	Font& getBackgroundInfo();
	Font& getButtonBack();
	Font& getButtonBackPushed();
	Font& getSecondBackgroundInfo();
	Font& getTextInfo();

private:

	Font m_backgroundInfo;
	Font m_secondBackgroundInfo;
	Font m_buttonBack;
	Font m_buttonBackPushed;
	Font m_textInfo;



};

#endif /* INFO_H_ */
