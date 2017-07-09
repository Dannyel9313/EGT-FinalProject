#include "BaseObject.h"

BaseObject::BaseObject() {
	this->m_KTexture = NULL;
	this->m_KRect = NULL;
}

BaseObject::~BaseObject() {
}

void BaseObject::loadTexture(std::string picPath, SDL_Renderer * renderer) {

	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(picPath.c_str());
	if (loadedSurface == NULL) {
		std::cerr << "The surface can not be created !" << std::endl;
	} else {
		SDL_SetColorKey(loadedSurface, SDL_TRUE,
				SDL_MapRGB(loadedSurface->format, 247, 247, 247));
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL) {
			std::cerr << "The texture can not be created !" << std::endl;
		}
		SDL_FreeSurface(loadedSurface);
	}
	m_KTexture = newTexture;
}

void BaseObject::free(SDL_Texture* textureToFree) {
	//Free texture if it exists
	if (textureToFree != NULL) {
		SDL_DestroyTexture(textureToFree);
		textureToFree = NULL;
	}
//	this->m_KRect = NULL;
}

SDL_Rect* BaseObject::getKRect() {
	return m_KRect;
}

SDL_Texture* BaseObject::getKTexture() {
	return m_KTexture;
}

SDL_Rect* BaseObject::setPosition(int x, int y) {
	this->m_KRect->x = x;
	this->m_KRect->y = y;
	this->m_KRect->w = introButton_width;
	this->m_KRect->h = introButton_height;

	return m_KRect;
}

void BaseObject::setDimensions(int w, int h) {
	this->m_KRect->w = w;
	this->m_KRect->h = h;
}

void BaseObject::setColor(Uint8 red, Uint8 green, Uint8 blue) {
	//Modulate texture rgb
	SDL_SetTextureColorMod(m_KTexture, red, green, blue);
}

void BaseObject::setBlendMode(SDL_BlendMode blending) {
	//Set blending function
	SDL_SetTextureBlendMode(m_KTexture, blending);
}

void BaseObject::setAlpha(Uint8 alpha) {
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(m_KTexture, alpha);
}

void BaseObject::setKTexture(SDL_Texture* kTexture) {
	m_KTexture = kTexture;
}
void BaseObject::buttonRender(int xCut, int yCut, int x, int y,
		SDL_Texture* texture, SDL_Renderer* renderer) {
	SDL_Rect buttonRect = { x, y, introVolumeButtons_width,
			introVolumeButtons_height };
	SDL_Rect cutButtonRect = { xCut, yCut, introVolumeButtonsCut_width,
			introVolumeButtonsCut_height };
	SDL_RenderCopy(renderer, texture, &cutButtonRect, &buttonRect);

}
