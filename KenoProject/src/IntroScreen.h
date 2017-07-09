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

class IntroScreen {
public:
//	m_vFont = { "-","V","O","L","U","M","E","+" };

	IntroScreen();
	virtual ~IntroScreen();

	void loadButtonFont(SDL_Renderer* renderer);

	void setButtonsPositionDimension(SDL_Renderer* renderer);



	BaseObject& getBackground();
	void setBackground(const BaseObject& background);
	Font& getInfoButton();
	void setInfoButton(const Font& infoButton);
	Font& getInsertCredit() ;
	void setInsertCredit(const Font& insertCredit);
	Font& getResumeGameButton() ;
	void setResumeGameButton(const Font& resumeGameButton);
	Font& getStartNewGameButton();
	void setStartNewGameButton(const Font& startNewGameButton);

	BaseObject& getVolumeButtonMinus();
	BaseObject& getVolumeButtonPlus();

private:
	BaseObject m_background;

	Font m_startNewGameButton;
	Font m_resumeGameButton;
	Font m_insertCredit;
//	std::vector <Font> m_vFont;
	BaseObject m_volumeButtonPlus;
	BaseObject m_volumeButtonMinus;
	Font m_infoButton;

};

#endif /* INTROSCREEN_H_ */
