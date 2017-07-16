#ifndef GAME_H_
#define GAME_H_
#include "BaseObject.h"
#include "NumbersGrid.h"
#include "BetButton.h"
#include "BackgroundGame.h"
#include "MinBet.h"
#include "MaxBet.h"
#include "ClearButton.h"
#include "QuickPick.h"
#include "CreditInGame.h"
#include "Win.h"
#include "History.h"
#include "CashOut.h"

class Game: public BaseObject
{
	public:
		//Get Number grid
		NumbersGrid & getNumbersGrid();

		//Get bet button
		BetButton & getBetButton();

		//Render the whole game screen
		void renderGame(SDL_Renderer*, int alpha);

		//
		void ifBetButtonClicked(SDL_Renderer*, const SDL_Event&);

		//Get min bet button
		MinBet& getMinBetButton();

		//Get max bet button
		MaxBet& getMaxBetButton();

		//Get clear button
		ClearButton& getClearButton();

		//Get quick pick button
		QuickPick& getQuickPickButton();

		//Get credit in game
		CreditInGame& getCreditInGame();

		//Get win in game
		Win& getWinInGame();

		//Get history
		History& getHistory();

		//Render on mousebuttondown
		void mouseButtonDownRender(SDL_Renderer*, const SDL_Event&);

		//Render on mouseover
		void mouseOnButtonRender(SDL_Renderer*, const SDL_Event&);

		//Changes color of clicked numbers
		void changeColorOfClickedNumbers(SDL_Renderer*, const SDL_Event&);

		//Get cash out button
		CashOut& getCashOutButton();

		//BackgroundGame& getBackground();

	private:
		NumbersGrid mGrid;
		BetButton mBetButton;
		MinBet m_minBetButton;
		MaxBet m_maxBetButton;
		ClearButton m_clearButton;
		QuickPick m_quickPickButton;
		CreditInGame m_creditInGame;
		Win m_winInGame;
		CashOut m_cashOutButton;
		History m_History;

		//BackgroundGame m_BackgroundGame;
};

#endif
