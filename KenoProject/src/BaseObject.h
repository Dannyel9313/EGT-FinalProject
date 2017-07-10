#ifndef BASEOBJECT_H_
#define BASEOBJECT_H_
#include "Include.h"
#include "Globals.h"


class BaseObject 
{
	public:
		//Constructor
		BaseObject();
	
		//Destructor
		virtual ~BaseObject();

		// button renderer
		void buttonRender(int xCut, int yCut, int x, int y, SDL_Texture* texture, SDL_Renderer* renderer);

		// verify if is click
		bool isClicked(int x, int y);

		//Load image from texture
		void loadTexture(std::string picPath, SDL_Renderer*);

		//Set rect position
		SDL_Rect setPosition(int x, int y,int w, int h);

		//Set rect dimensions
		void setDimensions(int w, int h);

		//Set color modulation
		void setColor(Uint8 red, Uint8 green, Uint8 blue);

		//Set blending
		void setBlendMode(SDL_BlendMode blending);

		//set alpha modulation
		void setAlpha(Uint8 alpha);

		//Deallocates texture
		void free(SDL_Texture* textureToFree);

		//Get m_KTexture
		SDL_Rect* getKRect();

		//Get m_KRect
		SDL_Texture* getKTexture();

		void setKTexture(SDL_Texture* kTexture);



	private:
		SDL_Texture* m_KTexture;
		SDL_Rect m_KRect;


};

#endif /* BASEOBJECT_H_ */
