#include "XML.h"

XML::XML() {}

const char* XML::ToString(int in_val) const;
{
	std::string s = boost::lexical_cast<std::string> (in_val);
	return s.c_str();
}

void XML::write(int credits, int array[8][10]) 
{
	//Specification node
	pugi::xml_node rootNode = doc.append_child(pugi::node_declaration);
    	rootNode.append_attribute("version")    = "1.0";
    	rootNode.append_attribute("encoding")   = "ISO-8859-1";

	//Main node
	pugi::xml_node node = doc.append_child("Recovery");

	//Credits
	pugi::xml_node descr = node.append_child("Credits");
	descr.append_child(pugi::node_pcdata).set_value(ToString(credits));

	//Flags
	pugi::xml_node flags = node.append_child("UserChoices");
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 10; j++)
		{
			flags.append_child(pugi::node_pcdata).set_value(ToString(array[i][j]));
		}
	}

	doc.save_file("Recovery.xml");
}


