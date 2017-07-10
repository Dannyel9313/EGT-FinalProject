#include "Include.h"
#include "BaseObject.h"
#include "GameKeno.h"


int main(int argc, char* args[]) 
{
	bool quit = false;

	GameKeno game;
	SDL_Event e;
	bool introMode = true;
	

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
			SDL_SetRenderDrawColor(game.getKenoRenderer(),255,255,255,255);
			SDL_RenderClear(game.getKenoRenderer());
			while (!quit) 
			{
				while (SDL_PollEvent(&e) != 0) 
				{
					if (e.type == SDL_QUIT) 
					{
						quit = true;
					}
					int x,y;
					if(e.type == SDL_MOUSEBUTTONDOWN)
					{
						SDL_GetMouseState(&x,&y);
						std::cout << "x -> " << x << " y -> " << y << std::endl;
					}

				}

if(introMode == true)
{
				game.getIntroMode().loadButtonFont(game.getKenoRenderer());
}
//game.getIntroMode().setButtonsPositionDimension(game.getKenoRenderer());

//SDL_RenderCopy(game.getKenoRenderer(),game.getIntroMode().getResumeGameButton().getKTexture(),NULL,
//		game.getIntroMode().getResumeGameButton().getKRect());
				SDL_RenderPresent(game.getKenoRenderer());
introMode = false;
			}
		}
	}
	game.close();
	return 0;
}
