#include "NumbersGrid.h"

NumbersGrid::NumbersGrid()
{
	//TODO NULL FONT, SOUND EFFECT
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
	SDL_Rect tempRect = {xPos, yPos, 40, 30};
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//Set new rect
			m_numbers[i][j] = tempRect;

			roundedBoxRGBA(renderer, 
				m_numbers[i][j].x, 
				m_numbers[i][j].y, 
				m_numbers[i][j].x+40, 
				m_numbers[i][j].y+30, 
				5, 225, 16, 16, 255);

			//Set new position
			xPos += 42;
			tempRect.x = xPos;
		}
		xPos = getKRect().x;
		yPos += 33;
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
			//1-digit numbers require specific spacing
			if(number < 10) 
			{
				//Set the destination rect
				dst_rect.x = m_numbers[i][j].x+13;
				dst_rect.y = m_numbers[i][j].y+5;	
				dst_rect.w = 24;	
				dst_rect.h = 22;

				//Sets outline to no outline
				TTF_SetFontOutline(m_font, 0);

				//Load text from font
				loadTextureFromTTF(toStringPlusSpace(number), 
					renderer, m_font, white);
				
				//Render
				render(renderer, &dst_rect);  
				
				//Sets outline to 1
				TTF_SetFontOutline(m_font, 1);

				//Load text from font for outline
				loadTextureFromTTF(toStringPlusSpace(number), 
					renderer, m_font, black);
				
				//Render
				render(renderer, &dst_rect); 
			}
			else 
			{
				//Set destination rect	
				dst_rect.x = m_numbers[i][j].x+9;
				dst_rect.y = m_numbers[i][j].y+5;	
				dst_rect.w = 24;	
				dst_rect.h = 22;

				//Set outline to no outline
				TTF_SetFontOutline(m_font, 0);

				//Load number from font
				loadTextureFromTTF(toString(number), renderer, m_font, white);

				//Render
				render(renderer, &dst_rect);  

				//Set outline to 1
				TTF_SetFontOutline(m_font, 1);

				//Load number from font
				loadTextureFromTTF(toString(number), renderer, m_font, black);

				//Render
				render(renderer, &dst_rect); 
			}
			number++;			
		}
	}	
}

void NumbersGrid::doIfClicked(SDL_Renderer * renderer, const SDL_Event & e) 
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if(isClickedFlags[i][j] == 0 && 
				isClicked(e, &m_numbers[i][j])) 
			{
				//Draw and fill rect
				isClickedFlags[i][j] = 1;
				roundedBoxRGBA(renderer, 
					m_numbers[i][j].x, 
					m_numbers[i][j].y, 
					m_numbers[i][j].x+40,
					m_numbers[i][j].y+30, 
					5, 255, 255, 0, 255);

				//Reapply numbers in rects
				numbersInRects(renderer);

				//Play sound effect
				Mix_PlayChannel(-1, m_ClickEffect, 0);
			}
			else if (isClickedFlags[i][j] == 1 && 
					isClicked(e, &m_numbers[i][j]))
			{
				//Draw and fill rect
				isClickedFlags[i][j] = 0;
				roundedBoxRGBA(renderer,
					m_numbers[i][j].x, 
					m_numbers[i][j].y,
					m_numbers[i][j].x+40,
					m_numbers[i][j].y+30, 
					5, 225, 16, 16, 255);

				//Reapply numbers in rects
				numbersInRects(renderer);

				//Play sound effect	
				Mix_PlayChannel(-1, m_ClickEffect, 0);
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

void NumbersGrid::pickRandomNumbers(SDL_Renderer * renderer, 
					const SDL_Event & e)
{
	SDL_Rect rect = {0, 0, 30, 30};
	int rand_1;
	int rand_2;
	if (isClicked(e, &rect))
	{
		resetRandFlags();
		for (int i = 0; i < 10; i++)
		{
			rand_1 = rand()%8;
			rand_2 = rand()%10;
			if (randomNumbersFlags[r1][r2] == 0) 
			{
				randomNumbersFlags[r1][r2] = 1;

				//Draw diagonal lines
				thickLineRGBA (renderer, 
					m_numbers[rand_1][rand_2].x,
					m_numbers[rand_1][rand_2].y+28,
					m_numbers[rand_1][rand_2].x+38,
					m_numbers[rand_1][rand_2].y, 
					3, 0, 0, 0, 50);

				thickLineRGBA (renderer, 
					m_numbers[rand_1][rand_2].x,
					m_numbers[rand_1][rand_2].y,
					m_numbers[rand_1][rand_2].x+38, 
					m_numbers[rand_1][rand_2].y+28,
					3, 0, 0, 0, 50);
			}
			//If already flag up increase loop by 1 time
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

bool NumbersGrid::loadSoundEffect(std::string path)
{
	bool success = true;	

	//Load effect from wav
	m_ClickEffect = Mix_LoadWAV(path.c_str());
	if (m_ClickEffect == NULL)
	{
		std::cout << "Error loading clicking effect" << std::endl;
		success = false;
	}

	return success;
}

int NumbersGrid::numberOfHits()
{
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (isClickedFlags[i][j] == 1 && 
				isClickedFlags[i][j] == randomNumbersFlags[i][j])
			{
				count++;
			}
		}
	}
	return count;		
}
