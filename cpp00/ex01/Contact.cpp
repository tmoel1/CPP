#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

Contact::Contact() {}
Contact::~Contact() {}

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
	std::ostringstream convertedIndex;
	convertedIndex << index;
	
	std::cout	<< std::setw(10) << truncateInput(convertedIndex.str()) << '|'
				<< std::setw(10) << truncateInput(_firstName) << '|'
				<< std::setw(10) << truncateInput(_lastName) << '|'
				<< std::setw(10) << truncateInput(_nickName) << std::endl;
}

void Contact::printCard() const
{
	std::cout	<< "First Name: " << _firstName << std::endl
				<< "Last Name: " << _lastName << std::endl
				<< "Nickname: " << _nickName << std::endl
				<< "Phone Number: " << _phoneNumber << std::endl
				<< "Darkest Secret: " << _darkestSecret << std::endl;
}

std::string Contact::truncateInput(const std::string& input)
{
	if (input.length() > 10)
		return input.substr(0, 9) + '.';
	else
		return input;
}

std::string Contact::_askValidInput(const std::string& prompt) 
{
	std::string input;
	while (true)
	{
		std::cout << prompt << std::flush;
		if (!std::getline(std::cin, input))
			return input;
		if (input.find_first_not_of(" \t\n\r\f\v") != std::string::npos)
			return input;
		std::cout << "Field cannot be empty" << std::endl;
	}
}