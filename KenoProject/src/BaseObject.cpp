#include "BaseObject.h"

BaseObject::BaseObject() 
{
	this->m_KTexture = NULL;
	this->m_KRect = NULL;
}

BaseObject::~BaseObject() {}

SDL_Texture* BaseObject::loadTexture(std::string picPath, SDL_Renderer * renderer) 
{

	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(picPath.c_str());
	if (loadedSurface == NULL) 
	{
		std::cerr << "The surface can not be created !" << std::endl;
	} 
	else 
	{
		newTexture = SDL_CreateTextureFromSurface(renderer,
				loadedSurface);
		if (newTexture == NULL) 
		{
			std::cerr << "The texture can not be created !" << std::endl;
		} 
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}

void BaseObject::free() 
{
	//Free texture if it exists
	if (m_KTexture != NULL) 
	{
		SDL_DestroyTexture(m_KTexture);
		m_KTexture = NULL;
	}
	this->m_KRect = NULL;
}

const SDL_Rect* BaseObject::getKRect() 
{
	return m_KRect;
}

const SDL_Texture* BaseObject::getKTexture() 
{
	return m_KTexture;
}

void BaseObject::setPosition(int x, int y) 
{
	this->m_KRect->x = x;
	this->m_KRect->y = y;
}

void BaseObject::setDimensions(int w, int h)
{
	this->m_KRect->w = w;
	this->m_KRect->h = h;
}

void BaseObject::setColor(Uint8 red, Uint8 green, Uint8 blue) 
{
	//Modulate texture rgb
	SDL_SetTextureColorMod(m_KTexture, red, green, blue);
}

void BaseObject::setBlendMode(SDL_BlendMode blending) 
{
	//Set blending function
	SDL_SetTextureBlendMode(m_KTexture, blending);
}

void BaseObject::setAlpha(Uint8 alpha) 
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(m_KTexture, alpha);
}
