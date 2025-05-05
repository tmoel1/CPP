#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	public:
	// default co-and-de-structors are fine?
	void fillFromInput();
	void printRow(index) const;
	void printCard() const;

	private:
	// do i need a truncation/right-alignment function here?
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif