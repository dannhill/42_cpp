#include "Cat.hpp"

Cat::Cat(void) : Animal(){
	std::cout << "What? A cat in our basement? How cute!" << std::endl;
	type = "Cat";
	_brain = new Brain();
	return;
}

Cat::Cat(Cat const & cpy) : Animal(){
	std::cout << "What? A cat in our basement? How cute!" << std::endl;
	type = "Cat";
	_brain = new Brain(*(cpy._brain));
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

Brain const &	Cat::getBrain(void) const{
	return *_brain;
}

Cat &	Cat::operator=(Cat const & asn){
	*_brain = *(asn._brain);
	return *this;
}
