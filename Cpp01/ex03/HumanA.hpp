#pragma once
#include "Weapon.hpp"
#include <string>

class HumanA{
    public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);

		void		attack(void);
    private:
		Weapon&		_weapon;
		std::string	_name;
};