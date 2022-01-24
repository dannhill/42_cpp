#include "Zombie.hpp"
#include <cstdlib>

void	randomChump(std::string name){
	static bool	init = true;
	int			r(0);
	Zombie		*zeap;

	if (init)
	{
		srand(time(NULL));
		init = false;
	}
	r = rand() % 2;
	if (r == 0)
	{
		zeap = newZombie(name);
		zeap->announce();
		delete zeap;
	}
	else if (r == 1)
	{
		Zombie	zack(name);

		zack.announce();
	}
	else
		std::cerr << "Error: wrong random number." << std::endl;
	return;
}