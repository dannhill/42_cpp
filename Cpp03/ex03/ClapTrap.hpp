#pragma once
#include <string>
#include <iostream>

class ClapTrap{
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & cpy);
		virtual	~ClapTrap(void);

		virtual void	attack(std::string const & target) const;
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		ClapTrap &	operator=(ClapTrap const & asn);

		ClapTrap(int);
	protected:
		std::string	_name;
		int			_hitpoints;
		int			_energy_points;
		int			_attack_damage;
	private:
		ClapTrap(void);
};