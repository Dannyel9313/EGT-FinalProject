#ifndef BASEOBJECT_H_
#define BASEOBJECT_H_

#include "Globals.h"
#include "GameKeno.h"

class BaseObject 
{
	public:
		//Constructor
		BaseObject();
	
		//Destructor
		virtual ~BaseObject();

		//Load image from texture
		SDL_Texture* loadTexture(std::string picPath, SDL_Renderer*);

		//Set rect position
		void setPosition(int x, int y);

		//Set rect dimensions
		void setDimensions(int w, int h);

		//Set color modulation
		void setColor(Uint8 red, Uint8 green, Uint8 blue);

		//Set blending
		void setBlendMode(SDL_BlendMode blending);

		//set alpha modulation
		void setAlpha(Uint8 alpha);

		//Deallocates texture
		void free();

		//Get m_KTexture
		const SDL_Rect* getKRect();

		//Get m_KRect
		const SDL_Texture* getKTexture();

	private:
		SDL_Texture* m_KTexture;
		SDL_Rect* m_KRect;
};

#endif /* BASEOBJECT_H_ */
