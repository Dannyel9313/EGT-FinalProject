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
	mGrid.reRenderClickedNumbers(renderer, 255);

	//Render bet text
	mBetButton.betText(renderer);

	//If button condition true show random numbers
	if(mBetButton.buttonCondition(mGrid.numbersClicked(), renderer))
	{		
		if (mBetButton.isClicked(e, mBetButton.getKRect())) 
		{
			//Render background
			render(renderer, NULL);

			//Render button
			mBetButton.render(renderer, mBetButton.getKRect());

			//Render bet text
			mBetButton.betText(renderer);
			mGrid.pickRandomNumbers(renderer, e);
			mGrid.blinkingSuccessHits(renderer);
		}
	}

}

