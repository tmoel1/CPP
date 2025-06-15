#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	std::cout << "Cat default contructed" << std::endl;

	type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy contructed" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat copy-assigned" << std::endl;

	if (this != &rhs)
		Animal::operator=(rhs);

	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructed" << std::endl;
}



void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}