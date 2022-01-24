#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"){
	return;
}

Ice::~Ice(void){
	return;
}

AMateria	*Ice::clone(void) const{
	return new Ice();
}

void	Ice::use(ICharacter & target){
	if (isActive())
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (!isActive())
		std::cout << "Spell unequipped." << std::endl;
	return;
}
