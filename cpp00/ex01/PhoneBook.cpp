//phonebook cpp code

//can probably do without a isValidIndex function, also in the .hpp header

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>


PhoneBook::PhoneBook() : _count(0), _next(0) {}

void PhoneBook::_printHeader() const
{
	std::cout	<< std::setw(10) << "Index" << '|'
				<< std::setw(10) << "First Name" << '|'
				<< std::setw(10) << "Last Name" << '|'
				<< std::setw(10) << "Nickname" << std::endl; //definitely no need to truncate here right??
}

void PhoneBook::add()
{
	_contacts[_next].fillFromInput();
	if (_count < 8)
		_count++;
	_next = (_next + 1) % 8; // in this function the two '8's should probably be replaced with a const in the hpp??
}

void PhoneBook::search() const
{
	if (_count == 0) // can we write it like if (!_count) ???
	{
		std::cout << "Phonebook is empty" << std::endl;
		return;
	}
	_printHeader();
		for (int i = 0; i < _count; i++) // should we pre-increment with ++i instead?
		_contacts[i].printRow(i);
	std::cout << "Select Index to display: " << std::flush; // no need for newline??
	std::string prompt;
	if (!std::getline(std::cin, prompt))
		return;
	int index;
	std::istringstream indexStream(prompt);
	if (!(indexStream >> index) || index < 0 || index > _count)
		std::cout << "Invalid Index" << std::endl;
	// int index = std:;atoi(line.c_str());
	// if (index < 0 || index > _count)
		// invalid
	// this commented version is more c-style but maybe more simple?
	else
		_contacts[index].printCard();
}