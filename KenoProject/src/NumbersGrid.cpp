#include "NumbersGrid.h"

void NumbersGrid::createRects(SDL_Renderer * renderer)
{
	int xPos = getKRect().x, yPos = getKRect().y;
	SDL_Rect tempRect = {xPos, yPos, 20, 20};
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//Set new rect
			m_numbers[i][j] = tempRect;

			//Draw and fill rect
			SDL_SetRenderDrawColor(renderer, 225, 16, 16, 255);
			SDL_RenderFillRect(renderer, &m_numbers[i][j]);

			//Set new position
			xPos += 25;
			tempRect.x = xPos;
		}
		xPos = getKRect().x;
		yPos += 25;
		tempRect.y = yPos;
		tempRect.x = xPos;
	}
}

void NumbersGrid::setNumbersGridRect(int x, int y, int w, int h)
{
	setPosition(x, y);
	setDimensions(w, h);
}
