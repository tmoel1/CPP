#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat manager("Manager", 1);
	Bureaucrat intern("Intern", 150);

	Form permit("Permit", 50, 10);
	Form leave("Leave", 150, 150);

	std::cout << "Forms:" << std::endl << permit << std::endl << leave << std::endl;

	manager.signForm(permit);
	intern.signForm(permit);
	intern.signForm(leave);
	manager.signForm(leave);

	std::cout << "Forms:" << std::endl << permit << std::endl << leave << std::endl;

	try
	{
		Form badForm("Bad Form", 0, 10);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}