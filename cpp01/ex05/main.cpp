#include "Harl.hpp"
#include <string>
#include <iostream>

int main()
{
	Harl test_harl;

	std::string tests[5] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
		"Some Random Input"
	};

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Test: " << tests[i] << std::endl;
		test_harl.complain(tests[i]);
		std::cout << std::endl;
	}
	return 0;
}