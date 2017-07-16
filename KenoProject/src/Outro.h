/*
 * Outro.h
 *
 *  Created on: 8.07.2017 ã.
 *      Author: ddada
 */

#ifndef OUTRO_H_
#define OUTRO_H_
#include <stdio.h>
#include <string>
#include "BaseObject.h"

class Outro: public BaseObject
{
public:
	Outro();
	virtual ~Outro();
	void loadFromTTF();
	void winingWindow(SDL_Renderer *);
	void writingOnScreen(SDL_Renderer *,double);
	BaseObject& getBackground();
	void setBackground(const BaseObject& back);
	BaseObject& getWinPic();
	void setWinPic(const BaseObject& win);

private:

	TTF_Font *  font;
	BaseObject background;
	BaseObject winPic;
	std::string doubleToString(double);
};

#endif /* OUTRO_H_ */
