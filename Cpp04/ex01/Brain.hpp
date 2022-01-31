#pragma once
#include <string>

class Brain{
	public:
		Brain(void);
		Brain(Brain const & cpy);
		~Brain(void);

		Brain &	operator=(Brain const & asn);

		std::string	ideas[100];
	protected:
		static const unsigned int	_size;
};
