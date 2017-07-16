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
	int x=0,y=0;

	SDL_Color color={0,0,0};
	SDL_Rect rect = {300,300 , 100, 100};
	SDL_Rect rect1={300,200,400,400};
	SDL_Rect rect2={x,y,100,100};

	winPic.loadTextureFromFile("gift.png",renderer);
	winPic.render(renderer,&rect1);

	for(int i=0;i<100;i++){
		x+=i;
		y+=i;
		loadTextureFromTTF("Congratulation !! You Win ", renderer, font, color);

	}
	render(renderer, &rect2);


	loadTextureFromTTF(doubleToString(money), renderer, font, color);
	render(renderer, &rect);
	SDL_RenderPresent(renderer);

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
