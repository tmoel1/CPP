#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Form; //new for ex01

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string&name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();

		const std::string&	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		void				signForm(Form& f) const; //new for ex01

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		static void	_validateGrade(int Grade);

		const std::string	_name;
		int					_grade;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

#endif