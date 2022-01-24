#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name){
	Zombie  			*horde;
	std::string			actual_name;

	if (N <= 0)
	{
		std::cerr << "Error: wrong number of zombies" << std::endl;
		return NULL;
	}
	horde = new Zombie[N];
	for(int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			horde[i] = *(new Zombie(name));
			continue;
		}
		std::stringstream	tmp;

		tmp << i + 1;
		actual_name = name + "-n°" + tmp.str();
		horde[i] = *(new Zombie(actual_name));
	}
	return horde;
}
