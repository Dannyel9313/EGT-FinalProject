#include "InsertCredit.h"

InsertCredit::InsertCredit()
{
	// TODO Auto-generated constructor stub+
	this->m_credit = 0;
}

InsertCredit::~InsertCredit() {
	// TODO Auto-generated destructor stub
}

int InsertCredit::getCredit() const
{
	return m_credit;
}

void InsertCredit::setCredit(int credit)
{
	this->m_credit = credit;
}

Font& InsertCredit::getFontCredit()
{
	return m_FontCredit;
}

Font& InsertCredit::getFontInsertCredit()
{
	return m_FontInsertCredit;
}

Font& InsertCredit::getFontMinus()
{
	return m_FontMinus;
}

Font& InsertCredit::getFontPlus()
{
	return m_FontPlus;
}

void InsertCredit::loadCreditElements(SDL_Renderer* renderer)
{

	setElementsFont();

	setElementsPositionDimension();

	setElementsColor();

	m_FontCreditRect.loadTextureFromFile("Resources/Images/creditRect.png", renderer);

	SDL_RenderCopy(renderer, m_FontCreditRect.getKTexture(),
			NULL, m_FontCreditRect.getKRect());

	m_FontInsertCredit.LoadFromRenderedText("INSERT CREDIT", renderer,
			m_FontInsertCredit.getButtonColor());

	m_FontInsertCredit.textRender(m_FontInsertCredit.getKRect(),
			m_FontInsertCredit.getKTexture(), renderer);

	m_FontPlus.LoadFromRenderedText("+", renderer, m_FontPlus.getButtonColor());

	m_FontPlus.textRender(m_FontPlus.getKRect(), m_FontPlus.getKTexture(),
			renderer);

	m_FontMinus.LoadFromRenderedText("-", renderer,
			m_FontMinus.getButtonColor());

	m_FontMinus.textRender(m_FontMinus.getKRect(), m_FontMinus.getKTexture(),
			renderer);

	m_FontCredit.LoadFromRenderedText(toString(m_credit), renderer,
			m_FontCredit.getButtonColor());

	m_FontCredit.textRender(m_FontCredit.getKRect(), m_FontCredit.getKTexture(),
			renderer);

}

void InsertCredit::setElementsFont()
{

	m_FontInsertCredit.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 40));

	m_FontPlus.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 40));

	m_FontMinus.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 40));

	m_FontCredit.setFont(TTF_OpenFont("Resources/Fonts/Blazed.ttf", 40));

}

void InsertCredit::setElementsPositionDimension()
{

	m_FontInsertCredit.setPosition(742, 445, introButton_width,
			introButton_height);

	m_FontPlus.setPosition(910, 545, introVolumeButtons_width,
			introVolumeButtons_height);

	m_FontMinus.setPosition(742, 545, introVolumeButtons_width,
			introVolumeButtons_height);

	m_FontCredit.setPosition(823, 548, introVolumeButtons_width,
			introVolumeButtons_height);

	m_FontCreditRect.setPosition(782, 531, introVolumeSlider_width,
			introVolumeSlider_height);

}

void InsertCredit::setElementsColor()
{
	m_FontCredit.setButtonColor(251, 211, 72);

	if (m_FontPlus.onMouseOver(m_FontPlus.getKRect()))
	{
		m_FontPlus.setButtonColor(255, 0, 39);
	}
	else
	{
		m_FontPlus.setButtonColor(251, 211, 72);
	}
	if (m_FontMinus.onMouseOver(m_FontMinus.getKRect()))
	{
		m_FontMinus.setButtonColor(255, 0, 39);
	}
	else
	{
		m_FontMinus.setButtonColor(251, 211, 72);
	}

	m_FontInsertCredit.setButtonColor(251, 211, 72);

	m_FontCredit.setButtonColor(251, 211, 72);


}

Font& InsertCredit::getFontCreditRect()
{
	return m_FontCreditRect;
}

void InsertCredit::setCreditToGame(SDL_Event* e)
{

	if (e->type == SDL_MOUSEBUTTONDOWN)
	{
		if (m_FontPlus.onMouseOver(m_FontPlus.getKRect()))
		{

			m_credit+=10;
		}
		if (m_FontMinus.onMouseOver(m_FontMinus.getKRect()))
		{
			if(m_credit > 10)
			{
			m_credit-=10;
			}
		}

	}
}
const char * InsertCredit::toString(int in_val)
{
	std::string str = boost::lexical_cast<std::string>(in_val);

	return str.c_str();
}
