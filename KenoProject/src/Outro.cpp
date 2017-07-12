#include "Outro.h"

Outro::Outro()
{

}

Outro::~Outro() {
	// TODO Auto-generated destructor stub
}




void Outro::winingWindow(SDL_Renderer * renderer) {
	SDL_Rect Message_rect;
		Message_rect.x = 0;
		Message_rect.y = 0;
		Message_rect.w = 800;
		Message_rect.h = 800;

		render(renderer, &Message_rect);

}

void Outro::loadFromTTF() {
	font = TTF_OpenFont("Italic.ttf", 24);
	TTF_SetFontStyle(font, TTF_STYLE_ITALIC);
}



void Outro::writingOnScreen(SDL_Renderer * renderer,double money) {
	//std::string str = money;
	SDL_Color color={0,0,0};
	SDL_Rect rect = {400,500 , 100, 100};

	loadTextureFromTTF(doubleToString(money), renderer, font, color);
	render(renderer, &rect);

}

std::string Outro::doubleToString(double var)
{
	std::string str = boost::lexical_cast<std::string> (var);
	return str.c_str();
}

