#include "BetButton.h"

BetButton::BetButton()
{
	//Set bet button position and dimensions
	setPosition(betButton_x, betButton_y);
	setDimensions(betButton_width, betButton_height);
}

void BetButton::betText(SDL_Renderer* renderer)
{
	//Set color
	m_font.setFontColor(0, 0, 0);

	//Set bet text position and dimensions
	m_font.setPosition(getKRect().x+betText_xIndent, getKRect().y+betText_yIndent);
	m_font.setDimensions(betText_width, betText_height);

	//Load bet text
	m_font.loadTextureFromTTF("Bet", renderer, m_font.getFont(), m_font.getFontColor());

	//Render bet text
	m_font.render(renderer, &m_font.getKRect());
}

bool BetButton::buttonCondition(int condition, SDL_Renderer* renderer)
{
	bool success = false;
	//If less than 2 numbers clicked transperent button nothing happens if clicked
	if (condition < minimumSpots) 
	{
		setAlpha(50);
		render(renderer, &getKRect()); 
		betText(renderer);
		success = false;
	}
	else if (condition >= minimumSpots) 
	{
		setAlpha(255);
		render(renderer, &getKRect());
		betText(renderer);
		success = true;
	}
	return success;
}

Font& BetButton::getFont()
{
	return m_font;
}
