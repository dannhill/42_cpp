#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main(void){
	ClapTrap	cletus("Cletus");
	ScavTrap	kevin("Kevin");
	FragTrap	lawrence("Lawrence");
	DiamondTrap	carbon("Carbon");

	cletus.attack("Kabiro");
	cletus.takeDamage(5);
	cletus.beRepaired(15);
	cletus.takeDamage(500);
	kevin.guardGate();
	kevin.attack("Gianni");
	lawrence.highFivesGuys();
	lawrence.attack("Jacob");
	lawrence.beRepaired(50);
	carbon.whoAmI();
	carbon.attack("Dani");

	return 0;
}