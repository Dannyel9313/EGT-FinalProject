
#ifndef GAMEKENO_H_
#define GAMEKENO_H_
#include "Include.h"
#include "Globals.h"
#include "IntroScreen.h"
#include "Info.h"
#include "Game.h"
#include "Outro.h"

class GameKeno 
{
	public:
		//Constructor
		GameKeno();

		//Destructor
		virtual ~GameKeno();

		//Initialize SDL
		bool init();

		//Load media
		bool loadMedia();
		
		//Free resources
		void close();
		
		//Set keno window
		void setKenoWindow(SDL_Window*);

		//Set keno renderer
		void setKenoRenderer(SDL_Renderer*);

		//Get keno window
		SDL_Window* getKenoWindow();

		//Get keno renderer
		SDL_Renderer* getKenoRenderer();

		//Get intro mode
		IntroScreen& getIntroMode();

		//Get info mode
		Info& getInfoMode();

		//Get game mode
		Game& getGameMode();

		//Get outro mode
		Outro& getOutroMode();

		// Get music
		Mix_Music*& getMainMusic();

	private:
		//Window
		SDL_Window* kenoWindow;

		//Renderer
		SDL_Renderer* kenoRenderer;

		Mix_Music* m_mainMusic;

		//Intro mode
		IntroScreen m_introMode;

		//Info mode
		Info m_InfoMode;

		//Game mode
		Game m_GameMode;

		//Outro mode
		Outro m_outroMode;
};

#endif /* GAMEKENO_H_ */
