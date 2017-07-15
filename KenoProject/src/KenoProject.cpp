#include "Include.h"
#include "BaseObject.h"
#include "GameKeno.h"

int main(int argc, char* args[]) {
	bool quit = false;

	GameKeno game;
	SDL_Event e;

	bool introMode = true;
	bool gameMode = false;
	bool infoMode = false;

	if (!game.init()) {
		std::cerr << "Problem with initializing" << std::endl;
	} else {
		if (!game.loadMedia()) {
			std::cerr << "Error loading media" << std::endl;
		} else {
			SDL_SetRenderDrawColor(game.getKenoRenderer(), 255, 255, 255, 255);
			SDL_RenderClear(game.getKenoRenderer());
//			game.getGameMode().getBackground().backgroundPresent(game.getKenoRenderer());
			game.getGameMode().renderGame(game.getKenoRenderer(), e);
//			game.getInfoMode().renderInfoScreen(game.getKenoRenderer());
//			game.getIntroMode().loadIntroScreen(game.getKenoRenderer());
			while (!quit && introMode == 1) 
			{
				while (SDL_PollEvent(&e) != 0) 
				{
					if (e.type == SDL_QUIT) 
					{
						quit = true;
					}

					game.getGameMode().renderGame(game.getKenoRenderer(),e);
					int x,y;
					if(e.type == SDL_MOUSEBUTTONDOWN){
					SDL_GetMouseState(&x,&y);


				std::cout << "X->" << x << "  Y->" << y << std::endl;
					}
//					game.getIntroMode().getVolume().moveVolumeDot(&e);
//					game.getIntroMode().getInsertCredit().setCreditToGame(&e);
//					game.getIntroMode().startNewGameClicked(&gameMode, e);
//					game.getIntroMode().startInfoClicked(&infoMode, e);
				}
//				if (gameMode || infoMode)
//				{
//					introMode = false;
//				}
//				else if (introMode)
//				{
//					game.getIntroMode().introScreenPresent(game.getKenoRenderer());
//				}

				SDL_RenderPresent(game.getKenoRenderer());
			}
//			if(gameMode)
//			{

//			}
//			while (!quit && gameMode == 1)
//			{
//				while(SDL_PollEvent(&e) != 0)
//				{
//					if(e.type == SDL_QUIT)
//					{
//						quit = true;
//					}
//					else if (e.type == SDL_MOUSEBUTTONDOWN)
//                                        {
//                                                game.getGameMode().getNumbersGrid().doIfClicked(game.getKenoRenderer(), e);
//                                                game.getGameMode().renderGame(game.getKenoRenderer(), e);
//                                        }
//				}
//				SDL_RenderPresent(game.getKenoRenderer());
//			}
//			if(infoMode){
//				game.getInfoMode().renderInfoScreen(game.getKenoRenderer());
//				SDL_RenderPresent(game.getKenoRenderer());
//			}
//			while (!quit && infoMode == 1)
//						{
//							while(SDL_PollEvent(&e) != 0)
//							{
//								if(e.type == SDL_QUIT)
//								{
//									quit = true;
//								}
//								else if (e.type == SDL_MOUSEBUTTONDOWN)
//			                                        {
//									if(infoMode){
//												game.getInfoMode().renderInfoScreen(game.getKenoRenderer());
//												SDL_RenderPresent(game.getKenoRenderer());
//											}
//			                                        }
//							}
//							SDL_RenderPresent(game.getKenoRenderer());
//						}
		}
	}
//	game.close();
	return 0;
}
