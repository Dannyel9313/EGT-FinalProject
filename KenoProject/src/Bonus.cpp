#include "Bonus.h"
#include "Outro.h"

Bonus::Bonus() 
{
	this->m_bonus = 0;
}

Bonus::~Bonus() 
{
}

void Bonus::loadBonusElements(SDL_Renderer* renderer)
{
	m_bonusText.LoadFromRenderedText(toString(m_bonus),renderer,m_bonusText.getButtonColor());

	m_bonusLogo.loadTextureFromFile("Resources/Images/bonusTransparent.png",renderer);

	m_bonusRectangle.loadTextureFromFile("Resources/Images/minMaxNumberRect.png",
			renderer);

}

void Bonus::setPositionAndDimension(SDL_Renderer* renderer)
{
	m_bonusText.setPosition(340, 45, bonusText_width, bonusText_height);

	m_bonusLogo.setPosition(160, 35, bonusLogo_width, bonusLogo_height);

	m_bonusRectangle.setPosition(300, 40, bonusRectangle_width, bonusRectangle_height);

}

void Bonus::renderBonus(SDL_Renderer* renderer)
{
	setFont();

	setColor();

	setPositionAndDimension(renderer);

	loadBonusElements(renderer);

	m_bonusLogo.render(renderer,m_bonusLogo.getKRect());

	m_bonusRectangle.render(renderer, m_bonusRectangle.getKRect());

	if(m_bonus > 0)
	{
	m_bonusText.textRender(m_bonusText.getKRect(), m_bonusText.getKTexture(), renderer);
	}

}

//void Bonus::bonusWindow(SDL_Renderer* renderer, double bonusCredit)
//{
//	TTF_Font* font;
//	font = TTF_OpenFont("Italic.ttf", 24);
//
//	TTF_SetFontStyle(font, TTF_STYLE_ITALIC);
//
//	SDL_Color color={0,0,0};
//	SDL_Rect rect = {200,0 , 100, 100};
//
//	std::string str = boost::lexical_cast<std::string> (bonusCredit);
//
//	loadTextureFromTTF(str.c_str(), renderer, font, color);
//	render(renderer, &rect);
//}

//void Bonus::addBonusPercent(double credit)
//{
//	double percent;
//	double winningMoney;
//	int round=1;
//
//	for(round=1; round<=10;round++ )
//	{
//		percent=(winningMoney+credit)/100;
//
//	}
//	credit+=percent;
//}

BaseObject& Bonus::getBonusLogo() {
	return m_bonusLogo;
}

BaseObject& Bonus::getBonusRectangle() {
	return m_bonusRectangle;
}

int Bonus::getBonus() const {
	return m_bonus;
}

Font& Bonus::getBonusText(){
	return m_bonusText;
}

void Bonus::setFont()
{

	m_bonusText.setFont(TTF_OpenFont("Resources/Fonts/Blazed.ttf",40));

}

void Bonus::setColor()
{

m_bonusText.setButtonColor(254, 254, 254);

}

void Bonus::setBonus(int bonus)
{
	m_bonus = bonus;
}

const char * Bonus::toString(int in_val)
{
	std::string str = boost::lexical_cast<std::string>(in_val);
	return str.c_str();
}
