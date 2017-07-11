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
			SDL_Color color = {255, 0, 19};
			game.getIntroMode().loadIntroScreen(game.getKenoRenderer());
			while (!quit) {
				while (SDL_PollEvent(&e) != 0) {
					if (e.type == SDL_QUIT) {
						quit = true;
					}
					int x, y;





//							SDL_RenderPresent(game.getKenoRenderer());
				}
//						std::cout << "x -> " << x << " y -> " << y << std::endl;
				if (introMode) {

				}
game.getIntroMode().introScreenPresent(game.getKenoRenderer());
//				if(game.getIntroMode().getInfoButton().isClicked(game.getIntroMode().getInfoButton().getKRect()))
//										{
//											//std::cout << "->" <<game.getIntroMode().getInfoButton().isClicked(game.getIntroMode().getInfoButton().getKRect())<< "<-" << std::endl;
//											game.getIntroMode().getInfoButton().setChangeButtonColor(255,0,39);
//											game.getIntroMode().getInfoButton().LoadFromRenderedText("INFO",game.getKenoRenderer(),game.getIntroMode().getInfoButton().getChangedButtonColor());
//											game.getIntroMode().introScreenPresent(game.getKenoRenderer());
//										}else{
//											game.getIntroMode().getInfoButton().setChangeButtonColor(255,255,255);
//																						game.getIntroMode().getInfoButton().LoadFromRenderedText("INFO",game.getKenoRenderer(),game.getIntroMode().getInfoButton().getChangedButtonColor());
//																						game.getIntroMode().introScreenPresent(game.getKenoRenderer());
//										}

//				SDL_RenderPresent(game.getKenoRenderer());
				introMode = false;
			}
		}
	}
	game.close();
	return 0;
}
