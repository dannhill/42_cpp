#include "Brain.hpp"

const unsigned int	Brain::_size(100);

Brain::Brain(void){
	for (int i = 0; i < 100; i++)
		ideas[i] = "Peace";
	return;
}

Brain::Brain(Brain const & cpy){
	for (unsigned int i(0); i < _size; i++)
		ideas[i] = cpy.ideas[i];
	return;
}

Brain::~Brain(void){
	return;
}

Brain &	Brain::operator=(Brain const & asn){
	for (unsigned int i(0); i < _size; i++)
		ideas[i] = asn.ideas[i];
	return *this;
}
