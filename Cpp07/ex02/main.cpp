#include "Array.hpp"
#include <iostream>

int	main(void){
	Array<int>	kek(5);
	Array<int>	lel(kek);
	Array<int>	asd = kek;

	std::cout << kek[3] << std::endl;
	std::cout << kek[7] << std::endl;

	kek[0] = 22;
	kek[1] = 44;
	kek[2] = 42;
	kek[3] = 99;
	kek[4] = 666;

	for (int i = 0; i < 5; i++)
		std::cout << kek[i] << std::endl;

	std::cout << std::endl;

	std::cout << kek.size() << std::endl;

	Array<int>	haha(kek);

	kek[3] = 100000;

	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
		std::cout << haha[i] << std::endl;

	return 0;
}
