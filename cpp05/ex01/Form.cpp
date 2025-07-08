#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Untitled Form"), _isSigned(false), _minGradeSign(150),
	_minGradeExec(150) {}


Form::Form(const std::string& name, int minGradeSign, int minGradeExec)
	: _name(name), _isSigned(false), _minGradeSign(minGradeSign), _minGradeExec(minGradeExec)
{
	_validateGrade(_minGradeSign);
	_validateGrade(_minGradeExec);
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned),
	_minGradeSign(other._minGradeSign), _minGradeExec(other._minGradeExec) {}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
		_isSigned = rhs._isSigned;
	return *this;
}

void	Form::_validateGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Form::~Form() {}



const std::string&	Form::getName() const
{
	return _name;
}

bool				Form::isSigned() const
{
	return _isSigned;
}

int					Form::getMinSignedGrade() const
{
	return _minGradeSign;
}

int					Form::getMinExecGrade() const
{
	return _minGradeExec;
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _minGradeSign)
	{
		throw GradeTooLowException();
	}	
	_isSigned = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Form: grade too high (# must be >= 1)";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Form: grade too low (# must be <= 150)";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form " << f.getName() << ", sign: " << f.getMinSignedGrade() << ", exec: "
		<< f.getMinExecGrade() << ", signed: " << (f.isSigned() ? "yes" : "no");
	
	return os;
}