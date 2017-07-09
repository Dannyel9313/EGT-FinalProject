#ifndef NUMBERSGRID_H_
#define NUMBERSGRID_H_
#include "Include.h"
#include "BaseObject.h"

class NumbersGrid: public BaseObject 
{
	public:
		void createRects(SDL_Renderer *);
		void setNumbersGridRect(int x, int y, int w, int h);		
	private:
		SDL_Rect m_numbers[8][10];
};

#endif
