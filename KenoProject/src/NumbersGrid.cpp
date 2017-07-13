#include "NumbersGrid.h"

NumbersGrid::NumbersGrid()
{
	//TODO NULL FONT, SOUND EFFECT
	setPosition(numbersGrid_x, numbersGrid_y);
	setDimensions(numbersGrid_width, numbersGrid_height);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			isClickedFlags[i][j] = 0;
			randomNumbersFlags[i][j] = 0;
			numberOfHitsFlags[i][j] = 0;
		}
	}
}

void NumbersGrid::createRects(SDL_Renderer * renderer, int alpha)
{
	int xPos = getKRect()->x, yPos = getKRect()->y;
	SDL_Rect tempRect = {xPos, yPos, numbersRect_width, numbersRect_height};
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//Set new rect
			m_numbers[i][j] = tempRect;

			roundedBoxRGBA(renderer, 
				m_numbers[i][j].x, 
				m_numbers[i][j].y, 
				m_numbers[i][j].x+numbersRect_width, 
				m_numbers[i][j].y+numbersRect_height, 
				5, 225, 16, 16, alpha);

			//Set new position
			xPos += numbersRect_width + 2;
			tempRect.x = xPos;
		}
		xPos = getKRect()->x;
		yPos += numbersRect_height + 3;
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
	m_font = TTF_OpenFont("Resources/Fonts/AUDI.TTF", numbersText_size);
	TTF_SetFontStyle(m_font, TTF_STYLE_BOLD);
}

void NumbersGrid::numbersInRects(SDL_Renderer * renderer)
{
	SDL_Rect dst_rect = {0, 0, 0, 0};
	SDL_Color white = {255, 255, 255};
	int number = 1;
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 10; j++)
		{
			//1-digit numbers require specific spacing
			if(number < 10) 
			{
				//Set the destination rect
				dst_rect.x = m_numbers[i][j].x+oneDigit_xIndent;
				dst_rect.y = m_numbers[i][j].y+oneDigit_yIndent;	
				dst_rect.w = numbers_width;	
				dst_rect.h = numbers_height;

				//Load text from font
				loadTextureFromTTF(toStringPlusSpace(number), 
					renderer, m_font, white);
				
				//Render
				render(renderer, &dst_rect);  
				
			}
			else 
			{
				//Set destination rect	
				dst_rect.x = m_numbers[i][j].x+twoDigit_xIndent;
				dst_rect.y = m_numbers[i][j].y+twoDigit_yIndent;	
				dst_rect.w = numbers_width;	
				dst_rect.h = numbers_height;

				//Load number from font
				loadTextureFromTTF(toString(number), renderer, m_font, white);

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
				isClicked(e, &m_numbers[i][j]) 
				&& numbersClicked() < 10) 
			{
				//Draw and fill rect
				isClickedFlags[i][j] = 1;
				roundedBoxRGBA(renderer, 
				m_numbers[i][j].x, 
				m_numbers[i][j].y, 
				m_numbers[i][j].x+numbersRect_width, 
				m_numbers[i][j].y+numbersRect_height, 
				5, 200, 200, 0, 255);

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
					m_numbers[i][j].x+numbersRect_width,
					m_numbers[i][j].y+numbersRect_height, 
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

void NumbersGrid::pickRandomNumbers(SDL_Renderer* renderer, 
					const SDL_Event& e)
{
	int rand_1;
	int rand_2;
	for (int i = 0; i < 20; i++)
	{
		rand_1 = rand()%8;
		rand_2 = rand()%10;
		if (randomNumbersFlags[rand_1][rand_2] == 0) 
		{
			randomNumbersFlags[rand_1][rand_2] = 1;
		}
		//If already flag up increase loop by 1 time
		else	
		{
			i--;
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
				numberOfHitsFlags[i][j] = 1;
				count++;
			}
		}
	}
	return count;		
}

int NumbersGrid::numbersClicked()
{
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			sum += isClickedFlags[i][j];
		}
	}
	return sum;
}

void NumbersGrid::reRenderClickedNumbers(SDL_Renderer* renderer, int alpha)
{
	createRects(renderer, alpha);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if(isClickedFlags[i][j]==1)
			{
				roundedBoxRGBA(renderer,
					m_numbers[i][j].x, 
					m_numbers[i][j].y,
					m_numbers[i][j].x+numbersRect_width,
					m_numbers[i][j].y+numbersRect_height, 
					5, 200, 200, 0, alpha);	
				//Reapply numbers in rects
				numbersInRects(renderer);
			}
		}
	}
}

void NumbersGrid::blinkingSuccessHits(SDL_Renderer* renderer)
{
	reRenderClickedNumbers(renderer, 50);
	renderRandomNumbers(renderer);
	numberOfHits();	
	int flag = 0;
	for (int k = 0; k < 8; k++) 
	{
		int timeout = SDL_GetTicks() + oneSecond;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if(numberOfHitsFlags[i][j] == 1)
				{
					if(flag == 0)
					{
						roundedBoxRGBA(renderer,
							m_numbers[i][j].x, 
							m_numbers[i][j].y,
							m_numbers[i][j].x+numbersRect_width,
							m_numbers[i][j].y+numbersRect_height, 
							5, 225, 16, 16, 255);
						//Reapply numbers in rects
						numbersInRects(renderer);
					}
					else if (flag == 1)
					{
						roundedBoxRGBA(renderer,
							m_numbers[i][j].x, 
							m_numbers[i][j].y,
							m_numbers[i][j].x+numbersRect_width,
							m_numbers[i][j].y+numbersRect_height, 
							5, 200, 200, 0, 255);
						//Reapply numbers in rects
						numbersInRects(renderer);
					}
				}
			}
		}
		if (flag == 0) 
		{
			flag = 1;
		}
		else if (flag == 1)
		{
			flag = 0;
		}
		SDL_RenderPresent(renderer);	
		while(!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {};
	}	
}

void NumbersGrid::renderRandomNumbers(SDL_Renderer* renderer)
{	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if(randomNumbersFlags[i][j] == 1)
			{
				//Draw diagonal lines
				if(filledCircleRGBA(renderer, 
					m_numbers[i][j].x+circle_xIndent,
					m_numbers[i][j].y+circle_yIndent,
					radiusOfCircle, 0, 0, 0, 255)!=0) 
				{
					std::cout << "Error drawing circle" 
						<< std::endl;
				}
			}
		}
	}
}
