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
	//Render background
	render(renderer, NULL);

	//Render numbers grid with clicked numbers
	mGrid.reRenderClickedNumbers(renderer);

	//Do something if clicked
	mGrid.doIfClicked(renderer, e);

	//Render bet text
	mBetButton.betText(renderer);

	//If button condition true show random numbers
	if(mBetButton.buttonCondition(mGrid.numbersClicked(), renderer))
	{
		mGrid.pickRandomNumbers(renderer, e, &mBetButton.getKRect());
	}
}
