#include "BaseObject.h"

BaseObject::BaseObject() 
{
	this->m_KTexture = NULL;
	this->m_chunkClick = NULL;
}

BaseObject::~BaseObject() 
{
	free();
}

bool BaseObject::isClicked(SDL_Rect* rect) {
	int x,y;
	SDL_GetMouseState(&x, &y);

		if (x >= rect->x && x <= rect->x + rect->w && y >= rect->y
				&& y <= rect->y + rect->h) 
		{
			return true;
		}

	return false;
}

bool BaseObject::isClicked(const SDL_Event & e, SDL_Rect * rect) const
{
        bool check = false;

        int x, y;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
                bool inside = true;
                SDL_GetMouseState(&x, &y);
                if (x < rect->x)
                {
                        inside = false;
                }
                else if (y < rect->y)
                {
                        inside = false;
                }
                else if (x > rect->x + rect->w)
                {
                        inside = false;
                }
                else if (y > rect->y + rect->h)
                {
                        inside = false;
                }
                if (inside)
                {
                        check = true;
                }
        }
        return check;
}


bool BaseObject::loadTextureFromFile(std::string picPath, SDL_Renderer * renderer) 
{

	free();

	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(picPath.c_str());
	if (loadedSurface == NULL) 
	{
		std::cerr << "The surface can not be created !" << std::endl;
	} 
	else 
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE,
				SDL_MapRGB(loadedSurface->format, 255, 255, 255));
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL) 
		{
			std::cerr << "The texture can not be created !" << std::endl;
		}
		SDL_FreeSurface(loadedSurface);
	}
	m_KTexture = newTexture;
}

bool BaseObject::loadTextureFromTTF(std::string text, SDL_Renderer* renderer,
                                        TTF_Font* font, const SDL_Color& textColor)
{
	free();

        //Success flag  
        bool success = true;

        //Final texture
        SDL_Texture * newTexture = NULL;

        //Load image at specified path
        SDL_Surface * textSurface = TTF_RenderText_Blended(font, text.c_str(), textColor);
        if (textSurface == NULL)
        {
                std::cout << "Unable to load image from file! " << text << " "
                        << IMG_GetError() << std::endl;
        }
        else
        {
                //Create texture from surface
                newTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                if (newTexture == NULL)
                {
                        std::cout << "Unable to create texture from surface! " << text.c_str() <<
                                " " << SDL_GetError() << std::endl;
                }
                //Free the surface
                SDL_FreeSurface(textSurface);
        }

        this->m_KTexture = newTexture;

        //Return success
        return m_KTexture != NULL;
}


void BaseObject::free() 
{
	//Free texture if it exists
	if (m_KTexture != NULL) 
	{
		SDL_DestroyTexture(m_KTexture);
		m_KTexture = NULL;
	}
	if (m_chunkClick != NULL)
	{
		Mix_FreeChunk(m_chunkClick);
	}
}

void BaseObject::loadChunkEfect() 
{
	m_chunkClick = Mix_LoadWAV("Select.wav");
}

Mix_Chunk*& BaseObject::getChunkClick() 
{
	return m_chunkClick;
}

SDL_Rect* BaseObject::getKRect() 
{
	return &m_KRect;
}

SDL_Texture* BaseObject::getKTexture() 
{
	return m_KTexture;
}

SDL_Rect BaseObject::setPosition(int x, int y,int w, int h) 
{
	this->m_KRect.x = x;
	this->m_KRect.y = y;
	this->m_KRect.w = w;
	this->m_KRect.h = h;

	return m_KRect;
}

void BaseObject::setPosition(int x, int y)
{
	this->m_KRect.x = x;
	this->m_KRect.y = y;
}

void BaseObject::setDimensions(int w, int h) 
{
	this->m_KRect.w = w;
	this->m_KRect.h = h;
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

void BaseObject::setKTexture(SDL_Texture* kTexture) 
{
	m_KTexture = kTexture;
}

//void BaseObject::buttonRender(int xCut, int yCut, int x, int y,
//		SDL_Texture* texture, SDL_Renderer* renderer) {
//	SDL_Rect buttonRect = { x, y, introVolumeButtons_width,
//			introVolumeButtons_height };
//	SDL_Rect cutButtonRect = { xCut, yCut, introVolumeButtonsCut_width,
//			introVolumeButtonsCut_height };
//	SDL_RenderCopy(renderer, texture, &cutButtonRect, &buttonRect);
//
//}

void BaseObject::render(SDL_Renderer * renderer, SDL_Rect * whereTo)
{
        SDL_RenderCopy(renderer, m_KTexture, NULL, whereTo);
}

