#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(0){
	_name = name;
	_hitpoints = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap " << _name << " has been spawned." << std::endl;
	return;
}

FragTrap::~FragTrap(void){
	std::cout << "The story of the FragTrap " << _name <<
		" has come to an end..." << std::endl;
	return;
}

void	FragTrap::attack(std::string const & target) const{
	std::cout << target << std::endl;
	return;
}

void	FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << _name << " wants to high five." << std::endl;
	return;
}

FragTrap::FragTrap(void) : ClapTrap(0){
	return;
}