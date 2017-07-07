#ifndef XML_H_
#define XML_H_
#include <iostream>
#include "pugixml.hpp"
#include "pugiconfig.hpp"
#include <fstream>

class XML {
	public:
		XML();
		XML(const char *);
		void traverse() const;
		void write(const char *);
	private:
		pugi::xml_document doc;	
};

#endif //XML.h
