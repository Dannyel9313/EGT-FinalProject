/*
 * GameKeno.cpp
 *
 *  Created on: 05.07.2017
 *      Author: Danny
 */
#include <iostream>
#include "GameKeno.h"

GameKeno::GameKeno() {
	// TODO Auto-generated constructor stub

}

GameKeno::~GameKeno() {
	// TODO Auto-generated destructor stub
}


                              // Game initializing ...
bool GameKeno::init() {
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "can not init video" << std::endl;
		success = false;
	} else {
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			std::cerr << "linear structure is not enable" << std::endl;
			success = false;
		} else {
			kenoWindow = SDL_CreateWindow("Keno", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height,
					SDL_WINDOW_SHOWN);
			if (kenoWindow == NULL) {
				std::cerr << "The window can not be created !" << std::endl;
				success = false;
			} else {
				kenoRenderer = SDL_CreateRenderer(kenoWindow, -1,
						SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
				if (kenoRenderer == NULL) {
					std::cerr << "Renderer can not be created !" << std::endl;
					success = false;
				} else {

					SDL_SetRenderDrawColor(kenoRenderer, 0xFF, 0xFF, 0xFF,
							0xFF);
					if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
						std::cerr << "The audio can not be initialized !"
								<< std::endl;
						success = false;
					} else {
						if (TTF_Init() == -1) {
							std::cerr << "Problem with initializing TTF !"
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

// Loading media
bool GameKeno::loadMedia() {
	bool success = true;
//
//	m_backgroundTxture = loadTexture("chessTable.png");
//	if (m_backgroundTxture == NULL) {
//		std::cerr << "Problem with loading background !" << std::endl;
//		success = false;
//	}
//	m_figuresTexture = loadTexture("chesFigures.png");
//	if (m_figuresTexture == NULL) {
//		std::cerr << "Problem with loading figures !" << std::endl;
//		success = false;
//	}
//	m_buttonTexture = loadTexture("buttonPlay.png");
//	if (m_buttonTexture == NULL) {
//		std::cerr << "Problem with loading buttons !" << std::endl;
//		success = false;
//	}
//	m_pushedButtonTexture = loadTexture("buttonPause.png");
//	if (m_pushedButtonTexture == NULL) {
//		std::cerr << "Problem with loading buttons !" << std::endl;
//		success = false;
//	}
//	mySong = Mix_LoadMUS("Anymood Live  Terasz 2013.09.16.mp3");
//	if (mySong == NULL) {
//		std::cerr << "Problem with loading music !" << std::endl;
//		success = false;
//	}
////	font = TTF_OpenFont("lazy.ttf",80);
////	if(font == NULL)
////	{
////		std::cerr << "Font can not be load !" << std::endl;
////	}else
////	{
////		SDL_Color textColor = {32,255,49};
////		LoadFromRenderedText("Push BUTTON or press SPACE to start !!!",textColor);
////	}



	return success;
}

//
void GameKeno::close() {
//	SDL_DestroyTexture(m_buttonTexture);
//	SDL_DestroyTexture(m_figuresTexture);
//	SDL_DestroyTexture(m_backgroundTxture);
//	m_buttonTexture = NULL;
//	m_figuresTexture = NULL;
//	m_buttonTexture = NULL;
////	TTF_CloseFont(font);
////	font = NULL;
//	Mix_FreeMusic(mySong);
//	mySong = NULL;

	SDL_DestroyRenderer(kenoRenderer);
	kenoRenderer = NULL;

	SDL_DestroyWindow(kenoWindow);
	kenoWindow = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

}

