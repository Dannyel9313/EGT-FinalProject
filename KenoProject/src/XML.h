#ifndef XML_H_
#define XML_H_

#include "Include.h"
#include <fstream>

class XML 
{
	public:
		//Constructor
		XML();

		~XML();

		//Read credits, position of flags
		void read(const char*);
		
		//Write in XML receive Credits(int), bonus, FlagsForPosition(int [][]);
		void write(int, int, int, int*, bool, bool, bool);

		//Get credits
		int getCredits() const;
	
		//Get bonus
		int getBonus() const;

		//Get bet
		int getBet() const;

		//Get min-max bet flag
		bool getMinBetFlag() const;
		bool getMaxBetFlag() const;
		bool getSetBetFlag() const;
		

		int* getUserChoices();
	private:
		//Utility function to convert int to string
		template <typename T>
		const char* ToString(T);

		//Utility function to convert int to string
		int toInt(char);

		//Documents
		pugi::xml_document doc;	

		//Bet
		int bet;

		//Saved credits
		int credits;

		//Bonus
		int bonus;

		//Saved user choices
		int* userChoices;	
	
		//Bet flags
		bool minBetFlag;
		bool maxBetFlag;
		bool setBetFlag;
};

#endif //XML.h
