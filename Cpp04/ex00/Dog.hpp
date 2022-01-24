#pragma once
#include "Animal.hpp"
#include <iostream>

class Dog : public Animal{
	public:
		Dog(void);
		virtual	~Dog(void);

		void		makeSound(void) const;
		std::string	getType(void) const;
};
