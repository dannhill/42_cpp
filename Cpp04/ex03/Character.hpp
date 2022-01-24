#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

class Character : public ICharacter{
	public:
		Character(std::string name);
		~Character(void);

		std::string const &	getName(void) const;
		void	equip(AMateria *m);
		void	unequip(int idx);
		void	use(int idx, ICharacter & target);
	private:
		std::string	_name;

		AMateria	*_spells[10];
		int			_idx;

		Character(void);
};
