#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm 
{
	public:
		AForm(const std::string& name, int gradeSign, int gradeExec);
		AForm(const AForm& rhs);
		AForm& operator=(const AForm& rhs);
		virtual ~AForm(); // virtual 

		const std::string&	getName()      const;
		bool				isSigned()     const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void	beSigned(const Bureaucrat& b);
		void	execute(Bureaucrat const& executor) const;

		class GradeTooHighException : public std::exception 
		{
		public:
			const char* what() const throw();
		};
		class GradeTooLowException  : public std::exception
		{
		public:
			const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
		public:
			const char* what() const throw();
		};

	protected:
		virtual void	executeAction() const = 0;

	private:
		static void		_validateGrade(int grade);

		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_isSigned;
};

std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif
