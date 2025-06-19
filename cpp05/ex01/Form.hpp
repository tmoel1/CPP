#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string&name, int gradeSign, int gradeExec);
		Form(const Form& other);
		Form& operator=(const Form& rhs);
		~Form();

		const std::string&	getName() const;
		bool				isSigned() const;
		int					getMinSignedGrade() const;
		int					getMinExecGrade() const;
		void				beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
		
	private:
		static void	_validateGrade(int grade);

		const std::string	_name;
		bool 				_isSigned;
		const int			_minGradeSign;
		const int			_minGradeExec;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif