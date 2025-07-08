#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>


/* Creates <target>_shrubbery with ASCII trees                         */
class ShrubberyCreationForm : public AForm 
{
	public:
		ShrubberyCreationForm();                                   // 1. default
		explicit ShrubberyCreationForm(const std::string& target); // 2. target ctor
		ShrubberyCreationForm(const ShrubberyCreationForm& other); // 3. copy
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs); // 4. assign
		virtual ~ShrubberyCreationForm();                          // 5. dtor

	private:
		virtual void	executeAction() const;   // concrete work
		
		const std::string	_target;
};

#endif
