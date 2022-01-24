#include "Dog.hpp"

Dog::Dog(void) : Animal(){
	std::cout << "Say hi to our new dog friend!" << std::endl;
	type = "Dog";
	_brain = new Brain();
	return;
}

Dog::~Dog(void){
	std::cout << "A dog has been killed. How sad!" << std::endl;
	delete _brain;
	return;
}

void	Dog::makeSound(void) const{
	std::cout << "Woof!" << std::endl;
	return;
}

std::string	Dog::getType(void) const{
	return type;
}
