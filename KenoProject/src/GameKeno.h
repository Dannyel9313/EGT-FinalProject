
#ifndef GAMEKENO_H_
#define GAMEKENO_H_
#include "Include.h"
#include "Globals.h"
#include "IntroScreen.h"

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



	private:
		//Window
		SDL_Window* kenoWindow;

		//Renderer
		SDL_Renderer* kenoRenderer;

		//intro mode
		IntroScreen m_introMode;
};

#endif /* GAMEKENO_H_ */
