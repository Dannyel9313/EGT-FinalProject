#ifndef HISTORY_H_
#define HISTORY_H_
#include "BaseObject.h"
#include "Font.h"
#include "Globals.h"

class History: public BaseObject
{
	public:
		static int currentRound;
	
		void renderHistory(SDL_Renderer*);
		void renderRoundText(SDL_Renderer*);
		void renderHitsText(SDL_Renderer*);
		void setRoundRects();
		void setHitsRects();
		void renderRounds(SDL_Renderer*);
		void renderHits(SDL_Renderer*, int, int);
		Font& getFont();

		std::string toString(int);
	private:
		Font m_text;
		SDL_Rect round;
		SDL_Rect hits;
		std::vector <SDL_Rect> roundsRects;
		std::vector <SDL_Rect> hitsRects;
		std::vector <int> saveHits;
};

#endif

