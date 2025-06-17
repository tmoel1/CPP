#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() : Animal(), brain(new Brain())
{
	std::cout << "Dog default contructed" << std::endl;

	type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Dog copy contructed" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog copy-assigned" << std::endl;

	if (this != &rhs)
	{
		Animal::operator=(rhs);
		*brain = *rhs.brain;
	}

	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructed" << std::endl;

	delete brain;
}



void			Dog::makeSound() const
{
	std::cout << "Woof woof!" << std::endl;
}

void			Dog::setIdea(int idx, const std::string& idea)
{
	brain->setIdea(idx, idea);
}

std::string		Dog::getIdea(int idx) const
{
	return brain->getIdea(idx);
}