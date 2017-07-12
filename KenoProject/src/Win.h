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

class Win: public BaseObject{
public:
	Win();
	virtual ~Win();

	void writeOnScreen(SDL_Renderer*);
private:
	Font f;
	std::string StringToDouble();
};

#endif /* WIN_H_ */