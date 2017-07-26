#include "XML.h"

XML::XML() 
{
	userChoices = new int[80];
}

XML::~XML()
{
	delete[] userChoices;
	userChoices = NULL;
}

const char* XML::ToString(int in_val)
{
	std::string s = boost::lexical_cast<std::string> (in_val);
	return s.c_str();
}

int XML::toInt(char char_val)
{
	int number = boost::lexical_cast<int> (char_val);
	return number;
}

void XML::write(int bet, int credits, int bonus, int* choices)
{
	//Main node
	pugi::xml_node node = doc.append_child("Recovery");

	//Credits
	pugi::xml_node credit = node.append_child("Credits");
	credit.append_child(pugi::node_pcdata).set_value(ToString(credits));

	//Bonus
	pugi::xml_node bonusNode = node.append_child("Bonus");
	bonusNode.append_child(pugi::node_pcdata).set_value(ToString(bonus));

	//Bet
	pugi::xml_node betNode = node.append_child("Bet");
	betNode.append_child(pugi::node_pcdata).set_value(ToString(bet));

	//Flags
	pugi::xml_node choicesFlags = node.append_child("UserChoices");
	if(choices != NULL)
	{
		for (int i = 0; i < 80; i++) 
		{
			choicesFlags.append_child(pugi::node_pcdata)
				.set_value(ToString(choices[i]));
		}
	}

	doc.save_file("Recovery.xml");
}

void XML::read(const char* file) 
{
	std::string temp_one;

	if (!doc.load_file(file))
	{
		std::cout << "Error" << std::endl;
	}

	pugi::xml_node recovery = doc.child("Recovery");
	pugi::xml_node i = doc.last_child();
	credits = i.child("Credits").text().as_int();
	bonus = i.child("Bonus").text().as_int();
	bet = i.child("Bet").text().as_int();
	temp_one = i.child("UserChoices").text().as_string();
	if(!temp_one.empty())
	{
		for (int i = 0; i < 80; i++)
		{
			userChoices[i] = toInt(temp_one[i]);
		}
	}
}

int XML::getCredits() const
{
	return this->credits;
}

int* XML::getUserChoices() 
{
	return this->userChoices;
}

int XML::getBonus() const
{
	return this->bonus;
}

int XML::getBet() const
{
	return this->bet;
}
