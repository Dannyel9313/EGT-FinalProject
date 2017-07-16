#include "History.h"

std::string History::toString(int val)
{
	std::string str = boost::lexical_cast <std::string> (val);
	return str;
}

int History::currentRound = 0;

void History::setRoundTable(SDL_Renderer* renderer)
{	
	//X, Y, Width, Height
	SDL_Rect tempRect = {RoundTable_X, RoundTable_Y, RoundTable_Width, RoundTable_Height};

	//Set round text
	tempRect.x += 9;
	tempRect.w -= 9;
	tempRect.h = RoundTable_Height/10;
	round = tempRect;

	//Push back round text rect
	roundLines.push_back(tempRect);

	//Set round numbers rect
	int yPos = RoundTable_Y;
	tempRect.x = RoundTable_X+35;
	tempRect.w = RoundTable_Width-65;
	for (int i = 0; i < 9; i++)
	{
		yPos += RoundTable_Height/10;		
		tempRect.y = yPos;
		roundLines.push_back(tempRect);
	}
}

void History::setHitsTable(SDL_Renderer* renderer)
{	
	SDL_Rect tempRect = {HitTable_X, HitTable_Y, HitTable_Width, HitTable_Height};
	
	//Set hit teVt
	tempRect.x += 9;
	tempRect.w -= 9;
	tempRect.h = HitTable_Height/10;
	round = tempRect;

	//Push back round text rect
	hitLines.push_back(tempRect);

	int yPos = RoundTable_Y;
	tempRect.x = HitTable_X+35;
	tempRect.w = RoundTable_Width-65;
	for (int i = 0; i < 9; i++)
	{
		yPos += RoundTable_Height/10;		
		tempRect.y = yPos;
		hitLines.push_back(tempRect);
	}
}

/*void History::setLines(SDL_Renderer* renderer)
{
	int yPos = 75;
	SDL_Rect tempRect = {500, 0, 320, 30};
	
	for (int i = 0; i < 6; i++)
	{
		tempRect.y = yPos;
		lines.push_back(tempRect);
		yPos += 30;
	}
}*/

/*void History::printHits(SDL_Renderer* renderer, int* hits)
{
	std::string path = "History.ttf";
	TTF_Font* font = TTF_OpenFont(path.c_str(), 6);

	SDL_Color white = {255, 255, 255};

	int temp;
	std::string str;
	std::string str_one;
	if(hits!=NULL) 
	{
		for (int i = 0; i < 80; i++)
		{
			temp = 1;
			if (hits[i] == 1)
			{
				temp = temp+i;
				str = toString(temp) + "|";
				str_one = str_one + str;  
			}
		}
	}

	if(!str.empty())
	{
		loadTextureFromTTF(str_one, renderer, font, white);
		render(renderer, &lines[0]);
	}

	if (font != NULL)
	{
		TTF_CloseFont(font);
		font = NULL;
	}
	delete[] hits;
}*/

void History::printHits(SDL_Renderer* renderer, int hits, int pushFlag)
{
	SDL_Color white = {255, 255, 255};
	
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
		historyText.LoadFromRenderedText(toString(saveHits[i]), renderer, white);
		historyText.textRender(&hitLines[i+1], historyText.getKTexture(), renderer);
	}

}

void History::printHistory(SDL_Renderer* renderer)
{
	roundedBoxRGBA(renderer, 820, 75, 670, 375, 5, 153, 0, 0, 150); 
}

void History::printRounds(SDL_Renderer* renderer)
{
	SDL_Color white = {255, 255, 255};
	for (int i = 0; i < 9; i++)
	{
		historyText.LoadFromRenderedText(toString(i+1), renderer, white);
		historyText.textRender(&roundLines[i+1], historyText.getKTexture(), renderer);
	}
}

void History::initializeHistory(SDL_Renderer* renderer)
{
	printHistory(renderer);

	setHitsTable(renderer);
	setRoundTable(renderer);	

	historyText.setFont(TTF_OpenFont("Resources/Fonts/AUDI.TTF", 16));
	SDL_Color white = {255, 255, 255};

	historyText.LoadFromRenderedText("round", renderer, white);
	historyText.textRender(&roundLines[0], historyText.getKTexture(), renderer);
	historyText.LoadFromRenderedText("hits", renderer, white);
	historyText.textRender(&hitLines[0], historyText.getKTexture(), renderer);	

	printRounds(renderer);
}
