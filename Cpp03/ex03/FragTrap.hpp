#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
	public:
		FragTrap(std::string name);
		~FragTrap(void);

		void attack(std::string const & target) const;

		void	highFivesGuys(void);
	private:
		FragTrap(void);
};