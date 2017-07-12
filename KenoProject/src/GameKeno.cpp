#include <iostream>
#include "GameKeno.h"

GameKeno::GameKeno() {
	this->kenoWindow = NULL;
	this->kenoRenderer = NULL;
}

GameKeno::~GameKeno() {
}

// Game initializing ...
bool GameKeno::init() {
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		std::cerr << "Could not init video" << std::endl;
		success = false;
	} else {
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			std::cerr << "Linear texture filtering is not enabled" << std::endl;
		} else {
			kenoWindow = SDL_CreateWindow("Keno", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
					SDL_WINDOW_SHOWN);
			if (kenoWindow == NULL) {
				std::cerr << "The window could not be created !" << std::endl;
				success = false;
			} else {
				kenoRenderer = SDL_CreateRenderer(kenoWindow, -1,
						SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
				if (kenoRenderer == NULL) {
					std::cerr << "Renderer could not be created !" << std::endl;
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
bool GameKeno::loadMedia() {
	bool success = true;

//		m_introMode.getBackground().loadTexture("IntroKenoImage2.png",kenoRenderer);
//
//		m_introMode.getStartNewGameButton().setFont(TTF_OpenFont("Pozo.ttf",50));
//		m_introMode.getResumeGameButton().setFont(TTF_OpenFont("Pozo.ttf",50));
//		m_introMode.getInsertCredit().setFont(TTF_OpenFont("Pozo.ttf",50));
//		m_introMode.getInfoButton().setFont(TTF_OpenFont("Pozo.ttf",50));
//		m_introMode.getVolumeButton().setFont(TTF_OpenFont("Pozo.ttf",50));
//
//		m_introMode.getStartNewGameButton().LoadFromRenderedText("START GAME",kenoRenderer,
//				m_introMode.getStartNewGameButton().setButtonColor(255,255,255));
//		m_introMode.getResumeGameButton().LoadFromRenderedText("RESUME GAME",kenoRenderer,
//				m_introMode.getResumeGameButton().setButtonColor(255,255,255));

        m_GameMode.loadTextureFromFile("mini.jpg", kenoRenderer);

        //Load clicking effect on number grid
        m_GameMode.getNumbersGrid().loadSoundEffect("floop2_x.wav");

        //Loads ttf for number grid
        m_GameMode.getNumbersGrid().loadTTF();

        m_GameMode.getBetButton().loadTextureFromFile("BetButton.png", kenoRenderer);

        TTF_Font* betButtonFont = TTF_OpenFont("AUDI.TTF", 24);
        m_GameMode.getBetButton().getFont().setFont(betButtonFont);

	return success;
}

//Free resources
void GameKeno::close() {
	TTF_CloseFont(m_introMode.getStartNewGameButton().getFont());
	TTF_CloseFont(m_introMode.getResumeGameButton().getFont());
	TTF_CloseFont(m_introMode.getInfoButton().getFont());
	TTF_CloseFont(m_introMode.getVolume().getFontPlus().getFont());
	TTF_CloseFont(m_introMode.getVolume().getFontVolume().getFont());
	TTF_CloseFont(m_introMode.getVolume().getFontMinus().getFont());
	TTF_CloseFont(m_introMode.getInsertCredit().getFontPlus().getFont());
	TTF_CloseFont(m_introMode.getInsertCredit().getFontMinus().getFont());
	TTF_CloseFont(
			m_introMode.getInsertCredit().getFontInsertCredit().getFont());

	SDL_DestroyTexture(m_introMode.getBackground().getKTexture());
	SDL_DestroyTexture(
			m_introMode.getInsertCredit().getFontCreditRect().getKTexture());
	SDL_DestroyTexture(m_introMode.getVolume().getFontDot().getKTexture());
	SDL_DestroyTexture(m_introMode.getVolume().getFontDotLine().getKTexture());

	Mix_FreeMusic(m_introMode.getIntroSong());
	m_introMode.getIntroSong() = NULL;

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

void GameKeno::setKenoWindow(SDL_Window * window) {
	this->kenoWindow = window;
}

void GameKeno::setKenoRenderer(SDL_Renderer * renderer) {
	this->kenoRenderer = renderer;
}

SDL_Window * GameKeno::getKenoWindow() {
	return this->kenoWindow;
}

SDL_Renderer * GameKeno::getKenoRenderer() {
	return this->kenoRenderer;
}

IntroScreen& GameKeno::getIntroMode() {
	return m_introMode;
}

Info& GameKeno::getInfoMode() {
	return m_InfoMode;
}

Game& GameKeno::getGameMode()
{
        return m_GameMode;
}

