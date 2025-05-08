#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int main()
{
	PhoneBook app;
	std::string cmd;
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
	}
	return 0;
}