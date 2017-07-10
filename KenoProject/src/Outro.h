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
	void setWinningMoney(double);
	int getWinningMoney();
	void winingWindow(SDL_Renderer *);
	void writingOnScreen(SDL_Renderer *);
private:
	double winningMoney;

};

#endif /* OUTRO_H_ */
