#ifndef GAME_H_
#define GAME_H_
#include "BaseObject.h"
#include "NumbersGrid.h"
#include "BetButton.h"

class Game: public BaseObject
{
	public:
		//Get Number grid
		NumbersGrid & getNumbersGrid();
		BetButton & getBetButton();

		void renderGame(SDL_Renderer*,const SDL_Event&);
	private:
		NumbersGrid mGrid;
		BetButton mBetButton;
};

#endif
