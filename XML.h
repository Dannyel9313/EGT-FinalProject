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
		void write(int, int, int*);

		//Get credits
		int getCredits() const;
		int getBonus() const;

		int* getUserChoices();
	private:
		//Utility function to convert int to string
		const char* ToString(int);

		//Utility function to convert int to string
		int toInt(char);

		//Documents
		pugi::xml_document doc;	

		//Saved credits
		int credits;

		//Bonus
		int bonus;

		//Saved user choices
		int* userChoices;	
};

#endif //XML.h
