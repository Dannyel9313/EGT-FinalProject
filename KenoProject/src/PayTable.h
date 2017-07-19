#ifndef PAYTABLE_H_
#define PAYTABLE_H_
#include "BaseObject.h"
#include "Font.h"

class PayTable: public BaseObject
{
	public:
		void renderPayTable(SDL_Renderer*);
		void renderHitsText(SDL_Renderer*);
		void renderPayText(SDL_Renderer*);
		void setHitsRects();
		void setPayRects();
		void renderHits(SDL_Renderer*, int);
		void renderPay(SDL_Renderer*, int);
		Font& getFont();
	private:
		Font m_text;
		std::vector <SDL_Rect> hitsRects;
		std::vector <SDL_Rect> paysRects;
};

#endif
