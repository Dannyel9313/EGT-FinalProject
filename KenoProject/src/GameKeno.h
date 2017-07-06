/*
 * GameKeno.h
 *
 *  Created on: 05.07.2017
 *      Author: Danny
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "Globals.h"
#ifndef GAMEKENO_H_
#define GAMEKENO_H_


class GameKeno {
public:

	SDL_Window* kenoWindow = NULL;
	SDL_Renderer* kenoRenderer = NULL;


	GameKeno();
	virtual ~GameKeno();

	bool init();
	bool loadMedia();
	void close();


private:
};

#endif /* GAMEKENO_H_ */
