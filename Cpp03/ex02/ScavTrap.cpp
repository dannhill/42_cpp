#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(0){
	_name = name;
	_hitpoints = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap " << _name << " has risen from a pile of"
		" scrap metal." << std::endl;
	return;
}

ScavTrap::~ScavTrap(void){
	std::cout << "ScavTrap " << _name << " has been deactivated." <<
		std::endl;
	return;
}

void	ScavTrap::guardGate(void){
	std::cout << "ScavTrap " << _name << " has entered Gate keeper"
		" mode." << std::endl;
	return;
}