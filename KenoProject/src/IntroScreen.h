#ifndef INTROSCREEN_H_
#define INTROSCREEN_H_

#include "BaseObject.h"
#include "Font.h"
#include "Volume.h"
#include "InsertCredit.h"

class IntroScreen {
public:

	IntroScreen();
	virtual ~IntroScreen();

	//Load intro screen
	void loadIntroScreen(SDL_Renderer* renderer);

	// Present intro screen
	void introScreenPresent(SDL_Renderer* renderer);

	//Load intro elements
	void loadIntroElements(SDL_Renderer* renderer);

	BaseObject& getBackground();
	void setBackground(const BaseObject& background);

	Font& getInfoButton();
	void setInfoButton(const Font& infoButton);

	Font& getResumeGameButton();
	void setResumeGameButton(const Font& resumeGameButton);

	Font& getStartNewGameButton();
	void setStartNewGameButton(const Font& startNewGameButton);



	Volume& getVolume();
	void setVolume(Volume& volume);

	void setPositionDimension();

	InsertCredit& getInsertCredit();
	void setInsertCredit(InsertCredit& insertCredit);

	Mix_Music*& getIntroSong();

	//Start new game button
	void startNewGameClicked(bool*, const SDL_Event&);

	//start info screen
	void startInfoClicked(bool*, const SDL_Event&);
private:
	// moving elements
	void moveStarNewGame(int yPos, SDL_Renderer* renderer);

	void moveResumeGame(int yPos, SDL_Renderer* renderer);

	void moveInfoGame(int yPos, SDL_Renderer* renderer);

	// Set elements font
	void setElementsFont();

	// Set elements color
	void setElementsColor();

	BaseObject m_background;

	Font m_startNewGameButton;
	Font m_resumeGameButton;
	InsertCredit m_insertCredit;
	Volume m_volume;
	Font m_infoButton;

	Mix_Music* m_introSong;

};

#endif /* INTROSCREEN_H_ */
