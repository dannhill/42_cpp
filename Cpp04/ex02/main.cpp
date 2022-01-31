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

	std::cout << std::endl << std::endl;

	Cat	*cat = new Cat();
	Cat	*cat2 = new Cat();

	*cat = *cat2;

	delete cat2;

	std::cout << cat->getBrain().ideas[23] << std::endl;

	Cat	*cat3 = new Cat(*cat);

	delete cat;

	std::cout << cat3->getBrain().ideas[57] << std::endl;

	std::cout << std::endl << std::endl;

	for (int i = 0; i < 100; i++)
		delete farm[i];
	return 0;
}