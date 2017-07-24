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
	bool controlGameFlag = false;
	bool controlInfoFlag = false;

	int x, y;

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

			Mix_PlayMusic(game.getMainMusic(),-1);
			Mix_VolumeMusic(game.getIntroMode().getVolume().getVolumePoint());
			game.getIntroMode().loadIntroScreen(game.getKenoRenderer());
			game.getIntroMode().introScreenPresent(game.getKenoRenderer());
			while (!quit)
			{
				 if (introMode)
					{
						game.getIntroMode().introScreenPresent(game.getKenoRenderer());
					}





				if(introMode){
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
						game.getIntroMode().startNewGameClicked(&gameMode,&controlGameFlag,&introMode, e);
						game.getIntroMode().startInfoClicked(&infoMode,&controlInfoFlag,&introMode, e);
						game.getIntroMode().introButtonsChunk(e);
					}
				}
				}
			if(gameMode == true  && controlGameFlag == true)
			{
			        //Initialize game state
                                game.getGameMode().initializeGameState();

				game.getGameMode().getCreditInGame().setGameCredit(game.getIntroMode().getInsertCredit().getCredit());
				game.getGameMode().renderGame(game.getKenoRenderer(), 255);


				quit = false;
			}

			if(gameMode){
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
						SDL_GetMouseState(&x, &y);
						std::cout << "X: " << x << " " << "Y: " << y << std::endl;
                                        }
					else if (e.type == SDL_MOUSEMOTION)
					{
						game.getGameMode().mouseOnButtonRender(game.getKenoRenderer(), e);
					}

			}
			}

			if(infoMode && controlInfoFlag)
			{
				game.getInfoMode().renderInfoScreen(game.getKenoRenderer());
				quit = false;
			}

				while(SDL_PollEvent(&e) != 0)
				{
					if(e.type == SDL_QUIT)
					{
						quit = true;
					}
					if(e.type == SDL_MOUSEBUTTONDOWN){
						game.getInfoMode().renderButtonDown(game.getKenoRenderer(), e);
						game.getInfoMode().buttonReturn(&introMode, e);
						std::cout << introMode << "<-" << std::endl;
					}
				}
				SDL_RenderPresent(game.getKenoRenderer());
				controlGameFlag = false;
				controlInfoFlag = false;
			}
		}
	}
//	game.close();
	return 0;
}
