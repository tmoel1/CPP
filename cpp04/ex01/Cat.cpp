#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat() : Animal(), brain(new Brain()) // new brain allocation here
{
	std::cout << "Cat default contructed" << std::endl;

	type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) // added here too
{
	std::cout << "Cat copy contructed" << std::endl;

	//type = other.type; // this added but why now?
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat copy-assigned" << std::endl;

	if (this != &rhs)
	{
		Animal::operator=(rhs);
		*brain = *rhs.brain; //added this
	}

	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructed" << std::endl;

	delete brain;
}



void			Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

void			Cat::setIdea(int idx, const std::string& idea) //added
{
	brain->setIdea(idx, idea);
}

std::string		Cat::getIdea(int idx) const
{
	return brain->getIdea(idx);
}