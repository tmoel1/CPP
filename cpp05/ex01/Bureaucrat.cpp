#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Anonymous Intern"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string&name, int grade) : _name(name), _grade(grade)
{
	_validateGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
		_grade = rhs._grade;

	return *this;
}

Bureaucrat::~Bureaucrat() {}



const std::string&	Bureaucrat::getName() const
{
	return _name;
}

int					Bureaucrat::getGrade() const
{
	return _grade;
}

void				Bureaucrat::incrementGrade()
{
	_validateGrade(_grade - 1);

	--_grade;
}

void				Bureaucrat::decrementGrade()
{
	_validateGrade(_grade + 1);

	++_grade;
}

const char*		Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat: grade too high (# must be >= 1)";
}

const char*		Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat: grade too low (# must be <= 150)";
}



void	Bureaucrat::_validateGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(Form& f) const //new for ex01
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}

	catch (const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << f.getName() << " because "
			<< e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	return os << b.getName() << ", bureaucrat grade " << b.getGrade() << '.';
}
