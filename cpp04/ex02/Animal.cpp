#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default contructed" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal copy contructed" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "Animal copy-assigned" << std::endl;

	if (this != &rhs)
		type = rhs.type;

	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructed" << std::endl;
}



std::string		Animal::getType() const
{
	return type;
}

/*
void	Animal::makeSound() const
{
	std::cout << "Animal: ???" << std::endl;
}
*/