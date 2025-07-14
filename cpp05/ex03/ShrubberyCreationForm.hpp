#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <string>


class ShrubberyCreationForm : public AForm 
{
	public:
		ShrubberyCreationForm();
		explicit ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
		virtual ~ShrubberyCreationForm();

	private:
		virtual void	executeAction() const;
		
		const std::string	_target;
};

#endif