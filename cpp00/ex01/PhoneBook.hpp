#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		
		void add();
		void search() const;

	private:
		void _printHeader() const;
		
		Contact _contacts[8];
		int _count;
		int _next;
		static const int kMaxContacts = 8;
};

#endif