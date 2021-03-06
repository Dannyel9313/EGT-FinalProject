#include "PayTable.h"

const char* toString(int val)
{
       std::string str = boost::lexical_cast <std::string> (val);
       return str.c_str();
}

void PayTable::renderPayTable(SDL_Renderer* renderer, int hits, int bet)
{
	roundedBoxRGBA(renderer, PAYTABLE_TOP_RIGHT.x, PAYTABLE_TOP_RIGHT.y,
				PAYTABLE_BOTTOM_LEFT.x, PAYTABLE_BOTTOM_LEFT.y,
				5, RED.r, RED.g, RED.b, 150); 
	renderHitsText(renderer);
	renderPayText(renderer);
	renderHits(renderer, hits, bet);
	renderPay(renderer, hits, bet);
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

void PayTable::renderHits(SDL_Renderer* renderer, int number, int bet)
{
	if(number >= 2 && bet > 0)
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

void PayTable::renderPay(SDL_Renderer* renderer, int numbers, int bet)
{
	if(numbers >= 2 && bet > 0)
	{
		for (int j = 0; j < numbers; j++)
		{
			paysRects[j].w = PAY_RECT_WIDTH;
			paysRects[j].x = PAY_RECT_X;
			if (bet*arrayQueficients[numbers-2][j] >= 10
				&& bet*arrayQueficients[numbers-2][j] < 100)
			{
				paysRects[j].w += 20;
				paysRects[j].x -= 20;
				m_text.LoadFromRenderedText(toString
				(bet*arrayQueficients[numbers-2][j]), 
				renderer, WHITE);

				m_text.textRender(&paysRects[j], 
					m_text.getKTexture(), 
					renderer);
			}	
			else if (bet*arrayQueficients[numbers-2][j] >= 100
				&& bet*arrayQueficients[numbers-2][j] < 1000)
			{
				paysRects[j].w += 40;
				paysRects[j].x -= 40;
				m_text.LoadFromRenderedText(toString
				(bet*arrayQueficients[numbers-2][j]), 
				renderer, WHITE);

				m_text.textRender(&paysRects[j], 
					m_text.getKTexture(), 
					renderer);
			}
			else if (bet*arrayQueficients[numbers-2][j] >= 1000)
			{
				paysRects[j].w += 60;
				paysRects[j].x -= 60;
				m_text.LoadFromRenderedText(toString
				(bet*arrayQueficients[numbers-2][j]), 
				renderer, WHITE);

				m_text.textRender(&paysRects[j], 
					m_text.getKTexture(), 
					renderer);
			}
			else if (bet*arrayQueficients[numbers-2][j] >= 0
				&& bet*arrayQueficients[numbers-2][j] < 10)
			{
				m_text.LoadFromRenderedText(toString
				(bet*arrayQueficients[numbers-2][j]), 
				renderer, WHITE);

				m_text.textRender(&paysRects[j], 
					m_text.getKTexture(), 
					renderer);
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

void PayTable::setLines()
{
	SDL_Rect tempRect = {LINE_RECT_X, LINE_RECT_Y, LINE_RECT_WIDTH,
		LINE_RECT_HEIGHT};

	for (int i = 0; i < 10; i++)
	{
		lines.push_back(tempRect);
		tempRect.y += PAYTABLE_HEIGHT/11;
	}
}

const std::vector <SDL_Rect>& PayTable::getLines()
{
	return lines;
}

void PayTable::reApplyLine(SDL_Renderer* renderer, int line, int numbersClicked, int bet)
{
	//Reapply hit
	if (line > 0)
	{
		hitsRects[line-1].w = HITS_RECT_WIDTH;	
		hitsRects[line-1].x = HITS_RECT_X;
		if(line >= 10)	
		{			
			hitsRects[line-1].w += 25;
			hitsRects[line-1].x -= 25;
			m_text.LoadFromRenderedText
				(toString(line), renderer, WHITE);
				m_text.textRender(&hitsRects[line-1],
				m_text.getKTexture(), renderer);
		}
		else if (line < 10)
		{
			m_text.LoadFromRenderedText
				(toString(line), renderer, WHITE);
				m_text.textRender(&hitsRects[line-1],
				m_text.getKTexture(), renderer);
		}

		//Reapply pay		
		paysRects[line-1].w = PAY_RECT_WIDTH;
		paysRects[line-1].x = PAY_RECT_X;
		if (bet*arrayQueficients[numbersClicked-2][line-1] >= 10
			&& bet*arrayQueficients[numbersClicked-2][line-1] 
			< 100)
		{
			paysRects[line-1].w += 20;
			paysRects[line-1].x -= 20;
			m_text.LoadFromRenderedText(toString
				(bet*arrayQueficients[numbersClicked-2][line-1]), 
				renderer, WHITE);

			m_text.textRender(&paysRects[line-1], 
				m_text.getKTexture(), 
				renderer);
		}		
		else if (bet*arrayQueficients[numbersClicked-2][line-1] >= 100
			&& bet*arrayQueficients[numbersClicked-2][line-1] 
			< 1000)
		{
			paysRects[line-1].w += 40;
			paysRects[line-1].x -= 40;
			m_text.LoadFromRenderedText(toString
				(bet*arrayQueficients[numbersClicked-2][line-1]), 
				renderer, WHITE);

			m_text.textRender(&paysRects[line-1], 
				m_text.getKTexture(), 
				renderer);
		}
		else if (bet*arrayQueficients[numbersClicked-2][line-1] >= 1000)
		{
			paysRects[line-1].w += 60;
			paysRects[line-1].x -= 60;
			m_text.LoadFromRenderedText(toString
				(bet*arrayQueficients[numbersClicked-2][line-1]), 
				renderer, WHITE);

			m_text.textRender(&paysRects[line-1], 
				m_text.getKTexture(), 
				renderer);
		}
		else if (bet*arrayQueficients[numbersClicked-2][line-1] >= 0
			&& bet*arrayQueficients[numbersClicked-2][line-1] < 10)
		{
			m_text.LoadFromRenderedText(toString
				(bet*arrayQueficients[numbersClicked-2][line-1]), 
				renderer, WHITE);

			m_text.textRender(&paysRects[line-1], 
				m_text.getKTexture(), 
				renderer);
		}
	}
}


Font& PayTable::getFont()
{
	return m_text;	
}
