#include "Outro.h"



Outro::Outro()
{

}

Outro::~Outro()
{
	// TODO Auto-generated destructor stub
}

void Outro::loadFireworksPictures(SDL_Renderer* renderer)
{

	SDL_Rect rectFireworks = { 0, 0, 1200, 800 };


	std::string m_fireworks[13] = { "Resources/Images/1.jpg", "Resources/Images/2.jpg",
						"Resources/Images/3.jpg", "Resources/Images/4.jpg",
						"Resources/Images/5.jpg", "Resources/Images/6.jpg",
						"Resources/Images/7.jpg", "Resources/Images/8.jpg",
						"Resources/Images/9.jpg", "Resources/Images/10.jpg",
						"Resources/Images/11.jpg", "Resources/Images/12.jpg",
						"Resources/Images/13.jpg" };

	for(int i = 0; i < 12; i++)
	{
	for(int i = 0; i < 12; i++)
	{


			m_fireworksBackground.loadTextureFromFile(m_fireworks[i].c_str(),renderer);
			m_fireworksBackground.render(renderer,&rectFireworks);


			SDL_RenderPresent(renderer);
	}
	}
}



void Outro::loadFromTTF()
{
	font = TTF_OpenFont("Resources/Fonts/Candles_.TTF", 24);

}



void Outro::writingOnScreen(SDL_Renderer * renderer,double money)
{

loadFromTTF();
loadFireworksPictures(renderer);

	SDL_Color color={241, 15, 247};//cvqt
	SDL_Rect rect = {200,300, 150, 100};//poziciq  na parite
	SDL_Rect rect1={80,100,580,540};//golemina na kartinkata
	SDL_Rect rect2={220,100,350,100};// nadpis congratulation
	SDL_Rect den={400,300,100,100};//denominaciq


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



					SDL_RenderCopy(renderer, labelCongrat.getKTexture(), NULL, &whereTo);
					SDL_RenderCopy(renderer, labelMoney.getKTexture(), NULL, &mylabel);
					SDL_RenderCopy(renderer, labelDenom.getKTexture(), NULL, &labelD);

					SDL_RenderPresent(renderer);


		}

	}
	int timeout = SDL_GetTicks()+5000;
	while(!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)){}
}





std::string Outro::doubleToString(double var)
{
	std::string str = boost::lexical_cast<std::string> (var);
	return str.c_str();
}

BaseObject& Outro::getWinPic()
{
	return winPic;
}
void Outro::setWinPic(const BaseObject& win)
{
	winPic=win;
}
