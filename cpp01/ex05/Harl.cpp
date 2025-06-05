#include "Harl.hpp"
#include <string>
#include <iostream>

Harl::Harl(){}
Harl::~Harl(){}

void Harl::complain(std::string level)
{
	static void (Harl::*actions[4])() = 
	{
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};

	int i = _levelIndex(level);
	if (i >= 0)
		(this->*actions[i])();
	else
		std::cout << "Grumble grumble grumble..." << std::endl;
}

int Harl::_levelIndex(const std::string& level)
{
	const std::string levels_array[4] = 
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++)
	{
		if (levels_array[i] == level)
			return i;
	}
	return -1;
}

void Harl::_debug()
{
	std::cout << "I love having extra bacon for my "
					"7XL-double-cheese-triple-pickle-special-ketchup burger. "
					"I really do!" << std::endl;
}

void Harl::_info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
					"You didn’t put enough bacon in my burger! "
					"If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. "
					"I’ve been coming for years, whereas you started working "
					"here just last month." << std::endl;
}

void Harl::_error()
{
	std::cout << "This is unacceptable! "
					"I want to speak to the manager now." << std::endl;
}