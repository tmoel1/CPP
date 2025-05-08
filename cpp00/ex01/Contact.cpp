#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

// no con-or-destructors needed????

void Contact::fillFromInput()
{
	_firstName = _askValidInput("First Name: ");
	_lastName = _askValidInput("Last Name: ");
	_nickName = _askValidInput("Nickname: ");
	_phoneNumber = _askValidInput("Phone Number: ");
	_darkestSecret = _askValidInput("Darkest Secret: ");
}

void Contact::printRow(int index) const
{
	std::ostringstream convertedIndex; // should i use just stringstream for both in and out operations?
	convertedIndex << index;
	
	std::cout	<< std::setw(10) << formatInput(convertedIndex.str()) << '|'
				<< std::setw(10) << formatInput(_firstName) << '|'
				<< std::setw(10) << formatInput(_lastName) << '|'
				<< std::setw(10) << formatInput(_nickName) << std::endl; // probably should endl here
} // is this formatting good or not? and newlines are necessary here instead of endl or not?????

void Contact::printCard() const
{
	std::cout	<< "First Name: " << _firstName << std::endl
				<< "Last Name: " << _lastName << std::endl
				<< "Nickname: " << _nickName << std::endl
				<< "Phone Number: " << _phoneNumber << std::endl // this is stringified right??
				<< "Darkest Secret: " << _darkestSecret << std::endl;
}

std::string Contact::formatInput(const std::string& input)
{
	if (input.length() > 10) // maybe should define a maxwidth var in the .hpp??? we can without a constructor if it's a static const
		return input.substr(0, 9) + '.';
	//else if (input.length() < 10)
	//	return std::string(10 - input.length(), ' ') + input; // remove this and use setw in the stream
	else
		return input; // could probably shorten this function to the first if, then the second could run as a catch-all
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
	} // a problem maybe here is that a string can be full of spaces and still count, is it ok?
}