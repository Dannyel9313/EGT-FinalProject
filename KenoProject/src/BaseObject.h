/*
 * BaseObject.h
 *
 *  Created on: 06.07.2017
 *      Author: Danny
 */
#include "Globals.h"
#ifndef BASEOBJECT_H_
#define BASEOBJECT_H_

#include "GameKeno.h"

class BaseObject: public GameKeno {
public:
	BaseObject();
	virtual ~BaseObject();

	//load image
	SDL_Texture* loadTexture(std::string picPath);

	//set rect position
	void setPosition(int x, int y);

	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	//set alpha modulation
	void setAlpha(Uint8 alpha );

	//Deallocates texture
	void free();

	int getHeight() const;
	void setHeight(int height);
	SDL_Rect*& getKRect();

	SDL_Texture*& getKTexture();

	int getWidth() const;
	void setWidth(int width);

private:

	SDL_Texture* m_KTexture;
	SDL_Rect* m_KRect;

	int m_Width;
	int m_Height;

};

#endif /* BASEOBJECT_H_ */
