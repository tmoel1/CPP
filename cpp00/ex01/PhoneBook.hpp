#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

//#include <string>  // not necessari in fact??
//#include <iostream>
//#include <iomanip>
#include "Contact.hpp"

// needs contact hpp?? yes because we declare an array of contacts??

class PhoneBook
{
	public:
		PhoneBook();
		
		void add();
		void search() const;

	private: // should private functions start with '_' ??
		bool _isValidIndex(int index) const;
		void _printHeader() const;
		
		Contact _contacts[8];
		// should we define as const/static the max # and column width?
		int _count;
		int _next;
};

#endif