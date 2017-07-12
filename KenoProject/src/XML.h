#ifndef XML_H_
#define XML_H_

#include "Include.h"
#include <fstream>

class XML {
	public:
		//Constructor
		XML();

		//Read saved credits
		void readCredit() const;
	
		//Read saved user choices
		void readUserChoices() const;
	
		//Write in XML receive Credits(int), FlagsForPosition(int [][]);
		void write(int, int [8][10]);
	private:
		//Utility function to convert int to string
		const char* ToString(int);

		//Documents
		pugi::xml_document doc;	
};

#endif //XML.h
