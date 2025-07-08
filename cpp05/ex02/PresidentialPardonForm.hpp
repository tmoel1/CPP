#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>


class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		explicit PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
		virtual ~PresidentialPardonForm();

	private:
		virtual void	executeAction() const;
		
		const std::string	_target;
};

#endif
