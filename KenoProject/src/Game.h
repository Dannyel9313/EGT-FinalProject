#ifndef GAME_H_
#define GAME_H_
#include "BaseObject.h"
#include "NumbersGrid.h"

class Game: public BaseObject
{
	public:
		//Get Number grid
		NumbersGrid & getNumbersGrid();
	private:
		NumbersGrid mGrid;
	//	History mHistory;
};

#endif
