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

	m_minBetButton.renderMinBet(renderer);
	m_maxBetButton.renderMaxBet(renderer);
	m_clearButton.renderClearButton(renderer);

	m_quickPickButton.renderQuickPickButton(renderer);

	m_creditInGame.renderCreditsInGame(renderer);
	m_winInGame.renderWinInGame(renderer);

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

			//Reset numbersgrid and button
			render(renderer, NULL);
			mGrid.resetNumbersGrid(renderer);
			mBetButton.buttonCondition(mGrid.numbersClicked(), renderer);

		}
	}
	m_clearButton.isClickedClearButton(renderer,e);
}

MinBet& Game::getMinBetButton(){
	return m_minBetButton;
}

MaxBet& Game::getMaxBetButton() {
	return m_maxBetButton;
}

ClearButton& Game::getClearButton() {
	return m_clearButton;
}

QuickPick& Game::getQuickPickButton(){
	return m_quickPickButton;
}

CreditInGame& Game::getCreditInGame() {
	return m_creditInGame;
}

Win& Game::getWinInGame() {
	return m_winInGame;
}
//BackgroundGame& Game::getBackground() {
//	return m_background;
//}
