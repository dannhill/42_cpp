#include "Brain.hpp"

Brain::Brain(void){
	for (int i = 0; i < 100; i++)
		ideas[i] = "Peace";
	return;
}

Brain::~Brain(void){
	return;
}
