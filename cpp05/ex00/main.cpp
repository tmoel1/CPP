#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat alice ("Alice", 2);
		Bureaucrat bob ("Bob", 149);

		std::cout << alice << std::endl << bob << std::endl;

		alice.incremenentGrade();
		std::cout << "After promotion: " << alice << std::endl;

		bob.decrementGrade();
		std::cout << "After promotion: " << bob << std::endl;

		bob.decrementGrade();
	}

	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooHigh("Alicia", 0);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooLow("Boba", 151);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}