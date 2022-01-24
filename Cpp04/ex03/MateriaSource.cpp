#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _idx(0){
	for (int i = 0; i < 10; i++)
		_spell_book[i] = NULL;
	return;
}

MateriaSource::~MateriaSource(void){
	for (int i = 0; i < 10; i++)
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
	if (_idx < 9)
		_idx++;
	else if (_idx >= 9)
		_idx = 0;
}

AMateria	*MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 10; i++)
	{
		if (_spell_book[i] != NULL && _spell_book[i]->getType() == type)
			return _spell_book[i]->clone();
	}
	std::cout << "Spell not learned." << std::endl;
	return NULL;
}
