#pragma once
#include "Brain.hpp"
#include <string>

class Animal{
	public:
		Animal(void);
		Animal(Animal const & cpy);
		virtual	~Animal(void);

		virtual void		makeSound(void) const;
		virtual std::string	getType(void) const;

		Animal &	operator=(Animal const & asn);
	protected:
		std::string	type;
		//lo scrivo nei commenti per i correttori: avrei potuto anche inserire un Brain protected nella classe Animal,
		//dal momento che Dog e Cat ereditano entrambi da Animal, in tal modo avrei risparmiato sul codice. Tuttavia il 
		//subject é poco chiaro a riguardo, quindi ho deciso di riscrivere la variabile membro _brain in entrambi gli
		//animali. Sappiate dunque che sono a conoscenza dell'altro modo 😅 .
};