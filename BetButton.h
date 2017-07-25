#ifndef BETBUTTON_H_
#define BETBUTTON_H_
#include "BaseObject.h"
#include "Font.h"

class BetButton: public BaseObject
{
	public:
		//Constructor
		BetButton();

		//Render bet text
		void betText(SDL_Renderer*);

		//Condition to make bet button clickable
		bool buttonCondition(int);

		//Render
		void renderButton(SDL_Renderer*);
		
		//Get font
		Font& getFont();
	private:
		//Font composition
		Font m_font;
};

#endif
