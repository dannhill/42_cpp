#pragma once
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
};