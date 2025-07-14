#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& rhs);
		~Intern();

		AForm* makeForm(const std::string& formName, const std::string& target) const;
	private:
		static AForm* _createShrubbery(const std::string& target);
		static AForm* _createRobotomy(const std::string& target);
		static AForm* _createPresidential(const std::string& target);
};

#endif