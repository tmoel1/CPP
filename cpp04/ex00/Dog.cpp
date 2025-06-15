#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << "Dog default contructed" << std::endl;

	type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy contructed" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog copy-assigned" << std::endl;

	if (this != &rhs)
		Animal::operator=(rhs);

	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructed" << std::endl;
}



void	Dog::makeSound() const
{
	std::cout << "Woof woof!" << std::endl;
}