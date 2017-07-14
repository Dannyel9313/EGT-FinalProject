#ifndef INFO_H_
#define INFO_H_
#include "Font.h"

class Info {
public:
	Info();
	virtual ~Info();

	// Load info screen
	void renderInfoScreen(SDL_Renderer* renderer);

	// Get background
	Font& getBackgroundInfo();

	// Get button back
	Font& getButtonBack();

	// Get pushed button back
	Font& getButtonBackPushed();

	// Get Second
//	Font& getSecondBackgroundInfo();

	// Get info text
	Font& getTextInfo();

	// Get text "Information"
	Font& getTextInformation();

	// Get back text
	Font& getButtonBackText();

private:

	Font m_backgroundInfo;
//	Font m_secondBackgroundInfo;
	Font m_buttonBackText;
	Font m_buttonBack;
	Font m_buttonBackPushed;
	Font m_textInformation;
	Font m_textInfo;

	// Set font elements
	void setElementsFont();

	// Set Elements position and dimension
	void setElementsPositionDimension();

	// Set elements color
	void setElementsColor();

	// Load info elements
	void loadInfoElements(SDL_Renderer* renderer);

};

#endif /* INFO_H_ */
