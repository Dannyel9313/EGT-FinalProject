/*
 * BaseObject.cpp
 *
 *  Created on: 06.07.2017
 *      Author: Danny
 */
#include <iostream>
#include "BaseObject.h"

BaseObject::BaseObject() {
	this->m_KTexture = NULL;
	this->m_KRect = NULL;
	this->m_Width = 0;
	this->m_Height = 0;
	// TODO Auto-generated constructor stub

}

BaseObject::~BaseObject() {
	// TODO Auto-generated destructor stub
}

SDL_Texture* BaseObject::loadTexture(std::string picPath) {

	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(picPath.c_str());
	if (loadedSurface == NULL) {
		std::cerr << "The surface can not be created !" << std::endl;
	} else {
		SDL_SetColorKey(loadedSurface, SDL_TRUE,
				SDL_MapRGB(loadedSurface->format, 255, 255, 255));
		newTexture = SDL_CreateTextureFromSurface(GameKeno::kenoRenderer,
				loadedSurface);
		if (newTexture == NULL) {
			std::cerr << "The texture can not be created !" << std::endl;
		} else {
			m_Width = loadedSurface->w;
			m_Height = loadedSurface->h;

		}
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

void BaseObject::free() {
	//Free texture if it exists
	if (m_KTexture != NULL) {
		SDL_DestroyTexture(m_KTexture);
		m_KTexture = NULL;
		m_Width = 0;
		m_Height = 0;
	}
}

int BaseObject::getHeight() const {
	return m_Height;
}

void BaseObject::setHeight(int height) {
	m_Height = height;
}

SDL_Rect*& BaseObject::getKRect() {
	return m_KRect;
}

SDL_Texture*& BaseObject::getKTexture() {
	return m_KTexture;
}

int BaseObject::getWidth() const {
	return m_Width;
}

void BaseObject::setPosition(int x, int y) {
	this->m_KRect->x = x;
	this->m_KRect->y = y;

}

void BaseObject::setWidth(int width) {
	m_Width = width;
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
