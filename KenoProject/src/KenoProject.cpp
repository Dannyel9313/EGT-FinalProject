#include "Include.h"
#include "BaseObject.h"
#include "GameKeno.h"
#include "XML.h"

enum gameState
{
	IntroMode,
	InfoMode,
	GameMode,
	RecoveryMode,
	OutroMode
};

int main(int argc, char* args[]) 
{
	bool quit = false;

	XML xml;
	GameKeno game;
	SDL_Event e;
	bool infoFlag = false;
	bool gameFlag = false;

	gameState state = IntroMode;

	if (!game.init()) 
	{
		std::cerr << "Problem with initializing" << std::endl;
	} 
	else 
	{
		if (!game.loadMedia()) 
		{
			std::cerr << "Error loading media" << std::endl;
		} 
		else 
		{
			SDL_RenderClear(game.getKenoRenderer());

			//Read recovery
			game.getGameMode().getXML().read("Recovery.xml");

			Mix_PlayMusic(game.getMainMusic(),-1);
			Mix_VolumeMusic(game.getIntroMode().getVolume().getVolumePoint());
			game.getIntroMode().loadIntroScreen(game.getKenoRenderer(),game.getGameMode().
					getXML().getCredits());
			while (!quit)
			{
				switch (state)
				{
					case IntroMode:
						game.getIntroMode().introScreenPresent(game.getKenoRenderer(),game.getGameMode().
								getXML().getCredits());
						while (SDL_PollEvent(&e) != 0) 
						{
							if (e.type == SDL_QUIT) 
							{
								quit = true;
							}
							else if (e.type == SDL_MOUSEBUTTONDOWN)
							{
								game.getIntroMode().getVolume().moveVolumeDot(&e);
								game.getIntroMode().getInsertCredit().setCreditToGame(&e);
								game.getGameMode().getCreditInGame().
									setGameCredit(game.getIntroMode().
									getInsertCredit().getCredit());
								if (game.getIntroMode().startNewGameClicked(e))
								{
									state = GameMode;
								}
								else if (game.getIntroMode().startInfoClicked(e))
								{
									state = InfoMode;
								}
								else if (game.getIntroMode().resumeGameClicked
										(e,game.getGameMode().
										 getXML().getCredits()))
								{
									state = RecoveryMode;
								}
								game.getIntroMode().introButtonsChunk(e);
							}
						}
						gameFlag = 0;
						break;
					case GameMode:
						if (gameFlag == 0)
						{
							//Initialize game state
							game.getGameMode().initializeGameState();
							game.getGameMode().renderGame(game.getKenoRenderer(), 255);
						}
						while(SDL_PollEvent(&e) != 0)
						{
							if(e.type == SDL_QUIT)
							{
								quit = true;
							}
							else if (e.type == SDL_MOUSEBUTTONDOWN)
							{
								game.getGameMode().changeColorOfClickedNumbers(game.getKenoRenderer(), e);
								game.getGameMode().mouseButtonDownRender(game.getKenoRenderer(), e);
								game.getGameMode().playPauseMusic(game.getKenoRenderer(), e, game.getMainMusic());
								if (game.getGameMode().cashOutButtonPushed(e))
								{
									state = OutroMode;
								}
							}
							else if (e.type == SDL_MOUSEMOTION)
							{
								game.getGameMode().mouseOnButtonRender(game.getKenoRenderer(), e);
							}
						}
						if(game.getGameMode().getCreditInGame().getGameCredit() == 0)
						{
							Mix_PauseMusic();
							game.getGameMode().getWinInGame().writeOnScreen(game.getKenoRenderer());
							game.getIntroMode().getInsertCredit().setCredit(0);
							Mix_ResumeMusic();

							//Set state to intro mode
							state = IntroMode;
						}
						gameFlag = 1;
						break;
					case RecoveryMode:
						if(game.getGameMode().getXML().getCredits() > 0)
						{
							//Read recovery
							game.getGameMode().getXML().read("Recovery.xml");

							//Initialize game state
							game.getGameMode().initializeGameState();

							//Set recovery values
							game.getGameMode().getCreditInGame().
								setGameCredit(game.getGameMode().
										getXML().getCredits());
							game.getGameMode().getNumbersGrid().
								raiseClickedFlags(game.getGameMode().
										getXML().getUserChoices());
							game.getGameMode().getBonusInGame().setBonus
								(game.getGameMode().getXML().getBonus());
							game.getGameMode().setBonus(game.getGameMode().getXML().
									getBonus());
							game.getGameMode().setBet(game.getGameMode().getXML().
									getBet());
							game.getGameMode().getMinBetButton().setMinimalBet(game.getGameMode().getXML().
									getBet());
							game.getGameMode().getMaxBetButton().setMaximalBet(game.getGameMode().getXML().
									getBet());
							game.getGameMode().setMinBetFlag(game.getGameMode().getXML().
									getMinBetFlag());
							game.getGameMode().setMaxBetFlag(game.getGameMode().getXML().
									getMaxBetFlag());
							game.getGameMode().setSetBetFlag(game.getGameMode().getXML().
									getSetBetFlag());

							game.getGameMode().renderGame(game.getKenoRenderer(), 255);
							game.getGameMode().reRenderMinimalBet(game.getKenoRenderer(), game.getGameMode().getBet());
							game.getGameMode().reRenderMaximalBet(game.getKenoRenderer(), game.getGameMode().getBet());

							state = GameMode;
						}
						else 
						{
							state = IntroMode;
						}
						break;
					case InfoMode:
						if (infoFlag == 0)
						{
							game.getInfoMode().renderInfoScreen(game.getKenoRenderer());
						}
						while(SDL_PollEvent(&e) != 0)
						{
							if(e.type == SDL_QUIT)
							{
								quit = true;
							}
							else if(e.type == SDL_MOUSEBUTTONDOWN)
							{
								if(game.getInfoMode().buttonReturn(e))
								{
									state = IntroMode;
								}
								game.getInfoMode().renderButtonDown(game.getKenoRenderer(), e);
							}
							else if(e.type == SDL_MOUSEMOTION)
							{
								game.getInfoMode().renderOnMauseOver(game.getKenoRenderer(), e);
							}
						}
						infoFlag = 1;
						break;
					case OutroMode:
						game.getOutroMode().writingOnScreen(game.getKenoRenderer(), game.getGameMode().
								calculateCreditsInMoney());
						game.getGameMode().resetVariables();
						game.getIntroMode().getInsertCredit().setCredit(0);
						//Read recovery
						game.getGameMode().getXML().read("Recovery.xml");

						//Set state to intro mode
						state = IntroMode;
						break;
				}
				SDL_RenderPresent(game.getKenoRenderer());
			}
		}
	}
	return 0;
}
