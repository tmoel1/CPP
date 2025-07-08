#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat manager("Manager", 1);
	Bureaucrat intern("Intern", 150);

	Form permit("Permit", 50, 10);
	Form leave("Leave", 150, 150);

	std::cout << "Forms:" << std::endl << permit << std::endl << leave << std::endl;

	intern.signForm(permit);
	manager.signForm(permit);
	intern.signForm(leave);

	std::cout << "Forms:" << std::endl << permit << std::endl << leave << std::endl;

	try
	{
		Form badHigh("Bad High", 0, 10);   // sign-grade too high
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form badLow("Bad Low", 151, 10);   // sign-grade too low
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form badExec("Bad Exec", 10, 200); // exec-grade too low
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}