#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _idx(0){
	for (int i = 0; i < 4; i++)
		_spell_book[i] = NULL;
	return;
}

MateriaSource::MateriaSource(MateriaSource const & cpy) : _idx(cpy._idx){
	for (int i = 0; i < 4; i++)
	{
		if (cpy._spell_book[i] != NULL)
			_spell_book[i] = cpy._spell_book[i]->clone();
		else if (cpy._spell_book[i] == NULL)
			_spell_book[i] = NULL;
	}
	return;
}

MateriaSource::~MateriaSource(void){
	for (int i = 0; i < 4; i++)
		delete _spell_book[i];
	return;
}

void	MateriaSource::learnMateria(AMateria *m){
	if (_spell_book[_idx] == NULL)
		_spell_book[_idx] = m;
	else if (_spell_book[_idx] != NULL)
	{
		std::cout << "Materia " << _spell_book[_idx]->getType() << " unlearned."
			<< std::endl;
		delete _spell_book[_idx];
		_spell_book[_idx] = m;
	}
	if (_idx < 3)
		_idx++;
	else if (_idx >= 3)
		_idx = 0;
}

AMateria	*MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++)
	{
		if (_spell_book[i] != NULL && _spell_book[i]->getType() == type)
			return _spell_book[i]->clone();
	}
	std::cout << "Spell not learned." << std::endl;
	return 0;
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & asn){
	_idx = asn._idx;
	for (int i = 0; i < 4; i++)
	{
		if (asn._spell_book[i] != NULL)
			_spell_book[i] = asn._spell_book[i]->clone();
		else if (asn._spell_book[i] == NULL)
			_spell_book[i] = NULL;
	}
	return *this;
}
