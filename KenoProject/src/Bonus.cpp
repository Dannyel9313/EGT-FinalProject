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

	m_extraBonusLogo.loadTextureFromFile("Resources/Images/extra-bonus.png",renderer);

}

void Bonus::setPositionAndDimension(SDL_Renderer* renderer)
{
	m_bonusText.setPosition(340, 45, bonusText_width, bonusText_height);

	m_bonusLogo.setPosition(160, 35, bonusLogo_width, bonusLogo_height);

	m_bonusRectangle.setPosition(300, 40, bonusRectangle_width, bonusRectangle_height);

	m_extraBonusLogo.setPosition(570, 350, extraBonusLogo_width, extraBonusLogo_height);

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
//	m_extraBonusLogo.render(renderer,m_extraBonusLogo.getKRect());

}


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

void Bonus::showBonus(SDL_Renderer* renderer, int bonusPoints)
{


m_bonusRectangle.render(renderer, m_bonusRectangle.getKRect());

m_bonusText.LoadFromRenderedText(toString(bonusPoints), renderer, m_bonusText.getButtonColor());

m_bonusText.textRender(m_bonusText.getKRect(), m_bonusText.getKTexture(), renderer);
}

BaseObject& Bonus::getExtraBonusLogo() {
	return m_extraBonusLogo;
}



const char * Bonus::toString(int in_val) {
	std::string str = boost::lexical_cast<std::string>(in_val);
	return str.c_str();
}

