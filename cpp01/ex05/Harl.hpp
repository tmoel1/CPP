#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
	public:
		Harl();
		~Harl();

		void	complain(std::string level);

	private:
		int		_levelIndex(const std::string& level);
		void	_debug();
		void	_info();
		void	_warning();
		void	_error();
};

#endif