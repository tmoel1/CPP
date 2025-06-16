#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	std::cout << "WrongCat default contructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy contructed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "WrongCat copy-assigned" << std::endl;

	if (this != &rhs)
		WrongAnimal::operator=(rhs);

	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructed" << std::endl;
}



void	WrongCat::makeSound() const
{
	std::cout << "Meow (wrongly)" << std::endl;
}