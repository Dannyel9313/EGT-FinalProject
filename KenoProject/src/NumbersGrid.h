#ifndef NUMBERSGRID_H_
#define NUMBERSGRID_H_
#include "Include.h"
#include "BaseObject.h"

class NumbersGrid: public BaseObject 
{
	public:
		NumbersGrid();
		~NumbersGrid();
	
		//Създава триъгълниците с помощта на gfx
		void createRects(SDL_Renderer*, int);
	
		//Задава позицията и размерите на нъмбър грид
		void setNumbersGridRect(int x, int y, int w, int h);		

		//Load numbers in rectangles
		void printNumbers(SDL_Renderer*);

		//Function load TFF
		void loadTTF();

		//Change color if clicked
		bool doIfClicked(SDL_Renderer*, const SDL_Event&);

		//Raise the flag of 10 numbers to be clicked
		void pickRandomChoices(SDL_Renderer*);

		void pickRandomNumbers(SDL_Renderer*);

		void resetRandFlags();

		//Loads clicking sound effect
		bool loadSoundEffect(std::string);

		//Number of hits
		int numberOfHits();

		//How many numbers are clicked
		int numbersClicked();

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

		//Reset isClickedFlags
		void resetIsClicked();

		//Get random numbers
		std::vector <bool>& getRandomNumbers();

		//Get number rects
		SDL_Rect* getNumberRects();

		//Render background of numbersGrid;
		void renderBackground(SDL_Renderer*);

		//Print only specific numbers
		void printSpecificNumber(SDL_Renderer*, int);

		//Get clicked numbers
		std::vector <bool>& getClickedNumbers();

		//Raise clicked flags
		void raiseClickedFlags(const std::vector <bool>&);
	private:
		const char* toString(int);

		SDL_Rect m_numbers[80];
		TTF_Font* m_font;
		std::vector <bool> isClickedFlags;
		std::vector <bool> randomNumbersFlags;
		std::vector <bool> numberOfHitsFlags;

		//Variable for sound effect
		Mix_Chunk* m_ClickEffect;

};

#endif
