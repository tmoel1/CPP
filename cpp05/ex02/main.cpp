#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat boss("Boss", 1);
	Bureaucrat lackey("Lackey", 140);

	ShrubberyCreationForm tree("home");
	RobotomyRequestForm    robo("Marvin");
	PresidentialPardonForm pardon("Arthur");

	/* Signing attempts */
	lackey.signForm(tree);    // succeeds (140 ≤ 145)
	boss.signForm(robo);      // sign grade 72 – boss can
	boss.signForm(pardon);    // sign grade 25 – boss can

	/* Execution attempts */
	lackey.executeForm(tree); // fails – exec needs 137, lackey 140
	boss.executeForm(tree);   // succeeds → file created

	boss.executeForm(robo);   // succeeds, 50% outcome
	boss.executeForm(pardon); // succeeds

	/* Unsigned form execution test */
	ShrubberyCreationForm notSigned("garden");
	boss.executeForm(notSigned); // should fail (not signed)
}
