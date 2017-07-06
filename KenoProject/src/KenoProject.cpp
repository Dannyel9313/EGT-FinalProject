//============================================================================
// Name        : KenoProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include "BaseObject.h"
#include "GameKeno.h"
using namespace std;

int main(int argc, char* args[]) {

	bool quit = false;
	GameKeno game;
	SDL_Event e;
	BaseObject introScreen;

	if (!game.init()) {
		cerr << "Problem with initializing" << endl;
	} else {
		if (!game.loadMedia()) {
		} else {
			while (!quit) {
				while (SDL_PollEvent(&e) != 0) {
					if (e.type == SDL_QUIT) {
						quit = true;
					}
					SDL_SetRenderDrawColor(game.kenoRenderer, 255, 255, 255,
							255);
					SDL_RenderClear(game.kenoRenderer);
					introScreen.setColor(255, 16, 100);
					SDL_RenderCopy(game.kenoRenderer, introScreen.getKTexture(),
					NULL, introScreen.getKRect());
				}

				SDL_RenderPresent(game.kenoRenderer);
			}

		}
	}

return 0;
}
