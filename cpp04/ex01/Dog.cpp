#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() : Animal(), brain(new Brain()) // new brain allocation here
{
	std::cout << "Dog default contructed" << std::endl;

	type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) // added here too
{
	std::cout << "Dog copy contructed" << std::endl;

	//type = other.type; // this added but why now? well it's sort of redundant unless you later change Dog::type

}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog copy-assigned" << std::endl;

	if (this != &rhs)
	{
		Animal::operator=(rhs);
		*brain = *rhs.brain; //added this
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

void			Dog::setIdea(int idx, const std::string& idea) //added
{
	brain->setIdea(idx, idea);
}

std::string		Dog::getIdea(int idx) const
{
	return brain->getIdea(idx);
}