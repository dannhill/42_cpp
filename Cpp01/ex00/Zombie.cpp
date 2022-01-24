#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name){
	return;
}

Zombie::Zombie(void) : _name("Nekros"){
	return;
}

Zombie::~Zombie(void){
	std::cout << "Zombie " << _name << " was sent back to Hell" << std::endl;
	return;
}

void	Zombie::announce(void){
	std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
	return;	
}