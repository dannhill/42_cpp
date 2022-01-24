#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(0),
ScavTrap(name), FragTrap(name){
	_name = name;
	std::cout << "Chimera-like DiamondTrap " << _name <<
		" has arisen from the dark..." << std::endl;
	ClapTrap::_name = name + "_clap_name";
	_hitpoints = FragTrap::_hitpoints;
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FragTrap::_attack_damage;

	return;
}

DiamondTrap::~DiamondTrap(void){
	std::cout << "The mighty chimera DiamondTrap " <<
		_name << " has perished." << std::endl;
	return;
}

void	DiamondTrap::attack(std::string const & target) const{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void){
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
	std::cout << "Actual name: " << _name << std::endl;
	return;
}

DiamondTrap::DiamondTrap(void) : ClapTrap(0), ScavTrap("DEF"),
FragTrap("DEF"){
	return;
}