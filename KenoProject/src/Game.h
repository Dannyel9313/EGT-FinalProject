#ifndef GAME_H_
#define GAME_H_
#include "BaseObject.h"
#include "NumbersGrid.h"
#include "BetButton.h"
#include "History.h"

class Game: public BaseObject
{
	public:
		//Get Number grid
		NumbersGrid& getNumbersGrid();

		//Get bet button
		BetButton& getBetButton();
		
		//Get history grid
		History& getHistory();

		//Render the whole game screen
		void renderGame(SDL_Renderer*,const SDL_Event&);

		//Do something if bet button clicked
		void ifBetButtonClicked(SDL_Renderer*, const SDL_Event&);
	private:
		History mHistory;
		NumbersGrid mGrid;
		BetButton mBetButton;
};

#endif
