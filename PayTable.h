#ifndef PAYTABLE_H_
#define PAYTABLE_H_
#include "BaseObject.h"
#include "Font.h"

class PayTable: public BaseObject
{
	public:
		void renderPayTable(SDL_Renderer*, int, int);
		void renderHitsText(SDL_Renderer*);
		void renderPayText(SDL_Renderer*);
		void setHitsRects();
		void setPayRects();

		//Divide the history box into 9 lines
		void setLines();
		
		//Get lines
		const std::vector <SDL_Rect>& getLines();

		void renderHits(SDL_Renderer*, int);
		void renderPay(SDL_Renderer*, int, int);
		
		//Reapply specific line
		void reApplyLine(SDL_Renderer*, int, int, int);

		Font& getFont();
	private:
		Font m_text;
		std::vector <SDL_Rect> hitsRects;
		std::vector <SDL_Rect> paysRects;
		std::vector <SDL_Rect> lines;
};

#endif
