#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name){
	return;
}

Zombie::Zombie(void) : _name("Nekros"){
	return;
}

Zombie::~Zombie(void){
	// std::cout << "PD " << _name << std::endl;
	return;
}

void	Zombie::announce(void){
	std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
	return;	
}