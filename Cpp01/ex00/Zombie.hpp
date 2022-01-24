#pragma once
#include <string>
#include <iostream>

class Zombie{
	public:
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);

		void	announce(void);
	private:
		std::string	_name;
};

Zombie	*newZombie(std::string name);

void	randomChump(std::string name);