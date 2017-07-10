#include "NumbersGrid.h"

NumbersGrid::NumbersGrid()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			isClickedFlags[i][j] = 0;
			randomNumbersFlags[i][j] = 0;
		}
	}
}

void NumbersGrid::createRects(SDL_Renderer * renderer)
{
	int xPos = getKRect().x, yPos = getKRect().y;
	SDL_Rect tempRect = {xPos, yPos, 30, 40};
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//Set new rect
			m_numbers[i][j] = tempRect;

			roundedBoxRGBA(renderer, m_numbers[i][j].x, m_numbers[i][j].y, m_numbers[i][j].x+40, m_numbers[i][j].y+30, 5, 
				225, 16, 16, 255);

			//Set new position
			xPos += 42;
			tempRect.x = xPos;
		}
		xPos = getKRect().x;
		yPos += 32;
		tempRect.y = yPos;
		tempRect.x = xPos;
	}
	numbersInRects(renderer);
}

void NumbersGrid::setNumbersGridRect(int x, int y, int w, int h)
{
	setPosition(x, y);
	setDimensions(w, h);
}

void NumbersGrid::loadTTF()
{
	m_font = TTF_OpenFont("AUDI.TTF", 24);
	TTF_SetFontStyle(m_font, TTF_STYLE_BOLD);
}

void NumbersGrid::numbersInRects(SDL_Renderer * renderer)
{
	SDL_Rect dst_rect = {0, 0, 0, 0};
	SDL_Color white = {255, 255, 255};
	SDL_Color black = {0, 0, 0};
	int number = 1;
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 10; j++)
		{
			if(number < 10) 
			{
				dst_rect.x = m_numbers[i][j].x+13;
				dst_rect.y = m_numbers[i][j].y+5;	
				dst_rect.w = 24;	
				dst_rect.h = 22;
				TTF_SetFontOutline(m_font, 0);
				loadTextureFromTTF(toStringPlusSpace(number), renderer, m_font, white);
				render(renderer, &dst_rect);  
				TTF_SetFontOutline(m_font, 1);
				loadTextureFromTTF(toStringPlusSpace(number), renderer, m_font, black);
				render(renderer, &dst_rect); 
			}
			else 
			{	
				dst_rect.x = m_numbers[i][j].x+9;
				dst_rect.y = m_numbers[i][j].y+5;	
				dst_rect.w = 24;	
				dst_rect.h = 22;
				TTF_SetFontOutline(m_font, 0);
				loadTextureFromTTF(toString(number), renderer, m_font, white);
				render(renderer, &dst_rect);  
				TTF_SetFontOutline(m_font, 1);
				loadTextureFromTTF(toString(number), renderer, m_font, black);
				render(renderer, &dst_rect); 
			}
			number++;			
		}
	}	
}

void NumbersGrid::changeColorIfClicked(SDL_Renderer * renderer, const SDL_Event & e) 
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if(isClicked(e, &m_numbers[i][j]) && isClickedFlags[i][j] == 0)
			{
				//Draw and fill rect
				isClickedFlags[i][j] = 1;
				roundedBoxRGBA(renderer, m_numbers[i][j].x, m_numbers[i][j].y, m_numbers[i][j].x+40, m_numbers[i][j].y+30, 5, 
					255, 255, 0, 255);
				numbersInRects(renderer);
			}
			else if (isClicked(e, &m_numbers[i][j]) && isClickedFlags[i][j] == 1)
			{
				//Draw and fill rect
				isClickedFlags[i][j] = 0;
				roundedBoxRGBA(renderer, m_numbers[i][j].x, m_numbers[i][j].y, m_numbers[i][j].x+40, m_numbers[i][j].y+30, 5, 
					225, 16, 16, 255);
				numbersInRects(renderer);
			}	
		}
	}
}

const char * NumbersGrid::toString(int in_val)
{
	std::string str = boost::lexical_cast<std::string> (in_val);
	return str.c_str();
}


const char * NumbersGrid::toStringPlusSpace(int in_val)
{
	std::string str = boost::lexical_cast<std::string> (in_val);
	str = str + ' ';
	return str.c_str();
}

void NumbersGrid::pickRandomNumbers(SDL_Renderer * renderer, const SDL_Event & e)
{
	SDL_Rect rect = {0, 0, 30, 30};
	int r1;
	int r2;
	if (isClicked(e, &rect))
	{
		createRects(renderer);
		resetRandFlags();
		for (int i = 0; i < 10; i++)
		{
			r1 = rand()%8;
			r2 = rand()%10;
			if (randomNumbersFlags[r1][r2] == 0) 
			{
				randomNumbersFlags[r1][r2] = 1;
				thickLineRGBA (renderer, m_numbers[r1][r2].x, m_numbers[r1][r2].y+28,
					 m_numbers[r1][r2].x+38, m_numbers[r1][r2].y, 3, 0, 0, 0, 50);
				thickLineRGBA (renderer, m_numbers[r1][r2].x, m_numbers[r1][r2].y,
					 m_numbers[r1][r2].x+38, m_numbers[r1][r2].y+28, 3, 0, 0, 0, 50);
			}
			else	
			{
				i--;
			}			
		}
	}
}

void NumbersGrid::resetRandFlags()
{	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			randomNumbersFlags[i][j] = 0;
		}
	}
}
