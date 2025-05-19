#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>


PhoneBook::PhoneBook() : _count(0), _next(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::_printHeader() const
{
	std::cout	<< std::setw(10) << "Index" << '|'
				<< std::setw(10) << "First Name" << '|'
				<< std::setw(10) << "Last Name" << '|'
				<< std::setw(10) << "Nickname" << std::endl;
}

void PhoneBook::add()
{
	_contacts[_next].fillFromInput();
	if (_count < kMaxContacts)
		_count++;
	_next = (_next + 1) % kMaxContacts;
}

void PhoneBook::search() const
{
	if (_count == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return;
	}
	_printHeader();
		for (int i = 0; i < _count; i++)
		_contacts[i].printRow(i);
	std::cout << "Select Index to display: " << std::flush;
	std::string prompt;
	if (!std::getline(std::cin, prompt))
		return;
	int index;
	std::istringstream indexStream(prompt);
	if (!(indexStream >> index) || index < 0 || index >= _count)
		std::cout << "Invalid Index, returning you to main menu" << std::endl;
	else
		_contacts[index].printCard();
}