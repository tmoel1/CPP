#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

/*
 * Abstract base for *all* future forms.
 * Holds:
 *   • immutable _name
 *   • immutable grades _gradeSign / _gradeExec
 *   • mutable  _isSigned
 * Performs range-checking + execute() template method.
 */
class AForm 
{
	public:
		/* ───── OCF ───── */
		AForm(const std::string& name, int gradeSign, int gradeExec);
		AForm(const AForm& rhs);
		AForm& operator=(const AForm& rhs);
		virtual ~AForm(); // virtual 

		/* ───── Getters ───── */
		const std::string&	getName()      const;
		bool				isSigned()     const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		/* ───── Behaviour ───── */
		void	beSigned(const Bureaucrat& b);
		void	execute(Bureaucrat const& executor) const;

		/* ───── Exceptions ───── */
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
		/* concrete classes must implement only the *action* */
		virtual void	executeAction() const = 0;

	private:
		static void		_validateGrade(int grade);

		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_isSigned;
};

/* Stream operator – prints *everything* */
std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif
