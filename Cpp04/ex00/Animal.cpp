#include "Animal.hpp"

Animal::Animal(void) : type("Animal"){
	return;
}

Animal::Animal(Animal const & cpy){
	type = cpy.type;
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

Animal &	Animal::operator=(const Animal & asn){
	type = asn.type;
	return *this;
}
