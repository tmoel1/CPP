#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int main()
{
	PhoneBook app;
	std::string cmd;
	std::cout	<< "Welcome to your highly advanced PhoneBook App!" << std::endl
				<< "Usage: type \"ADD\" to add a contact, \"SEARCH\" to see list or \"EXIT\" to quit."
				<< std::endl;
	while (true)
	{
		std::cout << "> " << std::flush;
		if (!std::getline(std::cin, cmd))
			break;
		if (cmd == "ADD")
			app.add();
		else if (cmd == "SEARCH")
			app.search();
		else if (cmd == "EXIT")
			break;
	}
	return 0;
}