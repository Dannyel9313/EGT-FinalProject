#include "Game.h"

Game::Game() :
		m_minBetFlag(true), m_maxBetFlag(true), m_setBetFlag(false), m_bet(0) {
}

NumbersGrid& Game::getNumbersGrid() {
	return mGrid;
}

BetButton& Game::getBetButton() {
	return mBetButton;
}

KenoDrawAnimation& Game::getDrawAnimation() {
	return m_DrawAnimation;
}

PayTable& Game::getPayTable() {
	return m_PayTable;
}

void Game::renderGame(SDL_Renderer* renderer, int alpha) {
	//Render background

	render(renderer, NULL);

	//Render numbers grid background
	mGrid.renderBackground(renderer);

	//Create number rects
	mGrid.createRects(renderer, alpha);

	//Print the numbers
	mGrid.printNumbers(renderer);

	//Render bet button
	mBetButton.buttonCondition(mGrid.numbersClicked());
	mBetButton.renderButton(renderer);

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

	//Render volume button
	m_volumeButton.renderVolumeButton(renderer);

	//Render history
	m_History.renderHistory(renderer);
	m_PayTable.renderPayTable(renderer);
	m_PayTable.renderHitsText(renderer);

	m_DrawAnimation.loadTextures(renderer);
	m_DrawAnimation.drawPipe(renderer);
}

void Game::mouseButtonDownRender(SDL_Renderer* renderer, const SDL_Event& e) {
	if (m_creditInGame.getGameCredit() >= m_bet && m_bet != 0)
	{
		//If button condition true show random numbers
		if (mBetButton.buttonCondition(mGrid.numbersClicked())) 
		{
			mBetButton.renderButton(renderer);
			mBetButton.betText(renderer);
			if (mBetButton.isClicked(e, mBetButton.getKRect())) 
			{
				//Pick 10 random numbers
				changeCreditOnClickingBet(renderer, e);

				mGrid.pickRandomNumbers(renderer, e);

				drawAnimation(renderer, mGrid.getRandomNumbers(),
						mGrid.getNumberRects());

				// Render game after animation
				renderAfterAnimationGame(renderer,150);


				mGrid.reRenderClickedNumbers(renderer, 50);

				mGrid.numberOfHits();

				showWinInGame(renderer);

				m_History.renderHits(renderer, mGrid.numberOfHits(), 0);

				mGrid.renderRandomNumbers(renderer);

				mGrid.printNumbers(renderer);

				mGrid.blinkingSuccessHits(renderer);

				History::currentRound++;

				m_History.renderHits(renderer, mGrid.numberOfHits(), 1);

				mGrid.resetIsClicked();

//				renderGame(renderer, 255);

				mGrid.resetNumbersGrid(renderer);
			}
		}
	}

	if (m_quickPickButton.getQuickPickText().isClicked(e,
			m_quickPickButton.getQuickPickText().getKRect()))
	{

		mGrid.resetNumbersGrid(renderer);
		mGrid.resetIsClicked();
		SDL_Rect payTableRect = { 585, 0, 235, 225 };
		cropFromRenderTo(renderer, &payTableRect, &payTableRect);
		m_PayTable.renderPayTable(renderer);
		m_PayTable.renderHitsText(renderer);
		m_PayTable.renderPayText(renderer);
		mGrid.pickRandomChoices(renderer);

		m_PayTable.renderHits(renderer,mGrid.numbersClicked());
		m_PayTable.renderPay(renderer,mGrid.numbersClicked());
		if(mBetButton.buttonCondition(mGrid.numbersClicked()))
		{
			mBetButton.renderButton(renderer);
			mBetButton.betText(renderer);
		}
	}

	setMinMaxBet(renderer, e);


	if (m_clearButton.getButtonRect().isClicked(e,
			m_clearButton.getButtonRect().getKRect())) 
	{
		SDL_Rect payTableRect = { 585, 0, 235, 225 };
		cropFromRenderTo(renderer, &payTableRect, &payTableRect);
		m_PayTable.renderPayTable(renderer);
		m_PayTable.renderHitsText(renderer);
		m_PayTable.renderPayText(renderer);
		mGrid.resetNumbersGrid(renderer);
		m_minBetButton.renderMinBet(renderer);
		m_maxBetButton.renderMaxBet(renderer);
		setBet(0);
		m_minBetFlag = true;
		m_maxBetFlag = true;
		m_setBetFlag = false;
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

void Game::changeColorOfClickedNumbers(SDL_Renderer* renderer,
		const SDL_Event& e) {
	mGrid.createRects(renderer, 255);
	mGrid.reRenderClickedNumbers(renderer, 255);
	if (mGrid.doIfClicked(renderer, e)) {
		SDL_Rect payTableRect = { 585, 0, 235, 225 };
		cropFromRenderTo(renderer, &payTableRect, &payTableRect);
		m_PayTable.renderPayTable(renderer);
		m_PayTable.renderHitsText(renderer);
		m_PayTable.renderPayText(renderer);
		m_PayTable.renderHits(renderer, mGrid.numbersClicked());
		m_PayTable.renderPay(renderer, mGrid.numbersClicked());
	}
	mGrid.printNumbers(renderer);

}

void Game::drawAnimationReRender(SDL_Renderer* renderer, SDL_Rect* rects) {
	int number = 0;
	for (int i = 0; i < 80; i++) {
		if (flags[i] == 1) {
			filledCircleRGBA(renderer, rects[i].x + 23, rects[i].y + 21, 20,
					colors[number].r, colors[number].g, colors[number].b, 255);
			mGrid.printSpecificNumber(renderer, i + 1);
			number++;
		}
	}
}

void Game::drawAnimation(SDL_Renderer* renderer, int* numbers,
		SDL_Rect* rects) {
	SDL_Rect test = { 500, 95, 80, 350 };
	colors.clear();
	for (int i = 0; i < 80; i++) {
		if (numbers[i] == 1) {
//			getDrawAnimation().playSoundEffect(0, 80);
			int r = rand();
			int g = rand();
			int b = rand();
			SDL_Color color = { r, g, b };
			colors.push_back(color);
			for (int k = 115; k <= rects[i].y + 20; k += 5) {
				//Render top left
				cropFromRenderTo(renderer, &test, &test);

				//Render numbers grid background
				mGrid.renderBackground(renderer);

				//Create number rects
				mGrid.createRects(renderer, 255);

				mGrid.reRenderClickedNumbers(renderer, 255);

				m_DrawAnimation.drawPipe(renderer);

				//Print the numbers
				mGrid.printNumbers(renderer);
				m_DrawAnimation.dropBalls(renderer, 540, k, r, g, b);

				drawAnimationReRender(renderer, rects);
				SDL_RenderPresent(renderer);
			}
			for (int j = 540; j >= rects[i].x + 23; j -= 5) {
				//Render top left
				cropFromRenderTo(renderer, &test, &test);

				//Render numbers grid background
				mGrid.renderBackground(renderer);

				//Create number rects
				mGrid.createRects(renderer, 255);

				mGrid.reRenderClickedNumbers(renderer, 255);

				m_DrawAnimation.drawPipe(renderer);

				//Print the numbers
				mGrid.printNumbers(renderer);
				m_DrawAnimation.dropBalls(renderer, j, rects[i].y + 20, r, g,
						b);

				drawAnimationReRender(renderer, rects);
				SDL_RenderPresent(renderer);
			}
//			getDrawAnimation().playSoundEffect(1, 128);
			int timeout = SDL_GetTicks() + 100;
			while (!(SDL_TICKS_PASSED(SDL_GetTicks(), timeout)))
				;
			flags.set(i, 1);
		}

	}

	drawAnimationReRender(renderer, rects);
	SDL_RenderPresent(renderer);
	flags.reset();
	delete[] numbers;
	delete[] rects;

}

MinBet& Game::getMinBetButton() {
	return m_minBetButton;
}

MaxBet& Game::getMaxBetButton() {
	return m_maxBetButton;
}

ClearButton& Game::getClearButton() {
	return m_clearButton;
}

QuickPick& Game::getQuickPickButton() {
	return m_quickPickButton;
}

CreditInGame& Game::getCreditInGame() {
	return m_creditInGame;
}

Win& Game::getWinInGame() {
	return m_winInGame;
}

History& Game::getHistory() {
	return m_History;
}

int Game::getBet() const {
	return m_bet;
}

void Game::setBet(int bet) {
	this->m_bet = bet;
}

void Game::changeCreditOnClickingBet(SDL_Renderer* renderer,
		const SDL_Event& e) {

	int temp = 0;
	int changedCredit = 0;

	temp = m_creditInGame.getGameCredit();

	changedCredit = temp - m_bet;
	m_creditInGame.setGameCredit(changedCredit);
	m_creditInGame.renderCreditsInGame(renderer);

}

void Game::showWinInGame(SDL_Renderer* renderer) {
	int winResult = 0;

	m_winInGame.setWinCredits(
			calculateWin(mGrid.numbersClicked(), mGrid.numberOfHits(), m_bet));
	m_winInGame.renderWinInGame(renderer);

	winResult = m_winInGame.getWinCredits() + m_creditInGame.getGameCredit();

	m_creditInGame.setGameCredit(winResult);
	m_creditInGame.renderCreditsInGame(renderer);

}

void Game::renderAfterAnimationGame(SDL_Renderer* renderer, int alpha) {

	//Render numbers grid background
	mGrid.renderBackground(renderer);

	//Create number rects
	mGrid.createRects(renderer, alpha);

	//Print the numbers
	mGrid.printNumbers(renderer);

	//Render bet button
	mBetButton.buttonCondition(mGrid.numbersClicked());
	mBetButton.renderButton(renderer);

	//Render bet text
	mBetButton.betText(renderer);


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

	//Render history
	m_History.renderHistory(renderer);


//	m_PayTable.renderPayTable(renderer);
//	m_PayTable.renderHitsText(renderer);

	m_DrawAnimation.loadTextures(renderer);
	m_DrawAnimation.drawPipe(renderer);
}

double Game::calculateCreditsInMoney(int credits) {

	double denomination = 0.25;
	double money = 0;

	money = denomination * credits;

	return money;
}

void Game::cashOutButtonPushed(bool* outroMode, const SDL_Event& e)
{
	if(m_cashOutButton.getCashOutRect().isClicked(e, m_cashOutButton.getCashOutRect().getKRect()))
	{
		*outroMode = true;
	}
}

// Play/pause music
void Game::playPauseMusic(SDL_Renderer* renderer, const SDL_Event& e,
		Mix_Music* mainMusic)

{
	if(m_volumeButton.getButtonRect().isClicked(e,
		 			m_volumeButton.getButtonRect().getKRect()))
		 	{
			if(Mix_PlayingMusic() == 0)
			 	{
			 		Mix_PlayMusic(mainMusic, -1);
			 	}
			 	else
			 	{
			 		if( Mix_PausedMusic() == 1 )
			 		{
			 			Mix_ResumeMusic();
			 		}
			 		else
			 		{
			 		Mix_PauseMusic();
			 		}
			 	}
		 	}

}

void Game::setMinMaxBet(SDL_Renderer* renderer, const SDL_Event& e) {

	std::cout << "min flag ->" << m_minBetFlag << std::endl;
	std::cout << "max flag ->" << m_maxBetFlag << std::endl;
	if (m_maxBetButton.getMaxBet().isClicked(e,
			m_maxBetButton.getMaxBet().getKRect())
			|| m_minBetButton.getMinBet().isClicked(e,
					m_minBetButton.getMinBet().getKRect()))
	{
	m_setBetFlag = true;
	}


	if (m_maxBetButton.getMaxBet().isClicked(e,
				m_maxBetButton.getMaxBet().getKRect()))
	{
			setBet(0);
			std::cout << "MaxBet-> " << m_bet << std::endl;
			m_maxBetButton.activateMaxButton(renderer);
			m_minBetButton.deactivateMinButton(renderer);
			m_maxBetFlag = true;
			m_minBetFlag = false;
		}

		if (m_minBetButton.getMinBet().isClicked(e,
				m_minBetButton.getMinBet().getKRect()) )
		{
			setBet(0);
			std::cout << "MINIMALBet-> " << m_bet << std::endl;
			m_minBetButton.activateMinButton(renderer);
			m_maxBetButton.deactivateMaxButton(renderer);
			m_minBetFlag = true;
			m_maxBetFlag = false;
		}

	if (m_minBetFlag == false && m_setBetFlag == true)
	{
		m_minBetButton.renderMinBet(renderer);
		m_minBetButton.deactivateMinButton(renderer);
	}

	if (m_maxBetFlag == false && m_setBetFlag == true) {
		m_maxBetButton.renderMaxBet(renderer);
		m_maxBetButton.deactivateMaxButton(renderer);
	}

	if (m_minBetFlag == true && m_setBetFlag == true) {
		m_minBetButton.betChoiceMin(renderer, e);
		setBet(m_minBetButton.getMinimalBet());
	}

	if (m_maxBetFlag == true && m_setBetFlag == true) {
		m_maxBetButton.betChoiceMax(renderer, e);
		setBet(m_maxBetButton.getMaximalBet());
	}

}

CashOut& Game::getCashOutButton() {
	return m_cashOutButton;
}
int Game::calculateWin(int spots, int match, int bet) {
	int result = 0;
	if (match > 0) {
		int arrayQueficient[9][10] ;

		result = arrayQueficient[spots - 2][match - 1] * bet;
	}
	return result;
}

// to fix function

//void Game::loadWinScreen(int spots, int match, int bet) {
//	SDL_Renderer* renderer;
//	if (calculateWin(spots, match, bet) > 0) {
//		m_winInGame.writeOnScreen(renderer);
//	}
//}

VolumeButton& Game::getVolumeButton() {
 	return m_volumeButton;
 }




