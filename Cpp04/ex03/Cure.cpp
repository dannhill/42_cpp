#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure"){
	return;
}

Cure::~Cure(void){
	return;
}

AMateria	*Cure::clone(void) const{
	// std::cout << "cureclone\n";
	return new Cure();
}

void	Cure::use(ICharacter & target){
	if (isActive())
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	else if (!isActive())
		std::cout << "Spell unequipped." << std::endl;
	return;
}
