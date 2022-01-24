#include "Weapon.hpp"

Weapon::Weapon(void) : _type("stick of cheese"){
    return;
}

Weapon::Weapon(std::string name) : _type(name){
    return;
}

Weapon::~Weapon(void){
    return;
}

std::string const&	Weapon::getType(void) const{
    return (std::string const&)_type;
}

void	Weapon::setType(std::string type){
	if (type.length() == 0)
	{
		std::cerr << "Error: type must be non-empty." << std::endl;
		return;
	}
	_type = type;
	return;
}