#pragma once
#include "Animal.hpp"
#include <iostream>

class Cat : public Animal{
	public:
		Cat(void);
		Cat(Cat const & cpy);
		virtual ~Cat(void);

		void		makeSound(void) const;
		std::string	getType(void) const;
		Brain const &	getBrain(void) const;

		Cat &	operator=(Cat const & asn);
	private:
		//lo scrivo nei commenti per i correttori: avrei potuto anche inserire un Brain protected nella classe Animal,
		//dal momento che Dog e Cat ereditano entrambi da Animal, in tal modo avrei risparmiato sul codice. Tuttavia il 
		//subject é poco chiaro a riguardo, quindi ho deciso di riscrivere la variabile membro _brain in entrambi gli
		//animali. Sappiate dunque che sono a conoscenza dell'altro modo 😅 .
		Brain	*_brain;
};
