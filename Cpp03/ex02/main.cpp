#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void){
	ClapTrap	cletus("Cletus");
	ScavTrap	kevin("Kevin");
	FragTrap	lawrence("Lawrence");

	cletus.attack("Kabiro");
	cletus.takeDamage(5);
	cletus.beRepaired(15);
	cletus.takeDamage(500);
	kevin.guardGate();
	kevin.attack("Gianni");
	lawrence.highFivesGuys();
	lawrence.attack("Jacob");
	lawrence.beRepaired(50);

	return 0;
}