#include "Include.h"
#include "BaseObject.h"
#include "GameKeno.h"
#include "XML.h"

int main(int argc, char* args[]) 
{
	bool quit = false;

	GameKeno game;
	SDL_Event e;
	
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
			while (!quit) 
			{
				while (SDL_PollEvent(&e) != 0) 
				{
					if (e.type == SDL_QUIT) 
					{
						quit = true;
					}
					SDL_RenderClear(game.getKenoRenderer());
				}
				SDL_RenderPresent(game.getKenoRenderer());
			}
		}
	}
	return 0;
}
