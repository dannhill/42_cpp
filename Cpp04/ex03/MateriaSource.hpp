#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & cpy);
		~MateriaSource(void);

		void		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const & type);

		MateriaSource &	operator=(MateriaSource const & asn);
	private:
		AMateria	*_spell_book[4];
		int			_idx;
};
