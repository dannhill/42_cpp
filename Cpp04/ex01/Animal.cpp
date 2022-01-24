#include "Animal.hpp"

Animal::Animal(void) : type("Animal"){
	return;
}

Animal::~Animal(void){
	return;
}

void	Animal::makeSound(void) const{
	return;
}

std::string	Animal::getType(void) const{
	return type;
}
