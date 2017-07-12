#ifndef BETBUTTON_H_
#define BETBUTTON_H_
#include "BaseObject.h"
#include "Font.h"

class BetButton: public BaseObject
{
	public:
		BetButton();
		void betText(SDL_Renderer*);
		//Condition to make bet button clickable
		bool buttonCondition(int, SDL_Renderer*);
		
		Font& getFont();
	private:
		Font m_font;
};

#endif
