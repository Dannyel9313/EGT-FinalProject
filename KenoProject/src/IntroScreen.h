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
	void loadIntroScreen(SDL_Renderer* renderer,double bonus);

	// Present intro screen
	void introScreenPresent(SDL_Renderer* renderer,double bonus);

	//Load intro elements
	void loadIntroElements(SDL_Renderer* renderer,double bonus);

	// Get background
	BaseObject& getBackground();

	// Get info
	Font& getInfoButton();

	// Get resume game
	Font& getResumeGameButton();

	// Get start new game
	Font& getStartNewGameButton();

	// Get volume
	Volume& getVolume();

	void setPositionDimension();

	//Get insert credit
	InsertCredit& getInsertCredit();

	//Start new game button
	void startNewGameClicked(bool*,bool*,bool*, const SDL_Event&);

	//start info screen
	void startInfoClicked(bool*,bool*,bool*, const SDL_Event&);

	//resume game
	void resumeGameClicked(bool*, bool*, bool*, bool*, const SDL_Event&);

	//loads chunk if button is clicked
	void introButtonsChunk(const SDL_Event&);

	// Get chunk
	Mix_Chunk*& getChunk();

private:
	// moving elements
	void moveStarNewGame(int yPos, SDL_Renderer* renderer);

	void moveResumeGame(int yPos, SDL_Renderer* renderer);

	void moveInfoGame(int yPos, SDL_Renderer* renderer);

	// Set elements font
	void setElementsFont();

	// Set elements color
	void setElementsColor(double bonus);

	BaseObject m_background;

	Font m_startNewGameButton;
	Font m_resumeGameButton;
	InsertCredit m_insertCredit;
	Volume m_volume;
	Font m_infoButton;

	Mix_Chunk* m_chunk;


};

#endif /* INTROSCREEN_H_ */
