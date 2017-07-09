#include <iostream>
#include "GameKeno.h"

GameKeno::GameKeno() 
{
	this->kenoWindow = NULL;
	this->kenoRenderer = NULL;
}

GameKeno::~GameKeno() {}

// Game initializing ...
bool GameKeno::init() 
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		std::cerr << "Could not init video" << std::endl;
		success = false;
	} 
	else 
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) 
		{
			std::cerr << "Linear texture filtering is not enabled" << std::endl;
		} 
		else 
		{
			kenoWindow = SDL_CreateWindow("Keno", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
					SDL_WINDOW_SHOWN);
			if (kenoWindow == NULL) 
			{
				std::cerr << "The window could not be created !" << std::endl;
				success = false;
			} 
			else {
				kenoRenderer = SDL_CreateRenderer(kenoWindow, -1,
						SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
				if (kenoRenderer == NULL) 
				{
					std::cerr << "Renderer could not be created !" << std::endl;
					success = false;
				} 
				else {
					SDL_SetRenderDrawColor(kenoRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
					if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) 
					{
						std::cerr << "The audio can not be initialized !"
								<< std::endl;
						success = false;
					} 
					else 
					{
						if (TTF_Init() == -1) 
						{
							std::cerr << "Failed to initialize TTF !"
									<< std::endl;
							success = false;
						}
					}
				}
			}
		}
	}
	return success;
}

//Loading media
bool GameKeno::loadMedia() 
{
	bool success = true;
	return success;
}

//Free resources
void GameKeno::close() 
{
	SDL_DestroyRenderer(kenoRenderer);
	kenoRenderer = NULL;

	SDL_DestroyWindow(kenoWindow);
	kenoWindow = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	//TODO free music
}

SDL_Window * GameKeno::getKenoWindow() 
{
	return this->kenoWindow;
}

SDL_Renderer * GameKeno::getKenoRenderer() 
{
	return this->kenoRenderer;
}

Game & GameKeno::getGame() 
{
	return gameMode;
}
