#include "ScavTrap.hpp"
#include <iostream>

int	main(void){
	ClapTrap	cletus("Cletus");
	ScavTrap	kevin("Kevin");

	cletus.attack("Kabiro");
	cletus.takeDamage(5);
	cletus.beRepaired(15);
	cletus.takeDamage(500);
	kevin.guardGate();
	kevin.attack("Gianni");

	return 0;
}