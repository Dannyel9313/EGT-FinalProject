#include "Include.h"
#include "BaseObject.h"
#include "GameKeno.h"
#include "XML.h"

int main(int argc, char* args[]) 
{
	bool quit = false;

	XML xml;
	GameKeno game;
	SDL_Event e;

	bool introMode = true;
	bool gameMode = false;
	bool infoMode = false;
	bool recoveryMode = false;
	bool outroMode = false;
	bool controlGameFlag = false;
	bool controlInfoFlag = false;



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
			//game.getIntroMode().introScreenPresent(game.getKenoRenderer(),game.getGameMode().
        	  	       //getXML().getCredits());
			while (!quit)
			{

				if (introMode)
				{
					game.getIntroMode().introScreenPresent(game.getKenoRenderer(),game.getGameMode().
                	  	       getXML().getCredits());
				}


				if(introMode)
				{
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
							game.getIntroMode().startNewGameClicked(&gameMode,&controlGameFlag,&introMode,&infoMode, e);
							game.getIntroMode().startInfoClicked(&infoMode,&controlInfoFlag,&introMode, e);
                                                        //If resume game clicked

                                                        game.getIntroMode().resumeGameClicked
                                                                (&gameMode, &controlGameFlag, &introMode,
                                                                        &recoveryMode,&infoMode, e,game.getGameMode().
                                                         	  	       getXML().getCredits());
							game.getIntroMode().introButtonsChunk(e);
						}
					}
				}

				if(gameMode == true  && controlGameFlag == true)  
				{
				        //Initialize game state
                       	 	        game.getGameMode().initializeGameState();
                       	 	        game.getGameMode().resetVariables();

					game.getGameMode().getCreditInGame().
						setGameCredit(game.getIntroMode().
						getInsertCredit().getCredit());
					
					game.getGameMode().renderGame(game.getKenoRenderer(), 255);
					quit = false;
				}

				if(gameMode)
				{
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
							game.getGameMode().cashOutButtonPushed(&outroMode, &gameMode, e);	
                                      		}
						else if (e.type == SDL_MOUSEMOTION)
						{
							game.getGameMode().mouseOnButtonRender(game.getKenoRenderer(), e);
						}

					}
				}

			
				else if(recoveryMode && game.getGameMode().
                                         	       getXML().getCredits() > 0)  
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
					game.getGameMode().setMinBetFlag(game.getGameMode().getXML().
						getMinBetFlag());
					game.getGameMode().setMaxBetFlag(game.getGameMode().getXML().
						getMaxBetFlag());
					game.getGameMode().setSetBetFlag(game.getGameMode().getXML().
						getSetBetFlag());
		
					game.getGameMode().renderGame(game.getKenoRenderer(), 255);
					game.getGameMode().reRenderMinimalBet(game.getKenoRenderer(), game.getGameMode().getBet());
					game.getGameMode().reRenderMaximalBet(game.getKenoRenderer(), game.getGameMode().getBet());

					recoveryMode = false;
					gameMode = true;
					controlGameFlag = true;
					quit = false;
				}
							

				else if(recoveryMode && game.getGameMode().
						getXML().getCredits() <= 0)
				{
					introMode = true;
					recoveryMode = false;
				}

				if(infoMode && controlInfoFlag)
				{
					game.getInfoMode().renderInfoScreen(game.getKenoRenderer());
					quit = false;
				}
			if(infoMode)
			{
				while(SDL_PollEvent(&e) != 0)
				{
					if(e.type == SDL_QUIT)
					{
						quit = true;
					}
					else if(e.type == SDL_MOUSEBUTTONDOWN)
					{
						game.getInfoMode().renderButtonDown(game.getKenoRenderer(), e);
						game.getInfoMode().buttonReturn(&introMode,& infoMode, e);
					}else if(e.type == SDL_MOUSEMOTION)
					{
						game.getInfoMode().renderOnMauseOver(game.getKenoRenderer(), e);
					}
				}
			}
				if(game.getGameMode().isGameOverFlag() == true)
				{
				gameMode = false;
				Mix_PauseMusic();
				game.getGameMode().getWinInGame().writeOnScreen(game.getKenoRenderer());
				game.getIntroMode().getInsertCredit().setCredit(0);
				Mix_ResumeMusic();
				introMode = true;
				}


				if (outroMode)
				{
					game.getOutroMode().writingOnScreen(game.getKenoRenderer(), game.getGameMode().
						calculateCreditsInMoney());
					introMode = true;
					game.getGameMode().resetVariables();
					game.getIntroMode().getInsertCredit().setCredit(0);
					//Read recovery
					game.getGameMode().getXML().read("Recovery.xml");
				}
				SDL_RenderPresent(game.getKenoRenderer());
				controlGameFlag = false;
				controlInfoFlag = false;
				outroMode = false;
				recoveryMode = false;

				game.getGameMode().setGameOverFlag(false);
			}
		}
	}
	return 0;
}
