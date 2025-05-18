#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

// should probably add those two constant here, plus tripple check the private/public is logical.
// but here or the phonebook hpp?? can one use the other??

class Contact
{
	public:
		// default co-and-de-structors are fine????
		void fillFromInput(); // uses askValidInput to linearly fill out contacts
		void printRow(int index) const; // print 4-column view
		void printCard() const; // print full contact card
		static std::string formatInput(const std::string& input); // truncate to fit in 10 char column
		// does the above need to be static in fact????

		// !! double check what needs to be public and private, and static or const or not and exactly why

	private:
		static std::string _askValidInput(const std::string&input); // promting loop checking for empty input or ctrl-d interrupts
		
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif