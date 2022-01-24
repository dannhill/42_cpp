#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	if (name.length() <= 0)
	{
		std::cerr << "Error: name must be non-empty" << std::endl;
		return;
	}
	_name = name;
	return;
}

HumanB::HumanB(void){
	std::cerr << ">>FATAL ERROR<<" << std::endl;
	return;
}

HumanB::~HumanB(void){
	return;
}

void	HumanB::attack(void){
	std::cout << _name << " attacks with his " <<
		_weapon->getType() << std::endl;
	return;
}

void	HumanB::setWeapon(Weapon &weapon){
	if (weapon.getType().length() <= 0)
		std::cerr << "Error: invalid weapon." << std::endl;
	else if (weapon.getType().length() > 0)
		_weapon = &weapon;
    return;
}