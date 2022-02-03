#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main(void){
	std::vector<int>	vec;

	vec.push_back(3);
	vec.push_back(27);
	vec.push_back(31);
	vec.push_back(55);
	vec.push_back(66);


	try{
		std::cout << easyfind(vec, 31) << std::endl;
	}
	catch (std::exception & e){
		std::cerr << e.what() << std::endl;
	}
}
