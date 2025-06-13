#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& rhs);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		int				_attackDamage;

		static const int	_kDefaultHealth	= 10;
		static const int	_kDefaultEnergy	= 10;
		static const int	_kDefaultAttack	= 0;
};

#endif