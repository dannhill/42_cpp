#include "Cat.hpp"

Cat::Cat(void) : Animal(){
	std::cout << "What? A cat in our basement? How cute!" << std::endl;
	type = "Cat";
	_brain = new Brain();
	return;
}

Cat::~Cat(void){
	std::cout << "No country for old cats..." << std::endl;
	delete _brain;
	return;
}

void	Cat::makeSound(void) const{
	std::cout << "Meow!" << std::endl;
	return;
}

std::string	Cat::getType(void) const{
	return type;
}
