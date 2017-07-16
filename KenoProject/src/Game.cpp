#include "Game.h"

NumbersGrid& Game::getNumbersGrid()
{
	return mGrid;
}

BetButton& Game::getBetButton()
{
	return mBetButton;
}

void Game::renderGame(SDL_Renderer* renderer, int alpha) 
{
	//Render background
	render(renderer, NULL);

	//Render numbers grid background
	mGrid.renderBackground(renderer);
	
	//Create number rects
	mGrid.createRects(renderer, alpha);

	//Print the numbers
	mGrid.printNumbers(renderer);
	
	//Render bet button
	mBetButton.buttonCondition(mGrid.numbersClicked(), renderer);
	
	//Render bet text
	mBetButton.betText(renderer);

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

	//Render cash out button
	m_cashOutButton.renderCashOutButton(renderer);

//	Render history
	m_History.initializeHistory(renderer);
}

void Game::mouseButtonDownRender(SDL_Renderer* renderer, const SDL_Event& e)
{
	if(m_clearButton.getButtonRect().isClicked(e,m_clearButton.getButtonRect().getKRect()))
			{
		mGrid.resetNumbersGrid(renderer);

			}

	if(m_maxBetButton.getMaxBet().isClicked(e,m_maxBetButton.getMaxBet().getKRect()))
	{
	m_maxBetButton.activateMaxButton(renderer);
	m_minBetButton.deactivateMinButton(renderer);
	}
if(m_minBetButton.getMinBet().isClicked(e,m_minBetButton.getMinBet().getKRect()))
{
	m_minBetButton.activateMinButton(renderer);
	m_maxBetButton.deactivateMaxButton(renderer);
}

	//If button condition true show random numbers
	if(mBetButton.buttonCondition(mGrid.numbersClicked(), renderer))
	{		
		if (mBetButton.isClicked(e, mBetButton.getKRect())) 
		{
			//Pick 10 random numbers
			mGrid.pickRandomNumbers(renderer, e);

			renderGame(renderer, 150);

			mGrid.reRenderClickedNumbers(renderer, 50);

			mGrid.renderRandomNumbers(renderer);
	
			mGrid.printNumbers(renderer);

			mGrid.numberOfHits();

			m_History.printHits(renderer, mGrid.numberOfHits(), 0);

			mGrid.blinkingSuccessHits(renderer);

			History::currentRound++;

			renderGame(renderer, 255);

			m_History.printHits(renderer, mGrid.numberOfHits(), 1);

			mGrid.resetNumbersGrid(renderer);

		}
	}	
}

void Game::mouseOnButtonRender(SDL_Renderer* renderer, const SDL_Event& e) 
{
	//Mouse over stuff	
	m_clearButton.changeColorOnMouseOver(renderer);

	m_quickPickButton.changeColorOnMouseOver(renderer);

	m_minBetButton.changeColorOnMouseOver(renderer);

	m_maxBetButton.changeColorOnMouseOver(renderer);

	m_cashOutButton.changeColorOnMouseOver(renderer);
}

void Game::changeColorOfClickedNumbers(SDL_Renderer* renderer, const SDL_Event& e)
{
	mGrid.createRects(renderer, 255);
	mGrid.reRenderClickedNumbers(renderer, 255);
	mGrid.doIfClicked(renderer, e);
	mGrid.printNumbers(renderer);
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

History& Game::getHistory()
{
	return m_History;
}

CashOut& Game::getCashOutButton() {
	return m_cashOutButton;
}
//BackgroundGame& Game::getBackground() {
//	return m_background;
//}

