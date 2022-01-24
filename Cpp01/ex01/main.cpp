#include "Zombie.hpp"

int main(void){
	Zombie  *zeap;

	zeap = zombieHorde(24, "Gianni");
	for(int i = 0; i < 24; i++)
		zeap[i].announce();
	delete [] zeap;
	return 0;
}