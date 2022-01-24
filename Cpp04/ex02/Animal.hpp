#pragma once
#include "Brain.hpp"
#include <string>

class Animal{
	public:
		Animal(void);
		virtual	~Animal(void);

		virtual void		makeSound(void) const = 0;
		virtual std::string	getType(void) const = 0;
	protected:
		std::string	type;
};