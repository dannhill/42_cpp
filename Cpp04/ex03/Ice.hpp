#pragma once
#include "AMateria.hpp"

class Ice : public AMateria{
	public:
		Ice(void);
		~Ice(void);

		AMateria	*clone(void) const;
		void		use(ICharacter & target);
};
