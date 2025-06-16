#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructed" << std::endl;

	for (int i = 0; i < kNumIdeas; ++i)
		ideasArray[i] = "empty";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructed" << std::endl;

	for (int i = 0; i < kNumIdeas; ++i)
		ideasArray[i] = other.ideasArray[i];
}

Brain& Brain::operator=(const Brain& rhs)
{
	std::cout << "Brain copy-assigned" << std::endl;

	if (this != &rhs)
	{
		for (int i = 0; i < kNumIdeas; ++i)
			ideasArray[i] = rhs.ideasArray[i];
	}

	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructed" << std::endl;
}



void			Brain::setIdea(int idx, const std::string& idea)
{
	if (idx >= 0 && idx < kNumIdeas)
		ideasArray[idx] = idea;
}

std::string		Brain::getIdea(int idx) const
{
	if (idx >= 0 && idx < kNumIdeas)
		return ideasArray[idx];
	else
		return "";
}
