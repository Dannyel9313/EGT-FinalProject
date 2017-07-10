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

	// Handle event
//	void handleEvent( SDL_Event& e, int x,int y );


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

	InsertCredit& getInsertCredit();
	void setInsertCredit(InsertCredit& insertCredit);

private:
	BaseObject m_background;

	Font m_startNewGameButton;
	Font m_resumeGameButton;
	InsertCredit m_insertCredit;
	Volume m_volume;
	Font m_infoButton;

};

#endif /* INTROSCREEN_H_ */
