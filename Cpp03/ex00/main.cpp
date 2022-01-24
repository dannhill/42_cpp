#include "ClapTrap.hpp"
#include <iostream>

int	main(void){
	ClapTrap	cletus("Cletus");

	cletus.attack("Kabiro");
	cletus.takeDamage(5);
	cletus.beRepaired(15);
	cletus.takeDamage(500);

	return 0;
}