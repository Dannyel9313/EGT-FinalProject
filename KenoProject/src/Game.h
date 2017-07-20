#ifndef GAME_H_
#define GAME_H_
#include "BaseObject.h"
#include "NumbersGrid.h"
#include "BetButton.h"
#include "MinBet.h"
#include "MaxBet.h"
#include "ClearButton.h"
#include "QuickPick.h"
#include "CreditInGame.h"
#include "Win.h"
#include "History.h"
#include "KenoDrawAnimation.h"
#include "CashOut.h"
#include "PayTable.h"
#include "VolumeButton.h"

class Game: public BaseObject
{
	public:
		Game();
		~Game();

		//Flags
		std::bitset <80> flags;
		std::vector <SDL_Color> colors;

		void renderAfterAnimationGame(SDL_Renderer*, int alpha);

		//Get Number grid
		NumbersGrid& getNumbersGrid();

		//Get bet button
		BetButton& getBetButton();

		PayTable& getPayTable();

		//Render the whole game screen
		void renderGame(SDL_Renderer*, int alpha);


		// Play/pause music
		void playPauseMusic(SDL_Renderer* renderer, const SDL_Event& e, Mix_Music* mainMusic);

		// Change credit
		void changeCreditOnClickingBet(SDL_Renderer* renderer, const SDL_Event& e);

		// show win credit
		void showWinInGame(SDL_Renderer* renderer);

		double calculateCreditsInMoney(int credits);

		//Get min bet button
		MinBet& getMinBetButton();

		//Get max bet button
		MaxBet& getMaxBetButton();

		//Get clear button
		ClearButton& getClearButton();

		//Get quick pick button
		QuickPick& getQuickPickButton();

		//Get volume button
		VolumeButton& getVolumeButton();

		//Get credit in game
		CreditInGame& getCreditInGame();

		//Get win in game
		Win& getWinInGame();

		//Get history
		History& getHistory();		
	
		//Draw animation
		KenoDrawAnimation& getDrawAnimation();

		//Render on mousebuttondown
		void mouseButtonDownRender(SDL_Renderer*, const SDL_Event&);

		//Render on mouseover
		void mouseOnButtonRender(SDL_Renderer*, const SDL_Event&);

		//Changes color of clicked numbers
		void changeColorOfClickedNumbers(SDL_Renderer*, const SDL_Event&);

		void drawAnimation(SDL_Renderer*, int*, SDL_Rect*);		
		void drawAnimationReRender(SDL_Renderer*, SDL_Rect*);

		int calculateWin(int spots, int match, int bet);

		//Get cash out button
		CashOut& getCashOutButton();
 
		// Set and Get method
		int getBet() const;
		void setBet(int bet);

		void cashOutButtonPushed(bool* outroMode, const SDL_Event& e);

		// Loads win if the user won
		void loadWinScreen(int spots, int match, int bet);

		// Loads big win if the user matched 10 out of 10
		void loadBigWinScreen(int spots, int match, int bet);

		//loads chunk if button is clicked
		void gameButtonsChunk();


	private:
		void setMinMaxBet(SDL_Renderer* renderer, const SDL_Event& e);

		bool m_setBetFlag;
	 	bool m_minBetFlag;
 		bool m_maxBetFlag;
 		int m_bet;
		NumbersGrid mGrid;
		BetButton mBetButton;
		MinBet m_minBetButton;
		MaxBet m_maxBetButton;
		ClearButton m_clearButton;
		QuickPick m_quickPickButton;
		CreditInGame m_creditInGame;
		Win m_winInGame;
		History m_History;
		KenoDrawAnimation m_DrawAnimation;		
		CashOut m_cashOutButton;
		PayTable m_PayTable;
		VolumeButton m_volumeButton;

		Mix_Chunk* m_chunk;
};

#endif
