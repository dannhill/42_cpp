#include "Dog.hpp"

Dog::Dog(void) : Animal(){
	type = "Dog";
	return;
}

Dog::~Dog(void){
	return;
}

void	Dog::makeSound(void) const{
	std::cout << "Woof!" << std::endl;
	return;
}

std::string	Dog::getType(void) const{
	return type;
}
