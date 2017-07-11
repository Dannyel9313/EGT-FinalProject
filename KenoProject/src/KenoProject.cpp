#include "Include.h"
#include "BaseObject.h"
#include "GameKeno.h"

int main(int argc, char* args[]) {
	bool quit = false;

	GameKeno game;
	SDL_Event e;
	bool introMode = true;

	if (!game.init()) {
		std::cerr << "Problem with initializing" << std::endl;
	} else {
		if (!game.loadMedia()) {
			std::cerr << "Error loading media" << std::endl;
		} else {
			SDL_SetRenderDrawColor(game.getKenoRenderer(), 255, 255, 255, 255);
			SDL_RenderClear(game.getKenoRenderer());

//			game.getIntroMode().loadIntroScreen(game.getKenoRenderer());
			int x,y;
			while (!quit) {
				while (SDL_PollEvent(&e) != 0) {
					if (e.type == SDL_QUIT) {
						quit = true;
					}
//					game.getIntroMode().getVolume().moveVolumeDot(&e);
//					game.getIntroMode().getInsertCredit().setCreditToGame(&e);
					SDL_GetMouseState(&x,&y);

					std::cout << "x -> " << x << " y -> " << y << std::endl;




				}

				if (introMode) {

				}
				game.getInfoMode().loadInfoScreen(game.getKenoRenderer());
//				game.getIntroMode().introScreenPresent(game.getKenoRenderer());
				SDL_RenderPresent(game.getKenoRenderer());
				introMode = false;
			}
		}
	}
	game.close();
	return 0;
}
