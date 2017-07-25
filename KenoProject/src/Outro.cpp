#include "Outro.h"



Outro::Outro()
{

}

Outro::~Outro()
{
	// TODO Auto-generated destructor stub
}




void Outro::winingWindow(SDL_Renderer * renderer)
{
	SDL_Rect rect;
		rect.x = 0;
		rect.y = 0;
	    rect.w = 1200;
		rect.h = 800;


//		Uint32 timer = SDL_GetTicks();
//				while (SDL_GetTicks() - timer < 5000 )
//				{

		//render(renderer, &rect);
		//SDL_RenderCopy(renderer, background.getKTexture(), NULL, NULL);
		//zarq[12].setBlendMode(SDL_BLENDMODE_BLEND);
		for(int i=0;i<12;i++){
		zarq[i].loadTextureFromFile("Resources/Images/1.jpg",renderer);
		zarq[i].render(renderer,&rect);
		SDL_RenderPresent(renderer);
		zarq[i].loadTextureFromFile("Resources/Images/2.jpg",renderer);
		zarq[i].render(renderer,&rect);
		SDL_RenderPresent(renderer);
		zarq[i].loadTextureFromFile("Resources/Images/3.jpg",renderer);
		zarq[i].render(renderer,&rect);
		SDL_RenderPresent(renderer);
		zarq[i].loadTextureFromFile("Resources/Images/4.jpg",renderer);
		zarq[i].render(renderer,&rect);
		SDL_RenderPresent(renderer);
		zarq[i].loadTextureFromFile("Resources/Images/5.jpg",renderer);
		zarq[i].render(renderer,&rect);
		SDL_RenderPresent(renderer);
		zarq[i].loadTextureFromFile("Resources/Images/6.jpg",renderer);
		zarq[i].render(renderer,&rect);
		SDL_RenderPresent(renderer);
		zarq[i].loadTextureFromFile("Resources/Images/7.jpg",renderer);
		zarq[i].render(renderer,&rect);
		SDL_RenderPresent(renderer);
		zarq[i].loadTextureFromFile("Resources/Images/8.jpg",renderer);
		zarq[i].render(renderer,&rect);
		SDL_RenderPresent(renderer);
		zarq[i].loadTextureFromFile("Resources/Images/9.jpg",renderer);
		zarq[i].render(renderer,&rect);
		SDL_RenderPresent(renderer);
		zarq[i].loadTextureFromFile("Resources/Images/10.jpg",renderer);
		zarq[i].render(renderer,&rect);
		SDL_RenderPresent(renderer);
		zarq[i].loadTextureFromFile("Resources/Images/11.jpg",renderer);
		zarq[i].render(renderer,&rect);
		SDL_RenderPresent(renderer);
		zarq[i].loadTextureFromFile("Resources/Images/12.jpg",renderer);
		zarq[i].render(renderer,&rect);
		SDL_RenderPresent(renderer);
		zarq[i].loadTextureFromFile("Resources/Images/13.jpg",renderer);



		zarq[i].render(renderer,&rect);
		SDL_RenderPresent(renderer);
		}
				//}
				SDL_RenderPresent(renderer);
//for(int i=100; i>95;i--){
	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	//SDL_RenderClear(renderer);

	//background.setAlpha(i);

	//zarq[i].render(renderer,&rect);

	//SDL_RenderPresent(renderer);


//}




}

void Outro::loadFromTTF()
{
	font = TTF_OpenFont("Resources/Fonts/Candles_.TTF", 24);
//	TTF_SetFontStyle(font, TTF_STYLE_ITALIC);
}



void Outro::writingOnScreen(SDL_Renderer * renderer,double money)
{

loadFromTTF();
winingWindow(renderer);

	SDL_Color color={241, 15, 247};//cvqt
	SDL_Rect rect = {200,300, 150, 100};//poziciq  na parite
	SDL_Rect rect1={100,100,500,500};//golemina na kartinkata
	SDL_Rect rect2={220,100,350,100};// nadpis congratulation
	SDL_Rect den={400,300,100,100};//denominaciq


//	Uint32 timerDelay = SDL_GetTicks();
//		while (SDL_GetTicks() - timerDelay < 5000 )
//		{


	labelCongrat.loadTextureFromTTF("Congratulations !!! You Win ", renderer, font, color);
	labelMoney.loadTextureFromTTF(doubleToString(money), renderer, font, color);
labelDenom.loadTextureFromTTF("BGN",renderer,font,color);

for(int i=0;i<500; i+=30){
	rect1.h=i;
	rect1.w=i;


	winPic.loadTextureFromFile("Resources/Images/winPic.jpg",renderer);
	winPic.render(renderer,&rect1);
	SDL_RenderPresent(renderer);

}


	for(int i=0;i<100;i+=50)
	{
//		rect2.h+=i;
//		rect2.w+=i;
//
//		rect.h+=i;
//		rect.w+=i;

		winPic.render(renderer,&rect1);

		for(int j=95;j<200;j++)
		{


SDL_Rect whereTo = rect2;
whereTo.x = j+ 2;
SDL_Rect mylabel = rect;
SDL_Rect  labelD=den;
labelD.y=j+3;
		mylabel.y = j + 3;

winPic.render(renderer,&rect1);

					//labelCongrat.render(renderer, &rect2);

					SDL_RenderCopy(renderer, labelCongrat.getKTexture(), NULL, &whereTo);
					SDL_RenderCopy(renderer, labelMoney.getKTexture(), NULL, &mylabel);
					SDL_RenderCopy(renderer, labelDenom.getKTexture(), NULL, &labelD);

					SDL_RenderPresent(renderer);


		}

	}
		}
	//SDL_RenderPresent(renderer);
//SDL_Delay(3000);

//}




std::string Outro::doubleToString(double var)
{
	std::string str = boost::lexical_cast<std::string> (var);
	return str.c_str();
}

BaseObject& Outro::getBackground()
{
	return zarq[12];
}

void Outro::setBackground(const BaseObject& back)
{
	zarq[12] = back;
}

BaseObject& Outro::getWinPic()
{
	return winPic;
}
void Outro::setWinPic(const BaseObject& win)
{
	winPic=win;
}
