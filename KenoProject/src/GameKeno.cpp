#include <iostream>
#include "GameKeno.h"

GameKeno::GameKeno() 
{
	this->kenoWindow = NULL;
	this->kenoRenderer = NULL;
	this->m_mainMusic = NULL;
}

GameKeno::~GameKeno() 
{
}

// Game initializing ...
bool GameKeno::init() 
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) 
	{
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
			else 
			{
				kenoRenderer = SDL_CreateRenderer(kenoWindow, -1,
						SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
				if (kenoRenderer == NULL) 
				{
					std::cerr << "Renderer could not be created !" << std::endl;
					success = false;
				} 
				else 
				{
					SDL_SetRenderDrawColor(kenoRenderer, 0xFF, 0xFF, 0xFF,
							0xFF);
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


        m_GameMode.loadTextureFromFile("Resources/Images/LasVegas.jpg", kenoRenderer);

        //Load clicking effect on number grid
        m_GameMode.getNumbersGrid().loadSoundEffect("Resources/Sounds/floop2_x.wav");

        //Loads ttf for number grid
        m_GameMode.getNumbersGrid().loadTTF();

        m_GameMode.getBetButton().loadTextureFromFile("Resources/Images/BetButton.png", kenoRenderer);

        TTF_Font* betButtonFont = TTF_OpenFont("Resources/Fonts/AUDI.TTF", 24);
        m_GameMode.getBetButton().getFont().setFont(betButtonFont);

	m_GameMode.getClearButton().getButtonClear().setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
//	m_GameMode.getDrawAnimation().loadChunkEffect("Resources/Sounds/corkPop.wav");
//	m_GameMode.getDrawAnimation().loadChunkEffect("Resources/Sounds/blop.wav");
	
	//Load pay table media
	m_GameMode.getPayTable().getFont().setFont(TTF_OpenFont("Resources/Fonts/AUDI.TTF", 24));

	//Load history table media
	m_GameMode.getHistory().getFont().setFont(TTF_OpenFont("Resources/Fonts/AUDI.TTF", 24));

	// Load music media
	m_mainMusic = Mix_LoadMUS("Resources/Sounds/Casino-Instrumental-Patzmarzbelts-Collections-HD.mp3");
	if(m_mainMusic == NULL)
	 	{
	 		std::cerr << "Could not load music file!" << std::endl;
	 	}
	return success;
}

//Free resources
void GameKeno::close() 
{
	Mix_FreeMusic(m_mainMusic);
	m_mainMusic = NULL;


	SDL_DestroyRenderer(kenoRenderer);
	kenoRenderer = NULL;

	SDL_DestroyWindow(kenoWindow);
	kenoWindow = NULL;

	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	//TODO free music
}

void GameKeno::setKenoWindow(SDL_Window* window) 
{
	this->kenoWindow = window;
}

void GameKeno::setKenoRenderer(SDL_Renderer* renderer) 
{
	this->kenoRenderer = renderer;
}

SDL_Window* GameKeno::getKenoWindow() 
{
	return this->kenoWindow;
}

SDL_Renderer* GameKeno::getKenoRenderer() 
{
	return this->kenoRenderer;
}

IntroScreen& GameKeno::getIntroMode() 
{
	return m_introMode;
}

Info& GameKeno::getInfoMode() 
{
	return m_InfoMode;
}

Game& GameKeno::getGameMode()
{
        return m_GameMode;
}

Outro& GameKeno::getOutroMode(){
	return m_outroMode;
}

Mix_Music*& GameKeno::getMainMusic(){
	return m_mainMusic;
}
