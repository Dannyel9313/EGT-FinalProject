#ifndef MINBET_H_
#define MINBET_H_
#include "Font.h"
#include "BaseObject.h"

class MinBet 
{
	public:
		MinBet();
		virtual ~MinBet();


		//Render min bet
		void renderMinBet(SDL_Renderer* renderer);

		//Change color on mouse button
		void changeColorOnMouseOver(SDL_Renderer* renderer);

		//Activate min bet
		void activateMinButton(SDL_Renderer* renderer);

		//Bet choice min
		void betChoiceMin(SDL_Renderer* renderer, const SDL_Event& e);

		//Deactivate min bet
		void deactivateMinButton(SDL_Renderer* renderer);

		// Get minimal bet
		Font& getMinBet();

		// Get bet five
		Font& getNumFive();

		// Get bet four
		Font& getNumFour();

		// Get bet one
		Font& getNumOne();

		// Get bet ten
		Font& getNumTen();

		// Get bet three
		Font& getNumThree();

		// Get bet two
		Font& getNumTwo();

		// Get button rect
		BaseObject& getButtonRect();

		// Get button circle
		BaseObject& getButtonStartCircle();

		// Get minimal bet
		int getMinimalBet() const;

		// Get minimal bet
		void setMinimalBet(int minimalBet);

	private:
		int m_MinimalBet;

		Font m_numOne;
		Font m_numTwo;
		Font m_numThree;
		Font m_numFour;
		Font m_numFive;
		Font m_numTen;

		Font m_minBet;

		BaseObject m_buttonRect;
		BaseObject m_buttonStartCircle;

		//Set font
		void setFont();

		//Set numbers Color
		void setNumbersColor();

		//Set elements position and dimension
		void setElementsPositionDimension();

		//Load elements
		void loadElements(SDL_Renderer* renderer);

		//Change color of number one
		void choiceNumberOne(SDL_Renderer* renderer, const SDL_Event& e);

		//Change color of number two
		void choiceNumberTwo(SDL_Renderer* renderer, const SDL_Event& e);

		//Change color of number tree
		void choiceNumberThree(SDL_Renderer* renderer, const SDL_Event& e);

		//Change color of number four
		void choiceNumberFour(SDL_Renderer* renderer, const SDL_Event& e);

		//Change color of number five
		void choiceNumberFive(SDL_Renderer* renderer, const SDL_Event& e);

		//Change color of number ten
		void choiceNumberTen(SDL_Renderer* renderer, const SDL_Event& e);

};

#endif /* MINBET_H_ */
