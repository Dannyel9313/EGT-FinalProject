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

		//Button renderer
		void buttonRender(int xCut, int yCut, int x, int y,
			 SDL_Texture* texture, SDL_Renderer* renderer);

		void render(SDL_Renderer *, SDL_Rect*);

		//Verify if is click
		bool onMouseOver(SDL_Rect* rect);
		bool isClicked(const SDL_Event&, SDL_Rect*) const;

		//Load image from texture
		void loadTextureFromFile(std::string picPath, SDL_Renderer*);

		// Load texture from ttf
		bool loadTextureFromTTF(std::string, SDL_Renderer*, TTF_Font*,const SDL_Color&);

		//Set rect position
		SDL_Rect setPosition(int x, int y,int w, int h);

		void setPosition(int x, int y);

		//Set rect dimensions
		void setDimensions(int w, int h);

		//Set color modulation
		void setColor(Uint8 red, Uint8 green, Uint8 blue);

		//Set blending
		void setBlendMode(SDL_BlendMode blending);

		//set alpha modulation
		void setAlpha(Uint8 alpha);

		//Set rect
		void setKRect(const SDL_Rect&);

		//Deallocates texture
		void free();

		//Get m_KTexture
		SDL_Rect* getKRect();

		//Get m_KRect
		SDL_Texture* getKTexture();

		void setKTexture(SDL_Texture* kTexture);

		void loadChunkEffect(std::string);

		//Mix_Chunk*& getChunkClick();
		//const std::vector& <Mix_Chunk*> getSoundEffects();

		void cropFromRenderTo(SDL_Renderer*, SDL_Rect*, SDL_Rect*);

		void playSoundEffect(int, int);
	private:
		SDL_Texture* m_KTexture;
		SDL_Rect m_KRect;

		//Mix_Chunk* m_chunkClick;
		std::vector <Mix_Chunk*> m_SoundEffects;
};

#endif
