#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
	public:
		MateriaSource(void);
		~MateriaSource(void);

		void		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const & type);
	private:
		AMateria	*_spell_book[10];
		int			_idx;
};
