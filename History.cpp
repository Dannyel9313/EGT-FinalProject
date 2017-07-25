#include "History.h"

std::string History::toString(int val)
{
	std::string str = boost::lexical_cast <std::string> (val);
	return str;
}

int History::currentRound = 0;

void History::renderHistory(SDL_Renderer* renderer)
{
	roundedBoxRGBA(renderer, HISTORY_TOP_RIGHT.x, HISTORY_TOP_RIGHT.y,
				HISTORY_BOTTOM_LEFT.x, HISTORY_BOTTOM_LEFT.y,
				5, RED.r, RED.g, RED.b, 150); 
	renderRoundText(renderer);
	renderHitsText(renderer);
	setHitsRects();
	setRoundRects();
	renderRounds(renderer);
}

void History::renderRoundText(SDL_Renderer* renderer)
{
	SDL_Rect tempRect = {ROUNDTABLE_TEXT_X, ROUNDTABLE_TEXT_Y, 
				ROUNDTABLE_TEXT_WIDTH, ROUNDTABLE_TEXT_HEIGHT};

        m_text.setKRect(tempRect);

        m_text.LoadFromRenderedText("round", renderer, WHITE);
        m_text.textRender(m_text.getKRect(), m_text.getKTexture(), renderer);
}

void History::renderHitsText(SDL_Renderer* renderer)
{
	SDL_Rect tempRect = {HITTABLE_TEXT_X, HITTABLE_TEXT_Y, 
				HITTABLE_TEXT_WIDTH, HITTABLE_TEXT_HEIGHT};

        m_text.setKRect(tempRect);

        m_text.LoadFromRenderedText("hits", renderer, WHITE);
        m_text.textRender(m_text.getKRect(), m_text.getKTexture(), renderer);
}

void History::setHitsRects()
{
        SDL_Rect tempRect = {HITTABLE_RECT_X, HITTABLE_RECT_Y,
                                HITTABLE_RECT_WIDTH, HITTABLE_RECT_HEIGHT};

        for (int i = 0; i < 9; i++)
        {
                tempRect.y += HISTORY_HEIGHT/10;
                hitsRects.push_back(tempRect);
        }
}

void History::setRoundRects()
{
        SDL_Rect tempRect = {ROUNDTABLE_RECT_X, ROUNDTABLE_RECT_Y,
                                ROUNDTABLE_RECT_WIDTH, ROUNDTABLE_RECT_HEIGHT};

        for (int i = 0; i < 9; i++)
        {
                tempRect.y += HISTORY_HEIGHT/10;
                roundsRects.push_back(tempRect);
        }
}

void History::renderRounds(SDL_Renderer* renderer)
{
	for (int i = 0; i < 9; i++)
        {        
		if (i+1 >= 10)
		{
			roundsRects[i].w = ROUNDTABLE_RECT_WIDTH + 20;       
                	roundsRects[i].x = ROUNDTABLE_RECT_X - 20;
			m_text.LoadFromRenderedText(toString(i+1), renderer, WHITE);
			m_text.textRender(&roundsRects[i], m_text.getKTexture(), renderer);
		}
		else if (i+1 < 10)
		{
			roundsRects[i].w = ROUNDTABLE_RECT_WIDTH;       
                	roundsRects[i].x = ROUNDTABLE_RECT_X-15;
			m_text.LoadFromRenderedText(toString(i+1), renderer, WHITE);
			m_text.textRender(&roundsRects[i], m_text.getKTexture(), renderer);
		}
      	}
}

void History::renderHits(SDL_Renderer* renderer, int hits, int pushFlag)
{
	if(pushFlag == 1)
	{
		if(currentRound == 10)
		{
			currentRound = 1;
			saveHits.clear();
		}
		saveHits.push_back(hits);	
	}

	for (int i = 0; i < currentRound; i++)	
	{
		if(saveHits[i] >= 10)
		{
			hitsRects[i].w = HITTABLE_RECT_WIDTH + 35;       
                	hitsRects[i].x = HITTABLE_RECT_X - 25;
			m_text.LoadFromRenderedText(toString(saveHits[i]), renderer, WHITE);
			m_text.textRender(&hitsRects[i], m_text.getKTexture(), renderer);
		}
		else if (saveHits[i] < 10)
		{		
			hitsRects[i].w = HITTABLE_RECT_WIDTH + 20;       
                	hitsRects[i].x = HITTABLE_RECT_X - 20;
			m_text.LoadFromRenderedText(toString(saveHits[i]), renderer, WHITE);
			m_text.textRender(&hitsRects[i], m_text.getKTexture(), renderer);
		}
	}
}

Font& History::getFont()
{
	return m_text;
}
