#pragma once
#include <string>
#include <iostream>
#include <sstream>

class Zombie{
	public:
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);

		void	announce(void);
	private:
		std::string	_name;
};

Zombie* zombieHorde( int N, std::string name );