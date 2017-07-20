#include "Volume.h"

Volume::Volume()
{
	// TODO Auto-generated constructor stub
	m_movingPoint = 129;
	m_volumePoint = 50;
}

Volume::~Volume()
{
	// TODO Auto-generated destructor stub
}

Font& Volume::getFontDot()
{
	return m_FontDot;
}

Font& Volume::getFontDotLine()
{
	return m_FontDotLine;
}

Font& Volume::getFontMinus()
{
	return m_FontMinus;
}

Font& Volume::getFontPlus()
{
	return m_FontPlus;
}

void Volume::LoadVolumeElements(SDL_Renderer* renderer)
{

	setElementsFont();
	setElementsPositionDimension();
	setElementsColor();

	m_FontDotLine.loadTextureFromFile("Resources/Images/volumeSlider.png", renderer);

	SDL_RenderCopy(renderer, m_FontDotLine.getKTexture(), NULL,
			m_FontDotLine.getKRect());

	m_FontDot.loadTextureFromFile("Resources/Images/volumeDot.png", renderer);

	SDL_RenderCopy(renderer, m_FontDot.getKTexture(), NULL,
			m_FontDot.getKRect());

	m_FontPlus.LoadFromRenderedText("+", renderer, m_FontPlus.getButtonColor());

	m_FontPlus.textRender(m_FontPlus.getKRect(), m_FontPlus.getKTexture(),
			renderer);

	m_FontMinus.LoadFromRenderedText("-", renderer,
			m_FontMinus.getButtonColor());

	m_FontMinus.textRender(m_FontMinus.getKRect(), m_FontMinus.getKTexture(),
			renderer);

	m_FontVolume.LoadFromRenderedText("VOLUME", renderer,
			m_FontVolume.getButtonColor());

	m_FontVolume.textRender(m_FontVolume.getKRect(), m_FontVolume.getKTexture(),
			renderer);

}

void Volume::setElementsPositionDimension()
{
	m_FontDotLine.setPosition(83, 531, introVolumeSlider_width,
			introVolumeSlider_height);

	m_FontDot.setPosition(m_movingPoint, 548, introVolumeDot_width,
			introVolumeDot_height);

	m_FontPlus.setPosition(203, 545, introVolumeButtons_width,
			introVolumeButtons_height);

	m_FontMinus.setPosition(43, 545, introVolumeButtons_width,

	introVolumeButtons_height);

	m_FontVolume.setPosition(43, 445, introButton_width, introButton_height);
}

void Volume::setElementsFont()
{

	m_FontPlus.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 40));
	m_FontMinus.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 40));
	m_FontVolume.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 40));
}

void Volume::moveVolumeDot(SDL_Event* e)
{

	if (e->type == SDL_MOUSEBUTTONDOWN)
	{
		if(m_movingPoint < 80 || m_volumePoint < 9)
		{
				m_movingPoint = 79;
				m_volumePoint = 0;
			}
			if(m_movingPoint > 169 || m_volumePoint > 108)
			{
				m_movingPoint = 169;
				m_volumePoint = 100;
			}
		if (m_FontPlus.onMouseOver(m_FontPlus.getKRect()))
		{
			if (m_volumePoint > -1 && m_volumePoint < 101 && m_movingPoint > 78
					&& m_movingPoint < 169)
			{

				m_volumePoint+=10;
				m_movingPoint+=10;

				Mix_VolumeMusic(m_volumePoint);

			}
		}
		if(m_FontMinus.onMouseOver(m_FontMinus.getKRect()))
		{
			if (m_volumePoint > 9 && m_volumePoint < 101 && m_movingPoint > 78
					&& m_movingPoint < 178)
			{

				m_volumePoint-=10;
				m_movingPoint-=10;

				Mix_VolumeMusic(m_volumePoint);

			}
		}

	}
}

void Volume::setElementsColor()
{
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
	m_FontVolume.setButtonColor(251, 211, 72);
}

Font& Volume::getFontVolume()
{
	return m_FontVolume;
}

int Volume::getMovingPoint() const
{
	return m_movingPoint;
}

void Volume::setMovingPoint(int movingPoint)
{
	m_movingPoint = movingPoint;
}

Font& Volume::getFontChanelClick()
{
	return m_FontChanelClick;
}

int Volume::getVolumePoint() const
{
	return m_volumePoint;
}

void Volume::setVolumePoint(int volumePoint)
{
	m_volumePoint = volumePoint;
}
