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


		background.loadTextureFromFile("back.png",renderer);
		background.render(renderer,&rect);
		SDL_RenderPresent(renderer);

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
	SDL_Rect rect2={200,100,400,100};// nadpis congratulation


for(int i=0;i<600; i+=50){
	rect1.h=0+i;
	rect1.w=i;
	winPic.loadTextureFromFile("gift.png",renderer);
	winPic.render(renderer,&rect1);
	SDL_RenderPresent(renderer);
	//SDL_RenderCopy(renderer, winPic.getKTexture(), NULL, NULL);

}


	for(int i=0;i<15;i+=2){
		rect2.h+=i;
		rect2.w+=i;

	}
	loadTextureFromTTF("Congratulation !! You Win ", renderer, font, color);
	render(renderer, &rect2);
				SDL_RenderPresent(renderer);


for(int i=0;i<100;i+=50){
//	x+=i;
//	y+=i;
	rect.h+=i;
	rect.w+=i;
	loadTextureFromTTF(doubleToString(money), renderer, font, color);
	SDL_RenderPresent(renderer);
	    render(renderer, &rect);

}
SDL_RenderPresent(renderer);
SDL_Delay(3000);

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
