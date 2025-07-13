#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat boss("Manager", 1);
	Bureaucrat lackey("Intern", 140);

	ShrubberyCreationForm tree("home");
	RobotomyRequestForm    robo("Marvin");
	PresidentialPardonForm pardon("Arthur");

	std::cout << "Operator overload tests:" << std::endl;
	std::cout << boss << std::endl;
	std::cout << lackey << std::endl;

	std::cout << tree << std::endl;
	std::cout << robo << std::endl;
	std::cout << pardon << std::endl;
	std::cout << std::endl;
	
	std::cout << "Signing attempts:" << std::endl;
	lackey.signForm(tree); // succeeds (140 ≤ 145)
	lackey.signForm(robo); // sign grade 72 - lackey cannot
	boss.signForm(robo); // sign grade 72 – boss can
	boss.signForm(pardon); // sign grade 25 – boss can
	std::cout << std::endl;

	std::cout << "Execution attempts:" << std::endl;
	lackey.executeForm(tree); // fails – exec needs 137, lackey 140
	boss.executeForm(tree); // succeeds → file created

	boss.executeForm(robo); // succeeds, 50% outcome
	boss.executeForm(pardon); // succeeds
	std::cout << std::endl;

	std::cout << "Unsigned execution attempts:" << std::endl;
	ShrubberyCreationForm notSigned("garden");
	boss.executeForm(notSigned); // should fail (not signed)

	std::cout << std::endl;
	std::cout << "Operator overload tests (again):" << std::endl;

	std::cout << tree << std::endl;
	std::cout << robo << std::endl;
	std::cout << pardon << std::endl;
	std::cout << notSigned << std::endl;
}
