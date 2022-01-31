#include "Character.hpp"

Character::Character(std::string name) : ICharacter(), _idx(0){
	if (name.length() <= 0)
	{
		std::cerr << "Error: Character name must be non-empty." << std::endl;
		_name = "Chara";
	}
	else if (name.length() > 0)
		_name = name;
	for (int i = 0; i < 4; i++)
		_spells[i] = NULL;
}

Character::Character(Character const & cpy) : ICharacter(), _idx(0){
	if (cpy._name.length() <= 0)
	{
		std::cerr << "Error: Character name must be non-empty." << std::endl;
		_name = "Chara";
	}
	else if (cpy._name.length() > 0)
		_name = cpy._name;
	for (int i = 0; i < 4; i++)
		{
			if (cpy._spells[i] != NULL)
				_spells[i] = cpy._spells[i]->clone();
			else if (cpy._spells[i] == NULL)
				_spells[i] = NULL;
		}
}

Character::~Character(void){
	for (int i = 0; i < 4; i++)
		delete _spells[i];
	return;
}

std::string const &	Character::getName(void) const{
	return _name;
}

void	Character::equip(AMateria *m){
	if (_spells[_idx] != NULL)
		std::cout << "Inventory full :/" << std::endl;
	else if (_spells[_idx] == NULL)
		_spells[_idx] = m;
	if (_idx < 3)
		_idx++;
	else if (_idx >= 3)
		_idx = 0;
	return;
}

void	Character::unequip(int idx){
	if (_spells[idx] != NULL)
		_spells[idx]->disable();
	return;
}

void	Character::use(int idx, ICharacter & target){
	if (_spells[idx] != NULL)
		_spells[idx]->use(target);
	else if (_spells[idx] == NULL)
		std::cout << "No spell equipped in given slot." << std::endl;
	return;
}

ICharacter &	Character::operator=(Character const & asn){
	if (asn._name.length() <= 0)
	{
		std::cerr << "Error: Character name must be non-empty." << std::endl;
		_name = "Chara";
	}
	else if (asn._name.length() > 0)
		_name = asn._name;
	for (int i = 0; i < 4; i++)
	{
		if (asn._spells[i] != NULL)
			_spells[i] = asn._spells[i]->clone();
		else if (asn._spells[i] == NULL)
			_spells[i] = NULL;

	}
	return *this;
}

Character::Character(void){
	return;
}
