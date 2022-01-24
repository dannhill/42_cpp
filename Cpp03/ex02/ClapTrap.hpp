#pragma once
#include <string>
#include <iostream>

class ClapTrap{
	public:
		ClapTrap(std::string name);
		virtual	~ClapTrap(void);

		void	attack(std::string const & target) const;
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		ClapTrap(int);
	protected:
		std::string	_name;
		int			_hitpoints;
		int			_energy_points;
		int			_attack_damage;
	private:
		ClapTrap(void);
};