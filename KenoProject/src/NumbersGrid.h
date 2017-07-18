#ifndef NUMBERSGRID_H_
#define NUMBERSGRID_H_
#include "Include.h"
#include "BaseObject.h"

class NumbersGrid: public BaseObject 
{
	public:
		NumbersGrid();
	
		void createRects(SDL_Renderer*, int);
		void setNumbersGridRect(int x, int y, int w, int h);		

		//Function load TFF
		void loadTTF();

		//Change color if clicked
		void doIfClicked(SDL_Renderer*, const SDL_Event&);

		void pickRandomNumbers(SDL_Renderer*, const SDL_Event&);

		void pickTenRandNumbersOnBoard(SDL_Renderer* renderer, const SDL_Event& e);

		void resetRandFlags();

		//Loads clicking sound effect
		bool loadSoundEffect(std::string);

		//Number of hits
		int numberOfHits();

		//How many numbers are clicked
		int numbersClicked();

		void pickRandomChoices(SDL_Renderer* renderer);

		//Re-render rect
		void reRenderClickedNumbers(SDL_Renderer*, int);

		//Blinking successful hits
		void blinkingSuccessHits(SDL_Renderer*);

		//Render random numbers
		void renderRandomNumbers(SDL_Renderer*);

		//Reset
		void resetNumbersGrid(SDL_Renderer*);

		//Reset all glags
		void resetFlags();

		//Get random numbers
		int* getRandomNumbers();

		//Get number rects
		SDL_Rect* getNumberRects();

		//Render background of numbersGrid;
		void renderBackground(SDL_Renderer*);

		//Load numbers in rectangles
		void printNumbers(SDL_Renderer*);

		void printSpecificNumber(SDL_Renderer*, int);



	private:
		const char* toString(int);

		SDL_Rect m_numbers[8][10];
		TTF_Font* m_font;
		int isClickedFlags[8][10];
		int randomNumbersFlags[8][10];
		int numberOfHitsFlags[8][10];

		//Variable for sound effect
		Mix_Chunk* m_ClickEffect;

};

#endif
