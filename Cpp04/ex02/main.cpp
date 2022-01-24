#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <cstdlib>

int	main(void){
	int	cats(50);
	int	dogs(50);
	int	r(-1);

	Animal	*farm[100];

	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		r = rand() % 2;
		if (r == 0 && cats > 0)
		{
			farm[i] = new Cat();
			cats--;
		}
		else if (dogs > 0)
		{
			farm[i] = new Dog();
			dogs--;
		}
		else if (cats > 0)
		{
			farm[i] = new Cat();
			cats--;
		}
	}

	for (int i = 0; i < 100; i++)
		delete farm[i];
	return 0;
}