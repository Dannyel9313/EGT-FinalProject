/*
 * Bonus.h
 *
 *  Created on: 8.07.2017 ã.
 *      Author: ddada
 */

#ifndef BONUS_H_
#define BONUS_H_
#include"Game.h"

#include "BaseObject.h"

class Bonus: public BaseObject {
public:
	Bonus();
	virtual ~Bonus();
	void addBonusPercent(double );

private:


};

#endif /* BONUS_H_ */
