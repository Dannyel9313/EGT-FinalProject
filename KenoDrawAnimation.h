#ifndef KENODRAWANIMATION_H_
#define KENODRAWANIMATION_H_
#include "BaseObject.h"
#include "Font.h"

class KenoDrawAnimation: public BaseObject
{
	public:
		void drawPipe(SDL_Renderer*);
		void dropBalls(SDL_Renderer*, int, int, int, int, int);
		void loadTextures(SDL_Renderer*);
	private:
		BaseObject horizontalPipe;
		BaseObject topRightPipe;
		Font m_font;
		
};

#endif
