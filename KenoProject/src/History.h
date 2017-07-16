#ifndef HISTORY_H_
#define HISTORY_H_
#include "BaseObject.h"
#include "Font.h"
#include "Globals.h"

class History: public BaseObject
{
	public:
		static int currentRound;
		void printHistory(SDL_Renderer*);
		void printHits(SDL_Renderer*, int, int);
		void setRoundTable(SDL_Renderer*);
		void setHitsTable(SDL_Renderer*);
		std::string toString(int);
		void initializeHistory(SDL_Renderer*);
		void printRounds(SDL_Renderer*);
	private:
		Font historyText;
		SDL_Rect round;
		SDL_Rect hits;
		std::vector <SDL_Rect> roundLines;
		std::vector <SDL_Rect> hitLines;
		std::vector <int> saveHits;
};

#endif

