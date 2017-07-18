#include "Outro.h"

Outro::Outro()
{

}

Outro::~Outro() {
	// TODO Auto-generated destructor stub
}




void Outro::winingWindow(SDL_Renderer * renderer) {
	SDL_Rect rect;
		rect.x = 0;
		rect.y = 0;
	    rect.w = 800;
		rect.h = 700;



		//render(renderer, &rect);
		//SDL_RenderCopy(renderer, background.getKTexture(), NULL, NULL);
		background.setBlendMode(SDL_BLENDMODE_BLEND);
		background.loadTextureFromFile("back.png",renderer);
for(int i=100; i>95;i--){
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	background.setAlpha(i);

	background.render(renderer,&rect);

	SDL_RenderPresent(renderer);


}




}

void Outro::loadFromTTF() {
	font = TTF_OpenFont("Italic.ttf", 24);
	TTF_SetFontStyle(font, TTF_STYLE_ITALIC);
}



void Outro::writingOnScreen(SDL_Renderer * renderer,double money) {

loadFromTTF();

	//std::string str = money;


	SDL_Color color={255,255,255};//cvqt
	SDL_Rect rect = {300,300, 100, 100};//poziciq  na parite
	SDL_Rect rect1={100,100,600,600};//golemina na kartinkata
	SDL_Rect rect2={200,100,350,100};// nadpis congratulation

	labelCongrat.loadTextureFromTTF("Congratulation !! You Win ", renderer, font, color);
	labelMoney.loadTextureFromTTF(doubleToString(money), renderer, font, color);


for(int i=0;i<600; i+=50){
	rect1.h=0+i;
	rect1.w=i;


	winPic.loadTextureFromFile("gift.png",renderer);
	winPic.render(renderer,&rect1);
	SDL_RenderPresent(renderer);
	//SDL_RenderCopy(renderer, winPic.getKTexture(), NULL, NULL);

}


	for(int i=0;i<100;i+=50){
		rect2.h+=i;
		rect2.w+=i;

		rect.h+=i;
		rect.w+=i;

		winPic.render(renderer,&rect1);
//		loadTextureFromTTF("Congratulation !! You Win ", renderer, font, color);
//		render(renderer, &rect2);
//		SDL_RenderPresent(renderer);

		for(int j=95;j<200;j++){


		//	SDL_Delay(1000);

		//	labelCongrat.loadTextureFromTTF("Congratulation !! You Win ", renderer, font, color);
		//	rect2.x = j + 5;
SDL_Rect whereTo = rect2;
whereTo.x = j+ 2;
SDL_Rect mylabel = rect;
		mylabel.y = j*2 + 3;
		SDL_SetRenderDrawColor(renderer, 3, 5, 20, 255);
		SDL_RenderCopy(renderer,background.getKTexture(),NULL,NULL);
winPic.render(renderer,&rect1);
					//labelCongrat.render(renderer, &rect2);

					SDL_RenderCopy(renderer, labelCongrat.getKTexture(), NULL, &whereTo);
					SDL_RenderCopy(renderer, labelMoney.getKTexture(), NULL, &mylabel);
					SDL_RenderPresent(renderer);
			//		labelCongrat.free();

		}

	}


//
//}

	//SDL_RenderPresent(renderer);
//SDL_Delay(3000);

}




std::string Outro::doubleToString(double var)
{
	std::string str = boost::lexical_cast<std::string> (var);
	return str.c_str();
}

BaseObject& Outro::getBackground() {
	return background;
}

void Outro::setBackground(const BaseObject& back) {
	background = back;
}

BaseObject& Outro::getWinPic(){
	return winPic;
}
void Outro::setWinPic(const BaseObject& win){
	winPic=win;
}
