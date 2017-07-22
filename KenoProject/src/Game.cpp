#include "Game.h"

Game::Game() :
		m_minBetFlag(true), m_maxBetFlag(true), m_setBetFlag(false), m_bonusFlag(false), m_bet(0) {
}

Game::~Game()
 {
 	Mix_FreeChunk(m_chunk);
 	m_chunk = NULL;
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

	//Render pay table
	m_PayTable.renderPayTable(renderer, 0, 0);

	m_DrawAnimation.loadTextures(renderer);
	m_DrawAnimation.drawPipe(renderer);

	m_bonusInGame.renderBonus(renderer);


}

void Game::mouseButtonDownRender(SDL_Renderer* renderer, const SDL_Event& e)
{
	if (m_creditInGame.getGameCredit() >= m_bet && m_bet != 0)
	{
		//If button condition true show random numbers
		if (mBetButton.buttonCondition(mGrid.numbersClicked())) 
		{
			mBetButton.renderButton(renderer);
			mBetButton.betText(renderer);
			if (mBetButton.isClicked(e, mBetButton.getKRect())) 
			{

				gameButtonsChunk();

				m_bonusInGame.showBonus(renderer,calculateBonus(getBet()));
				//Pick 10 random numbers
				changeCreditOnClickingBet(renderer, e);

				mGrid.pickRandomNumbers(renderer, e);

//				drawAnimation(renderer, mGrid.getRandomNumbers(),
//						mGrid.getNumberRects());

				// Render game after animation
				renderAfterAnimationGame(renderer,150);


				mGrid.reRenderClickedNumbers(renderer, 50);

				mGrid.numberOfHits();

				showWinInGame(renderer);
				bonusToCredits(mGrid.numberOfHits(), renderer);

				m_History.renderHits(renderer, mGrid.numberOfHits(), 0);

				mGrid.renderRandomNumbers(renderer);

				mGrid.printNumbers(renderer);

				mGrid.blinkingSuccessHits(renderer);

				payTableAnimation(renderer);

				if(m_bonusFlag == true)
				{
					showBonusLogo(renderer);

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

				if(m_bonusFlag == true){
				m_creditInGame.renderCreditsInGame(renderer);
				m_bonusInGame.renderBonus(renderer);
				m_bonusFlag = false;
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
		gameButtonsChunk();
		SDL_Rect payTableRect = {PAYTABLE_BOTTOM_LEFT.x,
				PAYTABLE_TOP_RIGHT.y, PAYTABLE_WIDTH,
					PAYTABLE_HEIGHT};
		cropFromRenderTo(renderer, &payTableRect, &payTableRect);
		m_PayTable.renderPayTable(renderer, 0, m_bet);
		mGrid.resetNumbersGrid(renderer);
		m_minBetButton.renderMinBet(renderer);
		m_maxBetButton.renderMaxBet(renderer);
		setBet(0);
		m_minBetFlag = true;
		m_maxBetFlag = true;
		m_setBetFlag = false;
	}

	//Re render bet button
	reRenderBetButton(renderer);
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

void Game::drawAnimation(SDL_Renderer* renderer, int* numbers,
		SDL_Rect* rects)
{
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

void Game::showWinInGame(SDL_Renderer* renderer)
{
	int winResult = 0;

	m_winInGame.setWinCredits(
			calculateWin(mGrid.numbersClicked(), mGrid.numberOfHits(), m_bet));
	m_winInGame.renderWinInGame(renderer);

	winResult = m_winInGame.getWinCredits() + m_creditInGame.getGameCredit();

	m_creditInGame.setGameCredit(winResult);
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
	reRenderHistory(renderer);	

//	m_PayTable.renderPayTable(renderer);
//	m_PayTable.renderHitsText(renderer);

	m_DrawAnimation.loadTextures(renderer);
	m_DrawAnimation.drawPipe(renderer);
}

double Game::calculateCreditsInMoney(int credits)
{

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
	std::cout << "Bonus ->" << getBonus() << std::endl;
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
	std::cout << match << " match" << std::endl;
	int tempBonus = 0;
	int resultDenom = 0;
	if(match > 2)
	{

	tempBonus = m_bonus * 10;

	resultDenom = tempBonus % 10;

	std::cout << resultDenom << "poslednaCifra" << std::endl;
	if(resultDenom > 5)
	{
		bonus = m_bonus + 1;
		std::cout<< "bonusa za setvane v ifa" << bonus <<std::endl;
	}
	else
	{
		bonus = m_bonus;
		std::cout << "bonusa za setvane izvyn ifa" << bonus << std::endl;
	}
	setBonus(0);

		std::cout << getBonus() << "bonus after null" << std::endl;
	m_creditInGame.setGameCredit((m_creditInGame.getGameCredit() + bonus));

	std::cout << "credits after bonus ->" << m_creditInGame.getGameCredit() << std::endl;

	m_bonusFlag = true;

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
		gameButtonsChunk();
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
			gameButtonsChunk();
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
	mBetButton.buttonCondition(mGrid.numbersClicked());
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

void Game::loadBigWinScreen(SDL_Renderer* renderer, int spots, int match, int bet)
  {

  	if(calculateWin(spots, match, bet) > 0)
  	{
  		if(match == 10)
  		{

 		m_winInGame.bigWin(renderer, 1000);
  		}
  	}
  }

void Game::loadWinScreen(SDL_Renderer* renderer, int spots, int match, int bet)
{
 	if (calculateWin(spots, match, bet) > 0)
 	{
 		m_winInGame.writeOnScreen(renderer, 100);
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
	for(int i = 0; i < 350; i += 5 )
	{

rectToCrop = {570, i, extraBonusLogo_width,extraBonusLogo_height};

		m_bonusInGame.getExtraBonusLogo().setPosition(570, i, extraBonusLogo_width, extraBonusLogo_height);
		m_bonusInGame.getExtraBonusLogo().render(renderer,m_bonusInGame.getExtraBonusLogo().getKRect());

		SDL_RenderPresent(renderer);
		cropFromRenderTo(renderer, &rectToCrop, &rectToCrop);

	}





}
