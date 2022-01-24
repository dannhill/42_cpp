#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name){
	return;
}

Zombie::Zombie(void) : _name("Nekros"){
	return;
}

Zombie::~Zombie(void){
	return;
}

void	Zombie::announce(void){
	std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
	return;	
}