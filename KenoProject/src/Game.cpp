#include "Game.h"

NumbersGrid& Game::getNumbersGrid()
{
	return mGrid;
}

BetButton& Game::getBetButton()
{
	return mBetButton;
}

void Game::renderGame(SDL_Renderer* renderer,const SDL_Event& e) 
{
	render(renderer, NULL);
	mGrid.reRenderClickedNumbers(renderer);
	mGrid.doIfClicked(renderer, e);
	mBetButton.betText(renderer);
	if(mBetButton.buttonCondition(mGrid.numbersClicked(), renderer))
	{
		mGrid.pickRandomNumbers(renderer, e, &mBetButton.getKRect());
	}
}
