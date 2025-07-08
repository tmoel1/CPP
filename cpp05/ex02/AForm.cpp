#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

AForm::AForm(const std::string& n, int gs, int ge)
	: _name(n), _gradeSign(gs), _gradeExec(ge), _isSigned(false)
{
	_validateGrade(_gradeSign);
	_validateGrade(_gradeExec);
}

AForm::AForm(const AForm& o) : _name(o._name), _gradeSign(o._gradeSign),
	_gradeExec(o._gradeExec), _isSigned(o._isSigned) {}

AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
		_isSigned = rhs._isSigned;
	
	return *this;
}

AForm::~AForm() {}



const std::string&	AForm::getName() const
{
	return _name;
}
bool				AForm::isSigned() const
{
	return _isSigned;
}
int					AForm::getSignGrade() const
{
	return _gradeSign;
}
int					AForm::getExecGrade() const
{
	return _gradeExec;
}



void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeSign)
		throw GradeTooLowException();

	_isSigned = true;
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	
	if (executor.getGrade() > _gradeExec)
		throw GradeTooLowException();
	
	executeAction();
}



const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm: grade too high (# must be ≥ 1)";
}

const char* AForm::GradeTooLowException::what()  const throw()
{
	return "AForm: grade too low (# must be ≤ 150)";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "AForm: form not yet signed";
}



void AForm::_validateGrade(int g)
{
	if (g < 1)
		throw GradeTooHighException();

	if (g > 150)
		throw GradeTooLowException();
}



std::ostream&	operator<<(std::ostream& os, const AForm& f)
{
	os << "Form "  << f.getName() << " [sign:" << f.getSignGrade() << ", exec:"
		<< f.getExecGrade() << "] – signed:" << (f.isSigned() ? "yes" : "no");
	
	return os;
}

/////// maybe modify the above prints to clean up the square brackets etc?