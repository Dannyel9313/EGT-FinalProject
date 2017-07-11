/*
 * IntroScreen.h
 *
 *  Created on: 08.07.2017
 *      Author: Danny
 */

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


	bool loadMusic();

	void introScreenPresent(SDL_Renderer* renderer);

	void introScreenButtonsEffects();

	BaseObject& getBackground();
	void setBackground(const BaseObject& background);

	Font& getInfoButton();
	void setInfoButton(const Font& infoButton);

	Font& getResumeGameButton() ;
	void setResumeGameButton(const Font& resumeGameButton);

	Font& getStartNewGameButton();
	void setStartNewGameButton(const Font& startNewGameButton);

	Volume& getVolume();
	void setVolume( Volume& volume);

	void setPositionDimension();

	InsertCredit& getInsertCredit();
	void setInsertCredit(InsertCredit& insertCredit);


	Mix_Chunk*& getChunkClic();
	Mix_Music*& getIntroSong();

private:
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
	Mix_Chunk* m_chunkClic;

};

#endif /* INTROSCREEN_H_ */
