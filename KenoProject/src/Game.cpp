#include "Game.h"

Game::Game()
{
	this->m_minBetFlag = true;
	this->m_maxBetFlag = true;
	this->m_setBetFlag = false;
	this->m_bonusFlag = false;
	this->m_counterInfoClick = 0;
	this->m_infoGameMode = false;
	this->m_bigWinFlag = false;
	this->m_gameOverFlag = false;
	this->m_bet = 0;
	this->m_bonus = 0;
	m_chunk = NULL;
}

Game::~Game()
{
	if (m_chunk != NULL)
	{
		Mix_FreeChunk(m_chunk);
		m_chunk = NULL;
	}

}

NumbersGrid& Game::getNumbersGrid()
{
	return mGrid;
}

BetButton& Game::getBetButton()
{
	return mBetButton;
}

KenoDrawAnimation& Game::getDrawAnimation()
{
	return m_DrawAnimation;
}

PayTable& Game::getPayTable()
{
	return m_PayTable;
}

void Game::initializeGameState()
{
	//Sets pay table lines
	m_PayTable.setLines();

	//Sets pay table hit rects
	m_PayTable.setHitsRects();

	//Set pay table pay rects
	m_PayTable.setPayRects();

}

void Game::renderGame(SDL_Renderer* renderer, int alpha)
{

	//Render background
	render(renderer, NULL);

	//Render numbers grid background
	mGrid.renderBackground(renderer);

	//Create number rects
	mGrid.createRects(renderer, alpha);

	mGrid.reRenderClickedNumbers(renderer, alpha);

	//Print the numbers
	mGrid.printNumbers(renderer);

	//Render bet button
	mBetButton.buttonCondition(mGrid.numbersClicked(), getBet());
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

	//Render pay table
	m_PayTable.renderPayTable(renderer, mGrid.numbersClicked(), m_bet);

	m_DrawAnimation.loadTextures(renderer);
	m_DrawAnimation.drawPipe(renderer);

	m_bonusInGame.renderBonus(renderer);

	m_infoButton.renderInfoButton(renderer);

	reRenderMinimalBet(renderer, m_bet);
	reRenderMaximalBet(renderer, m_bet);

	m_Recovery.write(getBet(), m_creditInGame.getGameCredit(),
			getBonus(),
			mGrid.getClickedNumbers(),
			m_minBetFlag, m_maxBetFlag, m_setBetFlag);

}

void Game::mouseButtonDownRender(SDL_Renderer* renderer, const SDL_Event& e)
{
	if (m_infoGameMode == false)
	{
		if(getBet() > 0)
		{
			//If button condition true show random numbers
			if (mBetButton.buttonCondition(mGrid.numbersClicked(), getBet())) 
			{
				mBetButton.renderButton(renderer);
				mBetButton.betText(renderer);
				if (mBetButton.isClicked(e, mBetButton.getKRect())) 
				{

					gameButtonsChunk();

					m_bonusInGame.showBonus(renderer,calculateBonus(getBet()));
					//Pick 10 random numbers
					changeCreditOnClickingBet(renderer, e);

					mGrid.pickRandomNumbers(renderer);

					//Calculates win and saves is
					calculateWinInGame();
					m_Recovery.write(getBet(), m_creditInGame.getGameCredit(),
							getBonus(),
							mGrid.getClickedNumbers(),
							m_minBetFlag, m_maxBetFlag, m_setBetFlag);


					drawAnimation(renderer, mGrid.getRandomNumbers(),
							mGrid.getNumberRects());

					//Render game after animation
					renderAfterAnimationGame(renderer,150);


					mGrid.reRenderClickedNumbers(renderer, 50);

					mGrid.numberOfHits();

					showWinInGame(renderer);
					bonusToCredits(mGrid.numberOfHits(), renderer);

					if(mGrid.numberOfHits() == 10)
					{
						m_bigWinFlag = true;
					}

					m_History.renderHits(renderer, mGrid.numberOfHits(), 0);

					mGrid.renderRandomNumbers(renderer);

					mGrid.printNumbers(renderer);

					mGrid.blinkingSuccessHits(renderer);

					payTableAnimation(renderer);

					if(m_bonusFlag == true)
					{
						Mix_PauseMusic();
						showBonusLogo(renderer);
						Mix_ResumeMusic();
					}

					History::currentRound++;

					if (History::currentRound == 10)
					{
						SDL_Rect tempRect = {HISTORY_BOTTOM_LEFT.x,
							HISTORY_TOP_RIGHT.y, HISTORY_WIDTH, HISTORY_HEIGHT};

						cropFromRenderTo(renderer, &tempRect, &tempRect);
						m_History.renderHistory(renderer);
					}


					m_History.renderHits(renderer, mGrid.numberOfHits(), 1);

					mGrid.resetIsClicked();

					mGrid.resetNumbersGrid(renderer);

					if(m_bonusFlag == true)
					{
						m_creditInGame.renderCreditsInGame(renderer);
						m_bonusInGame.renderBonus(renderer);
						m_bonusFlag = false;
					}
					if(m_creditInGame.getGameCredit() == 0)
					{
						m_gameOverFlag = true;
					}
					//Save data
					m_Recovery.write(getBet(), m_creditInGame.getGameCredit(),
							getBonus(),
							mGrid.getClickedNumbers(),
							m_minBetFlag, m_maxBetFlag, m_setBetFlag);

					if(m_bigWinFlag == true)
					{
						Mix_PauseMusic();
						m_winInGame.bigWin(renderer,m_winInGame.getWinCredits());
						renderGame(renderer,255);
						Mix_ResumeMusic();
						reRenderMinimalBet(renderer,m_bet);
						reRenderMaximalBet(renderer,m_bet);
						m_bigWinFlag = false;
					}

				}
			}
		}
	}

	if (m_quickPickButton.getQuickPickText().isClicked(e,
				m_quickPickButton.getQuickPickText().getKRect()))
	{
		gameButtonsChunk();
		mGrid.resetNumbersGrid(renderer);
		mGrid.resetIsClicked();
		SDL_Rect payTableRect = {PAYTABLE_BOTTOM_LEFT.x,
			PAYTABLE_TOP_RIGHT.y, PAYTABLE_WIDTH,
			PAYTABLE_HEIGHT};
		cropFromRenderTo(renderer, &payTableRect, &payTableRect);
		mGrid.pickRandomChoices(renderer);
		m_PayTable.renderPayTable(renderer, mGrid.numbersClicked(), m_bet);
		//Save data
		m_Recovery.write(getBet(), m_creditInGame.getGameCredit(),
				getBonus(),
				mGrid.getClickedNumbers(),
				m_minBetFlag, m_maxBetFlag, m_setBetFlag);
		if(mBetButton.buttonCondition(mGrid.numbersClicked(), getBet()))
		{
			mBetButton.renderButton(renderer);
			mBetButton.betText(renderer);
		}
	}

	setMinMaxBet(renderer, e);


	if (m_clearButton.getButtonRect().isClicked(e,
				m_clearButton.getButtonRect().getKRect())) 
	{
		setBet(0);
		gameButtonsChunk();
		SDL_Rect payTableRect = {PAYTABLE_BOTTOM_LEFT.x,
			PAYTABLE_TOP_RIGHT.y, PAYTABLE_WIDTH,
			PAYTABLE_HEIGHT};
		cropFromRenderTo(renderer, &payTableRect, &payTableRect);
		m_PayTable.renderPayTable(renderer, 0, m_bet);
		mGrid.resetNumbersGrid(renderer);
		m_minBetButton.renderMinBet(renderer);
		m_maxBetButton.renderMaxBet(renderer);
		m_minBetFlag = true;
		m_maxBetFlag = true;
		m_setBetFlag = false;
	}

	if(m_infoButton.isClicked(e, m_infoButton.getButtonRect().getKRect()))
	{


		m_counterInfoClick++;


		if((m_counterInfoClick % 2) == 0)
		{

			initializeGameState();
			renderGame(renderer,255);
			reRenderMinimalBet(renderer, m_bet);
			reRenderMaximalBet(renderer,m_bet);
			if(m_bonusInGame.getBonus() > 1)
			{
				m_bonusInGame.getBonusRectangle().render(renderer,m_bonusInGame.getBonusRectangle().getKRect());
				m_bonusInGame.getBonusText().render(renderer,m_bonusInGame.getBonusText().getKRect());
			}
			m_infoGameMode = false;
		}
		else
		{
			m_infoButton.isClickedInfoButton(renderer, e);
			m_infoGameMode = true;
		}


	}
	//Re render bet button
	reRenderBetButton(renderer);
	//ReRender pay table
	SDL_Rect payTableRect = {PAYTABLE_BOTTOM_LEFT.x,
		PAYTABLE_TOP_RIGHT.y, PAYTABLE_WIDTH,
		PAYTABLE_HEIGHT};
	cropFromRenderTo(renderer, &payTableRect, &payTableRect);
	m_PayTable.renderPayTable(renderer, mGrid.numbersClicked(), m_bet);
}

void Game::mouseOnButtonRender(SDL_Renderer* renderer, const SDL_Event& e)
{

	if(m_infoGameMode == false)
	{
		//Mouse over stuff	
		m_clearButton.changeColorOnMouseOver(renderer);

		m_quickPickButton.changeColorOnMouseOver(renderer);

		m_minBetButton.changeColorOnMouseOver(renderer);

		m_maxBetButton.changeColorOnMouseOver(renderer);

		m_cashOutButton.changeColorOnMouseOver(renderer);
	}
}

void Game::changeColorOfClickedNumbers(SDL_Renderer* renderer,
		const SDL_Event& e)
{
	mGrid.createRects(renderer, 255);
	mGrid.reRenderClickedNumbers(renderer, 255);
	if (mGrid.doIfClicked(renderer, e)) {
		SDL_Rect payTableRect = {PAYTABLE_BOTTOM_LEFT.x,
			PAYTABLE_TOP_RIGHT.y, PAYTABLE_WIDTH,
			PAYTABLE_HEIGHT};
		cropFromRenderTo(renderer, &payTableRect, &payTableRect);
		m_PayTable.renderPayTable(renderer, mGrid.numbersClicked(), m_bet);
		m_Recovery.write(getBet(), m_creditInGame.getGameCredit(),
				getBonus(),
				mGrid.getClickedNumbers(),
				m_minBetFlag, m_maxBetFlag, m_setBetFlag);

	}
	mGrid.printNumbers(renderer);

}

void Game::drawAnimationReRender(SDL_Renderer* renderer, SDL_Rect* rects)
{
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

void Game::drawAnimation(SDL_Renderer* renderer,const std::vector<bool>& numbers,
		SDL_Rect* rects)
{
	SDL_Rect test = { 500, 95, 80, 350 };
	colors.clear();
	for (int i = 0; i < 80; i++) {
		if (numbers[i] == true) {
			getDrawAnimation().playSoundEffect(0, 80);
			Uint8 r = rand()%155;
			Uint8 g = rand()%155;
			Uint8 b = rand()%155;
			SDL_Color color = { r, g, b };
			colors.push_back(color);
			for (int k = 115; k <= rects[i].y + 20; k += 20) {
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
			for (int j = 540; j >= rects[i].x + 23; j -= 20) {
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
			getDrawAnimation().playSoundEffect(1, 128);
			int timeout = SDL_GetTicks() + 100;
			while (!(SDL_TICKS_PASSED(SDL_GetTicks(), timeout)));
			flags.set(i, 1);
		}

	}
	//Create number rects
	mGrid.createRects(renderer, 255);

	mGrid.reRenderClickedNumbers(renderer, 255);

	//Print the numbers
	mGrid.printNumbers(renderer);

	drawAnimationReRender(renderer, rects);

	SDL_RenderPresent(renderer);
	flags.reset();
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
		const SDL_Event& e)
{

	int temp = 0;
	int changedCredit = 0;

	temp = m_creditInGame.getGameCredit();

	changedCredit = temp - m_bet;
	m_creditInGame.setGameCredit(changedCredit);
	m_creditInGame.renderCreditsInGame(renderer);

}

int Game::calculateWinInGame()
{
	int winResult = 0;

	m_winInGame.setWinCredits(
			calculateWin(mGrid.numbersClicked(), mGrid.numberOfHits(), m_bet));

	winResult = m_winInGame.getWinCredits() + m_creditInGame.getGameCredit();
	m_creditInGame.setGameCredit(winResult);
	return winResult;
}

void Game::showWinInGame(SDL_Renderer* renderer)
{
	m_winInGame.renderWinInGame(renderer);
	m_creditInGame.renderCreditsInGame(renderer);
}

void Game::renderAfterAnimationGame(SDL_Renderer* renderer, int alpha)
{

	//Render numbers grid background
	mGrid.renderBackground(renderer);

	//Create number rects
	mGrid.createRects(renderer, alpha);

	//Print the numbers
	mGrid.printNumbers(renderer);

	//Render bet button
	mBetButton.buttonCondition(mGrid.numbersClicked(), getBet());
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
	reRenderHistory(renderer);	

	//	m_PayTable.renderPayTable(renderer);
	//	m_PayTable.renderHitsText(renderer);

	m_DrawAnimation.loadTextures(renderer);
	m_DrawAnimation.drawPipe(renderer);
}

double Game::calculateCreditsInMoney()
{

	double denomination = 0.25;
	double money = 0;

	int bonus = 0;
	int tempBonus = 0;
	int resultDenom = 0;

	tempBonus = m_bonus * 10;

	resultDenom = tempBonus % 10;

	if(resultDenom > 5)
	{
		bonus = m_bonus + 1;

	}
	else
	{
		bonus = m_bonus;

	}

	money = denomination * (m_creditInGame.getGameCredit() + bonus);

	return money;
}

bool Game::cashOutButtonPushed(const SDL_Event& e)
{
	bool success = false;
	if(m_cashOutButton.getCashOutRect().isClicked(e, m_cashOutButton.getCashOutRect().getKRect()))
	{
		m_Recovery.write(getBet(), m_creditInGame.getGameCredit(),
				getBonus(),
				mGrid.getClickedNumbers(),
				m_minBetFlag, m_maxBetFlag, m_setBetFlag);
		success = true;
	}
	return success;
}

// Play/pause music
void Game::playPauseMusic(SDL_Renderer* renderer, const SDL_Event& e,
		Mix_Music* mainMusic)

{
	if(m_volumeButton.getButtonRect().isClicked(e,
				m_volumeButton.getButtonRect().getKRect()))
	{
		SDL_Rect cropRect = {VOLUME_BUTTON_POSITION_X, VOLUME_BUTTON_POSITION_Y,
			VOLUME_BUTTON_WIDTH, VOLUME_BUTTON_HEIGHT};

		if(Mix_PlayingMusic() == 0)
		{
			Mix_PlayMusic(mainMusic, -1);

		}
		else
		{
			if( Mix_PausedMusic() == 1 )
			{
				Mix_ResumeMusic();
				cropFromRenderTo(renderer, &cropRect, &cropRect);
				m_volumeButton.renderVolumeButton(renderer);
			}
			else
			{
				Mix_PauseMusic();
				cropFromRenderTo(renderer, &cropRect, &cropRect);
				m_volumeButton.getButtonRectPushed().render
					(renderer,m_volumeButton.getButtonRectPushed().getKRect());
			}
		}
	}

}

Bonus& Game::getBonusInGame()
{
	return m_bonusInGame;
}

int Game::calculateBonus(int bet)
{
	double bonus = 0;
	double result = 0;
	bonus = static_cast<double>(bet);

	result = m_bonus + (bonus * 0.1);

	setBonus(result);

	int bonusToShow = 0;

	bonusToShow += getBonus();

	return bonusToShow;

}

double Game::getBonus() const
{
	return m_bonus;
}

void Game::setBonus(double bonus)
{
	m_bonus = bonus;
}

void Game::bonusToCredits(int match, SDL_Renderer* renderer)
{
	int bonus = 0;

	int tempBonus = 0;
	int resultDenom = 0;
	if(match > 5)
	{

		tempBonus = m_bonus * 10;

		resultDenom = tempBonus % 10;


		if(resultDenom > 5)
		{
			bonus = m_bonus + 1;

		}
		else
		{
			bonus = m_bonus;

		}
		setBonus(0);


		m_creditInGame.setGameCredit((m_creditInGame.getGameCredit() + bonus));



		m_bonusFlag = true;

	}



}

InfoButton& Game::getInfoButton()
{
	return m_infoButton;
}

bool Game::isGameOverFlag() const {
	return m_gameOverFlag;
}

void Game::setGameOverFlag(bool gameOverFlag) {
	m_gameOverFlag = gameOverFlag;
}

void Game::reRenderMinimalBet(SDL_Renderer* renderer, int bet)
{

	reRenderMinimalBetNumOne(renderer, bet);
	reRenderMinimalBetNumTwo(renderer, bet);
	reRenderMinimalBetNumThree(renderer, bet);
	reRenderMinimalBetNumFour(renderer, bet);
	reRenderMinimalBetNumFive(renderer, bet);
	reRenderMinimalBetNumTen(renderer, bet);

	m_Recovery.write(getBet(), m_creditInGame.getGameCredit(),
			getBonus(),
			mGrid.getClickedNumbers(),
			m_minBetFlag, m_maxBetFlag, m_setBetFlag);
}

void Game::reRenderMaximalBet(SDL_Renderer* renderer, int bet)
{

	reRenderMaximalBetNumFive(renderer, bet);
	reRenderMaximalBetNumTen(renderer, bet);
	reRenderMaximalBetNumTwenty(renderer, bet);
	reRenderMaximalBetNumThirty(renderer, bet);
	reRenderMaximalBetNumFourty(renderer, bet);
	reRenderMaximalBetNumFifty(renderer, bet);


	m_Recovery.write(getBet(), m_creditInGame.getGameCredit(),
			getBonus(),
			mGrid.getClickedNumbers(),
			m_minBetFlag, m_maxBetFlag, m_setBetFlag);

}

void Game::reRenderMinimalBetNumOne(SDL_Renderer* renderer, int bet)
{
	if(bet == 1)
	{

		m_minBetButton.getButtonRect().render(renderer,m_minBetButton.getButtonRect().getKRect());

		m_minBetButton.getButtonStartCircle().loadTextureFromFile("Resources/Images/maxMinBettPushedGreen.png",renderer);
		m_minBetButton.getButtonStartCircle().render(renderer,m_minBetButton.getButtonStartCircle().getKRect());

		m_minBetButton.getMinBet().render(renderer,m_minBetButton.getMinBet().getKRect());
		m_minBetButton.getNumOne().setButtonColor(251, 211, 72);
		m_minBetButton.getNumOne().LoadFromRenderedText("1", renderer, m_minBetButton.getNumOne().getButtonColor());
		m_minBetButton.getNumOne().render(renderer,m_minBetButton.getNumOne().getKRect());

		m_minBetButton.getNumTwo().setButtonColor(254, 254, 254);
		m_minBetButton.getNumTwo().LoadFromRenderedText("2",renderer,m_minBetButton.getNumTwo().getButtonColor());
		m_minBetButton.getNumTwo().render(renderer,m_minBetButton.getNumTwo().getKRect());

		m_minBetButton.getNumThree().setButtonColor(254, 254, 254);
		m_minBetButton.getNumThree().LoadFromRenderedText("3", renderer, m_minBetButton.getNumThree().getButtonColor());
		m_minBetButton.getNumThree().render(renderer, m_minBetButton.getNumThree().getKRect());

		m_minBetButton.getNumFour().setButtonColor(254, 254, 254);
		m_minBetButton.getNumFour().LoadFromRenderedText("4",renderer,m_minBetButton.getNumFour().getButtonColor());
		m_minBetButton.getNumFour().render(renderer, m_minBetButton.getNumFour().getKRect());

		m_minBetButton.getNumFive().setButtonColor(254, 254, 254);
		m_minBetButton.getNumFive().LoadFromRenderedText("5",renderer,m_minBetButton.getNumFive().getButtonColor());
		m_minBetButton.getNumFive().render(renderer,m_minBetButton.getNumFive().getKRect());

		m_minBetButton.getNumTen().setButtonColor(254, 254, 254);
		m_minBetButton.getNumTen().LoadFromRenderedText("10",renderer,m_minBetButton.getNumTen().getButtonColor());
		m_minBetButton.getNumTen().render(renderer,m_minBetButton.getNumTen().getKRect());

		m_maxBetButton.deactivateMaxButton(renderer);
	}
}

void Game::reRenderMinimalBetNumTwo(SDL_Renderer* renderer, int bet)
{
	if(bet == 2)
	{
		m_minBetButton.getButtonRect().render(renderer,m_minBetButton.getButtonRect().getKRect());

		m_minBetButton.getButtonStartCircle().loadTextureFromFile("Resources/Images/maxMinBettPushedGreen.png",renderer);
		m_minBetButton.getButtonStartCircle().render(renderer,m_minBetButton.getButtonStartCircle().getKRect());

		m_minBetButton.getMinBet().render(renderer,m_minBetButton.getMinBet().getKRect());
		m_minBetButton.getNumOne().setButtonColor(254, 254, 254);
		m_minBetButton.getNumOne().LoadFromRenderedText("1", renderer, m_minBetButton.getNumOne().getButtonColor());
		m_minBetButton.getNumOne().render(renderer,m_minBetButton.getNumOne().getKRect());

		m_minBetButton.getNumTwo().setButtonColor(251, 211, 72);
		m_minBetButton.getNumTwo().LoadFromRenderedText("2",renderer,m_minBetButton.getNumTwo().getButtonColor());
		m_minBetButton.getNumTwo().render(renderer,m_minBetButton.getNumTwo().getKRect());

		m_minBetButton.getNumThree().setButtonColor(254, 254, 254);
		m_minBetButton.getNumThree().LoadFromRenderedText("3", renderer, m_minBetButton.getNumThree().getButtonColor());
		m_minBetButton.getNumThree().render(renderer, m_minBetButton.getNumThree().getKRect());

		m_minBetButton.getNumFour().setButtonColor(254, 254, 254);
		m_minBetButton.getNumFour().LoadFromRenderedText("4",renderer,m_minBetButton.getNumFour().getButtonColor());
		m_minBetButton.getNumFour().render(renderer, m_minBetButton.getNumFour().getKRect());

		m_minBetButton.getNumFive().setButtonColor(254, 254, 254);
		m_minBetButton.getNumFive().LoadFromRenderedText("5",renderer,m_minBetButton.getNumFive().getButtonColor());
		m_minBetButton.getNumFive().render(renderer,m_minBetButton.getNumFive().getKRect());

		m_minBetButton.getNumTen().setButtonColor(254, 254, 254);
		m_minBetButton.getNumTen().LoadFromRenderedText("10",renderer,m_minBetButton.getNumTen().getButtonColor());
		m_minBetButton.getNumTen().render(renderer,m_minBetButton.getNumTen().getKRect());

		m_maxBetButton.deactivateMaxButton(renderer);
	}
}

void Game::reRenderMinimalBetNumThree(SDL_Renderer* renderer, int bet)
{
	if(bet == 3)
	{
		m_minBetButton.getButtonRect().render(renderer,m_minBetButton.getButtonRect().getKRect());

		m_minBetButton.getButtonStartCircle().loadTextureFromFile("Resources/Images/maxMinBettPushedGreen.png",renderer);
		m_minBetButton.getButtonStartCircle().render(renderer,m_minBetButton.getButtonStartCircle().getKRect());

		m_minBetButton.getMinBet().render(renderer,m_minBetButton.getMinBet().getKRect());
		m_minBetButton.getNumOne().setButtonColor(254, 254, 254);
		m_minBetButton.getNumOne().LoadFromRenderedText("1", renderer, m_minBetButton.getNumOne().getButtonColor());
		m_minBetButton.getNumOne().render(renderer,m_minBetButton.getNumOne().getKRect());

		m_minBetButton.getNumTwo().setButtonColor(254, 254, 254);
		m_minBetButton.getNumTwo().LoadFromRenderedText("2",renderer,m_minBetButton.getNumTwo().getButtonColor());
		m_minBetButton.getNumTwo().render(renderer,m_minBetButton.getNumTwo().getKRect());

		m_minBetButton.getNumThree().setButtonColor(251, 211, 72);
		m_minBetButton.getNumThree().LoadFromRenderedText("3", renderer, m_minBetButton.getNumThree().getButtonColor());
		m_minBetButton.getNumThree().render(renderer, m_minBetButton.getNumThree().getKRect());

		m_minBetButton.getNumFour().setButtonColor(254, 254, 254);
		m_minBetButton.getNumFour().LoadFromRenderedText("4",renderer,m_minBetButton.getNumFour().getButtonColor());
		m_minBetButton.getNumFour().render(renderer, m_minBetButton.getNumFour().getKRect());

		m_minBetButton.getNumFive().setButtonColor(254, 254, 254);
		m_minBetButton.getNumFive().LoadFromRenderedText("5",renderer,m_minBetButton.getNumFive().getButtonColor());
		m_minBetButton.getNumFive().render(renderer,m_minBetButton.getNumFive().getKRect());

		m_minBetButton.getNumTen().setButtonColor(254, 254, 254);
		m_minBetButton.getNumTen().LoadFromRenderedText("10",renderer,m_minBetButton.getNumTen().getButtonColor());
		m_minBetButton.getNumTen().render(renderer,m_minBetButton.getNumTen().getKRect());

		m_maxBetButton.deactivateMaxButton(renderer);
	}
}

void Game::reRenderMinimalBetNumFour(SDL_Renderer* renderer, int bet)
{
	if(bet == 4)
	{
		m_minBetButton.getButtonRect().render(renderer,m_minBetButton.getButtonRect().getKRect());

		m_minBetButton.getButtonStartCircle().loadTextureFromFile("Resources/Images/maxMinBettPushedGreen.png",renderer);
		m_minBetButton.getButtonStartCircle().render(renderer,m_minBetButton.getButtonStartCircle().getKRect());

		m_minBetButton.getMinBet().render(renderer,m_minBetButton.getMinBet().getKRect());
		m_minBetButton.getNumOne().setButtonColor(254, 254, 254);
		m_minBetButton.getNumOne().LoadFromRenderedText("1", renderer, m_minBetButton.getNumOne().getButtonColor());
		m_minBetButton.getNumOne().render(renderer,m_minBetButton.getNumOne().getKRect());

		m_minBetButton.getNumTwo().setButtonColor(254, 254, 254);
		m_minBetButton.getNumTwo().LoadFromRenderedText("2",renderer,m_minBetButton.getNumTwo().getButtonColor());
		m_minBetButton.getNumTwo().render(renderer,m_minBetButton.getNumTwo().getKRect());

		m_minBetButton.getNumThree().setButtonColor(254, 254, 254);
		m_minBetButton.getNumThree().LoadFromRenderedText("3", renderer, m_minBetButton.getNumThree().getButtonColor());
		m_minBetButton.getNumThree().render(renderer, m_minBetButton.getNumThree().getKRect());

		m_minBetButton.getNumFour().setButtonColor(251, 211, 72);
		m_minBetButton.getNumFour().LoadFromRenderedText("4",renderer,m_minBetButton.getNumFour().getButtonColor());
		m_minBetButton.getNumFour().render(renderer, m_minBetButton.getNumFour().getKRect());

		m_minBetButton.getNumFive().setButtonColor(254, 254, 254);
		m_minBetButton.getNumFive().LoadFromRenderedText("5",renderer,m_minBetButton.getNumFive().getButtonColor());
		m_minBetButton.getNumFive().render(renderer,m_minBetButton.getNumFive().getKRect());

		m_minBetButton.getNumTen().setButtonColor(254, 254, 254);
		m_minBetButton.getNumTen().LoadFromRenderedText("10",renderer,m_minBetButton.getNumTen().getButtonColor());
		m_minBetButton.getNumTen().render(renderer,m_minBetButton.getNumTen().getKRect());

		m_maxBetButton.deactivateMaxButton(renderer);
	}
}

void Game::reRenderMinimalBetNumFive(SDL_Renderer* renderer, int bet)
{
	if(bet == 5 && m_minBetFlag == true)
	{
		m_minBetButton.getButtonRect().render(renderer,m_minBetButton.getButtonRect().getKRect());

		m_minBetButton.getButtonStartCircle().loadTextureFromFile("Resources/Images/maxMinBettPushedGreen.png",renderer);
		m_minBetButton.getButtonStartCircle().render(renderer,m_minBetButton.getButtonStartCircle().getKRect());

		m_minBetButton.getMinBet().render(renderer,m_minBetButton.getMinBet().getKRect());
		m_minBetButton.getNumOne().setButtonColor(254, 254, 254);
		m_minBetButton.getNumOne().LoadFromRenderedText("1", renderer, m_minBetButton.getNumOne().getButtonColor());
		m_minBetButton.getNumOne().render(renderer,m_minBetButton.getNumOne().getKRect());

		m_minBetButton.getNumTwo().setButtonColor(254, 254, 254);
		m_minBetButton.getNumTwo().LoadFromRenderedText("2",renderer,m_minBetButton.getNumTwo().getButtonColor());
		m_minBetButton.getNumTwo().render(renderer,m_minBetButton.getNumTwo().getKRect());

		m_minBetButton.getNumThree().setButtonColor(254, 254, 254);
		m_minBetButton.getNumThree().LoadFromRenderedText("3", renderer, m_minBetButton.getNumThree().getButtonColor());
		m_minBetButton.getNumThree().render(renderer, m_minBetButton.getNumThree().getKRect());

		m_minBetButton.getNumFour().setButtonColor(254, 254, 254);
		m_minBetButton.getNumFour().LoadFromRenderedText("4",renderer,m_minBetButton.getNumFour().getButtonColor());
		m_minBetButton.getNumFour().render(renderer, m_minBetButton.getNumFour().getKRect());

		m_minBetButton.getNumFive().setButtonColor(251, 211, 72);
		m_minBetButton.getNumFive().LoadFromRenderedText("5",renderer,m_minBetButton.getNumFive().getButtonColor());
		m_minBetButton.getNumFive().render(renderer,m_minBetButton.getNumFive().getKRect());

		m_minBetButton.getNumTen().setButtonColor(254, 254, 254);
		m_minBetButton.getNumTen().LoadFromRenderedText("10",renderer,m_minBetButton.getNumTen().getButtonColor());
		m_minBetButton.getNumTen().render(renderer,m_minBetButton.getNumTen().getKRect());

		m_maxBetButton.deactivateMaxButton(renderer);
	}
}

void Game::reRenderMaximalBetNumFive(SDL_Renderer* renderer, int bet)
{
	if(bet == 5 && m_maxBetFlag == true)
	{

		m_maxBetButton.getButtonRectMax().render(renderer, m_maxBetButton.getButtonRectMax().getKRect());

		m_maxBetButton.getButtonStartCircleMax().loadTextureFromFile("Resources/Images/maxMinBettPushedGreen.png",renderer);
		m_maxBetButton.getButtonStartCircleMax().render(renderer,m_maxBetButton.getButtonStartCircleMax().getKRect());

		m_maxBetButton.getMaxBet().render(renderer,m_maxBetButton.getMaxBet().getKRect());
		m_maxBetButton.getNumFiveMax().setButtonColor(251, 211, 72);
		m_maxBetButton.getNumFiveMax().LoadFromRenderedText("5", renderer, m_maxBetButton.getNumFiveMax().getButtonColor());
		m_maxBetButton.getNumFiveMax().render(renderer,m_maxBetButton.getNumFiveMax().getKRect());

		m_maxBetButton.getNumTenMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumTenMax().LoadFromRenderedText("10",renderer,m_maxBetButton.getNumTenMax().getButtonColor());
		m_maxBetButton.getNumTenMax().render(renderer,m_maxBetButton.getNumTenMax().getKRect());

		m_maxBetButton.getNumTwentyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumTwentyMax().LoadFromRenderedText("20", renderer, m_maxBetButton.getNumTwentyMax().getButtonColor());
		m_maxBetButton.getNumTwentyMax().render(renderer, m_maxBetButton.getNumTwentyMax().getKRect());

		m_maxBetButton.getNumThirtyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumThirtyMax().LoadFromRenderedText("30",renderer, m_maxBetButton.getNumThirtyMax().getButtonColor());
		m_maxBetButton.getNumThirtyMax().render(renderer, m_maxBetButton.getNumThirtyMax().getKRect());

		m_maxBetButton.getNumFourtyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumFourtyMax().LoadFromRenderedText("40",renderer, m_maxBetButton.getNumFourtyMax().getButtonColor());
		m_maxBetButton.getNumFourtyMax().render(renderer, m_maxBetButton.getNumFourtyMax().getKRect());

		m_maxBetButton.getNumFiftyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumFiftyMax().LoadFromRenderedText("50",renderer, m_maxBetButton.getNumFiftyMax().getButtonColor());
		m_maxBetButton.getNumFiftyMax().render(renderer, m_maxBetButton.getNumFiftyMax().getKRect());

		m_minBetButton.deactivateMinButton(renderer);
	}
}

void Game::reRenderMaximalBetNumTen(SDL_Renderer* renderer, int bet)
{
	if(bet == 10 && m_maxBetFlag == true)
	{

		m_maxBetButton.getButtonRectMax().render(renderer, m_maxBetButton.getButtonRectMax().getKRect());

		m_maxBetButton.getButtonStartCircleMax().loadTextureFromFile("Resources/Images/maxMinBettPushedGreen.png",renderer);
		m_maxBetButton.getButtonStartCircleMax().render(renderer,m_maxBetButton.getButtonStartCircleMax().getKRect());

		m_maxBetButton.getMaxBet().render(renderer,m_maxBetButton.getMaxBet().getKRect());
		m_maxBetButton.getNumFiveMax().setButtonColor(254, 254,	254);
		m_maxBetButton.getNumFiveMax().LoadFromRenderedText("5", renderer, m_maxBetButton.getNumFiveMax().getButtonColor());
		m_maxBetButton.getNumFiveMax().render(renderer,m_maxBetButton.getNumFiveMax().getKRect());

		m_maxBetButton.getNumTenMax().setButtonColor(251, 211, 72);
		m_maxBetButton.getNumTenMax().LoadFromRenderedText("10",renderer,m_maxBetButton.getNumTenMax().getButtonColor());
		m_maxBetButton.getNumTenMax().render(renderer,m_maxBetButton.getNumTenMax().getKRect());

		m_maxBetButton.getNumTwentyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumTwentyMax().LoadFromRenderedText("20", renderer, m_maxBetButton.getNumTwentyMax().getButtonColor());
		m_maxBetButton.getNumTwentyMax().render(renderer, m_maxBetButton.getNumTwentyMax().getKRect());

		m_maxBetButton.getNumThirtyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumThirtyMax().LoadFromRenderedText("30",renderer, m_maxBetButton.getNumThirtyMax().getButtonColor());
		m_maxBetButton.getNumThirtyMax().render(renderer, m_maxBetButton.getNumThirtyMax().getKRect());

		m_maxBetButton.getNumFourtyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumFourtyMax().LoadFromRenderedText("40",renderer, m_maxBetButton.getNumFourtyMax().getButtonColor());
		m_maxBetButton.getNumFourtyMax().render(renderer, m_maxBetButton.getNumFourtyMax().getKRect());

		m_maxBetButton.getNumFiftyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumFiftyMax().LoadFromRenderedText("50",renderer, m_maxBetButton.getNumFiftyMax().getButtonColor());
		m_maxBetButton.getNumFiftyMax().render(renderer, m_maxBetButton.getNumFiftyMax().getKRect());

		m_minBetButton.deactivateMinButton(renderer);
	}
}

void Game::reRenderMaximalBetNumTwenty(SDL_Renderer* renderer, int bet)
{
	if(bet == 20)
	{

		m_maxBetButton.getButtonRectMax().render(renderer, m_maxBetButton.getButtonRectMax().getKRect());

		m_maxBetButton.getButtonStartCircleMax().loadTextureFromFile("Resources/Images/maxMinBettPushedGreen.png",renderer);
		m_maxBetButton.getButtonStartCircleMax().render(renderer,m_maxBetButton.getButtonStartCircleMax().getKRect());

		m_maxBetButton.getMaxBet().render(renderer,m_maxBetButton.getMaxBet().getKRect());
		m_maxBetButton.getNumFiveMax().setButtonColor(254, 254,	254);
		m_maxBetButton.getNumFiveMax().LoadFromRenderedText("5", renderer, m_maxBetButton.getNumFiveMax().getButtonColor());
		m_maxBetButton.getNumFiveMax().render(renderer,m_maxBetButton.getNumFiveMax().getKRect());

		m_maxBetButton.getNumTenMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumTenMax().LoadFromRenderedText("10",renderer,m_maxBetButton.getNumTenMax().getButtonColor());
		m_maxBetButton.getNumTenMax().render(renderer,m_maxBetButton.getNumTenMax().getKRect());

		m_maxBetButton.getNumTwentyMax().setButtonColor(251, 211, 72);
		m_maxBetButton.getNumTwentyMax().LoadFromRenderedText("20", renderer, m_maxBetButton.getNumTwentyMax().getButtonColor());
		m_maxBetButton.getNumTwentyMax().render(renderer, m_maxBetButton.getNumTwentyMax().getKRect());

		m_maxBetButton.getNumThirtyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumThirtyMax().LoadFromRenderedText("30",renderer, m_maxBetButton.getNumThirtyMax().getButtonColor());
		m_maxBetButton.getNumThirtyMax().render(renderer, m_maxBetButton.getNumThirtyMax().getKRect());

		m_maxBetButton.getNumFourtyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumFourtyMax().LoadFromRenderedText("40",renderer, m_maxBetButton.getNumFourtyMax().getButtonColor());
		m_maxBetButton.getNumFourtyMax().render(renderer, m_maxBetButton.getNumFourtyMax().getKRect());

		m_maxBetButton.getNumFiftyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumFiftyMax().LoadFromRenderedText("50",renderer, m_maxBetButton.getNumFiftyMax().getButtonColor());
		m_maxBetButton.getNumFiftyMax().render(renderer, m_maxBetButton.getNumFiftyMax().getKRect());

		m_minBetButton.deactivateMinButton(renderer);
	}
}

void Game::reRenderMaximalBetNumThirty(SDL_Renderer* renderer, int bet)
{
	if(bet == 30)
	{

		m_maxBetButton.getButtonRectMax().render(renderer, m_maxBetButton.getButtonRectMax().getKRect());

		m_maxBetButton.getButtonStartCircleMax().loadTextureFromFile("Resources/Images/maxMinBettPushedGreen.png",renderer);
		m_maxBetButton.getButtonStartCircleMax().render(renderer,m_maxBetButton.getButtonStartCircleMax().getKRect());

		m_maxBetButton.getMaxBet().render(renderer,m_maxBetButton.getMaxBet().getKRect());
		m_maxBetButton.getNumFiveMax().setButtonColor(254, 254,	254);
		m_maxBetButton.getNumFiveMax().LoadFromRenderedText("5", renderer, m_maxBetButton.getNumFiveMax().getButtonColor());
		m_maxBetButton.getNumFiveMax().render(renderer,m_maxBetButton.getNumFiveMax().getKRect());

		m_maxBetButton.getNumTenMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumTenMax().LoadFromRenderedText("10",renderer,m_maxBetButton.getNumTenMax().getButtonColor());
		m_maxBetButton.getNumTenMax().render(renderer,m_maxBetButton.getNumTenMax().getKRect());

		m_maxBetButton.getNumTwentyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumTwentyMax().LoadFromRenderedText("20", renderer, m_maxBetButton.getNumTwentyMax().getButtonColor());
		m_maxBetButton.getNumTwentyMax().render(renderer, m_maxBetButton.getNumTwentyMax().getKRect());

		m_maxBetButton.getNumThirtyMax().setButtonColor(251, 211, 72);
		m_maxBetButton.getNumThirtyMax().LoadFromRenderedText("30",renderer, m_maxBetButton.getNumThirtyMax().getButtonColor());
		m_maxBetButton.getNumThirtyMax().render(renderer, m_maxBetButton.getNumThirtyMax().getKRect());

		m_maxBetButton.getNumFourtyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumFourtyMax().LoadFromRenderedText("40",renderer, m_maxBetButton.getNumFourtyMax().getButtonColor());
		m_maxBetButton.getNumFourtyMax().render(renderer, m_maxBetButton.getNumFourtyMax().getKRect());

		m_maxBetButton.getNumFiftyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumFiftyMax().LoadFromRenderedText("50",renderer, m_maxBetButton.getNumFiftyMax().getButtonColor());
		m_maxBetButton.getNumFiftyMax().render(renderer, m_maxBetButton.getNumFiftyMax().getKRect());

		m_minBetButton.deactivateMinButton(renderer);
	}
}

void Game::reRenderMaximalBetNumFourty(SDL_Renderer* renderer, int bet)
{
	if(bet == 40)
	{

		m_maxBetButton.getButtonRectMax().render(renderer, m_maxBetButton.getButtonRectMax().getKRect());

		m_maxBetButton.getButtonStartCircleMax().loadTextureFromFile("Resources/Images/maxMinBettPushedGreen.png",renderer);
		m_maxBetButton.getButtonStartCircleMax().render(renderer,m_maxBetButton.getButtonStartCircleMax().getKRect());

		m_maxBetButton.getMaxBet().render(renderer,m_maxBetButton.getMaxBet().getKRect());
		m_maxBetButton.getNumFiveMax().setButtonColor(254, 254,	254);
		m_maxBetButton.getNumFiveMax().LoadFromRenderedText("5", renderer, m_maxBetButton.getNumFiveMax().getButtonColor());
		m_maxBetButton.getNumFiveMax().render(renderer,m_maxBetButton.getNumFiveMax().getKRect());

		m_maxBetButton.getNumTenMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumTenMax().LoadFromRenderedText("10",renderer,m_maxBetButton.getNumTenMax().getButtonColor());
		m_maxBetButton.getNumTenMax().render(renderer,m_maxBetButton.getNumTenMax().getKRect());

		m_maxBetButton.getNumTwentyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumTwentyMax().LoadFromRenderedText("20", renderer, m_maxBetButton.getNumTwentyMax().getButtonColor());
		m_maxBetButton.getNumTwentyMax().render(renderer, m_maxBetButton.getNumTwentyMax().getKRect());

		m_maxBetButton.getNumThirtyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumThirtyMax().LoadFromRenderedText("30",renderer, m_maxBetButton.getNumThirtyMax().getButtonColor());
		m_maxBetButton.getNumThirtyMax().render(renderer, m_maxBetButton.getNumThirtyMax().getKRect());

		m_maxBetButton.getNumFourtyMax().setButtonColor(251, 211, 72);
		m_maxBetButton.getNumFourtyMax().LoadFromRenderedText("40",renderer, m_maxBetButton.getNumFourtyMax().getButtonColor());
		m_maxBetButton.getNumFourtyMax().render(renderer, m_maxBetButton.getNumFourtyMax().getKRect());

		m_maxBetButton.getNumFiftyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumFiftyMax().LoadFromRenderedText("50",renderer, m_maxBetButton.getNumFiftyMax().getButtonColor());
		m_maxBetButton.getNumFiftyMax().render(renderer, m_maxBetButton.getNumFiftyMax().getKRect());

		m_minBetButton.deactivateMinButton(renderer);
	}
}

void Game::reRenderMaximalBetNumFifty(SDL_Renderer* renderer, int bet)
{
	if(bet == 50)
	{

		m_maxBetButton.getButtonRectMax().render(renderer, m_maxBetButton.getButtonRectMax().getKRect());

		m_maxBetButton.getButtonStartCircleMax().loadTextureFromFile("Resources/Images/maxMinBettPushedGreen.png",renderer);
		m_maxBetButton.getButtonStartCircleMax().render(renderer,m_maxBetButton.getButtonStartCircleMax().getKRect());

		m_maxBetButton.getMaxBet().render(renderer,m_maxBetButton.getMaxBet().getKRect());
		m_maxBetButton.getNumFiveMax().setButtonColor(254, 254,	254);
		m_maxBetButton.getNumFiveMax().LoadFromRenderedText("5", renderer, m_maxBetButton.getNumFiveMax().getButtonColor());
		m_maxBetButton.getNumFiveMax().render(renderer,m_maxBetButton.getNumFiveMax().getKRect());

		m_maxBetButton.getNumTenMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumTenMax().LoadFromRenderedText("10",renderer,m_maxBetButton.getNumTenMax().getButtonColor());
		m_maxBetButton.getNumTenMax().render(renderer,m_maxBetButton.getNumTenMax().getKRect());

		m_maxBetButton.getNumTwentyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumTwentyMax().LoadFromRenderedText("20", renderer, m_maxBetButton.getNumTwentyMax().getButtonColor());
		m_maxBetButton.getNumTwentyMax().render(renderer, m_maxBetButton.getNumTwentyMax().getKRect());

		m_maxBetButton.getNumThirtyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumThirtyMax().LoadFromRenderedText("30",renderer, m_maxBetButton.getNumThirtyMax().getButtonColor());
		m_maxBetButton.getNumThirtyMax().render(renderer, m_maxBetButton.getNumThirtyMax().getKRect());

		m_maxBetButton.getNumFourtyMax().setButtonColor(254, 254, 254);
		m_maxBetButton.getNumFourtyMax().LoadFromRenderedText("40",renderer, m_maxBetButton.getNumFourtyMax().getButtonColor());
		m_maxBetButton.getNumFourtyMax().render(renderer, m_maxBetButton.getNumFourtyMax().getKRect());

		m_maxBetButton.getNumFiftyMax().setButtonColor(251, 211, 72);
		m_maxBetButton.getNumFiftyMax().LoadFromRenderedText("50",renderer, m_maxBetButton.getNumFiftyMax().getButtonColor());
		m_maxBetButton.getNumFiftyMax().render(renderer, m_maxBetButton.getNumFiftyMax().getKRect());

		m_minBetButton.deactivateMinButton(renderer);
	}
}

void Game::reRenderMinimalBetNumTen(SDL_Renderer* renderer, int bet)
{
	if(bet == 10 && m_minBetFlag == true)
	{
		m_minBetButton.getButtonRect().render(renderer,m_minBetButton.getButtonRect().getKRect());

		m_minBetButton.getButtonStartCircle().loadTextureFromFile("Resources/Images/maxMinBettPushedGreen.png",renderer);

		m_minBetButton.getButtonStartCircle().render(renderer,m_minBetButton.getButtonStartCircle().getKRect());

		m_minBetButton.getMinBet().render(renderer,m_minBetButton.getMinBet().getKRect());
		m_minBetButton.getNumOne().setButtonColor(254, 254, 254);
		m_minBetButton.getNumOne().LoadFromRenderedText("1", renderer, m_minBetButton.getNumOne().getButtonColor());
		m_minBetButton.getNumOne().render(renderer,m_minBetButton.getNumOne().getKRect());

		m_minBetButton.getNumTwo().setButtonColor(254, 254, 254);
		m_minBetButton.getNumTwo().LoadFromRenderedText("2",renderer,m_minBetButton.getNumTwo().getButtonColor());
		m_minBetButton.getNumTwo().render(renderer,m_minBetButton.getNumTwo().getKRect());

		m_minBetButton.getNumThree().setButtonColor(254, 254, 254);
		m_minBetButton.getNumThree().LoadFromRenderedText("3", renderer, m_minBetButton.getNumThree().getButtonColor());
		m_minBetButton.getNumThree().render(renderer, m_minBetButton.getNumThree().getKRect());

		m_minBetButton.getNumFour().setButtonColor(254, 254, 254);
		m_minBetButton.getNumFour().LoadFromRenderedText("4",renderer,m_minBetButton.getNumFour().getButtonColor());
		m_minBetButton.getNumFour().render(renderer, m_minBetButton.getNumFour().getKRect());

		m_minBetButton.getNumFive().setButtonColor(254, 254, 254);
		m_minBetButton.getNumFive().LoadFromRenderedText("5",renderer,m_minBetButton.getNumFive().getButtonColor());
		m_minBetButton.getNumFive().render(renderer,m_minBetButton.getNumFive().getKRect());

		m_minBetButton.getNumTen().setButtonColor(251, 211, 72);
		m_minBetButton.getNumTen().LoadFromRenderedText("10",renderer,m_minBetButton.getNumTen().getButtonColor());
		m_minBetButton.getNumTen().render(renderer,m_minBetButton.getNumTen().getKRect());

		m_maxBetButton.deactivateMaxButton(renderer);
	}
}

void Game::setMinMaxBet(SDL_Renderer* renderer, const SDL_Event& e)
{


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
		gameButtonsChunk();
		m_maxBetButton.activateMaxButton(renderer);
		m_minBetButton.deactivateMinButton(renderer);
		m_maxBetFlag = true;
		m_minBetFlag = false;
	}

	if (m_minBetButton.getMinBet().isClicked(e,
				m_minBetButton.getMinBet().getKRect()) )
	{
		gameButtonsChunk();
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

	if (m_maxBetFlag == false && m_setBetFlag == true)
	{
		m_maxBetButton.renderMaxBet(renderer);
		m_maxBetButton.deactivateMaxButton(renderer);
	}

	if (m_minBetFlag == true && m_setBetFlag == true)
	{
		m_minBetButton.betChoiceMin(renderer, e);
		setBet(m_minBetButton.getMinimalBet());
	}

	if (m_maxBetFlag == true && m_setBetFlag == true)
	{
		m_maxBetButton.betChoiceMax(renderer, e);
		setBet(m_maxBetButton.getMaximalBet());
	}
	m_Recovery.write(getBet(), m_creditInGame.getGameCredit(),
			getBonus(),
			mGrid.getClickedNumbers(),
			m_minBetFlag, m_maxBetFlag, m_setBetFlag);

}

CashOut& Game::getCashOutButton()
{
	return m_cashOutButton;
}
int Game::calculateWin(int spots, int match, int bet)
{
	int result = 0;
	if (match > 0) {
		int arrayQueficient[9][10] = { 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 16,
			0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 12, 0, 0, 0, 0, 0, 0, 0, 1, 3, 15,
			50, 0, 0, 0, 0, 0, 0, 1, 2, 3, 30, 75, 0, 0, 0, 0, 0, 0, 1, 6,
			12, 36, 100, 0, 0, 0, 0, 0, 1, 3, 6, 19, 90, 720, 0, 0, 0, 0, 1,
			2, 4, 8, 20, 80, 1200, 0, 0, 0, 1, 2, 3, 5, 10, 30, 600, 1800 };

		result = arrayQueficient[spots - 2][match - 1] * bet;
	}
	return result;
}

VolumeButton& Game::getVolumeButton()
{
	return m_volumeButton;
}

void Game::payTableAnimation(SDL_Renderer* renderer)
{
	SDL_Rect payTableRect = {PAYTABLE_BOTTOM_LEFT.x,
		PAYTABLE_TOP_RIGHT.y, PAYTABLE_WIDTH,
		PAYTABLE_HEIGHT};
	if(mGrid.numberOfHits() > 0)
	{
		for (int i = 1; i < 9; i++)
		{
			if (i % 2 != 0)
			{  
				SDL_SetRenderDrawColor(renderer, LIME.r, LIME.g,
						LIME.b, 150);
				SDL_RenderFillRect(renderer, 
						&m_PayTable.getLines()
						[mGrid.numberOfHits()-1]);
				m_PayTable.reApplyLine(renderer, 
						mGrid.numberOfHits(),
						mGrid.numbersClicked(),
						m_bet);
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, RED.r, RED.g,
						RED.b, 150);
				SDL_RenderFillRect(renderer, 
						&m_PayTable.getLines()
						[mGrid.numberOfHits()-1]);
				m_PayTable.reApplyLine(renderer, 
						mGrid.numberOfHits(),
						mGrid.numbersClicked(),
						m_bet);
			}
			SDL_RenderPresent(renderer);
			int timeout = SDL_GetTicks() + HALF_SECOND_MS;
			while(!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {}
		}
	}
	//Returns pay table to normal condition
	cropFromRenderTo(renderer, &payTableRect, &payTableRect);
	m_PayTable.renderPayTable(renderer, 0, m_bet);
}

void Game::reRenderBetButton(SDL_Renderer* renderer)
{
	SDL_Rect tempRect = {470, 510, 120, 100};
	cropFromRenderTo(renderer, &tempRect, &tempRect);	
	//Render bet button
	mBetButton.buttonCondition(mGrid.numbersClicked(), getBet());
	mBetButton.renderButton(renderer);

	//Render bet text
	mBetButton.betText(renderer);
}

void Game::reRenderHistory(SDL_Renderer* renderer)
{
	SDL_Rect tempRect = {HISTORY_X, HISTORY_Y, HISTORY_WIDTH, HISTORY_HEIGHT};
	cropFromRenderTo(renderer, &tempRect, &tempRect);	
	//Render history button
	m_History.renderHistory(renderer);
}



void Game::loadGameOverScreen(SDL_Renderer* renderer)
{
	if (m_creditInGame.getGameCredit() == 0)
	{
		m_winInGame.writeOnScreen(renderer);
	}
}

void Game::gameButtonsChunk()
{
	m_chunk = Mix_LoadWAV("Resources/Sounds/button-click-version-sound-effect-13.mp3");
	if(m_chunk == NULL)
	{
		std::cerr << "Could not load music chunk!" << std::endl;
	}
	Mix_PlayChannel(-1, m_chunk, 0);
}

void Game::showBonusLogo(SDL_Renderer* renderer)
{
	SDL_Rect rectToCrop;
	for(int i = -120; i < 350; i += 3)
	{
		rectToCrop = {570, i, extraBonusLogo_width,extraBonusLogo_height};

		m_bonusInGame.getExtraBonusLogo().setPosition(570, i, extraBonusLogo_width, extraBonusLogo_height);
		m_bonusInGame.getExtraBonusLogo().render(renderer,m_bonusInGame.getExtraBonusLogo().getKRect());

		SDL_RenderPresent(renderer);
		cropFromRenderTo(renderer, &rectToCrop, &rectToCrop);
	}

}


void Game::resetVariables()
{
	m_creditInGame.setGameCredit(0);
	setBonus(0);
	getBonusInGame().setBonus(0);
	getWinInGame().setWinCredits(0);
	m_bet = 0;	
	mGrid.resetFlags();
	m_Recovery.write(getBet(), m_creditInGame.getGameCredit(),
			getBonus(),
			mGrid.getClickedNumbers(),
			m_minBetFlag, m_maxBetFlag, m_setBetFlag);
}


XML& Game::getXML()
{
	return m_Recovery;
}

void Game::setMinBetFlag(bool flag)
{
	m_minBetFlag = flag;
}


bool Game::getMinBetFlag()
{
	return m_minBetFlag;
}

void Game::setMaxBetFlag(bool flag)
{
	m_maxBetFlag = flag;
}


bool Game::getMaxBetFlag()
{
	return m_maxBetFlag;
}

void Game::setSetBetFlag(bool flag)
{
	m_setBetFlag = flag;
}


bool Game::getSetBetFlag()
{
	return m_setBetFlag;
}
