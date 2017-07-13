/*
 * Win.h
 *
 *  Created on: Jul 11, 2017
 *      Author: Memmory Of Tomorrow
 */

#ifndef WIN_H_
#define WIN_H_

#include "BaseObject.h"
#include "Font.h"
#include <boost/lexical_cast.hpp>

class Win: public BaseObject{
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
	std::string floatToString(float var);

};

#endif /* WIN_H_ */
