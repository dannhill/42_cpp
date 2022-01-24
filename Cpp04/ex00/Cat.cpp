#include "Cat.hpp"

Cat::Cat(void) : Animal(){
	type = "Cat";
	return;
}

Cat::~Cat(void){
	return;
}

void	Cat::makeSound(void) const{
	std::cout << "Meow!" << std::endl;
	return;
}

std::string	Cat::getType(void) const{
	return type;
}
