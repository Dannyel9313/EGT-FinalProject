#ifndef WIN_H_
#define WIN_H_
#include "Include.h"
#include "BaseObject.h"
#include "Font.h"

class Win: public BaseObject
{
	public:
		Win();
		virtual ~Win();

		// render wining
		void renderWinInGame(SDL_Renderer* renderer);

		// Get circle of win
		BaseObject& getWinGameCircle();

		// Get win rectangle
		BaseObject& getWinGameRect();

		// Get win text in circle
		Font& getWinInGame();
	
		// Get win text in rectangle
		Font& getWinTextRect() ;

		void loadTexture(SDL_Renderer* renderer);

		// Loads "YOU HAVE WON" text
		void writeOnScreen(SDL_Renderer*, int);

		// Loads "Big win" text
		void bigWin(SDL_Renderer*, int);

		// Get win credits
		int getWinCredits() const;

		// Set win credits
		void setWinCredits(int winCredits);

		// Get chunk
		Mix_Chunk* getChunk();
	private:

		int m_winCredits;

		Font m_winInGame;
		Font m_winTextRect;

		BaseObject m_winGameRect;
		BaseObject m_winGameCircle;

		// cast to string
		std::string toString(int);

		// Set numbers Color
		void setColor();

		// Set elements position and dimension
		void setElementsPositionDimension();

		// Load elements
		void loadElements(SDL_Renderer* renderer);

		// Set font
		void setFont();

		Mix_Chunk* m_chunk;
		Font m_credits;
		Font Text;
		BaseObject mBackground;


};

#endif /* WIN_H_ */
