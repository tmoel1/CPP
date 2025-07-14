
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	AForm* form;

	// Create a RobotomyRequestForm
	std::cout << "Robot attempt:" << std::endl;
	form = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	if (form)
	{
		Bureaucrat chief("Chief", 1);
		chief.signForm(*form);
		chief.executeForm(*form);
		delete form;
	}

	// Create a PresidentialPardonForm
	std::cout << std::endl;
	std::cout << "Pardon attempt:" << std::endl;
	form = someRandomIntern.makeForm("PresidentialPardonForm", "Hunter");
	if (form)
	{
		Bureaucrat admin("Admin", 1);
		admin.signForm(*form);
		admin.executeForm(*form);
		delete form;
	}

	// Try unknown form
	std::cout << std::endl;
	std::cout << "Unkown attempt, shouldn't work:" << std::endl;
	form = someRandomIntern.makeForm("unknown thing", "nowhere");
	if (form)
	{
		std::cout << "Print this if form DOES appear to exist" << std::endl;
		delete form;
	}

	return 0;
}
