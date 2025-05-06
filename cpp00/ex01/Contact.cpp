#include <string>
#include <iostream>
#include <sstream>
// #include <iomanip> // needed?

#include "Contact.hpp"

// no con-or-destructors needed????

void Contact::fillFromInput()
{
	_firstName = _askValidInput("First Name: ");
	_lastName = _askValidInput("Last Name: ");
	_phoneNumber = _askValidInput("Phone Number: ");
	_darkestSecret = _askValidInput("Darkest Secret: ");
}

//printrow
void Contact::printRow(int index) const
{
	std::ostringstream convertedIndex;
	convertedIndex << index;
	
	std::cout	<< formatInput(convertedIndex.str()) << '|'
				<< formatInput(_firstName) << '|'
				<< formatInput(_lastName) << '|'
				<< formatInput(_nickName) << '\n';
} // is this formatting good or not? and newlines are necessary here instead of endl or not?????

//printcard // TO-DO!!!

std::string Contact::formatInput(const std::string& input)
{
	if (input.length() > 10) // maybe should define a maxwidth var in the .hpp???
		return input.substr(0, 9) + '.';
	else if (input.length() < 10)
		return std::string(10 - input.length(), ' ') + input;
	else
		return input; // could probably shorten this function to the first if then the second could run as a catch-all
}

std::string Contact::_askValidInput(const std::string& prompt)
{
	std::string input;
	while (true)
	{
		std::cout << prompt << std::flush; // flush to ensure direct display of prompt
		if (!std::getline(std::cin, input) || !input.empty())
			return input;
		std::cout << "Field cannot be empty" << std::endl; // is flushing here a risk??
	}
}