#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default contructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
	std::cout << "WrongAnimal copy contructed" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout << "WrongAnimal copy-assigned" << std::endl;

	if (this != &rhs)
		type = rhs.type;

	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructed" << std::endl;
}



std::string		WrongAnimal::getType() const
{
	return type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal: ???" << std::endl;
}