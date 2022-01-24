#pragma once
#include "Brain.hpp"
#include <string>

class Animal{
	public:
		Animal(void);
		virtual	~Animal(void);

		virtual void		makeSound(void) const;
		virtual std::string	getType(void) const;
	protected:
		std::string	type;
};