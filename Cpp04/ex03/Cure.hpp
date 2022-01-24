#pragma once
#include "AMateria.hpp"

class Cure : public AMateria{
	public:
		Cure(void);
		~Cure(void);

		AMateria	*clone(void) const;
		void		use(ICharacter & target);
};
