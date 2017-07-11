#ifndef NUMBERSGRID_H_
#define NUMBERSGRID_H_
#include "Include.h"
#include "BaseObject.h"

class NumbersGrid: public BaseObject 
{
	public:
		NumbersGrid();
	
		void createRects(SDL_Renderer *);
		void setNumbersGridRect(int x, int y, int w, int h);		

		//Function load TFF
		void loadTTF();

		//Do something if clicked
		void doIfClicked(SDL_Renderer *, const SDL_Event &);

		void pickRandomNumbers(SDL_Renderer *, const SDL_Event &);

		void resetRandFlags();

		//Loads clicking sound effect
		bool loadSoundEffect(std:string);

		//Number of hits
		int numberOfHits();
	private:
		//Utility function load numbers in rectangles
		void numbersInRects(SDL_Renderer *);

		const char * toString(int);
		const char * toStringPlusSpace(int);

		SDL_Rect m_numbers[8][10];
		TTF_Font * m_font;
		int isClickedFlags[8][10];
		int randomNumbersFlags[8][10];

		//Sound effect structure
		Mix_Chunk* m_ClickEffect;
};

#endif
