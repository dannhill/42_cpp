#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon){
	if (name.length() <= 0)
	{
		std::cerr << "Error: name must be non-empty" << std::endl;
		return;
	}
	_name = name;
	return;
}

HumanA::~HumanA(void){
	return;
}

void	HumanA::attack(void){
	std::cout << _name << " attacks with his " <<
		_weapon.getType() << std::endl;
	return;
}
