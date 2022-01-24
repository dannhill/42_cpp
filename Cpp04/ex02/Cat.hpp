#pragma once
#include "Animal.hpp"
#include <iostream>

class Cat : public Animal{
	public:
		Cat(void);
		virtual ~Cat(void);

		void		makeSound(void) const;
		std::string	getType(void) const;
	private:
		Brain	*_brain;
};
