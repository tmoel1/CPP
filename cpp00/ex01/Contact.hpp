#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	public:
		Contact();
		~Contact();

		void fillFromInput();
		void printRow(int index) const;
		void printCard() const;
		static std::string truncateInput(const std::string& input);
		
	private:
		static std::string _askValidInput(const std::string&input);
		
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif