#include "NumbersGrid.h"

NumbersGrid::NumbersGrid()
{
	m_font = NULL;
	m_ClickEffect = NULL;
	setPosition(numbersGrid_x, numbersGrid_y);
	setDimensions(numbersGrid_width, numbersGrid_height);
	for (int i = 0; i < 80; i++)
	{
		randomNumbersFlags.push_back(false);
		isClickedFlags.push_back(false);
		numberOfHitsFlags.push_back(false);
	}
}

NumbersGrid::~NumbersGrid()
{
	if (m_font != NULL)
	{
		TTF_CloseFont(m_font);
		m_font = NULL;
	}
	if (m_ClickEffect != NULL)
	{
		Mix_FreeChunk(m_ClickEffect);
		m_ClickEffect = NULL;
	}
}

void NumbersGrid::renderBackground(SDL_Renderer* renderer)
{
	//Set background of rects
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 200);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_RenderFillRect(renderer, getKRect());
}

void NumbersGrid::createRects(SDL_Renderer* renderer, int alpha)
{
	int xPos = getKRect()->x, yPos = getKRect()->y;
	SDL_Rect tempRect = {xPos, yPos, numbersRect_width, numbersRect_height};
	for (int i = 0; i < 80; i++)
	{
		//Set new rect
		m_numbers[i] = tempRect;

		roundedBoxRGBA(renderer, 
				m_numbers[i].x, 
				m_numbers[i].y, 
				m_numbers[i].x+numbersRect_width, 
				m_numbers[i].y+numbersRect_height, 
				5, 225, 16, 16, alpha);

		//Set new position
		xPos += numbersRect_width + 2;
		tempRect.x = xPos;
		if ((i+1)%10 == 0)
		{
			xPos = getKRect()->x;
			yPos += numbersRect_height + 3;
			tempRect.y = yPos;
			tempRect.x = xPos;
		}
	}
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

void NumbersGrid::printNumbers(SDL_Renderer * renderer)
{
	SDL_Rect dst_rect = {0, 0, 0, 0};
	SDL_Color white = {255, 255, 255};
	int number = 1;
	for (int i = 0; i < 80; i++) 
	{
		//1-digit numbers require specific spacing
		if(number < 10) 
		{
			//Set the destination rect
			dst_rect.x = m_numbers[i].x+oneDigit_xIndent;
			dst_rect.y = m_numbers[i].y+oneDigit_yIndent;	
			dst_rect.w = oneDigit_width;	
			dst_rect.h = oneDigit_height;

			//Load text from font
			loadTextureFromTTF(toString(number), 
					renderer, m_font, white);

			//Render
			render(renderer, &dst_rect);  

		}
		else 
		{
			//Set destination rect	
			dst_rect.x = m_numbers[i].x+twoDigit_xIndent;
			dst_rect.y = m_numbers[i].y+twoDigit_yIndent;	
			dst_rect.w = twoDigit_width;	
			dst_rect.h = twoDigit_height;

			//Load number from font
			loadTextureFromTTF(toString(number), renderer, m_font, white);

			//Render
			render(renderer, &dst_rect);  

		}
		number++;			
	}	
}

void NumbersGrid::printSpecificNumber(SDL_Renderer* renderer, int num)
{
	SDL_Rect dst_rect = {0, 0, 0, 0};
	SDL_Color white = {255, 255, 255};
	int number = 0;
	for (int i = 0; i < 80; i++) 
	{
		number++;			
		if (num == number)
		{
			//1-digit numbers require specific spacing
			if(number < 10) 
			{
				//Set the destination rect
				dst_rect.x = m_numbers[i].x+oneDigit_xIndent;
				dst_rect.y = m_numbers[i].y+oneDigit_yIndent;	
				dst_rect.w = oneDigit_width;	
				dst_rect.h = oneDigit_height;

				//Load text from font
				loadTextureFromTTF(toString(number), 
						renderer, m_font, white);

				//Render
				render(renderer, &dst_rect);  	
			}
			else 
			{
				//Set destination rect	
				dst_rect.x = m_numbers[i].x+twoDigit_xIndent;
				dst_rect.y = m_numbers[i].y+twoDigit_yIndent;	
				dst_rect.w = twoDigit_width;	
				dst_rect.h = twoDigit_height;

				//Load number from font
				loadTextureFromTTF(toString(number), renderer, m_font, white);

				//Render
				render(renderer, &dst_rect);  

			}
		}
	}	
}

bool NumbersGrid::doIfClicked(SDL_Renderer * renderer, const SDL_Event & e) 
{
	bool success = false;
	for (int i = 0; i < 80; i++)
	{
		if(isClickedFlags[i] == 0 && 
				isClicked(e, &m_numbers[i]) 
				&& numbersClicked() < 10) 
		{
			success = true;

			//Draw and fill rect
			isClickedFlags[i] = 1;
			roundedBoxRGBA(renderer, 
					m_numbers[i].x, 
					m_numbers[i].y, 
					m_numbers[i].x+numbersRect_width, 
					m_numbers[i].y+numbersRect_height, 
					5, 200, 200, 0, 255);

			//Play sound effect
			Mix_PlayChannel(-1, m_ClickEffect, 0);
		}
		else if (isClickedFlags[i] == 1 && 
				isClicked(e, &m_numbers[i]))
		{
			success = true;

			//Draw and fill rect
			isClickedFlags[i] = 0;
			roundedBoxRGBA(renderer,
					m_numbers[i].x, 
					m_numbers[i].y,
					m_numbers[i].x+numbersRect_width,
					m_numbers[i].y+numbersRect_height, 
					5, 225, 16, 16, 255);

			//Play sound effect
			Mix_PlayChannel(-1, m_ClickEffect, 0);
		}	
	}
	return success;
}

void NumbersGrid::pickRandomChoices(SDL_Renderer* renderer)
{	
	std::vector <int> vec;
        int randNum;

        for (int i = 0; i < 80; i++)
        {
                vec.push_back(i);
        }

        for (int i = 0; i < 10; i++)
        {
                //Get iterator to the beginning of the vector
                std::vector <int>::iterator it = vec.begin();

                //Feed srand with the current clock cycle
                srand(SDL_GetTicks());

                //Generate random number evenly distributed
                do
                {       
                        randNum = rand();
                } while (randNum >= (RAND_MAX - RAND_MAX % vec.size()));

                //Get rand num in the given range
                randNum %= vec.size();
                
                //Advance the iterator rand number of times
                advance(it, randNum);

                //Raise the flag
		if (isClickedFlags[*it] == false)
		{
               		isClickedFlags[*it] = true;
		}

                //Erase the element
                vec.erase(it);
	}
	for (int i = 0; i < 80; i++)
	{
		if (isClickedFlags[i] == true) 
		{
			roundedBoxRGBA(renderer, 
					m_numbers[i].x, 
					m_numbers[i].y, 
					m_numbers[i].x+numbersRect_width, 
					m_numbers[i].y+numbersRect_height, 
					5, 200, 200, 0, 255);

			//Play sound effect
			Mix_PlayChannel(-1, m_ClickEffect, 0);
		}
	}
	printNumbers(renderer);
}

const char* NumbersGrid::toString(int in_val)
{
	std::string str = boost::lexical_cast<std::string> (in_val);
	return str.c_str();
}


void NumbersGrid::pickRandomNumbers(SDL_Renderer* renderer)
{
	std::vector <int> vec;
        int randNum;

        for (int i = 0; i < 80; i++)
        {
                vec.push_back(i);
        }

        for (int i = 0; i < 20; i++)
        {
                //Get iterator to the beginning of the vector
                std::vector <int>::iterator it = vec.begin();

                //Feed srand with the current clock cycle
                srand(SDL_GetTicks());

                //Generate random number evenly distributed
                do
                {       
                        randNum = rand();
                } while (randNum >= (RAND_MAX - RAND_MAX % vec.size()));

                //Get rand num in the given range
                randNum %= vec.size();
                
                //Advance the iterator rand number of times
                advance(it, randNum);

                //Raise the flag
                randomNumbersFlags[*it] = true;

                //Erase the element
                vec.erase(it);
	}
}

void NumbersGrid::resetRandFlags()
{	
	for (int i = 0; i < 80; i++)
	{
		randomNumbersFlags[i] = false;
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
	for (int i = 0; i < 80; i++)
	{
		if (isClickedFlags[i] == true && 
				isClickedFlags[i] == randomNumbersFlags[i])
		{
			numberOfHitsFlags[i] = true;
			count++;
		}
	}
	return count;		
}

int NumbersGrid::numbersClicked()
{
	int sum = 0;
	for (int i = 0; i < 80; i++)
	{
		sum += isClickedFlags[i];
	}
	return sum;
}

void NumbersGrid::reRenderClickedNumbers(SDL_Renderer* renderer, int alpha)
{
	for (int i = 0; i < 80; i++)
	{
		if(isClickedFlags[i] == true)
		{
			roundedBoxRGBA(renderer,
					m_numbers[i].x, 
					m_numbers[i].y,
					m_numbers[i].x+numbersRect_width,
					m_numbers[i].y+numbersRect_height, 
					5, 200, 200, 0, alpha);	
		}
	}
}

void NumbersGrid::blinkingSuccessHits(SDL_Renderer* renderer)
{
	bool flag = false;
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 80; j++)
		{
			if(numberOfHitsFlags[j] == true)
			{
				if(flag == false)
				{
					roundedBoxRGBA(renderer,
							m_numbers[j].x, 
							m_numbers[j].y,
							m_numbers[j].x+numbersRect_width,
							m_numbers[j].y+numbersRect_height, 
							5, 225, 16, 16, 255);
				}
				else if (flag == true)
				{
					roundedBoxRGBA(renderer,
							m_numbers[j].x, 
							m_numbers[j].y,
							m_numbers[j].x+numbersRect_width,
							m_numbers[j].y+numbersRect_height, 
							5, 200, 200, 0, 255);
				}
			}
		}
		if (flag == false) 
		{
			flag = true;
		}
		else if (flag == true)
		{
			flag = false;
		}
		//Reapply numbers in rects
		printNumbers(renderer);
		SDL_RenderPresent(renderer);	
		int timeout = SDL_GetTicks() + 500;
		while(!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {};	
	}
}

void NumbersGrid::renderRandomNumbers(SDL_Renderer* renderer)
{	
	for (int i = 0; i < 80; i++)
	{
		if(randomNumbersFlags[i] == true)
		{
			//Draw diagonal lines
			if(filledCircleRGBA(renderer, 
						m_numbers[i].x+circle_xIndent,
						m_numbers[i].y+circle_yIndent,
						radiusOfCircle, 0, 0, 0, 255)!=0) 
			{
				std::cout << "Error drawing circle" 
					<< std::endl;
			}
		}
	}
}

void NumbersGrid::resetNumbersGrid(SDL_Renderer* renderer)
{
	resetFlags();
	createRects(renderer, 255);
	printNumbers(renderer);
}

void NumbersGrid::resetFlags()
{
	for (int i = 0; i < 80; i++)
	{
		isClickedFlags[i] = 0;
		randomNumbersFlags[i] = 0;
		numberOfHitsFlags[i] = 0;
	}
}

void NumbersGrid::resetIsClicked()
{
	for (int i = 0; i < 80; i++)
	{
		isClickedFlags[i] = 0;
	}
}

std::vector <bool>& NumbersGrid::getRandomNumbers()
{
	return randomNumbersFlags;
}

SDL_Rect* NumbersGrid::getNumberRects()
{
	return m_numbers;	
}

std::vector <bool>& NumbersGrid::getClickedNumbers()
{
	return isClickedFlags;	
}

void NumbersGrid::raiseClickedFlags(const std::vector <bool>& clickedNumbers)
{
	for (int i = 0; i < 80; i++)
	{
		if(clickedNumbers[i] == 1)
		{
			isClickedFlags[i] = 1;
		}
	}
}
