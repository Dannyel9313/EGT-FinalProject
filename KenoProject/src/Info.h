#ifndef INFO_H_
#define INFO_H_
#include "Font.h"

class Info {
public:
	Info();
	virtual ~Info();

	// Load info screen
	void renderInfoScreen(SDL_Renderer* renderer);

	//
	void renderButtonDown(SDL_Renderer* renderer, const SDL_Event& e);

	// change button on mause over
	void renderOnMauseOver(SDL_Renderer* renderer, const SDL_Event& e);

	void buttonReturn(bool* introMode,bool* infoMode, const SDL_Event& e);

	// Get background
	Font& getBackgroundInfo();

	// Get button back
	Font& getButtonBack();

	// Get back text
	Font& getButtonBackText();

	// Get button next
	Font& getButtonNext();

	// Get button return
	Font& getButtonReturn();

	// Get button next text
	Font& getButtonNextText();

	// Get button next text
	Font& getButtonReturnText();

	// Get info page
	int getInfoPage() const;

	// Set info page
	void setInfoPage(int infoPage);

private:

	int m_infoPage;

	Font m_backgroundInfo;

	Font m_buttonBackText;
	Font m_buttonBack;
	Font m_buttonNextText;
	Font m_buttonNext;
	Font m_buttonReturn;
	Font m_buttonReturnText;



	// Set font elements
	void setElementsFont();

	// Set Elements position and dimension
	void setElementsPositionDimension();

	// Set elements color
	void setElementsColor();

	// Load info elements
	void loadInfoElements(SDL_Renderer* renderer);

	// change button return on mause over
		void renderButtonReturnOnMouseOver(SDL_Renderer* renderer, const SDL_Event& e);

		// change button back on mause over
		void renderButtonBackOnMauseOver(SDL_Renderer* renderer, const SDL_Event& e);

		// change button next on mause over
		void renderButtonNextOnMauseOver(SDL_Renderer* renderer, const SDL_Event& e);

};

#endif /* INFO_H_ */
