#include "Game.h"

NumbersGrid& Game::getNumbersGrid()
{
	return mGrid;
}

BetButton& Game::getBetButton()
{
	return mBetButton;
}

void Game::renderGame(SDL_Renderer* renderer) 
{
	//Render background
	render(renderer, NULL);
	
	//Render numbers	
	mGrid.reRenderClickedNumbers(renderer, 255);

	//Render bet button
	mBetButton.buttonCondition(mGrid.numbersClicked(), renderer);

	//Render min bet button
	m_minBetButton.renderMinBet(renderer);

	//Render max bet button
	m_maxBetButton.renderMaxBet(renderer);

	//Render clear button
	m_clearButton.renderClearButton(renderer);

	//Render quick pick button
	m_quickPickButton.renderQuickPickButton(renderer);

	//Render credit in game
	m_creditInGame.renderCreditsInGame(renderer);

	//Render win in game
	m_winInGame.renderWinInGame(renderer);

	//Render bet text
	mBetButton.betText(renderer);
}

void Game::mouseButtonDownRender(SDL_Renderer* renderer, const SDL_Event& e)
{
	mGrid.doIfClicked(renderer, e);

	//If button condition true show random numbers
	if(mBetButton.buttonCondition(mGrid.numbersClicked(), renderer))
	{		
		if (mBetButton.isClicked(e, mBetButton.getKRect())) 
		{
			render(renderer, NULL);
		
			//Render button
			mBetButton.render(renderer, mBetButton.getKRect());

			//Render bet text
			mBetButton.betText(renderer);

			//Pick 10 random numbers
			mGrid.pickRandomNumbers(renderer, e);
	
			//Render bet button
			mBetButton.buttonCondition(mGrid.numbersClicked(), renderer);

			//Render min bet button
			m_minBetButton.renderMinBet(renderer);

			//Render max bet button
			m_maxBetButton.renderMaxBet(renderer);

			//Render clear button
			m_clearButton.renderClearButton(renderer);

			//Render quick pick button
			m_quickPickButton.renderQuickPickButton(renderer);

			//Render credit in game
			m_creditInGame.renderCreditsInGame(renderer);

			//Render win in game
			m_winInGame.renderWinInGame(renderer);

			//Render bet text
			mBetButton.betText(renderer);

			//Blinking 4 times
			mGrid.blinkingSuccessHits(renderer);

			//Reset numbersgrid and button
			render(renderer, NULL);
			mGrid.resetNumbersGrid(renderer);
			mBetButton.buttonCondition(mGrid.numbersClicked(), renderer);
		}
	}	

	mGrid.reRenderClickedNumbers(renderer, 255);
	renderGame(renderer);
}

void Game::mouseOnButtonRender(SDL_Renderer* renderer, const SDL_Event& e) 
{
	//Mouse over stuff	
	m_clearButton.changeColorOnMouseover(renderer);	
	
/*	////Update screen
	//Render background
	render(renderer, NULL);
			
	//Render button
	mBetButton.render(renderer, mBetButton.getKRect());

	//Render bet text
	mBetButton.betText(renderer);*/
}

MinBet& Game::getMinBetButton()
{
	return m_minBetButton;
}

MaxBet& Game::getMaxBetButton() 
{
	return m_maxBetButton;
}

ClearButton& Game::getClearButton() 
{
	return m_clearButton;
}

QuickPick& Game::getQuickPickButton()
{
	return m_quickPickButton;
}

CreditInGame& Game::getCreditInGame() 
{
	return m_creditInGame;
}

Win& Game::getWinInGame() 
{
	return m_winInGame;
}
//BackgroundGame& Game::getBackground() {
//	return m_background;
//}
