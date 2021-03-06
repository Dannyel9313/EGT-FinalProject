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
#include "Bonus.h"
#include "InfoButton.h"
#include "XML.h"

class Game: public BaseObject
{
	public:
		Game();

		~Game();

		//Call functions that only need to be called once
		void initializeGameState();

		//Flags
		std::bitset <80> flags;
		std::vector <SDL_Color> colors;

		//Render game after main animation
		void renderAfterAnimationGame(SDL_Renderer*, int alpha);

		//Get Number grid
		NumbersGrid& getNumbersGrid();

		//Get bet button
		BetButton& getBetButton();

		//Get pay table
		PayTable& getPayTable();

		//Add bonus to credits
		void bonusToCredits(int match, SDL_Renderer* renderer);

		//Render the whole game screen
		void renderGame(SDL_Renderer*, int alpha);

		// Calculate bonus to show in game
		int calculateBonus(int bet);

		// Play/pause music
		void playPauseMusic(SDL_Renderer* renderer, const SDL_Event& e, Mix_Music* mainMusic);

		// Change credit
		void changeCreditOnClickingBet(SDL_Renderer* renderer, const SDL_Event& e);

		int calculateWinInGame();

		// show win credit
		void showWinInGame(SDL_Renderer* renderer);

		// Calculate money from credits and denomination
		double calculateCreditsInMoney();

		// Loads game over if the user has 0 credits
		void loadGameOverScreen(SDL_Renderer* renderer, int spots, int match, int bet);

		// Loads big win if the user matched 10 out of 10
		void loadBigWinScreen(SDL_Renderer* renderer, int spots, int match, int bet);

		// Show Bonus logo when you get bonus
		void showBonusLogo(SDL_Renderer* renderer);

		bool cashOutButtonPushed(const SDL_Event& e);

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

		void drawAnimation(SDL_Renderer*, const std::vector <bool>&, SDL_Rect*);		
		void drawAnimationReRender(SDL_Renderer*, SDL_Rect*);

		//Calculate win credits
		int calculateWin(int spots, int match, int bet);

		//Get cash out button
		CashOut& getCashOutButton();
 
		//Get bet
		int getBet() const;

		//Set bet
		void setBet(int bet);

		//Loads game over if the user has no credits
		void loadGameOverScreen(SDL_Renderer*);

		//Get bonus
		Bonus& getBonusInGame();

		//Get bonus
		double getBonus() const;

		//Set bonus
		void setBonus(double bonus);
		
		void payTableAnimation(SDL_Renderer*);

		//Rerender bet button
		void reRenderBetButton(SDL_Renderer*);
		
		//Rerender history table
		void reRenderHistory(SDL_Renderer*);

		//loads chunk
		void gameButtonsChunk();

		//Get info button
		InfoButton& getInfoButton();

		//Get xml
		XML& getXML();

		//Reset variables
		void resetVariables();

		// Game Over Flag
		bool isGameOverFlag() const;

		// Set game over flag
		void setGameOverFlag(bool gameOverFlag);

		//Rerender minimal bet
		void reRenderMinimalBet(SDL_Renderer* renderer, int bet);

		//Rerender maximal bet
		void reRenderMaximalBet(SDL_Renderer* renderer, int bet);

		//Get min-max bet flag
		bool getMinBetFlag();
		bool getMaxBetFlag();
		
		//Set min-max bet flag
		void setMinBetFlag(bool);
		void setMaxBetFlag(bool);

		//Get set bet flag
		bool getSetBetFlag();
		
		//Set set bet flag
		void setSetBetFlag(bool);

	private:
		void setMinMaxBet(SDL_Renderer* renderer, const SDL_Event& e);


		int m_counterInfoClick;
		bool m_bigWinFlag;
		bool m_gameOverFlag;
		bool m_infoGameMode;
		bool m_bonusFlag;
		bool m_setBetFlag;
	 	bool m_minBetFlag;
 		bool m_maxBetFlag;
 		int m_bet;
 		double m_bonus;
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
		Bonus m_bonusInGame;
		InfoButton m_infoButton;
		Mix_Chunk* m_chunk;
		XML m_Recovery;

		// render minimal bet one
		void reRenderMinimalBetNumOne(SDL_Renderer* renderer, int bet);

		// render minimal bet two
		void reRenderMinimalBetNumTwo(SDL_Renderer* renderer, int bet);

		// render minimal bet three
		void reRenderMinimalBetNumThree(SDL_Renderer* renderer, int bet);

		// render minimal bet four
		void reRenderMinimalBetNumFour(SDL_Renderer* renderer, int bet);

		// render minimal bet five
		void reRenderMinimalBetNumFive(SDL_Renderer* renderer, int bet);

		// render minimal bet ten
		void reRenderMinimalBetNumTen(SDL_Renderer* renderer, int bet);

		// render maximal bet five
		void reRenderMaximalBetNumFive(SDL_Renderer* renderer, int bet);

		// render maximal bet ten
		void reRenderMaximalBetNumTen(SDL_Renderer* renderer, int bet);

		// render maximal bet twenty
		void reRenderMaximalBetNumTwenty(SDL_Renderer* renderer, int bet);

		// render maximal bet thirty
		void reRenderMaximalBetNumThirty(SDL_Renderer* renderer, int bet);

		// render maximal bet fourty
		void reRenderMaximalBetNumFourty(SDL_Renderer* renderer, int bet);

		// render maximal bet fifty
		void reRenderMaximalBetNumFifty(SDL_Renderer* renderer, int bet);


};

#endif	
