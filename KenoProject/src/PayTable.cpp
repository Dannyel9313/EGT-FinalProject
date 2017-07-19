#include "PayTable.h"

const char* toString(int val)
{
       std::string str = boost::lexical_cast <std::string> (val);
       return str.c_str();
}

void PayTable::renderPayTable(SDL_Renderer* renderer)
{
	roundedBoxRGBA(renderer, TOP_RIGHT_POINT.x, TOP_RIGHT_POINT.y,
				BOTTOM_LEFT_POINT.x, BOTTOM_LEFT_POINT.y,
				5, RED.r, RED.g, RED.b, 150); 
	renderHitsText(renderer);
	renderPayText(renderer);
	setHitsRects();
	setPayRects();
}

void PayTable::renderHitsText(SDL_Renderer* renderer)
{
	SDL_Rect tempRect = {HITS_TEXT_X, HITS_TEXT_Y, 
				HITS_TEXT_WIDTH, HITS_TEXT_HEIGHT};

	m_text.setKRect(tempRect);

	m_text.LoadFromRenderedText("hits", renderer, WHITE);
	m_text.textRender(m_text.getKRect(), m_text.getKTexture(), renderer);
}

void PayTable::renderPayText(SDL_Renderer* renderer)
{
	SDL_Rect tempRect = {PAY_TEXT_X, PAY_TEXT_Y, 
				PAY_TEXT_WIDTH, PAY_TEXT_HEIGHT};

	m_text.setKRect(tempRect);

	m_text.LoadFromRenderedText("pay", renderer, WHITE);
	m_text.textRender(m_text.getKRect(), m_text.getKTexture(), renderer);
}

void PayTable::renderHits(SDL_Renderer* renderer, int number)
{
	if(number >= 2)
	{
		for (int i = 0; i < number; i++)
		{
			hitsRects[i].w = HITS_RECT_WIDTH;	
			hitsRects[i].x = HITS_RECT_X;
			if(i+1 >= 10)
			{
				hitsRects[i].w += 25;
				hitsRects[i].x -= 25;
				m_text.LoadFromRenderedText(toString(i+1), renderer, WHITE);
				m_text.textRender(&hitsRects[i], m_text.getKTexture(), renderer);
			}
			else if (i+1 < 10)
			{
				m_text.LoadFromRenderedText(toString(i+1), renderer, WHITE);
				m_text.textRender(&hitsRects[i], m_text.getKTexture(), renderer);
			}
		}
	}
}

void PayTable::renderPay(SDL_Renderer* renderer, int numbers)
{
	if(numbers >= 2)
	{
		for (int i = 0; i < 9; i++)
		{
			if (numbers == i+2)
			{
				for (int j = 0; j < i+2; j++)
				{
					paysRects[j].w = PAY_RECT_WIDTH;
					paysRects[j].x = PAY_RECT_X;
					if (arrayQueficients[numbers-2][j] >= 10
						&& arrayQueficients[numbers-2][j] < 100)
					{
						paysRects[j].w += 20;
						paysRects[j].x -= 20;
						m_text.LoadFromRenderedText(toString
						(1*arrayQueficients[numbers-2][j]), 
						renderer, WHITE);

						m_text.textRender(&paysRects[j], 
							m_text.getKTexture(), 
							renderer);
					}	
					else if (arrayQueficients[numbers-2][j] >= 100
						&& arrayQueficients[numbers-2][j] < 1000)
					{
						paysRects[j].w += 40;
						paysRects[j].x -= 40;
						m_text.LoadFromRenderedText(toString
						(1*arrayQueficients[numbers-2][j]), 
						renderer, WHITE);

						m_text.textRender(&paysRects[j], 
							m_text.getKTexture(), 
							renderer);
					}
					else if (arrayQueficients[numbers-2][j] >= 1000)
					{
						paysRects[j].w += 60;
						paysRects[j].x -= 60;
						m_text.LoadFromRenderedText(toString
						(1*arrayQueficients[numbers-2][j]), 
						renderer, WHITE);

						m_text.textRender(&paysRects[j], 
							m_text.getKTexture(), 
							renderer);
					}
					else if (arrayQueficients[numbers-2][j] >= 0
						&& arrayQueficients[numbers-2][j] < 10)
					{
						m_text.LoadFromRenderedText(toString
						(1*arrayQueficients[numbers-2][j]), 
						renderer, WHITE);

						m_text.textRender(&paysRects[j], 
							m_text.getKTexture(), 
							renderer);
					}
				}
			}
		}

	}
}

void PayTable::setHitsRects()
{
	SDL_Rect tempRect = {HITS_RECT_X, HITS_RECT_Y,
				HITS_RECT_WIDTH, HITS_RECT_HEIGHT};
	
	for (int i = 0; i < 10; i++)
	{
		tempRect.y += PAYTABLE_HEIGHT/11;
		hitsRects.push_back(tempRect);
	}		
}

void PayTable::setPayRects()
{
	SDL_Rect tempRect = {PAY_RECT_X, PAY_TEXT_Y,
				PAY_RECT_WIDTH, PAY_RECT_HEIGHT};

	for (int i = 0; i < 10; i++)
	{
		tempRect.y += PAYTABLE_HEIGHT/11;
		paysRects.push_back(tempRect);
	}
}

Font& PayTable::getFont()
{
	return m_text;	
}
