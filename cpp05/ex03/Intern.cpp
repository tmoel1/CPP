#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&)
{
	return *this;
}

Intern::~Intern() {}



AForm* Intern::_createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::_createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::_createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) const
{
	const std::string formNames[] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};

	AForm* (*formCreators[])(const std::string&) = {
		&Intern::_createShrubbery,
		&Intern::_createRobotomy,
		&Intern::_createPresidential
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}

	std::cout << "Form '" << formName << "' doesn't exist" << std::endl;
	
	return NULL;
}