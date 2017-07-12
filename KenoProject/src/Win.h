#ifndef WIN_H_
#define WIN_H_

#include "BaseObject.h"
#include "Font.h"

class Win: public BaseObject
{
	public:
		Win();
		virtual ~Win();
	
		void writeOnScreen(SDL_Renderer*);
	private:
		Font firstText;
      	 	Font secondText;
      		Font thirdText;
       		Font fourthText;
        	Font fifthText;
		BaseObject mBackground;
		std::string StringToDouble();
};

#endif /* WIN_H_ */
