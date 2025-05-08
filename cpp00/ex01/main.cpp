#include "PhoneBook.hpp"
#include <string>
#include <iostream>

// testing: need to ensure the oldest element is replaced when a new one is entered
// when there are already 8 contacts (the max)
// also, in the subject it specifies that saved contacts can't have empty fields
// so i guess we need to make sure there are alpha chars in the inputted strings (not just spaces etc)
// subject also specifies that any other input is ignored so i guess i have to delete the invalid command prompt??
// should the list be indexed from 0 or 1?? specified in the subject??

int main()
{
	PhoneBook app;
	std::string cmd;
	std::cout	<< "Welcome to your highly advanced PhoneBook App!" << std::endl
				<< "Usage: type \"ADD\" to add a contact, \"SEARCH\" to see list or \"EXIT\" to quit."
				<< std::endl;
	while (true)
	{
		std::cout << "> " << std::flush; // maybe add some text explaining he usage keywords
		if (!std::getline(std::cin, cmd))
			break; // handle ctrl+d while in menu
		if (cmd == "ADD")
			app.add();
		else if (cmd == "SEARCH")
			app.search();
		else if (cmd == "EXIT")
			break; // this loops around to the first if() or a return is better here???
		//else
		//	std::cout << "Invalid command, try \"ADD\", \"SEARCH\" or \"EXIT\"." << std::endl;
	} // should  add a catch-all here that reminds the user of the commands if they enter wrongly???
	return 0;
}