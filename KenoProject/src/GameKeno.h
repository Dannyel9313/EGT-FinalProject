
#ifndef GAMEKENO_H_
#define GAMEKENO_H_
#include "Include.h"
#include "Globals.h"
#include "IntroScreen.h"
#include "Info.h"

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
		void setKenoWindow(SDL_Window *);

		//Set keno renderer
		void setKenoRenderer(SDL_Renderer *);

		//Get keno window
		SDL_Window * getKenoWindow();

		//Get keno renderer
		SDL_Renderer * getKenoRenderer();

		//Get intro mode
		IntroScreen& getIntroMode();

		//Get info mode
		Info& getInfoMode();

	private:
		// Window
		SDL_Window* kenoWindow;

		// Renderer
		SDL_Renderer* kenoRenderer;

		// Intro mode
		IntroScreen m_introMode;

		// Info mode
		Info m_InfoMode;
};

#endif /* GAMEKENO_H_ */
