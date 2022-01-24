#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
	public:
		DiamondTrap(std::string name);
		~DiamondTrap(void);

		void	attack(std::string const & target) const;

		void	whoAmI(void);
	private:
		std::string	_name;

		DiamondTrap(void);
};